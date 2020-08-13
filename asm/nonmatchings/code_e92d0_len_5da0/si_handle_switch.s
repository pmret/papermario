.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_switch
/* 0E9924 802C4F74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E9928 802C4F78 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E992C 802C4F7C 0080802D */  daddu $s0, $a0, $zero
/* 0E9930 802C4F80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9934 802C4F84 8E02000C */  lw    $v0, 0xc($s0)
/* 0E9938 802C4F88 0C0B1EAF */  jal   get_variable
/* 0E993C 802C4F8C 8C450000 */   lw    $a1, ($v0)
/* 0E9940 802C4F90 92030007 */  lbu   $v1, 7($s0)
/* 0E9944 802C4F94 0040282D */  daddu $a1, $v0, $zero
/* 0E9948 802C4F98 24630001 */  addiu $v1, $v1, 1
/* 0E994C 802C4F9C A2030007 */  sb    $v1, 7($s0)
/* 0E9950 802C4FA0 00031E00 */  sll   $v1, $v1, 0x18
/* 0E9954 802C4FA4 00032603 */  sra   $a0, $v1, 0x18
/* 0E9958 802C4FA8 28820008 */  slti  $v0, $a0, 8
/* 0E995C 802C4FAC 14400003 */  bnez  $v0, .L802C4FBC
/* 0E9960 802C4FB0 24020002 */   addiu $v0, $zero, 2
.L802C4FB4:
/* 0E9964 802C4FB4 080B13ED */  j     .L802C4FB4
/* 0E9968 802C4FB8 00000000 */   nop   

.L802C4FBC:
/* 0E996C 802C4FBC 00441804 */  sllv  $v1, $a0, $v0
/* 0E9970 802C4FC0 02031821 */  addu  $v1, $s0, $v1
/* 0E9974 802C4FC4 02042021 */  addu  $a0, $s0, $a0
/* 0E9978 802C4FC8 AC650118 */  sw    $a1, 0x118($v1)
/* 0E997C 802C4FCC 24030001 */  addiu $v1, $zero, 1
/* 0E9980 802C4FD0 A0830110 */  sb    $v1, 0x110($a0)
/* 0E9984 802C4FD4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E9988 802C4FD8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E998C 802C4FDC 03E00008 */  jr    $ra
/* 0E9990 802C4FE0 27BD0018 */   addiu $sp, $sp, 0x18

