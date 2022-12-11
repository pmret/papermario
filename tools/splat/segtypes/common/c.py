import os
import re
from pathlib import Path
from typing import Optional, Set

import spimdisasm

from util import log, options, symbols
from util.compiler import GCC, SN64
from util.symbols import Symbol

from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from segtypes.common.group import CommonSegGroup
from segtypes.common.rodata import CommonSegRodata


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
            if options.opts.use_legacy_include_asm:
                if len(macro_args) >= 3:
                    yield macro_args[2].strip(" )")
            else:
                if len(macro_args) >= 2:
                    yield macro_args[1].strip(" )")

    @staticmethod
    def get_global_asm_funcs(c_file):
        with open(c_file, "r") as f:
            text = CommonSegC.strip_c_comments(f.read())
        if options.opts.compiler in [GCC, SN64]:
            return set(CommonSegC.find_include_asm(text))
        else:
            return set(
                m.group(2) for m in CommonSegC.C_GLOBAL_ASM_IDO_RE.finditer(text)
            )

    def out_path(self) -> Optional[Path]:
        return options.opts.src_path / self.dir / f"{self.name}.c"

    def scan(self, rom_bytes: bytes):
        if (
            self.rom_start is not None
            and self.rom_end is not None
            and self.rom_start != self.rom_end
        ):
            path = self.out_path()
            if path:
                if options.opts.do_c_func_detection and os.path.exists(path):
                    # TODO run cpp?
                    self.defined_funcs = self.get_funcs_defined_in_c(path)
                    self.global_asm_funcs = self.get_global_asm_funcs(path)
                    symbols.to_mark_as_defined.update(self.defined_funcs)
                    symbols.to_mark_as_defined.update(self.global_asm_funcs)

            self.scan_code(rom_bytes)

    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end:
            asm_out_dir = options.opts.nonmatchings_path / self.dir
            asm_out_dir.mkdir(parents=True, exist_ok=True)

            self.print_file_boundaries()

            is_new_c_file = False

            c_path = self.out_path()
            if c_path:
                if not os.path.exists(c_path) and options.opts.create_c_files:
                    self.create_c_file(asm_out_dir, c_path)
                    is_new_c_file = True

                self.create_asm_dependencies_file(c_path, asm_out_dir, is_new_c_file)

            assert self.spim_section is not None
            for func in self.spim_section.symbolList:
                if func.getName() in self.global_asm_funcs or is_new_c_file:
                    assert func.vram is not None
                    assert isinstance(func, spimdisasm.mips.symbols.SymbolFunction)
                    func_sym = self.get_symbol(
                        func.vram, in_segment=True, type="func", local_only=True
                    )
                    assert func_sym is not None

                    self.create_c_asm_file(func, asm_out_dir, func_sym)

    def get_c_preamble(self):
        ret = []

        preamble = options.opts.generated_c_preamble
        ret.append(preamble)
        ret.append("")

        return ret

    def create_c_asm_file(
        self,
        func: spimdisasm.mips.symbols.SymbolFunction,
        out_dir: Path,
        func_sym: Symbol,
    ):
        outpath = out_dir / self.name / (func_sym.name + ".s")
        assert func.vram is not None

        # Skip extraction if the file exists and the symbol is marked as extract=false
        if outpath.exists() and not func_sym.extract:
            return

        outpath.parent.mkdir(parents=True, exist_ok=True)

        with open(outpath, "w", newline="\n") as f:
            if options.opts.asm_inc_header:
                f.write(
                    options.opts.c_newline.join(options.opts.asm_inc_header.split("\n"))
                )

            if self.parent and isinstance(self.parent, CommonSegGroup):
                if (
                    options.opts.migrate_rodata_to_functions
                    and func.vram in self.parent.rodata_syms
                ):
                    func_rodata = list({s for s in self.parent.rodata_syms[func.vram]})
                    func_rodata.sort(key=lambda s: s.vram_start)

                    rdata_list = []
                    late_rodata_list = []
                    late_rodata_size = 0

                    processed_rodata_segments = set()
                    for func_rodata_symbol in func_rodata:
                        rsub = self.parent.get_subsegment_for_ram(
                            func_rodata_symbol.vram_start
                        )

                        if rsub is not None and isinstance(rsub, CommonSegRodata):
                            if (
                                rsub in processed_rodata_segments
                                or rsub.spim_section is None
                            ):
                                continue

                            assert isinstance(
                                rsub.spim_section,
                                spimdisasm.mips.sections.SectionRodata,
                            )
                            (
                                rdata_list_aux,
                                late_rodata_list_aux,
                                late_rodata_size_aux,
                            ) = spimdisasm.mips.FilesHandlers.getRdataAndLateRodataForFunctionFromSection(
                                func, rsub.spim_section
                            )
                            rdata_list += rdata_list_aux
                            late_rodata_list += late_rodata_list_aux
                            late_rodata_size += late_rodata_size_aux

                            processed_rodata_segments.add(rsub)
                    spimdisasm.mips.FilesHandlers.writeFunctionRodataToFile(
                        f, func, rdata_list, late_rodata_list, late_rodata_size
                    )

            f.write(func.disassemble())

        self.log(f"Disassembled {func_sym.name} to {outpath}")

    def create_c_file(self, asm_out_dir, c_path):
        assert self.spim_section is not None

        c_lines = self.get_c_preamble()

        for func in self.spim_section.symbolList:
            assert isinstance(func, spimdisasm.mips.symbols.SymbolFunction)

            # Terrible hack to "auto-decompile" empty functions
            if (
                options.opts.auto_decompile_empty_functions
                and func.instructions[0].isJrRa()
                and func.instructions[1].isNop()
            ):
                c_lines.append("void " + func.getName() + "(void) {")
                c_lines.append("}")
            else:
                if options.opts.compiler in [GCC, SN64]:
                    if options.opts.use_legacy_include_asm:
                        rel_asm_out_dir = asm_out_dir.relative_to(
                            options.opts.nonmatchings_path
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
                        asm_outpath, options.opts.base_path
                    )
                    c_lines.append(f'#pragma GLOBAL_ASM("{rel_asm_outpath}")')
            c_lines.append("")

        Path(c_path).parent.mkdir(parents=True, exist_ok=True)
        with open(c_path, "w") as f:
            f.write("\n".join(c_lines))
        log.write(f"Wrote {self.name} to {c_path}")

    def create_asm_dependencies_file(
        self, c_path: Path, asm_out_dir: Path, is_new_c_file: bool
    ):
        if not options.opts.create_asm_dependencies:
            return
        if not (len(self.global_asm_funcs) > 0 or is_new_c_file):
            return

        assert self.spim_section is not None

        build_path = options.opts.build_path

        dep_path = build_path / c_path.with_suffix(".asmproc.d")
        dep_path.parent.mkdir(parents=True, exist_ok=True)
        with dep_path.open("w") as f:
            o_path = build_path / c_path.with_suffix(".o")
            f.write(f"{o_path}:")
            depend_list = []
            for func in self.spim_section.symbolList:
                func_name = func.getName()

                if func_name in self.global_asm_funcs or is_new_c_file:
                    outpath = asm_out_dir / self.name / (func_name + ".s")
                    depend_list.append(outpath)
                    f.write(f" \\\n    {outpath}")
            f.write("\n")

            for depend_file in depend_list:
                f.write(f"{depend_file}:\n")
