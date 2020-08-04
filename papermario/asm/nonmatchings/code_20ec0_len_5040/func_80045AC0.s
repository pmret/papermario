.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80045AC0
/* 020EC0 80045AC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 020EC4 80045AC4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 020EC8 80045AC8 0000202D */  daddu $a0, $zero, $zero
/* 020ECC 80045ACC 3C03800A */  lui   $v1, 0x800a
/* 020ED0 80045AD0 24630BC0 */  addiu $v1, $v1, 0xbc0
.L80045AD4:
/* 020ED4 80045AD4 A4600010 */  sh    $zero, 0x10($v1)
/* 020ED8 80045AD8 AC600018 */  sw    $zero, 0x18($v1)
/* 020EDC 80045ADC 24840001 */  addiu $a0, $a0, 1
/* 020EE0 80045AE0 28820020 */  slti  $v0, $a0, 0x20
/* 020EE4 80045AE4 1440FFFB */  bnez  $v0, .L80045AD4
/* 020EE8 80045AE8 2463001C */   addiu $v1, $v1, 0x1c
/* 020EEC 80045AEC 3C058004 */  lui   $a1, 0x8004
/* 020EF0 80045AF0 24A55BC8 */  addiu $a1, $a1, 0x5bc8
/* 020EF4 80045AF4 0C048C56 */  jal   func_80123158
/* 020EF8 80045AF8 0000202D */   daddu $a0, $zero, $zero
/* 020EFC 80045AFC 0C0117ED */  jal   func_80045FB4
/* 020F00 80045B00 00000000 */   nop   
/* 020F04 80045B04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 020F08 80045B08 03E00008 */  jr    $ra
/* 020F0C 80045B0C 27BD0018 */   addiu $sp, $sp, 0x18

/* 020F10 80045B10 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020F14 80045B14 AFB10014 */  sw    $s1, 0x14($sp)
/* 020F18 80045B18 0000882D */  daddu $s1, $zero, $zero
/* 020F1C 80045B1C AFB00010 */  sw    $s0, 0x10($sp)
/* 020F20 80045B20 3C10800A */  lui   $s0, 0x800a
/* 020F24 80045B24 26100BC0 */  addiu $s0, $s0, 0xbc0
/* 020F28 80045B28 AFBF0018 */  sw    $ra, 0x18($sp)
.L80045B2C:
/* 020F2C 80045B2C 8E040018 */  lw    $a0, 0x18($s0)
/* 020F30 80045B30 50800004 */  beql  $a0, $zero, .L80045B44
/* 020F34 80045B34 A6000010 */   sh    $zero, 0x10($s0)
/* 020F38 80045B38 0C00AB4B */  jal   heap_free
/* 020F3C 80045B3C 00000000 */   nop   
/* 020F40 80045B40 A6000010 */  sh    $zero, 0x10($s0)
.L80045B44:
/* 020F44 80045B44 26310001 */  addiu $s1, $s1, 1
/* 020F48 80045B48 2A220020 */  slti  $v0, $s1, 0x20
/* 020F4C 80045B4C 1440FFF7 */  bnez  $v0, .L80045B2C
/* 020F50 80045B50 2610001C */   addiu $s0, $s0, 0x1c
/* 020F54 80045B54 8FBF0018 */  lw    $ra, 0x18($sp)
/* 020F58 80045B58 8FB10014 */  lw    $s1, 0x14($sp)
/* 020F5C 80045B5C 8FB00010 */  lw    $s0, 0x10($sp)
/* 020F60 80045B60 03E00008 */  jr    $ra
/* 020F64 80045B64 27BD0020 */   addiu $sp, $sp, 0x20

