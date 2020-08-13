.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011E1C4
/* 0B48C4 8011E1C4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B48C8 8011E1C8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0B48CC 8011E1CC 0080902D */  daddu $s2, $a0, $zero
/* 0B48D0 8011E1D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B48D4 8011E1D4 0000882D */  daddu $s1, $zero, $zero
/* 0B48D8 8011E1D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B48DC 8011E1DC 0240802D */  daddu $s0, $s2, $zero
/* 0B48E0 8011E1E0 AFBF001C */  sw    $ra, 0x1c($sp)
.L8011E1E4:
/* 0B48E4 8011E1E4 8E040004 */  lw    $a0, 4($s0)
/* 0B48E8 8011E1E8 10800003 */  beqz  $a0, .L8011E1F8
/* 0B48EC 8011E1EC 26310001 */   addiu $s1, $s1, 1
/* 0B48F0 8011E1F0 0C047871 */  jal   func_8011E1C4
/* 0B48F4 8011E1F4 00000000 */   nop   
.L8011E1F8:
/* 0B48F8 8011E1F8 2A220020 */  slti  $v0, $s1, 0x20
/* 0B48FC 8011E1FC 1440FFF9 */  bnez  $v0, .L8011E1E4
/* 0B4900 8011E200 26100004 */   addiu $s0, $s0, 4
/* 0B4904 8011E204 0C00AB4B */  jal   heap_free
/* 0B4908 8011E208 0240202D */   daddu $a0, $s2, $zero
/* 0B490C 8011E20C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0B4910 8011E210 8FB20018 */  lw    $s2, 0x18($sp)
/* 0B4914 8011E214 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B4918 8011E218 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B491C 8011E21C 03E00008 */  jr    $ra
/* 0B4920 8011E220 27BD0020 */   addiu $sp, $sp, 0x20

