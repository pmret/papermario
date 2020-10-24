.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DE8_9D9E08
/* 9D9E08 80242DE8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D9E0C 80242DEC AFB1001C */  sw        $s1, 0x1c($sp)
/* 9D9E10 80242DF0 0080882D */  daddu     $s1, $a0, $zero
/* 9D9E14 80242DF4 AFBF0034 */  sw        $ra, 0x34($sp)
/* 9D9E18 80242DF8 AFB60030 */  sw        $s6, 0x30($sp)
/* 9D9E1C 80242DFC AFB5002C */  sw        $s5, 0x2c($sp)
/* 9D9E20 80242E00 AFB40028 */  sw        $s4, 0x28($sp)
/* 9D9E24 80242E04 AFB30024 */  sw        $s3, 0x24($sp)
/* 9D9E28 80242E08 AFB20020 */  sw        $s2, 0x20($sp)
/* 9D9E2C 80242E0C AFB00018 */  sw        $s0, 0x18($sp)
/* 9D9E30 80242E10 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 9D9E34 80242E14 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9D9E38 80242E18 8E30000C */  lw        $s0, 0xc($s1)
/* 9D9E3C 80242E1C 8E160000 */  lw        $s6, ($s0)
/* 9D9E40 80242E20 26100004 */  addiu     $s0, $s0, 4
/* 9D9E44 80242E24 0C0B1EAF */  jal       get_variable
/* 9D9E48 80242E28 02C0282D */   daddu    $a1, $s6, $zero
/* 9D9E4C 80242E2C 44820000 */  mtc1      $v0, $f0
/* 9D9E50 80242E30 00000000 */  nop       
/* 9D9E54 80242E34 46800020 */  cvt.s.w   $f0, $f0
/* 9D9E58 80242E38 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9D9E5C 80242E3C 8E140000 */  lw        $s4, ($s0)
/* 9D9E60 80242E40 26100004 */  addiu     $s0, $s0, 4
/* 9D9E64 80242E44 0220202D */  daddu     $a0, $s1, $zero
/* 9D9E68 80242E48 0C0B1EAF */  jal       get_variable
/* 9D9E6C 80242E4C 0280282D */   daddu    $a1, $s4, $zero
/* 9D9E70 80242E50 0220202D */  daddu     $a0, $s1, $zero
/* 9D9E74 80242E54 8E150000 */  lw        $s5, ($s0)
/* 9D9E78 80242E58 4482B000 */  mtc1      $v0, $f22
/* 9D9E7C 80242E5C 00000000 */  nop       
/* 9D9E80 80242E60 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9D9E84 80242E64 0C0B1EAF */  jal       get_variable
/* 9D9E88 80242E68 02A0282D */   daddu    $a1, $s5, $zero
/* 9D9E8C 80242E6C 2404FFFC */  addiu     $a0, $zero, -4
/* 9D9E90 80242E70 44820000 */  mtc1      $v0, $f0
/* 9D9E94 80242E74 00000000 */  nop       
/* 9D9E98 80242E78 46800020 */  cvt.s.w   $f0, $f0
/* 9D9E9C 80242E7C 0C00EABB */  jal       get_npc_unsafe
/* 9D9EA0 80242E80 E7A00014 */   swc1     $f0, 0x14($sp)
/* 9D9EA4 80242E84 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 9D9EA8 80242E88 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 9D9EAC 80242E8C 3C014334 */  lui       $at, 0x4334
/* 9D9EB0 80242E90 44816000 */  mtc1      $at, $f12
/* 9D9EB4 80242E94 00041880 */  sll       $v1, $a0, 2
/* 9D9EB8 80242E98 00641821 */  addu      $v1, $v1, $a0
/* 9D9EBC 80242E9C 00031880 */  sll       $v1, $v1, 2
/* 9D9EC0 80242EA0 00641823 */  subu      $v1, $v1, $a0
/* 9D9EC4 80242EA4 000320C0 */  sll       $a0, $v1, 3
/* 9D9EC8 80242EA8 00641821 */  addu      $v1, $v1, $a0
/* 9D9ECC 80242EAC 000318C0 */  sll       $v1, $v1, 3
/* 9D9ED0 80242EB0 3C01800B */  lui       $at, 0x800b
/* 9D9ED4 80242EB4 00230821 */  addu      $at, $at, $v1
/* 9D9ED8 80242EB8 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 9D9EDC 80242EBC 460C0300 */  add.s     $f12, $f0, $f12
/* 9D9EE0 80242EC0 0C00A6C9 */  jal       clamp_angle
/* 9D9EE4 80242EC4 0040982D */   daddu    $s3, $v0, $zero
/* 9D9EE8 80242EC8 27B00010 */  addiu     $s0, $sp, 0x10
/* 9D9EEC 80242ECC 0200202D */  daddu     $a0, $s0, $zero
/* 9D9EF0 80242ED0 27B20014 */  addiu     $s2, $sp, 0x14
/* 9D9EF4 80242ED4 0240282D */  daddu     $a1, $s2, $zero
/* 9D9EF8 80242ED8 3C064170 */  lui       $a2, 0x4170
/* 9D9EFC 80242EDC 8E67000C */  lw        $a3, 0xc($s3)
/* 9D9F00 80242EE0 0C00A7E7 */  jal       add_vec2D_polar
/* 9D9F04 80242EE4 46000506 */   mov.s    $f20, $f0
/* 9D9F08 80242EE8 0200202D */  daddu     $a0, $s0, $zero
/* 9D9F0C 80242EEC 3C064120 */  lui       $a2, 0x4120
/* 9D9F10 80242EF0 4407A000 */  mfc1      $a3, $f20
/* 9D9F14 80242EF4 0C00A7E7 */  jal       add_vec2D_polar
/* 9D9F18 80242EF8 0240282D */   daddu    $a1, $s2, $zero
/* 9D9F1C 80242EFC 0220202D */  daddu     $a0, $s1, $zero
/* 9D9F20 80242F00 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 9D9F24 80242F04 4600008D */  trunc.w.s $f2, $f0
/* 9D9F28 80242F08 44061000 */  mfc1      $a2, $f2
/* 9D9F2C 80242F0C 0C0B2026 */  jal       set_variable
/* 9D9F30 80242F10 02C0282D */   daddu    $a1, $s6, $zero
/* 9D9F34 80242F14 0220202D */  daddu     $a0, $s1, $zero
/* 9D9F38 80242F18 4600B08D */  trunc.w.s $f2, $f22
/* 9D9F3C 80242F1C 44061000 */  mfc1      $a2, $f2
/* 9D9F40 80242F20 0C0B2026 */  jal       set_variable
/* 9D9F44 80242F24 0280282D */   daddu    $a1, $s4, $zero
/* 9D9F48 80242F28 0220202D */  daddu     $a0, $s1, $zero
/* 9D9F4C 80242F2C C7A00014 */  lwc1      $f0, 0x14($sp)
/* 9D9F50 80242F30 4600008D */  trunc.w.s $f2, $f0
/* 9D9F54 80242F34 44061000 */  mfc1      $a2, $f2
/* 9D9F58 80242F38 0C0B2026 */  jal       set_variable
/* 9D9F5C 80242F3C 02A0282D */   daddu    $a1, $s5, $zero
/* 9D9F60 80242F40 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9D9F64 80242F44 8FB60030 */  lw        $s6, 0x30($sp)
/* 9D9F68 80242F48 8FB5002C */  lw        $s5, 0x2c($sp)
/* 9D9F6C 80242F4C 8FB40028 */  lw        $s4, 0x28($sp)
/* 9D9F70 80242F50 8FB30024 */  lw        $s3, 0x24($sp)
/* 9D9F74 80242F54 8FB20020 */  lw        $s2, 0x20($sp)
/* 9D9F78 80242F58 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9D9F7C 80242F5C 8FB00018 */  lw        $s0, 0x18($sp)
/* 9D9F80 80242F60 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 9D9F84 80242F64 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 9D9F88 80242F68 24020002 */  addiu     $v0, $zero, 2
/* 9D9F8C 80242F6C 03E00008 */  jr        $ra
/* 9D9F90 80242F70 27BD0048 */   addiu    $sp, $sp, 0x48
