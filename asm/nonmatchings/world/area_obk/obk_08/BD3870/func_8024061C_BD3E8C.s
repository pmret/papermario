.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_BD3E8C
/* BD3E8C 8024061C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD3E90 80240620 AFB10014 */  sw        $s1, 0x14($sp)
/* BD3E94 80240624 0080882D */  daddu     $s1, $a0, $zero
/* BD3E98 80240628 AFBF001C */  sw        $ra, 0x1c($sp)
/* BD3E9C 8024062C AFB20018 */  sw        $s2, 0x18($sp)
/* BD3EA0 80240630 AFB00010 */  sw        $s0, 0x10($sp)
/* BD3EA4 80240634 8E30000C */  lw        $s0, 0xc($s1)
/* BD3EA8 80240638 8E050000 */  lw        $a1, ($s0)
/* BD3EAC 8024063C 0C0B210B */  jal       get_float_variable
/* BD3EB0 80240640 26100004 */   addiu    $s0, $s0, 4
/* BD3EB4 80240644 8E050000 */  lw        $a1, ($s0)
/* BD3EB8 80240648 26100004 */  addiu     $s0, $s0, 4
/* BD3EBC 8024064C 4600008D */  trunc.w.s $f2, $f0
/* BD3EC0 80240650 44121000 */  mfc1      $s2, $f2
/* BD3EC4 80240654 0C0B210B */  jal       get_float_variable
/* BD3EC8 80240658 0220202D */   daddu    $a0, $s1, $zero
/* BD3ECC 8024065C 0220202D */  daddu     $a0, $s1, $zero
/* BD3ED0 80240660 8E050000 */  lw        $a1, ($s0)
/* BD3ED4 80240664 4600008D */  trunc.w.s $f2, $f0
/* BD3ED8 80240668 44111000 */  mfc1      $s1, $f2
/* BD3EDC 8024066C 0C0B210B */  jal       get_float_variable
/* BD3EE0 80240670 00000000 */   nop      
/* BD3EE4 80240674 0000202D */  daddu     $a0, $zero, $zero
/* BD3EE8 80240678 3C05FD05 */  lui       $a1, 0xfd05
/* BD3EEC 8024067C 4600008D */  trunc.w.s $f2, $f0
/* BD3EF0 80240680 44101000 */  mfc1      $s0, $f2
/* BD3EF4 80240684 0C0B1EAF */  jal       get_variable
/* BD3EF8 80240688 34A50F8A */   ori      $a1, $a1, 0xf8a
/* BD3EFC 8024068C 0040182D */  daddu     $v1, $v0, $zero
/* BD3F00 80240690 44920000 */  mtc1      $s2, $f0
/* BD3F04 80240694 00000000 */  nop       
/* BD3F08 80240698 46800020 */  cvt.s.w   $f0, $f0
/* BD3F0C 8024069C E460001C */  swc1      $f0, 0x1c($v1)
/* BD3F10 802406A0 44910000 */  mtc1      $s1, $f0
/* BD3F14 802406A4 00000000 */  nop       
/* BD3F18 802406A8 46800020 */  cvt.s.w   $f0, $f0
/* BD3F1C 802406AC E4600020 */  swc1      $f0, 0x20($v1)
/* BD3F20 802406B0 44900000 */  mtc1      $s0, $f0
/* BD3F24 802406B4 00000000 */  nop       
/* BD3F28 802406B8 46800020 */  cvt.s.w   $f0, $f0
/* BD3F2C 802406BC E4600024 */  swc1      $f0, 0x24($v1)
/* BD3F30 802406C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* BD3F34 802406C4 8FB20018 */  lw        $s2, 0x18($sp)
/* BD3F38 802406C8 8FB10014 */  lw        $s1, 0x14($sp)
/* BD3F3C 802406CC 8FB00010 */  lw        $s0, 0x10($sp)
/* BD3F40 802406D0 24020002 */  addiu     $v0, $zero, 2
/* BD3F44 802406D4 03E00008 */  jr        $ra
/* BD3F48 802406D8 27BD0020 */   addiu    $sp, $sp, 0x20
