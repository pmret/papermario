.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC220_E2EB50
/* E2EB50 802BC220 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EB54 802BC224 3C05802C */  lui       $a1, %hi(D_802BCC44)
/* E2EB58 802BC228 24A5CC44 */  addiu     $a1, $a1, %lo(D_802BCC44)
/* E2EB5C 802BC22C AFBF0014 */  sw        $ra, 0x14($sp)
/* E2EB60 802BC230 AFB00010 */  sw        $s0, 0x10($sp)
/* E2EB64 802BC234 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EB68 802BC238 8C900040 */   lw       $s0, 0x40($a0)
/* E2EB6C 802BC23C AE020000 */  sw        $v0, ($s0)
/* E2EB70 802BC240 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2EB74 802BC244 8FB00010 */  lw        $s0, 0x10($sp)
/* E2EB78 802BC248 03E00008 */  jr        $ra
/* E2EB7C 802BC24C 27BD0018 */   addiu    $sp, $sp, 0x18
