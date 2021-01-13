.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F4C_DCDC1C
/* DCDC1C 80240F4C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DCDC20 80240F50 AFB50024 */  sw        $s5, 0x24($sp)
/* DCDC24 80240F54 0080A82D */  daddu     $s5, $a0, $zero
/* DCDC28 80240F58 AFBF002C */  sw        $ra, 0x2c($sp)
/* DCDC2C 80240F5C AFB60028 */  sw        $s6, 0x28($sp)
/* DCDC30 80240F60 AFB40020 */  sw        $s4, 0x20($sp)
/* DCDC34 80240F64 AFB3001C */  sw        $s3, 0x1c($sp)
/* DCDC38 80240F68 AFB20018 */  sw        $s2, 0x18($sp)
/* DCDC3C 80240F6C AFB10014 */  sw        $s1, 0x14($sp)
/* DCDC40 80240F70 AFB00010 */  sw        $s0, 0x10($sp)
/* DCDC44 80240F74 F7B80040 */  sdc1      $f24, 0x40($sp)
/* DCDC48 80240F78 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DCDC4C 80240F7C F7B40030 */  sdc1      $f20, 0x30($sp)
/* DCDC50 80240F80 8EB30148 */  lw        $s3, 0x148($s5)
/* DCDC54 80240F84 86640008 */  lh        $a0, 8($s3)
/* DCDC58 80240F88 0C00EABB */  jal       get_npc_unsafe
/* DCDC5C 80240F8C 00A0B02D */   daddu    $s6, $a1, $zero
/* DCDC60 80240F90 0040A02D */  daddu     $s4, $v0, $zero
/* DCDC64 80240F94 AEA00074 */  sw        $zero, 0x74($s5)
/* DCDC68 80240F98 C6980038 */  lwc1      $f24, 0x38($s4)
/* DCDC6C 80240F9C C6960040 */  lwc1      $f22, 0x40($s4)
/* DCDC70 80240FA0 0000902D */  daddu     $s2, $zero, $zero
/* DCDC74 80240FA4 AEA00078 */  sw        $zero, 0x78($s5)
/* DCDC78 80240FA8 8E6300D0 */  lw        $v1, 0xd0($s3)
/* DCDC7C 80240FAC 8C620000 */  lw        $v0, ($v1)
/* DCDC80 80240FB0 3C0146FF */  lui       $at, 0x46ff
/* DCDC84 80240FB4 3421FE00 */  ori       $at, $at, 0xfe00
/* DCDC88 80240FB8 4481A000 */  mtc1      $at, $f20
/* DCDC8C 80240FBC 18400018 */  blez      $v0, .L80241020
/* DCDC90 80240FC0 0240802D */   daddu    $s0, $s2, $zero
/* DCDC94 80240FC4 0240882D */  daddu     $s1, $s2, $zero
.L80240FC8:
/* DCDC98 80240FC8 02231021 */  addu      $v0, $s1, $v1
/* DCDC9C 80240FCC 4600C306 */  mov.s     $f12, $f24
/* DCDCA0 80240FD0 C4440004 */  lwc1      $f4, 4($v0)
/* DCDCA4 80240FD4 46802120 */  cvt.s.w   $f4, $f4
/* DCDCA8 80240FD8 44062000 */  mfc1      $a2, $f4
/* DCDCAC 80240FDC C444000C */  lwc1      $f4, 0xc($v0)
/* DCDCB0 80240FE0 46802120 */  cvt.s.w   $f4, $f4
/* DCDCB4 80240FE4 44072000 */  mfc1      $a3, $f4
/* DCDCB8 80240FE8 0C00A7B5 */  jal       dist2D
/* DCDCBC 80240FEC 4600B386 */   mov.s    $f14, $f22
/* DCDCC0 80240FF0 4614003C */  c.lt.s    $f0, $f20
/* DCDCC4 80240FF4 00000000 */  nop
/* DCDCC8 80240FF8 45000003 */  bc1f      .L80241008
/* DCDCCC 80240FFC 2631000C */   addiu    $s1, $s1, 0xc
/* DCDCD0 80241000 46000506 */  mov.s     $f20, $f0
/* DCDCD4 80241004 AEB20078 */  sw        $s2, 0x78($s5)
.L80241008:
/* DCDCD8 80241008 8E6300D0 */  lw        $v1, 0xd0($s3)
/* DCDCDC 8024100C 26100001 */  addiu     $s0, $s0, 1
/* DCDCE0 80241010 8C620000 */  lw        $v0, ($v1)
/* DCDCE4 80241014 0202102A */  slt       $v0, $s0, $v0
/* DCDCE8 80241018 1440FFEB */  bnez      $v0, .L80240FC8
/* DCDCEC 8024101C 26520001 */   addiu    $s2, $s2, 1
.L80241020:
/* DCDCF0 80241020 8E6200CC */  lw        $v0, 0xcc($s3)
/* DCDCF4 80241024 8C420004 */  lw        $v0, 4($v0)
/* DCDCF8 80241028 AE820028 */  sw        $v0, 0x28($s4)
/* DCDCFC 8024102C 8E6200D0 */  lw        $v0, 0xd0($s3)
/* DCDD00 80241030 8C42007C */  lw        $v0, 0x7c($v0)
/* DCDD04 80241034 04410004 */  bgez      $v0, .L80241048
/* DCDD08 80241038 00000000 */   nop
/* DCDD0C 8024103C C6C00000 */  lwc1      $f0, ($s6)
/* DCDD10 80241040 0809041A */  j         .L80241068
/* DCDD14 80241044 E6800018 */   swc1     $f0, 0x18($s4)
.L80241048:
/* DCDD18 80241048 3C018025 */  lui       $at, %hi(D_8024A7D0)
/* DCDD1C 8024104C D422A7D0 */  ldc1      $f2, %lo(D_8024A7D0)($at)
/* DCDD20 80241050 44820000 */  mtc1      $v0, $f0
/* DCDD24 80241054 00000000 */  nop
/* DCDD28 80241058 46800021 */  cvt.d.w   $f0, $f0
/* DCDD2C 8024105C 46220003 */  div.d     $f0, $f0, $f2
/* DCDD30 80241060 46200020 */  cvt.s.d   $f0, $f0
/* DCDD34 80241064 E6800018 */  swc1      $f0, 0x18($s4)
.L80241068:
/* DCDD38 80241068 24020001 */  addiu     $v0, $zero, 1
/* DCDD3C 8024106C AEA20070 */  sw        $v0, 0x70($s5)
/* DCDD40 80241070 8FBF002C */  lw        $ra, 0x2c($sp)
/* DCDD44 80241074 8FB60028 */  lw        $s6, 0x28($sp)
/* DCDD48 80241078 8FB50024 */  lw        $s5, 0x24($sp)
/* DCDD4C 8024107C 8FB40020 */  lw        $s4, 0x20($sp)
/* DCDD50 80241080 8FB3001C */  lw        $s3, 0x1c($sp)
/* DCDD54 80241084 8FB20018 */  lw        $s2, 0x18($sp)
/* DCDD58 80241088 8FB10014 */  lw        $s1, 0x14($sp)
/* DCDD5C 8024108C 8FB00010 */  lw        $s0, 0x10($sp)
/* DCDD60 80241090 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DCDD64 80241094 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DCDD68 80241098 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DCDD6C 8024109C 03E00008 */  jr        $ra
/* DCDD70 802410A0 27BD0048 */   addiu    $sp, $sp, 0x48
