.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel do_camera_type_4
/* 9D10 8002E910 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D14 8002E914 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D18 8002E918 0080802D */  daddu     $s0, $a0, $zero
/* 9D1C 8002E91C AFBF0014 */  sw        $ra, 0x14($sp)
/* 9D20 8002E920 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* 9D24 8002E924 F7BC0038 */  sdc1      $f28, 0x38($sp)
/* 9D28 8002E928 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* 9D2C 8002E92C F7B80028 */  sdc1      $f24, 0x28($sp)
/* 9D30 8002E930 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 9D34 8002E934 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 9D38 8002E938 8602001C */  lh        $v0, 0x1c($s0)
/* 9D3C 8002E93C C6000060 */  lwc1      $f0, 0x60($s0)
/* 9D40 8002E940 4482B000 */  mtc1      $v0, $f22
/* 9D44 8002E944 00000000 */  nop
/* 9D48 8002E948 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9D4C 8002E94C 4600B03C */  c.lt.s    $f22, $f0
/* 9D50 8002E950 00000000 */  nop
/* 9D54 8002E954 45030001 */  bc1tl     .L8002E95C
/* 9D58 8002E958 4600B006 */   mov.s    $f0, $f22
.L8002E95C:
/* 9D5C 8002E95C 4600B107 */  neg.s     $f4, $f22
/* 9D60 8002E960 4604003C */  c.lt.s    $f0, $f4
/* 9D64 8002E964 00000000 */  nop
/* 9D68 8002E968 45030001 */  bc1tl     .L8002E970
/* 9D6C 8002E96C 46002006 */   mov.s    $f0, $f4
.L8002E970:
/* 9D70 8002E970 C6080068 */  lwc1      $f8, 0x68($s0)
/* 9D74 8002E974 8602001E */  lh        $v0, 0x1e($s0)
/* 9D78 8002E978 4482C000 */  mtc1      $v0, $f24
/* 9D7C 8002E97C 00000000 */  nop
/* 9D80 8002E980 4680C620 */  cvt.s.w   $f24, $f24
/* 9D84 8002E984 4608C03C */  c.lt.s    $f24, $f8
/* 9D88 8002E988 00000000 */  nop
/* 9D8C 8002E98C 45000002 */  bc1f      .L8002E998
/* 9D90 8002E990 E6000054 */   swc1     $f0, 0x54($s0)
/* 9D94 8002E994 4600C206 */  mov.s     $f8, $f24
.L8002E998:
/* 9D98 8002E998 4600C007 */  neg.s     $f0, $f24
/* 9D9C 8002E99C 4600403C */  c.lt.s    $f8, $f0
/* 9DA0 8002E9A0 00000000 */  nop
/* 9DA4 8002E9A4 45030001 */  bc1tl     .L8002E9AC
/* 9DA8 8002E9A8 46000206 */   mov.s    $f8, $f0
.L8002E9AC:
/* 9DAC 8002E9AC 86020020 */  lh        $v0, 0x20($s0)
/* 9DB0 8002E9B0 3C01800A */  lui       $at, %hi(D_8009A5EC)
/* 9DB4 8002E9B4 C424A5EC */  lwc1      $f4, %lo(D_8009A5EC)($at)
/* 9DB8 8002E9B8 AE000070 */  sw        $zero, 0x70($s0)
/* 9DBC 8002E9BC 44821000 */  mtc1      $v0, $f2
/* 9DC0 8002E9C0 00000000 */  nop
/* 9DC4 8002E9C4 468010A0 */  cvt.s.w   $f2, $f2
/* 9DC8 8002E9C8 46041082 */  mul.s     $f2, $f2, $f4
/* 9DCC 8002E9CC 00000000 */  nop
/* 9DD0 8002E9D0 86020022 */  lh        $v0, 0x22($s0)
/* 9DD4 8002E9D4 C6060070 */  lwc1      $f6, 0x70($s0)
/* 9DD8 8002E9D8 44820000 */  mtc1      $v0, $f0
/* 9DDC 8002E9DC 00000000 */  nop
/* 9DE0 8002E9E0 46800020 */  cvt.s.w   $f0, $f0
/* 9DE4 8002E9E4 86020006 */  lh        $v0, 6($s0)
/* 9DE8 8002E9E8 46040002 */  mul.s     $f0, $f0, $f4
/* 9DEC 8002E9EC 00000000 */  nop
/* 9DF0 8002E9F0 E608005C */  swc1      $f8, 0x5c($s0)
/* 9DF4 8002E9F4 AE000074 */  sw        $zero, 0x74($s0)
/* 9DF8 8002E9F8 E6060084 */  swc1      $f6, 0x84($s0)
/* 9DFC 8002E9FC E6020078 */  swc1      $f2, 0x78($s0)
/* 9E00 8002EA00 10400047 */  beqz      $v0, .L8002EB20
/* 9E04 8002EA04 E600007C */   swc1     $f0, 0x7c($s0)
/* 9E08 8002EA08 4480F000 */  mtc1      $zero, $f30
/* 9E0C 8002EA0C C6020074 */  lwc1      $f2, 0x74($s0)
/* 9E10 8002EA10 3C0140C9 */  lui       $at, 0x40c9
/* 9E14 8002EA14 34210FD0 */  ori       $at, $at, 0xfd0
/* 9E18 8002EA18 4481B000 */  mtc1      $at, $f22
/* 9E1C 8002EA1C C6080054 */  lwc1      $f8, 0x54($s0)
/* 9E20 8002EA20 C6000058 */  lwc1      $f0, 0x58($s0)
/* 9E24 8002EA24 C604007C */  lwc1      $f4, 0x7c($s0)
/* 9E28 8002EA28 C606005C */  lwc1      $f6, 0x5c($s0)
/* 9E2C 8002EA2C 3C0143B4 */  lui       $at, 0x43b4
/* 9E30 8002EA30 4481A000 */  mtc1      $at, $f20
/* 9E34 8002EA34 46161082 */  mul.s     $f2, $f2, $f22
/* 9E38 8002EA38 00000000 */  nop
/* 9E3C 8002EA3C A6000006 */  sh        $zero, 6($s0)
/* 9E40 8002EA40 E61E0098 */  swc1      $f30, 0x98($s0)
/* 9E44 8002EA44 E61E009C */  swc1      $f30, 0x9c($s0)
/* 9E48 8002EA48 46040000 */  add.s     $f0, $f0, $f4
/* 9E4C 8002EA4C E6080048 */  swc1      $f8, 0x48($s0)
/* 9E50 8002EA50 E6060050 */  swc1      $f6, 0x50($s0)
/* 9E54 8002EA54 E600004C */  swc1      $f0, 0x4c($s0)
/* 9E58 8002EA58 46141683 */  div.s     $f26, $f2, $f20
/* 9E5C 8002EA5C 0C00A85B */  jal       sin_rad
/* 9E60 8002EA60 4600D306 */   mov.s    $f12, $f26
/* 9E64 8002EA64 46000706 */  mov.s     $f28, $f0
/* 9E68 8002EA68 0C00A874 */  jal       cos_rad
/* 9E6C 8002EA6C 4600D306 */   mov.s    $f12, $f26
/* 9E70 8002EA70 46000286 */  mov.s     $f10, $f0
/* 9E74 8002EA74 461E5202 */  mul.s     $f8, $f10, $f30
/* 9E78 8002EA78 00000000 */  nop
/* 9E7C 8002EA7C 4600F087 */  neg.s     $f2, $f30
/* 9E80 8002EA80 4602E082 */  mul.s     $f2, $f28, $f2
/* 9E84 8002EA84 00000000 */  nop
/* 9E88 8002EA88 C6180078 */  lwc1      $f24, 0x78($s0)
/* 9E8C 8002EA8C 461CC102 */  mul.s     $f4, $f24, $f28
/* 9E90 8002EA90 00000000 */  nop
/* 9E94 8002EA94 460AC182 */  mul.s     $f6, $f24, $f10
/* 9E98 8002EA98 00000000 */  nop
/* 9E9C 8002EA9C C6000070 */  lwc1      $f0, 0x70($s0)
/* 9EA0 8002EAA0 46160002 */  mul.s     $f0, $f0, $f22
/* 9EA4 8002EAA4 00000000 */  nop
/* 9EA8 8002EAA8 4600F286 */  mov.s     $f10, $f30
/* 9EAC 8002EAAC 46005586 */  mov.s     $f22, $f10
/* 9EB0 8002EAB0 46044780 */  add.s     $f30, $f8, $f4
/* 9EB4 8002EAB4 46140683 */  div.s     $f26, $f0, $f20
/* 9EB8 8002EAB8 4600D306 */  mov.s     $f12, $f26
/* 9EBC 8002EABC 0C00A85B */  jal       sin_rad
/* 9EC0 8002EAC0 46061600 */   add.s    $f24, $f2, $f6
/* 9EC4 8002EAC4 46000706 */  mov.s     $f28, $f0
/* 9EC8 8002EAC8 0C00A874 */  jal       cos_rad
/* 9ECC 8002EACC 4600D306 */   mov.s    $f12, $f26
/* 9ED0 8002EAD0 46000286 */  mov.s     $f10, $f0
/* 9ED4 8002EAD4 46165182 */  mul.s     $f6, $f10, $f22
/* 9ED8 8002EAD8 00000000 */  nop
/* 9EDC 8002EADC 4616E102 */  mul.s     $f4, $f28, $f22
/* 9EE0 8002EAE0 00000000 */  nop
/* 9EE4 8002EAE4 461CC082 */  mul.s     $f2, $f24, $f28
/* 9EE8 8002EAE8 00000000 */  nop
/* 9EEC 8002EAEC 460AC002 */  mul.s     $f0, $f24, $f10
/* 9EF0 8002EAF0 00000000 */  nop
/* 9EF4 8002EAF4 46023281 */  sub.s     $f10, $f6, $f2
/* 9EF8 8002EAF8 46002180 */  add.s     $f6, $f4, $f0
/* 9EFC 8002EAFC C600004C */  lwc1      $f0, 0x4c($s0)
/* 9F00 8002EB00 461E0000 */  add.s     $f0, $f0, $f30
/* 9F04 8002EB04 C6040048 */  lwc1      $f4, 0x48($s0)
/* 9F08 8002EB08 460A2100 */  add.s     $f4, $f4, $f10
/* 9F0C 8002EB0C C6020050 */  lwc1      $f2, 0x50($s0)
/* 9F10 8002EB10 46061080 */  add.s     $f2, $f2, $f6
/* 9F14 8002EB14 E6000040 */  swc1      $f0, 0x40($s0)
/* 9F18 8002EB18 E604003C */  swc1      $f4, 0x3c($s0)
/* 9F1C 8002EB1C E6020044 */  swc1      $f2, 0x44($s0)
.L8002EB20:
/* 9F20 8002EB20 4480F000 */  mtc1      $zero, $f30
/* 9F24 8002EB24 C6020074 */  lwc1      $f2, 0x74($s0)
/* 9F28 8002EB28 3C0140C9 */  lui       $at, 0x40c9
/* 9F2C 8002EB2C 34210FD0 */  ori       $at, $at, 0xfd0
/* 9F30 8002EB30 4481B000 */  mtc1      $at, $f22
/* 9F34 8002EB34 C6080054 */  lwc1      $f8, 0x54($s0)
/* 9F38 8002EB38 46161082 */  mul.s     $f2, $f2, $f22
/* 9F3C 8002EB3C 00000000 */  nop
/* 9F40 8002EB40 C6000058 */  lwc1      $f0, 0x58($s0)
/* 9F44 8002EB44 C604007C */  lwc1      $f4, 0x7c($s0)
/* 9F48 8002EB48 C606005C */  lwc1      $f6, 0x5c($s0)
/* 9F4C 8002EB4C 3C0143B4 */  lui       $at, 0x43b4
/* 9F50 8002EB50 4481A000 */  mtc1      $at, $f20
/* 9F54 8002EB54 46040000 */  add.s     $f0, $f0, $f4
/* 9F58 8002EB58 E6080048 */  swc1      $f8, 0x48($s0)
/* 9F5C 8002EB5C E6060050 */  swc1      $f6, 0x50($s0)
/* 9F60 8002EB60 E600004C */  swc1      $f0, 0x4c($s0)
/* 9F64 8002EB64 46141683 */  div.s     $f26, $f2, $f20
/* 9F68 8002EB68 0C00A85B */  jal       sin_rad
/* 9F6C 8002EB6C 4600D306 */   mov.s    $f12, $f26
/* 9F70 8002EB70 46000706 */  mov.s     $f28, $f0
/* 9F74 8002EB74 0C00A874 */  jal       cos_rad
/* 9F78 8002EB78 4600D306 */   mov.s    $f12, $f26
/* 9F7C 8002EB7C 46000286 */  mov.s     $f10, $f0
/* 9F80 8002EB80 461E5202 */  mul.s     $f8, $f10, $f30
/* 9F84 8002EB84 00000000 */  nop
/* 9F88 8002EB88 4600F087 */  neg.s     $f2, $f30
/* 9F8C 8002EB8C 4602E082 */  mul.s     $f2, $f28, $f2
/* 9F90 8002EB90 00000000 */  nop
/* 9F94 8002EB94 C6180078 */  lwc1      $f24, 0x78($s0)
/* 9F98 8002EB98 461CC102 */  mul.s     $f4, $f24, $f28
/* 9F9C 8002EB9C 00000000 */  nop
/* 9FA0 8002EBA0 460AC182 */  mul.s     $f6, $f24, $f10
/* 9FA4 8002EBA4 00000000 */  nop
/* 9FA8 8002EBA8 C6000070 */  lwc1      $f0, 0x70($s0)
/* 9FAC 8002EBAC 46160002 */  mul.s     $f0, $f0, $f22
/* 9FB0 8002EBB0 00000000 */  nop
/* 9FB4 8002EBB4 4600F286 */  mov.s     $f10, $f30
/* 9FB8 8002EBB8 46005586 */  mov.s     $f22, $f10
/* 9FBC 8002EBBC 46044780 */  add.s     $f30, $f8, $f4
/* 9FC0 8002EBC0 46140683 */  div.s     $f26, $f0, $f20
/* 9FC4 8002EBC4 4600D306 */  mov.s     $f12, $f26
/* 9FC8 8002EBC8 0C00A85B */  jal       sin_rad
/* 9FCC 8002EBCC 46061600 */   add.s    $f24, $f2, $f6
/* 9FD0 8002EBD0 46000706 */  mov.s     $f28, $f0
/* 9FD4 8002EBD4 0C00A874 */  jal       cos_rad
/* 9FD8 8002EBD8 4600D306 */   mov.s    $f12, $f26
/* 9FDC 8002EBDC 46000286 */  mov.s     $f10, $f0
/* 9FE0 8002EBE0 46165102 */  mul.s     $f4, $f10, $f22
/* 9FE4 8002EBE4 00000000 */  nop
/* 9FE8 8002EBE8 4616E182 */  mul.s     $f6, $f28, $f22
/* 9FEC 8002EBEC 00000000 */  nop
/* 9FF0 8002EBF0 461CC002 */  mul.s     $f0, $f24, $f28
/* 9FF4 8002EBF4 00000000 */  nop
/* 9FF8 8002EBF8 460AC082 */  mul.s     $f2, $f24, $f10
/* 9FFC 8002EBFC 00000000 */  nop
/* A000 8002EC00 46002281 */  sub.s     $f10, $f4, $f0
/* A004 8002EC04 46023180 */  add.s     $f6, $f6, $f2
/* A008 8002EC08 C602004C */  lwc1      $f2, 0x4c($s0)
/* A00C 8002EC0C 461E1080 */  add.s     $f2, $f2, $f30
/* A010 8002EC10 C6000048 */  lwc1      $f0, 0x48($s0)
/* A014 8002EC14 8E060048 */  lw        $a2, 0x48($s0)
/* A018 8002EC18 460A0000 */  add.s     $f0, $f0, $f10
/* A01C 8002EC1C C60E0050 */  lwc1      $f14, 0x50($s0)
/* A020 8002EC20 8E070050 */  lw        $a3, 0x50($s0)
/* A024 8002EC24 46067380 */  add.s     $f14, $f14, $f6
/* A028 8002EC28 E6020040 */  swc1      $f2, 0x40($s0)
/* A02C 8002EC2C E600003C */  swc1      $f0, 0x3c($s0)
/* A030 8002EC30 46000306 */  mov.s     $f12, $f0
/* A034 8002EC34 0C00A720 */  jal       atan2
/* A038 8002EC38 E60E0044 */   swc1     $f14, 0x44($s0)
/* A03C 8002EC3C 4600B506 */  mov.s     $f20, $f22
/* A040 8002EC40 C6040048 */  lwc1      $f4, 0x48($s0)
/* A044 8002EC44 C602003C */  lwc1      $f2, 0x3c($s0)
/* A048 8002EC48 4600A306 */  mov.s     $f12, $f20
/* A04C 8002EC4C 46022581 */  sub.s     $f22, $f4, $f2
/* A050 8002EC50 C6040050 */  lwc1      $f4, 0x50($s0)
/* A054 8002EC54 C6020044 */  lwc1      $f2, 0x44($s0)
/* A058 8002EC58 4600A386 */  mov.s     $f14, $f20
/* A05C 8002EC5C 46022601 */  sub.s     $f24, $f4, $f2
/* A060 8002EC60 C604004C */  lwc1      $f4, 0x4c($s0)
/* A064 8002EC64 C6020040 */  lwc1      $f2, 0x40($s0)
/* A068 8002EC68 4406B000 */  mfc1      $a2, $f22
/* A06C 8002EC6C 4407C000 */  mfc1      $a3, $f24
/* A070 8002EC70 46022781 */  sub.s     $f30, $f4, $f2
/* A074 8002EC74 0C00A720 */  jal       atan2
/* A078 8002EC78 E600006C */   swc1     $f0, 0x6c($s0)
/* A07C 8002EC7C 4616B102 */  mul.s     $f4, $f22, $f22
/* A080 8002EC80 00000000 */  nop
/* A084 8002EC84 4618C082 */  mul.s     $f2, $f24, $f24
/* A088 8002EC88 00000000 */  nop
/* A08C 8002EC8C 46022300 */  add.s     $f12, $f4, $f2
/* A090 8002EC90 46000007 */  neg.s     $f0, $f0
/* A094 8002EC94 E6000090 */  swc1      $f0, 0x90($s0)
/* A098 8002EC98 46006004 */  sqrt.s    $f0, $f12
/* A09C 8002EC9C 46000032 */  c.eq.s    $f0, $f0
/* A0A0 8002ECA0 00000000 */  nop
/* A0A4 8002ECA4 45030004 */  bc1tl     .L8002ECB8
/* A0A8 8002ECA8 4600A306 */   mov.s    $f12, $f20
/* A0AC 8002ECAC 0C0187BC */  jal       sqrtf
/* A0B0 8002ECB0 00000000 */   nop
/* A0B4 8002ECB4 4600A306 */  mov.s     $f12, $f20
.L8002ECB8:
/* A0B8 8002ECB8 46000007 */  neg.s     $f0, $f0
/* A0BC 8002ECBC 4406F000 */  mfc1      $a2, $f30
/* A0C0 8002ECC0 44070000 */  mfc1      $a3, $f0
/* A0C4 8002ECC4 0C00A720 */  jal       atan2
/* A0C8 8002ECC8 46006386 */   mov.s    $f14, $f12
/* A0CC 8002ECCC E6000094 */  swc1      $f0, 0x94($s0)
/* A0D0 8002ECD0 8FBF0014 */  lw        $ra, 0x14($sp)
/* A0D4 8002ECD4 8FB00010 */  lw        $s0, 0x10($sp)
/* A0D8 8002ECD8 D7BE0040 */  ldc1      $f30, 0x40($sp)
/* A0DC 8002ECDC D7BC0038 */  ldc1      $f28, 0x38($sp)
/* A0E0 8002ECE0 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* A0E4 8002ECE4 D7B80028 */  ldc1      $f24, 0x28($sp)
/* A0E8 8002ECE8 D7B60020 */  ldc1      $f22, 0x20($sp)
/* A0EC 8002ECEC D7B40018 */  ldc1      $f20, 0x18($sp)
/* A0F0 8002ECF0 03E00008 */  jr        $ra
/* A0F4 8002ECF4 27BD0048 */   addiu    $sp, $sp, 0x48
