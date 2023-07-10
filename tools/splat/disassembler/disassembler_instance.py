from .disassembler import Disassembler
from .spimdisasm_disassembler import SpimdisasmDisassembler
from .null_disassembler import NullDisassembler

__instance: Disassembler = NullDisassembler()
__initialized = False


def create_disassembler_instance(platform: str):
    global __instance
    global __initialized
    if platform in ["n64", "psx", "ps2"]:
        __instance = SpimdisasmDisassembler()
        __initialized = True
        return

    raise NotImplementedError("No disassembler for requested platform")


def get_instance() -> Disassembler:
    global __instance
    global __initialized
    if not __initialized:
        raise Exception("Disassembler instance not initialized")
        return None
    return __instance
