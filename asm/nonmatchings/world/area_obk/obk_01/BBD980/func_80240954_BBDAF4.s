.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240954_BBDAF4
/* BBDAF4 80240954 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BBDAF8 80240958 AFB10014 */  sw        $s1, 0x14($sp)
/* BBDAFC 8024095C 0080882D */  daddu     $s1, $a0, $zero
/* BBDB00 80240960 AFBF0024 */  sw        $ra, 0x24($sp)
/* BBDB04 80240964 AFB40020 */  sw        $s4, 0x20($sp)
/* BBDB08 80240968 AFB3001C */  sw        $s3, 0x1c($sp)
/* BBDB0C 8024096C AFB20018 */  sw        $s2, 0x18($sp)
/* BBDB10 80240970 AFB00010 */  sw        $s0, 0x10($sp)
/* BBDB14 80240974 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* BBDB18 80240978 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* BBDB1C 8024097C F7B80038 */  sdc1      $f24, 0x38($sp)
/* BBDB20 80240980 F7B60030 */  sdc1      $f22, 0x30($sp)
/* BBDB24 80240984 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BBDB28 80240988 8E30000C */  lw        $s0, 0xc($s1)
/* BBDB2C 8024098C 8E130000 */  lw        $s3, ($s0)
/* BBDB30 80240990 26100004 */  addiu     $s0, $s0, 4
/* BBDB34 80240994 0C0B1EAF */  jal       get_variable
/* BBDB38 80240998 0260282D */   daddu    $a1, $s3, $zero
/* BBDB3C 8024099C 4482E000 */  mtc1      $v0, $f28
/* BBDB40 802409A0 00000000 */  nop       
/* BBDB44 802409A4 4680E720 */  cvt.s.w   $f28, $f28
/* BBDB48 802409A8 8E140000 */  lw        $s4, ($s0)
/* BBDB4C 802409AC 26100004 */  addiu     $s0, $s0, 4
/* BBDB50 802409B0 0220202D */  daddu     $a0, $s1, $zero
/* BBDB54 802409B4 0C0B1EAF */  jal       get_variable
/* BBDB58 802409B8 0280282D */   daddu    $a1, $s4, $zero
/* BBDB5C 802409BC 4482D000 */  mtc1      $v0, $f26
/* BBDB60 802409C0 00000000 */  nop       
/* BBDB64 802409C4 4680D6A0 */  cvt.s.w   $f26, $f26
/* BBDB68 802409C8 8E100000 */  lw        $s0, ($s0)
/* BBDB6C 802409CC 0220202D */  daddu     $a0, $s1, $zero
/* BBDB70 802409D0 0C0B1EAF */  jal       get_variable
/* BBDB74 802409D4 0200282D */   daddu    $a1, $s0, $zero
/* BBDB78 802409D8 4482C000 */  mtc1      $v0, $f24
/* BBDB7C 802409DC 00000000 */  nop       
/* BBDB80 802409E0 4680C620 */  cvt.s.w   $f24, $f24
/* BBDB84 802409E4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* BBDB88 802409E8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* BBDB8C 802409EC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BBDB90 802409F0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BBDB94 802409F4 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* BBDB98 802409F8 44800000 */  mtc1      $zero, $f0
/* BBDB9C 802409FC 00031080 */  sll       $v0, $v1, 2
/* BBDBA0 80240A00 00431021 */  addu      $v0, $v0, $v1
/* BBDBA4 80240A04 00021080 */  sll       $v0, $v0, 2
/* BBDBA8 80240A08 00431023 */  subu      $v0, $v0, $v1
/* BBDBAC 80240A0C 000218C0 */  sll       $v1, $v0, 3
/* BBDBB0 80240A10 00431021 */  addu      $v0, $v0, $v1
/* BBDBB4 80240A14 000210C0 */  sll       $v0, $v0, 3
/* BBDBB8 80240A18 46001032 */  c.eq.s    $f2, $f0
/* BBDBBC 80240A1C 3C01800B */  lui       $at, 0x800b
/* BBDBC0 80240A20 00220821 */  addu      $at, $at, $v0
/* BBDBC4 80240A24 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* BBDBC8 80240A28 45000005 */  bc1f      .L80240A40
/* BBDBCC 80240A2C 00000000 */   nop      
/* BBDBD0 80240A30 3C0142C8 */  lui       $at, 0x42c8
/* BBDBD4 80240A34 44810000 */  mtc1      $at, $f0
/* BBDBD8 80240A38 08090294 */  j         .L80240A50
/* BBDBDC 80240A3C 4600B581 */   sub.s    $f22, $f22, $f0
.L80240A40:
/* BBDBE0 80240A40 3C0142C8 */  lui       $at, 0x42c8
/* BBDBE4 80240A44 44810000 */  mtc1      $at, $f0
/* BBDBE8 80240A48 00000000 */  nop       
/* BBDBEC 80240A4C 4600B580 */  add.s     $f22, $f22, $f0
.L80240A50:
/* BBDBF0 80240A50 0C00A6C9 */  jal       clamp_angle
/* BBDBF4 80240A54 4600B306 */   mov.s    $f12, $f22
/* BBDBF8 80240A58 46000586 */  mov.s     $f22, $f0
/* BBDBFC 80240A5C 3C014170 */  lui       $at, 0x4170
/* BBDC00 80240A60 4481A000 */  mtc1      $at, $f20
/* BBDC04 80240A64 0C00A8BB */  jal       sin_deg
/* BBDC08 80240A68 4600B306 */   mov.s    $f12, $f22
/* BBDC0C 80240A6C 46140002 */  mul.s     $f0, $f0, $f20
/* BBDC10 80240A70 00000000 */  nop       
/* BBDC14 80240A74 864200B0 */  lh        $v0, 0xb0($s2)
/* BBDC18 80240A78 3C013F00 */  lui       $at, 0x3f00
/* BBDC1C 80240A7C 44812000 */  mtc1      $at, $f4
/* BBDC20 80240A80 44821000 */  mtc1      $v0, $f2
/* BBDC24 80240A84 00000000 */  nop       
/* BBDC28 80240A88 468010A0 */  cvt.s.w   $f2, $f2
/* BBDC2C 80240A8C 46041082 */  mul.s     $f2, $f2, $f4
/* BBDC30 80240A90 00000000 */  nop       
/* BBDC34 80240A94 4600E700 */  add.s     $f28, $f28, $f0
/* BBDC38 80240A98 4602D680 */  add.s     $f26, $f26, $f2
/* BBDC3C 80240A9C 0C00A8D4 */  jal       cos_deg
/* BBDC40 80240AA0 4600B306 */   mov.s    $f12, $f22
/* BBDC44 80240AA4 46140002 */  mul.s     $f0, $f0, $f20
/* BBDC48 80240AA8 00000000 */  nop       
/* BBDC4C 80240AAC 0220202D */  daddu     $a0, $s1, $zero
/* BBDC50 80240AB0 0260282D */  daddu     $a1, $s3, $zero
/* BBDC54 80240AB4 4600E18D */  trunc.w.s $f6, $f28
/* BBDC58 80240AB8 44063000 */  mfc1      $a2, $f6
/* BBDC5C 80240ABC 0C0B2026 */  jal       set_variable
/* BBDC60 80240AC0 4600C601 */   sub.s    $f24, $f24, $f0
/* BBDC64 80240AC4 0220202D */  daddu     $a0, $s1, $zero
/* BBDC68 80240AC8 4600D18D */  trunc.w.s $f6, $f26
/* BBDC6C 80240ACC 44063000 */  mfc1      $a2, $f6
/* BBDC70 80240AD0 0C0B2026 */  jal       set_variable
/* BBDC74 80240AD4 0280282D */   daddu    $a1, $s4, $zero
/* BBDC78 80240AD8 0220202D */  daddu     $a0, $s1, $zero
/* BBDC7C 80240ADC 4600C18D */  trunc.w.s $f6, $f24
/* BBDC80 80240AE0 44063000 */  mfc1      $a2, $f6
/* BBDC84 80240AE4 0C0B2026 */  jal       set_variable
/* BBDC88 80240AE8 0200282D */   daddu    $a1, $s0, $zero
/* BBDC8C 80240AEC 8FBF0024 */  lw        $ra, 0x24($sp)
/* BBDC90 80240AF0 8FB40020 */  lw        $s4, 0x20($sp)
/* BBDC94 80240AF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* BBDC98 80240AF8 8FB20018 */  lw        $s2, 0x18($sp)
/* BBDC9C 80240AFC 8FB10014 */  lw        $s1, 0x14($sp)
/* BBDCA0 80240B00 8FB00010 */  lw        $s0, 0x10($sp)
/* BBDCA4 80240B04 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* BBDCA8 80240B08 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* BBDCAC 80240B0C D7B80038 */  ldc1      $f24, 0x38($sp)
/* BBDCB0 80240B10 D7B60030 */  ldc1      $f22, 0x30($sp)
/* BBDCB4 80240B14 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BBDCB8 80240B18 24020002 */  addiu     $v0, $zero, 2
/* BBDCBC 80240B1C 03E00008 */  jr        $ra
/* BBDCC0 80240B20 27BD0050 */   addiu    $sp, $sp, 0x50
