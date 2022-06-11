from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from segtypes.common.group import CommonSegGroup
from typing import Optional, Set
import os
import re
from pathlib import Path
import spimdisasm
import rabbitizer

from util import log, options
from util.compiler import GCC, SN64
from util.symbols import Symbol


class CommonSegC(CommonSegCodeSubsegment):
    defined_funcs: Set[str] = set()
    global_asm_funcs: Set[str] = set()

    STRIP_C_COMMENTS_RE = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE,
    )

    C_FUNC_RE = re.compile(
        r"^(?:static\s+)?[^\s]+\s+([^\s(]+)\(([^;)]*)\)[^;]+?{", re.MULTILINE
    )

    C_GLOBAL_ASM_IDO_RE = re.compile(
        r"GLOBAL_ASM\(\"(\w+\/)*(\w+)\.s\"\)", re.MULTILINE
    )

    @staticmethod
    def strip_c_comments(text):
        def replacer(match):
            s = match.group(0)
            if s.startswith("/"):
                return " "
            else:
                return s

        return re.sub(CommonSegC.STRIP_C_COMMENTS_RE, replacer, text)

    @staticmethod
    def get_funcs_defined_in_c(c_file):
        with open(c_file, "r") as f:
            text = CommonSegC.strip_c_comments(f.read())

        return set(m.group(1) for m in CommonSegC.C_FUNC_RE.finditer(text))

    @staticmethod
    def find_all_instances(str, sub):
        start = 0
        while True:
            start = str.find(sub, start)
            if start == -1:
                return
            yield start
            start += len(sub)

    @staticmethod
    def get_close_parenthesis(str, pos):
        paren_count = 0
        while True:
            cur_char = str[pos]
            if cur_char == "(":
                paren_count += 1
            elif cur_char == ")":
                if paren_count == 0:
                    return pos + 1
                else:
                    paren_count -= 1
            pos += 1

    @staticmethod
    def find_include_asm(text: str):
        for pos in CommonSegC.find_all_instances(text, "INCLUDE_ASM("):
            close_paren_pos = CommonSegC.get_close_parenthesis(
                text, pos + len("INCLUDE_ASM(")
            )
            macro_contents = text[pos:close_paren_pos]
            macro_args = macro_contents.split(",")
            if options.get_use_legacy_include_asm():
                if len(macro_args) >= 3:
                    yield macro_args[2].strip(" )")
            else:
                if len(macro_args) >= 2:
                    yield macro_args[1].strip(" )")

    @staticmethod
    def get_global_asm_funcs(c_file):
        with open(c_file, "r") as f:
            text = CommonSegC.strip_c_comments(f.read())
        if options.get_compiler() in [GCC, SN64]:
            return set(CommonSegC.find_include_asm(text))
        else:
            return set(
                m.group(2) for m in CommonSegC.C_GLOBAL_ASM_IDO_RE.finditer(text)
            )

    def out_path(self) -> Optional[Path]:
        return options.get_src_path() / self.dir / f"{self.name}.c"

    def scan(self, rom_bytes: bytes):
        if (
            self.rom_start is not None
            and self.rom_end is not None
            and self.rom_start != self.rom_end
        ):
            path = self.out_path()
            if path:
                if options.do_c_func_detection() and os.path.exists(path):
                    # TODO run cpp?
                    self.defined_funcs = self.get_funcs_defined_in_c(path)
                    self.global_asm_funcs = self.get_global_asm_funcs(path)
                    self.mark_c_funcs_as_defined(
                        {*self.defined_funcs, *self.global_asm_funcs}
                    )

            self.scan_code(rom_bytes)

    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end:

            asm_out_dir = options.get_nonmatchings_path() / self.dir
            asm_out_dir.mkdir(parents=True, exist_ok=True)

            self.print_file_boundaries()

            is_new_c_file = False

            c_path = self.out_path()
            if c_path:
                if not os.path.exists(c_path) and options.get_create_c_files():
                    self.create_c_file(asm_out_dir, c_path)
                    is_new_c_file = True

            for func in self.text_section.symbolList:
                assert func.vram is not None
                func_sym = self.get_symbol(
                    func.vram, in_segment=True, type="func", local_only=True
                )
                assert func_sym is not None

                if func.getName() in self.global_asm_funcs or is_new_c_file:
                    self.create_c_asm_file(func, asm_out_dir, func_sym)

    def get_c_preamble(self):
        ret = []

        preamble = options.get_generated_c_premble()
        ret.append(preamble)
        ret.append("")

        return ret

    def mark_c_funcs_as_defined(self, c_funcs):
        for func_name in c_funcs:
            found = False
            for symbols in self.seg_symbols.values():
                for symbol in symbols:
                    if symbol.name == func_name:
                        symbol.defined = True
                        found = True
                        break
                if found:
                    break

    def create_c_asm_file(
        self, func: spimdisasm.mips.symbols.SymbolBase, out_dir, func_sym: Symbol
    ):
        outpath = Path(os.path.join(out_dir, self.name, func_sym.name + ".s"))
        assert func.vram is not None

        # Skip extraction if the file exists and the symbol is marked as extract=false
        if outpath.exists() and not func_sym.extract:
            return

        out_lines = []

        if options.asm_inc_header():
            out_lines.extend(options.asm_inc_header().split("\n"))

        if self.parent and isinstance(self.parent, CommonSegGroup):
            if (
                options.get_migrate_rodata_to_functions()
                and func.vram in self.parent.rodata_syms
            ):
                func_rodata = list(
                    {s for s in self.parent.rodata_syms[func.vram] if s.disasm_str}
                )
                func_rodata.sort(key=lambda s: s.vram_start)

                if len(func_rodata) > 0:
                    rsub = self.parent.get_subsegment_for_ram(func_rodata[0].vram_start)
                    if rsub and rsub.type != "rodata":
                        out_lines.append(".section .rodata")

                        for sym in func_rodata:
                            if sym.extract and sym.disasm_str:
                                out_lines.append("")
                                out_lines.append(
                                    f"{options.get_asm_data_macro()} {sym.name}"
                                )
                                out_lines.extend(
                                    sym.disasm_str.replace("\n\n", "\n").split("\n")
                                )

                        out_lines.append("")
                        out_lines.append(".section .text")
                        out_lines.append("")

        out_lines.append(func.disassemble())

        outpath.parent.mkdir(parents=True, exist_ok=True)

        with open(outpath, "w", newline="\n") as f:
            newline_sep = options.c_newline()
            f.write(newline_sep.join(out_lines))
        self.log(f"Disassembled {func_sym.name} to {outpath}")

    def create_c_file(self, asm_out_dir, c_path):
        c_lines = self.get_c_preamble()

        for func in self.text_section.symbolList:
            assert isinstance(func, spimdisasm.mips.symbols.SymbolFunction)

            # Terrible hack to "auto-decompile" empty functions
            if (
                options.get_auto_decompile_empty_functions()
                and func.instructions[0].isJrRa()
                and func.instructions[1].isNop()
            ):
                c_lines.append("void " + func.getName() + "(void) {")
                c_lines.append("}")
            else:
                if options.get_compiler() in [GCC, SN64]:
                    if options.get_use_legacy_include_asm():
                        rel_asm_out_dir = asm_out_dir.relative_to(
                            options.get_nonmatchings_path()
                        )
                        c_lines.append(
                            f'INCLUDE_ASM(s32, "{rel_asm_out_dir / self.name}", {func.getName()});'
                        )
                    else:
                        c_lines.append(
                            f'INCLUDE_ASM("{asm_out_dir / self.name}", {func.getName()});'
                        )
                else:
                    asm_outpath = Path(
                        os.path.join(asm_out_dir, self.name, func.getName() + ".s")
                    )
                    rel_asm_outpath = os.path.relpath(
                        asm_outpath, options.get_base_path()
                    )
                    c_lines.append(f'#pragma GLOBAL_ASM("{rel_asm_outpath}")')
            c_lines.append("")

        Path(c_path).parent.mkdir(parents=True, exist_ok=True)
        with open(c_path, "w") as f:
            f.write("\n".join(c_lines))
        log.write(f"Wrote {self.name} to {c_path}")
