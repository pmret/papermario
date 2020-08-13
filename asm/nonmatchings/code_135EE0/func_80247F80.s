.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247F80
/* 13B2C0 80247F80 3C01800A */  lui   $at, 0x800a
/* 13B2C4 80247F84 AC22A66C */  sw    $v0, -0x5994($at)
/* 13B2C8 80247F88 000B1400 */  sll   $v0, $t3, 0x10
/* 13B2CC 80247F8C AC8A0008 */  sw    $t2, 8($a0)
/* 13B2D0 80247F90 240A0064 */  addiu $t2, $zero, 0x64
