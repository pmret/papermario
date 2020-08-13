.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80052BC0
/* 02DFC0 80052BC0 3C02B65C */  lui   $v0, 0xb65c
/* 02DFC4 80052BC4 34426D59 */  ori   $v0, $v0, 0x6d59
/* 02DFC8 80052BC8 00820018 */  mult  $a0, $v0
/* 02DFCC 80052BCC 00002810 */  mfhi  $a1
/* 02DFD0 80052BD0 00A41821 */  addu  $v1, $a1, $a0
/* 02DFD4 80052BD4 00031B03 */  sra   $v1, $v1, 0xc
/* 02DFD8 80052BD8 000427C3 */  sra   $a0, $a0, 0x1f
/* 02DFDC 80052BDC 00641823 */  subu  $v1, $v1, $a0
/* 02DFE0 80052BE0 00031040 */  sll   $v0, $v1, 1
/* 02DFE4 80052BE4 00431021 */  addu  $v0, $v0, $v1
/* 02DFE8 80052BE8 000210C0 */  sll   $v0, $v0, 3
/* 02DFEC 80052BEC 00431023 */  subu  $v0, $v0, $v1
/* 02DFF0 80052BF0 03E00008 */  jr    $ra
/* 02DFF4 80052BF4 000210C0 */   sll   $v0, $v0, 3

