from split import *
import unittest
import io
import filecmp
import pprint
from util import symbols, options
import spimdisasm
from segtypes.common.rodata import CommonSegRodata
from segtypes.common.code import CommonSegCode
from segtypes.common.c import CommonSegC
from segtypes.common.bss import CommonSegBss
import difflib
from segtypes.common.group import CommonSegGroup


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
            file1_lines = []
            file2_lines = []
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
        assert symbols.check_valid_type("Symbol") == True

        splat_sym_types = {"func", "jtbl", "jtbl_label", "label"}

        for type in splat_sym_types:
            assert symbols.check_valid_type(type) == True

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
            assert symbols.check_valid_type(type) == True

    def test_add_symbol_to_spim_segment(self):
        context = None
        vromStart = 0x0
        vromEnd = 0x10
        vramStart = 0x40000000 + 0x0
        vramEnd = 0x40000000 + 0x10
        segment = spimdisasm.common.SymbolsSegment(
            context=context,
            vromStart=vromStart,
            vromEnd=vromEnd,
            vramStart=vramStart,
            vramEnd=vramEnd,
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
        context = spimdisasm.common.Context()
        section = spimdisasm.mips.sections.SectionBase(
            context=context,
            vromStart=0x100,
            vromEnd=None,
            vram=None,
            filename=None,
            words=None,
            sectionType=None,
            segmentVromStart=None,
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
        rom_start = 0x0
        rom_end = 0x100
        type = "func"
        name = "MyFunc"
        vram_start = 0x40000000
        args = None
        yaml = None

        # need to init otherwise options.opts isn't defined.
        # used in initializing a Segment
        test_init()

        segment = Segment(
            rom_start=rom_start,
            rom_end=rom_end,
            type=type,
            name=name,
            vram_start=vram_start,
            args=[],
            yaml=yaml,
        )
        context_sym = spimdisasm.common.ContextSymbol(address=0)
        result = symbols.create_symbol_from_spim_symbol(segment, context_sym)
        assert result.referenced == True
        assert result.extract == True
        assert result.name == "D_0"


def get_yaml():
    yaml = {
        "name": "basic_app",
        "type": "code",
        "start": 0,
        "vram": 0x400000,
        "subalign": 4,
        "subsegments": [[0, "data"], [0x1DC, "c", "main"], [0x1FC, "data"]],
    }
    return yaml


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
        for i in range(0, 0x100):
            rom_data.append(i)
        common_seg_rodata.disassemble_data(bytes(rom_data))
        assert common_seg_rodata.spim_section is not None
        assert common_seg_rodata.spim_section.words[0] == 0x0010203
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
            vromEnd=None,
            inFileOffset=None,
            vram=0x100,
            words=[0, 1, 2, 3, 4, 5, 6, 7],
            segmentVromStart=None,
            overlayCategory=None,
        )
        rodata_sym.contextSym.forceMigration = True

        context_sym = spimdisasm.common.ContextSymbol(address=0)
        context_sym.address = result_symbol_addr

        rodata_sym.contextSym.referenceFunctions = [context_sym]
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

        assert isinstance(bss.spim_section, spimdisasm.mips.sections.SectionBss)
        assert bss.spim_section.bssVramStart == 0x40000000
        assert bss.spim_section.bssVramEnd == 0x300


if __name__ == "__main__":
    unittest.main()
