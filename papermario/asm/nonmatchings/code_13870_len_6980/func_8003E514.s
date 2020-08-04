.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003E514
/* 019914 8003E514 3C01800B */  lui   $at, 0x800b
/* 019918 8003E518 A0240F18 */  sb    $a0, 0xf18($at)
/* 01991C 8003E51C 03E00008 */  jr    $ra
/* 019920 8003E520 00000000 */   nop   

