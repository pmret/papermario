.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245F30_AD4070
.double 90.0

glabel D_80245F38_AD4078
.double 270.0

.section .text

glabel func_802408A0_ACE9E0
/* ACE9E0 802408A0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* ACE9E4 802408A4 AFB3003C */  sw        $s3, 0x3c($sp)
/* ACE9E8 802408A8 0080982D */  daddu     $s3, $a0, $zero
/* ACE9EC 802408AC AFBF0044 */  sw        $ra, 0x44($sp)
/* ACE9F0 802408B0 AFB40040 */  sw        $s4, 0x40($sp)
/* ACE9F4 802408B4 AFB20038 */  sw        $s2, 0x38($sp)
/* ACE9F8 802408B8 AFB10034 */  sw        $s1, 0x34($sp)
/* ACE9FC 802408BC AFB00030 */  sw        $s0, 0x30($sp)
/* ACEA00 802408C0 F7B80058 */  sdc1      $f24, 0x58($sp)
/* ACEA04 802408C4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* ACEA08 802408C8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* ACEA0C 802408CC 8E620148 */  lw        $v0, 0x148($s3)
/* ACEA10 802408D0 0C00EABB */  jal       get_npc_unsafe
/* ACEA14 802408D4 84440008 */   lh       $a0, 8($v0)
/* ACEA18 802408D8 27A40020 */  addiu     $a0, $sp, 0x20
/* ACEA1C 802408DC 27A50024 */  addiu     $a1, $sp, 0x24
/* ACEA20 802408E0 0040802D */  daddu     $s0, $v0, $zero
/* ACEA24 802408E4 8E63000C */  lw        $v1, 0xc($s3)
/* ACEA28 802408E8 8E07000C */  lw        $a3, 0xc($s0)
/* ACEA2C 802408EC C6000038 */  lwc1      $f0, 0x38($s0)
/* ACEA30 802408F0 C6020040 */  lwc1      $f2, 0x40($s0)
/* ACEA34 802408F4 8C740000 */  lw        $s4, ($v1)
/* ACEA38 802408F8 24630004 */  addiu     $v1, $v1, 4
/* ACEA3C 802408FC C4780000 */  lwc1      $f24, ($v1)
/* ACEA40 80240900 4680C620 */  cvt.s.w   $f24, $f24
/* ACEA44 80240904 24630004 */  addiu     $v1, $v1, 4
/* ACEA48 80240908 C4740000 */  lwc1      $f20, ($v1)
/* ACEA4C 8024090C 4680A520 */  cvt.s.w   $f20, $f20
/* ACEA50 80240910 4406A000 */  mfc1      $a2, $f20
/* ACEA54 80240914 C4760004 */  lwc1      $f22, 4($v1)
/* ACEA58 80240918 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACEA5C 8024091C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACEA60 80240920 0C00A7E7 */  jal       add_vec2D_polar
/* ACEA64 80240924 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACEA68 80240928 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACEA6C 8024092C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACEA70 80240930 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACEA74 80240934 4480A000 */  mtc1      $zero, $f20
/* ACEA78 80240938 8E460028 */  lw        $a2, 0x28($s2)
/* ACEA7C 8024093C 4407A000 */  mfc1      $a3, $f20
/* ACEA80 80240940 0C00A7B5 */  jal       dist2D
/* ACEA84 80240944 4600A386 */   mov.s    $f14, $f20
/* ACEA88 80240948 4600A306 */  mov.s     $f12, $f20
/* ACEA8C 8024094C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACEA90 80240950 44066000 */  mfc1      $a2, $f12
/* ACEA94 80240954 8E470030 */  lw        $a3, 0x30($s2)
/* ACEA98 80240958 0C00A7B5 */  jal       dist2D
/* ACEA9C 8024095C 46000506 */   mov.s    $f20, $f0
/* ACEAA0 80240960 C604000C */  lwc1      $f4, 0xc($s0)
/* ACEAA4 80240964 3C018024 */  lui       $at, %hi(D_80245F30_AD4070)
/* ACEAA8 80240968 D4225F30 */  ldc1      $f2, %lo(D_80245F30_AD4070)($at)
/* ACEAAC 8024096C 46002121 */  cvt.d.s   $f4, $f4
/* ACEAB0 80240970 46222032 */  c.eq.d    $f4, $f2
/* ACEAB4 80240974 00000000 */  nop
/* ACEAB8 80240978 45010007 */  bc1t      .L80240998
/* ACEABC 8024097C 46000086 */   mov.s    $f2, $f0
/* ACEAC0 80240980 3C018024 */  lui       $at, %hi(D_80245F38_AD4078)
/* ACEAC4 80240984 D4205F38 */  ldc1      $f0, %lo(D_80245F38_AD4078)($at)
/* ACEAC8 80240988 46202032 */  c.eq.d    $f4, $f0
/* ACEACC 8024098C 00000000 */  nop
/* ACEAD0 80240990 45000008 */  bc1f      .L802409B4
/* ACEAD4 80240994 00000000 */   nop
.L80240998:
/* ACEAD8 80240998 4618A03E */  c.le.s    $f20, $f24
/* ACEADC 8024099C 00000000 */  nop
/* ACEAE0 802409A0 4500000C */  bc1f      .L802409D4
/* ACEAE4 802409A4 0000882D */   daddu    $s1, $zero, $zero
/* ACEAE8 802409A8 4616103E */  c.le.s    $f2, $f22
/* ACEAEC 802409AC 08090273 */  j         .L802409CC
/* ACEAF0 802409B0 00000000 */   nop
.L802409B4:
/* ACEAF4 802409B4 4618103E */  c.le.s    $f2, $f24
/* ACEAF8 802409B8 00000000 */  nop
/* ACEAFC 802409BC 45000005 */  bc1f      .L802409D4
/* ACEB00 802409C0 0000882D */   daddu    $s1, $zero, $zero
/* ACEB04 802409C4 4616A03E */  c.le.s    $f20, $f22
/* ACEB08 802409C8 00000000 */  nop
.L802409CC:
/* ACEB0C 802409CC 45030001 */  bc1tl     .L802409D4
/* ACEB10 802409D0 24110001 */   addiu    $s1, $zero, 1
.L802409D4:
/* ACEB14 802409D4 12200027 */  beqz      $s1, .L80240A74
/* ACEB18 802409D8 0260202D */   daddu    $a0, $s3, $zero
/* ACEB1C 802409DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACEB20 802409E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACEB24 802409E4 8E460028 */  lw        $a2, 0x28($s2)
/* ACEB28 802409E8 8E470030 */  lw        $a3, 0x30($s2)
/* ACEB2C 802409EC C602003C */  lwc1      $f2, 0x3c($s0)
/* ACEB30 802409F0 46006006 */  mov.s     $f0, $f12
/* ACEB34 802409F4 46007106 */  mov.s     $f4, $f14
/* ACEB38 802409F8 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACEB3C 802409FC E7A20028 */  swc1      $f2, 0x28($sp)
/* ACEB40 80240A00 0C00A7B5 */  jal       dist2D
/* ACEB44 80240A04 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACEB48 80240A08 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACEB4C 80240A0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACEB50 80240A10 8E460028 */  lw        $a2, 0x28($s2)
/* ACEB54 80240A14 8E470030 */  lw        $a3, 0x30($s2)
/* ACEB58 80240A18 0C00A720 */  jal       atan2
/* ACEB5C 80240A1C 46000506 */   mov.s    $f20, $f0
/* ACEB60 80240A20 3C040007 */  lui       $a0, 7
/* ACEB64 80240A24 34848000 */  ori       $a0, $a0, 0x8000
/* ACEB68 80240A28 27A50020 */  addiu     $a1, $sp, 0x20
/* ACEB6C 80240A2C E7B40010 */  swc1      $f20, 0x10($sp)
/* ACEB70 80240A30 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACEB74 80240A34 860200A6 */  lh        $v0, 0xa6($s0)
/* ACEB78 80240A38 27A60028 */  addiu     $a2, $sp, 0x28
/* ACEB7C 80240A3C 44820000 */  mtc1      $v0, $f0
/* ACEB80 80240A40 00000000 */  nop
/* ACEB84 80240A44 46800020 */  cvt.s.w   $f0, $f0
/* ACEB88 80240A48 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACEB8C 80240A4C 860200A8 */  lh        $v0, 0xa8($s0)
/* ACEB90 80240A50 27A70024 */  addiu     $a3, $sp, 0x24
/* ACEB94 80240A54 44820000 */  mtc1      $v0, $f0
/* ACEB98 80240A58 00000000 */  nop
/* ACEB9C 80240A5C 46800020 */  cvt.s.w   $f0, $f0
/* ACEBA0 80240A60 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACEBA4 80240A64 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACEBA8 80240A68 54400001 */  bnel      $v0, $zero, .L80240A70
/* ACEBAC 80240A6C 0000882D */   daddu    $s1, $zero, $zero
.L80240A70:
/* ACEBB0 80240A70 0260202D */  daddu     $a0, $s3, $zero
.L80240A74:
/* ACEBB4 80240A74 0280282D */  daddu     $a1, $s4, $zero
/* ACEBB8 80240A78 0C0B2026 */  jal       set_variable
/* ACEBBC 80240A7C 0220302D */   daddu    $a2, $s1, $zero
/* ACEBC0 80240A80 8FBF0044 */  lw        $ra, 0x44($sp)
/* ACEBC4 80240A84 8FB40040 */  lw        $s4, 0x40($sp)
/* ACEBC8 80240A88 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACEBCC 80240A8C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACEBD0 80240A90 8FB10034 */  lw        $s1, 0x34($sp)
/* ACEBD4 80240A94 8FB00030 */  lw        $s0, 0x30($sp)
/* ACEBD8 80240A98 D7B80058 */  ldc1      $f24, 0x58($sp)
/* ACEBDC 80240A9C D7B60050 */  ldc1      $f22, 0x50($sp)
/* ACEBE0 80240AA0 D7B40048 */  ldc1      $f20, 0x48($sp)
/* ACEBE4 80240AA4 24020002 */  addiu     $v0, $zero, 2
/* ACEBE8 80240AA8 03E00008 */  jr        $ra
/* ACEBEC 80240AAC 27BD0060 */   addiu    $sp, $sp, 0x60
