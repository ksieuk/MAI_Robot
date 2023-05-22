import asyncio
import asyncio_mqtt as aiomqtt

from aiogram import Router
from aiogram.filters.state import StateFilter
from aiogram.filters.text import Text
from aiogram.filters.command import Command
from aiogram.types import Message
from aiogram.fsm.context import FSMContext

from bot.structures.fsm_groups import DeliveryStates
from bot.config import drinks, locations, mqtt_settings
from bot.structures.keyboards.delivery import (
    get_kb_new_order, get_kb_drinks, get_kb_locations, get_kb_confirmation,
)

# router_delivery = Router()
router = Router()
# router_delivery.include_router(router)


@router.message(
    Text(text=['Отменить', 'Прекратить выполнение заказа'], ignore_case=True),
    StateFilter('*')
)
@router.message(
    Command('cancel'), StateFilter('*')
)
async def cmd_cancel_delivery(message: Message, state: FSMContext):
    await state.clear()
    await message.answer(
        text='Выполнение заказа прекращено',
        reply_markup=get_kb_new_order(),
    )


@router.message(Text(text='Сделать заказ', ignore_case=True), StateFilter(None))
async def cmd_new_order(message: Message, state: FSMContext):
    await message.answer(
        text='Выбери напиток',
        reply_markup=get_kb_drinks(),
    )
    await state.set_state(DeliveryStates.drink)


@router.message(StateFilter(DeliveryStates.drink))
async def cmd_get_drink(message: Message, state: FSMContext):
    drinks_names = drinks.get_state_names()
    state_info = drinks.get_state(message.text)

    if state_info is None:
        drinks_names_line = '\n'.join(drinks_names)
        return await message.answer(
            text=f"Выбери напиток из предложенных:\n\n{drinks_names_line}",
        )

    if state_info is False:
        return await message.answer(
            text='Этот напиток закончился, но я скоро отправлюсь в магазин за ним! Выбери другой напиток',
        )

    await message.answer(
        text='Отличный выбор!\nТеперь скажи, на какой метке ты находишься? Выбери цвет',
        reply_markup=get_kb_locations()
    )
    await state.set_state(DeliveryStates.location)


@router.message(StateFilter(DeliveryStates.location))
async def cmd_get_location(message: Message, state: FSMContext):
    state_info = locations.get_state(message.text)
    locations_names = locations.get_state_names()

    if state_info is None:
        locations_names_line = '\n'.join(locations_names)
        return await message.answer(
            text=f"Данной метки не существует, выберите из предложенных:\n\n{locations_names_line}",
        )

    if state_info is False:
        return await message.answer(
            text='Эта метка сейчас недоступна, выбери другую',
        )

    await message.answer(
        text='Отправляю ваш заказ',
        reply_markup=get_kb_confirmation()
    )

    await mqtt_new_order()

    await message.answer(
        text='Принято! Ваш заказ в процессе',
        reply_markup=get_kb_confirmation()
    )
    await state.set_state(DeliveryStates.confirmation)


async def mqtt_new_order():
    async with aiomqtt.Client(mqtt_settings.host) as client:
        await client.publish(mqtt_settings.topic, payload='NEW ORDER')


@router.message(Text(text='Заказ доставлен', ignore_case=True), StateFilter(DeliveryStates.confirmation))
async def cmd_confirmed(message: Message, state: FSMContext):
    # await mqtt_get_is_delivered()
    await message.answer(
        text='Спасибо, что выбрали нашу доставку!',
        reply_markup=get_kb_new_order()
    )
    await state.clear()


async def mqtt_get_is_delivered():
    reconnect_interval = 5  # In seconds
    while True:
        try:
            async with aiomqtt.Client(mqtt_settings.host) as client:
                async with client.messages() as messages:
                    await client.subscribe(topic=mqtt_settings.topic)
                    async for message in messages:
                        return message.payload.decode()
        except aiomqtt.MqttError as error:
            print(f'Error "{error}". Reconnecting in {reconnect_interval} seconds.')
            await asyncio.sleep(reconnect_interval)


@router.message(Text(text='Робот не приехал', ignore_case=True), StateFilter(DeliveryStates.confirmation))
async def cmd_confirmed(message: Message):
    await message.answer(
        text='Подождите еще немного!',
    )
