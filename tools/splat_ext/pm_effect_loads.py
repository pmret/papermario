from yaml.loader import Loader
from segtypes.n64.segment import N64Segment
from util import options
import yaml

class N64SegPm_effect_loads(N64Segment):
    effects = []

    @staticmethod
    def get_effect_asm(index, name):
        return f""".include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel {name}
/* 00 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 04 AFA40010 */  sw        $a0, 0x10($sp)
/* 08 AFA50014 */  sw        $a1, 0x14($sp)
/* 0C AFA60018 */  sw        $a2, 0x18($sp)
/* 10 AFA7001C */  sw        $a3, 0x1c($sp)
/* 14 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 18 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 1C E7B00028 */  swc1      $f16, 0x28($sp)
/* 20 AFBF002C */  sw        $ra, 0x2c($sp)
/* 24 0C016959 */  jal       load_effect
/* 28 ???????? */   addiu    $a0, $zero, 0x{index:X}
/* 2C 8FA40010 */  lw        $a0, 0x10($sp)
/* 30 8FA50014 */  lw        $a1, 0x14($sp)
/* 34 8FA60018 */  lw        $a2, 0x18($sp)
/* 38 8FA7001C */  lw        $a3, 0x1c($sp)
/* 3C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 40 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 44 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 48 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 50 3C01???? */  lui       $at, %hi(gEffectTable + 0x{index * 24:X})
/* 54 8C21???? */  lw        $at, %lo(gEffectTable + 0x{index * 24:X})($at)
/* 58 00200008 */  jr        $at
/* 5C 00000000 */   nop
"""

    def effect_path(self, effect):
        return options.get_build_path() / "asm" / "effects" / f"{effect}.s"

    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yml)

        with open(options.get_asm_path() / ".." / "effects.yaml") as f:
            self.effects = yaml.load(f.read(), Loader=yaml.SafeLoader)

    def split(self, rom_bytes):
        for i, effect in enumerate(self.effects):
            effect_asm = N64SegPm_effect_loads.get_effect_asm(i, effect)

            self.effect_path("").parent.mkdir(parents=True, exist_ok=True)

            with open(self.effect_path(effect), "w") as f:
                f.write(effect_asm)

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        ret = []

        for effect in self.effects:
            ret.append(LinkerEntry(
                self,
                [self.effect_path(effect)],
                self.effect_path(effect),
                ".text"
            ))

        return ret
