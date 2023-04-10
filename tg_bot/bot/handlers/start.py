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


router = Router()


@router.message(Command('start'))
async def cmd_start(message: Message, state: FSMContext):
    await state.clear()
    await message.answer(
        text='Привет!\nЯ Робот-доставщик напитков. Желаешь утолить жажду?',
        reply_markup=get_kb_new_order(),
    )


@router.message(Text(text='Сделать заказ', ignore_case=True), StateFilter(None))
async def cmd_new_order(message: Message, state: FSMContext):
    await message.answer(
        text='Выбери напиток',
        reply_markup=get_kb_drinks(),
    )
    await state.set_state(DeliveryStates.drink)


@router.message(Text(text=[
        'Кофе',
        'Чай',
        'Кола',
        'Сок',
        'Вода',
        'Молоко',
        'Лимонад',
        'Коктейль',
    ], ignore_case=True), StateFilter(DeliveryStates.drink))
async def cmd_get_drink(message: Message, state: FSMContext):
    await message.answer(
        text='Отличный выбор! Теперь скажи, где ты находишься?',
        reply_markup=get_kb_locations()
    )
    await state.set_state(DeliveryStates.location)


@router.message(Text(text=[
        'Около кулера',
        'Около входа',
        'Около принтера',
        'Около камеры',
    ], ignore_case=True), StateFilter(DeliveryStates.location))
async def cmd_get_location(message: Message, state: FSMContext):
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

