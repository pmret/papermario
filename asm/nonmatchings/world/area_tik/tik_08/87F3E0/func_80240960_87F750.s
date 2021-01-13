.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960_87F750
/* 87F750 80240960 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 87F754 80240964 AFB10014 */  sw        $s1, 0x14($sp)
/* 87F758 80240968 0080882D */  daddu     $s1, $a0, $zero
/* 87F75C 8024096C AFBF0020 */  sw        $ra, 0x20($sp)
/* 87F760 80240970 AFB3001C */  sw        $s3, 0x1c($sp)
/* 87F764 80240974 AFB20018 */  sw        $s2, 0x18($sp)
/* 87F768 80240978 AFB00010 */  sw        $s0, 0x10($sp)
/* 87F76C 8024097C 8E30000C */  lw        $s0, 0xc($s1)
/* 87F770 80240980 8E050000 */  lw        $a1, ($s0)
/* 87F774 80240984 0C0B1EAF */  jal       get_variable
/* 87F778 80240988 26100004 */   addiu    $s0, $s0, 4
/* 87F77C 8024098C 8E050000 */  lw        $a1, ($s0)
/* 87F780 80240990 26100004 */  addiu     $s0, $s0, 4
/* 87F784 80240994 0220202D */  daddu     $a0, $s1, $zero
/* 87F788 80240998 0C0B1EAF */  jal       get_variable
/* 87F78C 8024099C 0040982D */   daddu    $s3, $v0, $zero
/* 87F790 802409A0 8E050000 */  lw        $a1, ($s0)
/* 87F794 802409A4 26100004 */  addiu     $s0, $s0, 4
/* 87F798 802409A8 0220202D */  daddu     $a0, $s1, $zero
/* 87F79C 802409AC 0C0B1EAF */  jal       get_variable
/* 87F7A0 802409B0 0040902D */   daddu    $s2, $v0, $zero
/* 87F7A4 802409B4 0220202D */  daddu     $a0, $s1, $zero
/* 87F7A8 802409B8 8E050000 */  lw        $a1, ($s0)
/* 87F7AC 802409BC 0C0B1EAF */  jal       get_variable
/* 87F7B0 802409C0 0040882D */   daddu    $s1, $v0, $zero
/* 87F7B4 802409C4 0260202D */  daddu     $a0, $s3, $zero
/* 87F7B8 802409C8 0C04417A */  jal       get_entity_by_index
/* 87F7BC 802409CC 0040802D */   daddu    $s0, $v0, $zero
/* 87F7C0 802409D0 0040182D */  daddu     $v1, $v0, $zero
/* 87F7C4 802409D4 44920000 */  mtc1      $s2, $f0
/* 87F7C8 802409D8 00000000 */  nop
/* 87F7CC 802409DC 46800020 */  cvt.s.w   $f0, $f0
/* 87F7D0 802409E0 E4600048 */  swc1      $f0, 0x48($v1)
/* 87F7D4 802409E4 44910000 */  mtc1      $s1, $f0
/* 87F7D8 802409E8 00000000 */  nop
/* 87F7DC 802409EC 46800020 */  cvt.s.w   $f0, $f0
/* 87F7E0 802409F0 E460004C */  swc1      $f0, 0x4c($v1)
/* 87F7E4 802409F4 44900000 */  mtc1      $s0, $f0
/* 87F7E8 802409F8 00000000 */  nop
/* 87F7EC 802409FC 46800020 */  cvt.s.w   $f0, $f0
/* 87F7F0 80240A00 E4600050 */  swc1      $f0, 0x50($v1)
/* 87F7F4 80240A04 8FBF0020 */  lw        $ra, 0x20($sp)
/* 87F7F8 80240A08 8FB3001C */  lw        $s3, 0x1c($sp)
/* 87F7FC 80240A0C 8FB20018 */  lw        $s2, 0x18($sp)
/* 87F800 80240A10 8FB10014 */  lw        $s1, 0x14($sp)
/* 87F804 80240A14 8FB00010 */  lw        $s0, 0x10($sp)
/* 87F808 80240A18 24020002 */  addiu     $v0, $zero, 2
/* 87F80C 80240A1C 03E00008 */  jr        $ra
/* 87F810 80240A20 27BD0028 */   addiu    $sp, $sp, 0x28
/* 87F814 80240A24 00000000 */  nop
/* 87F818 80240A28 00000000 */  nop
/* 87F81C 80240A2C 00000000 */  nop
