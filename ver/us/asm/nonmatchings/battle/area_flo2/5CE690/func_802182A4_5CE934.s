.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182A4_5CE934
/* 5CE934 802182A4 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5CE938 802182A8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CE93C 802182AC 0080882D */  daddu     $s1, $a0, $zero
/* 5CE940 802182B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 5CE944 802182B4 AFB40028 */  sw        $s4, 0x28($sp)
/* 5CE948 802182B8 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CE94C 802182BC AFB20020 */  sw        $s2, 0x20($sp)
/* 5CE950 802182C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CE954 802182C4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5CE958 802182C8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5CE95C 802182CC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5CE960 802182D0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5CE964 802182D4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CE968 802182D8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CE96C 802182DC 8E30000C */  lw        $s0, 0xc($s1)
/* 5CE970 802182E0 8E130000 */  lw        $s3, ($s0)
/* 5CE974 802182E4 26100004 */  addiu     $s0, $s0, 4
/* 5CE978 802182E8 0C0B210B */  jal       evt_get_float_variable
/* 5CE97C 802182EC 0260282D */   daddu    $a1, $s3, $zero
/* 5CE980 802182F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 5CE984 802182F4 8E140000 */  lw        $s4, ($s0)
/* 5CE988 802182F8 26100004 */  addiu     $s0, $s0, 4
/* 5CE98C 802182FC 0220202D */  daddu     $a0, $s1, $zero
/* 5CE990 80218300 0C0B210B */  jal       evt_get_float_variable
/* 5CE994 80218304 0280282D */   daddu    $a1, $s4, $zero
/* 5CE998 80218308 46000786 */  mov.s     $f30, $f0
/* 5CE99C 8021830C 8E120000 */  lw        $s2, ($s0)
/* 5CE9A0 80218310 26100004 */  addiu     $s0, $s0, 4
/* 5CE9A4 80218314 0220202D */  daddu     $a0, $s1, $zero
/* 5CE9A8 80218318 0C0B210B */  jal       evt_get_float_variable
/* 5CE9AC 8021831C 0240282D */   daddu    $a1, $s2, $zero
/* 5CE9B0 80218320 46000706 */  mov.s     $f28, $f0
/* 5CE9B4 80218324 8E050000 */  lw        $a1, ($s0)
/* 5CE9B8 80218328 26100004 */  addiu     $s0, $s0, 4
/* 5CE9BC 8021832C 0C0B210B */  jal       evt_get_float_variable
/* 5CE9C0 80218330 0220202D */   daddu    $a0, $s1, $zero
/* 5CE9C4 80218334 8E050000 */  lw        $a1, ($s0)
/* 5CE9C8 80218338 26100004 */  addiu     $s0, $s0, 4
/* 5CE9CC 8021833C 0220202D */  daddu     $a0, $s1, $zero
/* 5CE9D0 80218340 0C0B210B */  jal       evt_get_float_variable
/* 5CE9D4 80218344 46000686 */   mov.s    $f26, $f0
/* 5CE9D8 80218348 46000606 */  mov.s     $f24, $f0
/* 5CE9DC 8021834C 8E050000 */  lw        $a1, ($s0)
/* 5CE9E0 80218350 0C0B210B */  jal       evt_get_float_variable
/* 5CE9E4 80218354 0220202D */   daddu    $a0, $s1, $zero
/* 5CE9E8 80218358 4600D306 */  mov.s     $f12, $f26
/* 5CE9EC 8021835C 3C014170 */  lui       $at, 0x4170
/* 5CE9F0 80218360 44811000 */  mtc1      $at, $f2
/* 5CE9F4 80218364 46000586 */  mov.s     $f22, $f0
/* 5CE9F8 80218368 0C00A8D4 */  jal       cos_deg
/* 5CE9FC 8021836C 4602C601 */   sub.s    $f24, $f24, $f2
/* 5CEA00 80218370 46000506 */  mov.s     $f20, $f0
/* 5CEA04 80218374 0C00A8D4 */  jal       cos_deg
/* 5CEA08 80218378 4600C306 */   mov.s    $f12, $f24
/* 5CEA0C 8021837C 4614B502 */  mul.s     $f20, $f22, $f20
/* 5CEA10 80218380 00000000 */  nop
/* 5CEA14 80218384 4600A502 */  mul.s     $f20, $f20, $f0
/* 5CEA18 80218388 00000000 */  nop
/* 5CEA1C 8021838C C7A40010 */  lwc1      $f4, 0x10($sp)
/* 5CEA20 80218390 46142100 */  add.s     $f4, $f4, $f20
/* 5CEA24 80218394 4600D306 */  mov.s     $f12, $f26
/* 5CEA28 80218398 0C00A8BB */  jal       sin_deg
/* 5CEA2C 8021839C E7A40010 */   swc1     $f4, 0x10($sp)
/* 5CEA30 802183A0 4600B002 */  mul.s     $f0, $f22, $f0
/* 5CEA34 802183A4 00000000 */  nop
/* 5CEA38 802183A8 4600D306 */  mov.s     $f12, $f26
/* 5CEA3C 802183AC 0C00A8D4 */  jal       cos_deg
/* 5CEA40 802183B0 4600F780 */   add.s    $f30, $f30, $f0
/* 5CEA44 802183B4 4600C306 */  mov.s     $f12, $f24
/* 5CEA48 802183B8 0C00A8BB */  jal       sin_deg
/* 5CEA4C 802183BC 46000506 */   mov.s    $f20, $f0
/* 5CEA50 802183C0 4614B582 */  mul.s     $f22, $f22, $f20
/* 5CEA54 802183C4 00000000 */  nop
/* 5CEA58 802183C8 4600B582 */  mul.s     $f22, $f22, $f0
/* 5CEA5C 802183CC 00000000 */  nop
/* 5CEA60 802183D0 0220202D */  daddu     $a0, $s1, $zero
/* 5CEA64 802183D4 0260282D */  daddu     $a1, $s3, $zero
/* 5CEA68 802183D8 8FA60010 */  lw        $a2, 0x10($sp)
/* 5CEA6C 802183DC 0C0B2190 */  jal       evt_set_float_variable
/* 5CEA70 802183E0 4616E701 */   sub.s    $f28, $f28, $f22
/* 5CEA74 802183E4 0220202D */  daddu     $a0, $s1, $zero
/* 5CEA78 802183E8 4406F000 */  mfc1      $a2, $f30
/* 5CEA7C 802183EC 0C0B2190 */  jal       evt_set_float_variable
/* 5CEA80 802183F0 0280282D */   daddu    $a1, $s4, $zero
/* 5CEA84 802183F4 0220202D */  daddu     $a0, $s1, $zero
/* 5CEA88 802183F8 4406E000 */  mfc1      $a2, $f28
/* 5CEA8C 802183FC 0C0B2190 */  jal       evt_set_float_variable
/* 5CEA90 80218400 0240282D */   daddu    $a1, $s2, $zero
/* 5CEA94 80218404 8FBF002C */  lw        $ra, 0x2c($sp)
/* 5CEA98 80218408 8FB40028 */  lw        $s4, 0x28($sp)
/* 5CEA9C 8021840C 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CEAA0 80218410 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CEAA4 80218414 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CEAA8 80218418 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CEAAC 8021841C D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5CEAB0 80218420 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5CEAB4 80218424 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5CEAB8 80218428 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5CEABC 8021842C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CEAC0 80218430 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CEAC4 80218434 24020002 */  addiu     $v0, $zero, 2
/* 5CEAC8 80218438 03E00008 */  jr        $ra
/* 5CEACC 8021843C 27BD0060 */   addiu    $sp, $sp, 0x60
