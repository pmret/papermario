.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_global_flag
/* 0DBAE0 801453E0 3C02F8D8 */  lui   $v0, 0xf8d8
/* 0DBAE4 801453E4 3442F200 */  ori   $v0, $v0, 0xf200
/* 0DBAE8 801453E8 0044102A */  slt   $v0, $v0, $a0
/* 0DBAEC 801453EC 14400003 */  bnez  $v0, .L801453FC
/* 0DBAF0 801453F0 3C0207BF */   lui   $v0, 0x7bf
/* 0DBAF4 801453F4 3442A480 */  ori   $v0, $v0, 0xa480
/* 0DBAF8 801453F8 00822021 */  addu  $a0, $a0, $v0
.L801453FC:
/* 0DBAFC 801453FC 04810002 */  bgez  $a0, .L80145408
/* 0DBB00 80145400 0080102D */   daddu $v0, $a0, $zero
/* 0DBB04 80145404 2482001F */  addiu $v0, $a0, 0x1f
.L80145408:
/* 0DBB08 80145408 00021143 */  sra   $v0, $v0, 5
/* 0DBB0C 8014540C 00021940 */  sll   $v1, $v0, 5
/* 0DBB10 80145410 00831823 */  subu  $v1, $a0, $v1
/* 0DBB14 80145414 3C04800E */  lui   $a0, 0x800e
/* 0DBB18 80145418 2484ACC0 */  addiu $a0, $a0, -0x5340
/* 0DBB1C 8014541C 00021080 */  sll   $v0, $v0, 2
/* 0DBB20 80145420 00442821 */  addu  $a1, $v0, $a0
/* 0DBB24 80145424 24020001 */  addiu $v0, $zero, 1
/* 0DBB28 80145428 8CA40FB0 */  lw    $a0, 0xfb0($a1)
/* 0DBB2C 8014542C 00621004 */  sllv  $v0, $v0, $v1
/* 0DBB30 80145430 00821824 */  and   $v1, $a0, $v0
/* 0DBB34 80145434 54600001 */  bnel  $v1, $zero, .L8014543C
/* 0DBB38 80145438 24030001 */   addiu $v1, $zero, 1
.L8014543C:
/* 0DBB3C 8014543C 00021027 */  nor   $v0, $zero, $v0
/* 0DBB40 80145440 00821024 */  and   $v0, $a0, $v0
/* 0DBB44 80145444 ACA20FB0 */  sw    $v0, 0xfb0($a1)
/* 0DBB48 80145448 03E00008 */  jr    $ra
/* 0DBB4C 8014544C 0060102D */   daddu $v0, $v1, $zero

