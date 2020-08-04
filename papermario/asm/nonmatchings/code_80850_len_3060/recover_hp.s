.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel recover_hp
/* 08377C 800EA2CC 3C058011 */  lui   $a1, 0x8011
/* 083780 800EA2D0 24A5F290 */  addiu $a1, $a1, -0xd70
/* 083784 800EA2D4 80A30002 */  lb    $v1, 2($a1)
/* 083788 800EA2D8 2402FFFE */  addiu $v0, $zero, -2
/* 08378C 800EA2DC 14820008 */  bne   $a0, $v0, .L800EA300
/* 083790 800EA2E0 00000000 */   nop   
/* 083794 800EA2E4 90A30003 */  lbu   $v1, 3($a1)
/* 083798 800EA2E8 24630001 */  addiu $v1, $v1, 1
/* 08379C 800EA2EC 00031600 */  sll   $v0, $v1, 0x18
/* 0837A0 800EA2F0 00021603 */  sra   $v0, $v0, 0x18
/* 0837A4 800EA2F4 A0A30003 */  sb    $v1, 3($a1)
/* 0837A8 800EA2F8 03E00008 */  jr    $ra
/* 0837AC 800EA2FC A0A30002 */   sb    $v1, 2($a1)

.L800EA300:
/* 0837B0 800EA300 5C800001 */  bgtzl $a0, .L800EA308
/* 0837B4 800EA304 00641821 */   addu  $v1, $v1, $a0
.L800EA308:
/* 0837B8 800EA308 2402FFFF */  addiu $v0, $zero, -1
/* 0837BC 800EA30C 10820005 */  beq   $a0, $v0, .L800EA324
/* 0837C0 800EA310 00000000 */   nop   
/* 0837C4 800EA314 80A20003 */  lb    $v0, 3($a1)
/* 0837C8 800EA318 0043102A */  slt   $v0, $v0, $v1
/* 0837CC 800EA31C 50400003 */  beql  $v0, $zero, .L800EA32C
/* 0837D0 800EA320 A0A30002 */   sb    $v1, 2($a1)
.L800EA324:
/* 0837D4 800EA324 80A30003 */  lb    $v1, 3($a1)
/* 0837D8 800EA328 A0A30002 */  sb    $v1, 2($a1)
.L800EA32C:
/* 0837DC 800EA32C 03E00008 */  jr    $ra
/* 0837E0 800EA330 0060102D */   daddu $v0, $v1, $zero

