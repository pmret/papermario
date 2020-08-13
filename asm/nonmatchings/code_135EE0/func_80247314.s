.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247314
/* 13A654 80247314 28A2003F */  slti  $v0, $a1, 0x3f
