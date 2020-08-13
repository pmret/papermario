.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E59A0
/* 07EE50 800E59A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07EE54 800E59A4 3C048011 */  lui   $a0, 0x8011
/* 07EE58 800E59A8 2484F250 */  addiu $a0, $a0, -0xdb0
/* 07EE5C 800E59AC AFBF0010 */  sw    $ra, 0x10($sp)
/* 07EE60 800E59B0 0C00A580 */  jal   mem_clear
/* 07EE64 800E59B4 24050034 */   addiu $a1, $zero, 0x34
/* 07EE68 800E59B8 0000382D */  daddu $a3, $zero, $zero
/* 07EE6C 800E59BC 3C068011 */  lui   $a2, 0x8011
/* 07EE70 800E59C0 24C6EF40 */  addiu $a2, $a2, -0x10c0
/* 07EE74 800E59C4 3C058011 */  lui   $a1, 0x8011
/* 07EE78 800E59C8 24A5EF10 */  addiu $a1, $a1, -0x10f0
/* 07EE7C 800E59CC 3C048011 */  lui   $a0, 0x8011
/* 07EE80 800E59D0 2484EF28 */  addiu $a0, $a0, -0x10d8
/* 07EE84 800E59D4 3C038011 */  lui   $v1, 0x8011
/* 07EE88 800E59D8 2463F6B8 */  addiu $v1, $v1, -0x948
/* 07EE8C 800E59DC 3C018011 */  lui   $at, 0x8011
/* 07EE90 800E59E0 AC20C944 */  sw    $zero, -0x36bc($at)
.L800E59E4:
/* 07EE94 800E59E4 A4600000 */  sh    $zero, ($v1)
/* 07EE98 800E59E8 AC800000 */  sw    $zero, ($a0)
/* 07EE9C 800E59EC ACA00000 */  sw    $zero, ($a1)
/* 07EEA0 800E59F0 ACC00000 */  sw    $zero, ($a2)
/* 07EEA4 800E59F4 24C60004 */  addiu $a2, $a2, 4
/* 07EEA8 800E59F8 24A50004 */  addiu $a1, $a1, 4
/* 07EEAC 800E59FC 24840004 */  addiu $a0, $a0, 4
/* 07EEB0 800E5A00 24E70001 */  addiu $a3, $a3, 1
/* 07EEB4 800E5A04 28E20005 */  slti  $v0, $a3, 5
/* 07EEB8 800E5A08 1440FFF6 */  bnez  $v0, .L800E59E4
/* 07EEBC 800E5A0C 24630002 */   addiu $v1, $v1, 2
/* 07EEC0 800E5A10 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07EEC4 800E5A14 3C018011 */  lui   $at, 0x8011
/* 07EEC8 800E5A18 AC20C964 */  sw    $zero, -0x369c($at)
/* 07EECC 800E5A1C 3C018011 */  lui   $at, 0x8011
/* 07EED0 800E5A20 AC20C924 */  sw    $zero, -0x36dc($at)
/* 07EED4 800E5A24 03E00008 */  jr    $ra
/* 07EED8 800E5A28 27BD0018 */   addiu $sp, $sp, 0x18

