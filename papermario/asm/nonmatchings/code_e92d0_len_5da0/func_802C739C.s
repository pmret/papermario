.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802C739C
/* 0EBD4C 802C739C 8C82000C */  lw    $v0, 0xc($a0)
/* 0EBD50 802C73A0 8C420000 */  lw    $v0, ($v0)
/* 0EBD54 802C73A4 AC820160 */  sw    $v0, 0x160($a0)
/* 0EBD58 802C73A8 03E00008 */  jr    $ra
/* 0EBD5C 802C73AC 24020002 */   addiu $v0, $zero, 2

