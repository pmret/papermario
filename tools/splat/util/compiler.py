from dataclasses import dataclass
from typing import Optional


@dataclass
class Compiler:
    name: str
    asm_function_macro: str = "glabel"
    asm_function_alt_macro: str = "glabel"
    asm_jtbl_label_macro: str = "glabel"
    asm_data_macro: str = "glabel"
    asm_end_label: str = ""
    c_newline: str = "\n"
    asm_inc_header: str = ""
    include_macro_inc: bool = True
    asm_emit_size_directive: Optional[bool] = None


GCC = Compiler(
    "GCC",
    asm_inc_header=".set noat      /* allow manual use of $at */\n.set noreorder /* don't insert nops after branches */\n\n",
)

SN64 = Compiler(
    "SN64",
    asm_function_macro=".globl",
    asm_jtbl_label_macro=".globl",
    asm_data_macro=".globl",
    asm_end_label=".end",
    c_newline="\r\n",
    include_macro_inc=False,
    asm_emit_size_directive=False,
)

IDO = Compiler("IDO", include_macro_inc=False, asm_emit_size_directive=False)

compiler_for_name = {"GCC": GCC, "SN64": SN64, "IDO": IDO}


def for_name(name: str) -> Compiler:
    name = name.upper()
    if name in compiler_for_name:
        return compiler_for_name[name]
    return Compiler(name)
