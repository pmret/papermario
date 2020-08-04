.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80030450
/* 00B850 80030450 03E00008 */  jr    $ra
/* 00B854 80030454 00000000 */   nop   

