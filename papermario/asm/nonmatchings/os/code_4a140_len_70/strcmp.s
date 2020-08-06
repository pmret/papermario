.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel strcmp
.L8006ED70:
/* 04A170 8006ED70 90860000 */  lbu   $a2, ($a0)
/* 04A174 8006ED74 24840001 */  addiu $a0, $a0, 1
/* 04A178 8006ED78 90A20000 */  lbu   $v0, ($a1)
/* 04A17C 8006ED7C 30C300FF */  andi  $v1, $a2, 0xff
/* 04A180 8006ED80 304200FF */  andi  $v0, $v0, 0xff
/* 04A184 8006ED84 10620003 */  beq   $v1, $v0, .L8006ED94
/* 04A188 8006ED88 24A50001 */   addiu $a1, $a1, 1
/* 04A18C 8006ED8C 0801BB67 */  j     .L8006ED9C
/* 04A190 8006ED90 00621023 */   subu  $v0, $v1, $v0

.L8006ED94:
/* 04A194 8006ED94 14C0FFF6 */  bnez  $a2, .L8006ED70
/* 04A198 8006ED98 00001021 */   addu  $v0, $zero, $zero
.L8006ED9C:
/* 04A19C 8006ED9C 03E00008 */  jr    $ra
/* 04A1A0 8006EDA0 00000000 */   nop   

/* 04A1A4 8006EDA4 00000000 */  nop   
/* 04A1A8 8006EDA8 00000000 */  nop   
/* 04A1AC 8006EDAC 00000000 */  nop   


