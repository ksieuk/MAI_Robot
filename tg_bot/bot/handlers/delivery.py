import asyncio
import time

import paho.mqtt.client as mqtt

from aiogram import Router, F
from aiogram.filters.command import Command, CommandStart
from aiogram.filters.state import StateFilter
from aiogram.filters.text import Text
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
from bot.config import drinks, locations

router = Router()


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
        text='Принято! Ваш заказ в процессе.',
        reply_markup=get_kb_confirmation()
    )
    await state.set_state(DeliveryStates.confirmation)


@router.message(Text(text='Заказ доставлен', ignore_case=True), StateFilter(DeliveryStates.confirmation))
async def cmd_confirmed(message: Message, state: FSMContext):
    await message.answer(
        text='Спасибо, что выбрали нашу доставку!',
        reply_markup=get_kb_new_order()
    )
    await state.clear()


@router.message(Text(text='Робот не приехал', ignore_case=True), StateFilter(DeliveryStates.confirmation))
async def cmd_confirmed(message: Message, state: FSMContext):
    await message.answer(
        text='Подождите еще немного!',
    )
