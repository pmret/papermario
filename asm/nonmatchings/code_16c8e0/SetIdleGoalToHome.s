.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetIdleGoalToHome
/* 19880C 80269F2C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 198810 80269F30 AFB00010 */  sw    $s0, 0x10($sp)
/* 198814 80269F34 0080802D */  daddu $s0, $a0, $zero
/* 198818 80269F38 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19881C 80269F3C 8E02000C */  lw    $v0, 0xc($s0)
/* 198820 80269F40 0C0B1EAF */  jal   get_variable
/* 198824 80269F44 8C450000 */   lw    $a1, ($v0)
/* 198828 80269F48 0040202D */  daddu $a0, $v0, $zero
/* 19882C 80269F4C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198830 80269F50 14820002 */  bne   $a0, $v0, .L80269F5C
/* 198834 80269F54 00000000 */   nop   
/* 198838 80269F58 8E040148 */  lw    $a0, 0x148($s0)
.L80269F5C:
/* 19883C 80269F5C 0C09A75B */  jal   get_actor
/* 198840 80269F60 00000000 */   nop   
/* 198844 80269F64 0040182D */  daddu $v1, $v0, $zero
/* 198848 80269F68 C4600138 */  lwc1  $f0, 0x138($v1)
/* 19884C 80269F6C C462013C */  lwc1  $f2, 0x13c($v1)
/* 198850 80269F70 C4640140 */  lwc1  $f4, 0x140($v1)
/* 198854 80269F74 E46000D4 */  swc1  $f0, 0xd4($v1)
/* 198858 80269F78 E46200D8 */  swc1  $f2, 0xd8($v1)
/* 19885C 80269F7C E46400DC */  swc1  $f4, 0xdc($v1)
/* 198860 80269F80 8FBF0014 */  lw    $ra, 0x14($sp)
/* 198864 80269F84 8FB00010 */  lw    $s0, 0x10($sp)
/* 198868 80269F88 24020002 */  addiu $v0, $zero, 2
/* 19886C 80269F8C 03E00008 */  jr    $ra
/* 198870 80269F90 27BD0018 */   addiu $sp, $sp, 0x18

