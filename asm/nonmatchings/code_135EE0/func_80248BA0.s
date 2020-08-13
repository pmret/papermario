.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248BA0
.L80248BA0:
/* 13BEE0 80248BA0 3C038027 */  lui   $v1, 0x8027
/* 13BEE4 80248BA4 8C63038C */  lw    $v1, 0x38c($v1)
/* 13BEE8 80248BA8 3C028027 */  lui   $v0, 0x8027
/* 13BEEC 80248BAC 8C420390 */  lw    $v0, 0x390($v0)
/* 13BEF0 80248BB0 1062000A */  beq   $v1, $v0, .L80248BDC
/* 13BEF4 80248BB4 24040020 */   addiu $a0, $zero, 0x20
/* 13BEF8 80248BB8 2605005D */  addiu $a1, $s0, 0x5d
/* 13BEFC 80248BBC 24C60017 */  addiu $a2, $a2, 0x17
/* 13BF00 80248BC0 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13BF04 80248BC4 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13BF08 80248BC8 01652821 */  addu  $a1, $t3, $a1
