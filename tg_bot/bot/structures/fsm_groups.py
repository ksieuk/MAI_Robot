from aiogram.fsm.state import StatesGroup, State


class DeliveryStates(StatesGroup):
    """States for delivery"""

    drink = State()
    location = State()
    confirmation = State()