.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E34_ACB954
/* ACB954 80240E34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ACB958 80240E38 AFB10014 */  sw        $s1, 0x14($sp)
/* ACB95C 80240E3C 0080882D */  daddu     $s1, $a0, $zero
/* ACB960 80240E40 AFBF0024 */  sw        $ra, 0x24($sp)
/* ACB964 80240E44 AFB40020 */  sw        $s4, 0x20($sp)
/* ACB968 80240E48 AFB3001C */  sw        $s3, 0x1c($sp)
/* ACB96C 80240E4C AFB20018 */  sw        $s2, 0x18($sp)
/* ACB970 80240E50 AFB00010 */  sw        $s0, 0x10($sp)
/* ACB974 80240E54 8E30000C */  lw        $s0, 0xc($s1)
/* ACB978 80240E58 8E140000 */  lw        $s4, ($s0)
/* ACB97C 80240E5C 26100004 */  addiu     $s0, $s0, 4
/* ACB980 80240E60 8E050000 */  lw        $a1, ($s0)
/* ACB984 80240E64 0C0B1EAF */  jal       evt_get_variable
/* ACB988 80240E68 26100004 */   addiu    $s0, $s0, 4
/* ACB98C 80240E6C 8E050000 */  lw        $a1, ($s0)
/* ACB990 80240E70 26100004 */  addiu     $s0, $s0, 4
/* ACB994 80240E74 0220202D */  daddu     $a0, $s1, $zero
/* ACB998 80240E78 0C0B1EAF */  jal       evt_get_variable
/* ACB99C 80240E7C 0040982D */   daddu    $s3, $v0, $zero
/* ACB9A0 80240E80 8E050000 */  lw        $a1, ($s0)
/* ACB9A4 80240E84 26100004 */  addiu     $s0, $s0, 4
/* ACB9A8 80240E88 0220202D */  daddu     $a0, $s1, $zero
/* ACB9AC 80240E8C 0C0B1EAF */  jal       evt_get_variable
/* ACB9B0 80240E90 0040902D */   daddu    $s2, $v0, $zero
/* ACB9B4 80240E94 0220202D */  daddu     $a0, $s1, $zero
/* ACB9B8 80240E98 8E050000 */  lw        $a1, ($s0)
/* ACB9BC 80240E9C 0C0B1EAF */  jal       evt_get_variable
/* ACB9C0 80240EA0 0040802D */   daddu    $s0, $v0, $zero
/* ACB9C4 80240EA4 44901000 */  mtc1      $s0, $f2
/* ACB9C8 80240EA8 00000000 */  nop
/* ACB9CC 80240EAC 468010A0 */  cvt.s.w   $f2, $f2
/* ACB9D0 80240EB0 44936000 */  mtc1      $s3, $f12
/* ACB9D4 80240EB4 00000000 */  nop
/* ACB9D8 80240EB8 46806320 */  cvt.s.w   $f12, $f12
/* ACB9DC 80240EBC 44061000 */  mfc1      $a2, $f2
/* ACB9E0 80240EC0 44821000 */  mtc1      $v0, $f2
/* ACB9E4 80240EC4 00000000 */  nop
/* ACB9E8 80240EC8 468010A0 */  cvt.s.w   $f2, $f2
/* ACB9EC 80240ECC 44071000 */  mfc1      $a3, $f2
/* ACB9F0 80240ED0 44927000 */  mtc1      $s2, $f14
/* ACB9F4 80240ED4 00000000 */  nop
/* ACB9F8 80240ED8 0C00A720 */  jal       atan2
/* ACB9FC 80240EDC 468073A0 */   cvt.s.w  $f14, $f14
/* ACBA00 80240EE0 0220202D */  daddu     $a0, $s1, $zero
/* ACBA04 80240EE4 4600008D */  trunc.w.s $f2, $f0
/* ACBA08 80240EE8 44061000 */  mfc1      $a2, $f2
/* ACBA0C 80240EEC 0C0B2026 */  jal       evt_set_variable
/* ACBA10 80240EF0 0280282D */   daddu    $a1, $s4, $zero
/* ACBA14 80240EF4 8FBF0024 */  lw        $ra, 0x24($sp)
/* ACBA18 80240EF8 8FB40020 */  lw        $s4, 0x20($sp)
/* ACBA1C 80240EFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* ACBA20 80240F00 8FB20018 */  lw        $s2, 0x18($sp)
/* ACBA24 80240F04 8FB10014 */  lw        $s1, 0x14($sp)
/* ACBA28 80240F08 8FB00010 */  lw        $s0, 0x10($sp)
/* ACBA2C 80240F0C 24020002 */  addiu     $v0, $zero, 2
/* ACBA30 80240F10 03E00008 */  jr        $ra
/* ACBA34 80240F14 27BD0028 */   addiu    $sp, $sp, 0x28
