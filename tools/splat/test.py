from spimdisasm.common import FileSectionType

from split import *
import unittest
import io
import filecmp
from util import symbols, options
import spimdisasm
from segtypes.common.rodata import CommonSegRodata
from segtypes.common.code import CommonSegCode
from segtypes.common.c import CommonSegC
from segtypes.common.bss import CommonSegBss
import difflib


class Testing(unittest.TestCase):
    def compare_files(self, test_path, ref_path):
        with io.open(test_path) as test_f, io.open(ref_path) as ref_f:
            self.assertListEqual(list(test_f), list(ref_f))

    def get_same_files(self, dcmp, out):
        for name in dcmp.same_files:
            out.append((name, dcmp.left, dcmp.right))

        for sub_dcmp in dcmp.subdirs.values():
            self.get_same_files(sub_dcmp, out)

    def get_diff_files(self, dcmp, out):
        for name in dcmp.diff_files:
            out.append((name, dcmp.left, dcmp.right))

        for sub_dcmp in dcmp.subdirs.values():
            self.get_diff_files(sub_dcmp, out)

    def get_left_only_files(self, dcmp, out):
        for name in dcmp.left_only:
            out.append((name, dcmp.left, dcmp.right))

        for sub_dcmp in dcmp.subdirs.values():
            self.get_left_only_files(sub_dcmp, out)

    def get_right_only_files(self, dcmp, out):
        for name in dcmp.right_only:
            out.append((name, dcmp.left, dcmp.right))

        for sub_dcmp in dcmp.subdirs.values():
            self.get_right_only_files(sub_dcmp, out)

    def test_basic_app(self):
        spimdisasm.common.GlobalConfig.ASM_GENERATED_BY = False
        main(["test/basic_app/splat.yaml"], None, None)

        comparison = filecmp.dircmp("test/basic_app/split", "test/basic_app/expected")

        diff_files: List[Tuple[str, str, str]] = []
        self.get_diff_files(comparison, diff_files)

        same_files: List[Tuple[str, str, str]] = []
        self.get_same_files(comparison, same_files)

        left_only_files: List[Tuple[str, str, str]] = []
        self.get_left_only_files(comparison, left_only_files)

        right_only_files: List[Tuple[str, str, str]] = []
        self.get_right_only_files(comparison, right_only_files)

        print("same_files", same_files)
        print("diff_files", diff_files)
        print("left_only_files", left_only_files)
        print("right_only_files", right_only_files)

        # if the files are different print out the difference
        for file in diff_files:
            # can't diff binary
            if file[0] == ".splache":
                continue
            with open(f"{file[1]}/{file[0]}") as file1:
                file1_lines = file1.readlines()
            with open(f"{file[2]}/{file[0]}") as file2:
                file2_lines = file2.readlines()

            for line in difflib.unified_diff(
                file1_lines, file2_lines, fromfile="file1", tofile="file2", lineterm=""
            ):
                print(line)

        assert len(diff_files) == 0
        assert len(left_only_files) == 0
        assert len(right_only_files) == 0


def test_init():
    options_dict = {
        "options": {
            "platform": "n64",
            "basename": "basic_app",
            "base_path": ".",
            "build_path": "build",
            "target_path": "build/main.bin",
            "asm_path": "split/asm",
            "src_path": "split/src",
            "ld_script_path": "split/basic_app.ld",
            "cache_path": "split/.splache",
            "symbol_addrs_path": "split/generated.symbols.txt",
            "undefined_funcs_auto_path": "split/undefined_funcs_auto.txt",
            "undefined_syms_auto_path": "split/undefined_syms_auto.txt",
        },
        "segments": [
            {
                "name": "basic_app",
                "type": "code",
                "start": 0,
                "vram": 0x400000,
                "subalign": 4,
                "subsegments": [[0, "data"], [0x1DC, "c", "main"], [0x1FC, "data"]],
            },
            [0x1290],
        ],
    }
    options.initialize(options_dict, ["./test/basic_app/splat.yaml"], [], False)


