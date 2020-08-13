.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_defeated
/* 01A1F0 8003EDF0 0080302D */  daddu $a2, $a0, $zero
/* 01A1F4 8003EDF4 04A10002 */  bgez  $a1, .L8003EE00
/* 01A1F8 8003EDF8 00A0182D */   daddu $v1, $a1, $zero
/* 01A1FC 8003EDFC 24A3001F */  addiu $v1, $a1, 0x1f
.L8003EE00:
/* 01A200 8003EE00 00031943 */  sra   $v1, $v1, 5
/* 01A204 8003EE04 00032140 */  sll   $a0, $v1, 5
/* 01A208 8003EE08 00A42023 */  subu  $a0, $a1, $a0
/* 01A20C 8003EE0C 00031880 */  sll   $v1, $v1, 2
/* 01A210 8003EE10 00061040 */  sll   $v0, $a2, 1
/* 01A214 8003EE14 00461021 */  addu  $v0, $v0, $a2
/* 01A218 8003EE18 00021100 */  sll   $v0, $v0, 4
/* 01A21C 8003EE1C 00621821 */  addu  $v1, $v1, $v0
/* 01A220 8003EE20 3C02800B */  lui   $v0, 0x800b
/* 01A224 8003EE24 24420F10 */  addiu $v0, $v0, 0xf10
/* 01A228 8003EE28 00621821 */  addu  $v1, $v1, $v0
/* 01A22C 8003EE2C 24020001 */  addiu $v0, $zero, 1
/* 01A230 8003EE30 8C6300B0 */  lw    $v1, 0xb0($v1)
/* 01A234 8003EE34 00821004 */  sllv  $v0, $v0, $a0
/* 01A238 8003EE38 03E00008 */  jr    $ra
/* 01A23C 8003EE3C 00621024 */   and   $v0, $v1, $v0

