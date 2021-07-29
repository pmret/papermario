.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel npc_test_move_without_slipping
/* 76DAC 800DD8FC 27BDFF68 */  addiu     $sp, $sp, -0x98
/* 76DB0 800DD900 C7AC00AC */  lwc1      $f12, 0xac($sp)
/* 76DB4 800DD904 3C0140C9 */  lui       $at, 0x40c9
/* 76DB8 800DD908 34210FD0 */  ori       $at, $at, 0xfd0
/* 76DBC 800DD90C 44810000 */  mtc1      $at, $f0
/* 76DC0 800DD910 AFB10064 */  sw        $s1, 0x64($sp)
/* 76DC4 800DD914 0080882D */  daddu     $s1, $a0, $zero
/* 76DC8 800DD918 AFB3006C */  sw        $s3, 0x6c($sp)
/* 76DCC 800DD91C 00A0982D */  daddu     $s3, $a1, $zero
/* 76DD0 800DD920 AFB00060 */  sw        $s0, 0x60($sp)
/* 76DD4 800DD924 00C0802D */  daddu     $s0, $a2, $zero
/* 76DD8 800DD928 AFB40070 */  sw        $s4, 0x70($sp)
/* 76DDC 800DD92C 00E0A02D */  daddu     $s4, $a3, $zero
/* 76DE0 800DD930 F7B60080 */  sdc1      $f22, 0x80($sp)
/* 76DE4 800DD934 C7B600A8 */  lwc1      $f22, 0xa8($sp)
/* 76DE8 800DD938 27A50038 */  addiu     $a1, $sp, 0x38
/* 76DEC 800DD93C F7B40078 */  sdc1      $f20, 0x78($sp)
/* 76DF0 800DD940 C7B400B0 */  lwc1      $f20, 0xb0($sp)
/* 76DF4 800DD944 46006302 */  mul.s     $f12, $f12, $f0
/* 76DF8 800DD948 00000000 */  nop
/* 76DFC 800DD94C 3C0143B4 */  lui       $at, 0x43b4
/* 76E00 800DD950 44810000 */  mtc1      $at, $f0
/* 76E04 800DD954 27A6003C */  addiu     $a2, $sp, 0x3c
/* 76E08 800DD958 AFBF0074 */  sw        $ra, 0x74($sp)
/* 76E0C 800DD95C AFB20068 */  sw        $s2, 0x68($sp)
/* 76E10 800DD960 F7BA0090 */  sdc1      $f26, 0x90($sp)
/* 76E14 800DD964 F7B80088 */  sdc1      $f24, 0x88($sp)
/* 76E18 800DD968 0C00A82D */  jal       sin_cos_rad
/* 76E1C 800DD96C 46006303 */   div.s    $f12, $f12, $f0
/* 76E20 800DD970 3C013F00 */  lui       $at, 0x3f00
/* 76E24 800DD974 44813000 */  mtc1      $at, $f6
/* 76E28 800DD978 00000000 */  nop
/* 76E2C 800DD97C 4606A082 */  mul.s     $f2, $f20, $f6
/* 76E30 800DD980 00000000 */  nop
/* 76E34 800DD984 4614B000 */  add.s     $f0, $f22, $f20
/* 76E38 800DD988 46020600 */  add.s     $f24, $f0, $f2
/* 76E3C 800DD98C C7A00038 */  lwc1      $f0, 0x38($sp)
/* 76E40 800DD990 4600B682 */  mul.s     $f26, $f22, $f0
/* 76E44 800DD994 00000000 */  nop
/* 76E48 800DD998 2412FFFF */  addiu     $s2, $zero, -1
/* 76E4C 800DD99C 27A20040 */  addiu     $v0, $sp, 0x40
/* 76E50 800DD9A0 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 76E54 800DD9A4 46001087 */  neg.s     $f2, $f2
/* 76E58 800DD9A8 4600A102 */  mul.s     $f4, $f20, $f0
/* 76E5C 800DD9AC 00000000 */  nop
/* 76E60 800DD9B0 E7A2003C */  swc1      $f2, 0x3c($sp)
/* 76E64 800DD9B4 E7B8004C */  swc1      $f24, 0x4c($sp)
/* 76E68 800DD9B8 C6680000 */  lwc1      $f8, ($s3)
/* 76E6C 800DD9BC C68A0000 */  lwc1      $f10, ($s4)
/* 76E70 800DD9C0 4602A502 */  mul.s     $f20, $f20, $f2
/* 76E74 800DD9C4 00000000 */  nop
/* 76E78 800DD9C8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 76E7C 800DD9CC 27A20044 */  addiu     $v0, $sp, 0x44
/* 76E80 800DD9D0 AFA20020 */  sw        $v0, 0x20($sp)
/* 76E84 800DD9D4 27A20048 */  addiu     $v0, $sp, 0x48
/* 76E88 800DD9D8 AFA20024 */  sw        $v0, 0x24($sp)
/* 76E8C 800DD9DC 27A2004C */  addiu     $v0, $sp, 0x4c
/* 76E90 800DD9E0 46062102 */  mul.s     $f4, $f4, $f6
/* 76E94 800DD9E4 00000000 */  nop
/* 76E98 800DD9E8 AFA20028 */  sw        $v0, 0x28($sp)
/* 76E9C 800DD9EC 27A20050 */  addiu     $v0, $sp, 0x50
/* 76EA0 800DD9F0 AFA2002C */  sw        $v0, 0x2c($sp)
/* 76EA4 800DD9F4 27A20054 */  addiu     $v0, $sp, 0x54
/* 76EA8 800DD9F8 4606A502 */  mul.s     $f20, $f20, $f6
/* 76EAC 800DD9FC 00000000 */  nop
/* 76EB0 800DDA00 AFA20030 */  sw        $v0, 0x30($sp)
/* 76EB4 800DDA04 27A20058 */  addiu     $v0, $sp, 0x58
/* 76EB8 800DDA08 E7A00010 */  swc1      $f0, 0x10($sp)
/* 76EBC 800DDA0C AFA00014 */  sw        $zero, 0x14($sp)
/* 76EC0 800DDA10 46044201 */  sub.s     $f8, $f8, $f4
/* 76EC4 800DDA14 E7A20018 */  swc1      $f2, 0x18($sp)
/* 76EC8 800DDA18 AFA20034 */  sw        $v0, 0x34($sp)
/* 76ECC 800DDA1C 46145281 */  sub.s     $f10, $f10, $f20
/* 76ED0 800DDA20 8E060000 */  lw        $a2, ($s0)
/* 76ED4 800DDA24 44054000 */  mfc1      $a1, $f8
/* 76ED8 800DDA28 44075000 */  mfc1      $a3, $f10
/* 76EDC 800DDA2C 4602B582 */  mul.s     $f22, $f22, $f2
/* 76EE0 800DDA30 00000000 */  nop
/* 76EE4 800DDA34 0C037513 */  jal       npc_raycast_general
/* 76EE8 800DDA38 0220202D */   daddu    $a0, $s1, $zero
/* 76EEC 800DDA3C 04400016 */  bltz      $v0, .L800DDA98
/* 76EF0 800DDA40 00000000 */   nop
/* 76EF4 800DDA44 C7A4004C */  lwc1      $f4, 0x4c($sp)
/* 76EF8 800DDA48 4618203E */  c.le.s    $f4, $f24
/* 76EFC 800DDA4C 00000000 */  nop
/* 76F00 800DDA50 45000011 */  bc1f      .L800DDA98
/* 76F04 800DDA54 00000000 */   nop
/* 76F08 800DDA58 46182101 */  sub.s     $f4, $f4, $f24
/* 76F0C 800DDA5C C7A00038 */  lwc1      $f0, 0x38($sp)
/* 76F10 800DDA60 46002002 */  mul.s     $f0, $f4, $f0
/* 76F14 800DDA64 00000000 */  nop
/* 76F18 800DDA68 C6620000 */  lwc1      $f2, ($s3)
/* 76F1C 800DDA6C 46001080 */  add.s     $f2, $f2, $f0
/* 76F20 800DDA70 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 76F24 800DDA74 46002102 */  mul.s     $f4, $f4, $f0
/* 76F28 800DDA78 00000000 */  nop
/* 76F2C 800DDA7C E6620000 */  swc1      $f2, ($s3)
/* 76F30 800DDA80 C6800000 */  lwc1      $f0, ($s4)
/* 76F34 800DDA84 46040000 */  add.s     $f0, $f0, $f4
/* 76F38 800DDA88 0040902D */  daddu     $s2, $v0, $zero
/* 76F3C 800DDA8C E6800000 */  swc1      $f0, ($s4)
/* 76F40 800DDA90 3C018011 */  lui       $at, %hi(D_8010C978)
/* 76F44 800DDA94 AC32C978 */  sw        $s2, %lo(D_8010C978)($at)
.L800DDA98:
/* 76F48 800DDA98 C6600000 */  lwc1      $f0, ($s3)
/* 76F4C 800DDA9C 461A0000 */  add.s     $f0, $f0, $f26
/* 76F50 800DDAA0 E6600000 */  swc1      $f0, ($s3)
/* 76F54 800DDAA4 C6800000 */  lwc1      $f0, ($s4)
/* 76F58 800DDAA8 46160000 */  add.s     $f0, $f0, $f22
/* 76F5C 800DDAAC 0240102D */  daddu     $v0, $s2, $zero
/* 76F60 800DDAB0 E6800000 */  swc1      $f0, ($s4)
/* 76F64 800DDAB4 8FBF0074 */  lw        $ra, 0x74($sp)
/* 76F68 800DDAB8 8FB40070 */  lw        $s4, 0x70($sp)
/* 76F6C 800DDABC 8FB3006C */  lw        $s3, 0x6c($sp)
/* 76F70 800DDAC0 8FB20068 */  lw        $s2, 0x68($sp)
/* 76F74 800DDAC4 8FB10064 */  lw        $s1, 0x64($sp)
/* 76F78 800DDAC8 8FB00060 */  lw        $s0, 0x60($sp)
/* 76F7C 800DDACC D7BA0090 */  ldc1      $f26, 0x90($sp)
/* 76F80 800DDAD0 D7B80088 */  ldc1      $f24, 0x88($sp)
/* 76F84 800DDAD4 D7B60080 */  ldc1      $f22, 0x80($sp)
/* 76F88 800DDAD8 D7B40078 */  ldc1      $f20, 0x78($sp)
/* 76F8C 800DDADC 03E00008 */  jr        $ra
/* 76F90 800DDAE0 27BD0098 */   addiu    $sp, $sp, 0x98
