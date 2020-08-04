.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DFCF4
/* 0791A4 800DFCF4 3C048011 */  lui   $a0, 0x8011
/* 0791A8 800DFCF8 2484EBB0 */  addiu $a0, $a0, -0x1450
/* 0791AC 800DFCFC 80830000 */  lb    $v1, ($a0)
/* 0791B0 800DFD00 24020001 */  addiu $v0, $zero, 1
/* 0791B4 800DFD04 1462000E */  bne   $v1, $v0, .L800DFD40
/* 0791B8 800DFD08 24020006 */   addiu $v0, $zero, 6
/* 0791BC 800DFD0C 80830003 */  lb    $v1, 3($a0)
/* 0791C0 800DFD10 10620009 */  beq   $v1, $v0, .L800DFD38
/* 0791C4 800DFD14 24020009 */   addiu $v0, $zero, 9
/* 0791C8 800DFD18 10620007 */  beq   $v1, $v0, .L800DFD38
/* 0791CC 800DFD1C 24020007 */   addiu $v0, $zero, 7
/* 0791D0 800DFD20 10620005 */  beq   $v1, $v0, .L800DFD38
/* 0791D4 800DFD24 24020004 */   addiu $v0, $zero, 4
/* 0791D8 800DFD28 10620003 */  beq   $v1, $v0, .L800DFD38
/* 0791DC 800DFD2C 24020008 */   addiu $v0, $zero, 8
/* 0791E0 800DFD30 14620003 */  bne   $v1, $v0, .L800DFD40
/* 0791E4 800DFD34 00000000 */   nop   
.L800DFD38:
/* 0791E8 800DFD38 03E00008 */  jr    $ra
/* 0791EC 800DFD3C 0000102D */   daddu $v0, $zero, $zero

.L800DFD40:
/* 0791F0 800DFD40 03E00008 */  jr    $ra
/* 0791F4 800DFD44 24020001 */   addiu $v0, $zero, 1

