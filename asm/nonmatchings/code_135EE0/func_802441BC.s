.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802441BC
/* 1374FC 802441BC 24050002 */   addiu $a1, $zero, 2
/* 137500 802441C0 08091076 */  j     func_802441D8
