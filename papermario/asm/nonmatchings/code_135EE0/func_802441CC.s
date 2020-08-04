.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802441CC
/* 13750C 802441CC A462000C */  sh    $v0, 0xc($v1)
/* 137510 802441D0 2694FFD3 */  addiu $s4, $s4, -0x2d
/* 137514 802441D4 2673FFE0 */  addiu $s3, $s3, -0x20