class Symbols(unittest.TestCase):
    def test_check_valid_type(self):
        disassembler_instance.create_disassembler_instance("n64")

        # first char is uppercase
        assert symbols.check_valid_type("Symbol")

        splat_sym_types = {"func", "jtbl", "jtbl_label", "label"}

        for type in splat_sym_types:
            assert symbols.check_valid_type(type)

        spim_types = [
            "char*",
            "u32",
            "Vec3f",
            "u8",
            "char",
            "u16",
            "f32",
            "u64",
            "asciz",
            "s8",
            "s64",
            "f64",
            "s16",
            "s32",
        ]

        for type in spim_types:
            assert symbols.check_valid_type(type)

    def test_add_symbol_to_spim_segment(self):
        segment = spimdisasm.common.SymbolsSegment(
            context=spimdisasm.common.Context(),
            vromStart=0x0,
            vromEnd=0x10,
            vramStart=0x40000000 + 0x0,
            vramEnd=0x40000000 + 0x10,
        )
        sym = symbols.Symbol(0x40000000)
        sym.user_declared = False
        sym.defined = True
        sym.rom = 0x0
        sym.type = "func"
        result = symbols.add_symbol_to_spim_segment(segment, sym)
        assert result.type == spimdisasm.common.SymbolSpecialType.function
        assert sym.user_declared == result.isUserDeclared
        assert sym.defined == result.isDefined

    def test_add_symbol_to_spim_section(self):
        section = spimdisasm.mips.sections.SectionBase(
            context=spimdisasm.common.Context(),
            vromStart=0x0,
            vromEnd=0x10,
            vram=0x40000000,
            filename="test",
            words=[],
            sectionType=FileSectionType.Text,
            segmentVromStart=0x0,
            overlayCategory=None,
        )
        sym = symbols.Symbol(0x100)
        sym.type = "func"
        sym.user_declared = False
        sym.defined = True
        result = symbols.add_symbol_to_spim_section(section, sym)
        assert result.type == spimdisasm.common.SymbolSpecialType.function
        assert sym.user_declared == result.isUserDeclared
        assert sym.defined == result.isDefined

    def test_create_symbol_from_spim_symbol(self):
        # need to init otherwise options.opts isn't defined.
        # used in initializing a Segment
        test_init()

        segment = Segment(
            rom_start=0x0,
            rom_end=0x100,
            type="func",
            name="MyFunc",
            vram_start=0x40000000,
            args=[],
            yaml=None,
        )
        context_sym = spimdisasm.common.ContextSymbol(address=0)
        result = symbols.create_symbol_from_spim_symbol(segment, context_sym)
        assert result.referenced
        assert result.extract
        assert result.name == "D_0"


def get_yaml():
    return {
        "name": "basic_app",
        "type": "code",
        "start": 0,
        "vram": 0x400000,
        "subalign": 4,
        "subsegments": [[0, "data"], [0x1DC, "c", "main"], [0x1FC, "data"]],
    }


class Rodata(unittest.TestCase):
    def test_disassemble_data(self):
        test_init()
        common_seg_rodata = CommonSegRodata(
            rom_start=0x0,
            rom_end=0x100,
            type=".rodata",
            name="MyRodata",
            vram_start=0x400,
            args=None,
            yaml=None,
        )
        rom_data = []
        for i in range(0x100):
            rom_data.append(i)
        common_seg_rodata.disassemble_data(bytes(rom_data))
        assert common_seg_rodata.spim_section is not None
        assert common_seg_rodata.spim_section.get_section().words[0] == 0x0010203
        assert symbols.get_all_symbols()[0].vram_start == 0x400
        assert symbols.get_all_symbols()[0].segment == common_seg_rodata
        assert symbols.get_all_symbols()[0].linker_section == ".rodata"

    def test_get_possible_text_subsegment_for_symbol(self):
        context = spimdisasm.common.Context()

        result_symbol_addr = 0x2DC

        # use SymbolRodata to test migration
        rodata_sym = spimdisasm.mips.symbols.SymbolRodata(
            context=context,
            vromStart=0x100,
            vromEnd=0x200,
            inFileOffset=0,
            vram=0x100,
            words=[0, 1, 2, 3, 4, 5, 6, 7],
            segmentVromStart=0,
            overlayCategory=None,
        )
        rodata_sym.contextSym.forceMigration = True

        context_sym = spimdisasm.common.ContextSymbol(address=0)
        context_sym.address = result_symbol_addr

        rodata_sym.contextSym.referenceFunctions = {context_sym}
        # Segment __init__ requires opts to be initialized
        test_init()

        common_seg_rodata = CommonSegRodata(
            rom_start=0x0,
            rom_end=0x100,
            type=".rodata",
            name="MyRodata",
            vram_start=0x400,
            args=None,
            yaml=None,
        )

        common_seg_rodata.parent = CommonSegCode(
            rom_start=0x0,
            rom_end=0x200,
            type="code",
            name="MyCode",
            vram_start=0x100,
            args=[],
            yaml=get_yaml(),
        )

        result = common_seg_rodata.get_possible_text_subsegment_for_symbol(rodata_sym)
        assert result is not None
        assert type(result[0]) == CommonSegC
        assert result[1].address == result_symbol_addr


class Bss(unittest.TestCase):
    def test_disassemble_data(self):
        # Segment __init__ requires opts to be initialized
        test_init()

        bss = CommonSegBss(
            rom_start=0x0,
            rom_end=0x100,
            type=".bss",
            name=None,
            vram_start=0x40000000,
            args=None,
            yaml=None,
        )

        bss.parent = CommonSegCode(
            rom_start=0x0,
            rom_end=0x200,
            type="code",
            name="MyCode",
            vram_start=0x100,
            args=[],
            yaml=get_yaml(),
        )

        rom_bytes = bytes([0, 1, 2, 3, 4, 5, 6, 7])
        bss.disassemble_data(rom_bytes)

        assert bss.spim_section is not None

        assert isinstance(
            bss.spim_section.get_section(), spimdisasm.mips.sections.SectionBss
        )
        assert bss.spim_section.get_section().bssVramStart == 0x40000000
        assert bss.spim_section.get_section().bssVramEnd == 0x300


