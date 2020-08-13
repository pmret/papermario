.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel RotateGroup
/* 0EE288 802C98D8 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0EE28C 802C98DC AFB1005C */  sw    $s1, 0x5c($sp)
/* 0EE290 802C98E0 0080882D */  daddu $s1, $a0, $zero
/* 0EE294 802C98E4 AFBF0064 */  sw    $ra, 0x64($sp)
/* 0EE298 802C98E8 AFB20060 */  sw    $s2, 0x60($sp)
/* 0EE29C 802C98EC AFB00058 */  sw    $s0, 0x58($sp)
/* 0EE2A0 802C98F0 F7BA0080 */  sdc1  $f26, 0x80($sp)
/* 0EE2A4 802C98F4 F7B80078 */  sdc1  $f24, 0x78($sp)
/* 0EE2A8 802C98F8 F7B60070 */  sdc1  $f22, 0x70($sp)
/* 0EE2AC 802C98FC F7B40068 */  sdc1  $f20, 0x68($sp)
/* 0EE2B0 802C9900 8E30000C */  lw    $s0, 0xc($s1)
/* 0EE2B4 802C9904 0C0B1EAF */  jal   get_variable
/* 0EE2B8 802C9908 8E050000 */   lw    $a1, ($s0)
/* 0EE2BC 802C990C 0C046C24 */  jal   func_8011B090
/* 0EE2C0 802C9910 0040202D */   daddu $a0, $v0, $zero
/* 0EE2C4 802C9914 0040902D */  daddu $s2, $v0, $zero
/* 0EE2C8 802C9918 2402FFFF */  addiu $v0, $zero, -1
/* 0EE2CC 802C991C 16420007 */  bne   $s2, $v0, .L802C993C
/* 0EE2D0 802C9920 26100004 */   addiu $s0, $s0, 4
/* 0EE2D4 802C9924 3C04802D */  lui   $a0, 0x802d
/* 0EE2D8 802C9928 24848C64 */  addiu $a0, $a0, -0x739c
/* 0EE2DC 802C992C 0C0B2568 */  jal   func_802C95A0
/* 0EE2E0 802C9930 0220282D */   daddu $a1, $s1, $zero
/* 0EE2E4 802C9934 080B267D */  j     .L802C99F4
/* 0EE2E8 802C9938 24020002 */   addiu $v0, $zero, 2

.L802C993C:
/* 0EE2EC 802C993C 8E050000 */  lw    $a1, ($s0)
/* 0EE2F0 802C9940 26100004 */  addiu $s0, $s0, 4
/* 0EE2F4 802C9944 0C0B210B */  jal   get_float_variable
/* 0EE2F8 802C9948 0220202D */   daddu $a0, $s1, $zero
/* 0EE2FC 802C994C 8E050000 */  lw    $a1, ($s0)
/* 0EE300 802C9950 26100004 */  addiu $s0, $s0, 4
/* 0EE304 802C9954 0220202D */  daddu $a0, $s1, $zero
/* 0EE308 802C9958 0C0B210B */  jal   get_float_variable
/* 0EE30C 802C995C 46000686 */   mov.s $f26, $f0
/* 0EE310 802C9960 8E050000 */  lw    $a1, ($s0)
/* 0EE314 802C9964 26100004 */  addiu $s0, $s0, 4
/* 0EE318 802C9968 0220202D */  daddu $a0, $s1, $zero
/* 0EE31C 802C996C 0C0B210B */  jal   get_float_variable
/* 0EE320 802C9970 46000606 */   mov.s $f24, $f0
/* 0EE324 802C9974 0220202D */  daddu $a0, $s1, $zero
/* 0EE328 802C9978 8E050000 */  lw    $a1, ($s0)
/* 0EE32C 802C997C 0C0B210B */  jal   get_float_variable
/* 0EE330 802C9980 46000506 */   mov.s $f20, $f0
/* 0EE334 802C9984 0240202D */  daddu $a0, $s2, $zero
/* 0EE338 802C9988 0C046C70 */  jal   func_8011B1C0
/* 0EE33C 802C998C 46000586 */   mov.s $f22, $f0
/* 0EE340 802C9990 0040802D */  daddu $s0, $v0, $zero
/* 0EE344 802C9994 96020000 */  lhu   $v0, ($s0)
/* 0EE348 802C9998 30420400 */  andi  $v0, $v0, 0x400
/* 0EE34C 802C999C 1440000B */  bnez  $v0, .L802C99CC
/* 0EE350 802C99A0 27A40018 */   addiu $a0, $sp, 0x18
/* 0EE354 802C99A4 4405D000 */  mfc1  $a1, $f26
/* 0EE358 802C99A8 4406C000 */  mfc1  $a2, $f24
/* 0EE35C 802C99AC 4407A000 */  mfc1  $a3, $f20
/* 0EE360 802C99B0 26040050 */  addiu $a0, $s0, 0x50
/* 0EE364 802C99B4 0C019EC8 */  jal   guRotateF
/* 0EE368 802C99B8 E7B60010 */   swc1  $f22, 0x10($sp)
/* 0EE36C 802C99BC 96020000 */  lhu   $v0, ($s0)
/* 0EE370 802C99C0 34421400 */  ori   $v0, $v0, 0x1400
/* 0EE374 802C99C4 080B267C */  j     .L802C99F0
/* 0EE378 802C99C8 A6020000 */   sh    $v0, ($s0)

.L802C99CC:
/* 0EE37C 802C99CC 4405D000 */  mfc1  $a1, $f26
/* 0EE380 802C99D0 4406C000 */  mfc1  $a2, $f24
/* 0EE384 802C99D4 4407A000 */  mfc1  $a3, $f20
/* 0EE388 802C99D8 0C019EC8 */  jal   guRotateF
/* 0EE38C 802C99DC E7B60010 */   swc1  $f22, 0x10($sp)
/* 0EE390 802C99E0 27A40018 */  addiu $a0, $sp, 0x18
/* 0EE394 802C99E4 26050050 */  addiu $a1, $s0, 0x50
/* 0EE398 802C99E8 0C019D80 */  jal   guMtxCatF
/* 0EE39C 802C99EC 00A0302D */   daddu $a2, $a1, $zero
.L802C99F0:
/* 0EE3A0 802C99F0 24020002 */  addiu $v0, $zero, 2
.L802C99F4:
/* 0EE3A4 802C99F4 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0EE3A8 802C99F8 8FB20060 */  lw    $s2, 0x60($sp)
/* 0EE3AC 802C99FC 8FB1005C */  lw    $s1, 0x5c($sp)
/* 0EE3B0 802C9A00 8FB00058 */  lw    $s0, 0x58($sp)
/* 0EE3B4 802C9A04 D7BA0080 */  ldc1  $f26, 0x80($sp)
/* 0EE3B8 802C9A08 D7B80078 */  ldc1  $f24, 0x78($sp)
/* 0EE3BC 802C9A0C D7B60070 */  ldc1  $f22, 0x70($sp)
/* 0EE3C0 802C9A10 D7B40068 */  ldc1  $f20, 0x68($sp)
/* 0EE3C4 802C9A14 03E00008 */  jr    $ra
/* 0EE3C8 802C9A18 27BD0088 */   addiu $sp, $sp, 0x88

