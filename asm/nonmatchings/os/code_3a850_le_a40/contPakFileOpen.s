.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel contPakFileOpen
/* 03ABB0 8005F7B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03ABB4 8005F7B4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 03ABB8 8005F7B8 AFB20028 */  sw    $s2, 0x28($sp)
/* 03ABBC 8005F7BC AFB10024 */  sw    $s1, 0x24($sp)
/* 03ABC0 8005F7C0 AFB00020 */  sw    $s0, 0x20($sp)
/* 03ABC4 8005F7C4 8C90000C */  lw    $s0, 0xc($a0)
/* 03ABC8 8005F7C8 3C058009 */  lui   $a1, 0x8009
/* 03ABCC 8005F7CC 94A53CA0 */  lhu   $a1, 0x3ca0($a1)
/* 03ABD0 8005F7D0 3C068009 */  lui   $a2, 0x8009
/* 03ABD4 8005F7D4 8CC63CA4 */  lw    $a2, 0x3ca4($a2)
/* 03ABD8 8005F7D8 8E110000 */  lw    $s1, ($s0)
/* 03ABDC 8005F7DC 8E020008 */  lw    $v0, 8($s0)
/* 03ABE0 8005F7E0 26320004 */  addiu $s2, $s1, 4
/* 03ABE4 8005F7E4 AFA20010 */  sw    $v0, 0x10($sp)
/* 03ABE8 8005F7E8 AFB20014 */  sw    $s2, 0x14($sp)
/* 03ABEC 8005F7EC 8E240000 */  lw    $a0, ($s1)
/* 03ABF0 8005F7F0 0C01A370 */  jal   osPfsFindFile
/* 03ABF4 8005F7F4 8E070004 */   lw    $a3, 4($s0)
/* 03ABF8 8005F7F8 0040202D */  daddu $a0, $v0, $zero
/* 03ABFC 8005F7FC 24020005 */  addiu $v0, $zero, 5
/* 03AC00 8005F800 14820011 */  bne   $a0, $v0, .L8005F848
/* 03AC04 8005F804 24020001 */   addiu $v0, $zero, 1
/* 03AC08 8005F808 8E030010 */  lw    $v1, 0x10($s0)
/* 03AC0C 8005F80C 1462000E */  bne   $v1, $v0, .L8005F848
/* 03AC10 8005F810 00000000 */   nop   
/* 03AC14 8005F814 8E020008 */  lw    $v0, 8($s0)
/* 03AC18 8005F818 3C058009 */  lui   $a1, 0x8009
/* 03AC1C 8005F81C 94A53CA0 */  lhu   $a1, 0x3ca0($a1)
/* 03AC20 8005F820 3C068009 */  lui   $a2, 0x8009
/* 03AC24 8005F824 8CC63CA4 */  lw    $a2, 0x3ca4($a2)
/* 03AC28 8005F828 AFA20010 */  sw    $v0, 0x10($sp)
/* 03AC2C 8005F82C 8E02000C */  lw    $v0, 0xc($s0)
/* 03AC30 8005F830 AFB20018 */  sw    $s2, 0x18($sp)
/* 03AC34 8005F834 AFA20014 */  sw    $v0, 0x14($sp)
/* 03AC38 8005F838 8E240000 */  lw    $a0, ($s1)
/* 03AC3C 8005F83C 0C01A064 */  jal   osPfsAllocateFile
/* 03AC40 8005F840 8E070004 */   lw    $a3, 4($s0)
/* 03AC44 8005F844 0040202D */  daddu $a0, $v0, $zero
.L8005F848:
/* 03AC48 8005F848 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03AC4C 8005F84C 8FB20028 */  lw    $s2, 0x28($sp)
/* 03AC50 8005F850 8FB10024 */  lw    $s1, 0x24($sp)
/* 03AC54 8005F854 8FB00020 */  lw    $s0, 0x20($sp)
/* 03AC58 8005F858 0080102D */  daddu $v0, $a0, $zero
/* 03AC5C 8005F85C 03E00008 */  jr    $ra
/* 03AC60 8005F860 27BD0030 */   addiu $sp, $sp, 0x30

