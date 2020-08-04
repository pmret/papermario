.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel memcpy
/* 03FE74 80064A74 10C00007 */  beqz  $a2, .L80064A94
/* 03FE78 80064A78 00801821 */   addu  $v1, $a0, $zero
.L80064A7C:
/* 03FE7C 80064A7C 90A20000 */  lbu   $v0, ($a1)
/* 03FE80 80064A80 24A50001 */  addiu $a1, $a1, 1
/* 03FE84 80064A84 24C6FFFF */  addiu $a2, $a2, -1
/* 03FE88 80064A88 A0620000 */  sb    $v0, ($v1)
/* 03FE8C 80064A8C 14C0FFFB */  bnez  $a2, .L80064A7C
/* 03FE90 80064A90 24630001 */   addiu $v1, $v1, 1
.L80064A94:
/* 03FE94 80064A94 03E00008 */  jr    $ra
/* 03FE98 80064A98 00801021 */   addu  $v0, $a0, $zero

/* 03FE9C 80064A9C 00000000 */  nop   
