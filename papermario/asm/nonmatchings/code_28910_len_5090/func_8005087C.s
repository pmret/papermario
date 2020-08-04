.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8005087C
/* 02BC7C 8005087C AC850204 */  sw    $a1, 0x204($a0)
/* 02BC80 80050880 03E00008 */  jr    $ra
/* 02BC84 80050884 A0860232 */   sb    $a2, 0x232($a0)

