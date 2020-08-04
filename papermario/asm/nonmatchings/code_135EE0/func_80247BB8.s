.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247BB8
/* 13AEF8 80247BB8 0C091CA6 */  jal   func_80247298
/* 13AEFC 80247BBC 01508021 */   addu  $s0, $t2, $s0
/* 13AF00 80247BC0 0200282D */  daddu $a1, $s0, $zero
/* 13AF04 80247BC4 24420011 */  addiu $v0, $v0, 0x11
/* 13AF08 80247BC8 00131C00 */  sll   $v1, $s3, 0x10
/* 13AF0C 80247BCC 00031AC3 */  sra   $v1, $v1, 0xb
/* 13AF10 80247BD0 3C0B8008 */  lui   $t3, 0x8008
/* 13AF14 80247BD4 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13AF18 80247BD8 006B1821 */  addu  $v1, $v1, $t3
/* 13AF1C 80247BDC 3C0B8009 */  lui   $t3, 0x8009
/* 13AF20 80247BE0 256BF060 */  addiu $t3, $t3, -0xfa0
/* 13AF24 80247BE4 24070001 */  addiu $a3, $zero, 1
/* 13AF28 80247BE8 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13AF2C 80247BEC 9063001A */  lbu   $v1, 0x1a($v1)
/* 13AF30 80247BF0 01423021 */  addu  $a2, $t2, $v0
/* 13AF34 80247BF4 00031080 */  sll   $v0, $v1, 2
/* 13AF38 80247BF8 00431021 */  addu  $v0, $v0, $v1
/* 13AF3C 80247BFC 00021080 */  sll   $v0, $v0, 2
/* 13AF40 80247C00 004B1021 */  addu  $v0, $v0, $t3
/* 13AF44 80247C04 80440012 */  lb    $a0, 0x12($v0)
/* 13AF48 80247C08 8FAA0068 */  lw    $t2, 0x68($sp)
/* 13AF4C 80247C0C 240200FF */  addiu $v0, $zero, 0xff
/* 13AF50 80247C10 AFA20014 */  sw    $v0, 0x14($sp)
/* 13AF54 80247C14 24020003 */  addiu $v0, $zero, 3
/* 13AF58 80247C18 AFA20018 */  sw    $v0, 0x18($sp)
/* 13AF5C 80247C1C 0C049DA7 */  jal   draw_number
/* 13AF60 80247C20 AFAA0010 */   sw    $t2, 0x10($sp)
