from aiogram import Router
from aiogram.filters.command import Command
from aiogram.filters.command import CommandObject
from aiogram.fsm.context import FSMContext
from aiogram.types import Message
from bot.structures.keyboards.delivery import get_kb_new_order
from bot.structures.states import States
from bot.structures.filters import IsAdmin
from bot.config import states_objs


router = Router()


@router.message(Command('start'))
async def cmd_start(message: Message, state: FSMContext):
    await state.clear()
    print(message.from_user.id)
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


@router.message(IsAdmin(), Command(commands=[
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

