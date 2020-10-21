.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240984_875744
/* 875744 80240984 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 875748 80240988 AFB10014 */  sw        $s1, 0x14($sp)
/* 87574C 8024098C 0080882D */  daddu     $s1, $a0, $zero
/* 875750 80240990 AFBF0020 */  sw        $ra, 0x20($sp)
/* 875754 80240994 AFB3001C */  sw        $s3, 0x1c($sp)
/* 875758 80240998 AFB20018 */  sw        $s2, 0x18($sp)
/* 87575C 8024099C AFB00010 */  sw        $s0, 0x10($sp)
/* 875760 802409A0 8E30000C */  lw        $s0, 0xc($s1)
/* 875764 802409A4 8E050000 */  lw        $a1, ($s0)
/* 875768 802409A8 0C0B1EAF */  jal       get_variable
/* 87576C 802409AC 26100004 */   addiu    $s0, $s0, 4
/* 875770 802409B0 8E050000 */  lw        $a1, ($s0)
/* 875774 802409B4 26100004 */  addiu     $s0, $s0, 4
/* 875778 802409B8 0220202D */  daddu     $a0, $s1, $zero
/* 87577C 802409BC 0C0B1EAF */  jal       get_variable
/* 875780 802409C0 0040982D */   daddu    $s3, $v0, $zero
/* 875784 802409C4 8E050000 */  lw        $a1, ($s0)
/* 875788 802409C8 26100004 */  addiu     $s0, $s0, 4
/* 87578C 802409CC 0220202D */  daddu     $a0, $s1, $zero
/* 875790 802409D0 0C0B1EAF */  jal       get_variable
/* 875794 802409D4 0040902D */   daddu    $s2, $v0, $zero
/* 875798 802409D8 0220202D */  daddu     $a0, $s1, $zero
/* 87579C 802409DC 8E050000 */  lw        $a1, ($s0)
/* 8757A0 802409E0 0C0B1EAF */  jal       get_variable
/* 8757A4 802409E4 0040882D */   daddu    $s1, $v0, $zero
/* 8757A8 802409E8 0260202D */  daddu     $a0, $s3, $zero
/* 8757AC 802409EC 0C04417A */  jal       get_entity_by_index
/* 8757B0 802409F0 0040802D */   daddu    $s0, $v0, $zero
/* 8757B4 802409F4 0040182D */  daddu     $v1, $v0, $zero
/* 8757B8 802409F8 44920000 */  mtc1      $s2, $f0
/* 8757BC 802409FC 00000000 */  nop       
/* 8757C0 80240A00 46800020 */  cvt.s.w   $f0, $f0
/* 8757C4 80240A04 E4600048 */  swc1      $f0, 0x48($v1)
/* 8757C8 80240A08 44910000 */  mtc1      $s1, $f0
/* 8757CC 80240A0C 00000000 */  nop       
/* 8757D0 80240A10 46800020 */  cvt.s.w   $f0, $f0
/* 8757D4 80240A14 E460004C */  swc1      $f0, 0x4c($v1)
/* 8757D8 80240A18 44900000 */  mtc1      $s0, $f0
/* 8757DC 80240A1C 00000000 */  nop       
/* 8757E0 80240A20 46800020 */  cvt.s.w   $f0, $f0
/* 8757E4 80240A24 E4600050 */  swc1      $f0, 0x50($v1)
/* 8757E8 80240A28 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8757EC 80240A2C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8757F0 80240A30 8FB20018 */  lw        $s2, 0x18($sp)
/* 8757F4 80240A34 8FB10014 */  lw        $s1, 0x14($sp)
/* 8757F8 80240A38 8FB00010 */  lw        $s0, 0x10($sp)
/* 8757FC 80240A3C 24020002 */  addiu     $v0, $zero, 2
/* 875800 80240A40 03E00008 */  jr        $ra
/* 875804 80240A44 27BD0028 */   addiu    $sp, $sp, 0x28
/* 875808 80240A48 00000000 */  nop       
/* 87580C 80240A4C 00000000 */  nop       
