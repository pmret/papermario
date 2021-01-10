.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D0_C4FDE0
/* C4FDE0 802408D0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C4FDE4 802408D4 AFB50024 */  sw        $s5, 0x24($sp)
/* C4FDE8 802408D8 0080A82D */  daddu     $s5, $a0, $zero
/* C4FDEC 802408DC AFBF002C */  sw        $ra, 0x2c($sp)
/* C4FDF0 802408E0 AFB60028 */  sw        $s6, 0x28($sp)
/* C4FDF4 802408E4 AFB40020 */  sw        $s4, 0x20($sp)
/* C4FDF8 802408E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* C4FDFC 802408EC AFB20018 */  sw        $s2, 0x18($sp)
/* C4FE00 802408F0 AFB10014 */  sw        $s1, 0x14($sp)
/* C4FE04 802408F4 AFB00010 */  sw        $s0, 0x10($sp)
/* C4FE08 802408F8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* C4FE0C 802408FC F7B60038 */  sdc1      $f22, 0x38($sp)
/* C4FE10 80240900 F7B40030 */  sdc1      $f20, 0x30($sp)
/* C4FE14 80240904 8EB30148 */  lw        $s3, 0x148($s5)
/* C4FE18 80240908 86640008 */  lh        $a0, 8($s3)
/* C4FE1C 8024090C 0C00EABB */  jal       get_npc_unsafe
/* C4FE20 80240910 00A0B02D */   daddu    $s6, $a1, $zero
/* C4FE24 80240914 0040A02D */  daddu     $s4, $v0, $zero
/* C4FE28 80240918 AEA00074 */  sw        $zero, 0x74($s5)
/* C4FE2C 8024091C C6980038 */  lwc1      $f24, 0x38($s4)
/* C4FE30 80240920 C6960040 */  lwc1      $f22, 0x40($s4)
/* C4FE34 80240924 0000902D */  daddu     $s2, $zero, $zero
/* C4FE38 80240928 AEA00078 */  sw        $zero, 0x78($s5)
/* C4FE3C 8024092C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* C4FE40 80240930 8C620000 */  lw        $v0, ($v1)
/* C4FE44 80240934 3C0146FF */  lui       $at, 0x46ff
/* C4FE48 80240938 3421FE00 */  ori       $at, $at, 0xfe00
/* C4FE4C 8024093C 4481A000 */  mtc1      $at, $f20
/* C4FE50 80240940 18400018 */  blez      $v0, .L802409A4
/* C4FE54 80240944 0240802D */   daddu    $s0, $s2, $zero
/* C4FE58 80240948 0240882D */  daddu     $s1, $s2, $zero
.L8024094C:
/* C4FE5C 8024094C 02231021 */  addu      $v0, $s1, $v1
/* C4FE60 80240950 4600C306 */  mov.s     $f12, $f24
/* C4FE64 80240954 C4440004 */  lwc1      $f4, 4($v0)
/* C4FE68 80240958 46802120 */  cvt.s.w   $f4, $f4
/* C4FE6C 8024095C 44062000 */  mfc1      $a2, $f4
/* C4FE70 80240960 C444000C */  lwc1      $f4, 0xc($v0)
/* C4FE74 80240964 46802120 */  cvt.s.w   $f4, $f4
/* C4FE78 80240968 44072000 */  mfc1      $a3, $f4
/* C4FE7C 8024096C 0C00A7B5 */  jal       dist2D
/* C4FE80 80240970 4600B386 */   mov.s    $f14, $f22
/* C4FE84 80240974 4614003C */  c.lt.s    $f0, $f20
/* C4FE88 80240978 00000000 */  nop       
/* C4FE8C 8024097C 45000003 */  bc1f      .L8024098C
/* C4FE90 80240980 2631000C */   addiu    $s1, $s1, 0xc
/* C4FE94 80240984 46000506 */  mov.s     $f20, $f0
/* C4FE98 80240988 AEB20078 */  sw        $s2, 0x78($s5)
.L8024098C:
/* C4FE9C 8024098C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* C4FEA0 80240990 26100001 */  addiu     $s0, $s0, 1
/* C4FEA4 80240994 8C620000 */  lw        $v0, ($v1)
/* C4FEA8 80240998 0202102A */  slt       $v0, $s0, $v0
/* C4FEAC 8024099C 1440FFEB */  bnez      $v0, .L8024094C
/* C4FEB0 802409A0 26520001 */   addiu    $s2, $s2, 1
.L802409A4:
/* C4FEB4 802409A4 8E6200CC */  lw        $v0, 0xcc($s3)
/* C4FEB8 802409A8 8C420004 */  lw        $v0, 4($v0)
/* C4FEBC 802409AC AE820028 */  sw        $v0, 0x28($s4)
/* C4FEC0 802409B0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* C4FEC4 802409B4 8C42007C */  lw        $v0, 0x7c($v0)
/* C4FEC8 802409B8 04410004 */  bgez      $v0, .L802409CC
/* C4FECC 802409BC 00000000 */   nop      
/* C4FED0 802409C0 C6C00000 */  lwc1      $f0, ($s6)
/* C4FED4 802409C4 0809027B */  j         .L802409EC
/* C4FED8 802409C8 E6800018 */   swc1     $f0, 0x18($s4)
.L802409CC:
/* C4FEDC 802409CC 3C018024 */  lui       $at, %hi(func_80242E88_95E088)
/* C4FEE0 802409D0 D4222E88 */  ldc1      $f2, %lo(func_80242E88_95E088)($at)
/* C4FEE4 802409D4 44820000 */  mtc1      $v0, $f0
/* C4FEE8 802409D8 00000000 */  nop       
/* C4FEEC 802409DC 46800021 */  cvt.d.w   $f0, $f0
/* C4FEF0 802409E0 46220003 */  div.d     $f0, $f0, $f2
/* C4FEF4 802409E4 46200020 */  cvt.s.d   $f0, $f0
/* C4FEF8 802409E8 E6800018 */  swc1      $f0, 0x18($s4)
.L802409EC:
/* C4FEFC 802409EC 24020001 */  addiu     $v0, $zero, 1
/* C4FF00 802409F0 AEA20070 */  sw        $v0, 0x70($s5)
/* C4FF04 802409F4 8FBF002C */  lw        $ra, 0x2c($sp)
/* C4FF08 802409F8 8FB60028 */  lw        $s6, 0x28($sp)
/* C4FF0C 802409FC 8FB50024 */  lw        $s5, 0x24($sp)
/* C4FF10 80240A00 8FB40020 */  lw        $s4, 0x20($sp)
/* C4FF14 80240A04 8FB3001C */  lw        $s3, 0x1c($sp)
/* C4FF18 80240A08 8FB20018 */  lw        $s2, 0x18($sp)
/* C4FF1C 80240A0C 8FB10014 */  lw        $s1, 0x14($sp)
/* C4FF20 80240A10 8FB00010 */  lw        $s0, 0x10($sp)
/* C4FF24 80240A14 D7B80040 */  ldc1      $f24, 0x40($sp)
/* C4FF28 80240A18 D7B60038 */  ldc1      $f22, 0x38($sp)
/* C4FF2C 80240A1C D7B40030 */  ldc1      $f20, 0x30($sp)
/* C4FF30 80240A20 03E00008 */  jr        $ra
/* C4FF34 80240A24 27BD0048 */   addiu    $sp, $sp, 0x48
