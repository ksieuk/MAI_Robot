from aiogram.types import ReplyKeyboardMarkup, KeyboardButton
from aiogram.utils.keyboard import ReplyKeyboardBuilder


def create_kb_buttons(*fields) -> ReplyKeyboardBuilder:
    kb = ReplyKeyboardBuilder()
    for drink in fields:
        kb.button(text=drink)
    kb.adjust(3)

    return kb


def create_kb_basic(*fields) -> ReplyKeyboardMarkup:
    kb = create_kb_buttons(*fields)

    return kb.as_markup(resize_keyboard=True)


def create_kb_delivery(*fields) -> ReplyKeyboardMarkup:
    kb = create_kb_buttons(*fields)
    kb.row(KeyboardButton(text='Прекратить выполнение заказа'))

    return kb.as_markup(resize_keyboard=True)

