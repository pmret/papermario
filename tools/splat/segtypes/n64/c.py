from segtypes.n64.codesubsegment import N64SegCodeSubsegment
from segtypes.n64.group import N64SegGroup
from typing import Optional, Set
import os
import re
from pathlib import Path

from util import options


class N64SegC(N64SegCodeSubsegment):
    defined_funcs: Set[str] = set()
    global_asm_funcs: Set[str] = set()

    STRIP_C_COMMENTS_RE = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )

    C_FUNC_RE = re.compile(
        r"^(static\s+)?[^\s]+\s+([^\s(]+)\(([^;)]*)\)[^;]+?{",
        re.MULTILINE
    )

    C_GLOBAL_ASM_RE = re.compile(
        r"(INCLUDE|GLOBAL)_ASM\(\"(\w+\/)*(\w+)\.s\"\)",
        re.MULTILINE
    )

    @staticmethod
    def strip_c_comments(text):
        def replacer(match):
            s = match.group(0)
            if s.startswith("/"):
                return " "
            else:
                return s
        return re.sub(N64SegC.STRIP_C_COMMENTS_RE, replacer, text)

    @staticmethod
    def get_funcs_defined_in_c(c_file):
        with open(c_file, "r") as f:
            text = N64SegC.strip_c_comments(f.read())

        return set(m.group(2) for m in N64SegC.C_FUNC_RE.finditer(text))

    @staticmethod
    def get_global_asm_funcs(c_file):
        with open(c_file, "r") as f:
            text = N64SegC.strip_c_comments(f.read())
        return set(m.group(3) for m in N64SegC.C_GLOBAL_ASM_RE.finditer(text))

    def out_path(self) -> Optional[Path]:
        return options.get_src_path() / self.dir / f"{self.name}.c"

    def scan(self, rom_bytes: bytes):
        if self.rom_start is not None and self.rom_end is not None and self.rom_start != self.rom_end:
            path = self.out_path()
            if path:
                if options.get("do_c_func_detection", True) and os.path.exists(path):
                    # TODO run cpp?
                    self.defined_funcs = self.get_funcs_defined_in_c(path)
                    self.mark_c_funcs_as_defined(self.defined_funcs)
                    self.global_asm_funcs = self.get_global_asm_funcs(path)

            self.funcs_text = self.disassemble_code(rom_bytes)

    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end:

            asm_out_dir = options.get_asm_path() / "nonmatchings" / self.dir
            asm_out_dir.mkdir(parents=True, exist_ok=True)

            is_new_c_file = False

            c_path = self.out_path()
            if c_path:
                if not os.path.exists(c_path) and options.get("create_new_c_files", True):
                    self.create_c_file(self.funcs_text, asm_out_dir, c_path)
                    is_new_c_file = True

            for func in self.funcs_text:
                func_name = self.parent.get_symbol(func, type="func", local_only=True).name

                if options.get_compiler() == "GCC":
                    if func_name not in self.defined_funcs:
                        self.create_c_asm_file(self.funcs_text, func, asm_out_dir, func_name)
                else:
                    if func_name in self.global_asm_funcs or is_new_c_file:
                        self.create_c_asm_file(self.funcs_text, func, asm_out_dir, func_name)

    def get_gcc_inc_header(self):
        ret = []
        ret.append(".set noat      # allow manual use of $at")
        ret.append(".set noreorder # don't insert nops after branches")
        ret.append("")

        return ret

    def get_c_preamble(self):
        ret = []

        preamble = options.get_generated_c_premble()
        ret.append(preamble)
        ret.append("")

        return ret

    def mark_c_funcs_as_defined(self, c_funcs):
        for func_name in c_funcs:
            found = False
            for func_addr in self.seg_symbols:
                for symbol in self.seg_symbols[func_addr]:
                    if symbol.name == func_name:
                        symbol.defined = True
                        found = True
                        break
                if found:
                    break

    def create_c_asm_file(self, funcs_text, func, out_dir, func_name):
        if options.get_compiler() == "GCC":
            out_lines = self.get_gcc_inc_header()
        else:
            out_lines = []

        if self.parent and isinstance(self.parent, N64SegGroup):
            if func in self.parent.rodata_syms:
                func_rodata = list({s for s in self.parent.rodata_syms[func] if s.disasm_str})
                func_rodata.sort(key=lambda s:s.vram_start)

                if len(func_rodata) > 0:
                    rsub = self.parent.get_subsegment_for_ram(func_rodata[0].vram_start)
                    if rsub and rsub.type != "rodata":
                        out_lines.append(".section .rodata")

                        for sym in func_rodata:
                            if sym.disasm_str:
                                out_lines.extend(sym.disasm_str.replace("\n\n", "\n").split("\n"))

                        out_lines.append("")
                        out_lines.append(".section .text")
                        out_lines.append("")

        out_lines.extend(funcs_text[func][0])
        out_lines.append("")

        outpath = Path(os.path.join(out_dir, self.name, func_name + ".s"))
        outpath.parent.mkdir(parents=True, exist_ok=True)

        with open(outpath, "w", newline="\n") as f:
            f.write("\n".join(out_lines))
        self.log(f"Disassembled {func_name} to {outpath}")

    def create_c_file(self, funcs_text, asm_out_dir, c_path):
        c_lines = self.get_c_preamble()

        for func in funcs_text:
            func_name = self.parent.get_symbol(func, type="func", local_only=True).name

            # Terrible hack to "auto-decompile" empty functions
            # TODO move disassembly into funcs_text or somewhere we can access it from here
            if len(funcs_text[func][0]) == 3 and funcs_text[func][0][1][-3:] == "$ra" and funcs_text[func][0][2][-3:] == "nop":
                c_lines.append("void " + func_name + "(void) {")
                c_lines.append("}")
            else:
                if options.get_compiler() == "GCC":
                    c_lines.append("INCLUDE_ASM(s32, \"{}\", {});".format(self.name, func_name))
                else:
                    asm_outpath = Path(os.path.join(asm_out_dir, self.dir, self.name, func_name + ".s"))
                    rel_asm_outpath = os.path.relpath(asm_outpath, options.get_base_path())
                    c_lines.append(f"#pragma GLOBAL_ASM(\"{rel_asm_outpath}\")")
            c_lines.append("")

        Path(c_path).parent.mkdir(parents=True, exist_ok=True)
        with open(c_path, "w") as f:
            f.write("\n".join(c_lines))
        print(f"Wrote {self.name} to {c_path}")
