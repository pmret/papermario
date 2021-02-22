.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435C0_803E40
/* 803E40 802435C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803E44 802435C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 803E48 802435C8 0080882D */  daddu     $s1, $a0, $zero
/* 803E4C 802435CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 803E50 802435D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 803E54 802435D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 803E58 802435D8 8E30000C */  lw        $s0, 0xc($s1)
/* 803E5C 802435DC 8E050000 */  lw        $a1, ($s0)
/* 803E60 802435E0 0C0B210B */  jal       get_float_variable
/* 803E64 802435E4 26100004 */   addiu    $s0, $s0, 4
/* 803E68 802435E8 8E050000 */  lw        $a1, ($s0)
/* 803E6C 802435EC 26100004 */  addiu     $s0, $s0, 4
/* 803E70 802435F0 4600008D */  trunc.w.s $f2, $f0
/* 803E74 802435F4 44121000 */  mfc1      $s2, $f2
/* 803E78 802435F8 0C0B210B */  jal       get_float_variable
/* 803E7C 802435FC 0220202D */   daddu    $a0, $s1, $zero
/* 803E80 80243600 0220202D */  daddu     $a0, $s1, $zero
/* 803E84 80243604 8E050000 */  lw        $a1, ($s0)
/* 803E88 80243608 4600008D */  trunc.w.s $f2, $f0
/* 803E8C 8024360C 44111000 */  mfc1      $s1, $f2
/* 803E90 80243610 0C0B210B */  jal       get_float_variable
/* 803E94 80243614 00000000 */   nop
/* 803E98 80243618 0000202D */  daddu     $a0, $zero, $zero
/* 803E9C 8024361C 3C05FD05 */  lui       $a1, 0xfd05
/* 803EA0 80243620 4600008D */  trunc.w.s $f2, $f0
/* 803EA4 80243624 44101000 */  mfc1      $s0, $f2
/* 803EA8 80243628 0C0B1EAF */  jal       get_variable
/* 803EAC 8024362C 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 803EB0 80243630 0040182D */  daddu     $v1, $v0, $zero
/* 803EB4 80243634 44920000 */  mtc1      $s2, $f0
/* 803EB8 80243638 00000000 */  nop
/* 803EBC 8024363C 46800020 */  cvt.s.w   $f0, $f0
/* 803EC0 80243640 E460001C */  swc1      $f0, 0x1c($v1)
/* 803EC4 80243644 44910000 */  mtc1      $s1, $f0
/* 803EC8 80243648 00000000 */  nop
/* 803ECC 8024364C 46800020 */  cvt.s.w   $f0, $f0
/* 803ED0 80243650 E4600020 */  swc1      $f0, 0x20($v1)
/* 803ED4 80243654 44900000 */  mtc1      $s0, $f0
/* 803ED8 80243658 00000000 */  nop
/* 803EDC 8024365C 46800020 */  cvt.s.w   $f0, $f0
/* 803EE0 80243660 E4600024 */  swc1      $f0, 0x24($v1)
/* 803EE4 80243664 8FBF001C */  lw        $ra, 0x1c($sp)
/* 803EE8 80243668 8FB20018 */  lw        $s2, 0x18($sp)
/* 803EEC 8024366C 8FB10014 */  lw        $s1, 0x14($sp)
/* 803EF0 80243670 8FB00010 */  lw        $s0, 0x10($sp)
/* 803EF4 80243674 24020002 */  addiu     $v0, $zero, 2
/* 803EF8 80243678 03E00008 */  jr        $ra
/* 803EFC 8024367C 27BD0020 */   addiu    $sp, $sp, 0x20
