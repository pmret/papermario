.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel IsPlayerWithin
/* 0F9314 802D4964 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F9318 802D4968 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F931C 802D496C 0080882D */  daddu $s1, $a0, $zero
/* 0F9320 802D4970 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9324 802D4974 3C12FE36 */  lui   $s2, 0xfe36
/* 0F9328 802D4978 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F932C 802D497C 3C138011 */  lui   $s3, 0x8011
/* 0F9330 802D4980 2673EFC8 */  addiu $s3, $s3, -0x1038
/* 0F9334 802D4984 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F9338 802D4988 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F933C 802D498C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0F9340 802D4990 8E30000C */  lw    $s0, 0xc($s1)
/* 0F9344 802D4994 10A00010 */  beqz  $a1, .L802D49D8
/* 0F9348 802D4998 36523C80 */   ori   $s2, $s2, 0x3c80
/* 0F934C 802D499C 8E050000 */  lw    $a1, ($s0)
/* 0F9350 802D49A0 0C0B1EAF */  jal   get_variable
/* 0F9354 802D49A4 26100004 */   addiu $s0, $s0, 4
/* 0F9358 802D49A8 AE220070 */  sw    $v0, 0x70($s1)
/* 0F935C 802D49AC 8E050000 */  lw    $a1, ($s0)
/* 0F9360 802D49B0 26100004 */  addiu $s0, $s0, 4
/* 0F9364 802D49B4 0C0B1EAF */  jal   get_variable
/* 0F9368 802D49B8 0220202D */   daddu $a0, $s1, $zero
/* 0F936C 802D49BC AE220074 */  sw    $v0, 0x74($s1)
/* 0F9370 802D49C0 8E050000 */  lw    $a1, ($s0)
/* 0F9374 802D49C4 26100004 */  addiu $s0, $s0, 4
/* 0F9378 802D49C8 0C0B1EAF */  jal   get_variable
/* 0F937C 802D49CC 0220202D */   daddu $a0, $s1, $zero
/* 0F9380 802D49D0 AE220078 */  sw    $v0, 0x78($s1)
/* 0F9384 802D49D4 8E120000 */  lw    $s2, ($s0)
.L802D49D8:
/* 0F9388 802D49D8 C6220070 */  lwc1  $f2, 0x70($s1)
/* 0F938C 802D49DC 468010A0 */  cvt.s.w $f2, $f2
/* 0F9390 802D49E0 44061000 */  mfc1  $a2, $f2
/* 0F9394 802D49E4 C6220074 */  lwc1  $f2, 0x74($s1)
/* 0F9398 802D49E8 468010A0 */  cvt.s.w $f2, $f2
/* 0F939C 802D49EC C66C0028 */  lwc1  $f12, 0x28($s3)
/* 0F93A0 802D49F0 C66E0030 */  lwc1  $f14, 0x30($s3)
/* 0F93A4 802D49F4 44071000 */  mfc1  $a3, $f2
/* 0F93A8 802D49F8 0C00A7B5 */  jal   dist2D
/* 0F93AC 802D49FC 00000000 */   nop   
/* 0F93B0 802D4A00 0220202D */  daddu $a0, $s1, $zero
/* 0F93B4 802D4A04 0240282D */  daddu $a1, $s2, $zero
/* 0F93B8 802D4A08 0000302D */  daddu $a2, $zero, $zero
/* 0F93BC 802D4A0C 0C0B2026 */  jal   set_variable
/* 0F93C0 802D4A10 46000506 */   mov.s $f20, $f0
/* 0F93C4 802D4A14 C6200078 */  lwc1  $f0, 0x78($s1)
/* 0F93C8 802D4A18 46800020 */  cvt.s.w $f0, $f0
/* 0F93CC 802D4A1C 4600A03C */  c.lt.s $f20, $f0
/* 0F93D0 802D4A20 00000000 */  nop   
/* 0F93D4 802D4A24 45000004 */  bc1f  .L802D4A38
/* 0F93D8 802D4A28 0220202D */   daddu $a0, $s1, $zero
/* 0F93DC 802D4A2C 0240282D */  daddu $a1, $s2, $zero
/* 0F93E0 802D4A30 0C0B2026 */  jal   set_variable
/* 0F93E4 802D4A34 24060001 */   addiu $a2, $zero, 1
.L802D4A38:
/* 0F93E8 802D4A38 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F93EC 802D4A3C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F93F0 802D4A40 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F93F4 802D4A44 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F93F8 802D4A48 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F93FC 802D4A4C D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0F9400 802D4A50 24020002 */  addiu $v0, $zero, 2
/* 0F9404 802D4A54 03E00008 */  jr    $ra
/* 0F9408 802D4A58 27BD0030 */   addiu $sp, $sp, 0x30

