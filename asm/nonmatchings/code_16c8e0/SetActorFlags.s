.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetActorFlags
/* 19B710 8026CE30 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19B714 8026CE34 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B718 8026CE38 0080882D */  daddu $s1, $a0, $zero
/* 19B71C 8026CE3C AFBF0018 */  sw    $ra, 0x18($sp)
/* 19B720 8026CE40 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B724 8026CE44 8E30000C */  lw    $s0, 0xc($s1)
/* 19B728 8026CE48 8E050000 */  lw    $a1, ($s0)
/* 19B72C 8026CE4C 0C0B1EAF */  jal   get_variable
/* 19B730 8026CE50 26100004 */   addiu $s0, $s0, 4
/* 19B734 8026CE54 0040202D */  daddu $a0, $v0, $zero
/* 19B738 8026CE58 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B73C 8026CE5C 14820002 */  bne   $a0, $v0, .L8026CE68
/* 19B740 8026CE60 00000000 */   nop   
/* 19B744 8026CE64 8E240148 */  lw    $a0, 0x148($s1)
.L8026CE68:
/* 19B748 8026CE68 0C09A75B */  jal   get_actor
/* 19B74C 8026CE6C 8E100000 */   lw    $s0, ($s0)
/* 19B750 8026CE70 AC500000 */  sw    $s0, ($v0)
/* 19B754 8026CE74 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19B758 8026CE78 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B75C 8026CE7C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B760 8026CE80 24020002 */  addiu $v0, $zero, 2
/* 19B764 8026CE84 03E00008 */  jr    $ra
/* 19B768 8026CE88 27BD0020 */   addiu $sp, $sp, 0x20

