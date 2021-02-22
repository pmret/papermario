.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A8_BBB828
/* BBB828 802404A8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BBB82C 802404AC AFB10024 */  sw        $s1, 0x24($sp)
/* BBB830 802404B0 0080882D */  daddu     $s1, $a0, $zero
/* BBB834 802404B4 AFB00020 */  sw        $s0, 0x20($sp)
/* BBB838 802404B8 00A0802D */  daddu     $s0, $a1, $zero
/* BBB83C 802404BC AFBF002C */  sw        $ra, 0x2c($sp)
/* BBB840 802404C0 AFB20028 */  sw        $s2, 0x28($sp)
/* BBB844 802404C4 0C0B36B0 */  jal       resolve_npc
/* BBB848 802404C8 8E250084 */   lw       $a1, 0x84($s1)
/* BBB84C 802404CC 1200000E */  beqz      $s0, .L80240508
/* BBB850 802404D0 0040902D */   daddu    $s2, $v0, $zero
/* BBB854 802404D4 C6260088 */  lwc1      $f6, 0x88($s1)
/* BBB858 802404D8 468031A0 */  cvt.s.w   $f6, $f6
/* BBB85C 802404DC 44063000 */  mfc1      $a2, $f6
/* BBB860 802404E0 C626008C */  lwc1      $f6, 0x8c($s1)
/* BBB864 802404E4 468031A0 */  cvt.s.w   $f6, $f6
/* BBB868 802404E8 8E220098 */  lw        $v0, 0x98($s1)
/* BBB86C 802404EC 44073000 */  mfc1      $a3, $f6
/* BBB870 802404F0 AE22009C */  sw        $v0, 0x9c($s1)
/* BBB874 802404F4 C64C0038 */  lwc1      $f12, 0x38($s2)
/* BBB878 802404F8 0C00A7B5 */  jal       dist2D
/* BBB87C 802404FC C64E0040 */   lwc1     $f14, 0x40($s2)
/* BBB880 80240500 4600018D */  trunc.w.s $f6, $f0
/* BBB884 80240504 E62600A0 */  swc1      $f6, 0xa0($s1)
.L80240508:
/* BBB888 80240508 8E22009C */  lw        $v0, 0x9c($s1)
/* BBB88C 8024050C 1C400003 */  bgtz      $v0, .L8024051C
/* BBB890 80240510 00000000 */   nop
/* BBB894 80240514 08090172 */  j         .L802405C8
/* BBB898 80240518 24020002 */   addiu    $v0, $zero, 2
.L8024051C:
/* BBB89C 8024051C C6220090 */  lwc1      $f2, 0x90($s1)
/* BBB8A0 80240520 468010A0 */  cvt.s.w   $f2, $f2
/* BBB8A4 80240524 C6240094 */  lwc1      $f4, 0x94($s1)
/* BBB8A8 80240528 46802120 */  cvt.s.w   $f4, $f4
/* BBB8AC 8024052C C6200098 */  lwc1      $f0, 0x98($s1)
/* BBB8B0 80240530 46800020 */  cvt.s.w   $f0, $f0
/* BBB8B4 80240534 4600018D */  trunc.w.s $f6, $f0
/* BBB8B8 80240538 E7A60010 */  swc1      $f6, 0x10($sp)
/* BBB8BC 8024053C 44820000 */  mtc1      $v0, $f0
/* BBB8C0 80240540 00000000 */  nop
/* BBB8C4 80240544 46800020 */  cvt.s.w   $f0, $f0
/* BBB8C8 80240548 44051000 */  mfc1      $a1, $f2
/* BBB8CC 8024054C 44062000 */  mfc1      $a2, $f4
/* BBB8D0 80240550 4600018D */  trunc.w.s $f6, $f0
/* BBB8D4 80240554 44073000 */  mfc1      $a3, $f6
/* BBB8D8 80240558 0C00A8ED */  jal       update_lerp
/* BBB8DC 8024055C 0000202D */   daddu    $a0, $zero, $zero
/* BBB8E0 80240560 46000306 */  mov.s     $f12, $f0
/* BBB8E4 80240564 27A50018 */  addiu     $a1, $sp, 0x18
/* BBB8E8 80240568 0C00A88D */  jal       sin_cos_deg
/* BBB8EC 8024056C 27A6001C */   addiu    $a2, $sp, 0x1c
/* BBB8F0 80240570 C7A00018 */  lwc1      $f0, 0x18($sp)
/* BBB8F4 80240574 C62200A0 */  lwc1      $f2, 0xa0($s1)
/* BBB8F8 80240578 468010A0 */  cvt.s.w   $f2, $f2
/* BBB8FC 8024057C 46001082 */  mul.s     $f2, $f2, $f0
/* BBB900 80240580 00000000 */  nop
/* BBB904 80240584 C6200088 */  lwc1      $f0, 0x88($s1)
/* BBB908 80240588 46800020 */  cvt.s.w   $f0, $f0
/* BBB90C 8024058C 46020000 */  add.s     $f0, $f0, $f2
/* BBB910 80240590 E6400038 */  swc1      $f0, 0x38($s2)
/* BBB914 80240594 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BBB918 80240598 C62200A0 */  lwc1      $f2, 0xa0($s1)
/* BBB91C 8024059C 468010A0 */  cvt.s.w   $f2, $f2
/* BBB920 802405A0 46001082 */  mul.s     $f2, $f2, $f0
/* BBB924 802405A4 00000000 */  nop
/* BBB928 802405A8 C620008C */  lwc1      $f0, 0x8c($s1)
/* BBB92C 802405AC 46800020 */  cvt.s.w   $f0, $f0
/* BBB930 802405B0 46020000 */  add.s     $f0, $f0, $f2
/* BBB934 802405B4 E6400040 */  swc1      $f0, 0x40($s2)
/* BBB938 802405B8 8E23009C */  lw        $v1, 0x9c($s1)
/* BBB93C 802405BC 0000102D */  daddu     $v0, $zero, $zero
/* BBB940 802405C0 2463FFFF */  addiu     $v1, $v1, -1
/* BBB944 802405C4 AE23009C */  sw        $v1, 0x9c($s1)
.L802405C8:
/* BBB948 802405C8 8FBF002C */  lw        $ra, 0x2c($sp)
/* BBB94C 802405CC 8FB20028 */  lw        $s2, 0x28($sp)
/* BBB950 802405D0 8FB10024 */  lw        $s1, 0x24($sp)
/* BBB954 802405D4 8FB00020 */  lw        $s0, 0x20($sp)
/* BBB958 802405D8 03E00008 */  jr        $ra
/* BBB95C 802405DC 27BD0030 */   addiu    $sp, $sp, 0x30
