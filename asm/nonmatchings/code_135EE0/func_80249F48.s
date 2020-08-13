.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249F48
/* 13D288 80249F48 8FAB0078 */  lw    $t3, 0x78($sp)
/* 13D28C 80249F4C 8FAA0054 */  lw    $t2, 0x54($sp)
/* 13D290 80249F50 256B0004 */  addiu $t3, $t3, 4
/* 13D294 80249F54 254A0001 */  addiu $t2, $t2, 1
/* 13D298 80249F58 AFAB0078 */  sw    $t3, 0x78($sp)
/* 13D29C 80249F5C AFAA0054 */  sw    $t2, 0x54($sp)
.L80249F60:
/* 13D2A0 80249F60 8FAB007C */  lw    $t3, 0x7c($sp)
/* 13D2A4 80249F64 8D620008 */  lw    $v0, 8($t3)
/* 13D2A8 80249F68 26520001 */  addiu $s2, $s2, 1
/* 13D2AC 80249F6C 0242102A */  slt   $v0, $s2, $v0
/* 13D2B0 80249F70 1440FF33 */  bnez  $v0, .L80249C40
/* 13D2B4 80249F74 00000000 */   nop   
.L80249F78:
/* 13D2B8 80249F78 27DE0001 */  addiu $fp, $fp, 1
/* 13D2BC 80249F7C 8FAA007C */  lw    $t2, 0x7c($sp)
/* 13D2C0 80249F80 2BC20014 */  slti  $v0, $fp, 0x14
/* 13D2C4 80249F84 254A000C */  addiu $t2, $t2, 0xc
/* 13D2C8 80249F88 1440FF1C */  bnez  $v0, .L80249BFC
/* 13D2CC 80249F8C AFAA007C */   sw    $t2, 0x7c($sp)
.L80249F90:
/* 13D2D0 80249F90 8FAB0050 */  lw    $t3, 0x50($sp)
/* 13D2D4 80249F94 256B0001 */  addiu $t3, $t3, 1
/* 13D2D8 80249F98 29620003 */  slti  $v0, $t3, 3
/* 13D2DC 80249F9C 1440FF13 */  bnez  $v0, .L80249BEC
/* 13D2E0 80249FA0 AFAB0050 */   sw    $t3, 0x50($sp)
/* 13D2E4 80249FA4 3C09800A */  lui   $t1, 0x800a
/* 13D2E8 80249FA8 2529A66C */  addiu $t1, $t1, -0x5994
/* 13D2EC 80249FAC 8FAA00AC */  lw    $t2, 0xac($sp)
/* 13D2F0 80249FB0 8FAB00B0 */  lw    $t3, 0xb0($sp)
