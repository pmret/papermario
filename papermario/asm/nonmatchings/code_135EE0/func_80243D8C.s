.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80243D8C
/* 1370CC 80243D8C 4600018D */  trunc.w.s $f6, $f0
/* 1370D0 80243D90 44053000 */  mfc1  $a1, $f6
/* 1370D4 80243D94 00000000 */  nop   
/* 1370D8 80243D98 30A50FFF */  andi  $a1, $a1, 0xfff
