.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246288
/* 1395C8 80246288 0C0511F8 */  jal   func_801447E0
/* 1395CC 8024628C 0260A82D */   daddu $s5, $s3, $zero
/* 1395D0 80246290 3C048025 */  lui   $a0, 0x8025
/* 1395D4 80246294 00902021 */  addu  $a0, $a0, $s0
