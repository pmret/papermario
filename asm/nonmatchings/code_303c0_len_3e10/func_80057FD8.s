.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80057FD8
/* 0333D8 80057FD8 18C00008 */  blez  $a2, .L80057FFC
/* 0333DC 80057FDC 0000182D */   daddu $v1, $zero, $zero
.L80057FE0:
/* 0333E0 80057FE0 90820000 */  lbu   $v0, ($a0)
/* 0333E4 80057FE4 24840001 */  addiu $a0, $a0, 1
/* 0333E8 80057FE8 24630001 */  addiu $v1, $v1, 1
/* 0333EC 80057FEC A0A20000 */  sb    $v0, ($a1)
/* 0333F0 80057FF0 0066102A */  slt   $v0, $v1, $a2
/* 0333F4 80057FF4 1440FFFA */  bnez  $v0, .L80057FE0
/* 0333F8 80057FF8 24A50001 */   addiu $a1, $a1, 1
.L80057FFC:
/* 0333FC 80057FFC 03E00008 */  jr    $ra
/* 033400 80058000 00000000 */   nop   

