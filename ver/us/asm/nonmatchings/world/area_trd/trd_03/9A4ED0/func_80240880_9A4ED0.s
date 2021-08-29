.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240880_9A4ED0
/* 9A4ED0 80240880 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9A4ED4 80240884 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A4ED8 80240888 0080882D */  daddu     $s1, $a0, $zero
/* 9A4EDC 8024088C AFBF0020 */  sw        $ra, 0x20($sp)
/* 9A4EE0 80240890 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9A4EE4 80240894 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A4EE8 80240898 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A4EEC 8024089C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 9A4EF0 802408A0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 9A4EF4 802408A4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 9A4EF8 802408A8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 9A4EFC 802408AC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 9A4F00 802408B0 8E30000C */  lw        $s0, 0xc($s1)
/* 9A4F04 802408B4 8E050000 */  lw        $a1, ($s0)
/* 9A4F08 802408B8 0C0B1EAF */  jal       evt_get_variable
/* 9A4F0C 802408BC 26100004 */   addiu    $s0, $s0, 4
/* 9A4F10 802408C0 8E050000 */  lw        $a1, ($s0)
/* 9A4F14 802408C4 26100004 */  addiu     $s0, $s0, 4
/* 9A4F18 802408C8 0220202D */  daddu     $a0, $s1, $zero
/* 9A4F1C 802408CC 0C0B1EAF */  jal       evt_get_variable
/* 9A4F20 802408D0 0040902D */   daddu    $s2, $v0, $zero
/* 9A4F24 802408D4 0220202D */  daddu     $a0, $s1, $zero
/* 9A4F28 802408D8 8E050000 */  lw        $a1, ($s0)
/* 9A4F2C 802408DC 0C0B1EAF */  jal       evt_get_variable
/* 9A4F30 802408E0 0040982D */   daddu    $s3, $v0, $zero
/* 9A4F34 802408E4 3C10800B */  lui       $s0, %hi(gCameras)
/* 9A4F38 802408E8 26101D80 */  addiu     $s0, $s0, %lo(gCameras)
/* 9A4F3C 802408EC C60C006C */  lwc1      $f12, 0x6c($s0)
/* 9A4F40 802408F0 3C014387 */  lui       $at, 0x4387
/* 9A4F44 802408F4 4481B000 */  mtc1      $at, $f22
/* 9A4F48 802408F8 00000000 */  nop
/* 9A4F4C 802408FC 46166300 */  add.s     $f12, $f12, $f22
/* 9A4F50 80240900 4482C000 */  mtc1      $v0, $f24
/* 9A4F54 80240904 00000000 */  nop
/* 9A4F58 80240908 4680C620 */  cvt.s.w   $f24, $f24
/* 9A4F5C 8024090C 3C0142C8 */  lui       $at, 0x42c8
/* 9A4F60 80240910 4481D000 */  mtc1      $at, $f26
/* 9A4F64 80240914 0C00A8BB */  jal       sin_deg
/* 9A4F68 80240918 46186300 */   add.s    $f12, $f12, $f24
/* 9A4F6C 8024091C 461A0002 */  mul.s     $f0, $f0, $f26
/* 9A4F70 80240920 00000000 */  nop
/* 9A4F74 80240924 4492A000 */  mtc1      $s2, $f20
/* 9A4F78 80240928 00000000 */  nop
/* 9A4F7C 8024092C 4680A520 */  cvt.s.w   $f20, $f20
/* 9A4F80 80240930 4600A000 */  add.s     $f0, $f20, $f0
/* 9A4F84 80240934 4600008D */  trunc.w.s $f2, $f0
/* 9A4F88 80240938 E6220084 */  swc1      $f2, 0x84($s1)
/* 9A4F8C 8024093C C60C006C */  lwc1      $f12, 0x6c($s0)
/* 9A4F90 80240940 46166300 */  add.s     $f12, $f12, $f22
/* 9A4F94 80240944 0C00A8D4 */  jal       cos_deg
/* 9A4F98 80240948 46186300 */   add.s    $f12, $f12, $f24
/* 9A4F9C 8024094C 461A0002 */  mul.s     $f0, $f0, $f26
/* 9A4FA0 80240950 00000000 */  nop
/* 9A4FA4 80240954 4493B000 */  mtc1      $s3, $f22
/* 9A4FA8 80240958 00000000 */  nop
/* 9A4FAC 8024095C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9A4FB0 80240960 4600B001 */  sub.s     $f0, $f22, $f0
/* 9A4FB4 80240964 3C0142B4 */  lui       $at, 0x42b4
/* 9A4FB8 80240968 4481E000 */  mtc1      $at, $f28
/* 9A4FBC 8024096C 4600008D */  trunc.w.s $f2, $f0
/* 9A4FC0 80240970 E6220088 */  swc1      $f2, 0x88($s1)
/* 9A4FC4 80240974 C60C006C */  lwc1      $f12, 0x6c($s0)
/* 9A4FC8 80240978 461C6300 */  add.s     $f12, $f12, $f28
/* 9A4FCC 8024097C 0C00A8BB */  jal       sin_deg
/* 9A4FD0 80240980 46186300 */   add.s    $f12, $f12, $f24
/* 9A4FD4 80240984 461A0002 */  mul.s     $f0, $f0, $f26
/* 9A4FD8 80240988 00000000 */  nop
/* 9A4FDC 8024098C 4600A500 */  add.s     $f20, $f20, $f0
/* 9A4FE0 80240990 4600A08D */  trunc.w.s $f2, $f20
/* 9A4FE4 80240994 E622008C */  swc1      $f2, 0x8c($s1)
/* 9A4FE8 80240998 C60C006C */  lwc1      $f12, 0x6c($s0)
/* 9A4FEC 8024099C 461C6300 */  add.s     $f12, $f12, $f28
/* 9A4FF0 802409A0 0C00A8D4 */  jal       cos_deg
/* 9A4FF4 802409A4 46186300 */   add.s    $f12, $f12, $f24
/* 9A4FF8 802409A8 461A0002 */  mul.s     $f0, $f0, $f26
/* 9A4FFC 802409AC 00000000 */  nop
/* 9A5000 802409B0 4600B581 */  sub.s     $f22, $f22, $f0
/* 9A5004 802409B4 4600B08D */  trunc.w.s $f2, $f22
/* 9A5008 802409B8 E6220090 */  swc1      $f2, 0x90($s1)
/* 9A500C 802409BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9A5010 802409C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9A5014 802409C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A5018 802409C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A501C 802409CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A5020 802409D0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 9A5024 802409D4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 9A5028 802409D8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 9A502C 802409DC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 9A5030 802409E0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 9A5034 802409E4 24020002 */  addiu     $v0, $zero, 2
/* 9A5038 802409E8 03E00008 */  jr        $ra
/* 9A503C 802409EC 27BD0050 */   addiu    $sp, $sp, 0x50
