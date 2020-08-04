.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248BCC
/* 13BF0C 80248BCC 0C090AEB */  jal   func_80242BAC
/* 13BF10 80248BD0 01463021 */   addu  $a2, $t2, $a2
/* 13BF14 80248BD4 080922FF */  j     func_80248BFC
/* 13BF18 80248BD8 00000000 */   nop   

.L80248BDC:
/* 13BF1C 80248BDC 2605005D */  addiu $a1, $s0, 0x5d
/* 13BF20 80248BE0 24C60017 */  addiu $a2, $a2, 0x17
