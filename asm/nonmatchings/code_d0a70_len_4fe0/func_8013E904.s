.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013E904
/* D5004 8013E904 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D5008 8013E908 AFB40020 */  sw        $s4, 0x20($sp)
/* D500C 8013E90C 0080A02D */  daddu     $s4, $a0, $zero
/* D5010 8013E910 24050002 */  addiu     $a1, $zero, 2
/* D5014 8013E914 AFBF002C */  sw        $ra, 0x2c($sp)
/* D5018 8013E918 AFB60028 */  sw        $s6, 0x28($sp)
/* D501C 8013E91C AFB50024 */  sw        $s5, 0x24($sp)
/* D5020 8013E920 AFB3001C */  sw        $s3, 0x1c($sp)
/* D5024 8013E924 AFB20018 */  sw        $s2, 0x18($sp)
/* D5028 8013E928 AFB10014 */  sw        $s1, 0x14($sp)
/* D502C 8013E92C AFB00010 */  sw        $s0, 0x10($sp)
/* D5030 8013E930 8E93002C */  lw        $s3, 0x2c($s4)
/* D5034 8013E934 3C120001 */  lui       $s2, 1
/* D5038 8013E938 96640008 */  lhu       $a0, 8($s3)
/* D503C 8013E93C 0C04BF84 */  jal       func_8012FE10
/* D5040 8013E940 36521630 */   ori      $s2, $s2, 0x1630
/* D5044 8013E944 24050002 */  addiu     $a1, $zero, 2
/* D5048 8013E948 9664000A */  lhu       $a0, 0xa($s3)
/* D504C 8013E94C 0C04BF84 */  jal       func_8012FE10
/* D5050 8013E950 0040B02D */   daddu    $s6, $v0, $zero
/* D5054 8013E954 3C108007 */  lui       $s0, %hi(D_800741F0)
/* D5058 8013E958 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* D505C 8013E95C 3C11800A */  lui       $s1, %hi(D_8009A674)
/* D5060 8013E960 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* D5064 8013E964 96040000 */  lhu       $a0, ($s0)
/* D5068 8013E968 3C068015 */  lui       $a2, %hi(D_8014EE10)
/* D506C 8013E96C 8CC6EE10 */  lw        $a2, %lo(D_8014EE10)($a2)
/* D5070 8013E970 8E230000 */  lw        $v1, ($s1)
/* D5074 8013E974 3C014059 */  lui       $at, 0x4059
/* D5078 8013E978 44811800 */  mtc1      $at, $f3
/* D507C 8013E97C 44801000 */  mtc1      $zero, $f2
/* D5080 8013E980 3C073F80 */  lui       $a3, 0x3f80
/* D5084 8013E984 00042180 */  sll       $a0, $a0, 6
/* D5088 8013E988 00922021 */  addu      $a0, $a0, $s2
/* D508C 8013E98C 00642021 */  addu      $a0, $v1, $a0
/* D5090 8013E990 94C50008 */  lhu       $a1, 8($a2)
/* D5094 8013E994 94C3000A */  lhu       $v1, 0xa($a2)
/* D5098 8013E998 44850000 */  mtc1      $a1, $f0
/* D509C 8013E99C 00000000 */  nop       
/* D50A0 8013E9A0 46800020 */  cvt.s.w   $f0, $f0
/* D50A4 8013E9A4 46000021 */  cvt.d.s   $f0, $f0
/* D50A8 8013E9A8 46220003 */  div.d     $f0, $f0, $f2
/* D50AC 8013E9AC 46200020 */  cvt.s.d   $f0, $f0
/* D50B0 8013E9B0 44050000 */  mfc1      $a1, $f0
/* D50B4 8013E9B4 44830000 */  mtc1      $v1, $f0
/* D50B8 8013E9B8 00000000 */  nop       
/* D50BC 8013E9BC 46800020 */  cvt.s.w   $f0, $f0
/* D50C0 8013E9C0 46000021 */  cvt.d.s   $f0, $f0
/* D50C4 8013E9C4 46220003 */  div.d     $f0, $f0, $f2
/* D50C8 8013E9C8 46200020 */  cvt.s.d   $f0, $f0
/* D50CC 8013E9CC 44060000 */  mfc1      $a2, $f0
/* D50D0 8013E9D0 0C019DC0 */  jal       guScale
/* D50D4 8013E9D4 0040A82D */   daddu    $s5, $v0, $zero
/* D50D8 8013E9D8 3C06E200 */  lui       $a2, 0xe200
/* D50DC 8013E9DC 34C6001C */  ori       $a2, $a2, 0x1c
/* D50E0 8013E9E0 3C050050 */  lui       $a1, 0x50
/* D50E4 8013E9E4 3C08800A */  lui       $t0, %hi(D_8009A66C)
/* D50E8 8013E9E8 2508A66C */  addiu     $t0, $t0, %lo(D_8009A66C)
/* D50EC 8013E9EC 8D070000 */  lw        $a3, ($t0)
/* D50F0 8013E9F0 34A54E50 */  ori       $a1, $a1, 0x4e50
/* D50F4 8013E9F4 00E0202D */  daddu     $a0, $a3, $zero
/* D50F8 8013E9F8 24E70008 */  addiu     $a3, $a3, 8
/* D50FC 8013E9FC AD070000 */  sw        $a3, ($t0)
/* D5100 8013EA00 96020000 */  lhu       $v0, ($s0)
/* D5104 8013EA04 3C03DA38 */  lui       $v1, 0xda38
/* D5108 8013EA08 AC830000 */  sw        $v1, ($a0)
/* D510C 8013EA0C 24430001 */  addiu     $v1, $v0, 1
/* D5110 8013EA10 3042FFFF */  andi      $v0, $v0, 0xffff
/* D5114 8013EA14 00021180 */  sll       $v0, $v0, 6
/* D5118 8013EA18 A6030000 */  sh        $v1, ($s0)
/* D511C 8013EA1C 8E230000 */  lw        $v1, ($s1)
/* D5120 8013EA20 00521021 */  addu      $v0, $v0, $s2
/* D5124 8013EA24 00621821 */  addu      $v1, $v1, $v0
/* D5128 8013EA28 3C028000 */  lui       $v0, 0x8000
/* D512C 8013EA2C 00621821 */  addu      $v1, $v1, $v0
/* D5130 8013EA30 24E20008 */  addiu     $v0, $a3, 8
/* D5134 8013EA34 AC830004 */  sw        $v1, 4($a0)
/* D5138 8013EA38 AD020000 */  sw        $v0, ($t0)
/* D513C 8013EA3C ACE60000 */  sw        $a2, ($a3)
/* D5140 8013EA40 ACE50004 */  sw        $a1, 4($a3)
/* D5144 8013EA44 92830002 */  lbu       $v1, 2($s4)
/* D5148 8013EA48 2402000F */  addiu     $v0, $zero, 0xf
/* D514C 8013EA4C 14620010 */  bne       $v1, $v0, .L8013EA90
/* D5150 8013EA50 3C04FC12 */   lui      $a0, 0xfc12
/* D5154 8013EA54 3C05FC12 */  lui       $a1, 0xfc12
/* D5158 8013EA58 34A51624 */  ori       $a1, $a1, 0x1624
/* D515C 8013EA5C 3C04FF2F */  lui       $a0, 0xff2f
/* D5160 8013EA60 3484FFFF */  ori       $a0, $a0, 0xffff
/* D5164 8013EA64 24E20010 */  addiu     $v0, $a3, 0x10
/* D5168 8013EA68 AD020000 */  sw        $v0, ($t0)
/* D516C 8013EA6C 8E830030 */  lw        $v1, 0x30($s4)
/* D5170 8013EA70 3C02FA00 */  lui       $v0, 0xfa00
/* D5174 8013EA74 ACE20008 */  sw        $v0, 8($a3)
/* D5178 8013EA78 24E20018 */  addiu     $v0, $a3, 0x18
/* D517C 8013EA7C AD020000 */  sw        $v0, ($t0)
/* D5180 8013EA80 ACE50010 */  sw        $a1, 0x10($a3)
/* D5184 8013EA84 ACE40014 */  sw        $a0, 0x14($a3)
/* D5188 8013EA88 0804FAAA */  j         .L8013EAA8
/* D518C 8013EA8C 306300FF */   andi     $v1, $v1, 0xff
.L8013EA90:
/* D5190 8013EA90 34841824 */  ori       $a0, $a0, 0x1824
/* D5194 8013EA94 3C03FF33 */  lui       $v1, 0xff33
/* D5198 8013EA98 3463FFFF */  ori       $v1, $v1, 0xffff
/* D519C 8013EA9C 24E20010 */  addiu     $v0, $a3, 0x10
/* D51A0 8013EAA0 AD020000 */  sw        $v0, ($t0)
/* D51A4 8013EAA4 ACE40008 */  sw        $a0, 8($a3)
.L8013EAA8:
/* D51A8 8013EAA8 ACE3000C */  sw        $v1, 0xc($a3)
/* D51AC 8013EAAC 3C02E300 */  lui       $v0, 0xe300
/* D51B0 8013EAB0 34421001 */  ori       $v0, $v0, 0x1001
/* D51B4 8013EAB4 3C05F500 */  lui       $a1, 0xf500
/* D51B8 8013EAB8 34A50100 */  ori       $a1, $a1, 0x100
/* D51BC 8013EABC 3C060703 */  lui       $a2, 0x703
/* D51C0 8013EAC0 34C6C000 */  ori       $a2, $a2, 0xc000
/* D51C4 8013EAC4 3C07800A */  lui       $a3, %hi(D_8009A66C)
/* D51C8 8013EAC8 24E7A66C */  addiu     $a3, $a3, %lo(D_8009A66C)
/* D51CC 8013EACC 3C0BF240 */  lui       $t3, 0xf240
/* D51D0 8013EAD0 3C080700 */  lui       $t0, 0x700
/* D51D4 8013EAD4 3C0AE600 */  lui       $t2, 0xe600
/* D51D8 8013EAD8 3C09E700 */  lui       $t1, 0xe700
/* D51DC 8013EADC 8CE40000 */  lw        $a0, ($a3)
/* D51E0 8013EAE0 356B0400 */  ori       $t3, $t3, 0x400
/* D51E4 8013EAE4 0080182D */  daddu     $v1, $a0, $zero
/* D51E8 8013EAE8 24840008 */  addiu     $a0, $a0, 8
/* D51EC 8013EAEC ACE40000 */  sw        $a0, ($a3)
/* D51F0 8013EAF0 AC620000 */  sw        $v0, ($v1)
/* D51F4 8013EAF4 34028000 */  ori       $v0, $zero, 0x8000
/* D51F8 8013EAF8 AC620004 */  sw        $v0, 4($v1)
/* D51FC 8013EAFC 24820008 */  addiu     $v0, $a0, 8
/* D5200 8013EB00 ACE20000 */  sw        $v0, ($a3)
/* D5204 8013EB04 3C02FD10 */  lui       $v0, 0xfd10
/* D5208 8013EB08 AC820000 */  sw        $v0, ($a0)
/* D520C 8013EB0C 24820010 */  addiu     $v0, $a0, 0x10
/* D5210 8013EB10 ACE20000 */  sw        $v0, ($a3)
/* D5214 8013EB14 8E630004 */  lw        $v1, 4($s3)
/* D5218 8013EB18 3C02E800 */  lui       $v0, 0xe800
/* D521C 8013EB1C AC820008 */  sw        $v0, 8($a0)
/* D5220 8013EB20 24820018 */  addiu     $v0, $a0, 0x18
/* D5224 8013EB24 AC80000C */  sw        $zero, 0xc($a0)
/* D5228 8013EB28 ACE20000 */  sw        $v0, ($a3)
/* D522C 8013EB2C 24820020 */  addiu     $v0, $a0, 0x20
/* D5230 8013EB30 AC850010 */  sw        $a1, 0x10($a0)
/* D5234 8013EB34 AC880014 */  sw        $t0, 0x14($a0)
/* D5238 8013EB38 ACE20000 */  sw        $v0, ($a3)
/* D523C 8013EB3C 24820028 */  addiu     $v0, $a0, 0x28
/* D5240 8013EB40 AC8A0018 */  sw        $t2, 0x18($a0)
/* D5244 8013EB44 AC80001C */  sw        $zero, 0x1c($a0)
/* D5248 8013EB48 ACE20000 */  sw        $v0, ($a3)
/* D524C 8013EB4C 3C02F000 */  lui       $v0, 0xf000
/* D5250 8013EB50 AC820020 */  sw        $v0, 0x20($a0)
/* D5254 8013EB54 24820030 */  addiu     $v0, $a0, 0x30
/* D5258 8013EB58 AC860024 */  sw        $a2, 0x24($a0)
/* D525C 8013EB5C ACE20000 */  sw        $v0, ($a3)
/* D5260 8013EB60 24820038 */  addiu     $v0, $a0, 0x38
/* D5264 8013EB64 32A5000F */  andi      $a1, $s5, 0xf
/* D5268 8013EB68 00052B80 */  sll       $a1, $a1, 0xe
/* D526C 8013EB6C 32C6000F */  andi      $a2, $s6, 0xf
/* D5270 8013EB70 00063100 */  sll       $a2, $a2, 4
/* D5274 8013EB74 AC890028 */  sw        $t1, 0x28($a0)
/* D5278 8013EB78 AC80002C */  sw        $zero, 0x2c($a0)
/* D527C 8013EB7C ACE20000 */  sw        $v0, ($a3)
/* D5280 8013EB80 AC830004 */  sw        $v1, 4($a0)
/* D5284 8013EB84 96620008 */  lhu       $v0, 8($s3)
/* D5288 8013EB88 24830040 */  addiu     $v1, $a0, 0x40
/* D528C 8013EB8C ACE30000 */  sw        $v1, ($a3)
/* D5290 8013EB90 3C03FD48 */  lui       $v1, 0xfd48
/* D5294 8013EB94 00021042 */  srl       $v0, $v0, 1
/* D5298 8013EB98 2442FFFF */  addiu     $v0, $v0, -1
/* D529C 8013EB9C 30420FFF */  andi      $v0, $v0, 0xfff
/* D52A0 8013EBA0 00431025 */  or        $v0, $v0, $v1
/* D52A4 8013EBA4 AC820030 */  sw        $v0, 0x30($a0)
/* D52A8 8013EBA8 8E630000 */  lw        $v1, ($s3)
/* D52AC 8013EBAC 24820048 */  addiu     $v0, $a0, 0x48
/* D52B0 8013EBB0 ACE20000 */  sw        $v0, ($a3)
/* D52B4 8013EBB4 AC830034 */  sw        $v1, 0x34($a0)
/* D52B8 8013EBB8 00C81825 */  or        $v1, $a2, $t0
/* D52BC 8013EBBC 96620008 */  lhu       $v0, 8($s3)
/* D52C0 8013EBC0 00A31825 */  or        $v1, $a1, $v1
/* D52C4 8013EBC4 AC83003C */  sw        $v1, 0x3c($a0)
/* D52C8 8013EBC8 3C03F548 */  lui       $v1, 0xf548
/* D52CC 8013EBCC 00021042 */  srl       $v0, $v0, 1
/* D52D0 8013EBD0 24420007 */  addiu     $v0, $v0, 7
/* D52D4 8013EBD4 000210C3 */  sra       $v0, $v0, 3
/* D52D8 8013EBD8 304201FF */  andi      $v0, $v0, 0x1ff
/* D52DC 8013EBDC 00021240 */  sll       $v0, $v0, 9
/* D52E0 8013EBE0 00431025 */  or        $v0, $v0, $v1
/* D52E4 8013EBE4 AC820038 */  sw        $v0, 0x38($a0)
/* D52E8 8013EBE8 3C02F400 */  lui       $v0, 0xf400
/* D52EC 8013EBEC AC8A0040 */  sw        $t2, 0x40($a0)
/* D52F0 8013EBF0 AC800044 */  sw        $zero, 0x44($a0)
/* D52F4 8013EBF4 AC820048 */  sw        $v0, 0x48($a0)
/* D52F8 8013EBF8 96620008 */  lhu       $v0, 8($s3)
/* D52FC 8013EBFC 9663000A */  lhu       $v1, 0xa($s3)
/* D5300 8013EC00 00A62825 */  or        $a1, $a1, $a2
/* D5304 8013EC04 AC890050 */  sw        $t1, 0x50($a0)
/* D5308 8013EC08 AC800054 */  sw        $zero, 0x54($a0)
/* D530C 8013EC0C 2442FFFF */  addiu     $v0, $v0, -1
/* D5310 8013EC10 00021040 */  sll       $v0, $v0, 1
/* D5314 8013EC14 30420FFF */  andi      $v0, $v0, 0xfff
/* D5318 8013EC18 00021300 */  sll       $v0, $v0, 0xc
/* D531C 8013EC1C 2463FFFF */  addiu     $v1, $v1, -1
/* D5320 8013EC20 00031880 */  sll       $v1, $v1, 2
/* D5324 8013EC24 30630FFF */  andi      $v1, $v1, 0xfff
/* D5328 8013EC28 00681825 */  or        $v1, $v1, $t0
/* D532C 8013EC2C 00431025 */  or        $v0, $v0, $v1
/* D5330 8013EC30 AC82004C */  sw        $v0, 0x4c($a0)
/* D5334 8013EC34 96620008 */  lhu       $v0, 8($s3)
/* D5338 8013EC38 3C03F540 */  lui       $v1, 0xf540
/* D533C 8013EC3C AC85005C */  sw        $a1, 0x5c($a0)
/* D5340 8013EC40 AC8B0060 */  sw        $t3, 0x60($a0)
/* D5344 8013EC44 00021042 */  srl       $v0, $v0, 1
/* D5348 8013EC48 24420007 */  addiu     $v0, $v0, 7
/* D534C 8013EC4C 000210C3 */  sra       $v0, $v0, 3
/* D5350 8013EC50 304201FF */  andi      $v0, $v0, 0x1ff
/* D5354 8013EC54 00021240 */  sll       $v0, $v0, 9
/* D5358 8013EC58 00431025 */  or        $v0, $v0, $v1
/* D535C 8013EC5C AC820058 */  sw        $v0, 0x58($a0)
/* D5360 8013EC60 96630008 */  lhu       $v1, 8($s3)
/* D5364 8013EC64 9662000A */  lhu       $v0, 0xa($s3)
/* D5368 8013EC68 246300FF */  addiu     $v1, $v1, 0xff
/* D536C 8013EC6C 00031880 */  sll       $v1, $v1, 2
/* D5370 8013EC70 30630FFF */  andi      $v1, $v1, 0xfff
/* D5374 8013EC74 00031B00 */  sll       $v1, $v1, 0xc
/* D5378 8013EC78 244200FF */  addiu     $v0, $v0, 0xff
/* D537C 8013EC7C 00021080 */  sll       $v0, $v0, 2
/* D5380 8013EC80 30420FFF */  andi      $v0, $v0, 0xfff
/* D5384 8013EC84 00621825 */  or        $v1, $v1, $v0
/* D5388 8013EC88 AC830064 */  sw        $v1, 0x64($a0)
/* D538C 8013EC8C C684004C */  lwc1      $f4, 0x4c($s4)
/* D5390 8013EC90 C6860050 */  lwc1      $f6, 0x50($s4)
/* D5394 8013EC94 96630008 */  lhu       $v1, 8($s3)
/* D5398 8013EC98 9662000A */  lhu       $v0, 0xa($s3)
/* D539C 8013EC9C 4600220D */  trunc.w.s $f8, $f4
/* D53A0 8013ECA0 44054000 */  mfc1      $a1, $f8
/* D53A4 8013ECA4 4600320D */  trunc.w.s $f8, $f6
/* D53A8 8013ECA8 44064000 */  mfc1      $a2, $f8
/* D53AC 8013ECAC 00031880 */  sll       $v1, $v1, 2
/* D53B0 8013ECB0 44831000 */  mtc1      $v1, $f2
/* D53B4 8013ECB4 00000000 */  nop       
/* D53B8 8013ECB8 468010A0 */  cvt.s.w   $f2, $f2
/* D53BC 8013ECBC 00021080 */  sll       $v0, $v0, 2
/* D53C0 8013ECC0 44820000 */  mtc1      $v0, $f0
/* D53C4 8013ECC4 00000000 */  nop       
/* D53C8 8013ECC8 46800020 */  cvt.s.w   $f0, $f0
/* D53CC 8013ECCC 30A50FFF */  andi      $a1, $a1, 0xfff
/* D53D0 8013ECD0 00052B00 */  sll       $a1, $a1, 0xc
/* D53D4 8013ECD4 30C60FFF */  andi      $a2, $a2, 0xfff
/* D53D8 8013ECD8 3C02F200 */  lui       $v0, 0xf200
/* D53DC 8013ECDC 46041080 */  add.s     $f2, $f2, $f4
/* D53E0 8013ECE0 00C23025 */  or        $a2, $a2, $v0
/* D53E4 8013ECE4 00A62825 */  or        $a1, $a1, $a2
/* D53E8 8013ECE8 46060000 */  add.s     $f0, $f0, $f6
/* D53EC 8013ECEC AC850068 */  sw        $a1, 0x68($a0)
/* D53F0 8013ECF0 4600120D */  trunc.w.s $f8, $f2
/* D53F4 8013ECF4 44024000 */  mfc1      $v0, $f8
/* D53F8 8013ECF8 4600020D */  trunc.w.s $f8, $f0
/* D53FC 8013ECFC 44034000 */  mfc1      $v1, $f8
/* D5400 8013ED00 30420FFF */  andi      $v0, $v0, 0xfff
/* D5404 8013ED04 00021300 */  sll       $v0, $v0, 0xc
/* D5408 8013ED08 30630FFF */  andi      $v1, $v1, 0xfff
/* D540C 8013ED0C 00431025 */  or        $v0, $v0, $v1
/* D5410 8013ED10 AC82006C */  sw        $v0, 0x6c($a0)
/* D5414 8013ED14 C662000C */  lwc1      $f2, 0xc($s3)
/* D5418 8013ED18 468010A0 */  cvt.s.w   $f2, $f2
/* D541C 8013ED1C C680004C */  lwc1      $f0, 0x4c($s4)
/* D5420 8013ED20 96620008 */  lhu       $v0, 8($s3)
/* D5424 8013ED24 46020000 */  add.s     $f0, $f0, $f2
/* D5428 8013ED28 00021080 */  sll       $v0, $v0, 2
/* D542C 8013ED2C 4600020D */  trunc.w.s $f8, $f0
/* D5430 8013ED30 44034000 */  mfc1      $v1, $f8
/* D5434 8013ED34 14400002 */  bnez      $v0, .L8013ED40
/* D5438 8013ED38 0062001A */   div      $zero, $v1, $v0
/* D543C 8013ED3C 0007000D */  break     7
.L8013ED40:
/* D5440 8013ED40 2401FFFF */   addiu    $at, $zero, -1
/* D5444 8013ED44 14410004 */  bne       $v0, $at, .L8013ED58
/* D5448 8013ED48 3C018000 */   lui      $at, 0x8000
/* D544C 8013ED4C 14610002 */  bne       $v1, $at, .L8013ED58
/* D5450 8013ED50 00000000 */   nop      
/* D5454 8013ED54 0006000D */  break     6
.L8013ED58:
/* D5458 8013ED58 00001010 */   mfhi     $v0
/* D545C 8013ED5C 44820000 */  mtc1      $v0, $f0
/* D5460 8013ED60 00000000 */  nop       
/* D5464 8013ED64 46800020 */  cvt.s.w   $f0, $f0
/* D5468 8013ED68 E680004C */  swc1      $f0, 0x4c($s4)
/* D546C 8013ED6C C6620010 */  lwc1      $f2, 0x10($s3)
/* D5470 8013ED70 468010A0 */  cvt.s.w   $f2, $f2
/* D5474 8013ED74 C6800050 */  lwc1      $f0, 0x50($s4)
/* D5478 8013ED78 9662000A */  lhu       $v0, 0xa($s3)
/* D547C 8013ED7C 46020000 */  add.s     $f0, $f0, $f2
/* D5480 8013ED80 00021080 */  sll       $v0, $v0, 2
/* D5484 8013ED84 4600020D */  trunc.w.s $f8, $f0
/* D5488 8013ED88 44034000 */  mfc1      $v1, $f8
/* D548C 8013ED8C 14400002 */  bnez      $v0, .L8013ED98
/* D5490 8013ED90 0062001A */   div      $zero, $v1, $v0
/* D5494 8013ED94 0007000D */  break     7
.L8013ED98:
/* D5498 8013ED98 2401FFFF */   addiu    $at, $zero, -1
/* D549C 8013ED9C 14410004 */  bne       $v0, $at, .L8013EDB0
/* D54A0 8013EDA0 3C018000 */   lui      $at, 0x8000
/* D54A4 8013EDA4 14610002 */  bne       $v1, $at, .L8013EDB0
/* D54A8 8013EDA8 00000000 */   nop      
/* D54AC 8013EDAC 0006000D */  break     6
.L8013EDB0:
/* D54B0 8013EDB0 00002810 */   mfhi     $a1
/* D54B4 8013EDB4 3C06D838 */  lui       $a2, 0xd838
/* D54B8 8013EDB8 34C60002 */  ori       $a2, $a2, 2
/* D54BC 8013EDBC 24820050 */  addiu     $v0, $a0, 0x50
/* D54C0 8013EDC0 ACE20000 */  sw        $v0, ($a3)
/* D54C4 8013EDC4 24820058 */  addiu     $v0, $a0, 0x58
/* D54C8 8013EDC8 ACE20000 */  sw        $v0, ($a3)
/* D54CC 8013EDCC 24820060 */  addiu     $v0, $a0, 0x60
/* D54D0 8013EDD0 ACE20000 */  sw        $v0, ($a3)
/* D54D4 8013EDD4 24820068 */  addiu     $v0, $a0, 0x68
/* D54D8 8013EDD8 ACE20000 */  sw        $v0, ($a3)
/* D54DC 8013EDDC 24820070 */  addiu     $v0, $a0, 0x70
/* D54E0 8013EDE0 ACE20000 */  sw        $v0, ($a3)
/* D54E4 8013EDE4 24820078 */  addiu     $v0, $a0, 0x78
/* D54E8 8013EDE8 44850000 */  mtc1      $a1, $f0
/* D54EC 8013EDEC 00000000 */  nop       
/* D54F0 8013EDF0 46800020 */  cvt.s.w   $f0, $f0
/* D54F4 8013EDF4 E6800050 */  swc1      $f0, 0x50($s4)
/* D54F8 8013EDF8 ACE20000 */  sw        $v0, ($a3)
/* D54FC 8013EDFC 3C02DE00 */  lui       $v0, 0xde00
/* D5500 8013EE00 AC820070 */  sw        $v0, 0x70($a0)
/* D5504 8013EE04 8E630014 */  lw        $v1, 0x14($s3)
/* D5508 8013EE08 24820080 */  addiu     $v0, $a0, 0x80
/* D550C 8013EE0C ACE20000 */  sw        $v0, ($a3)
/* D5510 8013EE10 24020040 */  addiu     $v0, $zero, 0x40
/* D5514 8013EE14 AC860078 */  sw        $a2, 0x78($a0)
/* D5518 8013EE18 AC82007C */  sw        $v0, 0x7c($a0)
/* D551C 8013EE1C AC830074 */  sw        $v1, 0x74($a0)
/* D5520 8013EE20 8FBF002C */  lw        $ra, 0x2c($sp)
/* D5524 8013EE24 8FB60028 */  lw        $s6, 0x28($sp)
/* D5528 8013EE28 8FB50024 */  lw        $s5, 0x24($sp)
/* D552C 8013EE2C 8FB40020 */  lw        $s4, 0x20($sp)
/* D5530 8013EE30 8FB3001C */  lw        $s3, 0x1c($sp)
/* D5534 8013EE34 8FB20018 */  lw        $s2, 0x18($sp)
/* D5538 8013EE38 8FB10014 */  lw        $s1, 0x14($sp)
/* D553C 8013EE3C 8FB00010 */  lw        $s0, 0x10($sp)
/* D5540 8013EE40 03E00008 */  jr        $ra
/* D5544 8013EE44 27BD0030 */   addiu    $sp, $sp, 0x30
