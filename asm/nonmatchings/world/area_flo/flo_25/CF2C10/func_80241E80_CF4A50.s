.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E80_CF4A50
/* CF4A50 80241E80 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CF4A54 80241E84 AFB10014 */  sw        $s1, 0x14($sp)
/* CF4A58 80241E88 0080882D */  daddu     $s1, $a0, $zero
/* CF4A5C 80241E8C AFBF0020 */  sw        $ra, 0x20($sp)
/* CF4A60 80241E90 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF4A64 80241E94 AFB20018 */  sw        $s2, 0x18($sp)
/* CF4A68 80241E98 AFB00010 */  sw        $s0, 0x10($sp)
/* CF4A6C 80241E9C 8E30000C */  lw        $s0, 0xc($s1)
/* CF4A70 80241EA0 8E050000 */  lw        $a1, ($s0)
/* CF4A74 80241EA4 0C0B1EAF */  jal       get_variable
/* CF4A78 80241EA8 26100004 */   addiu    $s0, $s0, 4
/* CF4A7C 80241EAC 8E050000 */  lw        $a1, ($s0)
/* CF4A80 80241EB0 26100004 */  addiu     $s0, $s0, 4
/* CF4A84 80241EB4 0220202D */  daddu     $a0, $s1, $zero
/* CF4A88 80241EB8 0C0B1EAF */  jal       get_variable
/* CF4A8C 80241EBC 0040982D */   daddu    $s3, $v0, $zero
/* CF4A90 80241EC0 8E050000 */  lw        $a1, ($s0)
/* CF4A94 80241EC4 26100004 */  addiu     $s0, $s0, 4
/* CF4A98 80241EC8 0220202D */  daddu     $a0, $s1, $zero
/* CF4A9C 80241ECC 0C0B1EAF */  jal       get_variable
/* CF4AA0 80241ED0 0040902D */   daddu    $s2, $v0, $zero
/* CF4AA4 80241ED4 0220202D */  daddu     $a0, $s1, $zero
/* CF4AA8 80241ED8 8E050000 */  lw        $a1, ($s0)
/* CF4AAC 80241EDC 0C0B1EAF */  jal       get_variable
/* CF4AB0 80241EE0 0040882D */   daddu    $s1, $v0, $zero
/* CF4AB4 80241EE4 0260202D */  daddu     $a0, $s3, $zero
/* CF4AB8 80241EE8 0C04C3D6 */  jal       get_item_entity
/* CF4ABC 80241EEC 0040802D */   daddu    $s0, $v0, $zero
/* CF4AC0 80241EF0 0040182D */  daddu     $v1, $v0, $zero
/* CF4AC4 80241EF4 44920000 */  mtc1      $s2, $f0
/* CF4AC8 80241EF8 00000000 */  nop       
/* CF4ACC 80241EFC 46800020 */  cvt.s.w   $f0, $f0
/* CF4AD0 80241F00 E4600008 */  swc1      $f0, 8($v1)
/* CF4AD4 80241F04 44910000 */  mtc1      $s1, $f0
/* CF4AD8 80241F08 00000000 */  nop       
/* CF4ADC 80241F0C 46800020 */  cvt.s.w   $f0, $f0
/* CF4AE0 80241F10 E460000C */  swc1      $f0, 0xc($v1)
/* CF4AE4 80241F14 44900000 */  mtc1      $s0, $f0
/* CF4AE8 80241F18 00000000 */  nop       
/* CF4AEC 80241F1C 46800020 */  cvt.s.w   $f0, $f0
/* CF4AF0 80241F20 E4600010 */  swc1      $f0, 0x10($v1)
/* CF4AF4 80241F24 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF4AF8 80241F28 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF4AFC 80241F2C 8FB20018 */  lw        $s2, 0x18($sp)
/* CF4B00 80241F30 8FB10014 */  lw        $s1, 0x14($sp)
/* CF4B04 80241F34 8FB00010 */  lw        $s0, 0x10($sp)
/* CF4B08 80241F38 24020002 */  addiu     $v0, $zero, 2
/* CF4B0C 80241F3C 03E00008 */  jr        $ra
/* CF4B10 80241F40 27BD0028 */   addiu    $sp, $sp, 0x28
