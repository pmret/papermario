.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011E014
/* 0B4714 8011E014 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0B4718 8011E018 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B471C 8011E01C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0B4720 8011E020 0C019D28 */  jal   guMtxIdentF
/* 0B4724 8011E024 0080802D */   daddu $s0, $a0, $zero
/* 0B4728 8011E028 3C013F80 */  lui   $at, 0x3f80
/* 0B472C 8011E02C 44810000 */  mtc1  $at, $f0
/* 0B4730 8011E030 3C01BF80 */  lui   $at, 0xbf80
/* 0B4734 8011E034 44811000 */  mtc1  $at, $f2
/* 0B4738 8011E038 E6000000 */  swc1  $f0, ($s0)
/* 0B473C 8011E03C E6020014 */  swc1  $f2, 0x14($s0)
/* 0B4740 8011E040 E6000028 */  swc1  $f0, 0x28($s0)
/* 0B4744 8011E044 E600003C */  swc1  $f0, 0x3c($s0)
/* 0B4748 8011E048 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0B474C 8011E04C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B4750 8011E050 03E00008 */  jr    $ra
/* 0B4754 8011E054 27BD0018 */   addiu $sp, $sp, 0x18

