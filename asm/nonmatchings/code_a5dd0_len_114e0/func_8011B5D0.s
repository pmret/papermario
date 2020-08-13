.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011B5D0
/* 0B1CD0 8011B5D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B1CD4 8011B5D4 3084FFFF */  andi  $a0, $a0, 0xffff
/* 0B1CD8 8011B5D8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0B1CDC 8011B5DC AFB10014 */  sw    $s1, 0x14($sp)
/* 0B1CE0 8011B5E0 0C046C24 */  jal   func_8011B090
/* 0B1CE4 8011B5E4 AFB00010 */   sw    $s0, 0x10($sp)
/* 0B1CE8 8011B5E8 0C046C70 */  jal   func_8011B1C0
/* 0B1CEC 8011B5EC 0040202D */   daddu $a0, $v0, $zero
/* 0B1CF0 8011B5F0 0040882D */  daddu $s1, $v0, $zero
/* 0B1CF4 8011B5F4 9230009C */  lbu   $s0, 0x9c($s1)
/* 0B1CF8 8011B5F8 96220000 */  lhu   $v0, ($s1)
/* 0B1CFC 8011B5FC 9223009D */  lbu   $v1, 0x9d($s1)
/* 0B1D00 8011B600 3042FFFB */  andi  $v0, $v0, 0xfffb
/* 0B1D04 8011B604 0070182A */  slt   $v1, $v1, $s0
/* 0B1D08 8011B608 14600010 */  bnez  $v1, .L8011B64C
/* 0B1D0C 8011B60C A6220000 */   sh    $v0, ($s1)
.L8011B610:
/* 0B1D10 8011B610 0C046B4C */  jal   get_model_from_list_index
/* 0B1D14 8011B614 0200202D */   daddu $a0, $s0, $zero
/* 0B1D18 8011B618 0040202D */  daddu $a0, $v0, $zero
/* 0B1D1C 8011B61C 94850000 */  lhu   $a1, ($a0)
/* 0B1D20 8011B620 8C830004 */  lw    $v1, 4($a0)
/* 0B1D24 8011B624 34A20008 */  ori   $v0, $a1, 8
/* 0B1D28 8011B628 10600003 */  beqz  $v1, .L8011B638
/* 0B1D2C 8011B62C A4820000 */   sh    $v0, ($a0)
/* 0B1D30 8011B630 34A21008 */  ori   $v0, $a1, 0x1008
/* 0B1D34 8011B634 A4820000 */  sh    $v0, ($a0)
.L8011B638:
/* 0B1D38 8011B638 9222009D */  lbu   $v0, 0x9d($s1)
/* 0B1D3C 8011B63C 26100001 */  addiu $s0, $s0, 1
/* 0B1D40 8011B640 0050102A */  slt   $v0, $v0, $s0
/* 0B1D44 8011B644 1040FFF2 */  beqz  $v0, .L8011B610
/* 0B1D48 8011B648 00000000 */   nop   
.L8011B64C:
/* 0B1D4C 8011B64C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0B1D50 8011B650 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B1D54 8011B654 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B1D58 8011B658 03E00008 */  jr    $ra
/* 0B1D5C 8011B65C 27BD0020 */   addiu $sp, $sp, 0x20

