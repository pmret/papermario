.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetGoalToFirstTarget
/* 198D7C 8026A49C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 198D80 8026A4A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 198D84 8026A4A4 0080802D */  daddu $s0, $a0, $zero
/* 198D88 8026A4A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 198D8C 8026A4AC 8E02000C */  lw    $v0, 0xc($s0)
/* 198D90 8026A4B0 0C0B1EAF */  jal   get_variable
/* 198D94 8026A4B4 8C450000 */   lw    $a1, ($v0)
/* 198D98 8026A4B8 0040202D */  daddu $a0, $v0, $zero
/* 198D9C 8026A4BC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198DA0 8026A4C0 14820002 */  bne   $a0, $v0, .L8026A4CC
/* 198DA4 8026A4C4 00000000 */   nop   
/* 198DA8 8026A4C8 8E040148 */  lw    $a0, 0x148($s0)
.L8026A4CC:
/* 198DAC 8026A4CC 0C09A75B */  jal   get_actor
/* 198DB0 8026A4D0 00000000 */   nop   
/* 198DB4 8026A4D4 8044040D */  lb    $a0, 0x40d($v0)
/* 198DB8 8026A4D8 00041880 */  sll   $v1, $a0, 2
/* 198DBC 8026A4DC 00641821 */  addu  $v1, $v1, $a0
/* 198DC0 8026A4E0 00031880 */  sll   $v1, $v1, 2
/* 198DC4 8026A4E4 2463022C */  addiu $v1, $v1, 0x22c
/* 198DC8 8026A4E8 00431821 */  addu  $v1, $v0, $v1
/* 198DCC 8026A4EC 84650000 */  lh    $a1, ($v1)
/* 198DD0 8026A4F0 84660002 */  lh    $a2, 2($v1)
/* 198DD4 8026A4F4 0C09A5D5 */  jal   set_goal_pos_to_part
/* 198DD8 8026A4F8 2444000C */   addiu $a0, $v0, 0xc
/* 198DDC 8026A4FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 198DE0 8026A500 8FB00010 */  lw    $s0, 0x10($sp)
/* 198DE4 8026A504 24020002 */  addiu $v0, $zero, 2
/* 198DE8 8026A508 03E00008 */  jr    $ra
/* 198DEC 8026A50C 27BD0018 */   addiu $sp, $sp, 0x18

