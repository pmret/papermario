.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D6000
/* 3D5020 E00D6000 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 3D5024 E00D6004 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 3D5028 E00D6008 4485A000 */  mtc1      $a1, $f20
/* 3D502C E00D600C F7B60068 */  sdc1      $f22, 0x68($sp)
/* 3D5030 E00D6010 4486B000 */  mtc1      $a2, $f22
/* 3D5034 E00D6014 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 3D5038 E00D6018 4487C000 */  mtc1      $a3, $f24
/* 3D503C E00D601C AFB70054 */  sw        $s7, 0x54($sp)
/* 3D5040 E00D6020 0080B82D */  daddu     $s7, $a0, $zero
/* 3D5044 E00D6024 AFB00038 */  sw        $s0, 0x38($sp)
/* 3D5048 E00D6028 8FB0009C */  lw        $s0, 0x9c($sp)
/* 3D504C E00D602C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D5050 E00D6030 AFBF005C */  sw        $ra, 0x5c($sp)
/* 3D5054 E00D6034 AFBE0058 */  sw        $fp, 0x58($sp)
/* 3D5058 E00D6038 AFB60050 */  sw        $s6, 0x50($sp)
/* 3D505C E00D603C AFB5004C */  sw        $s5, 0x4c($sp)
/* 3D5060 E00D6040 AFB40048 */  sw        $s4, 0x48($sp)
/* 3D5064 E00D6044 AFB30044 */  sw        $s3, 0x44($sp)
/* 3D5068 E00D6048 AFB20040 */  sw        $s2, 0x40($sp)
/* 3D506C E00D604C AFB1003C */  sw        $s1, 0x3c($sp)
/* 3D5070 E00D6050 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 3D5074 E00D6054 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 3D5078 E00D6058 3C08E00D */  lui       $t0, %hi(D_E00D6E74)
/* 3D507C E00D605C 01174021 */  addu      $t0, $t0, $s7
/* 3D5080 E00D6060 91086E74 */  lbu       $t0, %lo(D_E00D6E74)($t0)
/* 3D5084 E00D6064 3C02E00D */  lui       $v0, %hi(func_E00D6718)
/* 3D5088 E00D6068 24426718 */  addiu     $v0, $v0, %lo(func_E00D6718)
/* 3D508C E00D606C AFA20018 */  sw        $v0, 0x18($sp)
/* 3D5090 E00D6070 3C02E00D */  lui       $v0, %hi(func_E00D6720)
/* 3D5094 E00D6074 24426720 */  addiu     $v0, $v0, %lo(func_E00D6720)
/* 3D5098 E00D6078 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D509C E00D607C 3C02E00D */  lui       $v0, %hi(func_E00D693C)
/* 3D50A0 E00D6080 2442693C */  addiu     $v0, $v0, %lo(func_E00D693C)
/* 3D50A4 E00D6084 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D50A8 E00D6088 2402006B */  addiu     $v0, $zero, 0x6b
/* 3D50AC E00D608C AFA00010 */  sw        $zero, 0x10($sp)
/* 3D50B0 E00D6090 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D50B4 E00D6094 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D50B8 E00D6098 0C080124 */  jal       func_E0200490
/* 3D50BC E00D609C AFA8002C */   sw       $t0, 0x2c($sp)
/* 3D50C0 E00D60A0 8FA9002C */  lw        $t1, 0x2c($sp)
/* 3D50C4 E00D60A4 AFA20028 */  sw        $v0, 0x28($sp)
/* 3D50C8 E00D60A8 000920C0 */  sll       $a0, $t1, 3
/* 3D50CC E00D60AC 00892021 */  addu      $a0, $a0, $t1
/* 3D50D0 E00D60B0 000420C0 */  sll       $a0, $a0, 3
/* 3D50D4 E00D60B4 0C08012C */  jal       func_E02004B0
/* 3D50D8 E00D60B8 AC490008 */   sw       $t1, 8($v0)
/* 3D50DC E00D60BC 0040902D */  daddu     $s2, $v0, $zero
/* 3D50E0 E00D60C0 8FA80028 */  lw        $t0, 0x28($sp)
/* 3D50E4 E00D60C4 0240A02D */  daddu     $s4, $s2, $zero
/* 3D50E8 E00D60C8 16400003 */  bnez      $s2, .LE00D60D8
/* 3D50EC E00D60CC AD12000C */   sw       $s2, 0xc($t0)
.LE00D60D0:
/* 3D50F0 E00D60D0 08035834 */  j         .LE00D60D0
/* 3D50F4 E00D60D4 00000000 */   nop
.LE00D60D8:
/* 3D50F8 E00D60D8 AE570000 */  sw        $s7, ($s2)
/* 3D50FC E00D60DC 1E000004 */  bgtz      $s0, .LE00D60F0
/* 3D5100 E00D60E0 AE400014 */   sw       $zero, 0x14($s2)
/* 3D5104 E00D60E4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D5108 E00D60E8 0803583D */  j         .LE00D60F4
/* 3D510C E00D60EC AE420010 */   sw       $v0, 0x10($s2)
.LE00D60F0:
/* 3D5110 E00D60F0 AE500010 */  sw        $s0, 0x10($s2)
.LE00D60F4:
/* 3D5114 E00D60F4 24040168 */  addiu     $a0, $zero, 0x168
/* 3D5118 E00D60F8 AE400024 */  sw        $zero, 0x24($s2)
/* 3D511C E00D60FC E6540004 */  swc1      $f20, 4($s2)
/* 3D5120 E00D6100 E6560008 */  swc1      $f22, 8($s2)
/* 3D5124 E00D6104 E658000C */  swc1      $f24, 0xc($s2)
/* 3D5128 E00D6108 C7A00098 */  lwc1      $f0, 0x98($sp)
/* 3D512C E00D610C 240200FF */  addiu     $v0, $zero, 0xff
/* 3D5130 E00D6110 AE420018 */  sw        $v0, 0x18($s2)
/* 3D5134 E00D6114 AE42001C */  sw        $v0, 0x1c($s2)
/* 3D5138 E00D6118 AE420020 */  sw        $v0, 0x20($s2)
/* 3D513C E00D611C AE420028 */  sw        $v0, 0x28($s2)
/* 3D5140 E00D6120 E6400034 */  swc1      $f0, 0x34($s2)
/* 3D5144 E00D6124 3C013F80 */  lui       $at, 0x3f80
/* 3D5148 E00D6128 44810000 */  mtc1      $at, $f0
/* 3D514C E00D612C 240200F5 */  addiu     $v0, $zero, 0xf5
/* 3D5150 E00D6130 AE42002C */  sw        $v0, 0x2c($s2)
/* 3D5154 E00D6134 AE400030 */  sw        $zero, 0x30($s2)
/* 3D5158 E00D6138 E6400044 */  swc1      $f0, 0x44($s2)
/* 3D515C E00D613C 3C02E00D */  lui       $v0, %hi(D_E00D6E84)
/* 3D5160 E00D6140 00571021 */  addu      $v0, $v0, $s7
/* 3D5164 E00D6144 90426E84 */  lbu       $v0, %lo(D_E00D6E84)($v0)
/* 3D5168 E00D6148 24110001 */  addiu     $s1, $zero, 1
/* 3D516C E00D614C 44820000 */  mtc1      $v0, $f0
/* 3D5170 E00D6150 00000000 */  nop
/* 3D5174 E00D6154 46800020 */  cvt.s.w   $f0, $f0
/* 3D5178 E00D6158 0C080138 */  jal       func_E02004E0
/* 3D517C E00D615C E6400038 */   swc1     $f0, 0x38($s2)
/* 3D5180 E00D6160 8FA90028 */  lw        $t1, 0x28($sp)
/* 3D5184 E00D6164 8D230008 */  lw        $v1, 8($t1)
/* 3D5188 E00D6168 4482E000 */  mtc1      $v0, $f28
/* 3D518C E00D616C 00000000 */  nop
/* 3D5190 E00D6170 4680E720 */  cvt.s.w   $f28, $f28
/* 3D5194 E00D6174 0223182A */  slt       $v1, $s1, $v1
/* 3D5198 E00D6178 10600155 */  beqz      $v1, .LE00D66D0
/* 3D519C E00D617C 26520048 */   addiu    $s2, $s2, 0x48
/* 3D51A0 E00D6180 3C135555 */  lui       $s3, 0x5555
/* 3D51A4 E00D6184 36735556 */  ori       $s3, $s3, 0x5556
/* 3D51A8 E00D6188 24160014 */  addiu     $s6, $zero, 0x14
/* 3D51AC E00D618C 241E000A */  addiu     $fp, $zero, 0xa
/* 3D51B0 E00D6190 2650003C */  addiu     $s0, $s2, 0x3c
/* 3D51B4 E00D6194 0000A82D */  daddu     $s5, $zero, $zero
/* 3D51B8 E00D6198 001717C3 */  sra       $v0, $s7, 0x1f
/* 3D51BC E00D619C 02F30018 */  mult      $s7, $s3
/* 3D51C0 E00D61A0 3C01E00D */  lui       $at, %hi(D_E00D6EA0)
/* 3D51C4 E00D61A4 D4366EA0 */  ldc1      $f22, %lo(D_E00D6EA0)($at)
/* 3D51C8 E00D61A8 3C01E00D */  lui       $at, %hi(D_E00D6EA8)
/* 3D51CC E00D61AC D43A6EA8 */  ldc1      $f26, %lo(D_E00D6EA8)($at)
/* 3D51D0 E00D61B0 3C013FF0 */  lui       $at, 0x3ff0
/* 3D51D4 E00D61B4 4481A800 */  mtc1      $at, $f21
/* 3D51D8 E00D61B8 4480A000 */  mtc1      $zero, $f20
/* 3D51DC E00D61BC 3C01E00D */  lui       $at, %hi(D_E00D6EB0)
/* 3D51E0 E00D61C0 D4386EB0 */  ldc1      $f24, %lo(D_E00D6EB0)($at)
/* 3D51E4 E00D61C4 00004010 */  mfhi      $t0
/* 3D51E8 E00D61C8 01024023 */  subu      $t0, $t0, $v0
/* 3D51EC E00D61CC AFA80030 */  sw        $t0, 0x30($sp)
.LE00D61D0:
/* 3D51F0 E00D61D0 8FA90030 */  lw        $t1, 0x30($sp)
/* 3D51F4 E00D61D4 00091040 */  sll       $v0, $t1, 1
/* 3D51F8 E00D61D8 00491021 */  addu      $v0, $v0, $t1
/* 3D51FC E00D61DC 02E21023 */  subu      $v0, $s7, $v0
/* 3D5200 E00D61E0 AE420000 */  sw        $v0, ($s2)
/* 3D5204 E00D61E4 2EE2000D */  sltiu     $v0, $s7, 0xd
/* 3D5208 E00D61E8 1040010C */  beqz      $v0, .LE00D661C
/* 3D520C E00D61EC 00171080 */   sll      $v0, $s7, 2
/* 3D5210 E00D61F0 3C01E00D */  lui       $at, %hi(jtbl_E00D6EB8)
/* 3D5214 E00D61F4 00220821 */  addu      $at, $at, $v0
/* 3D5218 E00D61F8 8C226EB8 */  lw        $v0, %lo(jtbl_E00D6EB8)($at)
/* 3D521C E00D61FC 00400008 */  jr        $v0
/* 3D5220 E00D6200 00000000 */   nop
glabel LE00D6204_3D5224
/* 3D5224 E00D6204 0C080138 */  jal       func_E02004E0
/* 3D5228 E00D6208 2404000A */   addiu    $a0, $zero, 0xa
/* 3D522C E00D620C 44821000 */  mtc1      $v0, $f2
/* 3D5230 E00D6210 00000000 */  nop
/* 3D5234 E00D6214 468010A1 */  cvt.d.w   $f2, $f2
/* 3D5238 E00D6218 46361082 */  mul.d     $f2, $f2, $f22
/* 3D523C E00D621C 00000000 */  nop
/* 3D5240 E00D6220 02330018 */  mult      $s1, $s3
/* 3D5244 E00D6224 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D5248 E00D6228 00004010 */  mfhi      $t0
/* 3D524C E00D622C 01031823 */  subu      $v1, $t0, $v1
/* 3D5250 E00D6230 00031040 */  sll       $v0, $v1, 1
/* 3D5254 E00D6234 00431021 */  addu      $v0, $v0, $v1
/* 3D5258 E00D6238 02221023 */  subu      $v0, $s1, $v0
/* 3D525C E00D623C 44820000 */  mtc1      $v0, $f0
/* 3D5260 E00D6240 00000000 */  nop
/* 3D5264 E00D6244 46800021 */  cvt.d.w   $f0, $f0
/* 3D5268 E00D6248 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D526C E00D624C 00000000 */  nop
/* 3D5270 E00D6250 46361080 */  add.d     $f2, $f2, $f22
/* 3D5274 E00D6254 AE16FFD4 */  sw        $s6, -0x2c($s0)
/* 3D5278 E00D6258 AE000004 */  sw        $zero, 4($s0)
/* 3D527C E00D625C 08035982 */  j         .LE00D6608
/* 3D5280 E00D6260 46201087 */   neg.d    $f2, $f2
glabel LE00D6264_3D5284
/* 3D5284 E00D6264 0C080138 */  jal       func_E02004E0
/* 3D5288 E00D6268 2404000A */   addiu    $a0, $zero, 0xa
/* 3D528C E00D626C 44821000 */  mtc1      $v0, $f2
/* 3D5290 E00D6270 00000000 */  nop
/* 3D5294 E00D6274 468010A1 */  cvt.d.w   $f2, $f2
/* 3D5298 E00D6278 46361082 */  mul.d     $f2, $f2, $f22
/* 3D529C E00D627C 00000000 */  nop
/* 3D52A0 E00D6280 02330018 */  mult      $s1, $s3
/* 3D52A4 E00D6284 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D52A8 E00D6288 00004010 */  mfhi      $t0
/* 3D52AC E00D628C 01031823 */  subu      $v1, $t0, $v1
/* 3D52B0 E00D6290 00031040 */  sll       $v0, $v1, 1
/* 3D52B4 E00D6294 00431021 */  addu      $v0, $v0, $v1
/* 3D52B8 E00D6298 02221023 */  subu      $v0, $s1, $v0
/* 3D52BC E00D629C 44820000 */  mtc1      $v0, $f0
/* 3D52C0 E00D62A0 00000000 */  nop
/* 3D52C4 E00D62A4 46800021 */  cvt.d.w   $f0, $f0
/* 3D52C8 E00D62A8 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D52CC E00D62AC 00000000 */  nop
/* 3D52D0 E00D62B0 46361080 */  add.d     $f2, $f2, $f22
/* 3D52D4 E00D62B4 AE16FFD4 */  sw        $s6, -0x2c($s0)
/* 3D52D8 E00D62B8 08035982 */  j         .LE00D6608
/* 3D52DC E00D62BC AE000004 */   sw       $zero, 4($s0)
glabel LE00D62C0_3D52E0
/* 3D52E0 E00D62C0 0C080138 */  jal       func_E02004E0
/* 3D52E4 E00D62C4 2404000A */   addiu    $a0, $zero, 0xa
/* 3D52E8 E00D62C8 02330018 */  mult      $s1, $s3
/* 3D52EC E00D62CC 001127C3 */  sra       $a0, $s1, 0x1f
/* 3D52F0 E00D62D0 00004010 */  mfhi      $t0
/* 3D52F4 E00D62D4 01042023 */  subu      $a0, $t0, $a0
/* 3D52F8 E00D62D8 00041840 */  sll       $v1, $a0, 1
/* 3D52FC E00D62DC 00641821 */  addu      $v1, $v1, $a0
/* 3D5300 E00D62E0 02231823 */  subu      $v1, $s1, $v1
/* 3D5304 E00D62E4 44830000 */  mtc1      $v1, $f0
/* 3D5308 E00D62E8 00000000 */  nop
/* 3D530C E00D62EC 46800021 */  cvt.d.w   $f0, $f0
/* 3D5310 E00D62F0 46380002 */  mul.d     $f0, $f0, $f24
/* 3D5314 E00D62F4 00000000 */  nop
/* 3D5318 E00D62F8 24420004 */  addiu     $v0, $v0, 4
/* 3D531C E00D62FC 00021023 */  negu      $v0, $v0
/* 3D5320 E00D6300 44821000 */  mtc1      $v0, $f2
/* 3D5324 E00D6304 00000000 */  nop
/* 3D5328 E00D6308 468010A0 */  cvt.s.w   $f2, $f2
/* 3D532C E00D630C E602FFFC */  swc1      $f2, -4($s0)
/* 3D5330 E00D6310 4620A001 */  sub.d     $f0, $f20, $f0
/* 3D5334 E00D6314 AE1EFFD4 */  sw        $fp, -0x2c($s0)
/* 3D5338 E00D6318 08035985 */  j         .LE00D6614
/* 3D533C E00D631C AE000004 */   sw       $zero, 4($s0)
glabel LE00D6320_3D5340
/* 3D5340 E00D6320 0C080138 */  jal       func_E02004E0
/* 3D5344 E00D6324 2404000A */   addiu    $a0, $zero, 0xa
/* 3D5348 E00D6328 02330018 */  mult      $s1, $s3
/* 3D534C E00D632C 001127C3 */  sra       $a0, $s1, 0x1f
/* 3D5350 E00D6330 00004010 */  mfhi      $t0
/* 3D5354 E00D6334 01042023 */  subu      $a0, $t0, $a0
/* 3D5358 E00D6338 00041840 */  sll       $v1, $a0, 1
/* 3D535C E00D633C 00641821 */  addu      $v1, $v1, $a0
/* 3D5360 E00D6340 02231823 */  subu      $v1, $s1, $v1
/* 3D5364 E00D6344 44830000 */  mtc1      $v1, $f0
/* 3D5368 E00D6348 00000000 */  nop
/* 3D536C E00D634C 46800021 */  cvt.d.w   $f0, $f0
/* 3D5370 E00D6350 46380002 */  mul.d     $f0, $f0, $f24
/* 3D5374 E00D6354 00000000 */  nop
/* 3D5378 E00D6358 24420004 */  addiu     $v0, $v0, 4
/* 3D537C E00D635C 00021023 */  negu      $v0, $v0
/* 3D5380 E00D6360 44821000 */  mtc1      $v0, $f2
/* 3D5384 E00D6364 00000000 */  nop
/* 3D5388 E00D6368 468010A0 */  cvt.s.w   $f2, $f2
/* 3D538C E00D636C E602FFFC */  swc1      $f2, -4($s0)
/* 3D5390 E00D6370 4620A001 */  sub.d     $f0, $f20, $f0
/* 3D5394 E00D6374 AE1EFFD4 */  sw        $fp, -0x2c($s0)
/* 3D5398 E00D6378 08035985 */  j         .LE00D6614
/* 3D539C E00D637C AE000004 */   sw       $zero, 4($s0)
glabel LE00D6380_3D53A0
/* 3D53A0 E00D6380 0C080138 */  jal       func_E02004E0
/* 3D53A4 E00D6384 2404000A */   addiu    $a0, $zero, 0xa
/* 3D53A8 E00D6388 44821000 */  mtc1      $v0, $f2
/* 3D53AC E00D638C 00000000 */  nop
/* 3D53B0 E00D6390 468010A1 */  cvt.d.w   $f2, $f2
/* 3D53B4 E00D6394 46361082 */  mul.d     $f2, $f2, $f22
/* 3D53B8 E00D6398 00000000 */  nop
/* 3D53BC E00D639C 02330018 */  mult      $s1, $s3
/* 3D53C0 E00D63A0 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D53C4 E00D63A4 00004010 */  mfhi      $t0
/* 3D53C8 E00D63A8 01031823 */  subu      $v1, $t0, $v1
/* 3D53CC E00D63AC 00031040 */  sll       $v0, $v1, 1
/* 3D53D0 E00D63B0 00431021 */  addu      $v0, $v0, $v1
/* 3D53D4 E00D63B4 02221023 */  subu      $v0, $s1, $v0
/* 3D53D8 E00D63B8 44820000 */  mtc1      $v0, $f0
/* 3D53DC E00D63BC 00000000 */  nop
/* 3D53E0 E00D63C0 46800021 */  cvt.d.w   $f0, $f0
/* 3D53E4 E00D63C4 46380002 */  mul.d     $f0, $f0, $f24
/* 3D53E8 E00D63C8 00000000 */  nop
/* 3D53EC E00D63CC 3C01E00D */  lui       $at, %hi(D_E00D6EF0)
/* 3D53F0 E00D63D0 D4246EF0 */  ldc1      $f4, %lo(D_E00D6EF0)($at)
/* 3D53F4 E00D63D4 3C01BF80 */  lui       $at, 0xbf80
/* 3D53F8 E00D63D8 44813000 */  mtc1      $at, $f6
/* 3D53FC E00D63DC 08035980 */  j         .LE00D6600
/* 3D5400 E00D63E0 46241080 */   add.d    $f2, $f2, $f4
glabel LE00D63E4_3D5404
/* 3D5404 E00D63E4 0C080138 */  jal       func_E02004E0
/* 3D5408 E00D63E8 2404000A */   addiu    $a0, $zero, 0xa
/* 3D540C E00D63EC 44821000 */  mtc1      $v0, $f2
/* 3D5410 E00D63F0 00000000 */  nop
/* 3D5414 E00D63F4 468010A1 */  cvt.d.w   $f2, $f2
/* 3D5418 E00D63F8 46361082 */  mul.d     $f2, $f2, $f22
/* 3D541C E00D63FC 00000000 */  nop
/* 3D5420 E00D6400 02330018 */  mult      $s1, $s3
/* 3D5424 E00D6404 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D5428 E00D6408 00004010 */  mfhi      $t0
/* 3D542C E00D640C 01031823 */  subu      $v1, $t0, $v1
/* 3D5430 E00D6410 00031040 */  sll       $v0, $v1, 1
/* 3D5434 E00D6414 00431021 */  addu      $v0, $v0, $v1
/* 3D5438 E00D6418 02221023 */  subu      $v0, $s1, $v0
/* 3D543C E00D641C 44820000 */  mtc1      $v0, $f0
/* 3D5440 E00D6420 00000000 */  nop
/* 3D5444 E00D6424 46800021 */  cvt.d.w   $f0, $f0
/* 3D5448 E00D6428 46380002 */  mul.d     $f0, $f0, $f24
/* 3D544C E00D642C 00000000 */  nop
/* 3D5450 E00D6430 3C01E00D */  lui       $at, %hi(D_E00D6EF8)
/* 3D5454 E00D6434 D4246EF8 */  ldc1      $f4, %lo(D_E00D6EF8)($at)
/* 3D5458 E00D6438 3C01C000 */  lui       $at, 0xc000
/* 3D545C E00D643C 44813000 */  mtc1      $at, $f6
/* 3D5460 E00D6440 AE16FFD4 */  sw        $s6, -0x2c($s0)
/* 3D5464 E00D6444 46241080 */  add.d     $f2, $f2, $f4
/* 3D5468 E00D6448 E6060004 */  swc1      $f6, 4($s0)
/* 3D546C E00D644C 240200FF */  addiu     $v0, $zero, 0xff
/* 3D5470 E00D6450 46201087 */  neg.d     $f2, $f2
/* 3D5474 E00D6454 4620A001 */  sub.d     $f0, $f20, $f0
/* 3D5478 E00D6458 462010A0 */  cvt.s.d   $f2, $f2
/* 3D547C E00D645C E602FFFC */  swc1      $f2, -4($s0)
/* 3D5480 E00D6460 46200020 */  cvt.s.d   $f0, $f0
/* 3D5484 E00D6464 E600FFF8 */  swc1      $f0, -8($s0)
/* 3D5488 E00D6468 AE820018 */  sw        $v0, 0x18($s4)
/* 3D548C E00D646C 240200F5 */  addiu     $v0, $zero, 0xf5
/* 3D5490 E00D6470 AE82001C */  sw        $v0, 0x1c($s4)
/* 3D5494 E00D6474 240200D7 */  addiu     $v0, $zero, 0xd7
/* 3D5498 E00D6478 AE820020 */  sw        $v0, 0x20($s4)
/* 3D549C E00D647C 240200DC */  addiu     $v0, $zero, 0xdc
/* 3D54A0 E00D6480 AE820028 */  sw        $v0, 0x28($s4)
/* 3D54A4 E00D6484 2402003C */  addiu     $v0, $zero, 0x3c
/* 3D54A8 E00D6488 AE82002C */  sw        $v0, 0x2c($s4)
/* 3D54AC E00D648C 08035987 */  j         .LE00D661C
/* 3D54B0 E00D6490 AE9E0030 */   sw       $fp, 0x30($s4)
glabel LE00D6494_3D54B4
/* 3D54B4 E00D6494 0C080138 */  jal       func_E02004E0
/* 3D54B8 E00D6498 2404000A */   addiu    $a0, $zero, 0xa
/* 3D54BC E00D649C 44821000 */  mtc1      $v0, $f2
/* 3D54C0 E00D64A0 00000000 */  nop
/* 3D54C4 E00D64A4 468010A1 */  cvt.d.w   $f2, $f2
/* 3D54C8 E00D64A8 463A1082 */  mul.d     $f2, $f2, $f26
/* 3D54CC E00D64AC 00000000 */  nop
/* 3D54D0 E00D64B0 02330018 */  mult      $s1, $s3
/* 3D54D4 E00D64B4 001127C3 */  sra       $a0, $s1, 0x1f
/* 3D54D8 E00D64B8 00004010 */  mfhi      $t0
/* 3D54DC E00D64BC 01042023 */  subu      $a0, $t0, $a0
/* 3D54E0 E00D64C0 00041840 */  sll       $v1, $a0, 1
/* 3D54E4 E00D64C4 00641821 */  addu      $v1, $v1, $a0
/* 3D54E8 E00D64C8 02231823 */  subu      $v1, $s1, $v1
/* 3D54EC E00D64CC 44832000 */  mtc1      $v1, $f4
/* 3D54F0 E00D64D0 00000000 */  nop
/* 3D54F4 E00D64D4 46802121 */  cvt.d.w   $f4, $f4
/* 3D54F8 E00D64D8 46382102 */  mul.d     $f4, $f4, $f24
/* 3D54FC E00D64DC 00000000 */  nop
/* 3D5500 E00D64E0 4624A101 */  sub.d     $f4, $f20, $f4
/* 3D5504 E00D64E4 3C013FE0 */  lui       $at, 0x3fe0
/* 3D5508 E00D64E8 44810800 */  mtc1      $at, $f1
/* 3D550C E00D64EC 44800000 */  mtc1      $zero, $f0
/* 3D5510 E00D64F0 00000000 */  nop
/* 3D5514 E00D64F4 46202102 */  mul.d     $f4, $f4, $f0
/* 3D5518 E00D64F8 00000000 */  nop
/* 3D551C E00D64FC 3C014000 */  lui       $at, 0x4000
/* 3D5520 E00D6500 44810800 */  mtc1      $at, $f1
/* 3D5524 E00D6504 44800000 */  mtc1      $zero, $f0
/* 3D5528 E00D6508 00000000 */  nop
/* 3D552C E00D650C 46201080 */  add.d     $f2, $f2, $f0
/* 3D5530 E00D6510 AE1EFFD4 */  sw        $fp, -0x2c($s0)
/* 3D5534 E00D6514 AE000004 */  sw        $zero, 4($s0)
/* 3D5538 E00D6518 462010A0 */  cvt.s.d   $f2, $f2
/* 3D553C E00D651C E602FFFC */  swc1      $f2, -4($s0)
/* 3D5540 E00D6520 46202120 */  cvt.s.d   $f4, $f4
/* 3D5544 E00D6524 08035987 */  j         .LE00D661C
/* 3D5548 E00D6528 E604FFF8 */   swc1     $f4, -8($s0)
glabel LE00D652C_3D554C
/* 3D554C E00D652C 0C080138 */  jal       func_E02004E0
/* 3D5550 E00D6530 2404000A */   addiu    $a0, $zero, 0xa
/* 3D5554 E00D6534 3C01E00D */  lui       $at, %hi(D_E00D6F00)
/* 3D5558 E00D6538 D4206F00 */  ldc1      $f0, %lo(D_E00D6F00)($at)
/* 3D555C E00D653C 44821000 */  mtc1      $v0, $f2
/* 3D5560 E00D6540 00000000 */  nop
/* 3D5564 E00D6544 468010A1 */  cvt.d.w   $f2, $f2
/* 3D5568 E00D6548 46201082 */  mul.d     $f2, $f2, $f0
/* 3D556C E00D654C 00000000 */  nop
/* 3D5570 E00D6550 02330018 */  mult      $s1, $s3
/* 3D5574 E00D6554 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D5578 E00D6558 00004010 */  mfhi      $t0
/* 3D557C E00D655C 01031823 */  subu      $v1, $t0, $v1
/* 3D5580 E00D6560 00031040 */  sll       $v0, $v1, 1
/* 3D5584 E00D6564 00431021 */  addu      $v0, $v0, $v1
/* 3D5588 E00D6568 02221023 */  subu      $v0, $s1, $v0
/* 3D558C E00D656C 44820000 */  mtc1      $v0, $f0
/* 3D5590 E00D6570 00000000 */  nop
/* 3D5594 E00D6574 46800021 */  cvt.d.w   $f0, $f0
/* 3D5598 E00D6578 46380002 */  mul.d     $f0, $f0, $f24
/* 3D559C E00D657C 00000000 */  nop
/* 3D55A0 E00D6580 3C01BF80 */  lui       $at, 0xbf80
/* 3D55A4 E00D6584 44812000 */  mtc1      $at, $f4
/* 3D55A8 E00D6588 00000000 */  nop
/* 3D55AC E00D658C E6040004 */  swc1      $f4, 4($s0)
/* 3D55B0 E00D6590 46361080 */  add.d     $f2, $f2, $f22
/* 3D55B4 E00D6594 2402001E */  addiu     $v0, $zero, 0x1e
/* 3D55B8 E00D6598 08035982 */  j         .LE00D6608
/* 3D55BC E00D659C AE02FFD4 */   sw       $v0, -0x2c($s0)
glabel LE00D65A0_3D55C0
/* 3D55C0 E00D65A0 0C080138 */  jal       func_E02004E0
/* 3D55C4 E00D65A4 2404000A */   addiu    $a0, $zero, 0xa
/* 3D55C8 E00D65A8 44821000 */  mtc1      $v0, $f2
/* 3D55CC E00D65AC 00000000 */  nop
/* 3D55D0 E00D65B0 468010A1 */  cvt.d.w   $f2, $f2
/* 3D55D4 E00D65B4 46361082 */  mul.d     $f2, $f2, $f22
/* 3D55D8 E00D65B8 00000000 */  nop
/* 3D55DC E00D65BC 02330018 */  mult      $s1, $s3
/* 3D55E0 E00D65C0 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D55E4 E00D65C4 00004010 */  mfhi      $t0
/* 3D55E8 E00D65C8 01031823 */  subu      $v1, $t0, $v1
/* 3D55EC E00D65CC 00031040 */  sll       $v0, $v1, 1
/* 3D55F0 E00D65D0 00431021 */  addu      $v0, $v0, $v1
/* 3D55F4 E00D65D4 02221023 */  subu      $v0, $s1, $v0
/* 3D55F8 E00D65D8 44820000 */  mtc1      $v0, $f0
/* 3D55FC E00D65DC 00000000 */  nop
/* 3D5600 E00D65E0 46800021 */  cvt.d.w   $f0, $f0
/* 3D5604 E00D65E4 46380002 */  mul.d     $f0, $f0, $f24
/* 3D5608 E00D65E8 00000000 */  nop
/* 3D560C E00D65EC 3C01E00D */  lui       $at, %hi(D_E00D6F08)
/* 3D5610 E00D65F0 D4246F08 */  ldc1      $f4, %lo(D_E00D6F08)($at)
/* 3D5614 E00D65F4 3C01C000 */  lui       $at, 0xc000
/* 3D5618 E00D65F8 44813000 */  mtc1      $at, $f6
/* 3D561C E00D65FC 46241080 */  add.d     $f2, $f2, $f4
.LE00D6600:
/* 3D5620 E00D6600 AE16FFD4 */  sw        $s6, -0x2c($s0)
/* 3D5624 E00D6604 E6060004 */  swc1      $f6, 4($s0)
.LE00D6608:
/* 3D5628 E00D6608 4620A001 */  sub.d     $f0, $f20, $f0
/* 3D562C E00D660C 462010A0 */  cvt.s.d   $f2, $f2
/* 3D5630 E00D6610 E602FFFC */  swc1      $f2, -4($s0)
.LE00D6614:
/* 3D5634 E00D6614 46200020 */  cvt.s.d   $f0, $f0
/* 3D5638 E00D6618 E600FFF8 */  swc1      $f0, -8($s0)
.LE00D661C:
/* 3D563C E00D661C 0C080138 */  jal       func_E02004E0
/* 3D5640 E00D6620 8E04FFD4 */   lw       $a0, -0x2c($s0)
/* 3D5644 E00D6624 C602FFFC */  lwc1      $f2, -4($s0)
/* 3D5648 E00D6628 44800000 */  mtc1      $zero, $f0
/* 3D564C E00D662C 00021823 */  negu      $v1, $v0
/* 3D5650 E00D6630 4600103C */  c.lt.s    $f2, $f0
/* 3D5654 E00D6634 00000000 */  nop
/* 3D5658 E00D6638 45000004 */  bc1f      .LE00D664C
/* 3D565C E00D663C AE03FFD8 */   sw       $v1, -0x28($s0)
/* 3D5660 E00D6640 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3D5664 E00D6644 46001087 */  neg.s     $f2, $f2
/* 3D5668 E00D6648 00431023 */  subu      $v0, $v0, $v1
.LE00D664C:
/* 3D566C E00D664C 44820000 */  mtc1      $v0, $f0
/* 3D5670 E00D6650 00000000 */  nop
/* 3D5674 E00D6654 46800020 */  cvt.s.w   $f0, $f0
/* 3D5678 E00D6658 46020002 */  mul.s     $f0, $f0, $f2
/* 3D567C E00D665C 00000000 */  nop
/* 3D5680 E00D6660 E600FFC8 */  swc1      $f0, -0x38($s0)
/* 3D5684 E00D6664 8FA9002C */  lw        $t1, 0x2c($sp)
/* 3D5688 E00D6668 2522FFFF */  addiu     $v0, $t1, -1
/* 3D568C E00D666C 14400002 */  bnez      $v0, .LE00D6678
/* 3D5690 E00D6670 02A2001A */   div      $zero, $s5, $v0
/* 3D5694 E00D6674 0007000D */  break     7
.LE00D6678:
/* 3D5698 E00D6678 2401FFFF */   addiu    $at, $zero, -1
/* 3D569C E00D667C 14410004 */  bne       $v0, $at, .LE00D6690
/* 3D56A0 E00D6680 3C018000 */   lui      $at, 0x8000
/* 3D56A4 E00D6684 16A10002 */  bne       $s5, $at, .LE00D6690
/* 3D56A8 E00D6688 00000000 */   nop
/* 3D56AC E00D668C 0006000D */  break     6
.LE00D6690:
/* 3D56B0 E00D6690 00001012 */   mflo     $v0
/* 3D56B4 E00D6694 26310001 */  addiu     $s1, $s1, 1
/* 3D56B8 E00D6698 26520048 */  addiu     $s2, $s2, 0x48
/* 3D56BC E00D669C 44820000 */  mtc1      $v0, $f0
/* 3D56C0 E00D66A0 00000000 */  nop
/* 3D56C4 E00D66A4 46800020 */  cvt.s.w   $f0, $f0
/* 3D56C8 E00D66A8 461C0000 */  add.s     $f0, $f0, $f28
/* 3D56CC E00D66AC AE00FFCC */  sw        $zero, -0x34($s0)
/* 3D56D0 E00D66B0 AE00FFD0 */  sw        $zero, -0x30($s0)
/* 3D56D4 E00D66B4 E6000000 */  swc1      $f0, ($s0)
/* 3D56D8 E00D66B8 8FA80028 */  lw        $t0, 0x28($sp)
/* 3D56DC E00D66BC 26B50168 */  addiu     $s5, $s5, 0x168
/* 3D56E0 E00D66C0 8D020008 */  lw        $v0, 8($t0)
/* 3D56E4 E00D66C4 0222102A */  slt       $v0, $s1, $v0
/* 3D56E8 E00D66C8 1440FEC1 */  bnez      $v0, .LE00D61D0
/* 3D56EC E00D66CC 26100048 */   addiu    $s0, $s0, 0x48
.LE00D66D0:
/* 3D56F0 E00D66D0 8FA20028 */  lw        $v0, 0x28($sp)
/* 3D56F4 E00D66D4 8FBF005C */  lw        $ra, 0x5c($sp)
/* 3D56F8 E00D66D8 8FBE0058 */  lw        $fp, 0x58($sp)
/* 3D56FC E00D66DC 8FB70054 */  lw        $s7, 0x54($sp)
/* 3D5700 E00D66E0 8FB60050 */  lw        $s6, 0x50($sp)
/* 3D5704 E00D66E4 8FB5004C */  lw        $s5, 0x4c($sp)
/* 3D5708 E00D66E8 8FB40048 */  lw        $s4, 0x48($sp)
/* 3D570C E00D66EC 8FB30044 */  lw        $s3, 0x44($sp)
/* 3D5710 E00D66F0 8FB20040 */  lw        $s2, 0x40($sp)
/* 3D5714 E00D66F4 8FB1003C */  lw        $s1, 0x3c($sp)
/* 3D5718 E00D66F8 8FB00038 */  lw        $s0, 0x38($sp)
/* 3D571C E00D66FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 3D5720 E00D6700 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 3D5724 E00D6704 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 3D5728 E00D6708 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 3D572C E00D670C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 3D5730 E00D6710 03E00008 */  jr        $ra
/* 3D5734 E00D6714 27BD0088 */   addiu    $sp, $sp, 0x88
