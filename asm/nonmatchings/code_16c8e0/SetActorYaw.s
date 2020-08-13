.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetActorYaw
/* 199C38 8026B358 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199C3C 8026B35C AFB20018 */  sw    $s2, 0x18($sp)
/* 199C40 8026B360 0080902D */  daddu $s2, $a0, $zero
/* 199C44 8026B364 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199C48 8026B368 AFB10014 */  sw    $s1, 0x14($sp)
/* 199C4C 8026B36C AFB00010 */  sw    $s0, 0x10($sp)
/* 199C50 8026B370 8E51000C */  lw    $s1, 0xc($s2)
/* 199C54 8026B374 8E250000 */  lw    $a1, ($s1)
/* 199C58 8026B378 0C0B1EAF */  jal   get_variable
/* 199C5C 8026B37C 26310004 */   addiu $s1, $s1, 4
/* 199C60 8026B380 0040802D */  daddu $s0, $v0, $zero
/* 199C64 8026B384 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199C68 8026B388 16020002 */  bne   $s0, $v0, .L8026B394
/* 199C6C 8026B38C 00000000 */   nop   
/* 199C70 8026B390 8E500148 */  lw    $s0, 0x148($s2)
.L8026B394:
/* 199C74 8026B394 8E250000 */  lw    $a1, ($s1)
/* 199C78 8026B398 0C0B1EAF */  jal   get_variable
/* 199C7C 8026B39C 0240202D */   daddu $a0, $s2, $zero
/* 199C80 8026B3A0 0200202D */  daddu $a0, $s0, $zero
/* 199C84 8026B3A4 0C098FDA */  jal   set_actor_yaw
/* 199C88 8026B3A8 0040282D */   daddu $a1, $v0, $zero
/* 199C8C 8026B3AC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199C90 8026B3B0 8FB20018 */  lw    $s2, 0x18($sp)
/* 199C94 8026B3B4 8FB10014 */  lw    $s1, 0x14($sp)
/* 199C98 8026B3B8 8FB00010 */  lw    $s0, 0x10($sp)
/* 199C9C 8026B3BC 24020002 */  addiu $v0, $zero, 2
/* 199CA0 8026B3C0 03E00008 */  jr    $ra
/* 199CA4 8026B3C4 27BD0020 */   addiu $sp, $sp, 0x20

