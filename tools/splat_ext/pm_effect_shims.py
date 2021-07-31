from yaml.loader import Loader
from segtypes.n64.segment import N64Segment
from util import options
import yaml

class N64SegPm_effect_shims(N64Segment):
    shims = []

    @staticmethod
    def get_shim_asm(index, name):
        return f""".include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel {name}
/* 0 3C01E020 */  lui       $at, %hi(effectFuncs + 0x{index * 4:X})
/* 4 8C210694 */  lw        $at, %lo(effectFuncs + 0x{index * 4:X})($at)
/* 8 00200008 */  jr        $at
/* C 00000000 */   nop
"""

    def shim_path(self, shim):
        return options.get_build_path() / "asm" / "effect_shims" / f"{shim}.s"

    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yml)

        with open(options.get_asm_path() / ".." / "effect_shims.yaml") as f:
            self.shims = yaml.load(f.read(), Loader=yaml.SafeLoader)

    def split(self, rom_bytes):
        for i, shim in enumerate(self.shims):
            shim_asm = N64SegPm_effect_shims.get_shim_asm(i, shim)

            self.shim_path("").parent.mkdir(parents=True, exist_ok=True)

            with open(self.shim_path(shim), "w") as f:
                f.write(shim_asm)

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        ret = []

        for shim in self.shims:
            ret.append(LinkerEntry(
                self,
                [self.shim_path(shim)],
                self.shim_path(shim),
                ".text"
            ))

        return ret
