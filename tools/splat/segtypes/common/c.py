import os
import re
from pathlib import Path
from typing import Optional, Set, List

import spimdisasm

from util import log, options, symbols
from util.compiler import GCC, SN64, IDO
from util.symbols import Symbol

from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from segtypes.common.rodata import CommonSegRodata


STRIP_C_COMMENTS_RE = re.compile(
    r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
    re.DOTALL | re.MULTILINE,
)

C_FUNC_RE = re.compile(
    r"^(?:static\s+)?[^\s]+\s+([^\s(]+)\(([^;)]*)\)[^;]+?{", re.MULTILINE
)

C_GLOBAL_ASM_IDO_RE = re.compile(r"GLOBAL_ASM\(\"(\w+\/)*(\w+)\.s\"\)", re.MULTILINE)


class CommonSegC(CommonSegCodeSubsegment):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.defined_funcs: Set[str] = set()
        self.global_asm_funcs: Set[str] = set()
        self.global_asm_rodata_syms: Set[str] = set()

        self.file_extension = "c"

    @staticmethod
    def strip_c_comments(text):
        def replacer(match):
            s = match.group(0)
            if s.startswith("/"):
                return " "
            else:
                return s

        return re.sub(STRIP_C_COMMENTS_RE, replacer, text)

    @staticmethod
    def get_funcs_defined_in_c(c_file: Path) -> Set[str]:
        with open(c_file, "r") as f:
            text = CommonSegC.strip_c_comments(f.read())

        return set(m.group(1) for m in C_FUNC_RE.finditer(text))

    @staticmethod
    def find_all_instances(string: str, sub: str):
        start = 0
        while True:
            start = string.find(sub, start)
            if start == -1:
                return
            yield start
            start += len(sub)

    @staticmethod
    def get_close_parenthesis(string: str, pos: int):
        paren_count = 0
        while True:
            cur_char = string[pos]
            if cur_char == "(":
                paren_count += 1
            elif cur_char == ")":
                if paren_count == 0:
                    return pos + 1
                else:
                    paren_count -= 1
            pos += 1

    @staticmethod
    def find_include_macro(text: str, macro_name: str):
        for pos in CommonSegC.find_all_instances(text, f"{macro_name}("):
            close_paren_pos = CommonSegC.get_close_parenthesis(
                text, pos + len(f"{macro_name}(")
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
    def find_include_asm(text: str):
        return CommonSegC.find_include_macro(text, "INCLUDE_ASM")

    @staticmethod
    def find_include_rodata(text: str):
        return CommonSegC.find_include_macro(text, "INCLUDE_RODATA")

    @staticmethod
    def get_global_asm_funcs(c_file: Path) -> Set[str]:
        with c_file.open() as f:
            text = CommonSegC.strip_c_comments(f.read())
        if options.opts.compiler in [GCC, SN64]:
            return set(CommonSegC.find_include_asm(text))
        else:
            return set(m.group(2) for m in C_GLOBAL_ASM_IDO_RE.finditer(text))

    @staticmethod
    def get_global_asm_rodata_syms(c_file: Path) -> Set[str]:
        with c_file.open() as f:
            text = CommonSegC.strip_c_comments(f.read())
        if options.opts.compiler in [GCC, SN64]:
            return set(CommonSegC.find_include_rodata(text))
        else:
            return set(m.group(2) for m in C_GLOBAL_ASM_IDO_RE.finditer(text))

    @staticmethod
    def is_text() -> bool:
        return True

    def out_path(self) -> Optional[Path]:
        return options.opts.src_path / self.dir / f"{self.name}.{self.file_extension}"

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
                    self.global_asm_rodata_syms = self.get_global_asm_rodata_syms(path)
                    symbols.to_mark_as_defined.update(self.defined_funcs)
                    symbols.to_mark_as_defined.update(self.global_asm_funcs)
                    symbols.to_mark_as_defined.update(self.global_asm_rodata_syms)

            self.scan_code(rom_bytes)

    def split(self, rom_bytes: bytes):
        if self.rom_start != self.rom_end:
            asm_out_dir = options.opts.nonmatchings_path / self.dir
            asm_out_dir.mkdir(parents=True, exist_ok=True)

            self.print_file_boundaries()

            assert self.spim_section is not None and isinstance(
                self.spim_section.get_section(), spimdisasm.mips.sections.SectionText
            ), f"{self.name}, rom_start:{self.rom_start}, rom_end:{self.rom_end}"

            rodata_section_type = ""
            rodata_spim_segment: Optional[spimdisasm.mips.sections.SectionRodata] = None
            if (
                options.opts.migrate_rodata_to_functions
                and self.rodata_sibling is not None
            ):
                assert isinstance(
                    self.rodata_sibling, CommonSegRodata
                ), self.rodata_sibling.type
                rodata_section_type = (
                    self.rodata_sibling.get_linker_section_linksection()
                )
                if self.rodata_sibling.spim_section is not None:
                    assert isinstance(
                        self.rodata_sibling.spim_section.get_section(),
                        spimdisasm.mips.sections.SectionRodata,
                    )
                    rodata_spim_segment = self.rodata_sibling.spim_section.get_section()

            # Precompute function-rodata pairings
            symbols_entries = (
                spimdisasm.mips.FunctionRodataEntry.getAllEntriesFromSections(
                    self.spim_section.get_section(), rodata_spim_segment
                )
            )

            is_new_c_file = False

            # Check and create the C file
            c_path = self.out_path()
            if c_path:
                if not c_path.exists() and options.opts.create_c_files:
                    self.create_c_file(asm_out_dir, c_path, symbols_entries)
                    is_new_c_file = True

                self.create_asm_dependencies_file(
                    c_path, asm_out_dir, is_new_c_file, symbols_entries
                )

            # Produce the asm files for functions
            for entry in symbols_entries:
                entry.sectionText = self.get_linker_section_linksection()
                entry.sectionRodata = rodata_section_type
                if entry.function is not None:
                    if (
                        entry.function.getName() in self.global_asm_funcs
                        or is_new_c_file
                        or options.opts.disassemble_all
                    ):
                        func_sym = self.get_symbol(
                            entry.function.vram,
                            in_segment=True,
                            type="func",
                            local_only=True,
                        )
                        assert func_sym is not None

                        self.create_c_asm_file(entry, asm_out_dir, func_sym)
                else:
                    for spim_rodata_sym in entry.rodataSyms:
                        if (
                            spim_rodata_sym.getName() in self.global_asm_rodata_syms
                            or is_new_c_file
                            or options.opts.disassemble_all
                        ):
                            rodata_sym = self.get_symbol(
                                spim_rodata_sym.vram, in_segment=True, local_only=True
                            )
                            assert rodata_sym is not None

                            self.create_unmigrated_rodata_file(
                                spim_rodata_sym, asm_out_dir, rodata_sym
                            )

    def get_c_preamble(self):
        ret = []

        preamble = options.opts.generated_c_preamble
        ret.append(preamble)
        ret.append("")

        return ret

    def check_gaps_in_migrated_rodata(
        self,
        func: spimdisasm.mips.symbols.SymbolFunction,
        rodata_list: List[spimdisasm.mips.symbols.SymbolBase],
    ):
        for index in range(len(rodata_list) - 1):
            rodata_sym = rodata_list[index]
            next_rodata_sym = rodata_list[index + 1]

            if rodata_sym.vramEnd != next_rodata_sym.vram:
                log.write(
                    f"\nA gap was detected in migrated rodata symbols!", status="warn"
                )
                log.write(
                    f"\t In function '{func.getName()}' (0x{func.vram:08X}), gap detected between '{rodata_sym.getName()}' (0x{rodata_sym.vram:08X}) and '{next_rodata_sym.getName()}' (0x{next_rodata_sym.vram:08X})"
                )
                log.write(
                    f"\t The address of the missing rodata symbol is 0x{rodata_sym.vramEnd:08X}"
                )
                log.write(
                    f"\t Try to force the migration of that symbol with `force_migration:True` in the symbol_addrs.txt file; or avoid the migration of symbols around this address with `force_not_migration:True`"
                )

    def create_c_asm_file(
        self,
        func_rodata_entry: spimdisasm.mips.FunctionRodataEntry,
        out_dir: Path,
        func_sym: Symbol,
    ):
        outpath = out_dir / self.name / (func_sym.name + ".s")

        # Skip extraction if the file exists and the symbol is marked as extract=false
        if outpath.exists() and not func_sym.extract:
            return

        outpath.parent.mkdir(parents=True, exist_ok=True)

        with outpath.open("w", newline="\n") as f:
            if options.opts.asm_inc_header:
                f.write(
                    options.opts.c_newline.join(options.opts.asm_inc_header.split("\n"))
                )

            func_rodata_entry.writeToFile(f)

            if func_rodata_entry.function is not None:
                self.check_gaps_in_migrated_rodata(
                    func_rodata_entry.function, func_rodata_entry.rodataSyms
                )
                self.check_gaps_in_migrated_rodata(
                    func_rodata_entry.function, func_rodata_entry.lateRodataSyms
                )

        self.log(f"Disassembled {func_sym.name} to {outpath}")

    def create_unmigrated_rodata_file(
        self,
        spim_rodata_sym: spimdisasm.mips.symbols.SymbolBase,
        out_dir: Path,
        rodata_sym: Symbol,
    ):
        outpath = out_dir / self.name / (rodata_sym.name + ".s")

        # Skip extraction if the file exists and the symbol is marked as extract=false
        if outpath.exists() and not rodata_sym.extract:
            return

        outpath.parent.mkdir(parents=True, exist_ok=True)

        with outpath.open("w", newline="\n") as f:
            if options.opts.include_macro_inc:
                f.write('.include "macro.inc"\n\n')
            preamble = options.opts.generated_s_preamble
            if preamble:
                f.write(preamble + "\n")
            assert rodata_sym.linker_section is not None, rodata_sym.name
            f.write(f".section {rodata_sym.linker_section}\n\n")
            f.write(spim_rodata_sym.disassemble())

        self.log(f"Disassembled {rodata_sym.name} to {outpath}")

    def get_c_line_include_macro(
        self,
        spim_sym: spimdisasm.mips.symbols.SymbolBase,
        asm_out_dir: Path,
        macro_name: str,
    ) -> str:
        if options.opts.compiler == IDO:
            # IDO uses the asm processor to embeed assembly, and it doesn't require a special directive to include symbols
            asm_outpath = Path(
                os.path.join(asm_out_dir, self.name, spim_sym.getName() + ".s")
            )
            rel_asm_outpath = os.path.relpath(asm_outpath, options.opts.base_path)
            return f'#pragma GLOBAL_ASM("{rel_asm_outpath}")'

        if options.opts.use_legacy_include_asm:
            rel_asm_out_dir = asm_out_dir.relative_to(options.opts.nonmatchings_path)
            return f'{macro_name}(const s32, "{rel_asm_out_dir / self.name}", {spim_sym.getName()});'

        return f'{macro_name}("{asm_out_dir / self.name}", {spim_sym.getName()});'

    def get_c_lines_for_function(
        self, func: spimdisasm.mips.symbols.SymbolFunction, asm_out_dir: Path
    ) -> List[str]:
        c_lines = []

        # Terrible hack to "auto-decompile" empty functions
        if (
            options.opts.auto_decompile_empty_functions
            and len(func.instructions) == 2
            and func.instructions[0].isReturn()
            and func.instructions[1].isNop()
        ):
            c_lines.append("void " + func.getName() + "(void) {")
            c_lines.append("}")
        else:
            c_lines.append(
                self.get_c_line_include_macro(func, asm_out_dir, "INCLUDE_ASM")
            )
        c_lines.append("")
        return c_lines

    def get_c_lines_for_rodata_sym(
        self, rodata_sym: spimdisasm.mips.symbols.SymbolBase, asm_out_dir: Path
    ):
        c_lines = [
            self.get_c_line_include_macro(rodata_sym, asm_out_dir, "INCLUDE_RODATA")
        ]
        c_lines.append("")
        return c_lines

    def create_c_file(
        self,
        asm_out_dir: Path,
        c_path: Path,
        symbols_entries: List[spimdisasm.mips.FunctionRodataEntry],
    ):
        c_lines = self.get_c_preamble()

        for entry in symbols_entries:
            if entry.function is not None:
                c_lines += self.get_c_lines_for_function(entry.function, asm_out_dir)
            else:
                for rodata_sym in entry.rodataSyms:
                    c_lines += self.get_c_lines_for_rodata_sym(rodata_sym, asm_out_dir)

        c_path.parent.mkdir(parents=True, exist_ok=True)
        with c_path.open("w") as f:
            f.write("\n".join(c_lines))
        log.write(f"Wrote {self.name} to {c_path}")

    def create_asm_dependencies_file(
        self,
        c_path: Path,
        asm_out_dir: Path,
        is_new_c_file: bool,
        symbols_entries: List[spimdisasm.mips.FunctionRodataEntry],
    ):
        if not options.opts.create_asm_dependencies:
            return
        if (
            len(self.global_asm_funcs) + len(self.global_asm_rodata_syms)
        ) == 0 and not is_new_c_file:
            return

        assert self.spim_section is not None

        build_path = options.opts.build_path

        dep_path = build_path / c_path.with_suffix(".asmproc.d")
        dep_path.parent.mkdir(parents=True, exist_ok=True)
        with dep_path.open("w") as f:
            if options.opts.use_o_as_suffix:
                o_path = build_path / c_path.with_suffix(".o")
            else:
                o_path = build_path / c_path.with_suffix(c_path.suffix + ".o")
            f.write(f"{o_path}:")
            depend_list = []
            for entry in symbols_entries:
                if entry.function is not None:
                    func_name = entry.function.getName()

                    if func_name in self.global_asm_funcs or is_new_c_file:
                        outpath = asm_out_dir / self.name / (func_name + ".s")
                        depend_list.append(outpath)
                        f.write(f" \\\n    {outpath}")
                else:
                    for rodata_sym in entry.rodataSyms:
                        rodata_name = rodata_sym.getName()

                        if rodata_name in self.global_asm_rodata_syms or is_new_c_file:
                            outpath = asm_out_dir / self.name / (rodata_name + ".s")
                            depend_list.append(outpath)
                            f.write(f" \\\n    {outpath}")

            f.write("\n")

            for depend_file in depend_list:
                f.write(f"{depend_file}:\n")
