.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC32C_E2EC5C
/* E2EC5C 802BC32C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EC60 802BC330 3C05802C */  lui       $a1, %hi(D_802BCCF8_E2F628)
/* E2EC64 802BC334 24A5CCF8 */  addiu     $a1, $a1, %lo(D_802BCCF8_E2F628)
/* E2EC68 802BC338 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2EC6C 802BC33C 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EC70 802BC340 00000000 */   nop
/* E2EC74 802BC344 0C03BCCA */  jal       enable_partner_ai
/* E2EC78 802BC348 00000000 */   nop
/* E2EC7C 802BC34C 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EC80 802BC350 03E00008 */  jr        $ra
/* E2EC84 802BC354 27BD0018 */   addiu    $sp, $sp, 0x18
