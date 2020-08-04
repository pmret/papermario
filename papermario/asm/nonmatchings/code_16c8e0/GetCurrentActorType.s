.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetCurrentActorType
/* 1AC3B4 8027DAD4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AC3B8 8027DAD8 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AC3BC 8027DADC 0080882D */  daddu $s1, $a0, $zero
/* 1AC3C0 8027DAE0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 1AC3C4 8027DAE4 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AC3C8 8027DAE8 8E30000C */  lw    $s0, 0xc($s1)
/* 1AC3CC 8027DAEC 8E050000 */  lw    $a1, ($s0)
/* 1AC3D0 8027DAF0 0C0B1EAF */  jal   get_variable
/* 1AC3D4 8027DAF4 26100004 */   addiu $s0, $s0, 4
/* 1AC3D8 8027DAF8 0040202D */  daddu $a0, $v0, $zero
/* 1AC3DC 8027DAFC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AC3E0 8027DB00 14820002 */  bne   $a0, $v0, .L8027DB0C
/* 1AC3E4 8027DB04 8E100000 */   lw    $s0, ($s0)
/* 1AC3E8 8027DB08 8E240148 */  lw    $a0, 0x148($s1)
.L8027DB0C:
/* 1AC3EC 8027DB0C 0C09A75B */  jal   get_actor
/* 1AC3F0 8027DB10 00000000 */   nop   
/* 1AC3F4 8027DB14 0220202D */  daddu $a0, $s1, $zero
/* 1AC3F8 8027DB18 90460136 */  lbu   $a2, 0x136($v0)
/* 1AC3FC 8027DB1C 0C0B2026 */  jal   set_variable
/* 1AC400 8027DB20 0200282D */   daddu $a1, $s0, $zero
/* 1AC404 8027DB24 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1AC408 8027DB28 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AC40C 8027DB2C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AC410 8027DB30 24020002 */  addiu $v0, $zero, 2
/* 1AC414 8027DB34 03E00008 */  jr    $ra
/* 1AC418 8027DB38 27BD0020 */   addiu $sp, $sp, 0x20

