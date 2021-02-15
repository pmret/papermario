.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E50_A2B090
/* A2B090 80240E50 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A2B094 80240E54 AFB10014 */  sw        $s1, 0x14($sp)
/* A2B098 80240E58 0080882D */  daddu     $s1, $a0, $zero
/* A2B09C 80240E5C AFBF0020 */  sw        $ra, 0x20($sp)
/* A2B0A0 80240E60 AFB3001C */  sw        $s3, 0x1c($sp)
/* A2B0A4 80240E64 AFB20018 */  sw        $s2, 0x18($sp)
/* A2B0A8 80240E68 AFB00010 */  sw        $s0, 0x10($sp)
/* A2B0AC 80240E6C 8E30000C */  lw        $s0, 0xc($s1)
/* A2B0B0 80240E70 8E050000 */  lw        $a1, ($s0)
/* A2B0B4 80240E74 0C0B1EAF */  jal       get_variable
/* A2B0B8 80240E78 26100004 */   addiu    $s0, $s0, 4
/* A2B0BC 80240E7C 8E050000 */  lw        $a1, ($s0)
/* A2B0C0 80240E80 26100004 */  addiu     $s0, $s0, 4
/* A2B0C4 80240E84 0220202D */  daddu     $a0, $s1, $zero
/* A2B0C8 80240E88 0C0B1EAF */  jal       get_variable
/* A2B0CC 80240E8C 0040902D */   daddu    $s2, $v0, $zero
/* A2B0D0 80240E90 8E050000 */  lw        $a1, ($s0)
/* A2B0D4 80240E94 26100004 */  addiu     $s0, $s0, 4
/* A2B0D8 80240E98 0C0B210B */  jal       get_float_variable
/* A2B0DC 80240E9C 0220202D */   daddu    $a0, $s1, $zero
/* A2B0E0 80240EA0 8E050000 */  lw        $a1, ($s0)
/* A2B0E4 80240EA4 26100004 */  addiu     $s0, $s0, 4
/* A2B0E8 80240EA8 4600010D */  trunc.w.s $f4, $f0
/* A2B0EC 80240EAC 44132000 */  mfc1      $s3, $f4
/* A2B0F0 80240EB0 0C0B210B */  jal       get_float_variable
/* A2B0F4 80240EB4 0220202D */   daddu    $a0, $s1, $zero
/* A2B0F8 80240EB8 8E050000 */  lw        $a1, ($s0)
/* A2B0FC 80240EBC 4600010D */  trunc.w.s $f4, $f0
/* A2B100 80240EC0 44102000 */  mfc1      $s0, $f4
/* A2B104 80240EC4 0C0B210B */  jal       get_float_variable
/* A2B108 80240EC8 0220202D */   daddu    $a0, $s1, $zero
/* A2B10C 80240ECC 8E43000C */  lw        $v1, 0xc($s2)
/* A2B110 80240ED0 44931000 */  mtc1      $s3, $f2
/* A2B114 80240ED4 00000000 */  nop
/* A2B118 80240ED8 468010A0 */  cvt.s.w   $f2, $f2
/* A2B11C 80240EDC E4620004 */  swc1      $f2, 4($v1)
/* A2B120 80240EE0 8E43000C */  lw        $v1, 0xc($s2)
/* A2B124 80240EE4 44901000 */  mtc1      $s0, $f2
/* A2B128 80240EE8 00000000 */  nop
/* A2B12C 80240EEC 468010A0 */  cvt.s.w   $f2, $f2
/* A2B130 80240EF0 E4620008 */  swc1      $f2, 8($v1)
/* A2B134 80240EF4 4600010D */  trunc.w.s $f4, $f0
/* A2B138 80240EF8 44032000 */  mfc1      $v1, $f4
/* A2B13C 80240EFC 8E44000C */  lw        $a0, 0xc($s2)
/* A2B140 80240F00 44830000 */  mtc1      $v1, $f0
/* A2B144 80240F04 00000000 */  nop
/* A2B148 80240F08 46800020 */  cvt.s.w   $f0, $f0
/* A2B14C 80240F0C E480000C */  swc1      $f0, 0xc($a0)
/* A2B150 80240F10 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2B154 80240F14 8FB3001C */  lw        $s3, 0x1c($sp)
/* A2B158 80240F18 8FB20018 */  lw        $s2, 0x18($sp)
/* A2B15C 80240F1C 8FB10014 */  lw        $s1, 0x14($sp)
/* A2B160 80240F20 8FB00010 */  lw        $s0, 0x10($sp)
/* A2B164 80240F24 24020002 */  addiu     $v0, $zero, 2
/* A2B168 80240F28 03E00008 */  jr        $ra
/* A2B16C 80240F2C 27BD0028 */   addiu    $sp, $sp, 0x28
