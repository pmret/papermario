.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetActorDefenseBoost
/* 19E54C 8026FC6C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19E550 8026FC70 AFB10014 */  sw    $s1, 0x14($sp)
/* 19E554 8026FC74 0080882D */  daddu $s1, $a0, $zero
/* 19E558 8026FC78 AFBF0018 */  sw    $ra, 0x18($sp)
/* 19E55C 8026FC7C AFB00010 */  sw    $s0, 0x10($sp)
/* 19E560 8026FC80 8E30000C */  lw    $s0, 0xc($s1)
/* 19E564 8026FC84 8E050000 */  lw    $a1, ($s0)
/* 19E568 8026FC88 0C0B1EAF */  jal   get_variable
/* 19E56C 8026FC8C 26100004 */   addiu $s0, $s0, 4
/* 19E570 8026FC90 0040202D */  daddu $a0, $v0, $zero
/* 19E574 8026FC94 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19E578 8026FC98 14820002 */  bne   $a0, $v0, .L8026FCA4
/* 19E57C 8026FC9C 00000000 */   nop   
/* 19E580 8026FCA0 8E240148 */  lw    $a0, 0x148($s1)
.L8026FCA4:
/* 19E584 8026FCA4 0C09A75B */  jal   get_actor
/* 19E588 8026FCA8 8E100000 */   lw    $s0, ($s0)
/* 19E58C 8026FCAC 0220202D */  daddu $a0, $s1, $zero
/* 19E590 8026FCB0 80460222 */  lb    $a2, 0x222($v0)
/* 19E594 8026FCB4 0C0B2026 */  jal   set_variable
/* 19E598 8026FCB8 0200282D */   daddu $a1, $s0, $zero
/* 19E59C 8026FCBC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19E5A0 8026FCC0 8FB10014 */  lw    $s1, 0x14($sp)
/* 19E5A4 8026FCC4 8FB00010 */  lw    $s0, 0x10($sp)
/* 19E5A8 8026FCC8 24020002 */  addiu $v0, $zero, 2
/* 19E5AC 8026FCCC 03E00008 */  jr    $ra
/* 19E5B0 8026FCD0 27BD0020 */   addiu $sp, $sp, 0x20

