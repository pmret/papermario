.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ResumeTakeTurn
/* 1A72FC 80278A1C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A7300 80278A20 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A7304 80278A24 0080902D */  daddu $s2, $a0, $zero
/* 1A7308 80278A28 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A730C 80278A2C AFB10014 */  sw    $s1, 0x14($sp)
/* 1A7310 80278A30 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A7314 80278A34 8E51000C */  lw    $s1, 0xc($s2)
/* 1A7318 80278A38 8E250000 */  lw    $a1, ($s1)
/* 1A731C 80278A3C 0C0B1EAF */  jal   get_variable
/* 1A7320 80278A40 26310004 */   addiu $s1, $s1, 4
/* 1A7324 80278A44 0040802D */  daddu $s0, $v0, $zero
/* 1A7328 80278A48 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A732C 80278A4C 16020002 */  bne   $s0, $v0, .L80278A58
/* 1A7330 80278A50 00000000 */   nop   
/* 1A7334 80278A54 8E500148 */  lw    $s0, 0x148($s2)
.L80278A58:
/* 1A7338 80278A58 8E250000 */  lw    $a1, ($s1)
/* 1A733C 80278A5C 0C0B1EAF */  jal   get_variable
/* 1A7340 80278A60 0240202D */   daddu $a0, $s2, $zero
/* 1A7344 80278A64 0C09A75B */  jal   get_actor
/* 1A7348 80278A68 0200202D */   daddu $a0, $s0, $zero
/* 1A734C 80278A6C 8C4401E4 */  lw    $a0, 0x1e4($v0)
/* 1A7350 80278A70 0C0B1123 */  jal   resume_all_script
/* 1A7354 80278A74 00000000 */   nop   
/* 1A7358 80278A78 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A735C 80278A7C 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A7360 80278A80 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A7364 80278A84 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A7368 80278A88 24020002 */  addiu $v0, $zero, 2
/* 1A736C 80278A8C 03E00008 */  jr    $ra
/* 1A7370 80278A90 27BD0020 */   addiu $sp, $sp, 0x20

