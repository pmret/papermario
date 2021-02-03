.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1628_78EDF8
/* 78EDF8 802A1628 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 78EDFC 802A162C AFB10024 */  sw        $s1, 0x24($sp)
/* 78EE00 802A1630 0080882D */  daddu     $s1, $a0, $zero
/* 78EE04 802A1634 AFBF002C */  sw        $ra, 0x2c($sp)
/* 78EE08 802A1638 AFB20028 */  sw        $s2, 0x28($sp)
/* 78EE0C 802A163C AFB00020 */  sw        $s0, 0x20($sp)
/* 78EE10 802A1640 8E30000C */  lw        $s0, 0xc($s1)
/* 78EE14 802A1644 8E050000 */  lw        $a1, ($s0)
/* 78EE18 802A1648 0C0B1EAF */  jal       get_variable
/* 78EE1C 802A164C 26100004 */   addiu    $s0, $s0, 4
/* 78EE20 802A1650 8E050000 */  lw        $a1, ($s0)
/* 78EE24 802A1654 26100004 */  addiu     $s0, $s0, 4
/* 78EE28 802A1658 0220202D */  daddu     $a0, $s1, $zero
/* 78EE2C 802A165C 0C0B1EAF */  jal       get_variable
/* 78EE30 802A1660 0040902D */   daddu    $s2, $v0, $zero
/* 78EE34 802A1664 0220202D */  daddu     $a0, $s1, $zero
/* 78EE38 802A1668 8E050000 */  lw        $a1, ($s0)
/* 78EE3C 802A166C 0C0B1EAF */  jal       get_variable
/* 78EE40 802A1670 0040802D */   daddu    $s0, $v0, $zero
/* 78EE44 802A1674 24040002 */  addiu     $a0, $zero, 2
/* 78EE48 802A1678 44921000 */  mtc1      $s2, $f2
/* 78EE4C 802A167C 00000000 */  nop
/* 78EE50 802A1680 468010A0 */  cvt.s.w   $f2, $f2
/* 78EE54 802A1684 44051000 */  mfc1      $a1, $f2
/* 78EE58 802A1688 44901000 */  mtc1      $s0, $f2
/* 78EE5C 802A168C 00000000 */  nop
/* 78EE60 802A1690 468010A0 */  cvt.s.w   $f2, $f2
/* 78EE64 802A1694 44061000 */  mfc1      $a2, $f2
/* 78EE68 802A1698 44821000 */  mtc1      $v0, $f2
/* 78EE6C 802A169C 00000000 */  nop
/* 78EE70 802A16A0 468010A0 */  cvt.s.w   $f2, $f2
/* 78EE74 802A16A4 3C01BF80 */  lui       $at, 0xbf80
/* 78EE78 802A16A8 44810000 */  mtc1      $at, $f0
/* 78EE7C 802A16AC 44071000 */  mfc1      $a3, $f2
/* 78EE80 802A16B0 24030005 */  addiu     $v1, $zero, 5
/* 78EE84 802A16B4 AFA00010 */  sw        $zero, 0x10($sp)
/* 78EE88 802A16B8 AFA00018 */  sw        $zero, 0x18($sp)
/* 78EE8C 802A16BC AFA3001C */  sw        $v1, 0x1c($sp)
/* 78EE90 802A16C0 0C01C064 */  jal       func_80070190
/* 78EE94 802A16C4 E7A00014 */   swc1     $f0, 0x14($sp)
/* 78EE98 802A16C8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 78EE9C 802A16CC 8FB20028 */  lw        $s2, 0x28($sp)
/* 78EEA0 802A16D0 8FB10024 */  lw        $s1, 0x24($sp)
/* 78EEA4 802A16D4 8FB00020 */  lw        $s0, 0x20($sp)
/* 78EEA8 802A16D8 24020002 */  addiu     $v0, $zero, 2
/* 78EEAC 802A16DC 03E00008 */  jr        $ra
