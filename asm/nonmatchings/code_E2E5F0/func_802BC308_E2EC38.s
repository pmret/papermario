.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC308_E2EC38
/* E2EC38 802BC308 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EC3C 802BC30C 3C05802C */  lui       $a1, %hi(D_802BCCD4)
/* E2EC40 802BC310 24A5CCD4 */  addiu     $a1, $a1, %lo(D_802BCCD4)
/* E2EC44 802BC314 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2EC48 802BC318 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EC4C 802BC31C 00000000 */   nop
/* E2EC50 802BC320 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EC54 802BC324 03E00008 */  jr        $ra
/* E2EC58 802BC328 27BD0018 */   addiu    $sp, $sp, 0x18
