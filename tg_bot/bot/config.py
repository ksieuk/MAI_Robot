import os
from dotenv import load_dotenv
from pydantic import BaseSettings, SecretStr, Field
from bot.structures.states import JsonFileStorage, States
from pathlib import Path


load_dotenv()


class BotSettings(BaseSettings):
    bot_token: SecretStr

    class Config:
        env_file = '.env'


class MqttSettings(BaseSettings):
    host = Field('', env='MQQT_HOST')
    topic = Field('delivery', env='MQQT_TOPIC')


BASE_DIR = Path(__file__).resolve().parent
drinks = States(JsonFileStorage(str(BASE_DIR / 'static/drinks.json')))
locations = States(JsonFileStorage(str(BASE_DIR / 'static/locations.json')))
states_objs = {'drink': drinks, 'location': locations}

bot_settings = BotSettings()
mqtt_settings = MqttSettings()
print(mqtt_settings.dict())

ADMINS_IDS = set(map(int, os.environ.get('ADMINS_IDS').split(',')))
