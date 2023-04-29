from pydantic import BaseSettings, SecretStr
from bot.structures.states import JsonFileStorage, States


class Settings(BaseSettings):
    bot_token: SecretStr

    class Config:
        env_file = '.env'
        env_file_encoding = 'utf-8'


bot_settings = Settings()
drinks = States(JsonFileStorage('drinks.json'))
locations = States(JsonFileStorage('locations.json'))
states_objs = {'drink': drinks, 'location': locations}
