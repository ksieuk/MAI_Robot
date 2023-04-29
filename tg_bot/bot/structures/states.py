import abc
import json
import os.path
from typing import Any


class BaseStorage(abc.ABC):
    """Абстрактное хранилище состояния.

    Позволяет сохранять, получать и удалять состояние.
    Способ хранения состояния может варьироваться в зависимости
    от итоговой реализации. Например, можно хранить информацию
    в базе данных или в распределённом файловом хранилище.
    """

    @abc.abstractmethod
    def save_state(self, state: dict[str, Any]) -> None:
        """Сохранить состояние в хранилище."""

    @abc.abstractmethod
    def retrieve_state(self) -> dict[str, Any]:
        """Получить состояние из хранилища."""

    @abc.abstractmethod
    def delete_state(self, key: str) -> None:
        """Удалить состояние по определенному ключу."""

    @abc.abstractmethod
    def get_state_names(self) -> list[str]:
        """Получить список всех имен состояний в хранилище."""


class JsonFileStorage(BaseStorage):
    """Реализация хранилища, использующего локальный файл.

    Формат хранения: JSON
    """

    def __init__(self, file_path: str) -> None:
        self.file_path = file_path

    def save_state(self, state: dict[str, Any]) -> None:
        """Сохранить состояние в хранилище."""
        with open(self.file_path, "w") as file:
            json.dump(state, file, ensure_ascii=False)

    def retrieve_state(self) -> dict[str, Any]:
        """Получить состояние из хранилища."""
        if not os.path.isfile(self.file_path):
            return {}
        with open(self.file_path, "r") as file:
            state = json.load(file)
        return state

    def delete_state(self, key: str) -> None:
        """Удалить состояние по заданному ключу."""
        state = self.retrieve_state()
        if key in state:
            del state[key]
            self.save_state(state)

    def get_state_names(self) -> list[str]:
        """Получить список всех имен состояний в хранилище."""
        state = self.retrieve_state()
        return list(state.keys())


class States:
    """Класс для работы с состояниями."""

    def __init__(self, storage: BaseStorage) -> None:
        self.storage = storage

    def set_state(self, key: str, value: True | False) -> None:
        """Установить состояние для определённого ключа."""
        state = self.storage.retrieve_state()
        state[key] = value
        self.storage.save_state(state)

    def get_state(self, key: str) -> Any:
        """Получить состояние по определённому ключу."""
        state = self.storage.retrieve_state()
        return state.get(key) if state else None

    def delete_state(self, key: str) -> None:
        """Удалить состояние по заданному ключу."""
        self.storage.delete_state(key)

    def get_state_names(self) -> list[str]:
        """Получить список всех имен состояний."""
        return self.storage.get_state_names()
