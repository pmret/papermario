.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243680_803F00
/* 803F00 80243680 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803F04 80243684 AFB10014 */  sw        $s1, 0x14($sp)
/* 803F08 80243688 0080882D */  daddu     $s1, $a0, $zero
/* 803F0C 8024368C AFBF001C */  sw        $ra, 0x1c($sp)
/* 803F10 80243690 AFB20018 */  sw        $s2, 0x18($sp)
/* 803F14 80243694 AFB00010 */  sw        $s0, 0x10($sp)
/* 803F18 80243698 8E30000C */  lw        $s0, 0xc($s1)
/* 803F1C 8024369C 8E050000 */  lw        $a1, ($s0)
/* 803F20 802436A0 0C0B210B */  jal       get_float_variable
/* 803F24 802436A4 26100004 */   addiu    $s0, $s0, 4
/* 803F28 802436A8 8E050000 */  lw        $a1, ($s0)
/* 803F2C 802436AC 26100004 */  addiu     $s0, $s0, 4
/* 803F30 802436B0 4600008D */  trunc.w.s $f2, $f0
/* 803F34 802436B4 44121000 */  mfc1      $s2, $f2
/* 803F38 802436B8 0C0B210B */  jal       get_float_variable
/* 803F3C 802436BC 0220202D */   daddu    $a0, $s1, $zero
/* 803F40 802436C0 0220202D */  daddu     $a0, $s1, $zero
/* 803F44 802436C4 8E050000 */  lw        $a1, ($s0)
/* 803F48 802436C8 4600008D */  trunc.w.s $f2, $f0
/* 803F4C 802436CC 44111000 */  mfc1      $s1, $f2
/* 803F50 802436D0 0C0B210B */  jal       get_float_variable
/* 803F54 802436D4 00000000 */   nop
/* 803F58 802436D8 0000202D */  daddu     $a0, $zero, $zero
/* 803F5C 802436DC 3C05FD05 */  lui       $a1, 0xfd05
/* 803F60 802436E0 4600008D */  trunc.w.s $f2, $f0
/* 803F64 802436E4 44101000 */  mfc1      $s0, $f2
/* 803F68 802436E8 0C0B1EAF */  jal       get_variable
/* 803F6C 802436EC 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 803F70 802436F0 0040182D */  daddu     $v1, $v0, $zero
/* 803F74 802436F4 44920000 */  mtc1      $s2, $f0
/* 803F78 802436F8 00000000 */  nop
/* 803F7C 802436FC 46800020 */  cvt.s.w   $f0, $f0
/* 803F80 80243700 E4600028 */  swc1      $f0, 0x28($v1)
/* 803F84 80243704 44910000 */  mtc1      $s1, $f0
/* 803F88 80243708 00000000 */  nop
/* 803F8C 8024370C 46800020 */  cvt.s.w   $f0, $f0
/* 803F90 80243710 E460002C */  swc1      $f0, 0x2c($v1)
/* 803F94 80243714 44900000 */  mtc1      $s0, $f0
/* 803F98 80243718 00000000 */  nop
/* 803F9C 8024371C 46800020 */  cvt.s.w   $f0, $f0
/* 803FA0 80243720 E4600030 */  swc1      $f0, 0x30($v1)
/* 803FA4 80243724 8FBF001C */  lw        $ra, 0x1c($sp)
/* 803FA8 80243728 8FB20018 */  lw        $s2, 0x18($sp)
/* 803FAC 8024372C 8FB10014 */  lw        $s1, 0x14($sp)
/* 803FB0 80243730 8FB00010 */  lw        $s0, 0x10($sp)
/* 803FB4 80243734 24020002 */  addiu     $v0, $zero, 2
/* 803FB8 80243738 03E00008 */  jr        $ra
/* 803FBC 8024373C 27BD0020 */   addiu    $sp, $sp, 0x20
