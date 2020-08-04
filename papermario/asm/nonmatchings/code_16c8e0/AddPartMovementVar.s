.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddPartMovementVar
/* 19ABC8 8026C2E8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19ABCC 8026C2EC AFB3001C */  sw    $s3, 0x1c($sp)
/* 19ABD0 8026C2F0 0080982D */  daddu $s3, $a0, $zero
/* 19ABD4 8026C2F4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19ABD8 8026C2F8 AFB20018 */  sw    $s2, 0x18($sp)
/* 19ABDC 8026C2FC AFB10014 */  sw    $s1, 0x14($sp)
/* 19ABE0 8026C300 AFB00010 */  sw    $s0, 0x10($sp)
/* 19ABE4 8026C304 8E70000C */  lw    $s0, 0xc($s3)
/* 19ABE8 8026C308 8E050000 */  lw    $a1, ($s0)
/* 19ABEC 8026C30C 0C0B1EAF */  jal   get_variable
/* 19ABF0 8026C310 26100004 */   addiu $s0, $s0, 4
/* 19ABF4 8026C314 0040902D */  daddu $s2, $v0, $zero
/* 19ABF8 8026C318 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19ABFC 8026C31C 16420002 */  bne   $s2, $v0, .L8026C328
/* 19AC00 8026C320 00000000 */   nop   
/* 19AC04 8026C324 8E720148 */  lw    $s2, 0x148($s3)
.L8026C328:
/* 19AC08 8026C328 8E050000 */  lw    $a1, ($s0)
/* 19AC0C 8026C32C 26100004 */  addiu $s0, $s0, 4
/* 19AC10 8026C330 0C0B1EAF */  jal   get_variable
/* 19AC14 8026C334 0260202D */   daddu $a0, $s3, $zero
/* 19AC18 8026C338 8E050000 */  lw    $a1, ($s0)
/* 19AC1C 8026C33C 26100004 */  addiu $s0, $s0, 4
/* 19AC20 8026C340 0260202D */  daddu $a0, $s3, $zero
/* 19AC24 8026C344 0C0B1EAF */  jal   get_variable
/* 19AC28 8026C348 0040882D */   daddu $s1, $v0, $zero
/* 19AC2C 8026C34C 0260202D */  daddu $a0, $s3, $zero
/* 19AC30 8026C350 8E050000 */  lw    $a1, ($s0)
/* 19AC34 8026C354 0C0B1EAF */  jal   get_variable
/* 19AC38 8026C358 0040802D */   daddu $s0, $v0, $zero
/* 19AC3C 8026C35C 0240202D */  daddu $a0, $s2, $zero
/* 19AC40 8026C360 0C09A75B */  jal   get_actor
/* 19AC44 8026C364 0040902D */   daddu $s2, $v0, $zero
/* 19AC48 8026C368 0040202D */  daddu $a0, $v0, $zero
/* 19AC4C 8026C36C 0C099117 */  jal   get_actor_part
/* 19AC50 8026C370 0220282D */   daddu $a1, $s1, $zero
/* 19AC54 8026C374 8C440010 */  lw    $a0, 0x10($v0)
/* 19AC58 8026C378 00108080 */  sll   $s0, $s0, 2
/* 19AC5C 8026C37C 00902021 */  addu  $a0, $a0, $s0
/* 19AC60 8026C380 8C83004C */  lw    $v1, 0x4c($a0)
/* 19AC64 8026C384 00721821 */  addu  $v1, $v1, $s2
/* 19AC68 8026C388 AC83004C */  sw    $v1, 0x4c($a0)
/* 19AC6C 8026C38C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19AC70 8026C390 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19AC74 8026C394 8FB20018 */  lw    $s2, 0x18($sp)
/* 19AC78 8026C398 8FB10014 */  lw    $s1, 0x14($sp)
/* 19AC7C 8026C39C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19AC80 8026C3A0 24020002 */  addiu $v0, $zero, 2
/* 19AC84 8026C3A4 03E00008 */  jr    $ra
/* 19AC88 8026C3A8 27BD0028 */   addiu $sp, $sp, 0x28

