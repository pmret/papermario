.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802497AC
/* 13CAEC 802497AC 00000000 */  nop   
/* 13CAF0 802497B0 84840000 */  lh    $a0, ($a0)
/* 13CAF4 802497B4 84A30000 */  lh    $v1, ($a1)
/* 13CAF8 802497B8 0064182A */  slt   $v1, $v1, $a0
/* 13CAFC 802497BC 14600002 */  bnez  $v1, .L802497C8
/* 13CB00 802497C0 24020001 */   addiu $v0, $zero, 1
/* 13CB04 802497C4 2402FFFF */  addiu $v0, $zero, -1
.L802497C8:
/* 13CB08 802497C8 03E00008 */  jr    $ra
/* 13CB0C 802497CC 00000000 */   nop   

