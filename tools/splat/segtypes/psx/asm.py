from segtypes.common.asm import CommonSegAsm
from typing import Optional
from pathlib import Path

from util import options


class PsxSegAsm(CommonSegAsm):
    @staticmethod
    def get_file_header():
        ret = []

        ret.append(".include \"macro.inc\"")
        ret.append("")
        ret.append("# assembler directives")
        ret.append(".set noat      # allow manual use of $at")
        ret.append(".set noreorder # don't insert nops after branches")
        ret.append("")
        ret.append(".section .text, \"ax\"")
        ret.append("")

        return ret
