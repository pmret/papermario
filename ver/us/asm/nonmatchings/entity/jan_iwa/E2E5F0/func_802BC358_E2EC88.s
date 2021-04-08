.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC358_E2EC88
/* E2EC88 802BC358 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EC8C 802BC35C 3C05802C */  lui       $a1, %hi(D_802BCD1C_E2F64C)
/* E2EC90 802BC360 24A5CD1C */  addiu     $a1, $a1, %lo(D_802BCD1C_E2F64C)
/* E2EC94 802BC364 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2EC98 802BC368 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EC9C 802BC36C 00000000 */   nop
/* E2ECA0 802BC370 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2ECA4 802BC374 03E00008 */  jr        $ra
/* E2ECA8 802BC378 27BD0018 */   addiu    $sp, $sp, 0x18
