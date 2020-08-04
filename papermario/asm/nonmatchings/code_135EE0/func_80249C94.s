.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249C94
/* 13CFD4 80249C94 3C038027 */  lui   $v1, 0x8027
/* 13CFD8 80249C98 806300D4 */  lb    $v1, 0xd4($v1)
/* 13CFDC 80249C9C 2C420001 */  sltiu $v0, $v0, 1
/* 13CFE0 80249CA0 AFA20074 */  sw    $v0, 0x74($sp)
/* 13CFE4 80249CA4 24020003 */  addiu $v0, $zero, 3
/* 13CFE8 80249CA8 14620012 */  bne   $v1, $v0, .L80249CF4
/* 13CFEC 80249CAC 0000A02D */   daddu $s4, $zero, $zero
