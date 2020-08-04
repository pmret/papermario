.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E9860
/* 082D10 800E9860 3C038011 */  lui   $v1, 0x8011
/* 082D14 800E9864 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082D18 800E9868 80640045 */  lb    $a0, 0x45($v1)
/* 082D1C 800E986C 24020001 */  addiu $v0, $zero, 1
/* 082D20 800E9870 00442023 */  subu  $a0, $v0, $a0
/* 082D24 800E9874 80620046 */  lb    $v0, 0x46($v1)
/* 082D28 800E9878 54400001 */  bnezl $v0, .L800E9880
/* 082D2C 800E987C 0000202D */   daddu $a0, $zero, $zero
.L800E9880:
/* 082D30 800E9880 80620044 */  lb    $v0, 0x44($v1)
/* 082D34 800E9884 54400001 */  bnezl $v0, .L800E988C
/* 082D38 800E9888 0000202D */   daddu $a0, $zero, $zero
.L800E988C:
/* 082D3C 800E988C 03E00008 */  jr    $ra
/* 082D40 800E9890 0080102D */   daddu $v0, $a0, $zero

