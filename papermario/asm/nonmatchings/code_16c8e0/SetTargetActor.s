.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetTargetActor
/* 1AAE28 8027C548 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AAE2C 8027C54C AFB20018 */  sw    $s2, 0x18($sp)
/* 1AAE30 8027C550 0080902D */  daddu $s2, $a0, $zero
/* 1AAE34 8027C554 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1AAE38 8027C558 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AAE3C 8027C55C AFB00010 */  sw    $s0, 0x10($sp)
/* 1AAE40 8027C560 8E51000C */  lw    $s1, 0xc($s2)
/* 1AAE44 8027C564 8E250000 */  lw    $a1, ($s1)
/* 1AAE48 8027C568 0C0B1EAF */  jal   get_variable
/* 1AAE4C 8027C56C 26310004 */   addiu $s1, $s1, 4
/* 1AAE50 8027C570 0040802D */  daddu $s0, $v0, $zero
/* 1AAE54 8027C574 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AAE58 8027C578 16020002 */  bne   $s0, $v0, .L8027C584
/* 1AAE5C 8027C57C 00000000 */   nop   
/* 1AAE60 8027C580 8E500148 */  lw    $s0, 0x148($s2)
.L8027C584:
/* 1AAE64 8027C584 8E250000 */  lw    $a1, ($s1)
/* 1AAE68 8027C588 0C0B1EAF */  jal   get_variable
/* 1AAE6C 8027C58C 0240202D */   daddu $a0, $s2, $zero
/* 1AAE70 8027C590 0200202D */  daddu $a0, $s0, $zero
/* 1AAE74 8027C594 0C09A75B */  jal   get_actor
/* 1AAE78 8027C598 0040802D */   daddu $s0, $v0, $zero
/* 1AAE7C 8027C59C 0040202D */  daddu $a0, $v0, $zero
/* 1AAE80 8027C5A0 24030001 */  addiu $v1, $zero, 1
/* 1AAE84 8027C5A4 A4900428 */  sh    $s0, 0x428($a0)
/* 1AAE88 8027C5A8 A0830426 */  sb    $v1, 0x426($a0)
/* 1AAE8C 8027C5AC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1AAE90 8027C5B0 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AAE94 8027C5B4 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AAE98 8027C5B8 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AAE9C 8027C5BC 24020002 */  addiu $v0, $zero, 2
/* 1AAEA0 8027C5C0 03E00008 */  jr    $ra
/* 1AAEA4 8027C5C4 27BD0020 */   addiu $sp, $sp, 0x20

