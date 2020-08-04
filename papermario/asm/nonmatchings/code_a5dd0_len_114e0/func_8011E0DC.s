.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011E0DC
/* 0B47DC 8011E0DC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B47E0 8011E0E0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0B47E4 8011E0E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0B47E8 8011E0E8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B47EC 8011E0EC AFB00010 */  sw    $s0, 0x10($sp)
/* 0B47F0 8011E0F0 848200F6 */  lh    $v0, 0xf6($a0)
/* 0B47F4 8011E0F4 00A0902D */  daddu $s2, $a1, $zero
/* 0B47F8 8011E0F8 14520003 */  bne   $v0, $s2, .L8011E108
/* 0B47FC 8011E0FC 0000882D */   daddu $s1, $zero, $zero
/* 0B4800 8011E100 0804784E */  j     .L8011E138
/* 0B4804 8011E104 0080102D */   daddu $v0, $a0, $zero

.L8011E108:
/* 0B4808 8011E108 0080802D */  daddu $s0, $a0, $zero
.L8011E10C:
/* 0B480C 8011E10C 8E040004 */  lw    $a0, 4($s0)
/* 0B4810 8011E110 50800005 */  beql  $a0, $zero, .L8011E128
/* 0B4814 8011E114 26310001 */   addiu $s1, $s1, 1
/* 0B4818 8011E118 0C047837 */  jal   func_8011E0DC
/* 0B481C 8011E11C 0240282D */   daddu $a1, $s2, $zero
/* 0B4820 8011E120 14400005 */  bnez  $v0, .L8011E138
/* 0B4824 8011E124 26310001 */   addiu $s1, $s1, 1
.L8011E128:
/* 0B4828 8011E128 2A220020 */  slti  $v0, $s1, 0x20
/* 0B482C 8011E12C 1440FFF7 */  bnez  $v0, .L8011E10C
/* 0B4830 8011E130 26100004 */   addiu $s0, $s0, 4
/* 0B4834 8011E134 0000102D */  daddu $v0, $zero, $zero
.L8011E138:
/* 0B4838 8011E138 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0B483C 8011E13C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0B4840 8011E140 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B4844 8011E144 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B4848 8011E148 03E00008 */  jr    $ra
/* 0B484C 8011E14C 27BD0020 */   addiu $sp, $sp, 0x20

