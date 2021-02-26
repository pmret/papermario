.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002E988
/* 9D88 8002E988 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D8C 8002E98C AFB00010 */  sw        $s0, 0x10($sp)
/* 9D90 8002E990 0080802D */  daddu     $s0, $a0, $zero
/* 9D94 8002E994 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9D98 8002E998 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* 9D9C 8002E99C F7BC0038 */  sdc1      $f28, 0x38($sp)
/* 9DA0 8002E9A0 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* 9DA4 8002E9A4 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 9DA8 8002E9A8 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 9DAC 8002E9AC F7B40018 */  sdc1      $f20, 0x18($sp)
/* 9DB0 8002E9B0 86020020 */  lh        $v0, 0x20($s0)
/* 9DB4 8002E9B4 3C01800A */  lui       $at, %hi(D_8009A5CC)
/* 9DB8 8002E9B8 C426A5CC */  lwc1      $f6, %lo(D_8009A5CC)($at)
/* 9DBC 8002E9BC 86030022 */  lh        $v1, 0x22($s0)
/* 9DC0 8002E9C0 44822000 */  mtc1      $v0, $f4
/* 9DC4 8002E9C4 00000000 */  nop
/* 9DC8 8002E9C8 46802120 */  cvt.s.w   $f4, $f4
/* 9DCC 8002E9CC 44831000 */  mtc1      $v1, $f2
/* 9DD0 8002E9D0 00000000 */  nop
/* 9DD4 8002E9D4 468010A0 */  cvt.s.w   $f2, $f2
/* 9DD8 8002E9D8 46062102 */  mul.s     $f4, $f4, $f6
/* 9DDC 8002E9DC 00000000 */  nop
/* 9DE0 8002E9E0 8602001E */  lh        $v0, 0x1e($s0)
/* 9DE4 8002E9E4 86030006 */  lh        $v1, 6($s0)
/* 9DE8 8002E9E8 44820000 */  mtc1      $v0, $f0
/* 9DEC 8002E9EC 00000000 */  nop
/* 9DF0 8002E9F0 46800020 */  cvt.s.w   $f0, $f0
/* 9DF4 8002E9F4 8602001C */  lh        $v0, 0x1c($s0)
/* 9DF8 8002E9F8 46061082 */  mul.s     $f2, $f2, $f6
/* 9DFC 8002E9FC 00000000 */  nop
/* 9E00 8002EA00 E6000070 */  swc1      $f0, 0x70($s0)
/* 9E04 8002EA04 46000186 */  mov.s     $f6, $f0
/* 9E08 8002EA08 E6060084 */  swc1      $f6, 0x84($s0)
/* 9E0C 8002EA0C 44820000 */  mtc1      $v0, $f0
/* 9E10 8002EA10 00000000 */  nop
/* 9E14 8002EA14 46800020 */  cvt.s.w   $f0, $f0
/* 9E18 8002EA18 E6000074 */  swc1      $f0, 0x74($s0)
/* 9E1C 8002EA1C E6040078 */  swc1      $f4, 0x78($s0)
/* 9E20 8002EA20 10600047 */  beqz      $v1, .L8002EB40
/* 9E24 8002EA24 E602007C */   swc1     $f2, 0x7c($s0)
/* 9E28 8002EA28 46000086 */  mov.s     $f2, $f0
/* 9E2C 8002EA2C 4480C000 */  mtc1      $zero, $f24
/* 9E30 8002EA30 3C0140C9 */  lui       $at, 0x40c9
/* 9E34 8002EA34 34210FD0 */  ori       $at, $at, 0xfd0
/* 9E38 8002EA38 4481B000 */  mtc1      $at, $f22
/* 9E3C 8002EA3C C6080054 */  lwc1      $f8, 0x54($s0)
/* 9E40 8002EA40 C6000058 */  lwc1      $f0, 0x58($s0)
/* 9E44 8002EA44 C604007C */  lwc1      $f4, 0x7c($s0)
/* 9E48 8002EA48 C606005C */  lwc1      $f6, 0x5c($s0)
/* 9E4C 8002EA4C 3C0143B4 */  lui       $at, 0x43b4
/* 9E50 8002EA50 4481A000 */  mtc1      $at, $f20
/* 9E54 8002EA54 46161082 */  mul.s     $f2, $f2, $f22
/* 9E58 8002EA58 00000000 */  nop
/* 9E5C 8002EA5C A6000006 */  sh        $zero, 6($s0)
/* 9E60 8002EA60 E6180098 */  swc1      $f24, 0x98($s0)
/* 9E64 8002EA64 E618009C */  swc1      $f24, 0x9c($s0)
/* 9E68 8002EA68 46040000 */  add.s     $f0, $f0, $f4
/* 9E6C 8002EA6C E6080048 */  swc1      $f8, 0x48($s0)
/* 9E70 8002EA70 E6060050 */  swc1      $f6, 0x50($s0)
/* 9E74 8002EA74 E600004C */  swc1      $f0, 0x4c($s0)
/* 9E78 8002EA78 46141683 */  div.s     $f26, $f2, $f20
/* 9E7C 8002EA7C 0C00A84B */  jal       func_8002A12C
/* 9E80 8002EA80 4600D306 */   mov.s    $f12, $f26
/* 9E84 8002EA84 46000786 */  mov.s     $f30, $f0
/* 9E88 8002EA88 0C00A864 */  jal       func_8002A190
/* 9E8C 8002EA8C 4600D306 */   mov.s    $f12, $f26
/* 9E90 8002EA90 46000306 */  mov.s     $f12, $f0
/* 9E94 8002EA94 46186202 */  mul.s     $f8, $f12, $f24
/* 9E98 8002EA98 00000000 */  nop
/* 9E9C 8002EA9C 4600C087 */  neg.s     $f2, $f24
/* 9EA0 8002EAA0 4602F082 */  mul.s     $f2, $f30, $f2
/* 9EA4 8002EAA4 00000000 */  nop
/* 9EA8 8002EAA8 C61C0078 */  lwc1      $f28, 0x78($s0)
/* 9EAC 8002EAAC 461EE102 */  mul.s     $f4, $f28, $f30
/* 9EB0 8002EAB0 00000000 */  nop
/* 9EB4 8002EAB4 460CE182 */  mul.s     $f6, $f28, $f12
/* 9EB8 8002EAB8 00000000 */  nop
/* 9EBC 8002EABC C6000070 */  lwc1      $f0, 0x70($s0)
/* 9EC0 8002EAC0 46160002 */  mul.s     $f0, $f0, $f22
/* 9EC4 8002EAC4 00000000 */  nop
/* 9EC8 8002EAC8 4600C286 */  mov.s     $f10, $f24
/* 9ECC 8002EACC 46005586 */  mov.s     $f22, $f10
/* 9ED0 8002EAD0 46044600 */  add.s     $f24, $f8, $f4
/* 9ED4 8002EAD4 46140683 */  div.s     $f26, $f0, $f20
/* 9ED8 8002EAD8 4600D306 */  mov.s     $f12, $f26
/* 9EDC 8002EADC 0C00A84B */  jal       func_8002A12C
/* 9EE0 8002EAE0 46061700 */   add.s    $f28, $f2, $f6
/* 9EE4 8002EAE4 46000786 */  mov.s     $f30, $f0
/* 9EE8 8002EAE8 0C00A864 */  jal       func_8002A190
/* 9EEC 8002EAEC 4600D306 */   mov.s    $f12, $f26
/* 9EF0 8002EAF0 46000306 */  mov.s     $f12, $f0
/* 9EF4 8002EAF4 46166202 */  mul.s     $f8, $f12, $f22
/* 9EF8 8002EAF8 00000000 */  nop
/* 9EFC 8002EAFC 4616F182 */  mul.s     $f6, $f30, $f22
/* 9F00 8002EB00 00000000 */  nop
/* 9F04 8002EB04 461EE102 */  mul.s     $f4, $f28, $f30
/* 9F08 8002EB08 00000000 */  nop
/* 9F0C 8002EB0C 460CE082 */  mul.s     $f2, $f28, $f12
/* 9F10 8002EB10 00000000 */  nop
/* 9F14 8002EB14 C600004C */  lwc1      $f0, 0x4c($s0)
/* 9F18 8002EB18 46180400 */  add.s     $f16, $f0, $f24
/* 9F1C 8002EB1C 46044281 */  sub.s     $f10, $f8, $f4
/* 9F20 8002EB20 46023080 */  add.s     $f2, $f6, $f2
/* 9F24 8002EB24 C6000048 */  lwc1      $f0, 0x48($s0)
/* 9F28 8002EB28 460A0100 */  add.s     $f4, $f0, $f10
/* 9F2C 8002EB2C C6000050 */  lwc1      $f0, 0x50($s0)
/* 9F30 8002EB30 46020200 */  add.s     $f8, $f0, $f2
/* 9F34 8002EB34 E6100040 */  swc1      $f16, 0x40($s0)
/* 9F38 8002EB38 E604003C */  swc1      $f4, 0x3c($s0)
/* 9F3C 8002EB3C E6080044 */  swc1      $f8, 0x44($s0)
.L8002EB40:
/* 9F40 8002EB40 C6020054 */  lwc1      $f2, 0x54($s0)
/* 9F44 8002EB44 C6000048 */  lwc1      $f0, 0x48($s0)
/* 9F48 8002EB48 46001101 */  sub.s     $f4, $f2, $f0
/* 9F4C 8002EB4C C602005C */  lwc1      $f2, 0x5c($s0)
/* 9F50 8002EB50 C6000050 */  lwc1      $f0, 0x50($s0)
/* 9F54 8002EB54 46001201 */  sub.s     $f8, $f2, $f0
/* 9F58 8002EB58 C6000058 */  lwc1      $f0, 0x58($s0)
/* 9F5C 8002EB5C C602007C */  lwc1      $f2, 0x7c($s0)
/* 9F60 8002EB60 46020000 */  add.s     $f0, $f0, $f2
/* 9F64 8002EB64 C602004C */  lwc1      $f2, 0x4c($s0)
/* 9F68 8002EB68 46020401 */  sub.s     $f16, $f0, $f2
/* 9F6C 8002EB6C 3C014180 */  lui       $at, 0x4180
/* 9F70 8002EB70 44811000 */  mtc1      $at, $f2
/* 9F74 8002EB74 46002005 */  abs.s     $f0, $f4
/* 9F78 8002EB78 4600103C */  c.lt.s    $f2, $f0
/* 9F7C 8002EB7C 00000000 */  nop
/* 9F80 8002EB80 4502000C */  bc1fl     .L8002EBB4
/* 9F84 8002EB84 46008005 */   abs.s    $f0, $f16
/* 9F88 8002EB88 44800000 */  mtc1      $zero, $f0
/* 9F8C 8002EB8C 00000000 */  nop
/* 9F90 8002EB90 4600203C */  c.lt.s    $f4, $f0
/* 9F94 8002EB94 00000000 */  nop
/* 9F98 8002EB98 45000005 */  bc1f      .L8002EBB0
/* 9F9C 8002EB9C 46001106 */   mov.s    $f4, $f2
/* 9FA0 8002EBA0 3C01C180 */  lui       $at, 0xc180
/* 9FA4 8002EBA4 44812000 */  mtc1      $at, $f4
/* 9FA8 8002EBA8 3C014180 */  lui       $at, 0x4180
/* 9FAC 8002EBAC 44811000 */  mtc1      $at, $f2
.L8002EBB0:
/* 9FB0 8002EBB0 46008005 */  abs.s     $f0, $f16
.L8002EBB4:
/* 9FB4 8002EBB4 4600103C */  c.lt.s    $f2, $f0
/* 9FB8 8002EBB8 00000000 */  nop
/* 9FBC 8002EBBC 45000009 */  bc1f      .L8002EBE4
/* 9FC0 8002EBC0 00000000 */   nop
/* 9FC4 8002EBC4 44800000 */  mtc1      $zero, $f0
/* 9FC8 8002EBC8 00000000 */  nop
/* 9FCC 8002EBCC 4600803C */  c.lt.s    $f16, $f0
/* 9FD0 8002EBD0 00000000 */  nop
/* 9FD4 8002EBD4 45000003 */  bc1f      .L8002EBE4
/* 9FD8 8002EBD8 46001406 */   mov.s    $f16, $f2
/* 9FDC 8002EBDC 3C01C180 */  lui       $at, 0xc180
/* 9FE0 8002EBE0 44818000 */  mtc1      $at, $f16
.L8002EBE4:
/* 9FE4 8002EBE4 3C014180 */  lui       $at, 0x4180
/* 9FE8 8002EBE8 44811000 */  mtc1      $at, $f2
/* 9FEC 8002EBEC 46004005 */  abs.s     $f0, $f8
/* 9FF0 8002EBF0 4600103C */  c.lt.s    $f2, $f0
/* 9FF4 8002EBF4 00000000 */  nop
/* 9FF8 8002EBF8 45000009 */  bc1f      .L8002EC20
/* 9FFC 8002EBFC 00000000 */   nop
/* A000 8002EC00 44800000 */  mtc1      $zero, $f0
/* A004 8002EC04 00000000 */  nop
/* A008 8002EC08 4600403C */  c.lt.s    $f8, $f0
/* A00C 8002EC0C 00000000 */  nop
/* A010 8002EC10 45000003 */  bc1f      .L8002EC20
/* A014 8002EC14 46001206 */   mov.s    $f8, $f2
/* A018 8002EC18 3C01C180 */  lui       $at, 0xc180
/* A01C 8002EC1C 44814000 */  mtc1      $at, $f8
.L8002EC20:
/* A020 8002EC20 3C013F00 */  lui       $at, 0x3f00
/* A024 8002EC24 4481A000 */  mtc1      $at, $f20
/* A028 8002EC28 00000000 */  nop
/* A02C 8002EC2C 46142082 */  mul.s     $f2, $f4, $f20
/* A030 8002EC30 00000000 */  nop
/* A034 8002EC34 46148182 */  mul.s     $f6, $f16, $f20
/* A038 8002EC38 00000000 */  nop
/* A03C 8002EC3C 46144202 */  mul.s     $f8, $f8, $f20
/* A040 8002EC40 00000000 */  nop
/* A044 8002EC44 C6000074 */  lwc1      $f0, 0x74($s0)
/* A048 8002EC48 3C0140C9 */  lui       $at, 0x40c9
/* A04C 8002EC4C 34210FD0 */  ori       $at, $at, 0xfd0
/* A050 8002EC50 4481B000 */  mtc1      $at, $f22
/* A054 8002EC54 00000000 */  nop
/* A058 8002EC58 46160002 */  mul.s     $f0, $f0, $f22
/* A05C 8002EC5C 00000000 */  nop
/* A060 8002EC60 4480C000 */  mtc1      $zero, $f24
/* A064 8002EC64 C6040048 */  lwc1      $f4, 0x48($s0)
/* A068 8002EC68 3C0143B4 */  lui       $at, 0x43b4
/* A06C 8002EC6C 44819000 */  mtc1      $at, $f18
/* A070 8002EC70 46022100 */  add.s     $f4, $f4, $f2
/* A074 8002EC74 C602004C */  lwc1      $f2, 0x4c($s0)
/* A078 8002EC78 46120683 */  div.s     $f26, $f0, $f18
/* A07C 8002EC7C 46061080 */  add.s     $f2, $f2, $f6
/* A080 8002EC80 C6000050 */  lwc1      $f0, 0x50($s0)
/* A084 8002EC84 4600D306 */  mov.s     $f12, $f26
/* A088 8002EC88 46080000 */  add.s     $f0, $f0, $f8
/* A08C 8002EC8C E6040048 */  swc1      $f4, 0x48($s0)
/* A090 8002EC90 E602004C */  swc1      $f2, 0x4c($s0)
/* A094 8002EC94 0C00A84B */  jal       func_8002A12C
/* A098 8002EC98 E6000050 */   swc1     $f0, 0x50($s0)
/* A09C 8002EC9C 46000786 */  mov.s     $f30, $f0
/* A0A0 8002ECA0 0C00A864 */  jal       func_8002A190
/* A0A4 8002ECA4 4600D306 */   mov.s    $f12, $f26
/* A0A8 8002ECA8 46000306 */  mov.s     $f12, $f0
/* A0AC 8002ECAC 46186202 */  mul.s     $f8, $f12, $f24
/* A0B0 8002ECB0 00000000 */  nop
/* A0B4 8002ECB4 4600C087 */  neg.s     $f2, $f24
/* A0B8 8002ECB8 4602F082 */  mul.s     $f2, $f30, $f2
/* A0BC 8002ECBC 00000000 */  nop
/* A0C0 8002ECC0 C61C0078 */  lwc1      $f28, 0x78($s0)
/* A0C4 8002ECC4 461EE102 */  mul.s     $f4, $f28, $f30
/* A0C8 8002ECC8 00000000 */  nop
/* A0CC 8002ECCC 460CE182 */  mul.s     $f6, $f28, $f12
/* A0D0 8002ECD0 00000000 */  nop
/* A0D4 8002ECD4 C6000070 */  lwc1      $f0, 0x70($s0)
/* A0D8 8002ECD8 46160002 */  mul.s     $f0, $f0, $f22
/* A0DC 8002ECDC 00000000 */  nop
/* A0E0 8002ECE0 4600C286 */  mov.s     $f10, $f24
/* A0E4 8002ECE4 3C0143B4 */  lui       $at, 0x43b4
/* A0E8 8002ECE8 44819000 */  mtc1      $at, $f18
/* A0EC 8002ECEC 46005586 */  mov.s     $f22, $f10
/* A0F0 8002ECF0 46044600 */  add.s     $f24, $f8, $f4
/* A0F4 8002ECF4 46120683 */  div.s     $f26, $f0, $f18
/* A0F8 8002ECF8 4600D306 */  mov.s     $f12, $f26
/* A0FC 8002ECFC 0C00A84B */  jal       func_8002A12C
/* A100 8002ED00 46061700 */   add.s    $f28, $f2, $f6
/* A104 8002ED04 46000786 */  mov.s     $f30, $f0
/* A108 8002ED08 0C00A864 */  jal       func_8002A190
/* A10C 8002ED0C 4600D306 */   mov.s    $f12, $f26
/* A110 8002ED10 46000306 */  mov.s     $f12, $f0
/* A114 8002ED14 461EE002 */  mul.s     $f0, $f28, $f30
/* A118 8002ED18 00000000 */  nop
/* A11C 8002ED1C C602004C */  lwc1      $f2, 0x4c($s0)
/* A120 8002ED20 46181400 */  add.s     $f16, $f2, $f24
/* A124 8002ED24 C6020040 */  lwc1      $f2, 0x40($s0)
/* A128 8002ED28 46028081 */  sub.s     $f2, $f16, $f2
/* A12C 8002ED2C 46141402 */  mul.s     $f16, $f2, $f20
/* A130 8002ED30 00000000 */  nop
/* A134 8002ED34 46166082 */  mul.s     $f2, $f12, $f22
/* A138 8002ED38 00000000 */  nop
/* A13C 8002ED3C 46001281 */  sub.s     $f10, $f2, $f0
/* A140 8002ED40 4616F082 */  mul.s     $f2, $f30, $f22
/* A144 8002ED44 00000000 */  nop
/* A148 8002ED48 C6000048 */  lwc1      $f0, 0x48($s0)
/* A14C 8002ED4C 460A0100 */  add.s     $f4, $f0, $f10
/* A150 8002ED50 C600003C */  lwc1      $f0, 0x3c($s0)
/* A154 8002ED54 46002001 */  sub.s     $f0, $f4, $f0
/* A158 8002ED58 46140102 */  mul.s     $f4, $f0, $f20
/* A15C 8002ED5C 00000000 */  nop
/* A160 8002ED60 460CE002 */  mul.s     $f0, $f28, $f12
/* A164 8002ED64 00000000 */  nop
/* A168 8002ED68 46001080 */  add.s     $f2, $f2, $f0
/* A16C 8002ED6C C6000050 */  lwc1      $f0, 0x50($s0)
/* A170 8002ED70 46020200 */  add.s     $f8, $f0, $f2
/* A174 8002ED74 C6000044 */  lwc1      $f0, 0x44($s0)
/* A178 8002ED78 46004001 */  sub.s     $f0, $f8, $f0
/* A17C 8002ED7C 46140202 */  mul.s     $f8, $f0, $f20
/* A180 8002ED80 00000000 */  nop
/* A184 8002ED84 3C014180 */  lui       $at, 0x4180
/* A188 8002ED88 44811000 */  mtc1      $at, $f2
/* A18C 8002ED8C 46002005 */  abs.s     $f0, $f4
/* A190 8002ED90 4600103C */  c.lt.s    $f2, $f0
/* A194 8002ED94 00000000 */  nop
/* A198 8002ED98 4502000A */  bc1fl     .L8002EDC4
/* A19C 8002ED9C 46008005 */   abs.s    $f0, $f16
/* A1A0 8002EDA0 4616203C */  c.lt.s    $f4, $f22
/* A1A4 8002EDA4 00000000 */  nop
/* A1A8 8002EDA8 45000005 */  bc1f      .L8002EDC0
/* A1AC 8002EDAC 46001106 */   mov.s    $f4, $f2
/* A1B0 8002EDB0 3C01C180 */  lui       $at, 0xc180
/* A1B4 8002EDB4 44812000 */  mtc1      $at, $f4
/* A1B8 8002EDB8 3C014180 */  lui       $at, 0x4180
/* A1BC 8002EDBC 44811000 */  mtc1      $at, $f2
.L8002EDC0:
/* A1C0 8002EDC0 46008005 */  abs.s     $f0, $f16
.L8002EDC4:
/* A1C4 8002EDC4 4600103C */  c.lt.s    $f2, $f0
/* A1C8 8002EDC8 00000000 */  nop
/* A1CC 8002EDCC 45000009 */  bc1f      .L8002EDF4
/* A1D0 8002EDD0 00000000 */   nop
/* A1D4 8002EDD4 44800000 */  mtc1      $zero, $f0
/* A1D8 8002EDD8 00000000 */  nop
/* A1DC 8002EDDC 4600803C */  c.lt.s    $f16, $f0
/* A1E0 8002EDE0 00000000 */  nop
/* A1E4 8002EDE4 45000003 */  bc1f      .L8002EDF4
/* A1E8 8002EDE8 46001406 */   mov.s    $f16, $f2
/* A1EC 8002EDEC 3C01C180 */  lui       $at, 0xc180
/* A1F0 8002EDF0 44818000 */  mtc1      $at, $f16
.L8002EDF4:
/* A1F4 8002EDF4 3C014180 */  lui       $at, 0x4180
/* A1F8 8002EDF8 44811000 */  mtc1      $at, $f2
/* A1FC 8002EDFC 46004005 */  abs.s     $f0, $f8
/* A200 8002EE00 4600103C */  c.lt.s    $f2, $f0
/* A204 8002EE04 00000000 */  nop
/* A208 8002EE08 45000009 */  bc1f      .L8002EE30
/* A20C 8002EE0C 00000000 */   nop
/* A210 8002EE10 44800000 */  mtc1      $zero, $f0
/* A214 8002EE14 00000000 */  nop
/* A218 8002EE18 4600403C */  c.lt.s    $f8, $f0
/* A21C 8002EE1C 00000000 */  nop
/* A220 8002EE20 45000003 */  bc1f      .L8002EE30
/* A224 8002EE24 46001206 */   mov.s    $f8, $f2
/* A228 8002EE28 3C01C180 */  lui       $at, 0xc180
/* A22C 8002EE2C 44814000 */  mtc1      $at, $f8
.L8002EE30:
/* A230 8002EE30 C600003C */  lwc1      $f0, 0x3c($s0)
/* A234 8002EE34 46040000 */  add.s     $f0, $f0, $f4
/* A238 8002EE38 C60E0044 */  lwc1      $f14, 0x44($s0)
/* A23C 8002EE3C 8E060048 */  lw        $a2, 0x48($s0)
/* A240 8002EE40 46087380 */  add.s     $f14, $f14, $f8
/* A244 8002EE44 C6020040 */  lwc1      $f2, 0x40($s0)
/* A248 8002EE48 8E070050 */  lw        $a3, 0x50($s0)
/* A24C 8002EE4C 46101080 */  add.s     $f2, $f2, $f16
/* A250 8002EE50 E600003C */  swc1      $f0, 0x3c($s0)
/* A254 8002EE54 46000306 */  mov.s     $f12, $f0
/* A258 8002EE58 E6020040 */  swc1      $f2, 0x40($s0)
/* A25C 8002EE5C 0C00A710 */  jal       func_80029C40
/* A260 8002EE60 E60E0044 */   swc1     $f14, 0x44($s0)
/* A264 8002EE64 C6040048 */  lwc1      $f4, 0x48($s0)
/* A268 8002EE68 4480A000 */  mtc1      $zero, $f20
/* A26C 8002EE6C C602003C */  lwc1      $f2, 0x3c($s0)
/* A270 8002EE70 E600006C */  swc1      $f0, 0x6c($s0)
/* A274 8002EE74 46022581 */  sub.s     $f22, $f4, $f2
/* A278 8002EE78 C6040050 */  lwc1      $f4, 0x50($s0)
/* A27C 8002EE7C C6020044 */  lwc1      $f2, 0x44($s0)
/* A280 8002EE80 4600A306 */  mov.s     $f12, $f20
/* A284 8002EE84 46022701 */  sub.s     $f28, $f4, $f2
/* A288 8002EE88 C604004C */  lwc1      $f4, 0x4c($s0)
/* A28C 8002EE8C C6020040 */  lwc1      $f2, 0x40($s0)
/* A290 8002EE90 4406B000 */  mfc1      $a2, $f22
/* A294 8002EE94 46022601 */  sub.s     $f24, $f4, $f2
/* A298 8002EE98 4407E000 */  mfc1      $a3, $f28
/* A29C 8002EE9C 0C00A710 */  jal       func_80029C40
/* A2A0 8002EEA0 4600A386 */   mov.s    $f14, $f20
/* A2A4 8002EEA4 4616B102 */  mul.s     $f4, $f22, $f22
/* A2A8 8002EEA8 00000000 */  nop
/* A2AC 8002EEAC 461CE082 */  mul.s     $f2, $f28, $f28
/* A2B0 8002EEB0 00000000 */  nop
/* A2B4 8002EEB4 46022300 */  add.s     $f12, $f4, $f2
/* A2B8 8002EEB8 46000007 */  neg.s     $f0, $f0
/* A2BC 8002EEBC E6000090 */  swc1      $f0, 0x90($s0)
/* A2C0 8002EEC0 46006004 */  sqrt.s    $f0, $f12
/* A2C4 8002EEC4 46000032 */  c.eq.s    $f0, $f0
/* A2C8 8002EEC8 00000000 */  nop
/* A2CC 8002EECC 45030004 */  bc1tl     .L8002EEE0
/* A2D0 8002EED0 4600A306 */   mov.s    $f12, $f20
/* A2D4 8002EED4 0C0187B0 */  jal       func_80061EC0
/* A2D8 8002EED8 00000000 */   nop
/* A2DC 8002EEDC 4600A306 */  mov.s     $f12, $f20
.L8002EEE0:
/* A2E0 8002EEE0 46000007 */  neg.s     $f0, $f0
/* A2E4 8002EEE4 4406C000 */  mfc1      $a2, $f24
/* A2E8 8002EEE8 44070000 */  mfc1      $a3, $f0
/* A2EC 8002EEEC 0C00A710 */  jal       func_80029C40
/* A2F0 8002EEF0 46006386 */   mov.s    $f14, $f12
/* A2F4 8002EEF4 E6000094 */  swc1      $f0, 0x94($s0)
/* A2F8 8002EEF8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2FC 8002EEFC 8FB00010 */  lw        $s0, 0x10($sp)
/* A300 8002EF00 D7BE0040 */  ldc1      $f30, 0x40($sp)
/* A304 8002EF04 D7BC0038 */  ldc1      $f28, 0x38($sp)
/* A308 8002EF08 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* A30C 8002EF0C D7B80028 */  ldc1      $f24, 0x28($sp)
/* A310 8002EF10 D7B60020 */  ldc1      $f22, 0x20($sp)
/* A314 8002EF14 D7B40018 */  ldc1      $f20, 0x18($sp)
/* A318 8002EF18 03E00008 */  jr        $ra
/* A31C 8002EF1C 27BD0048 */   addiu    $sp, $sp, 0x48
