.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960_882B20
/* 882B20 80240960 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 882B24 80240964 AFB10014 */  sw        $s1, 0x14($sp)
/* 882B28 80240968 0080882D */  daddu     $s1, $a0, $zero
/* 882B2C 8024096C AFBF0020 */  sw        $ra, 0x20($sp)
/* 882B30 80240970 AFB3001C */  sw        $s3, 0x1c($sp)
/* 882B34 80240974 AFB20018 */  sw        $s2, 0x18($sp)
/* 882B38 80240978 AFB00010 */  sw        $s0, 0x10($sp)
/* 882B3C 8024097C 8E30000C */  lw        $s0, 0xc($s1)
/* 882B40 80240980 8E050000 */  lw        $a1, ($s0)
/* 882B44 80240984 0C0B1EAF */  jal       get_variable
/* 882B48 80240988 26100004 */   addiu    $s0, $s0, 4
/* 882B4C 8024098C 8E050000 */  lw        $a1, ($s0)
/* 882B50 80240990 26100004 */  addiu     $s0, $s0, 4
/* 882B54 80240994 0220202D */  daddu     $a0, $s1, $zero
/* 882B58 80240998 0C0B1EAF */  jal       get_variable
/* 882B5C 8024099C 0040982D */   daddu    $s3, $v0, $zero
/* 882B60 802409A0 8E050000 */  lw        $a1, ($s0)
/* 882B64 802409A4 26100004 */  addiu     $s0, $s0, 4
/* 882B68 802409A8 0220202D */  daddu     $a0, $s1, $zero
/* 882B6C 802409AC 0C0B1EAF */  jal       get_variable
/* 882B70 802409B0 0040902D */   daddu    $s2, $v0, $zero
/* 882B74 802409B4 0220202D */  daddu     $a0, $s1, $zero
/* 882B78 802409B8 8E050000 */  lw        $a1, ($s0)
/* 882B7C 802409BC 0C0B1EAF */  jal       get_variable
/* 882B80 802409C0 0040882D */   daddu    $s1, $v0, $zero
/* 882B84 802409C4 0260202D */  daddu     $a0, $s3, $zero
/* 882B88 802409C8 0C04417A */  jal       get_entity_by_index
/* 882B8C 802409CC 0040802D */   daddu    $s0, $v0, $zero
/* 882B90 802409D0 0040182D */  daddu     $v1, $v0, $zero
/* 882B94 802409D4 44920000 */  mtc1      $s2, $f0
/* 882B98 802409D8 00000000 */  nop       
/* 882B9C 802409DC 46800020 */  cvt.s.w   $f0, $f0
/* 882BA0 802409E0 E4600048 */  swc1      $f0, 0x48($v1)
/* 882BA4 802409E4 44910000 */  mtc1      $s1, $f0
/* 882BA8 802409E8 00000000 */  nop       
/* 882BAC 802409EC 46800020 */  cvt.s.w   $f0, $f0
/* 882BB0 802409F0 E460004C */  swc1      $f0, 0x4c($v1)
/* 882BB4 802409F4 44900000 */  mtc1      $s0, $f0
/* 882BB8 802409F8 00000000 */  nop       
/* 882BBC 802409FC 46800020 */  cvt.s.w   $f0, $f0
/* 882BC0 80240A00 E4600050 */  swc1      $f0, 0x50($v1)
/* 882BC4 80240A04 8FBF0020 */  lw        $ra, 0x20($sp)
/* 882BC8 80240A08 8FB3001C */  lw        $s3, 0x1c($sp)
/* 882BCC 80240A0C 8FB20018 */  lw        $s2, 0x18($sp)
/* 882BD0 80240A10 8FB10014 */  lw        $s1, 0x14($sp)
/* 882BD4 80240A14 8FB00010 */  lw        $s0, 0x10($sp)
/* 882BD8 80240A18 24020002 */  addiu     $v0, $zero, 2
/* 882BDC 80240A1C 03E00008 */  jr        $ra
/* 882BE0 80240A20 27BD0028 */   addiu    $sp, $sp, 0x28
/* 882BE4 80240A24 00000000 */  nop       
/* 882BE8 80240A28 00000000 */  nop       
/* 882BEC 80240A2C 00000000 */  nop       
