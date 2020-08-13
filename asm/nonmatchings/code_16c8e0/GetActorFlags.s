.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetActorFlags
/* 19B800 8026CF20 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19B804 8026CF24 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B808 8026CF28 0080882D */  daddu $s1, $a0, $zero
/* 19B80C 8026CF2C AFBF0018 */  sw    $ra, 0x18($sp)
/* 19B810 8026CF30 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B814 8026CF34 8E30000C */  lw    $s0, 0xc($s1)
/* 19B818 8026CF38 8E050000 */  lw    $a1, ($s0)
/* 19B81C 8026CF3C 0C0B1EAF */  jal   get_variable
/* 19B820 8026CF40 26100004 */   addiu $s0, $s0, 4
/* 19B824 8026CF44 0040202D */  daddu $a0, $v0, $zero
/* 19B828 8026CF48 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B82C 8026CF4C 14820002 */  bne   $a0, $v0, .L8026CF58
/* 19B830 8026CF50 00000000 */   nop   
/* 19B834 8026CF54 8E240148 */  lw    $a0, 0x148($s1)
.L8026CF58:
/* 19B838 8026CF58 0C09A75B */  jal   get_actor
/* 19B83C 8026CF5C 8E100000 */   lw    $s0, ($s0)
/* 19B840 8026CF60 0220202D */  daddu $a0, $s1, $zero
/* 19B844 8026CF64 8C460000 */  lw    $a2, ($v0)
/* 19B848 8026CF68 0C0B2026 */  jal   set_variable
/* 19B84C 8026CF6C 0200282D */   daddu $a1, $s0, $zero
/* 19B850 8026CF70 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19B854 8026CF74 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B858 8026CF78 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B85C 8026CF7C 24020002 */  addiu $v0, $zero, 2
/* 19B860 8026CF80 03E00008 */  jr    $ra
/* 19B864 8026CF84 27BD0020 */   addiu $sp, $sp, 0x20

