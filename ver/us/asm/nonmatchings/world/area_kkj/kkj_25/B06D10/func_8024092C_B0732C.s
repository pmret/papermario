.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024092C_B0732C
/* B0732C 8024092C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B07330 80240930 AFB10014 */  sw        $s1, 0x14($sp)
/* B07334 80240934 0080882D */  daddu     $s1, $a0, $zero
/* B07338 80240938 AFBF001C */  sw        $ra, 0x1c($sp)
/* B0733C 8024093C AFB20018 */  sw        $s2, 0x18($sp)
/* B07340 80240940 AFB00010 */  sw        $s0, 0x10($sp)
/* B07344 80240944 8E30000C */  lw        $s0, 0xc($s1)
/* B07348 80240948 8E050000 */  lw        $a1, ($s0)
/* B0734C 8024094C 0C0B210B */  jal       get_float_variable
/* B07350 80240950 26100004 */   addiu    $s0, $s0, 4
/* B07354 80240954 8E050000 */  lw        $a1, ($s0)
/* B07358 80240958 26100004 */  addiu     $s0, $s0, 4
/* B0735C 8024095C 4600008D */  trunc.w.s $f2, $f0
/* B07360 80240960 44121000 */  mfc1      $s2, $f2
/* B07364 80240964 0C0B210B */  jal       get_float_variable
/* B07368 80240968 0220202D */   daddu    $a0, $s1, $zero
/* B0736C 8024096C 0220202D */  daddu     $a0, $s1, $zero
/* B07370 80240970 8E050000 */  lw        $a1, ($s0)
/* B07374 80240974 4600008D */  trunc.w.s $f2, $f0
/* B07378 80240978 44111000 */  mfc1      $s1, $f2
/* B0737C 8024097C 0C0B210B */  jal       get_float_variable
/* B07380 80240980 00000000 */   nop
/* B07384 80240984 0000202D */  daddu     $a0, $zero, $zero
/* B07388 80240988 3C05FD05 */  lui       $a1, 0xfd05
/* B0738C 8024098C 4600008D */  trunc.w.s $f2, $f0
/* B07390 80240990 44101000 */  mfc1      $s0, $f2
/* B07394 80240994 0C0B1EAF */  jal       get_variable
/* B07398 80240998 34A50F8A */   ori      $a1, $a1, 0xf8a
/* B0739C 8024099C 0040182D */  daddu     $v1, $v0, $zero
/* B073A0 802409A0 44920000 */  mtc1      $s2, $f0
/* B073A4 802409A4 00000000 */  nop
/* B073A8 802409A8 46800020 */  cvt.s.w   $f0, $f0
/* B073AC 802409AC E460001C */  swc1      $f0, 0x1c($v1)
/* B073B0 802409B0 44910000 */  mtc1      $s1, $f0
/* B073B4 802409B4 00000000 */  nop
/* B073B8 802409B8 46800020 */  cvt.s.w   $f0, $f0
/* B073BC 802409BC E4600020 */  swc1      $f0, 0x20($v1)
/* B073C0 802409C0 44900000 */  mtc1      $s0, $f0
/* B073C4 802409C4 00000000 */  nop
/* B073C8 802409C8 46800020 */  cvt.s.w   $f0, $f0
/* B073CC 802409CC E4600024 */  swc1      $f0, 0x24($v1)
/* B073D0 802409D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* B073D4 802409D4 8FB20018 */  lw        $s2, 0x18($sp)
/* B073D8 802409D8 8FB10014 */  lw        $s1, 0x14($sp)
/* B073DC 802409DC 8FB00010 */  lw        $s0, 0x10($sp)
/* B073E0 802409E0 24020002 */  addiu     $v0, $zero, 2
/* B073E4 802409E4 03E00008 */  jr        $ra
/* B073E8 802409E8 27BD0020 */   addiu    $sp, $sp, 0x20
