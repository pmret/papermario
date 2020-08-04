.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E96C8
/* 082B78 800E96C8 3C028011 */  lui   $v0, 0x8011
/* 082B7C 800E96CC 8442CD10 */  lh    $v0, -0x32f0($v0)
/* 082B80 800E96D0 3C038011 */  lui   $v1, 0x8011
/* 082B84 800E96D4 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082B88 800E96D8 10400005 */  beqz  $v0, .L800E96F0
/* 082B8C 800E96DC 00000000 */   nop   
/* 082B90 800E96E0 8062006C */  lb    $v0, 0x6c($v1)
/* 082B94 800E96E4 14400002 */  bnez  $v0, .L800E96F0
/* 082B98 800E96E8 24020001 */   addiu $v0, $zero, 1
/* 082B9C 800E96EC A062006C */  sb    $v0, 0x6c($v1)
.L800E96F0:
/* 082BA0 800E96F0 03E00008 */  jr    $ra
/* 082BA4 800E96F4 00000000 */   nop   

