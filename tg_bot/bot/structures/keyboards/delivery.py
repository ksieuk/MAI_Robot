from aiogram.types import ReplyKeyboardMarkup

from bot.structures.keyboards.base_buttons import create_kb_basic


def get_kb_new_order() -> ReplyKeyboardMarkup:
    return create_kb_basic("Сделать заказ")


def get_kb_drinks() -> ReplyKeyboardMarkup:
    drinks = [
        'Кофе',
        'Чай',
        'Кола',
        'Сок',
        'Вода',
        'Молоко',
        'Лимонад',
        'Коктейль',
    ]
    return create_kb_basic(*drinks)


def get_kb_locations() -> ReplyKeyboardMarkup:
    locations = [
        'Около кулера',
        'Около входа',
        'Около принтера',
        'Около камеры',
    ]
    return create_kb_basic(*locations)


def get_kb_confirmation() -> ReplyKeyboardMarkup:
    return create_kb_basic('Заказ доставлен', 'Робот не приехал')

