.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021823C_4F7E1C
/* 4F7E1C 8021823C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4F7E20 80218240 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7E24 80218244 0080882D */  daddu     $s1, $a0, $zero
/* 4F7E28 80218248 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4F7E2C 8021824C AFB40020 */  sw        $s4, 0x20($sp)
/* 4F7E30 80218250 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7E34 80218254 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7E38 80218258 AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7E3C 8021825C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 4F7E40 80218260 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 4F7E44 80218264 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7E48 80218268 8E050000 */  lw        $a1, ($s0)
/* 4F7E4C 8021826C 0C0B1EAF */  jal       get_variable
/* 4F7E50 80218270 26100004 */   addiu    $s0, $s0, 4
/* 4F7E54 80218274 8E050000 */  lw        $a1, ($s0)
/* 4F7E58 80218278 26100004 */  addiu     $s0, $s0, 4
/* 4F7E5C 8021827C 0220202D */  daddu     $a0, $s1, $zero
/* 4F7E60 80218280 0C0B1EAF */  jal       get_variable
/* 4F7E64 80218284 0040982D */   daddu    $s3, $v0, $zero
/* 4F7E68 80218288 8E050000 */  lw        $a1, ($s0)
/* 4F7E6C 8021828C 26100004 */  addiu     $s0, $s0, 4
/* 4F7E70 80218290 0220202D */  daddu     $a0, $s1, $zero
/* 4F7E74 80218294 0C0B1EAF */  jal       get_variable
/* 4F7E78 80218298 0040A02D */   daddu    $s4, $v0, $zero
/* 4F7E7C 8021829C 0220202D */  daddu     $a0, $s1, $zero
/* 4F7E80 802182A0 8E050000 */  lw        $a1, ($s0)
/* 4F7E84 802182A4 0C0B1EAF */  jal       get_variable
/* 4F7E88 802182A8 0040902D */   daddu    $s2, $v0, $zero
/* 4F7E8C 802182AC 4482A000 */  mtc1      $v0, $f20
/* 4F7E90 802182B0 00000000 */  nop       
/* 4F7E94 802182B4 4680A520 */  cvt.s.w   $f20, $f20
/* 4F7E98 802182B8 0C00A8D4 */  jal       cos_deg
/* 4F7E9C 802182BC 4600A306 */   mov.s    $f12, $f20
/* 4F7EA0 802182C0 4492B000 */  mtc1      $s2, $f22
/* 4F7EA4 802182C4 00000000 */  nop       
/* 4F7EA8 802182C8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 4F7EAC 802182CC 4600B002 */  mul.s     $f0, $f22, $f0
/* 4F7EB0 802182D0 00000000 */  nop       
/* 4F7EB4 802182D4 4600A306 */  mov.s     $f12, $f20
/* 4F7EB8 802182D8 4493A000 */  mtc1      $s3, $f20
/* 4F7EBC 802182DC 00000000 */  nop       
/* 4F7EC0 802182E0 4680A520 */  cvt.s.w   $f20, $f20
/* 4F7EC4 802182E4 4600A500 */  add.s     $f20, $f20, $f0
/* 4F7EC8 802182E8 0C00A8BB */  jal       sin_deg
/* 4F7ECC 802182EC 26100004 */   addiu    $s0, $s0, 4
/* 4F7ED0 802182F0 4600B582 */  mul.s     $f22, $f22, $f0
/* 4F7ED4 802182F4 00000000 */  nop       
/* 4F7ED8 802182F8 8E050000 */  lw        $a1, ($s0)
/* 4F7EDC 802182FC 26100004 */  addiu     $s0, $s0, 4
/* 4F7EE0 80218300 0220202D */  daddu     $a0, $s1, $zero
/* 4F7EE4 80218304 4406A000 */  mfc1      $a2, $f20
/* 4F7EE8 80218308 4494A000 */  mtc1      $s4, $f20
/* 4F7EEC 8021830C 00000000 */  nop       
/* 4F7EF0 80218310 4680A520 */  cvt.s.w   $f20, $f20
/* 4F7EF4 80218314 0C0B2190 */  jal       set_float_variable
/* 4F7EF8 80218318 4616A501 */   sub.s    $f20, $f20, $f22
/* 4F7EFC 8021831C 8E050000 */  lw        $a1, ($s0)
/* 4F7F00 80218320 4406A000 */  mfc1      $a2, $f20
/* 4F7F04 80218324 0C0B2190 */  jal       set_float_variable
/* 4F7F08 80218328 0220202D */   daddu    $a0, $s1, $zero
/* 4F7F0C 8021832C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4F7F10 80218330 8FB40020 */  lw        $s4, 0x20($sp)
/* 4F7F14 80218334 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7F18 80218338 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7F1C 8021833C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7F20 80218340 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7F24 80218344 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 4F7F28 80218348 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 4F7F2C 8021834C 24020002 */  addiu     $v0, $zero, 2
/* 4F7F30 80218350 03E00008 */  jr        $ra
/* 4F7F34 80218354 27BD0038 */   addiu    $sp, $sp, 0x38
/* 4F7F38 80218358 00000000 */  nop       
/* 4F7F3C 8021835C 00000000 */  nop       
