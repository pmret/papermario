.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DAC
/* A3A28C 80240DAC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A3A290 80240DB0 AFB10014 */  sw        $s1, 0x14($sp)
/* A3A294 80240DB4 0080882D */  daddu     $s1, $a0, $zero
/* A3A298 80240DB8 AFBF0024 */  sw        $ra, 0x24($sp)
/* A3A29C 80240DBC AFB40020 */  sw        $s4, 0x20($sp)
/* A3A2A0 80240DC0 AFB3001C */  sw        $s3, 0x1c($sp)
/* A3A2A4 80240DC4 AFB20018 */  sw        $s2, 0x18($sp)
/* A3A2A8 80240DC8 AFB00010 */  sw        $s0, 0x10($sp)
/* A3A2AC 80240DCC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* A3A2B0 80240DD0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* A3A2B4 80240DD4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* A3A2B8 80240DD8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A3A2BC 80240DDC F7B40028 */  sdc1      $f20, 0x28($sp)
/* A3A2C0 80240DE0 8E30000C */  lw        $s0, 0xc($s1)
/* A3A2C4 80240DE4 8E130000 */  lw        $s3, ($s0)
/* A3A2C8 80240DE8 26100004 */  addiu     $s0, $s0, 4
/* A3A2CC 80240DEC 0C0B1EAF */  jal       get_variable
/* A3A2D0 80240DF0 0260282D */   daddu    $a1, $s3, $zero
/* A3A2D4 80240DF4 4482E000 */  mtc1      $v0, $f28
/* A3A2D8 80240DF8 00000000 */  nop       
/* A3A2DC 80240DFC 4680E720 */  cvt.s.w   $f28, $f28
/* A3A2E0 80240E00 8E140000 */  lw        $s4, ($s0)
/* A3A2E4 80240E04 26100004 */  addiu     $s0, $s0, 4
/* A3A2E8 80240E08 0220202D */  daddu     $a0, $s1, $zero
/* A3A2EC 80240E0C 0C0B1EAF */  jal       get_variable
/* A3A2F0 80240E10 0280282D */   daddu    $a1, $s4, $zero
/* A3A2F4 80240E14 4482D000 */  mtc1      $v0, $f26
/* A3A2F8 80240E18 00000000 */  nop       
/* A3A2FC 80240E1C 4680D6A0 */  cvt.s.w   $f26, $f26
/* A3A300 80240E20 8E100000 */  lw        $s0, ($s0)
/* A3A304 80240E24 0220202D */  daddu     $a0, $s1, $zero
/* A3A308 80240E28 0C0B1EAF */  jal       get_variable
/* A3A30C 80240E2C 0200282D */   daddu    $a1, $s0, $zero
/* A3A310 80240E30 4482C000 */  mtc1      $v0, $f24
/* A3A314 80240E34 00000000 */  nop       
/* A3A318 80240E38 4680C620 */  cvt.s.w   $f24, $f24
/* A3A31C 80240E3C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* A3A320 80240E40 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* A3A324 80240E44 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A3A328 80240E48 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A3A32C 80240E4C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* A3A330 80240E50 44800000 */  mtc1      $zero, $f0
/* A3A334 80240E54 00031080 */  sll       $v0, $v1, 2
/* A3A338 80240E58 00431021 */  addu      $v0, $v0, $v1
/* A3A33C 80240E5C 00021080 */  sll       $v0, $v0, 2
/* A3A340 80240E60 00431023 */  subu      $v0, $v0, $v1
/* A3A344 80240E64 000218C0 */  sll       $v1, $v0, 3
/* A3A348 80240E68 00431021 */  addu      $v0, $v0, $v1
/* A3A34C 80240E6C 000210C0 */  sll       $v0, $v0, 3
/* A3A350 80240E70 46001032 */  c.eq.s    $f2, $f0
/* A3A354 80240E74 3C01800B */  lui       $at, 0x800b
/* A3A358 80240E78 00220821 */  addu      $at, $at, $v0
/* A3A35C 80240E7C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* A3A360 80240E80 45000005 */  bc1f      .L80240E98
/* A3A364 80240E84 00000000 */   nop      
/* A3A368 80240E88 3C0142C8 */  lui       $at, 0x42c8
/* A3A36C 80240E8C 44810000 */  mtc1      $at, $f0
/* A3A370 80240E90 080903AA */  j         .L80240EA8
/* A3A374 80240E94 4600B581 */   sub.s    $f22, $f22, $f0
.L80240E98:
/* A3A378 80240E98 3C0142C8 */  lui       $at, 0x42c8
/* A3A37C 80240E9C 44810000 */  mtc1      $at, $f0
/* A3A380 80240EA0 00000000 */  nop       
/* A3A384 80240EA4 4600B580 */  add.s     $f22, $f22, $f0
.L80240EA8:
/* A3A388 80240EA8 0C00A6C9 */  jal       clamp_angle
/* A3A38C 80240EAC 4600B306 */   mov.s    $f12, $f22
/* A3A390 80240EB0 46000586 */  mov.s     $f22, $f0
/* A3A394 80240EB4 3C014170 */  lui       $at, 0x4170
/* A3A398 80240EB8 4481A000 */  mtc1      $at, $f20
/* A3A39C 80240EBC 0C00A8BB */  jal       sin_deg
/* A3A3A0 80240EC0 4600B306 */   mov.s    $f12, $f22
/* A3A3A4 80240EC4 46140002 */  mul.s     $f0, $f0, $f20
/* A3A3A8 80240EC8 00000000 */  nop       
/* A3A3AC 80240ECC 864200B0 */  lh        $v0, 0xb0($s2)
/* A3A3B0 80240ED0 3C013F00 */  lui       $at, 0x3f00
/* A3A3B4 80240ED4 44812000 */  mtc1      $at, $f4
/* A3A3B8 80240ED8 44821000 */  mtc1      $v0, $f2
/* A3A3BC 80240EDC 00000000 */  nop       
/* A3A3C0 80240EE0 468010A0 */  cvt.s.w   $f2, $f2
/* A3A3C4 80240EE4 46041082 */  mul.s     $f2, $f2, $f4
/* A3A3C8 80240EE8 00000000 */  nop       
/* A3A3CC 80240EEC 4600E700 */  add.s     $f28, $f28, $f0
/* A3A3D0 80240EF0 4602D680 */  add.s     $f26, $f26, $f2
/* A3A3D4 80240EF4 0C00A8D4 */  jal       cos_deg
/* A3A3D8 80240EF8 4600B306 */   mov.s    $f12, $f22
/* A3A3DC 80240EFC 46140002 */  mul.s     $f0, $f0, $f20
/* A3A3E0 80240F00 00000000 */  nop       
/* A3A3E4 80240F04 0220202D */  daddu     $a0, $s1, $zero
/* A3A3E8 80240F08 0260282D */  daddu     $a1, $s3, $zero
/* A3A3EC 80240F0C 4600E18D */  trunc.w.s $f6, $f28
/* A3A3F0 80240F10 44063000 */  mfc1      $a2, $f6
/* A3A3F4 80240F14 0C0B2026 */  jal       set_variable
/* A3A3F8 80240F18 4600C601 */   sub.s    $f24, $f24, $f0
/* A3A3FC 80240F1C 0220202D */  daddu     $a0, $s1, $zero
/* A3A400 80240F20 4600D18D */  trunc.w.s $f6, $f26
/* A3A404 80240F24 44063000 */  mfc1      $a2, $f6
/* A3A408 80240F28 0C0B2026 */  jal       set_variable
/* A3A40C 80240F2C 0280282D */   daddu    $a1, $s4, $zero
/* A3A410 80240F30 0220202D */  daddu     $a0, $s1, $zero
/* A3A414 80240F34 4600C18D */  trunc.w.s $f6, $f24
/* A3A418 80240F38 44063000 */  mfc1      $a2, $f6
/* A3A41C 80240F3C 0C0B2026 */  jal       set_variable
/* A3A420 80240F40 0200282D */   daddu    $a1, $s0, $zero
/* A3A424 80240F44 8FBF0024 */  lw        $ra, 0x24($sp)
/* A3A428 80240F48 8FB40020 */  lw        $s4, 0x20($sp)
/* A3A42C 80240F4C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A3A430 80240F50 8FB20018 */  lw        $s2, 0x18($sp)
/* A3A434 80240F54 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A438 80240F58 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A43C 80240F5C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* A3A440 80240F60 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* A3A444 80240F64 D7B80038 */  ldc1      $f24, 0x38($sp)
/* A3A448 80240F68 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A3A44C 80240F6C D7B40028 */  ldc1      $f20, 0x28($sp)
/* A3A450 80240F70 24020002 */  addiu     $v0, $zero, 2
/* A3A454 80240F74 03E00008 */  jr        $ra
/* A3A458 80240F78 27BD0050 */   addiu    $sp, $sp, 0x50
