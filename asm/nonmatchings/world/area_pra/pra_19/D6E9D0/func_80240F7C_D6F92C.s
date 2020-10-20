.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F7C_D6F92C
/* D6F92C 80240F7C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D6F930 80240F80 AFB10014 */  sw        $s1, 0x14($sp)
/* D6F934 80240F84 0080882D */  daddu     $s1, $a0, $zero
/* D6F938 80240F88 AFBF0024 */  sw        $ra, 0x24($sp)
/* D6F93C 80240F8C AFB40020 */  sw        $s4, 0x20($sp)
/* D6F940 80240F90 AFB3001C */  sw        $s3, 0x1c($sp)
/* D6F944 80240F94 AFB20018 */  sw        $s2, 0x18($sp)
/* D6F948 80240F98 AFB00010 */  sw        $s0, 0x10($sp)
/* D6F94C 80240F9C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D6F950 80240FA0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D6F954 80240FA4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* D6F958 80240FA8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D6F95C 80240FAC F7B40028 */  sdc1      $f20, 0x28($sp)
/* D6F960 80240FB0 8E30000C */  lw        $s0, 0xc($s1)
/* D6F964 80240FB4 8E130000 */  lw        $s3, ($s0)
/* D6F968 80240FB8 26100004 */  addiu     $s0, $s0, 4
/* D6F96C 80240FBC 0C0B1EAF */  jal       get_variable
/* D6F970 80240FC0 0260282D */   daddu    $a1, $s3, $zero
/* D6F974 80240FC4 4482E000 */  mtc1      $v0, $f28
/* D6F978 80240FC8 00000000 */  nop       
/* D6F97C 80240FCC 4680E720 */  cvt.s.w   $f28, $f28
/* D6F980 80240FD0 8E140000 */  lw        $s4, ($s0)
/* D6F984 80240FD4 26100004 */  addiu     $s0, $s0, 4
/* D6F988 80240FD8 0220202D */  daddu     $a0, $s1, $zero
/* D6F98C 80240FDC 0C0B1EAF */  jal       get_variable
/* D6F990 80240FE0 0280282D */   daddu    $a1, $s4, $zero
/* D6F994 80240FE4 4482D000 */  mtc1      $v0, $f26
/* D6F998 80240FE8 00000000 */  nop       
/* D6F99C 80240FEC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D6F9A0 80240FF0 8E100000 */  lw        $s0, ($s0)
/* D6F9A4 80240FF4 0220202D */  daddu     $a0, $s1, $zero
/* D6F9A8 80240FF8 0C0B1EAF */  jal       get_variable
/* D6F9AC 80240FFC 0200282D */   daddu    $a1, $s0, $zero
/* D6F9B0 80241000 4482C000 */  mtc1      $v0, $f24
/* D6F9B4 80241004 00000000 */  nop       
/* D6F9B8 80241008 4680C620 */  cvt.s.w   $f24, $f24
/* D6F9BC 8024100C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D6F9C0 80241010 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D6F9C4 80241014 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D6F9C8 80241018 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D6F9CC 8024101C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* D6F9D0 80241020 44800000 */  mtc1      $zero, $f0
/* D6F9D4 80241024 00031080 */  sll       $v0, $v1, 2
/* D6F9D8 80241028 00431021 */  addu      $v0, $v0, $v1
/* D6F9DC 8024102C 00021080 */  sll       $v0, $v0, 2
/* D6F9E0 80241030 00431023 */  subu      $v0, $v0, $v1
/* D6F9E4 80241034 000218C0 */  sll       $v1, $v0, 3
/* D6F9E8 80241038 00431021 */  addu      $v0, $v0, $v1
/* D6F9EC 8024103C 000210C0 */  sll       $v0, $v0, 3
/* D6F9F0 80241040 46001032 */  c.eq.s    $f2, $f0
/* D6F9F4 80241044 3C01800B */  lui       $at, 0x800b
/* D6F9F8 80241048 00220821 */  addu      $at, $at, $v0
/* D6F9FC 8024104C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D6FA00 80241050 45000005 */  bc1f      .L80241068
/* D6FA04 80241054 00000000 */   nop      
/* D6FA08 80241058 3C0142C8 */  lui       $at, 0x42c8
/* D6FA0C 8024105C 44810000 */  mtc1      $at, $f0
/* D6FA10 80241060 0809041E */  j         .L80241078
/* D6FA14 80241064 4600B581 */   sub.s    $f22, $f22, $f0
.L80241068:
/* D6FA18 80241068 3C0142C8 */  lui       $at, 0x42c8
/* D6FA1C 8024106C 44810000 */  mtc1      $at, $f0
/* D6FA20 80241070 00000000 */  nop       
/* D6FA24 80241074 4600B580 */  add.s     $f22, $f22, $f0
.L80241078:
/* D6FA28 80241078 0C00A6C9 */  jal       clamp_angle
/* D6FA2C 8024107C 4600B306 */   mov.s    $f12, $f22
/* D6FA30 80241080 46000586 */  mov.s     $f22, $f0
/* D6FA34 80241084 3C014170 */  lui       $at, 0x4170
/* D6FA38 80241088 4481A000 */  mtc1      $at, $f20
/* D6FA3C 8024108C 0C00A8BB */  jal       sin_deg
/* D6FA40 80241090 4600B306 */   mov.s    $f12, $f22
/* D6FA44 80241094 46140002 */  mul.s     $f0, $f0, $f20
/* D6FA48 80241098 00000000 */  nop       
/* D6FA4C 8024109C 864200B0 */  lh        $v0, 0xb0($s2)
/* D6FA50 802410A0 3C013F00 */  lui       $at, 0x3f00
/* D6FA54 802410A4 44812000 */  mtc1      $at, $f4
/* D6FA58 802410A8 44821000 */  mtc1      $v0, $f2
/* D6FA5C 802410AC 00000000 */  nop       
/* D6FA60 802410B0 468010A0 */  cvt.s.w   $f2, $f2
/* D6FA64 802410B4 46041082 */  mul.s     $f2, $f2, $f4
/* D6FA68 802410B8 00000000 */  nop       
/* D6FA6C 802410BC 4600E700 */  add.s     $f28, $f28, $f0
/* D6FA70 802410C0 4602D680 */  add.s     $f26, $f26, $f2
/* D6FA74 802410C4 0C00A8D4 */  jal       cos_deg
/* D6FA78 802410C8 4600B306 */   mov.s    $f12, $f22
/* D6FA7C 802410CC 46140002 */  mul.s     $f0, $f0, $f20
/* D6FA80 802410D0 00000000 */  nop       
/* D6FA84 802410D4 0220202D */  daddu     $a0, $s1, $zero
/* D6FA88 802410D8 0260282D */  daddu     $a1, $s3, $zero
/* D6FA8C 802410DC 4600E18D */  trunc.w.s $f6, $f28
/* D6FA90 802410E0 44063000 */  mfc1      $a2, $f6
/* D6FA94 802410E4 0C0B2026 */  jal       set_variable
/* D6FA98 802410E8 4600C601 */   sub.s    $f24, $f24, $f0
/* D6FA9C 802410EC 0220202D */  daddu     $a0, $s1, $zero
/* D6FAA0 802410F0 4600D18D */  trunc.w.s $f6, $f26
/* D6FAA4 802410F4 44063000 */  mfc1      $a2, $f6
/* D6FAA8 802410F8 0C0B2026 */  jal       set_variable
/* D6FAAC 802410FC 0280282D */   daddu    $a1, $s4, $zero
/* D6FAB0 80241100 0220202D */  daddu     $a0, $s1, $zero
/* D6FAB4 80241104 4600C18D */  trunc.w.s $f6, $f24
/* D6FAB8 80241108 44063000 */  mfc1      $a2, $f6
/* D6FABC 8024110C 0C0B2026 */  jal       set_variable
/* D6FAC0 80241110 0200282D */   daddu    $a1, $s0, $zero
/* D6FAC4 80241114 8FBF0024 */  lw        $ra, 0x24($sp)
/* D6FAC8 80241118 8FB40020 */  lw        $s4, 0x20($sp)
/* D6FACC 8024111C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D6FAD0 80241120 8FB20018 */  lw        $s2, 0x18($sp)
/* D6FAD4 80241124 8FB10014 */  lw        $s1, 0x14($sp)
/* D6FAD8 80241128 8FB00010 */  lw        $s0, 0x10($sp)
/* D6FADC 8024112C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D6FAE0 80241130 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D6FAE4 80241134 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D6FAE8 80241138 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D6FAEC 8024113C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D6FAF0 80241140 24020002 */  addiu     $v0, $zero, 2
/* D6FAF4 80241144 03E00008 */  jr        $ra
/* D6FAF8 80241148 27BD0050 */   addiu    $sp, $sp, 0x50
