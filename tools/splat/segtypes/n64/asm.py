from util import options

from segtypes.common.asm import CommonSegAsm


class N64SegAsm(CommonSegAsm):
    @staticmethod
    def get_file_header():
        ret = []

        ret.append('.include "macro.inc"')
        ret.append("")
        ret.append("/* assembler directives */")
        ret.append(".set noat      /* allow manual use of $at */")
        ret.append(".set noreorder /* don't insert nops after branches */")
        if options.opts.add_set_gp_64:
            ret.append(
                ".set gp=64     /* allow use of 64-bit general purpose registers */"
            )
        ret.append("")
        preamble = options.opts.generated_s_preamble
        if preamble:
            ret.append(preamble)
            ret.append("")
        ret.append('.section .text, "ax"')
        ret.append("")

        return ret
