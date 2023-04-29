import asyncio
import time

import paho.mqtt.client as mqtt

from aiogram import Router, F
from aiogram.filters.command import Command, CommandStart
from aiogram.filters.state import StateFilter
from aiogram.filters.text import Text
from aiogram.filters.command import CommandObject
from aiogram.fsm.context import FSMContext
from aiogram.types import (
    Message, KeyboardButton,
    ReplyKeyboardMarkup, ReplyKeyboardRemove,
    InlineKeyboardMarkup, InlineKeyboardButton,
)

from bot.structures.fsm_groups import DeliveryStates
from bot.structures.keyboards.delivery import (
    get_kb_new_order, get_kb_drinks, get_kb_locations, get_kb_confirmation,
)
from bot.structures.states import States
from bot.config import states_objs


router = Router()


@router.message(Command('start'))
async def cmd_start(message: Message, state: FSMContext):
    await state.clear()
    await message.answer(
        text='Привет!\nЯ Робот-доставщик напитков. Желаешь утолить жажду?',
        reply_markup=get_kb_new_order(),
    )


async def set_drink_state(
        message: Message, state_obj: States,
        state_name: str | None, command_name: str, command_full_name: str
):
    try:
        assert state_name is not None
    except AssertionError:
        return await message.answer(
            text=f'Неверный формат ввода. Пример использования команды: `/{command_full_name} молоко`'
            .replace('.', r'\.'),
            reply_markup=get_kb_new_order(),
            parse_mode='MarkdownV2',
        )

    if command_name == 'del':
        state_obj.delete_state(state_name)
    else:
        is_exist = True if command_name == 'add' else False
        state_obj.set_state(state_name, is_exist)

    await message.answer(
        text='Готово!',
        reply_markup=get_kb_new_order(),
    )


@router.message(Command(commands=[
    'add_drink', 'del_drink', 'out_drink',
    'add_location', 'del_location', 'out_location'
]))
async def cmd_drinks(message: Message, command: CommandObject, state: FSMContext):
    await state.clear()

    command_full_name = command.command
    state_name = command.args
    command_name, state_obj_name = command_full_name.split('_')
    state_obj = states_objs[state_obj_name]

    await set_drink_state(message, state_obj, state_name, command_name, command_full_name)


@router.message(Command('test'))
async def test(message: Message):
    client.connect("broker.hivemq.com", port=1883, keepalive=60, bind_address="")

    client.publish("test-python", "ПРИВЕЕЕЕЕТ hello")

    await message.answer(
        text='отправил запрос',
        reply_markup=get_kb_new_order(),
    )


@router.message(Command('test2'))
async def test2(message: Message):
    # client.connect("broker.hivemq.com", port=1883, keepalive=60, bind_address="")
    client.connect("broker.hivemq.com", port=1883, keepalive=60, bind_address="")

    client.loop_start()  # start the loop
    print("Subscribing to topic", "house/bulbs/bulb1")
    client.subscribe("testik")
    client.publish("testik", 'sdfsdf')
    await asyncio.sleep(20)

    await message.answer(
        text='готово',
        reply_markup=get_kb_new_order(),
    )


def on_message(client_, userdata, message):
    print("message received ", str(message.payload.decode("utf-8")))
    print("message topic=", message.topic)
    print("message qos=", message.qos)
    print("message retain flag=", message.retain)


client = mqtt.Client(client_id="myPy",
                     transport='tcp',
                     protocol=mqtt.MQTTv5)
client.on_message = on_message
