.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_99_main
/* 3CC9E0 E00C6000 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 3CC9E4 E00C6004 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3CC9E8 E00C6008 0080882D */  daddu     $s1, $a0, $zero
/* 3CC9EC E00C600C AFB30034 */  sw        $s3, 0x34($sp)
/* 3CC9F0 E00C6010 24130001 */  addiu     $s3, $zero, 1
/* 3CC9F4 E00C6014 AFB5003C */  sw        $s5, 0x3c($sp)
/* 3CC9F8 E00C6018 8FB50098 */  lw        $s5, 0x98($sp)
/* 3CC9FC E00C601C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3CCA00 E00C6020 AFB20030 */  sw        $s2, 0x30($sp)
/* 3CCA04 E00C6024 8FB2009C */  lw        $s2, 0x9c($sp)
/* 3CCA08 E00C6028 24020002 */  addiu     $v0, $zero, 2
/* 3CCA0C E00C602C AFBF0040 */  sw        $ra, 0x40($sp)
/* 3CCA10 E00C6030 AFB40038 */  sw        $s4, 0x38($sp)
/* 3CCA14 E00C6034 AFB00028 */  sw        $s0, 0x28($sp)
/* 3CCA18 E00C6038 F7BE0070 */  sdc1      $f30, 0x70($sp)
/* 3CCA1C E00C603C F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 3CCA20 E00C6040 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 3CCA24 E00C6044 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 3CCA28 E00C6048 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 3CCA2C E00C604C F7B40048 */  sdc1      $f20, 0x48($sp)
/* 3CCA30 E00C6050 AFA5007C */  sw        $a1, 0x7c($sp)
/* 3CCA34 E00C6054 AFA60080 */  sw        $a2, 0x80($sp)
/* 3CCA38 E00C6058 16220002 */  bne       $s1, $v0, .LE00C6064
/* 3CCA3C E00C605C AFA70084 */   sw       $a3, 0x84($sp)
/* 3CCA40 E00C6060 24130008 */  addiu     $s3, $zero, 8
.LE00C6064:
/* 3CCA44 E00C6064 3C02E00C */  lui       $v0, %hi(func_E00C6394)
/* 3CCA48 E00C6068 24426394 */  addiu     $v0, $v0, %lo(func_E00C6394)
/* 3CCA4C E00C606C AFA20018 */  sw        $v0, 0x18($sp)
/* 3CCA50 E00C6070 3C02E00C */  lui       $v0, %hi(func_E00C639C)
/* 3CCA54 E00C6074 2442639C */  addiu     $v0, $v0, %lo(func_E00C639C)
/* 3CCA58 E00C6078 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3CCA5C E00C607C 3C02E00C */  lui       $v0, %hi(func_E00C6768)
/* 3CCA60 E00C6080 24426768 */  addiu     $v0, $v0, %lo(func_E00C6768)
/* 3CCA64 E00C6084 AFA20020 */  sw        $v0, 0x20($sp)
/* 3CCA68 E00C6088 24020063 */  addiu     $v0, $zero, 0x63
/* 3CCA6C E00C608C AFA00010 */  sw        $zero, 0x10($sp)
/* 3CCA70 E00C6090 AFA00024 */  sw        $zero, 0x24($sp)
/* 3CCA74 E00C6094 0C080124 */  jal       shim_create_effect_instance
/* 3CCA78 E00C6098 AFA20014 */   sw       $v0, 0x14($sp)
/* 3CCA7C E00C609C 00132140 */  sll       $a0, $s3, 5
/* 3CCA80 E00C60A0 00932023 */  subu      $a0, $a0, $s3
/* 3CCA84 E00C60A4 00042080 */  sll       $a0, $a0, 2
/* 3CCA88 E00C60A8 0040A02D */  daddu     $s4, $v0, $zero
/* 3CCA8C E00C60AC 0C08012C */  jal       shim_general_heap_malloc
/* 3CCA90 E00C60B0 AE930008 */   sw       $s3, 8($s4)
/* 3CCA94 E00C60B4 0040802D */  daddu     $s0, $v0, $zero
/* 3CCA98 E00C60B8 16000003 */  bnez      $s0, .LE00C60C8
/* 3CCA9C E00C60BC AE82000C */   sw       $v0, 0xc($s4)
.LE00C60C0:
/* 3CCAA0 E00C60C0 08031830 */  j         .LE00C60C0
/* 3CCAA4 E00C60C4 00000000 */   nop
.LE00C60C8:
/* 3CCAA8 E00C60C8 5E400003 */  bgtzl     $s2, .LE00C60D8
/* 3CCAAC E00C60CC AE120020 */   sw       $s2, 0x20($s0)
/* 3CCAB0 E00C60D0 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3CCAB4 E00C60D4 AE020020 */  sw        $v0, 0x20($s0)
.LE00C60D8:
/* 3CCAB8 E00C60D8 C7AA007C */  lwc1      $f10, 0x7c($sp)
/* 3CCABC E00C60DC E60A0004 */  swc1      $f10, 4($s0)
/* 3CCAC0 E00C60E0 C7A00088 */  lwc1      $f0, 0x88($sp)
/* 3CCAC4 E00C60E4 46005086 */  mov.s     $f2, $f10
/* 3CCAC8 E00C60E8 AE110000 */  sw        $s1, ($s0)
/* 3CCACC E00C60EC AE000024 */  sw        $zero, 0x24($s0)
/* 3CCAD0 E00C60F0 AE15001C */  sw        $s5, 0x1c($s0)
/* 3CCAD4 E00C60F4 AE000034 */  sw        $zero, 0x34($s0)
/* 3CCAD8 E00C60F8 E6000010 */  swc1      $f0, 0x10($s0)
/* 3CCADC E00C60FC C7AA0080 */  lwc1      $f10, 0x80($sp)
/* 3CCAE0 E00C6100 E60A0008 */  swc1      $f10, 8($s0)
/* 3CCAE4 E00C6104 C7AA0084 */  lwc1      $f10, 0x84($sp)
/* 3CCAE8 E00C6108 46000206 */  mov.s     $f8, $f0
/* 3CCAEC E00C610C E60A000C */  swc1      $f10, 0xc($s0)
/* 3CCAF0 E00C6110 C7A0008C */  lwc1      $f0, 0x8c($sp)
/* 3CCAF4 E00C6114 46024201 */  sub.s     $f8, $f8, $f2
/* 3CCAF8 E00C6118 E6000014 */  swc1      $f0, 0x14($s0)
/* 3CCAFC E00C611C C7A00090 */  lwc1      $f0, 0x90($sp)
/* 3CCB00 E00C6120 C6020014 */  lwc1      $f2, 0x14($s0)
/* 3CCB04 E00C6124 E6000018 */  swc1      $f0, 0x18($s0)
/* 3CCB08 E00C6128 C7A00094 */  lwc1      $f0, 0x94($sp)
/* 3CCB0C E00C612C 44952000 */  mtc1      $s5, $f4
/* 3CCB10 E00C6130 00000000 */  nop
/* 3CCB14 E00C6134 46802120 */  cvt.s.w   $f4, $f4
/* 3CCB18 E00C6138 E6000048 */  swc1      $f0, 0x48($s0)
/* 3CCB1C E00C613C C6000008 */  lwc1      $f0, 8($s0)
/* 3CCB20 E00C6140 46005186 */  mov.s     $f6, $f10
/* 3CCB24 E00C6144 46001081 */  sub.s     $f2, $f2, $f0
/* 3CCB28 E00C6148 C6000018 */  lwc1      $f0, 0x18($s0)
/* 3CCB2C E00C614C 46044203 */  div.s     $f8, $f8, $f4
/* 3CCB30 E00C6150 E6080060 */  swc1      $f8, 0x60($s0)
/* 3CCB34 E00C6154 46060001 */  sub.s     $f0, $f0, $f6
/* 3CCB38 E00C6158 46041083 */  div.s     $f2, $f2, $f4
/* 3CCB3C E00C615C E6020064 */  swc1      $f2, 0x64($s0)
/* 3CCB40 E00C6160 46040003 */  div.s     $f0, $f0, $f4
/* 3CCB44 E00C6164 1220007B */  beqz      $s1, .LE00C6354
/* 3CCB48 E00C6168 E6000068 */   swc1     $f0, 0x68($s0)
/* 3CCB4C E00C616C 24020001 */  addiu     $v0, $zero, 1
/* 3CCB50 E00C6170 1622002B */  bne       $s1, $v0, .LE00C6220
/* 3CCB54 E00C6174 24040168 */   addiu    $a0, $zero, 0x168
/* 3CCB58 E00C6178 24040040 */  addiu     $a0, $zero, 0x40
/* 3CCB5C E00C617C 240300FF */  addiu     $v1, $zero, 0xff
/* 3CCB60 E00C6180 24020058 */  addiu     $v0, $zero, 0x58
/* 3CCB64 E00C6184 AE02002C */  sw        $v0, 0x2c($s0)
/* 3CCB68 E00C6188 24020046 */  addiu     $v0, $zero, 0x46
/* 3CCB6C E00C618C AE020030 */  sw        $v0, 0x30($s0)
/* 3CCB70 E00C6190 24020037 */  addiu     $v0, $zero, 0x37
/* 3CCB74 E00C6194 AE020034 */  sw        $v0, 0x34($s0)
/* 3CCB78 E00C6198 2402000B */  addiu     $v0, $zero, 0xb
/* 3CCB7C E00C619C AE020038 */  sw        $v0, 0x38($s0)
/* 3CCB80 E00C61A0 24020033 */  addiu     $v0, $zero, 0x33
/* 3CCB84 E00C61A4 AE02003C */  sw        $v0, 0x3c($s0)
/* 3CCB88 E00C61A8 2402007B */  addiu     $v0, $zero, 0x7b
/* 3CCB8C E00C61AC AE030028 */  sw        $v1, 0x28($s0)
/* 3CCB90 E00C61B0 AE020040 */  sw        $v0, 0x40($s0)
/* 3CCB94 E00C61B4 0C080138 */  jal       shim_rand_int
/* 3CCB98 E00C61B8 AE030044 */   sw       $v1, 0x44($s0)
/* 3CCB9C E00C61BC 24040040 */  addiu     $a0, $zero, 0x40
/* 3CCBA0 E00C61C0 44820000 */  mtc1      $v0, $f0
/* 3CCBA4 E00C61C4 00000000 */  nop
/* 3CCBA8 E00C61C8 46800020 */  cvt.s.w   $f0, $f0
/* 3CCBAC E00C61CC 0C080138 */  jal       shim_rand_int
/* 3CCBB0 E00C61D0 E600004C */   swc1     $f0, 0x4c($s0)
/* 3CCBB4 E00C61D4 3C013E4C */  lui       $at, 0x3e4c
/* 3CCBB8 E00C61D8 3421CCCD */  ori       $at, $at, 0xcccd
/* 3CCBBC E00C61DC 44811000 */  mtc1      $at, $f2
/* 3CCBC0 E00C61E0 3C013E99 */  lui       $at, 0x3e99
/* 3CCBC4 E00C61E4 3421999A */  ori       $at, $at, 0x999a
/* 3CCBC8 E00C61E8 44812000 */  mtc1      $at, $f4
/* 3CCBCC E00C61EC 3C01C120 */  lui       $at, 0xc120
/* 3CCBD0 E00C61F0 44813000 */  mtc1      $at, $f6
/* 3CCBD4 E00C61F4 44820000 */  mtc1      $v0, $f0
/* 3CCBD8 E00C61F8 00000000 */  nop
/* 3CCBDC E00C61FC 46800020 */  cvt.s.w   $f0, $f0
/* 3CCBE0 E00C6200 E6000050 */  swc1      $f0, 0x50($s0)
/* 3CCBE4 E00C6204 AE000054 */  sw        $zero, 0x54($s0)
/* 3CCBE8 E00C6208 AE000058 */  sw        $zero, 0x58($s0)
/* 3CCBEC E00C620C AE000074 */  sw        $zero, 0x74($s0)
/* 3CCBF0 E00C6210 E6020070 */  swc1      $f2, 0x70($s0)
/* 3CCBF4 E00C6214 E604006C */  swc1      $f4, 0x6c($s0)
/* 3CCBF8 E00C6218 080318D5 */  j         .LE00C6354
/* 3CCBFC E00C621C E6060078 */   swc1     $f6, 0x78($s0)
.LE00C6220:
/* 3CCC00 E00C6220 240300FF */  addiu     $v1, $zero, 0xff
/* 3CCC04 E00C6224 24020058 */  addiu     $v0, $zero, 0x58
/* 3CCC08 E00C6228 AE02002C */  sw        $v0, 0x2c($s0)
/* 3CCC0C E00C622C 24020046 */  addiu     $v0, $zero, 0x46
/* 3CCC10 E00C6230 AE020030 */  sw        $v0, 0x30($s0)
/* 3CCC14 E00C6234 24020037 */  addiu     $v0, $zero, 0x37
/* 3CCC18 E00C6238 AE020034 */  sw        $v0, 0x34($s0)
/* 3CCC1C E00C623C 2402000B */  addiu     $v0, $zero, 0xb
/* 3CCC20 E00C6240 AE020038 */  sw        $v0, 0x38($s0)
/* 3CCC24 E00C6244 24020033 */  addiu     $v0, $zero, 0x33
/* 3CCC28 E00C6248 AE02003C */  sw        $v0, 0x3c($s0)
/* 3CCC2C E00C624C 2402007B */  addiu     $v0, $zero, 0x7b
/* 3CCC30 E00C6250 AE030028 */  sw        $v1, 0x28($s0)
/* 3CCC34 E00C6254 AE020040 */  sw        $v0, 0x40($s0)
/* 3CCC38 E00C6258 0C080138 */  jal       shim_rand_int
/* 3CCC3C E00C625C AE030044 */   sw       $v1, 0x44($s0)
/* 3CCC40 E00C6260 4482C000 */  mtc1      $v0, $f24
/* 3CCC44 E00C6264 00000000 */  nop
/* 3CCC48 E00C6268 4680C620 */  cvt.s.w   $f24, $f24
/* 3CCC4C E00C626C 12600039 */  beqz      $s3, .LE00C6354
/* 3CCC50 E00C6270 0000882D */   daddu    $s1, $zero, $zero
/* 3CCC54 E00C6274 26100078 */  addiu     $s0, $s0, 0x78
/* 3CCC58 E00C6278 0220902D */  daddu     $s2, $s1, $zero
/* 3CCC5C E00C627C 3C014040 */  lui       $at, 0x4040
/* 3CCC60 E00C6280 4481F000 */  mtc1      $at, $f30
/* 3CCC64 E00C6284 3C013F80 */  lui       $at, 0x3f80
/* 3CCC68 E00C6288 4481B000 */  mtc1      $at, $f22
/* 3CCC6C E00C628C 3C01C234 */  lui       $at, 0xc234
/* 3CCC70 E00C6290 4481E000 */  mtc1      $at, $f28
/* 3CCC74 E00C6294 3C01C120 */  lui       $at, 0xc120
/* 3CCC78 E00C6298 4481D000 */  mtc1      $at, $f26
.LE00C629C:
/* 3CCC7C E00C629C C7AA007C */  lwc1      $f10, 0x7c($sp)
/* 3CCC80 E00C62A0 4492A000 */  mtc1      $s2, $f20
/* 3CCC84 E00C62A4 00000000 */  nop
/* 3CCC88 E00C62A8 4680A520 */  cvt.s.w   $f20, $f20
/* 3CCC8C E00C62AC E60AFF8C */  swc1      $f10, -0x74($s0)
/* 3CCC90 E00C62B0 C7AA0080 */  lwc1      $f10, 0x80($sp)
/* 3CCC94 E00C62B4 4618A500 */  add.s     $f20, $f20, $f24
/* 3CCC98 E00C62B8 E60AFF90 */  swc1      $f10, -0x70($s0)
/* 3CCC9C E00C62BC C7AA0084 */  lwc1      $f10, 0x84($sp)
/* 3CCCA0 E00C62C0 4600A306 */  mov.s     $f12, $f20
/* 3CCCA4 E00C62C4 0C080140 */  jal       shim_sin_deg
/* 3CCCA8 E00C62C8 E60AFF94 */   swc1     $f10, -0x6c($s0)
/* 3CCCAC E00C62CC 3C0140A0 */  lui       $at, 0x40a0
/* 3CCCB0 E00C62D0 44815000 */  mtc1      $at, $f10
/* 3CCCB4 E00C62D4 00000000 */  nop
/* 3CCCB8 E00C62D8 460A0002 */  mul.s     $f0, $f0, $f10
/* 3CCCBC E00C62DC 00000000 */  nop
/* 3CCCC0 E00C62E0 4600A306 */  mov.s     $f12, $f20
/* 3CCCC4 E00C62E4 0C080144 */  jal       shim_cos_deg
/* 3CCCC8 E00C62E8 E600FFE8 */   swc1     $f0, -0x18($s0)
/* 3CCCCC E00C62EC 46000000 */  add.s     $f0, $f0, $f0
/* 3CCCD0 E00C62F0 2652002D */  addiu     $s2, $s2, 0x2d
/* 3CCCD4 E00C62F4 461E0000 */  add.s     $f0, $f0, $f30
/* 3CCCD8 E00C62F8 26310001 */  addiu     $s1, $s1, 1
/* 3CCCDC E00C62FC 24040040 */  addiu     $a0, $zero, 0x40
/* 3CCCE0 E00C6300 0C080138 */  jal       shim_rand_int
/* 3CCCE4 E00C6304 E600FFEC */   swc1     $f0, -0x14($s0)
/* 3CCCE8 E00C6308 24040040 */  addiu     $a0, $zero, 0x40
/* 3CCCEC E00C630C 44820000 */  mtc1      $v0, $f0
/* 3CCCF0 E00C6310 00000000 */  nop
/* 3CCCF4 E00C6314 46800020 */  cvt.s.w   $f0, $f0
/* 3CCCF8 E00C6318 0C080138 */  jal       shim_rand_int
/* 3CCCFC E00C631C E600FFD4 */   swc1     $f0, -0x2c($s0)
/* 3CCD00 E00C6320 44820000 */  mtc1      $v0, $f0
/* 3CCD04 E00C6324 00000000 */  nop
/* 3CCD08 E00C6328 46800020 */  cvt.s.w   $f0, $f0
/* 3CCD0C E00C632C E600FFD8 */  swc1      $f0, -0x28($s0)
/* 3CCD10 E00C6330 E616FFF8 */  swc1      $f22, -8($s0)
/* 3CCD14 E00C6334 E616FFF4 */  swc1      $f22, -0xc($s0)
/* 3CCD18 E00C6338 AE00FFDC */  sw        $zero, -0x24($s0)
/* 3CCD1C E00C633C AE00FFE0 */  sw        $zero, -0x20($s0)
/* 3CCD20 E00C6340 E61CFFFC */  swc1      $f28, -4($s0)
/* 3CCD24 E00C6344 E61A0000 */  swc1      $f26, ($s0)
/* 3CCD28 E00C6348 0233102A */  slt       $v0, $s1, $s3
/* 3CCD2C E00C634C 1440FFD3 */  bnez      $v0, .LE00C629C
/* 3CCD30 E00C6350 2610007C */   addiu    $s0, $s0, 0x7c
.LE00C6354:
/* 3CCD34 E00C6354 0280102D */  daddu     $v0, $s4, $zero
/* 3CCD38 E00C6358 8FBF0040 */  lw        $ra, 0x40($sp)
/* 3CCD3C E00C635C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 3CCD40 E00C6360 8FB40038 */  lw        $s4, 0x38($sp)
/* 3CCD44 E00C6364 8FB30034 */  lw        $s3, 0x34($sp)
/* 3CCD48 E00C6368 8FB20030 */  lw        $s2, 0x30($sp)
/* 3CCD4C E00C636C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3CCD50 E00C6370 8FB00028 */  lw        $s0, 0x28($sp)
/* 3CCD54 E00C6374 D7BE0070 */  ldc1      $f30, 0x70($sp)
/* 3CCD58 E00C6378 D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 3CCD5C E00C637C D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 3CCD60 E00C6380 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 3CCD64 E00C6384 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 3CCD68 E00C6388 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 3CCD6C E00C638C 03E00008 */  jr        $ra
/* 3CCD70 E00C6390 27BD0078 */   addiu    $sp, $sp, 0x78
