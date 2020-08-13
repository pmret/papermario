.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel NpcJump0
/* 0F3074 802CE6C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3078 802CE6C8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F307C 802CE6CC 0C0B390D */  jal   _npc_jump_to
/* 0F3080 802CE6D0 0000302D */   daddu $a2, $zero, $zero
/* 0F3084 802CE6D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F3088 802CE6D8 03E00008 */  jr    $ra
/* 0F308C 802CE6DC 27BD0018 */   addiu $sp, $sp, 0x18

