.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E88
/* 95E088 80242E88 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 95E08C 80242E8C AFB1001C */  sw        $s1, 0x1c($sp)
/* 95E090 80242E90 0080882D */  daddu     $s1, $a0, $zero
/* 95E094 80242E94 AFBF0034 */  sw        $ra, 0x34($sp)
/* 95E098 80242E98 AFB60030 */  sw        $s6, 0x30($sp)
/* 95E09C 80242E9C AFB5002C */  sw        $s5, 0x2c($sp)
/* 95E0A0 80242EA0 AFB40028 */  sw        $s4, 0x28($sp)
/* 95E0A4 80242EA4 AFB30024 */  sw        $s3, 0x24($sp)
/* 95E0A8 80242EA8 AFB20020 */  sw        $s2, 0x20($sp)
/* 95E0AC 80242EAC AFB00018 */  sw        $s0, 0x18($sp)
/* 95E0B0 80242EB0 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 95E0B4 80242EB4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 95E0B8 80242EB8 8E30000C */  lw        $s0, 0xc($s1)
/* 95E0BC 80242EBC 8E160000 */  lw        $s6, ($s0)
/* 95E0C0 80242EC0 26100004 */  addiu     $s0, $s0, 4
/* 95E0C4 80242EC4 0C0B1EAF */  jal       get_variable
/* 95E0C8 80242EC8 02C0282D */   daddu    $a1, $s6, $zero
/* 95E0CC 80242ECC 44820000 */  mtc1      $v0, $f0
/* 95E0D0 80242ED0 00000000 */  nop       
/* 95E0D4 80242ED4 46800020 */  cvt.s.w   $f0, $f0
/* 95E0D8 80242ED8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 95E0DC 80242EDC 8E140000 */  lw        $s4, ($s0)
/* 95E0E0 80242EE0 26100004 */  addiu     $s0, $s0, 4
/* 95E0E4 80242EE4 0220202D */  daddu     $a0, $s1, $zero
/* 95E0E8 80242EE8 0C0B1EAF */  jal       get_variable
/* 95E0EC 80242EEC 0280282D */   daddu    $a1, $s4, $zero
/* 95E0F0 80242EF0 0220202D */  daddu     $a0, $s1, $zero
/* 95E0F4 80242EF4 8E150000 */  lw        $s5, ($s0)
/* 95E0F8 80242EF8 4482B000 */  mtc1      $v0, $f22
/* 95E0FC 80242EFC 00000000 */  nop       
/* 95E100 80242F00 4680B5A0 */  cvt.s.w   $f22, $f22
/* 95E104 80242F04 0C0B1EAF */  jal       get_variable
/* 95E108 80242F08 02A0282D */   daddu    $a1, $s5, $zero
/* 95E10C 80242F0C 2404FFFC */  addiu     $a0, $zero, -4
/* 95E110 80242F10 44820000 */  mtc1      $v0, $f0
/* 95E114 80242F14 00000000 */  nop       
/* 95E118 80242F18 46800020 */  cvt.s.w   $f0, $f0
/* 95E11C 80242F1C 0C00EABB */  jal       get_npc_unsafe
/* 95E120 80242F20 E7A00014 */   swc1     $f0, 0x14($sp)
/* 95E124 80242F24 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 95E128 80242F28 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 95E12C 80242F2C 3C014334 */  lui       $at, 0x4334
/* 95E130 80242F30 44816000 */  mtc1      $at, $f12
/* 95E134 80242F34 00041880 */  sll       $v1, $a0, 2
/* 95E138 80242F38 00641821 */  addu      $v1, $v1, $a0
/* 95E13C 80242F3C 00031880 */  sll       $v1, $v1, 2
/* 95E140 80242F40 00641823 */  subu      $v1, $v1, $a0
/* 95E144 80242F44 000320C0 */  sll       $a0, $v1, 3
/* 95E148 80242F48 00641821 */  addu      $v1, $v1, $a0
/* 95E14C 80242F4C 000318C0 */  sll       $v1, $v1, 3
/* 95E150 80242F50 3C01800B */  lui       $at, 0x800b
/* 95E154 80242F54 00230821 */  addu      $at, $at, $v1
/* 95E158 80242F58 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 95E15C 80242F5C 460C0300 */  add.s     $f12, $f0, $f12
/* 95E160 80242F60 0C00A6C9 */  jal       clamp_angle
/* 95E164 80242F64 0040982D */   daddu    $s3, $v0, $zero
/* 95E168 80242F68 27B00010 */  addiu     $s0, $sp, 0x10
/* 95E16C 80242F6C 0200202D */  daddu     $a0, $s0, $zero
/* 95E170 80242F70 27B20014 */  addiu     $s2, $sp, 0x14
/* 95E174 80242F74 0240282D */  daddu     $a1, $s2, $zero
/* 95E178 80242F78 3C064170 */  lui       $a2, 0x4170
/* 95E17C 80242F7C 8E67000C */  lw        $a3, 0xc($s3)
/* 95E180 80242F80 0C00A7E7 */  jal       add_vec2D_polar
/* 95E184 80242F84 46000506 */   mov.s    $f20, $f0
/* 95E188 80242F88 0200202D */  daddu     $a0, $s0, $zero
/* 95E18C 80242F8C 3C064120 */  lui       $a2, 0x4120
/* 95E190 80242F90 4407A000 */  mfc1      $a3, $f20
/* 95E194 80242F94 0C00A7E7 */  jal       add_vec2D_polar
/* 95E198 80242F98 0240282D */   daddu    $a1, $s2, $zero
/* 95E19C 80242F9C 0220202D */  daddu     $a0, $s1, $zero
/* 95E1A0 80242FA0 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 95E1A4 80242FA4 4600008D */  trunc.w.s $f2, $f0
/* 95E1A8 80242FA8 44061000 */  mfc1      $a2, $f2
/* 95E1AC 80242FAC 0C0B2026 */  jal       set_variable
/* 95E1B0 80242FB0 02C0282D */   daddu    $a1, $s6, $zero
/* 95E1B4 80242FB4 0220202D */  daddu     $a0, $s1, $zero
/* 95E1B8 80242FB8 4600B08D */  trunc.w.s $f2, $f22
/* 95E1BC 80242FBC 44061000 */  mfc1      $a2, $f2
/* 95E1C0 80242FC0 0C0B2026 */  jal       set_variable
/* 95E1C4 80242FC4 0280282D */   daddu    $a1, $s4, $zero
/* 95E1C8 80242FC8 0220202D */  daddu     $a0, $s1, $zero
/* 95E1CC 80242FCC C7A00014 */  lwc1      $f0, 0x14($sp)
/* 95E1D0 80242FD0 4600008D */  trunc.w.s $f2, $f0
/* 95E1D4 80242FD4 44061000 */  mfc1      $a2, $f2
/* 95E1D8 80242FD8 0C0B2026 */  jal       set_variable
/* 95E1DC 80242FDC 02A0282D */   daddu    $a1, $s5, $zero
/* 95E1E0 80242FE0 8FBF0034 */  lw        $ra, 0x34($sp)
/* 95E1E4 80242FE4 8FB60030 */  lw        $s6, 0x30($sp)
/* 95E1E8 80242FE8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 95E1EC 80242FEC 8FB40028 */  lw        $s4, 0x28($sp)
/* 95E1F0 80242FF0 8FB30024 */  lw        $s3, 0x24($sp)
/* 95E1F4 80242FF4 8FB20020 */  lw        $s2, 0x20($sp)
/* 95E1F8 80242FF8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 95E1FC 80242FFC 8FB00018 */  lw        $s0, 0x18($sp)
/* 95E200 80243000 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 95E204 80243004 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 95E208 80243008 24020002 */  addiu     $v0, $zero, 2
/* 95E20C 8024300C 03E00008 */  jr        $ra
/* 95E210 80243010 27BD0048 */   addiu    $sp, $sp, 0x48
