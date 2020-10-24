.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E20_8036A0
/* 8036A0 80242E20 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8036A4 80242E24 AFB10014 */  sw        $s1, 0x14($sp)
/* 8036A8 80242E28 0080882D */  daddu     $s1, $a0, $zero
/* 8036AC 80242E2C AFB00010 */  sw        $s0, 0x10($sp)
/* 8036B0 80242E30 00A0802D */  daddu     $s0, $a1, $zero
/* 8036B4 80242E34 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8036B8 80242E38 AFB20018 */  sw        $s2, 0x18($sp)
/* 8036BC 80242E3C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8036C0 80242E40 0C00EABB */  jal       get_npc_unsafe
/* 8036C4 80242E44 2404FFFC */   addiu    $a0, $zero, -4
/* 8036C8 80242E48 12000017 */  beqz      $s0, .L80242EA8
/* 8036CC 80242E4C 0040902D */   daddu    $s2, $v0, $zero
/* 8036D0 80242E50 0220202D */  daddu     $a0, $s1, $zero
/* 8036D4 80242E54 3C05FE36 */  lui       $a1, 0xfe36
/* 8036D8 80242E58 0C0B210B */  jal       get_float_variable
/* 8036DC 80242E5C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8036E0 80242E60 0220202D */  daddu     $a0, $s1, $zero
/* 8036E4 80242E64 3C05FE36 */  lui       $a1, 0xfe36
/* 8036E8 80242E68 3C014270 */  lui       $at, 0x4270
/* 8036EC 80242E6C 4481A000 */  mtc1      $at, $f20
/* 8036F0 80242E70 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 8036F4 80242E74 46140003 */  div.s     $f0, $f0, $f20
/* 8036F8 80242E78 0C0B210B */  jal       get_float_variable
/* 8036FC 80242E7C E6200074 */   swc1     $f0, 0x74($s1)
/* 803700 80242E80 0220202D */  daddu     $a0, $s1, $zero
/* 803704 80242E84 3C05FE36 */  lui       $a1, 0xfe36
/* 803708 80242E88 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 80370C 80242E8C 46140003 */  div.s     $f0, $f0, $f20
/* 803710 80242E90 0C0B210B */  jal       get_float_variable
/* 803714 80242E94 E6200078 */   swc1     $f0, 0x78($s1)
/* 803718 80242E98 46140003 */  div.s     $f0, $f0, $f20
/* 80371C 80242E9C 2402003C */  addiu     $v0, $zero, 0x3c
/* 803720 80242EA0 E620007C */  swc1      $f0, 0x7c($s1)
/* 803724 80242EA4 AE220070 */  sw        $v0, 0x70($s1)
.L80242EA8:
/* 803728 80242EA8 C6400038 */  lwc1      $f0, 0x38($s2)
/* 80372C 80242EAC C6220074 */  lwc1      $f2, 0x74($s1)
/* 803730 80242EB0 46020000 */  add.s     $f0, $f0, $f2
/* 803734 80242EB4 E6400038 */  swc1      $f0, 0x38($s2)
/* 803738 80242EB8 C640003C */  lwc1      $f0, 0x3c($s2)
/* 80373C 80242EBC C6220078 */  lwc1      $f2, 0x78($s1)
/* 803740 80242EC0 46020000 */  add.s     $f0, $f0, $f2
/* 803744 80242EC4 E640003C */  swc1      $f0, 0x3c($s2)
/* 803748 80242EC8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 80374C 80242ECC C622007C */  lwc1      $f2, 0x7c($s1)
/* 803750 80242ED0 46020000 */  add.s     $f0, $f0, $f2
/* 803754 80242ED4 E6400040 */  swc1      $f0, 0x40($s2)
/* 803758 80242ED8 8E230070 */  lw        $v1, 0x70($s1)
/* 80375C 80242EDC 2463FFFF */  addiu     $v1, $v1, -1
/* 803760 80242EE0 2C620001 */  sltiu     $v0, $v1, 1
/* 803764 80242EE4 AE230070 */  sw        $v1, 0x70($s1)
/* 803768 80242EE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 80376C 80242EEC 8FB20018 */  lw        $s2, 0x18($sp)
/* 803770 80242EF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 803774 80242EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 803778 80242EF8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 80377C 80242EFC 00021040 */  sll       $v0, $v0, 1
/* 803780 80242F00 03E00008 */  jr        $ra
/* 803784 80242F04 27BD0028 */   addiu    $sp, $sp, 0x28
