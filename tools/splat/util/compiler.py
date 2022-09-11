from dataclasses import dataclass


@dataclass
class Compiler:
    name: str
    asm_function_macro: str = "glabel"
    asm_data_macro: str = "glabel"
    asm_end_label: str = ""
    c_newline: str = "\n"
    asm_inc_header: str = ""


GCC = Compiler(
    "GCC",
    asm_inc_header=".set noat      # allow manual use of $at\n.set noreorder # don't insert nops after branches\n\n",
)

SN64 = Compiler(
    "SN64",
    asm_function_macro=".globl",
    asm_data_macro=".globl",
    asm_end_label=".end",
    c_newline="\r\n",
)

IDO = Compiler("IDO")

compiler_for_name = {"GCC": GCC, "SN64": SN64, "IDO": IDO}


def for_name(name: str) -> Compiler:
    name = name.upper()
    if name in compiler_for_name:
        return compiler_for_name[name]
    return Compiler(name)
