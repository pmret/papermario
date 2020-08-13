.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetActorLevel
/* 1AE628 8027FD48 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AE62C 8027FD4C AFB10014 */  sw    $s1, 0x14($sp)
/* 1AE630 8027FD50 0080882D */  daddu $s1, $a0, $zero
/* 1AE634 8027FD54 AFBF0018 */  sw    $ra, 0x18($sp)
/* 1AE638 8027FD58 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AE63C 8027FD5C 8E30000C */  lw    $s0, 0xc($s1)
/* 1AE640 8027FD60 8E050000 */  lw    $a1, ($s0)
/* 1AE644 8027FD64 0C0B1EAF */  jal   get_variable
/* 1AE648 8027FD68 26100004 */   addiu $s0, $s0, 4
/* 1AE64C 8027FD6C 0040202D */  daddu $a0, $v0, $zero
/* 1AE650 8027FD70 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AE654 8027FD74 14820002 */  bne   $a0, $v0, .L8027FD80
/* 1AE658 8027FD78 00000000 */   nop   
/* 1AE65C 8027FD7C 8E240148 */  lw    $a0, 0x148($s1)
.L8027FD80:
/* 1AE660 8027FD80 0C09A75B */  jal   get_actor
/* 1AE664 8027FD84 8E100000 */   lw    $s0, ($s0)
/* 1AE668 8027FD88 8C420008 */  lw    $v0, 8($v0)
/* 1AE66C 8027FD8C 0220202D */  daddu $a0, $s1, $zero
/* 1AE670 8027FD90 90460006 */  lbu   $a2, 6($v0)
/* 1AE674 8027FD94 0C0B2026 */  jal   set_variable
/* 1AE678 8027FD98 0200282D */   daddu $a1, $s0, $zero
/* 1AE67C 8027FD9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1AE680 8027FDA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AE684 8027FDA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AE688 8027FDA8 24020002 */  addiu $v0, $zero, 2
/* 1AE68C 8027FDAC 03E00008 */  jr    $ra
/* 1AE690 8027FDB0 27BD0020 */   addiu $sp, $sp, 0x20

