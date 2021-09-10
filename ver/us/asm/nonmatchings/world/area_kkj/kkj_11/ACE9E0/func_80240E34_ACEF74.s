.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E34_ACEF74
/* ACEF74 80240E34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ACEF78 80240E38 AFB10014 */  sw        $s1, 0x14($sp)
/* ACEF7C 80240E3C 0080882D */  daddu     $s1, $a0, $zero
/* ACEF80 80240E40 AFBF0024 */  sw        $ra, 0x24($sp)
/* ACEF84 80240E44 AFB40020 */  sw        $s4, 0x20($sp)
/* ACEF88 80240E48 AFB3001C */  sw        $s3, 0x1c($sp)
/* ACEF8C 80240E4C AFB20018 */  sw        $s2, 0x18($sp)
/* ACEF90 80240E50 AFB00010 */  sw        $s0, 0x10($sp)
/* ACEF94 80240E54 8E30000C */  lw        $s0, 0xc($s1)
/* ACEF98 80240E58 8E140000 */  lw        $s4, ($s0)
/* ACEF9C 80240E5C 26100004 */  addiu     $s0, $s0, 4
/* ACEFA0 80240E60 8E050000 */  lw        $a1, ($s0)
/* ACEFA4 80240E64 0C0B1EAF */  jal       evt_get_variable
/* ACEFA8 80240E68 26100004 */   addiu    $s0, $s0, 4
/* ACEFAC 80240E6C 8E050000 */  lw        $a1, ($s0)
/* ACEFB0 80240E70 26100004 */  addiu     $s0, $s0, 4
/* ACEFB4 80240E74 0220202D */  daddu     $a0, $s1, $zero
/* ACEFB8 80240E78 0C0B1EAF */  jal       evt_get_variable
/* ACEFBC 80240E7C 0040982D */   daddu    $s3, $v0, $zero
/* ACEFC0 80240E80 8E050000 */  lw        $a1, ($s0)
/* ACEFC4 80240E84 26100004 */  addiu     $s0, $s0, 4
/* ACEFC8 80240E88 0220202D */  daddu     $a0, $s1, $zero
/* ACEFCC 80240E8C 0C0B1EAF */  jal       evt_get_variable
/* ACEFD0 80240E90 0040902D */   daddu    $s2, $v0, $zero
/* ACEFD4 80240E94 0220202D */  daddu     $a0, $s1, $zero
/* ACEFD8 80240E98 8E050000 */  lw        $a1, ($s0)
/* ACEFDC 80240E9C 0C0B1EAF */  jal       evt_get_variable
/* ACEFE0 80240EA0 0040802D */   daddu    $s0, $v0, $zero
/* ACEFE4 80240EA4 44901000 */  mtc1      $s0, $f2
/* ACEFE8 80240EA8 00000000 */  nop
/* ACEFEC 80240EAC 468010A0 */  cvt.s.w   $f2, $f2
/* ACEFF0 80240EB0 44936000 */  mtc1      $s3, $f12
/* ACEFF4 80240EB4 00000000 */  nop
/* ACEFF8 80240EB8 46806320 */  cvt.s.w   $f12, $f12
/* ACEFFC 80240EBC 44061000 */  mfc1      $a2, $f2
/* ACF000 80240EC0 44821000 */  mtc1      $v0, $f2
/* ACF004 80240EC4 00000000 */  nop
/* ACF008 80240EC8 468010A0 */  cvt.s.w   $f2, $f2
/* ACF00C 80240ECC 44071000 */  mfc1      $a3, $f2
/* ACF010 80240ED0 44927000 */  mtc1      $s2, $f14
/* ACF014 80240ED4 00000000 */  nop
/* ACF018 80240ED8 0C00A720 */  jal       atan2
/* ACF01C 80240EDC 468073A0 */   cvt.s.w  $f14, $f14
/* ACF020 80240EE0 0220202D */  daddu     $a0, $s1, $zero
/* ACF024 80240EE4 4600008D */  trunc.w.s $f2, $f0
/* ACF028 80240EE8 44061000 */  mfc1      $a2, $f2
/* ACF02C 80240EEC 0C0B2026 */  jal       evt_set_variable
/* ACF030 80240EF0 0280282D */   daddu    $a1, $s4, $zero
/* ACF034 80240EF4 8FBF0024 */  lw        $ra, 0x24($sp)
/* ACF038 80240EF8 8FB40020 */  lw        $s4, 0x20($sp)
/* ACF03C 80240EFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* ACF040 80240F00 8FB20018 */  lw        $s2, 0x18($sp)
/* ACF044 80240F04 8FB10014 */  lw        $s1, 0x14($sp)
/* ACF048 80240F08 8FB00010 */  lw        $s0, 0x10($sp)
/* ACF04C 80240F0C 24020002 */  addiu     $v0, $zero, 2
/* ACF050 80240F10 03E00008 */  jr        $ra
/* ACF054 80240F14 27BD0028 */   addiu    $sp, $sp, 0x28
