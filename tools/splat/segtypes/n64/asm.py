from segtypes.common.asm import CommonSegAsm

from util import options


class N64SegAsm(CommonSegAsm):
    @staticmethod
    def get_file_header():
        ret = []

        ret.append('.include "macro.inc"')
        ret.append("")
        ret.append("# assembler directives")
        ret.append(".set noat      # allow manual use of $at")
        ret.append(".set noreorder # don't insert nops after branches")
        ret.append(".set gp=64     # allow use of 64-bit general purpose registers")
        ret.append("")
        preamble = options.get_generated_s_preamble()
        if preamble:
            ret.append(preamble)
            ret.append("")
        ret.append('.section .text, "ax"')
        ret.append("")

        return ret
