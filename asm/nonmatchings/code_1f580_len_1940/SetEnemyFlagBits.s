.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetEnemyFlagBits
/* 020A88 80045688 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 020A8C 8004568C AFB10014 */  sw    $s1, 0x14($sp)
/* 020A90 80045690 0080882D */  daddu $s1, $a0, $zero
/* 020A94 80045694 AFBF0020 */  sw    $ra, 0x20($sp)
/* 020A98 80045698 AFB3001C */  sw    $s3, 0x1c($sp)
/* 020A9C 8004569C AFB20018 */  sw    $s2, 0x18($sp)
/* 020AA0 800456A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 020AA4 800456A4 8E30000C */  lw    $s0, 0xc($s1)
/* 020AA8 800456A8 8E330148 */  lw    $s3, 0x148($s1)
/* 020AAC 800456AC 8E050000 */  lw    $a1, ($s0)
/* 020AB0 800456B0 0C0B1EAF */  jal   get_variable
/* 020AB4 800456B4 26100004 */   addiu $s0, $s0, 4
/* 020AB8 800456B8 0040902D */  daddu $s2, $v0, $zero
/* 020ABC 800456BC 8E050004 */  lw    $a1, 4($s0)
/* 020AC0 800456C0 8E100000 */  lw    $s0, ($s0)
/* 020AC4 800456C4 0C0B1EAF */  jal   get_variable
/* 020AC8 800456C8 0220202D */   daddu $a0, $s1, $zero
/* 020ACC 800456CC 0040882D */  daddu $s1, $v0, $zero
/* 020AD0 800456D0 2402FFFF */  addiu $v0, $zero, -1
/* 020AD4 800456D4 16420002 */  bne   $s2, $v0, .L800456E0
/* 020AD8 800456D8 00000000 */   nop   
/* 020ADC 800456DC 86720008 */  lh    $s2, 8($s3)
.L800456E0:
/* 020AE0 800456E0 0C00FB3A */  jal   get_enemy
/* 020AE4 800456E4 0240202D */   daddu $a0, $s2, $zero
/* 020AE8 800456E8 12200004 */  beqz  $s1, .L800456FC
/* 020AEC 800456EC 0040982D */   daddu $s3, $v0, $zero
/* 020AF0 800456F0 8E620000 */  lw    $v0, ($s3)
/* 020AF4 800456F4 080115C2 */  j     .L80045708
/* 020AF8 800456F8 00501025 */   or    $v0, $v0, $s0

.L800456FC:
/* 020AFC 800456FC 8E620000 */  lw    $v0, ($s3)
/* 020B00 80045700 00101827 */  nor   $v1, $zero, $s0
/* 020B04 80045704 00431024 */  and   $v0, $v0, $v1
.L80045708:
/* 020B08 80045708 AE620000 */  sw    $v0, ($s3)
/* 020B0C 8004570C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 020B10 80045710 8FB3001C */  lw    $s3, 0x1c($sp)
/* 020B14 80045714 8FB20018 */  lw    $s2, 0x18($sp)
/* 020B18 80045718 8FB10014 */  lw    $s1, 0x14($sp)
/* 020B1C 8004571C 8FB00010 */  lw    $s0, 0x10($sp)
/* 020B20 80045720 24020002 */  addiu $v0, $zero, 2
/* 020B24 80045724 03E00008 */  jr    $ra
/* 020B28 80045728 27BD0028 */   addiu $sp, $sp, 0x28

/* 020B2C 8004572C 03E00008 */  jr    $ra
/* 020B30 80045730 24020002 */   addiu $v0, $zero, 2

