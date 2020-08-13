.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetLoadType
/* 0EEE70 802CA4C0 3C028007 */  lui   $v0, 0x8007
/* 0EEE74 802CA4C4 8C42419C */  lw    $v0, 0x419c($v0)
/* 0EEE78 802CA4C8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEE7C 802CA4CC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEE80 802CA4D0 8C83000C */  lw    $v1, 0xc($a0)
/* 0EEE84 802CA4D4 90460167 */  lbu   $a2, 0x167($v0)
/* 0EEE88 802CA4D8 8C650000 */  lw    $a1, ($v1)
/* 0EEE8C 802CA4DC 0C0B2026 */  jal   set_variable
/* 0EEE90 802CA4E0 0006302B */   sltu  $a2, $zero, $a2
/* 0EEE94 802CA4E4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEE98 802CA4E8 24020002 */  addiu $v0, $zero, 2
/* 0EEE9C 802CA4EC 03E00008 */  jr    $ra
/* 0EEEA0 802CA4F0 27BD0018 */   addiu $sp, $sp, 0x18

