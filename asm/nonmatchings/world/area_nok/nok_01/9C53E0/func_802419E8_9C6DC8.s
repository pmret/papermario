.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419E8_9C6DC8
/* 9C6DC8 802419E8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9C6DCC 802419EC AFB20018 */  sw        $s2, 0x18($sp)
/* 9C6DD0 802419F0 0080902D */  daddu     $s2, $a0, $zero
/* 9C6DD4 802419F4 AFBF0030 */  sw        $ra, 0x30($sp)
/* 9C6DD8 802419F8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 9C6DDC 802419FC AFB60028 */  sw        $s6, 0x28($sp)
/* 9C6DE0 80241A00 AFB50024 */  sw        $s5, 0x24($sp)
/* 9C6DE4 80241A04 AFB40020 */  sw        $s4, 0x20($sp)
/* 9C6DE8 80241A08 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9C6DEC 80241A0C AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6DF0 80241A10 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6DF4 80241A14 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 9C6DF8 80241A18 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9C6DFC 80241A1C 8E50000C */  lw        $s0, 0xc($s2)
/* 9C6E00 80241A20 8E050000 */  lw        $a1, ($s0)
/* 9C6E04 80241A24 0C0B1EAF */  jal       get_variable
/* 9C6E08 80241A28 26100004 */   addiu    $s0, $s0, 4
/* 9C6E0C 80241A2C 8E050000 */  lw        $a1, ($s0)
/* 9C6E10 80241A30 26100004 */  addiu     $s0, $s0, 4
/* 9C6E14 80241A34 0240202D */  daddu     $a0, $s2, $zero
/* 9C6E18 80241A38 0C0B1EAF */  jal       get_variable
/* 9C6E1C 80241A3C 0040B82D */   daddu    $s7, $v0, $zero
/* 9C6E20 80241A40 8E050000 */  lw        $a1, ($s0)
/* 9C6E24 80241A44 26100004 */  addiu     $s0, $s0, 4
/* 9C6E28 80241A48 0240202D */  daddu     $a0, $s2, $zero
/* 9C6E2C 80241A4C 0C0B1EAF */  jal       get_variable
/* 9C6E30 80241A50 0040B02D */   daddu    $s6, $v0, $zero
/* 9C6E34 80241A54 0240202D */  daddu     $a0, $s2, $zero
/* 9C6E38 80241A58 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C6E3C 80241A5C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 9C6E40 80241A60 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* 9C6E44 80241A64 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* 9C6E48 80241A68 8E140000 */  lw        $s4, ($s0)
/* 9C6E4C 80241A6C 00061880 */  sll       $v1, $a2, 2
/* 9C6E50 80241A70 00661821 */  addu      $v1, $v1, $a2
/* 9C6E54 80241A74 00031880 */  sll       $v1, $v1, 2
/* 9C6E58 80241A78 00661823 */  subu      $v1, $v1, $a2
/* 9C6E5C 80241A7C 000330C0 */  sll       $a2, $v1, 3
/* 9C6E60 80241A80 00661821 */  addu      $v1, $v1, $a2
/* 9C6E64 80241A84 000318C0 */  sll       $v1, $v1, 3
/* 9C6E68 80241A88 3C01800B */  lui       $at, 0x800b
/* 9C6E6C 80241A8C 00230821 */  addu      $at, $at, $v1
/* 9C6E70 80241A90 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 9C6E74 80241A94 8E150004 */  lw        $s5, 4($s0)
/* 9C6E78 80241A98 4600010D */  trunc.w.s $f4, $f0
/* 9C6E7C 80241A9C 44112000 */  mfc1      $s1, $f4
/* 9C6E80 80241AA0 0C0B1EAF */  jal       get_variable
/* 9C6E84 80241AA4 0040982D */   daddu    $s3, $v0, $zero
/* 9C6E88 80241AA8 4491B000 */  mtc1      $s1, $f22
/* 9C6E8C 80241AAC 00000000 */  nop       
/* 9C6E90 80241AB0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9C6E94 80241AB4 4600B306 */  mov.s     $f12, $f22
/* 9C6E98 80241AB8 0C00A8D4 */  jal       cos_deg
/* 9C6E9C 80241ABC 0040802D */   daddu    $s0, $v0, $zero
/* 9C6EA0 80241AC0 4493A000 */  mtc1      $s3, $f20
/* 9C6EA4 80241AC4 00000000 */  nop       
/* 9C6EA8 80241AC8 4680A520 */  cvt.s.w   $f20, $f20
/* 9C6EAC 80241ACC 4600A002 */  mul.s     $f0, $f20, $f0
/* 9C6EB0 80241AD0 00000000 */  nop       
/* 9C6EB4 80241AD4 0240202D */  daddu     $a0, $s2, $zero
/* 9C6EB8 80241AD8 44901000 */  mtc1      $s0, $f2
/* 9C6EBC 80241ADC 00000000 */  nop       
/* 9C6EC0 80241AE0 468010A0 */  cvt.s.w   $f2, $f2
/* 9C6EC4 80241AE4 46001081 */  sub.s     $f2, $f2, $f0
/* 9C6EC8 80241AE8 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C6ECC 80241AEC 4600110D */  trunc.w.s $f4, $f2
/* 9C6ED0 80241AF0 44102000 */  mfc1      $s0, $f4
/* 9C6ED4 80241AF4 0C0B1EAF */  jal       get_variable
/* 9C6ED8 80241AF8 34A5D483 */   ori      $a1, $a1, 0xd483
/* 9C6EDC 80241AFC 4600B306 */  mov.s     $f12, $f22
/* 9C6EE0 80241B00 0C00A8BB */  jal       sin_deg
/* 9C6EE4 80241B04 0040882D */   daddu    $s1, $v0, $zero
/* 9C6EE8 80241B08 4600A502 */  mul.s     $f20, $f20, $f0
/* 9C6EEC 80241B0C 00000000 */  nop       
/* 9C6EF0 80241B10 0240202D */  daddu     $a0, $s2, $zero
/* 9C6EF4 80241B14 44910000 */  mtc1      $s1, $f0
/* 9C6EF8 80241B18 00000000 */  nop       
/* 9C6EFC 80241B1C 46800020 */  cvt.s.w   $f0, $f0
/* 9C6F00 80241B20 46140001 */  sub.s     $f0, $f0, $f20
/* 9C6F04 80241B24 0280282D */  daddu     $a1, $s4, $zero
/* 9C6F08 80241B28 02173023 */  subu      $a2, $s0, $s7
/* 9C6F0C 80241B2C 4600010D */  trunc.w.s $f4, $f0
/* 9C6F10 80241B30 44102000 */  mfc1      $s0, $f4
/* 9C6F14 80241B34 0C0B2026 */  jal       set_variable
/* 9C6F18 80241B38 02168023 */   subu     $s0, $s0, $s6
/* 9C6F1C 80241B3C 0240202D */  daddu     $a0, $s2, $zero
/* 9C6F20 80241B40 02A0282D */  daddu     $a1, $s5, $zero
/* 9C6F24 80241B44 0C0B2026 */  jal       set_variable
/* 9C6F28 80241B48 0200302D */   daddu    $a2, $s0, $zero
/* 9C6F2C 80241B4C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 9C6F30 80241B50 8FB7002C */  lw        $s7, 0x2c($sp)
/* 9C6F34 80241B54 8FB60028 */  lw        $s6, 0x28($sp)
/* 9C6F38 80241B58 8FB50024 */  lw        $s5, 0x24($sp)
/* 9C6F3C 80241B5C 8FB40020 */  lw        $s4, 0x20($sp)
/* 9C6F40 80241B60 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9C6F44 80241B64 8FB20018 */  lw        $s2, 0x18($sp)
/* 9C6F48 80241B68 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C6F4C 80241B6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C6F50 80241B70 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 9C6F54 80241B74 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 9C6F58 80241B78 24020002 */  addiu     $v0, $zero, 2
/* 9C6F5C 80241B7C 03E00008 */  jr        $ra
/* 9C6F60 80241B80 27BD0048 */   addiu    $sp, $sp, 0x48
