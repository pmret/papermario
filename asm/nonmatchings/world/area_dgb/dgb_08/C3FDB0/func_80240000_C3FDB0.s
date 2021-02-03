.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C3FDB0
/* C3FDB0 80240000 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C3FDB4 80240004 AFB50024 */  sw        $s5, 0x24($sp)
/* C3FDB8 80240008 0080A82D */  daddu     $s5, $a0, $zero
/* C3FDBC 8024000C AFBF002C */  sw        $ra, 0x2c($sp)
/* C3FDC0 80240010 AFB60028 */  sw        $s6, 0x28($sp)
/* C3FDC4 80240014 AFB40020 */  sw        $s4, 0x20($sp)
/* C3FDC8 80240018 AFB3001C */  sw        $s3, 0x1c($sp)
/* C3FDCC 8024001C AFB20018 */  sw        $s2, 0x18($sp)
/* C3FDD0 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* C3FDD4 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* C3FDD8 80240028 F7B80040 */  sdc1      $f24, 0x40($sp)
/* C3FDDC 8024002C F7B60038 */  sdc1      $f22, 0x38($sp)
/* C3FDE0 80240030 F7B40030 */  sdc1      $f20, 0x30($sp)
/* C3FDE4 80240034 8EB30148 */  lw        $s3, 0x148($s5)
/* C3FDE8 80240038 86640008 */  lh        $a0, 8($s3)
/* C3FDEC 8024003C 0C00EABB */  jal       get_npc_unsafe
/* C3FDF0 80240040 00A0B02D */   daddu    $s6, $a1, $zero
/* C3FDF4 80240044 0040A02D */  daddu     $s4, $v0, $zero
/* C3FDF8 80240048 AEA00074 */  sw        $zero, 0x74($s5)
/* C3FDFC 8024004C C6980038 */  lwc1      $f24, 0x38($s4)
/* C3FE00 80240050 C6960040 */  lwc1      $f22, 0x40($s4)
/* C3FE04 80240054 0000902D */  daddu     $s2, $zero, $zero
/* C3FE08 80240058 AEA00078 */  sw        $zero, 0x78($s5)
/* C3FE0C 8024005C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* C3FE10 80240060 8C620000 */  lw        $v0, ($v1)
/* C3FE14 80240064 3C0146FF */  lui       $at, 0x46ff
/* C3FE18 80240068 3421FE00 */  ori       $at, $at, 0xfe00
/* C3FE1C 8024006C 4481A000 */  mtc1      $at, $f20
/* C3FE20 80240070 18400018 */  blez      $v0, .L802400D4
/* C3FE24 80240074 0240802D */   daddu    $s0, $s2, $zero
/* C3FE28 80240078 0240882D */  daddu     $s1, $s2, $zero
.L8024007C:
/* C3FE2C 8024007C 02231021 */  addu      $v0, $s1, $v1
/* C3FE30 80240080 4600C306 */  mov.s     $f12, $f24
/* C3FE34 80240084 C4440004 */  lwc1      $f4, 4($v0)
/* C3FE38 80240088 46802120 */  cvt.s.w   $f4, $f4
/* C3FE3C 8024008C 44062000 */  mfc1      $a2, $f4
/* C3FE40 80240090 C444000C */  lwc1      $f4, 0xc($v0)
/* C3FE44 80240094 46802120 */  cvt.s.w   $f4, $f4
/* C3FE48 80240098 44072000 */  mfc1      $a3, $f4
/* C3FE4C 8024009C 0C00A7B5 */  jal       dist2D
/* C3FE50 802400A0 4600B386 */   mov.s    $f14, $f22
/* C3FE54 802400A4 4614003C */  c.lt.s    $f0, $f20
/* C3FE58 802400A8 00000000 */  nop
/* C3FE5C 802400AC 45000003 */  bc1f      .L802400BC
/* C3FE60 802400B0 2631000C */   addiu    $s1, $s1, 0xc
/* C3FE64 802400B4 46000506 */  mov.s     $f20, $f0
/* C3FE68 802400B8 AEB20078 */  sw        $s2, 0x78($s5)
.L802400BC:
/* C3FE6C 802400BC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* C3FE70 802400C0 26100001 */  addiu     $s0, $s0, 1
/* C3FE74 802400C4 8C620000 */  lw        $v0, ($v1)
/* C3FE78 802400C8 0202102A */  slt       $v0, $s0, $v0
/* C3FE7C 802400CC 1440FFEB */  bnez      $v0, .L8024007C
/* C3FE80 802400D0 26520001 */   addiu    $s2, $s2, 1
.L802400D4:
/* C3FE84 802400D4 8E6200CC */  lw        $v0, 0xcc($s3)
/* C3FE88 802400D8 8C420004 */  lw        $v0, 4($v0)
/* C3FE8C 802400DC AE820028 */  sw        $v0, 0x28($s4)
/* C3FE90 802400E0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* C3FE94 802400E4 8C42007C */  lw        $v0, 0x7c($v0)
/* C3FE98 802400E8 04410004 */  bgez      $v0, .L802400FC
/* C3FE9C 802400EC 00000000 */   nop
/* C3FEA0 802400F0 C6C00000 */  lwc1      $f0, ($s6)
/* C3FEA4 802400F4 08090047 */  j         .L8024011C
/* C3FEA8 802400F8 E6800018 */   swc1     $f0, 0x18($s4)
.L802400FC:
/* C3FEAC 802400FC 3C018024 */  lui       $at, %hi(D_80246A00_C467B0)
/* C3FEB0 80240100 D4226A00 */  ldc1      $f2, %lo(D_80246A00_C467B0)($at)
/* C3FEB4 80240104 44820000 */  mtc1      $v0, $f0
/* C3FEB8 80240108 00000000 */  nop
/* C3FEBC 8024010C 46800021 */  cvt.d.w   $f0, $f0
/* C3FEC0 80240110 46220003 */  div.d     $f0, $f0, $f2
/* C3FEC4 80240114 46200020 */  cvt.s.d   $f0, $f0
/* C3FEC8 80240118 E6800018 */  swc1      $f0, 0x18($s4)
.L8024011C:
/* C3FECC 8024011C 24020001 */  addiu     $v0, $zero, 1
/* C3FED0 80240120 AEA20070 */  sw        $v0, 0x70($s5)
/* C3FED4 80240124 8FBF002C */  lw        $ra, 0x2c($sp)
/* C3FED8 80240128 8FB60028 */  lw        $s6, 0x28($sp)
/* C3FEDC 8024012C 8FB50024 */  lw        $s5, 0x24($sp)
/* C3FEE0 80240130 8FB40020 */  lw        $s4, 0x20($sp)
/* C3FEE4 80240134 8FB3001C */  lw        $s3, 0x1c($sp)
/* C3FEE8 80240138 8FB20018 */  lw        $s2, 0x18($sp)
/* C3FEEC 8024013C 8FB10014 */  lw        $s1, 0x14($sp)
/* C3FEF0 80240140 8FB00010 */  lw        $s0, 0x10($sp)
/* C3FEF4 80240144 D7B80040 */  ldc1      $f24, 0x40($sp)
/* C3FEF8 80240148 D7B60038 */  ldc1      $f22, 0x38($sp)
/* C3FEFC 8024014C D7B40030 */  ldc1      $f20, 0x30($sp)
/* C3FF00 80240150 03E00008 */  jr        $ra
/* C3FF04 80240154 27BD0048 */   addiu    $sp, $sp, 0x48
