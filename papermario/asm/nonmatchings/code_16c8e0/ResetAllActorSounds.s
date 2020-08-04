.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ResetAllActorSounds
/* 19DFCC 8026F6EC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19DFD0 8026F6F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19DFD4 8026F6F4 0080802D */  daddu $s0, $a0, $zero
/* 19DFD8 8026F6F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19DFDC 8026F6FC 8E02000C */  lw    $v0, 0xc($s0)
/* 19DFE0 8026F700 0C0B1EAF */  jal   get_variable
/* 19DFE4 8026F704 8C450000 */   lw    $a1, ($v0)
/* 19DFE8 8026F708 0040202D */  daddu $a0, $v0, $zero
/* 19DFEC 8026F70C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19DFF0 8026F710 14820002 */  bne   $a0, $v0, .L8026F71C
/* 19DFF4 8026F714 00000000 */   nop   
/* 19DFF8 8026F718 8E040148 */  lw    $a0, 0x148($s0)
.L8026F71C:
/* 19DFFC 8026F71C 0C09A75B */  jal   get_actor
/* 19E000 8026F720 00000000 */   nop   
/* 19E004 8026F724 0C099EA7 */  jal   reset_all_actor_sounds
/* 19E008 8026F728 0040202D */   daddu $a0, $v0, $zero
/* 19E00C 8026F72C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19E010 8026F730 8FB00010 */  lw    $s0, 0x10($sp)
/* 19E014 8026F734 24020002 */  addiu $v0, $zero, 2
/* 19E018 8026F738 03E00008 */  jr    $ra
/* 19E01C 8026F73C 27BD0018 */   addiu $sp, $sp, 0x18

