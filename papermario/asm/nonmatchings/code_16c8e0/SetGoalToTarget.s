.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetGoalToTarget
/* 198C88 8026A3A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 198C8C 8026A3AC AFB00010 */  sw    $s0, 0x10($sp)
/* 198C90 8026A3B0 0080802D */  daddu $s0, $a0, $zero
/* 198C94 8026A3B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 198C98 8026A3B8 8E02000C */  lw    $v0, 0xc($s0)
/* 198C9C 8026A3BC 0C0B1EAF */  jal   get_variable
/* 198CA0 8026A3C0 8C450000 */   lw    $a1, ($v0)
/* 198CA4 8026A3C4 0040202D */  daddu $a0, $v0, $zero
/* 198CA8 8026A3C8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198CAC 8026A3CC 14820002 */  bne   $a0, $v0, .L8026A3D8
/* 198CB0 8026A3D0 00000000 */   nop   
/* 198CB4 8026A3D4 8E040148 */  lw    $a0, 0x148($s0)
.L8026A3D8:
/* 198CB8 8026A3D8 0C09A75B */  jal   get_actor
/* 198CBC 8026A3DC 00000000 */   nop   
/* 198CC0 8026A3E0 84450428 */  lh    $a1, 0x428($v0)
/* 198CC4 8026A3E4 80460426 */  lb    $a2, 0x426($v0)
/* 198CC8 8026A3E8 0C09A5D5 */  jal   set_goal_pos_to_part
/* 198CCC 8026A3EC 2444000C */   addiu $a0, $v0, 0xc
/* 198CD0 8026A3F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 198CD4 8026A3F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 198CD8 8026A3F8 24020002 */  addiu $v0, $zero, 2
/* 198CDC 8026A3FC 03E00008 */  jr    $ra
/* 198CE0 8026A400 27BD0018 */   addiu $sp, $sp, 0x18

