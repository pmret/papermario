.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80025F44
/* 001344 80025F44 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 001348 80025F48 AFBF0010 */  sw    $ra, 0x10($sp)
/* 00134C 80025F4C 0080382D */  daddu $a3, $a0, $zero
/* 001350 80025F50 3C048009 */  lui   $a0, 0x8009
/* 001354 80025F54 24847D30 */  addiu $a0, $a0, 0x7d30
/* 001358 80025F58 0C00973F */  jal   func_80025CFC
/* 00135C 80025F5C 00000000 */   nop   
.L80025F60:
/* 001360 80025F60 080097D8 */  j     .L80025F60
/* 001364 80025F64 00000000 */   nop   

/* 001368 80025F68 00000000 */  nop   
/* 00136C 80025F6C 00000000 */  nop   

.set reorder
