import os
from dotenv import load_dotenv
from pydantic import BaseSettings, SecretStr, Field
from bot.structures.states import JsonFileStorage, States


load_dotenv()


class BotSettings(BaseSettings):
    bot_token: SecretStr

    class Config:
        env_file = '.env'


class MqttSettings(BaseSettings):
    host = Field('', env='MQQT_HOST')
    topic = Field('delivery', env='MQQT_TOPIC')


drinks = States(JsonFileStorage('drinks.json'))
locations = States(JsonFileStorage('locations.json'))
states_objs = {'drink': drinks, 'location': locations}

bot_settings = BotSettings()
mqtt_settings = MqttSettings()
print(mqtt_settings.dict())

ADMINS_IDS = set(os.environ.get('ADMINS_IDS').split(','))
