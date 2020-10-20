.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960
/* 869E10 80240960 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 869E14 80240964 AFB10014 */  sw        $s1, 0x14($sp)
/* 869E18 80240968 0080882D */  daddu     $s1, $a0, $zero
/* 869E1C 8024096C AFBF0020 */  sw        $ra, 0x20($sp)
/* 869E20 80240970 AFB3001C */  sw        $s3, 0x1c($sp)
/* 869E24 80240974 AFB20018 */  sw        $s2, 0x18($sp)
/* 869E28 80240978 AFB00010 */  sw        $s0, 0x10($sp)
/* 869E2C 8024097C 8E30000C */  lw        $s0, 0xc($s1)
/* 869E30 80240980 8E050000 */  lw        $a1, ($s0)
/* 869E34 80240984 0C0B1EAF */  jal       get_variable
/* 869E38 80240988 26100004 */   addiu    $s0, $s0, 4
/* 869E3C 8024098C 8E050000 */  lw        $a1, ($s0)
/* 869E40 80240990 26100004 */  addiu     $s0, $s0, 4
/* 869E44 80240994 0220202D */  daddu     $a0, $s1, $zero
/* 869E48 80240998 0C0B1EAF */  jal       get_variable
/* 869E4C 8024099C 0040982D */   daddu    $s3, $v0, $zero
/* 869E50 802409A0 8E050000 */  lw        $a1, ($s0)
/* 869E54 802409A4 26100004 */  addiu     $s0, $s0, 4
/* 869E58 802409A8 0220202D */  daddu     $a0, $s1, $zero
/* 869E5C 802409AC 0C0B1EAF */  jal       get_variable
/* 869E60 802409B0 0040902D */   daddu    $s2, $v0, $zero
/* 869E64 802409B4 0220202D */  daddu     $a0, $s1, $zero
/* 869E68 802409B8 8E050000 */  lw        $a1, ($s0)
/* 869E6C 802409BC 0C0B1EAF */  jal       get_variable
/* 869E70 802409C0 0040882D */   daddu    $s1, $v0, $zero
/* 869E74 802409C4 0260202D */  daddu     $a0, $s3, $zero
/* 869E78 802409C8 0C04417A */  jal       get_entity_by_index
/* 869E7C 802409CC 0040802D */   daddu    $s0, $v0, $zero
/* 869E80 802409D0 0040182D */  daddu     $v1, $v0, $zero
/* 869E84 802409D4 44920000 */  mtc1      $s2, $f0
/* 869E88 802409D8 00000000 */  nop       
/* 869E8C 802409DC 46800020 */  cvt.s.w   $f0, $f0
/* 869E90 802409E0 E4600048 */  swc1      $f0, 0x48($v1)
/* 869E94 802409E4 44910000 */  mtc1      $s1, $f0
/* 869E98 802409E8 00000000 */  nop       
/* 869E9C 802409EC 46800020 */  cvt.s.w   $f0, $f0
/* 869EA0 802409F0 E460004C */  swc1      $f0, 0x4c($v1)
/* 869EA4 802409F4 44900000 */  mtc1      $s0, $f0
/* 869EA8 802409F8 00000000 */  nop       
/* 869EAC 802409FC 46800020 */  cvt.s.w   $f0, $f0
/* 869EB0 80240A00 E4600050 */  swc1      $f0, 0x50($v1)
/* 869EB4 80240A04 8FBF0020 */  lw        $ra, 0x20($sp)
/* 869EB8 80240A08 8FB3001C */  lw        $s3, 0x1c($sp)
/* 869EBC 80240A0C 8FB20018 */  lw        $s2, 0x18($sp)
/* 869EC0 80240A10 8FB10014 */  lw        $s1, 0x14($sp)
/* 869EC4 80240A14 8FB00010 */  lw        $s0, 0x10($sp)
/* 869EC8 80240A18 24020002 */  addiu     $v0, $zero, 2
/* 869ECC 80240A1C 03E00008 */  jr        $ra
/* 869ED0 80240A20 27BD0028 */   addiu    $sp, $sp, 0x28
/* 869ED4 80240A24 00000000 */  nop       
/* 869ED8 80240A28 00000000 */  nop       
/* 869EDC 80240A2C 00000000 */  nop       
