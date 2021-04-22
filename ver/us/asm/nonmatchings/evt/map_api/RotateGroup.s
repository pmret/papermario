.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RotateGroup
/* EE288 802C98D8 27BDFF78 */  addiu     $sp, $sp, -0x88
/* EE28C 802C98DC AFB1005C */  sw        $s1, 0x5c($sp)
/* EE290 802C98E0 0080882D */  daddu     $s1, $a0, $zero
/* EE294 802C98E4 AFBF0064 */  sw        $ra, 0x64($sp)
/* EE298 802C98E8 AFB20060 */  sw        $s2, 0x60($sp)
/* EE29C 802C98EC AFB00058 */  sw        $s0, 0x58($sp)
/* EE2A0 802C98F0 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* EE2A4 802C98F4 F7B80078 */  sdc1      $f24, 0x78($sp)
/* EE2A8 802C98F8 F7B60070 */  sdc1      $f22, 0x70($sp)
/* EE2AC 802C98FC F7B40068 */  sdc1      $f20, 0x68($sp)
/* EE2B0 802C9900 8E30000C */  lw        $s0, 0xc($s1)
/* EE2B4 802C9904 0C0B1EAF */  jal       get_variable
/* EE2B8 802C9908 8E050000 */   lw       $a1, ($s0)
/* EE2BC 802C990C 0C046C24 */  jal       func_8011B090
/* EE2C0 802C9910 0040202D */   daddu    $a0, $v0, $zero
/* EE2C4 802C9914 0040902D */  daddu     $s2, $v0, $zero
/* EE2C8 802C9918 2402FFFF */  addiu     $v0, $zero, -1
/* EE2CC 802C991C 16420007 */  bne       $s2, $v0, .L802C993C
/* EE2D0 802C9920 26100004 */   addiu    $s0, $s0, 4
/* EE2D4 802C9924 3C04802D */  lui       $a0, %hi(RotateModel)
/* EE2D8 802C9928 24848C64 */  addiu     $a0, $a0, %lo(RotateModel)
/* EE2DC 802C992C 0C0B2568 */  jal       func_802C95A0
/* EE2E0 802C9930 0220282D */   daddu    $a1, $s1, $zero
/* EE2E4 802C9934 080B267D */  j         .L802C99F4
/* EE2E8 802C9938 24020002 */   addiu    $v0, $zero, 2
.L802C993C:
/* EE2EC 802C993C 8E050000 */  lw        $a1, ($s0)
/* EE2F0 802C9940 26100004 */  addiu     $s0, $s0, 4
/* EE2F4 802C9944 0C0B210B */  jal       get_float_variable
/* EE2F8 802C9948 0220202D */   daddu    $a0, $s1, $zero
/* EE2FC 802C994C 8E050000 */  lw        $a1, ($s0)
/* EE300 802C9950 26100004 */  addiu     $s0, $s0, 4
/* EE304 802C9954 0220202D */  daddu     $a0, $s1, $zero
/* EE308 802C9958 0C0B210B */  jal       get_float_variable
/* EE30C 802C995C 46000686 */   mov.s    $f26, $f0
/* EE310 802C9960 8E050000 */  lw        $a1, ($s0)
/* EE314 802C9964 26100004 */  addiu     $s0, $s0, 4
/* EE318 802C9968 0220202D */  daddu     $a0, $s1, $zero
/* EE31C 802C996C 0C0B210B */  jal       get_float_variable
/* EE320 802C9970 46000606 */   mov.s    $f24, $f0
/* EE324 802C9974 0220202D */  daddu     $a0, $s1, $zero
/* EE328 802C9978 8E050000 */  lw        $a1, ($s0)
/* EE32C 802C997C 0C0B210B */  jal       get_float_variable
/* EE330 802C9980 46000506 */   mov.s    $f20, $f0
/* EE334 802C9984 0240202D */  daddu     $a0, $s2, $zero
/* EE338 802C9988 0C046C70 */  jal       func_8011B1C0
/* EE33C 802C998C 46000586 */   mov.s    $f22, $f0
/* EE340 802C9990 0040802D */  daddu     $s0, $v0, $zero
/* EE344 802C9994 96020000 */  lhu       $v0, ($s0)
/* EE348 802C9998 30420400 */  andi      $v0, $v0, 0x400
/* EE34C 802C999C 1440000B */  bnez      $v0, .L802C99CC
/* EE350 802C99A0 27A40018 */   addiu    $a0, $sp, 0x18
/* EE354 802C99A4 4405D000 */  mfc1      $a1, $f26
/* EE358 802C99A8 4406C000 */  mfc1      $a2, $f24
/* EE35C 802C99AC 4407A000 */  mfc1      $a3, $f20
/* EE360 802C99B0 26040050 */  addiu     $a0, $s0, 0x50
/* EE364 802C99B4 0C019EC8 */  jal       guRotateF
/* EE368 802C99B8 E7B60010 */   swc1     $f22, 0x10($sp)
/* EE36C 802C99BC 96020000 */  lhu       $v0, ($s0)
/* EE370 802C99C0 34421400 */  ori       $v0, $v0, 0x1400
/* EE374 802C99C4 080B267C */  j         .L802C99F0
/* EE378 802C99C8 A6020000 */   sh       $v0, ($s0)
.L802C99CC:
/* EE37C 802C99CC 4405D000 */  mfc1      $a1, $f26
/* EE380 802C99D0 4406C000 */  mfc1      $a2, $f24
/* EE384 802C99D4 4407A000 */  mfc1      $a3, $f20
/* EE388 802C99D8 0C019EC8 */  jal       guRotateF
/* EE38C 802C99DC E7B60010 */   swc1     $f22, 0x10($sp)
/* EE390 802C99E0 27A40018 */  addiu     $a0, $sp, 0x18
/* EE394 802C99E4 26050050 */  addiu     $a1, $s0, 0x50
/* EE398 802C99E8 0C019D80 */  jal       guMtxCatF
/* EE39C 802C99EC 00A0302D */   daddu    $a2, $a1, $zero
.L802C99F0:
/* EE3A0 802C99F0 24020002 */  addiu     $v0, $zero, 2
.L802C99F4:
/* EE3A4 802C99F4 8FBF0064 */  lw        $ra, 0x64($sp)
/* EE3A8 802C99F8 8FB20060 */  lw        $s2, 0x60($sp)
/* EE3AC 802C99FC 8FB1005C */  lw        $s1, 0x5c($sp)
/* EE3B0 802C9A00 8FB00058 */  lw        $s0, 0x58($sp)
/* EE3B4 802C9A04 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* EE3B8 802C9A08 D7B80078 */  ldc1      $f24, 0x78($sp)
/* EE3BC 802C9A0C D7B60070 */  ldc1      $f22, 0x70($sp)
/* EE3C0 802C9A10 D7B40068 */  ldc1      $f20, 0x68($sp)
/* EE3C4 802C9A14 03E00008 */  jr        $ra
/* EE3C8 802C9A18 27BD0088 */   addiu    $sp, $sp, 0x88
