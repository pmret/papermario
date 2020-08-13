.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetOriginalActorType
/* 1AC348 8027DA68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AC34C 8027DA6C AFB10014 */  sw    $s1, 0x14($sp)
/* 1AC350 8027DA70 0080882D */  daddu $s1, $a0, $zero
/* 1AC354 8027DA74 AFBF0018 */  sw    $ra, 0x18($sp)
/* 1AC358 8027DA78 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AC35C 8027DA7C 8E30000C */  lw    $s0, 0xc($s1)
/* 1AC360 8027DA80 8E050000 */  lw    $a1, ($s0)
/* 1AC364 8027DA84 0C0B1EAF */  jal   get_variable
/* 1AC368 8027DA88 26100004 */   addiu $s0, $s0, 4
/* 1AC36C 8027DA8C 0040202D */  daddu $a0, $v0, $zero
/* 1AC370 8027DA90 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AC374 8027DA94 14820002 */  bne   $a0, $v0, .L8027DAA0
/* 1AC378 8027DA98 8E100000 */   lw    $s0, ($s0)
/* 1AC37C 8027DA9C 8E240148 */  lw    $a0, 0x148($s1)
.L8027DAA0:
/* 1AC380 8027DAA0 0C09A75B */  jal   get_actor
/* 1AC384 8027DAA4 00000000 */   nop   
/* 1AC388 8027DAA8 8C420008 */  lw    $v0, 8($v0)
/* 1AC38C 8027DAAC 0220202D */  daddu $a0, $s1, $zero
/* 1AC390 8027DAB0 90460005 */  lbu   $a2, 5($v0)
/* 1AC394 8027DAB4 0C0B2026 */  jal   set_variable
/* 1AC398 8027DAB8 0200282D */   daddu $a1, $s0, $zero
/* 1AC39C 8027DABC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1AC3A0 8027DAC0 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AC3A4 8027DAC4 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AC3A8 8027DAC8 24020002 */  addiu $v0, $zero, 2
/* 1AC3AC 8027DACC 03E00008 */  jr    $ra
/* 1AC3B0 8027DAD0 27BD0020 */   addiu $sp, $sp, 0x20

