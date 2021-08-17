.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_115_main
/* 3E0930 E00E6000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3E0934 E00E6004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3E0938 E00E6008 4485A000 */  mtc1      $a1, $f20
/* 3E093C E00E600C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3E0940 E00E6010 4486B000 */  mtc1      $a2, $f22
/* 3E0944 E00E6014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3E0948 E00E6018 4487C000 */  mtc1      $a3, $f24
/* 3E094C E00E601C AFB30034 */  sw        $s3, 0x34($sp)
/* 3E0950 E00E6020 0080982D */  daddu     $s3, $a0, $zero
/* 3E0954 E00E6024 AFB00028 */  sw        $s0, 0x28($sp)
/* 3E0958 E00E6028 8FB0006C */  lw        $s0, 0x6c($sp)
/* 3E095C E00E602C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E0960 E00E6030 AFB20030 */  sw        $s2, 0x30($sp)
/* 3E0964 E00E6034 8FB20070 */  lw        $s2, 0x70($sp)
/* 3E0968 E00E6038 3C02E00E */  lui       $v0, %hi(func_E00E617C)
/* 3E096C E00E603C 2442617C */  addiu     $v0, $v0, %lo(func_E00E617C)
/* 3E0970 E00E6040 AFA20018 */  sw        $v0, 0x18($sp)
/* 3E0974 E00E6044 3C02E00E */  lui       $v0, %hi(func_E00E6184)
/* 3E0978 E00E6048 24426184 */  addiu     $v0, $v0, %lo(func_E00E6184)
/* 3E097C E00E604C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E0980 E00E6050 3C02E00E */  lui       $v0, %hi(func_E00E64D4)
/* 3E0984 E00E6054 244264D4 */  addiu     $v0, $v0, %lo(func_E00E64D4)
/* 3E0988 E00E6058 AFA20020 */  sw        $v0, 0x20($sp)
/* 3E098C E00E605C 24020073 */  addiu     $v0, $zero, 0x73
/* 3E0990 E00E6060 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3E0994 E00E6064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3E0998 E00E6068 AFA00010 */  sw        $zero, 0x10($sp)
/* 3E099C E00E606C AFA00024 */  sw        $zero, 0x24($sp)
/* 3E09A0 E00E6070 AFA20014 */  sw        $v0, 0x14($sp)
/* 3E09A4 E00E6074 0C080124 */  jal       func_E0200490
/* 3E09A8 E00E6078 26100001 */   addiu    $s0, $s0, 1
/* 3E09AC E00E607C 001020C0 */  sll       $a0, $s0, 3
/* 3E09B0 E00E6080 00902023 */  subu      $a0, $a0, $s0
/* 3E09B4 E00E6084 000420C0 */  sll       $a0, $a0, 3
/* 3E09B8 E00E6088 0040882D */  daddu     $s1, $v0, $zero
/* 3E09BC E00E608C 0C08012C */  jal       func_E02004B0
/* 3E09C0 E00E6090 AE300008 */   sw       $s0, 8($s1)
/* 3E09C4 E00E6094 0040182D */  daddu     $v1, $v0, $zero
/* 3E09C8 E00E6098 14600003 */  bnez      $v1, .LE00E60A8
/* 3E09CC E00E609C AE23000C */   sw       $v1, 0xc($s1)
.LE00E60A0:
/* 3E09D0 E00E60A0 08039828 */  j         .LE00E60A0
/* 3E09D4 E00E60A4 00000000 */   nop
.LE00E60A8:
/* 3E09D8 E00E60A8 AC730000 */  sw        $s3, ($v1)
/* 3E09DC E00E60AC 1E400004 */  bgtz      $s2, .LE00E60C0
/* 3E09E0 E00E60B0 AC60002C */   sw       $zero, 0x2c($v1)
/* 3E09E4 E00E60B4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3E09E8 E00E60B8 08039831 */  j         .LE00E60C4
/* 3E09EC E00E60BC AC620028 */   sw       $v0, 0x28($v1)
.LE00E60C0:
/* 3E09F0 E00E60C0 AC720028 */  sw        $s2, 0x28($v1)
.LE00E60C4:
/* 3E09F4 E00E60C4 240200FF */  addiu     $v0, $zero, 0xff
/* 3E09F8 E00E60C8 24040001 */  addiu     $a0, $zero, 1
/* 3E09FC E00E60CC AC620030 */  sw        $v0, 0x30($v1)
/* 3E0A00 E00E60D0 E4740004 */  swc1      $f20, 4($v1)
/* 3E0A04 E00E60D4 E4760008 */  swc1      $f22, 8($v1)
/* 3E0A08 E00E60D8 E478000C */  swc1      $f24, 0xc($v1)
/* 3E0A0C E00E60DC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3E0A10 E00E60E0 00131080 */  sll       $v0, $s3, 2
/* 3E0A14 E00E60E4 E4600034 */  swc1      $f0, 0x34($v1)
/* 3E0A18 E00E60E8 3C01E00E */  lui       $at, %hi(D_E00E6890)
/* 3E0A1C E00E60EC 00220821 */  addu      $at, $at, $v0
/* 3E0A20 E00E60F0 C4226890 */  lwc1      $f2, %lo(D_E00E6890)($at)
/* 3E0A24 E00E60F4 468010A0 */  cvt.s.w   $f2, $f2
/* 3E0A28 E00E60F8 3C013F00 */  lui       $at, 0x3f00
/* 3E0A2C E00E60FC 44810000 */  mtc1      $at, $f0
/* 3E0A30 E00E6100 0090102A */  slt       $v0, $a0, $s0
/* 3E0A34 E00E6104 46001082 */  mul.s     $f2, $f2, $f0
/* 3E0A38 E00E6108 00000000 */  nop
/* 3E0A3C E00E610C 10400010 */  beqz      $v0, .LE00E6150
/* 3E0A40 E00E6110 24630038 */   addiu    $v1, $v1, 0x38
/* 3E0A44 E00E6114 3C01BF80 */  lui       $at, 0xbf80
/* 3E0A48 E00E6118 44812000 */  mtc1      $at, $f4
.LE00E611C:
/* 3E0A4C E00E611C 30820001 */  andi      $v0, $a0, 1
/* 3E0A50 E00E6120 44820000 */  mtc1      $v0, $f0
/* 3E0A54 E00E6124 00000000 */  nop
/* 3E0A58 E00E6128 46800020 */  cvt.s.w   $f0, $f0
/* 3E0A5C E00E612C 46001002 */  mul.s     $f0, $f2, $f0
/* 3E0A60 E00E6130 00000000 */  nop
/* 3E0A64 E00E6134 46002001 */  sub.s     $f0, $f4, $f0
/* 3E0A68 E00E6138 24840001 */  addiu     $a0, $a0, 1
/* 3E0A6C E00E613C 0090102A */  slt       $v0, $a0, $s0
/* 3E0A70 E00E6140 4600018D */  trunc.w.s $f6, $f0
/* 3E0A74 E00E6144 E4660020 */  swc1      $f6, 0x20($v1)
/* 3E0A78 E00E6148 1440FFF4 */  bnez      $v0, .LE00E611C
/* 3E0A7C E00E614C 24630038 */   addiu    $v1, $v1, 0x38
.LE00E6150:
/* 3E0A80 E00E6150 0220102D */  daddu     $v0, $s1, $zero
/* 3E0A84 E00E6154 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3E0A88 E00E6158 8FB30034 */  lw        $s3, 0x34($sp)
/* 3E0A8C E00E615C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3E0A90 E00E6160 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3E0A94 E00E6164 8FB00028 */  lw        $s0, 0x28($sp)
/* 3E0A98 E00E6168 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3E0A9C E00E616C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3E0AA0 E00E6170 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3E0AA4 E00E6174 03E00008 */  jr        $ra
/* 3E0AA8 E00E6178 27BD0058 */   addiu    $sp, $sp, 0x58
