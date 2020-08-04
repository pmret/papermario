.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247000
/* 13A340 80247000 84A20000 */  lh    $v0, ($a1)
/* 13A344 80247004 14400003 */  bnez  $v0, .L80247014
/* 13A348 80247008 00021140 */   sll   $v0, $v0, 5
/* 13A34C 8024700C 08091C08 */  j     func_80247020
/* 13A350 80247010 24047FFF */   addiu $a0, $zero, 0x7fff

.L80247014:
/* 13A354 80247014 3C048008 */  lui   $a0, 0x8008
/* 13A358 80247018 00822021 */  addu  $a0, $a0, $v0
/* 13A35C 8024701C 948478E6 */  lhu   $a0, 0x78e6($a0)
