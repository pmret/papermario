.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_spirits_draw_contents
/* 13FD40 8024CA00 27BDFED0 */  addiu     $sp, $sp, -0x130
/* 13FD44 8024CA04 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 13FD48 8024CA08 AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 13FD4C 8024CA0C AFB700F4 */  sw        $s7, 0xf4($sp)
/* 13FD50 8024CA10 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 13FD54 8024CA14 AFB500EC */  sw        $s5, 0xec($sp)
/* 13FD58 8024CA18 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 13FD5C 8024CA1C AFB300E4 */  sw        $s3, 0xe4($sp)
/* 13FD60 8024CA20 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 13FD64 8024CA24 AFB100DC */  sw        $s1, 0xdc($sp)
/* 13FD68 8024CA28 AFB000D8 */  sw        $s0, 0xd8($sp)
/* 13FD6C 8024CA2C F7BE0128 */  sdc1      $f30, 0x128($sp)
/* 13FD70 8024CA30 F7BC0120 */  sdc1      $f28, 0x120($sp)
/* 13FD74 8024CA34 F7BA0118 */  sdc1      $f26, 0x118($sp)
/* 13FD78 8024CA38 F7B80110 */  sdc1      $f24, 0x110($sp)
/* 13FD7C 8024CA3C F7B60108 */  sdc1      $f22, 0x108($sp)
/* 13FD80 8024CA40 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 13FD84 8024CA44 AFA40130 */  sw        $a0, 0x130($sp)
/* 13FD88 8024CA48 AFA50134 */  sw        $a1, 0x134($sp)
/* 13FD8C 8024CA4C AFA60138 */  sw        $a2, 0x138($sp)
/* 13FD90 8024CA50 0C039D59 */  jal       get_player_data
/* 13FD94 8024CA54 AFA7013C */   sw       $a3, 0x13c($sp)
/* 13FD98 8024CA58 3C05DC08 */  lui       $a1, 0xdc08
/* 13FD9C 8024CA5C 34A50008 */  ori       $a1, $a1, 8
/* 13FDA0 8024CA60 0000A02D */  daddu     $s4, $zero, $zero
/* 13FDA4 8024CA64 AFA200D0 */  sw        $v0, 0xd0($sp)
/* 13FDA8 8024CA68 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 13FDAC 8024CA6C 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 13FDB0 8024CA70 0040882D */  daddu     $s1, $v0, $zero
/* 13FDB4 8024CA74 3C1EE700 */  lui       $fp, 0xe700
/* 13FDB8 8024CA78 24170400 */  addiu     $s7, $zero, 0x400
/* 13FDBC 8024CA7C 24160010 */  addiu     $s6, $zero, 0x10
/* 13FDC0 8024CA80 24150016 */  addiu     $s5, $zero, 0x16
/* 13FDC4 8024CA84 24130054 */  addiu     $s3, $zero, 0x54
/* 13FDC8 8024CA88 0280902D */  daddu     $s2, $s4, $zero
/* 13FDCC 8024CA8C 8E230000 */  lw        $v1, ($s1)
/* 13FDD0 8024CA90 03C0102D */  daddu     $v0, $fp, $zero
/* 13FDD4 8024CA94 0060202D */  daddu     $a0, $v1, $zero
/* 13FDD8 8024CA98 24630008 */  addiu     $v1, $v1, 8
/* 13FDDC 8024CA9C AE230000 */  sw        $v1, ($s1)
/* 13FDE0 8024CAA0 AC820000 */  sw        $v0, ($a0)
/* 13FDE4 8024CAA4 24620008 */  addiu     $v0, $v1, 8
/* 13FDE8 8024CAA8 AC800004 */  sw        $zero, 4($a0)
/* 13FDEC 8024CAAC AE220000 */  sw        $v0, ($s1)
/* 13FDF0 8024CAB0 3C028025 */  lui       $v0, %hi(D_8024F8B0)
/* 13FDF4 8024CAB4 2442F8B0 */  addiu     $v0, $v0, %lo(D_8024F8B0)
/* 13FDF8 8024CAB8 AC620004 */  sw        $v0, 4($v1)
/* 13FDFC 8024CABC 00761021 */  addu      $v0, $v1, $s6
/* 13FE00 8024CAC0 AC650000 */  sw        $a1, ($v1)
/* 13FE04 8024CAC4 AE220000 */  sw        $v0, ($s1)
/* 13FE08 8024CAC8 3C02DE00 */  lui       $v0, 0xde00
/* 13FE0C 8024CACC AC620008 */  sw        $v0, 8($v1)
/* 13FE10 8024CAD0 3C028027 */  lui       $v0, %hi(D_8026F5A0)
/* 13FE14 8024CAD4 2442F5A0 */  addiu     $v0, $v0, %lo(D_8026F5A0)
/* 13FE18 8024CAD8 AC62000C */  sw        $v0, 0xc($v1)
.L8024CADC:
/* 13FE1C 8024CADC 3C02FD48 */  lui       $v0, 0xfd48
/* 13FE20 8024CAE0 3442003F */  ori       $v0, $v0, 0x3f
/* 13FE24 8024CAE4 3C0DF548 */  lui       $t5, 0xf548
/* 13FE28 8024CAE8 35AD1000 */  ori       $t5, $t5, 0x1000
/* 13FE2C 8024CAEC 3C0C0708 */  lui       $t4, 0x708
/* 13FE30 8024CAF0 358C0170 */  ori       $t4, $t4, 0x170
/* 13FE34 8024CAF4 3C0B070F */  lui       $t3, 0x70f
/* 13FE38 8024CAF8 356BE000 */  ori       $t3, $t3, 0xe000
/* 13FE3C 8024CAFC 3C0FF540 */  lui       $t7, 0xf540
/* 13FE40 8024CB00 35EF1000 */  ori       $t7, $t7, 0x1000
/* 13FE44 8024CB04 3C0E0008 */  lui       $t6, 8
/* 13FE48 8024CB08 35CE0170 */  ori       $t6, $t6, 0x170
/* 13FE4C 8024CB0C 3C10001F */  lui       $s0, 0x1f
/* 13FE50 8024CB10 3610C000 */  ori       $s0, $s0, 0xc000
/* 13FE54 8024CB14 326A0FFF */  andi      $t2, $s3, 0xfff
/* 13FE58 8024CB18 26730058 */  addiu     $s3, $s3, 0x58
/* 13FE5C 8024CB1C 32490FFF */  andi      $t1, $s2, 0xfff
/* 13FE60 8024CB20 26520058 */  addiu     $s2, $s2, 0x58
/* 13FE64 8024CB24 26940001 */  addiu     $s4, $s4, 1
/* 13FE68 8024CB28 014B5825 */  or        $t3, $t2, $t3
/* 13FE6C 8024CB2C 01505025 */  or        $t2, $t2, $s0
/* 13FE70 8024CB30 8FB80134 */  lw        $t8, 0x134($sp)
/* 13FE74 8024CB34 8E230000 */  lw        $v1, ($s1)
/* 13FE78 8024CB38 2704000F */  addiu     $a0, $t8, 0xf
/* 13FE7C 8024CB3C 00042080 */  sll       $a0, $a0, 2
/* 13FE80 8024CB40 0060402D */  daddu     $t0, $v1, $zero
/* 13FE84 8024CB44 8FB80138 */  lw        $t8, 0x138($sp)
/* 13FE88 8024CB48 24630008 */  addiu     $v1, $v1, 8
/* 13FE8C 8024CB4C 03153821 */  addu      $a3, $t8, $s5
/* 13FE90 8024CB50 00072880 */  sll       $a1, $a3, 2
/* 13FE94 8024CB54 24E70016 */  addiu     $a3, $a3, 0x16
/* 13FE98 8024CB58 00073880 */  sll       $a3, $a3, 2
/* 13FE9C 8024CB5C 8FB80134 */  lw        $t8, 0x134($sp)
/* 13FEA0 8024CB60 26B50016 */  addiu     $s5, $s5, 0x16
/* 13FEA4 8024CB64 AE230000 */  sw        $v1, ($s1)
/* 13FEA8 8024CB68 AD020000 */  sw        $v0, ($t0)
/* 13FEAC 8024CB6C 3C028027 */  lui       $v0, %hi(D_8026A2B0)
/* 13FEB0 8024CB70 2442A2B0 */  addiu     $v0, $v0, %lo(D_8026A2B0)
/* 13FEB4 8024CB74 AD020004 */  sw        $v0, 4($t0)
/* 13FEB8 8024CB78 24620008 */  addiu     $v0, $v1, 8
/* 13FEBC 8024CB7C AE220000 */  sw        $v0, ($s1)
/* 13FEC0 8024CB80 24620010 */  addiu     $v0, $v1, 0x10
/* 13FEC4 8024CB84 AC6D0000 */  sw        $t5, ($v1)
/* 13FEC8 8024CB88 AC6C0004 */  sw        $t4, 4($v1)
/* 13FECC 8024CB8C AE220000 */  sw        $v0, ($s1)
/* 13FED0 8024CB90 3C02E600 */  lui       $v0, 0xe600
/* 13FED4 8024CB94 AC620008 */  sw        $v0, 8($v1)
/* 13FED8 8024CB98 24620018 */  addiu     $v0, $v1, 0x18
/* 13FEDC 8024CB9C AC60000C */  sw        $zero, 0xc($v1)
/* 13FEE0 8024CBA0 AE220000 */  sw        $v0, ($s1)
/* 13FEE4 8024CBA4 3C02F400 */  lui       $v0, 0xf400
/* 13FEE8 8024CBA8 01221025 */  or        $v0, $t1, $v0
/* 13FEEC 8024CBAC AC620010 */  sw        $v0, 0x10($v1)
/* 13FEF0 8024CBB0 24620020 */  addiu     $v0, $v1, 0x20
/* 13FEF4 8024CBB4 AC6B0014 */  sw        $t3, 0x14($v1)
/* 13FEF8 8024CBB8 AE220000 */  sw        $v0, ($s1)
/* 13FEFC 8024CBBC 24620028 */  addiu     $v0, $v1, 0x28
/* 13FF00 8024CBC0 AC7E0018 */  sw        $fp, 0x18($v1)
/* 13FF04 8024CBC4 AC60001C */  sw        $zero, 0x1c($v1)
/* 13FF08 8024CBC8 AE220000 */  sw        $v0, ($s1)
/* 13FF0C 8024CBCC 24620030 */  addiu     $v0, $v1, 0x30
/* 13FF10 8024CBD0 AC6F0020 */  sw        $t7, 0x20($v1)
/* 13FF14 8024CBD4 AC6E0024 */  sw        $t6, 0x24($v1)
/* 13FF18 8024CBD8 AE220000 */  sw        $v0, ($s1)
/* 13FF1C 8024CBDC 3C02F200 */  lui       $v0, 0xf200
/* 13FF20 8024CBE0 01224825 */  or        $t1, $t1, $v0
/* 13FF24 8024CBE4 24020010 */  addiu     $v0, $zero, 0x10
/* 13FF28 8024CBE8 AC690028 */  sw        $t1, 0x28($v1)
/* 13FF2C 8024CBEC AC6A002C */  sw        $t2, 0x2c($v1)
/* 13FF30 8024CBF0 AFA00010 */  sw        $zero, 0x10($sp)
/* 13FF34 8024CBF4 AFA20014 */  sw        $v0, 0x14($sp)
/* 13FF38 8024CBF8 AFB60018 */  sw        $s6, 0x18($sp)
/* 13FF3C 8024CBFC AFB7001C */  sw        $s7, 0x1c($sp)
/* 13FF40 8024CC00 AFB70020 */  sw        $s7, 0x20($sp)
/* 13FF44 8024CC04 2706010F */  addiu     $a2, $t8, 0x10f
/* 13FF48 8024CC08 0C091216 */  jal       pause_draw_rect
/* 13FF4C 8024CC0C 00063080 */   sll      $a2, $a2, 2
/* 13FF50 8024CC10 8E220000 */  lw        $v0, ($s1)
/* 13FF54 8024CC14 26D602C0 */  addiu     $s6, $s6, 0x2c0
/* 13FF58 8024CC18 0040182D */  daddu     $v1, $v0, $zero
/* 13FF5C 8024CC1C 24420008 */  addiu     $v0, $v0, 8
/* 13FF60 8024CC20 AE220000 */  sw        $v0, ($s1)
/* 13FF64 8024CC24 2A820005 */  slti      $v0, $s4, 5
/* 13FF68 8024CC28 AC7E0000 */  sw        $fp, ($v1)
/* 13FF6C 8024CC2C 1440FFAB */  bnez      $v0, .L8024CADC
/* 13FF70 8024CC30 AC600004 */   sw       $zero, 4($v1)
/* 13FF74 8024CC34 4480A000 */  mtc1      $zero, $f20
/* 13FF78 8024CC38 3C130001 */  lui       $s3, 1
/* 13FF7C 8024CC3C 36731630 */  ori       $s3, $s3, 0x1630
/* 13FF80 8024CC40 0000A02D */  daddu     $s4, $zero, $zero
/* 13FF84 8024CC44 3C0643A0 */  lui       $a2, 0x43a0
/* 13FF88 8024CC48 3C074370 */  lui       $a3, 0x4370
/* 13FF8C 8024CC4C 3C01C47A */  lui       $at, 0xc47a
/* 13FF90 8024CC50 44810000 */  mtc1      $at, $f0
/* 13FF94 8024CC54 3C01447A */  lui       $at, 0x447a
/* 13FF98 8024CC58 44811000 */  mtc1      $at, $f2
/* 13FF9C 8024CC5C 3C013F80 */  lui       $at, 0x3f80
/* 13FFA0 8024CC60 4481B000 */  mtc1      $at, $f22
/* 13FFA4 8024CC64 4405A000 */  mfc1      $a1, $f20
/* 13FFA8 8024CC68 27A40050 */  addiu     $a0, $sp, 0x50
/* 13FFAC 8024CC6C E7B40010 */  swc1      $f20, 0x10($sp)
/* 13FFB0 8024CC70 E7A00014 */  swc1      $f0, 0x14($sp)
/* 13FFB4 8024CC74 E7A20018 */  swc1      $f2, 0x18($sp)
/* 13FFB8 8024CC78 0C018E44 */  jal       guOrthoF
/* 13FFBC 8024CC7C E7B6001C */   swc1     $f22, 0x1c($sp)
/* 13FFC0 8024CC80 27A40050 */  addiu     $a0, $sp, 0x50
/* 13FFC4 8024CC84 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 13FFC8 8024CC88 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 13FFCC 8024CC8C 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 13FFD0 8024CC90 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 13FFD4 8024CC94 96250000 */  lhu       $a1, ($s1)
/* 13FFD8 8024CC98 8E420000 */  lw        $v0, ($s2)
/* 13FFDC 8024CC9C 00052980 */  sll       $a1, $a1, 6
/* 13FFE0 8024CCA0 00B32821 */  addu      $a1, $a1, $s3
/* 13FFE4 8024CCA4 0C019D40 */  jal       guMtxF2L
/* 13FFE8 8024CCA8 00452821 */   addu     $a1, $v0, $a1
/* 13FFEC 8024CCAC 3C09DA38 */  lui       $t1, 0xda38
/* 13FFF0 8024CCB0 35290007 */  ori       $t1, $t1, 7
/* 13FFF4 8024CCB4 27A40050 */  addiu     $a0, $sp, 0x50
/* 13FFF8 8024CCB8 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 13FFFC 8024CCBC 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 140000 8024CCC0 8E030000 */  lw        $v1, ($s0)
/* 140004 8024CCC4 4405A000 */  mfc1      $a1, $f20
/* 140008 8024CCC8 4406A000 */  mfc1      $a2, $f20
/* 14000C 8024CCCC 4407A000 */  mfc1      $a3, $f20
/* 140010 8024CCD0 96220000 */  lhu       $v0, ($s1)
/* 140014 8024CCD4 0060402D */  daddu     $t0, $v1, $zero
/* 140018 8024CCD8 24630008 */  addiu     $v1, $v1, 8
/* 14001C 8024CCDC AE030000 */  sw        $v1, ($s0)
/* 140020 8024CCE0 24430001 */  addiu     $v1, $v0, 1
/* 140024 8024CCE4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 140028 8024CCE8 00021180 */  sll       $v0, $v0, 6
/* 14002C 8024CCEC AD090000 */  sw        $t1, ($t0)
/* 140030 8024CCF0 A6230000 */  sh        $v1, ($s1)
/* 140034 8024CCF4 8E430000 */  lw        $v1, ($s2)
/* 140038 8024CCF8 00531021 */  addu      $v0, $v0, $s3
/* 14003C 8024CCFC 00621821 */  addu      $v1, $v1, $v0
/* 140040 8024CD00 0C019E40 */  jal       guTranslateF
/* 140044 8024CD04 AD030004 */   sw       $v1, 4($t0)
/* 140048 8024CD08 27A40050 */  addiu     $a0, $sp, 0x50
/* 14004C 8024CD0C 96250000 */  lhu       $a1, ($s1)
/* 140050 8024CD10 8E420000 */  lw        $v0, ($s2)
/* 140054 8024CD14 00052980 */  sll       $a1, $a1, 6
/* 140058 8024CD18 00B32821 */  addu      $a1, $a1, $s3
/* 14005C 8024CD1C 0C019D40 */  jal       guMtxF2L
/* 140060 8024CD20 00452821 */   addu     $a1, $v0, $a1
/* 140064 8024CD24 3C04DA38 */  lui       $a0, 0xda38
/* 140068 8024CD28 34840002 */  ori       $a0, $a0, 2
/* 14006C 8024CD2C 8E020000 */  lw        $v0, ($s0)
/* 140070 8024CD30 96230000 */  lhu       $v1, ($s1)
/* 140074 8024CD34 0040282D */  daddu     $a1, $v0, $zero
/* 140078 8024CD38 24420008 */  addiu     $v0, $v0, 8
/* 14007C 8024CD3C AE020000 */  sw        $v0, ($s0)
/* 140080 8024CD40 24620001 */  addiu     $v0, $v1, 1
/* 140084 8024CD44 3063FFFF */  andi      $v1, $v1, 0xffff
/* 140088 8024CD48 00031980 */  sll       $v1, $v1, 6
/* 14008C 8024CD4C 00731821 */  addu      $v1, $v1, $s3
/* 140090 8024CD50 ACA40000 */  sw        $a0, ($a1)
/* 140094 8024CD54 A6220000 */  sh        $v0, ($s1)
/* 140098 8024CD58 8E420000 */  lw        $v0, ($s2)
/* 14009C 8024CD5C 3C048027 */  lui       $a0, %hi(D_802706FC)
/* 1400A0 8024CD60 8C8406FC */  lw        $a0, %lo(D_802706FC)($a0)
/* 1400A4 8024CD64 00431021 */  addu      $v0, $v0, $v1
/* 1400A8 8024CD68 188000B3 */  blez      $a0, .L8024D038
/* 1400AC 8024CD6C ACA20004 */   sw       $v0, 4($a1)
/* 1400B0 8024CD70 3C168027 */  lui       $s6, %hi(D_802706C0)
/* 1400B4 8024CD74 26D606C0 */  addiu     $s6, $s6, %lo(D_802706C0)
/* 1400B8 8024CD78 4600A686 */  mov.s     $f26, $f20
/* 1400BC 8024CD7C 27B30090 */  addiu     $s3, $sp, 0x90
/* 1400C0 8024CD80 3C013F66 */  lui       $at, 0x3f66
/* 1400C4 8024CD84 34216666 */  ori       $at, $at, 0x6666
/* 1400C8 8024CD88 4481F000 */  mtc1      $at, $f30
/* 1400CC 8024CD8C 00141880 */  sll       $v1, $s4, 2
.L8024CD90:
/* 1400D0 8024CD90 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1400D4 8024CD94 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1400D8 8024CD98 3C128025 */  lui       $s2, %hi(D_8024F974)
/* 1400DC 8024CD9C 02439021 */  addu      $s2, $s2, $v1
/* 1400E0 8024CDA0 8E52F974 */  lw        $s2, %lo(D_8024F974)($s2)
/* 1400E4 8024CDA4 3C038025 */  lui       $v1, %hi(D_8024F93C)
/* 1400E8 8024CDA8 2463F93C */  addiu     $v1, $v1, %lo(D_8024F93C)
/* 1400EC 8024CDAC 94420134 */  lhu       $v0, 0x134($v0)
/* 1400F0 8024CDB0 8FB800D0 */  lw        $t8, 0xd0($sp)
/* 1400F4 8024CDB4 00021080 */  sll       $v0, $v0, 2
/* 1400F8 8024CDB8 4482B000 */  mtc1      $v0, $f22
/* 1400FC 8024CDBC 00000000 */  nop
/* 140100 8024CDC0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 140104 8024CDC4 001210C0 */  sll       $v0, $s2, 3
/* 140108 8024CDC8 00431021 */  addu      $v0, $v0, $v1
/* 14010C 8024CDCC C4580000 */  lwc1      $f24, ($v0)
/* 140110 8024CDD0 4680C620 */  cvt.s.w   $f24, $f24
/* 140114 8024CDD4 C45C0004 */  lwc1      $f28, 4($v0)
/* 140118 8024CDD8 4680E720 */  cvt.s.w   $f28, $f28
/* 14011C 8024CDDC 8302028E */  lb        $v0, 0x28e($t8)
/* 140120 8024CDE0 26430001 */  addiu     $v1, $s2, 1
/* 140124 8024CDE4 0043102A */  slt       $v0, $v0, $v1
/* 140128 8024CDE8 10400004 */  beqz      $v0, .L8024CDFC
/* 14012C 8024CDEC 0000802D */   daddu    $s0, $zero, $zero
/* 140130 8024CDF0 4480A000 */  mtc1      $zero, $f20
/* 140134 8024CDF4 080933BA */  j         .L8024CEE8
/* 140138 8024CDF8 24110080 */   addiu    $s1, $zero, 0x80
.L8024CDFC:
/* 14013C 8024CDFC 3C018027 */  lui       $at, %hi(D_80270050)
/* 140140 8024CE00 D4240050 */  ldc1      $f4, %lo(D_80270050)($at)
/* 140144 8024CE04 4600B5A1 */  cvt.d.s   $f22, $f22
/* 140148 8024CE08 4624B102 */  mul.d     $f4, $f22, $f4
/* 14014C 8024CE0C 00000000 */  nop
/* 140150 8024CE10 3C018027 */  lui       $at, %hi(D_80270058)
/* 140154 8024CE14 D4220058 */  ldc1      $f2, %lo(D_80270058)($at)
/* 140158 8024CE18 4492A000 */  mtc1      $s2, $f20
/* 14015C 8024CE1C 00000000 */  nop
/* 140160 8024CE20 4680A521 */  cvt.d.w   $f20, $f20
/* 140164 8024CE24 4622A082 */  mul.d     $f2, $f20, $f2
/* 140168 8024CE28 00000000 */  nop
/* 14016C 8024CE2C 3C018027 */  lui       $at, %hi(D_80270060)
/* 140170 8024CE30 D4200060 */  ldc1      $f0, %lo(D_80270060)($at)
/* 140174 8024CE34 46201080 */  add.d     $f2, $f2, $f0
/* 140178 8024CE38 4622B082 */  mul.d     $f2, $f22, $f2
/* 14017C 8024CE3C 00000000 */  nop
/* 140180 8024CE40 02520018 */  mult      $s2, $s2
/* 140184 8024CE44 0000C012 */  mflo      $t8
/* 140188 8024CE48 00000000 */  nop
/* 14018C 8024CE4C 00000000 */  nop
/* 140190 8024CE50 03120018 */  mult      $t8, $s2
/* 140194 8024CE54 0000C012 */  mflo      $t8
/* 140198 8024CE58 44986000 */  mtc1      $t8, $f12
/* 14019C 8024CE5C 00000000 */  nop
/* 1401A0 8024CE60 46806321 */  cvt.d.w   $f12, $f12
/* 1401A4 8024CE64 46246300 */  add.d     $f12, $f12, $f4
/* 1401A8 8024CE68 46226300 */  add.d     $f12, $f12, $f2
/* 1401AC 8024CE6C 0C00A8BB */  jal       sin_deg
/* 1401B0 8024CE70 46206320 */   cvt.s.d  $f12, $f12
/* 1401B4 8024CE74 3C013FD0 */  lui       $at, 0x3fd0
/* 1401B8 8024CE78 44816800 */  mtc1      $at, $f13
/* 1401BC 8024CE7C 44806000 */  mtc1      $zero, $f12
/* 1401C0 8024CE80 00000000 */  nop
/* 1401C4 8024CE84 462CA302 */  mul.d     $f12, $f20, $f12
/* 1401C8 8024CE88 00000000 */  nop
/* 1401CC 8024CE8C 3C018027 */  lui       $at, %hi(D_80270068)
/* 1401D0 8024CE90 D4220068 */  ldc1      $f2, %lo(D_80270068)($at)
/* 1401D4 8024CE94 4622A502 */  mul.d     $f20, $f20, $f2
/* 1401D8 8024CE98 00000000 */  nop
/* 1401DC 8024CE9C 3C018027 */  lui       $at, %hi(D_80270070)
/* 1401E0 8024CEA0 D4220070 */  ldc1      $f2, %lo(D_80270070)($at)
/* 1401E4 8024CEA4 46341081 */  sub.d     $f2, $f2, $f20
/* 1401E8 8024CEA8 4622B082 */  mul.d     $f2, $f22, $f2
/* 1401EC 8024CEAC 00000000 */  nop
/* 1401F0 8024CEB0 46366300 */  add.d     $f12, $f12, $f22
/* 1401F4 8024CEB4 46226300 */  add.d     $f12, $f12, $f2
/* 1401F8 8024CEB8 46000506 */  mov.s     $f20, $f0
/* 1401FC 8024CEBC 0C00A8BB */  jal       sin_deg
/* 140200 8024CEC0 46206320 */   cvt.s.d  $f12, $f12
/* 140204 8024CEC4 3C0140A0 */  lui       $at, 0x40a0
/* 140208 8024CEC8 44811000 */  mtc1      $at, $f2
/* 14020C 8024CECC 00000000 */  nop
/* 140210 8024CED0 4602A502 */  mul.s     $f20, $f20, $f2
/* 140214 8024CED4 00000000 */  nop
/* 140218 8024CED8 241000FF */  addiu     $s0, $zero, 0xff
/* 14021C 8024CEDC 0200882D */  daddu     $s1, $s0, $zero
/* 140220 8024CEE0 4600A502 */  mul.s     $f20, $f20, $f0
/* 140224 8024CEE4 00000000 */  nop
.L8024CEE8:
/* 140228 8024CEE8 24050008 */  addiu     $a1, $zero, 8
/* 14022C 8024CEEC 3C038027 */  lui       $v1, %hi(D_802706E0)
/* 140230 8024CEF0 246306E0 */  addiu     $v1, $v1, %lo(D_802706E0)
/* 140234 8024CEF4 00121080 */  sll       $v0, $s2, 2
/* 140238 8024CEF8 0043A821 */  addu      $s5, $v0, $v1
/* 14023C 8024CEFC 0200302D */  daddu     $a2, $s0, $zero
/* 140240 8024CF00 8EA30000 */  lw        $v1, ($s5)
/* 140244 8024CF04 24020040 */  addiu     $v0, $zero, 0x40
/* 140248 8024CF08 AFA60010 */  sw        $a2, 0x10($sp)
/* 14024C 8024CF0C AFB10014 */  sw        $s1, 0x14($sp)
/* 140250 8024CF10 AFA20018 */  sw        $v0, 0x18($sp)
/* 140254 8024CF14 00031880 */  sll       $v1, $v1, 2
/* 140258 8024CF18 00761821 */  addu      $v1, $v1, $s6
/* 14025C 8024CF1C 8C640000 */  lw        $a0, ($v1)
/* 140260 8024CF20 0C0B7A25 */  jal       func_802DE894
/* 140264 8024CF24 00C0382D */   daddu    $a3, $a2, $zero
/* 140268 8024CF28 8FB80134 */  lw        $t8, 0x134($sp)
/* 14026C 8024CF2C 27020016 */  addiu     $v0, $t8, 0x16
/* 140270 8024CF30 44820000 */  mtc1      $v0, $f0
/* 140274 8024CF34 00000000 */  nop
/* 140278 8024CF38 46800020 */  cvt.s.w   $f0, $f0
/* 14027C 8024CF3C 46180000 */  add.s     $f0, $f0, $f24
/* 140280 8024CF40 8FB80138 */  lw        $t8, 0x138($sp)
/* 140284 8024CF44 2702004D */  addiu     $v0, $t8, 0x4d
/* 140288 8024CF48 44050000 */  mfc1      $a1, $f0
/* 14028C 8024CF4C 44820000 */  mtc1      $v0, $f0
/* 140290 8024CF50 00000000 */  nop
/* 140294 8024CF54 46800020 */  cvt.s.w   $f0, $f0
/* 140298 8024CF58 461C0000 */  add.s     $f0, $f0, $f28
/* 14029C 8024CF5C 46140000 */  add.s     $f0, $f0, $f20
/* 1402A0 8024CF60 4407D000 */  mfc1      $a3, $f26
/* 1402A4 8024CF64 44060000 */  mfc1      $a2, $f0
/* 1402A8 8024CF68 0C019E40 */  jal       guTranslateF
/* 1402AC 8024CF6C 27A40050 */   addiu    $a0, $sp, 0x50
/* 1402B0 8024CF70 3C054334 */  lui       $a1, 0x4334
/* 1402B4 8024CF74 4406D000 */  mfc1      $a2, $f26
/* 1402B8 8024CF78 4407D000 */  mfc1      $a3, $f26
/* 1402BC 8024CF7C 3C013F80 */  lui       $at, 0x3f80
/* 1402C0 8024CF80 44813000 */  mtc1      $at, $f6
/* 1402C4 8024CF84 0260202D */  daddu     $a0, $s3, $zero
/* 1402C8 8024CF88 0C019EC8 */  jal       guRotateF
/* 1402CC 8024CF8C E7A60010 */   swc1     $f6, 0x10($sp)
/* 1402D0 8024CF90 0260202D */  daddu     $a0, $s3, $zero
/* 1402D4 8024CF94 27A50050 */  addiu     $a1, $sp, 0x50
/* 1402D8 8024CF98 0C019D80 */  jal       guMtxCatF
/* 1402DC 8024CF9C 00A0302D */   daddu    $a2, $a1, $zero
/* 1402E0 8024CFA0 2642FFFF */  addiu     $v0, $s2, -1
/* 1402E4 8024CFA4 2C420003 */  sltiu     $v0, $v0, 3
/* 1402E8 8024CFA8 1040000A */  beqz      $v0, .L8024CFD4
/* 1402EC 8024CFAC 0260202D */   daddu    $a0, $s3, $zero
/* 1402F0 8024CFB0 3C054334 */  lui       $a1, 0x4334
/* 1402F4 8024CFB4 4406D000 */  mfc1      $a2, $f26
/* 1402F8 8024CFB8 3C073F80 */  lui       $a3, 0x3f80
/* 1402FC 8024CFBC 0C019EC8 */  jal       guRotateF
/* 140300 8024CFC0 E7BA0010 */   swc1     $f26, 0x10($sp)
/* 140304 8024CFC4 0260202D */  daddu     $a0, $s3, $zero
/* 140308 8024CFC8 27A50050 */  addiu     $a1, $sp, 0x50
/* 14030C 8024CFCC 0C019D80 */  jal       guMtxCatF
/* 140310 8024CFD0 00A0302D */   daddu    $a2, $a1, $zero
.L8024CFD4:
/* 140314 8024CFD4 4405F000 */  mfc1      $a1, $f30
/* 140318 8024CFD8 4406F000 */  mfc1      $a2, $f30
/* 14031C 8024CFDC 4407F000 */  mfc1      $a3, $f30
/* 140320 8024CFE0 0C019DF0 */  jal       guScaleF
/* 140324 8024CFE4 0260202D */   daddu    $a0, $s3, $zero
/* 140328 8024CFE8 0260202D */  daddu     $a0, $s3, $zero
/* 14032C 8024CFEC 27A50050 */  addiu     $a1, $sp, 0x50
/* 140330 8024CFF0 0C019D80 */  jal       guMtxCatF
/* 140334 8024CFF4 00A0302D */   daddu    $a2, $a1, $zero
/* 140338 8024CFF8 0000282D */  daddu     $a1, $zero, $zero
/* 14033C 8024CFFC 00A0302D */  daddu     $a2, $a1, $zero
/* 140340 8024D000 8EA20000 */  lw        $v0, ($s5)
/* 140344 8024D004 27A30050 */  addiu     $v1, $sp, 0x50
/* 140348 8024D008 AFA30010 */  sw        $v1, 0x10($sp)
/* 14034C 8024D00C 00021080 */  sll       $v0, $v0, 2
/* 140350 8024D010 00561021 */  addu      $v0, $v0, $s6
/* 140354 8024D014 8C440000 */  lw        $a0, ($v0)
/* 140358 8024D018 0C0B78F6 */  jal       func_802DE3D8
/* 14035C 8024D01C 00A0382D */   daddu    $a3, $a1, $zero
/* 140360 8024D020 3C028027 */  lui       $v0, %hi(D_802706FC)
/* 140364 8024D024 8C4206FC */  lw        $v0, %lo(D_802706FC)($v0)
/* 140368 8024D028 26940001 */  addiu     $s4, $s4, 1
/* 14036C 8024D02C 0282102A */  slt       $v0, $s4, $v0
/* 140370 8024D030 1440FF57 */  bnez      $v0, .L8024CD90
/* 140374 8024D034 00141880 */   sll      $v1, $s4, 2
.L8024D038:
/* 140378 8024D038 3C02D838 */  lui       $v0, 0xd838
/* 14037C 8024D03C 34420002 */  ori       $v0, $v0, 2
/* 140380 8024D040 8FB80134 */  lw        $t8, 0x134($sp)
/* 140384 8024D044 3C0C800A */  lui       $t4, %hi(gMasterGfxPos)
/* 140388 8024D048 258CA66C */  addiu     $t4, $t4, %lo(gMasterGfxPos)
/* 14038C 8024D04C 27060007 */  addiu     $a2, $t8, 7
/* 140390 8024D050 8FB80138 */  lw        $t8, 0x138($sp)
/* 140394 8024D054 8D890000 */  lw        $t1, ($t4)
/* 140398 8024D058 2708000E */  addiu     $t0, $t8, 0xe
/* 14039C 8024D05C 8FB80134 */  lw        $t8, 0x134($sp)
/* 1403A0 8024D060 0120182D */  daddu     $v1, $t1, $zero
/* 1403A4 8024D064 270A0117 */  addiu     $t2, $t8, 0x117
/* 1403A8 8024D068 8FB80138 */  lw        $t8, 0x138($sp)
/* 1403AC 8024D06C 25290008 */  addiu     $t1, $t1, 8
/* 1403B0 8024D070 AD890000 */  sw        $t1, ($t4)
/* 1403B4 8024D074 AC620000 */  sw        $v0, ($v1)
/* 1403B8 8024D078 24020040 */  addiu     $v0, $zero, 0x40
/* 1403BC 8024D07C AC620004 */  sw        $v0, 4($v1)
/* 1403C0 8024D080 1CC00002 */  bgtz      $a2, .L8024D08C
/* 1403C4 8024D084 270B008C */   addiu    $t3, $t8, 0x8c
/* 1403C8 8024D088 24060001 */  addiu     $a2, $zero, 1
.L8024D08C:
/* 1403CC 8024D08C 59000001 */  blezl     $t0, .L8024D094
/* 1403D0 8024D090 24080001 */   addiu    $t0, $zero, 1
.L8024D094:
/* 1403D4 8024D094 1940006D */  blez      $t2, .L8024D24C
/* 1403D8 8024D098 00000000 */   nop
/* 1403DC 8024D09C 1960006B */  blez      $t3, .L8024D24C
/* 1403E0 8024D0A0 28C2013F */   slti     $v0, $a2, 0x13f
/* 1403E4 8024D0A4 10400069 */  beqz      $v0, .L8024D24C
/* 1403E8 8024D0A8 290200EF */   slti     $v0, $t0, 0xef
/* 1403EC 8024D0AC 10400067 */  beqz      $v0, .L8024D24C
/* 1403F0 8024D0B0 2942013F */   slti     $v0, $t2, 0x13f
/* 1403F4 8024D0B4 50400001 */  beql      $v0, $zero, .L8024D0BC
/* 1403F8 8024D0B8 240A013F */   addiu    $t2, $zero, 0x13f
.L8024D0BC:
/* 1403FC 8024D0BC 296200EF */  slti      $v0, $t3, 0xef
/* 140400 8024D0C0 50400001 */  beql      $v0, $zero, .L8024D0C8
/* 140404 8024D0C4 240B00EF */   addiu    $t3, $zero, 0xef
.L8024D0C8:
/* 140408 8024D0C8 44861000 */  mtc1      $a2, $f2
/* 14040C 8024D0CC 00000000 */  nop
/* 140410 8024D0D0 468010A0 */  cvt.s.w   $f2, $f2
/* 140414 8024D0D4 25220008 */  addiu     $v0, $t1, 8
/* 140418 8024D0D8 3C014080 */  lui       $at, 0x4080
/* 14041C 8024D0DC 44812000 */  mtc1      $at, $f4
/* 140420 8024D0E0 44880000 */  mtc1      $t0, $f0
/* 140424 8024D0E4 00000000 */  nop
/* 140428 8024D0E8 46800020 */  cvt.s.w   $f0, $f0
/* 14042C 8024D0EC 46041082 */  mul.s     $f2, $f2, $f4
/* 140430 8024D0F0 00000000 */  nop
/* 140434 8024D0F4 8FB80134 */  lw        $t8, 0x134($sp)
/* 140438 8024D0F8 3C08ED00 */  lui       $t0, 0xed00
/* 14043C 8024D0FC 27060007 */  addiu     $a2, $t8, 7
/* 140440 8024D100 8FB80138 */  lw        $t8, 0x138($sp)
/* 140444 8024D104 46040002 */  mul.s     $f0, $f0, $f4
/* 140448 8024D108 00000000 */  nop
/* 14044C 8024D10C AD820000 */  sw        $v0, ($t4)
/* 140450 8024D110 2707000E */  addiu     $a3, $t8, 0xe
/* 140454 8024D114 4600118D */  trunc.w.s $f6, $f2
/* 140458 8024D118 44023000 */  mfc1      $v0, $f6
/* 14045C 8024D11C 00000000 */  nop
/* 140460 8024D120 30420FFF */  andi      $v0, $v0, 0xfff
/* 140464 8024D124 00021300 */  sll       $v0, $v0, 0xc
/* 140468 8024D128 4600018D */  trunc.w.s $f6, $f0
/* 14046C 8024D12C 44033000 */  mfc1      $v1, $f6
/* 140470 8024D130 448A1000 */  mtc1      $t2, $f2
/* 140474 8024D134 00000000 */  nop
/* 140478 8024D138 468010A0 */  cvt.s.w   $f2, $f2
/* 14047C 8024D13C 46041082 */  mul.s     $f2, $f2, $f4
/* 140480 8024D140 00000000 */  nop
/* 140484 8024D144 30630FFF */  andi      $v1, $v1, 0xfff
/* 140488 8024D148 00681825 */  or        $v1, $v1, $t0
/* 14048C 8024D14C 00431025 */  or        $v0, $v0, $v1
/* 140490 8024D150 448B0000 */  mtc1      $t3, $f0
/* 140494 8024D154 00000000 */  nop
/* 140498 8024D158 46800020 */  cvt.s.w   $f0, $f0
/* 14049C 8024D15C 46040002 */  mul.s     $f0, $f0, $f4
/* 1404A0 8024D160 00000000 */  nop
/* 1404A4 8024D164 AD220000 */  sw        $v0, ($t1)
/* 1404A8 8024D168 4600118D */  trunc.w.s $f6, $f2
/* 1404AC 8024D16C 44023000 */  mfc1      $v0, $f6
/* 1404B0 8024D170 00000000 */  nop
/* 1404B4 8024D174 30420FFF */  andi      $v0, $v0, 0xfff
/* 1404B8 8024D178 00021300 */  sll       $v0, $v0, 0xc
/* 1404BC 8024D17C 4600018D */  trunc.w.s $f6, $f0
/* 1404C0 8024D180 44033000 */  mfc1      $v1, $f6
/* 1404C4 8024D184 00000000 */  nop
/* 1404C8 8024D188 30630FFF */  andi      $v1, $v1, 0xfff
/* 1404CC 8024D18C 00431025 */  or        $v0, $v0, $v1
/* 1404D0 8024D190 AD220004 */  sw        $v0, 4($t1)
/* 1404D4 8024D194 24020110 */  addiu     $v0, $zero, 0x110
/* 1404D8 8024D198 AFA20014 */  sw        $v0, 0x14($sp)
/* 1404DC 8024D19C 2402007E */  addiu     $v0, $zero, 0x7e
/* 1404E0 8024D1A0 AFA20018 */  sw        $v0, 0x18($sp)
/* 1404E4 8024D1A4 93A20147 */  lbu       $v0, 0x147($sp)
/* 1404E8 8024D1A8 3C013F80 */  lui       $at, 0x3f80
/* 1404EC 8024D1AC 44810000 */  mtc1      $at, $f0
/* 1404F0 8024D1B0 8FB8013C */  lw        $t8, 0x13c($sp)
/* 1404F4 8024D1B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 1404F8 8024D1B8 93A2014B */  lbu       $v0, 0x14b($sp)
/* 1404FC 8024D1BC 0000202D */  daddu     $a0, $zero, $zero
/* 140500 8024D1C0 AFA20020 */  sw        $v0, 0x20($sp)
/* 140504 8024D1C4 8FA20140 */  lw        $v0, 0x140($sp)
/* 140508 8024D1C8 3C058027 */  lui       $a1, %hi(D_8026FE78)
/* 14050C 8024D1CC 24A5FE78 */  addiu     $a1, $a1, %lo(D_8026FE78)
/* 140510 8024D1D0 AFA00010 */  sw        $zero, 0x10($sp)
/* 140514 8024D1D4 AFA0002C */  sw        $zero, 0x2c($sp)
/* 140518 8024D1D8 AFA00030 */  sw        $zero, 0x30($sp)
/* 14051C 8024D1DC AFA00034 */  sw        $zero, 0x34($sp)
/* 140520 8024D1E0 AFA00038 */  sw        $zero, 0x38($sp)
/* 140524 8024D1E4 AFA0003C */  sw        $zero, 0x3c($sp)
/* 140528 8024D1E8 AFA00040 */  sw        $zero, 0x40($sp)
/* 14052C 8024D1EC AFA0004C */  sw        $zero, 0x4c($sp)
/* 140530 8024D1F0 E7A00024 */  swc1      $f0, 0x24($sp)
/* 140534 8024D1F4 E7A00028 */  swc1      $f0, 0x28($sp)
/* 140538 8024D1F8 AFB80044 */  sw        $t8, 0x44($sp)
/* 14053C 8024D1FC 0C03D4B8 */  jal       draw_box
/* 140540 8024D200 AFA20048 */   sw       $v0, 0x48($sp)
/* 140544 8024D204 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 140548 8024D208 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 14054C 8024D20C 24020005 */  addiu     $v0, $zero, 5
/* 140550 8024D210 1462000E */  bne       $v1, $v0, .L8024D24C
/* 140554 8024D214 24040027 */   addiu    $a0, $zero, 0x27
/* 140558 8024D218 8FB80130 */  lw        $t8, 0x130($sp)
/* 14055C 8024D21C 3C038025 */  lui       $v1, %hi(D_8024F990)
/* 140560 8024D220 2463F990 */  addiu     $v1, $v1, %lo(D_8024F990)
/* 140564 8024D224 93020003 */  lbu       $v0, 3($t8)
/* 140568 8024D228 8FB80134 */  lw        $t8, 0x134($sp)
/* 14056C 8024D22C 000210C0 */  sll       $v0, $v0, 3
/* 140570 8024D230 00431021 */  addu      $v0, $v0, $v1
/* 140574 8024D234 8C450000 */  lw        $a1, ($v0)
/* 140578 8024D238 8C460004 */  lw        $a2, 4($v0)
/* 14057C 8024D23C 03052821 */  addu      $a1, $t8, $a1
/* 140580 8024D240 8FB80138 */  lw        $t8, 0x138($sp)
/* 140584 8024D244 0C090B41 */  jal       func_80242D04
/* 140588 8024D248 03063021 */   addu     $a2, $t8, $a2
.L8024D24C:
/* 14058C 8024D24C 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 140590 8024D250 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 140594 8024D254 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 140598 8024D258 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 14059C 8024D25C 8FB500EC */  lw        $s5, 0xec($sp)
/* 1405A0 8024D260 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 1405A4 8024D264 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 1405A8 8024D268 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 1405AC 8024D26C 8FB100DC */  lw        $s1, 0xdc($sp)
/* 1405B0 8024D270 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 1405B4 8024D274 D7BE0128 */  ldc1      $f30, 0x128($sp)
/* 1405B8 8024D278 D7BC0120 */  ldc1      $f28, 0x120($sp)
/* 1405BC 8024D27C D7BA0118 */  ldc1      $f26, 0x118($sp)
/* 1405C0 8024D280 D7B80110 */  ldc1      $f24, 0x110($sp)
/* 1405C4 8024D284 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 1405C8 8024D288 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 1405CC 8024D28C 03E00008 */  jr        $ra
/* 1405D0 8024D290 27BD0130 */   addiu    $sp, $sp, 0x130
