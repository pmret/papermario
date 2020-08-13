.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EB42C
/* 0848DC 800EB42C 3C028011 */  lui   $v0, 0x8011
/* 0848E0 800EB430 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 0848E4 800EB434 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0848E8 800EB438 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0848EC 800EB43C 8C42002C */  lw    $v0, 0x2c($v0)
/* 0848F0 800EB440 50400009 */  beql  $v0, $zero, .L800EB468
/* 0848F4 800EB444 0000102D */   daddu $v0, $zero, $zero
/* 0848F8 800EB448 3C048011 */  lui   $a0, 0x8011
/* 0848FC 800EB44C 8C84C930 */  lw    $a0, -0x36d0($a0)
/* 084900 800EB450 0040F809 */  jalr  $v0
/* 084904 800EB454 00000000 */  nop   
/* 084908 800EB458 0040182D */  daddu $v1, $v0, $zero
/* 08490C 800EB45C 10600002 */  beqz  $v1, .L800EB468
/* 084910 800EB460 24020001 */   addiu $v0, $zero, 1
/* 084914 800EB464 0000102D */  daddu $v0, $zero, $zero
.L800EB468:
/* 084918 800EB468 8FBF0010 */  lw    $ra, 0x10($sp)
/* 08491C 800EB46C 03E00008 */  jr    $ra
/* 084920 800EB470 27BD0018 */   addiu $sp, $sp, 0x18

