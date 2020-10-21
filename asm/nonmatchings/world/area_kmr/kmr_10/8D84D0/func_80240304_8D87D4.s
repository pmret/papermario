.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240304_8D87D4
/* 8D87D4 80240304 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8D87D8 80240308 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D87DC 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* 8D87E0 80240310 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8D87E4 80240314 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8D87E8 80240318 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D87EC 8024031C AFB00010 */  sw        $s0, 0x10($sp)
/* 8D87F0 80240320 8E30000C */  lw        $s0, 0xc($s1)
/* 8D87F4 80240324 8E050000 */  lw        $a1, ($s0)
/* 8D87F8 80240328 0C0B1EAF */  jal       get_variable
/* 8D87FC 8024032C 26100004 */   addiu    $s0, $s0, 4
/* 8D8800 80240330 8E050000 */  lw        $a1, ($s0)
/* 8D8804 80240334 26100004 */  addiu     $s0, $s0, 4
/* 8D8808 80240338 0220202D */  daddu     $a0, $s1, $zero
/* 8D880C 8024033C 0C0B1EAF */  jal       get_variable
/* 8D8810 80240340 0040982D */   daddu    $s3, $v0, $zero
/* 8D8814 80240344 8E050000 */  lw        $a1, ($s0)
/* 8D8818 80240348 26100004 */  addiu     $s0, $s0, 4
/* 8D881C 8024034C 0220202D */  daddu     $a0, $s1, $zero
/* 8D8820 80240350 0C0B1EAF */  jal       get_variable
/* 8D8824 80240354 0040902D */   daddu    $s2, $v0, $zero
/* 8D8828 80240358 0220202D */  daddu     $a0, $s1, $zero
/* 8D882C 8024035C 8E050000 */  lw        $a1, ($s0)
/* 8D8830 80240360 0C0B1EAF */  jal       get_variable
/* 8D8834 80240364 0040882D */   daddu    $s1, $v0, $zero
/* 8D8838 80240368 0260202D */  daddu     $a0, $s3, $zero
/* 8D883C 8024036C 0C04417A */  jal       get_entity_by_index
/* 8D8840 80240370 0040802D */   daddu    $s0, $v0, $zero
/* 8D8844 80240374 0040182D */  daddu     $v1, $v0, $zero
/* 8D8848 80240378 44920000 */  mtc1      $s2, $f0
/* 8D884C 8024037C 00000000 */  nop       
/* 8D8850 80240380 46800020 */  cvt.s.w   $f0, $f0
/* 8D8854 80240384 E4600048 */  swc1      $f0, 0x48($v1)
/* 8D8858 80240388 44910000 */  mtc1      $s1, $f0
/* 8D885C 8024038C 00000000 */  nop       
/* 8D8860 80240390 46800020 */  cvt.s.w   $f0, $f0
/* 8D8864 80240394 E460004C */  swc1      $f0, 0x4c($v1)
/* 8D8868 80240398 44900000 */  mtc1      $s0, $f0
/* 8D886C 8024039C 00000000 */  nop       
/* 8D8870 802403A0 46800020 */  cvt.s.w   $f0, $f0
/* 8D8874 802403A4 E4600050 */  swc1      $f0, 0x50($v1)
/* 8D8878 802403A8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8D887C 802403AC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8D8880 802403B0 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D8884 802403B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D8888 802403B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D888C 802403BC 24020002 */  addiu     $v0, $zero, 2
/* 8D8890 802403C0 03E00008 */  jr        $ra
/* 8D8894 802403C4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 8D8898 802403C8 00000000 */  nop       
/* 8D889C 802403CC 00000000 */  nop       
