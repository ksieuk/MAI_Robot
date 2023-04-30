from aiogram.types import ReplyKeyboardMarkup

from bot.structures.keyboards.base_buttons import create_kb_basic, create_kb_delivery
from bot.config import drinks, locations


def get_kb_new_order() -> ReplyKeyboardMarkup:
    return create_kb_basic("Сделать заказ")


def get_kb_drinks() -> ReplyKeyboardMarkup:
    return create_kb_delivery(*drinks.get_state_names())


def get_kb_locations() -> ReplyKeyboardMarkup:
    return create_kb_delivery(*locations.get_state_names())


def get_kb_confirmation() -> ReplyKeyboardMarkup:
    return create_kb_delivery('Заказ доставлен', 'Робот не приехал')

