import esphome.config_validation as cv
from esphome.components.remote_base import declare_protocol, register_trigger, register_dumper

CODEOWNERS = ["@j9brown"]

DEPENDENCIES = ["remote_base"]

MULTI_CONF = False

CONFIG_SCHEMA = cv.COMPONENT_SCHEMA


async def to_code(config):
    pass


MaxxfanData, MaxxfanBinarySensor, MaxxfanTrigger, MaxxfanAction, MaxxfanDumper = declare_protocol("Maxxfan")


@register_trigger("maxxfan", MaxxfanTrigger, MaxxfanData)
def maxxfan_trigger(var, config):
    pass


@register_dumper("maxxfan", MaxxfanDumper)
def maxxfan_dumper(var, config):
    pass
