.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC250_E2EB80
/* E2EB80 802BC250 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EB84 802BC254 3C05802C */  lui       $a1, %hi(D_802BCC68)
/* E2EB88 802BC258 24A5CC68 */  addiu     $a1, $a1, %lo(D_802BCC68)
/* E2EB8C 802BC25C AFBF0010 */  sw        $ra, 0x10($sp)
/* E2EB90 802BC260 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EB94 802BC264 00000000 */   nop
/* E2EB98 802BC268 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EB9C 802BC26C 03E00008 */  jr        $ra
/* E2EBA0 802BC270 27BD0018 */   addiu    $sp, $sp, 0x18
