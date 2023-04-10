from aiogram.types import ReplyKeyboardMarkup
from aiogram.utils.keyboard import ReplyKeyboardBuilder


def create_kb_basic(*fields) -> ReplyKeyboardMarkup:
    kb = ReplyKeyboardBuilder()
    for drink in fields:
        kb.button(text=drink)
    kb.adjust(3)

    return kb.as_markup(resize_keyboard=True)