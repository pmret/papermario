.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel hide_coin_counter
/* 082B48 800E9698 3C028011 */  lui   $v0, 0x8011
/* 082B4C 800E969C 8442CD10 */  lh    $v0, -0x32f0($v0)
/* 082B50 800E96A0 3C038011 */  lui   $v1, 0x8011
/* 082B54 800E96A4 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082B58 800E96A8 10400005 */  beqz  $v0, .L800E96C0
/* 082B5C 800E96AC 00000000 */   nop   
/* 082B60 800E96B0 8062006C */  lb    $v0, 0x6c($v1)
/* 082B64 800E96B4 14400002 */  bnez  $v0, .L800E96C0
/* 082B68 800E96B8 2402003C */   addiu $v0, $zero, 0x3c
/* 082B6C 800E96BC A062006C */  sb    $v0, 0x6c($v1)
.L800E96C0:
/* 082B70 800E96C0 03E00008 */  jr    $ra
/* 082B74 800E96C4 00000000 */   nop   

