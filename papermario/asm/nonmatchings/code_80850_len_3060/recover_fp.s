.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel recover_fp
/* 083714 800EA264 3C058011 */  lui   $a1, 0x8011
/* 083718 800EA268 24A5F290 */  addiu $a1, $a1, -0xd70
/* 08371C 800EA26C 80A30005 */  lb    $v1, 5($a1)
/* 083720 800EA270 2402FFFE */  addiu $v0, $zero, -2
/* 083724 800EA274 14820008 */  bne   $a0, $v0, .L800EA298
/* 083728 800EA278 00000000 */   nop   
/* 08372C 800EA27C 90A30006 */  lbu   $v1, 6($a1)
/* 083730 800EA280 24630001 */  addiu $v1, $v1, 1
/* 083734 800EA284 00031600 */  sll   $v0, $v1, 0x18
/* 083738 800EA288 00021603 */  sra   $v0, $v0, 0x18
/* 08373C 800EA28C A0A30006 */  sb    $v1, 6($a1)
/* 083740 800EA290 03E00008 */  jr    $ra
/* 083744 800EA294 A0A30005 */   sb    $v1, 5($a1)

.L800EA298:
/* 083748 800EA298 5C800001 */  bgtzl $a0, .L800EA2A0
/* 08374C 800EA29C 00641821 */   addu  $v1, $v1, $a0
.L800EA2A0:
/* 083750 800EA2A0 2402FFFF */  addiu $v0, $zero, -1
/* 083754 800EA2A4 10820005 */  beq   $a0, $v0, .L800EA2BC
/* 083758 800EA2A8 00000000 */   nop   
/* 08375C 800EA2AC 80A20006 */  lb    $v0, 6($a1)
/* 083760 800EA2B0 0043102A */  slt   $v0, $v0, $v1
/* 083764 800EA2B4 50400003 */  beql  $v0, $zero, .L800EA2C4
/* 083768 800EA2B8 A0A30005 */   sb    $v1, 5($a1)
.L800EA2BC:
/* 08376C 800EA2BC 80A30006 */  lb    $v1, 6($a1)
/* 083770 800EA2C0 A0A30005 */  sb    $v1, 5($a1)
.L800EA2C4:
/* 083774 800EA2C4 03E00008 */  jr    $ra
/* 083778 800EA2C8 0060102D */   daddu $v0, $v1, $zero

