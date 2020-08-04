.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80056D34
/* 032134 80056D34 24020001 */  addiu $v0, $zero, 1
/* 032138 80056D38 3C018008 */  lui   $at, 0x8008
/* 03213C 80056D3C 03E00008 */  jr    $ra
/* 032140 80056D40 A0228E58 */   sb    $v0, -0x71a8($at)

