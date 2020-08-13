.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011FFB4
/* 0B66B4 8011FFB4 18C00008 */  blez  $a2, .L8011FFD8
/* 0B66B8 8011FFB8 0000382D */   daddu $a3, $zero, $zero
.L8011FFBC:
/* 0B66BC 8011FFBC 90A30003 */  lbu   $v1, 3($a1)
/* 0B66C0 8011FFC0 00871021 */  addu  $v0, $a0, $a3
/* 0B66C4 8011FFC4 24E70001 */  addiu $a3, $a3, 1
/* 0B66C8 8011FFC8 A0430015 */  sb    $v1, 0x15($v0)
/* 0B66CC 8011FFCC 00E6102A */  slt   $v0, $a3, $a2
/* 0B66D0 8011FFD0 1440FFFA */  bnez  $v0, .L8011FFBC
/* 0B66D4 8011FFD4 24A50004 */   addiu $a1, $a1, 4
.L8011FFD8:
/* 0B66D8 8011FFD8 03E00008 */  jr    $ra
/* 0B66DC 8011FFDC 00000000 */   nop   