class SymbolsInitialize(unittest.TestCase):
    def test_attrs(self):
        import pathlib

        symbols.reset_symbols()
        test_init()

        sym_addrs_lines = [
            "func_1 = 0x100; // type:func size:10 rom:100 segment:test_segment name_end:the_name_end "
        ]

        all_segments = [
            Segment(
                rom_start=0x100,
                rom_end=0x200,
                type="func",
                name="test_segment",
                vram_start=0x300,
                args=[],
                yaml={},
            )
        ]

        symbols.handle_sym_addrs(
            pathlib.Path("/tmp/thing"), sym_addrs_lines, all_segments
        )
        assert symbols.all_symbols[0].given_name == "func_1"
        assert symbols.all_symbols[0].type == "func"
        assert symbols.all_symbols[0].given_size == 10
        assert symbols.all_symbols[0].rom == 100
        assert symbols.all_symbols[0].segment == all_segments[0]
        assert symbols.all_symbols[0].given_name_end == "the_name_end"

    def test_boolean_attrs(self):
        import pathlib

        symbols.reset_symbols()
        test_init()

        sym_addrs_lines = [
            "func_1 = 0x100; // defined:True extract:True force_migration:True force_not_migration:True "
            "allow_addend:True dont_allow_addend:True"
        ]

        all_segments = [
            Segment(
                rom_start=0x100,
                rom_end=0x200,
                type="func",
                name="test_segment",
                vram_start=0x300,
                args=[],
                yaml={},
            )
        ]

        symbols.handle_sym_addrs(
            pathlib.Path("/tmp/thing"), sym_addrs_lines, all_segments
        )
        assert symbols.all_symbols[0].defined == True
        assert symbols.all_symbols[0].force_migration == True
        assert symbols.all_symbols[0].force_not_migration == True
        assert symbols.all_symbols[0].allow_addend == True
        assert symbols.all_symbols[0].dont_allow_addend == True

    # test spim ban range
    def test_ignore(self):
        import pathlib

        symbols.reset_symbols()
        test_init()

        sym_addrs_lines = ["func_1 = 0x100; // ignore:True size:4"]

        all_segments = [
            Segment(
                rom_start=0x100,
                rom_end=0x200,
                type="func",
                name="test_segment",
                vram_start=0x300,
                args=[],
                yaml={},
            )
        ]

        symbols.handle_sym_addrs(
            pathlib.Path("/tmp/thing"), sym_addrs_lines, all_segments
        )
        assert symbols.spim_context.bannedRangedSymbols[0].start == 0x100
        assert symbols.spim_context.bannedRangedSymbols[0].end == 0x100 + 4


class InitializeSpimContext(unittest.TestCase):
    def test_overlay(self):
        symbols.reset_symbols()
        test_init()

        yaml = {
            "name": "boot",
            "type": "code",
            "start": 4096,
            "vram": 2147484672,
            "bss_size": 128,
            "exclusive_ram_id": "overlay",
            "subsegments": [
                [4096, "c", "main"],
                [4336, "hasm", "handwritten"],
                [4352, "data", "main"],
                [4368, "rodata", "main"],
                {"type": "bss", "vram": 2147484992, "name": "main"},
            ],
        }

        all_segments: List["Segment"] = [
            CommonSegCode(
                rom_start=0x0,
                rom_end=0x200,
                type="code",
                name="main",
                vram_start=0x100,
                args=[],
                yaml=yaml,
            )
        ]

        # force this since it's hard to set up
        all_segments[0].exclusive_ram_id = "overlay"

        symbols.initialize_spim_context(all_segments)
        # spim should have added something to overlaySegments
        assert (
            type(symbols.spim_context.overlaySegments["overlay"][0])
            == spimdisasm.common.SymbolsSegment
        )

    # test globalSegment settings
    def test_global(self):
        symbols.reset_symbols()
        test_init()

        yaml = {
            "name": "boot",
            "type": "code",
            "start": 4096,
            "vram": 2147484672,
            "bss_size": 128,
            "exclusive_ram_id": "overlay",
            "subsegments": [
                [4096, "c", "main"],
                [4336, "hasm", "handwritten"],
                [4352, "data", "main"],
                [4368, "rodata", "main"],
                {"type": "bss", "vram": 2147484992, "name": "main"},
            ],
        }

        all_segments: List["Segment"] = [
            CommonSegCode(
                rom_start=0x0,
                rom_end=0x200,
                type="code",
                name="main",
                vram_start=0x100,
                args=[],
                yaml=yaml,
            )
        ]

        assert symbols.spim_context.globalSegment.vramStart == 2147483648
        assert symbols.spim_context.globalSegment.vramEnd == 2147487744
        symbols.initialize_spim_context(all_segments)
        assert symbols.spim_context.globalSegment.vramStart == 256
        assert symbols.spim_context.globalSegment.vramEnd == 896


if __name__ == "__main__":
    unittest.main()
