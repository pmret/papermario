.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411E8_BEDFD8
/* BEDFD8 802411E8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* BEDFDC 802411EC AFB3004C */  sw        $s3, 0x4c($sp)
/* BEDFE0 802411F0 0080982D */  daddu     $s3, $a0, $zero
/* BEDFE4 802411F4 AFBF0054 */  sw        $ra, 0x54($sp)
/* BEDFE8 802411F8 AFB40050 */  sw        $s4, 0x50($sp)
/* BEDFEC 802411FC AFB20048 */  sw        $s2, 0x48($sp)
/* BEDFF0 80241200 AFB10044 */  sw        $s1, 0x44($sp)
/* BEDFF4 80241204 AFB00040 */  sw        $s0, 0x40($sp)
/* BEDFF8 80241208 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* BEDFFC 8024120C F7B80068 */  sdc1      $f24, 0x68($sp)
/* BEE000 80241210 F7B60060 */  sdc1      $f22, 0x60($sp)
/* BEE004 80241214 F7B40058 */  sdc1      $f20, 0x58($sp)
/* BEE008 80241218 8E710148 */  lw        $s1, 0x148($s3)
/* BEE00C 8024121C 00A0902D */  daddu     $s2, $a1, $zero
/* BEE010 80241220 86240008 */  lh        $a0, 8($s1)
/* BEE014 80241224 0C00EABB */  jal       get_npc_unsafe
/* BEE018 80241228 00C0A02D */   daddu    $s4, $a2, $zero
/* BEE01C 8024122C 0040802D */  daddu     $s0, $v0, $zero
/* BEE020 80241230 C6200078 */  lwc1      $f0, 0x78($s1)
/* BEE024 80241234 46800020 */  cvt.s.w   $f0, $f0
/* BEE028 80241238 46000021 */  cvt.d.s   $f0, $f0
/* BEE02C 8024123C 3C014059 */  lui       $at, 0x4059
/* BEE030 80241240 44811800 */  mtc1      $at, $f3
/* BEE034 80241244 44801000 */  mtc1      $zero, $f2
/* BEE038 80241248 8602008E */  lh        $v0, 0x8e($s0)
/* BEE03C 8024124C 9603008E */  lhu       $v1, 0x8e($s0)
/* BEE040 80241250 46220003 */  div.d     $f0, $f0, $f2
/* BEE044 80241254 46200620 */  cvt.s.d   $f24, $f0
/* BEE048 80241258 C6200088 */  lwc1      $f0, 0x88($s1)
/* BEE04C 8024125C 46800020 */  cvt.s.w   $f0, $f0
/* BEE050 80241260 46000021 */  cvt.d.s   $f0, $f0
/* BEE054 80241264 46220003 */  div.d     $f0, $f0, $f2
/* BEE058 80241268 46200020 */  cvt.s.d   $f0, $f0
/* BEE05C 8024126C 18400003 */  blez      $v0, .L8024127C
/* BEE060 80241270 4600C680 */   add.s    $f26, $f24, $f0
/* BEE064 80241274 2462FFFF */  addiu     $v0, $v1, -1
/* BEE068 80241278 A602008E */  sh        $v0, 0x8e($s0)
.L8024127C:
/* BEE06C 8024127C 8E220070 */  lw        $v0, 0x70($s1)
/* BEE070 80241280 18400034 */  blez      $v0, .L80241354
/* BEE074 80241284 00000000 */   nop      
/* BEE078 80241288 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BEE07C 8024128C 46806320 */  cvt.s.w   $f12, $f12
/* BEE080 80241290 44820000 */  mtc1      $v0, $f0
/* BEE084 80241294 00000000 */  nop       
/* BEE088 80241298 46800020 */  cvt.s.w   $f0, $f0
/* BEE08C 8024129C 46000021 */  cvt.d.s   $f0, $f0
/* BEE090 802412A0 46220003 */  div.d     $f0, $f0, $f2
/* BEE094 802412A4 0C00A8BB */  jal       sin_deg
/* BEE098 802412A8 462005A0 */   cvt.s.d  $f22, $f0
/* BEE09C 802412AC 8E020000 */  lw        $v0, ($s0)
/* BEE0A0 802412B0 30420008 */  andi      $v0, $v0, 8
/* BEE0A4 802412B4 10400003 */  beqz      $v0, .L802412C4
/* BEE0A8 802412B8 46000506 */   mov.s    $f20, $f0
/* BEE0AC 802412BC 080904C1 */  j         .L80241304
/* BEE0B0 802412C0 0000102D */   daddu    $v0, $zero, $zero
.L802412C4:
/* BEE0B4 802412C4 27A50028 */  addiu     $a1, $sp, 0x28
/* BEE0B8 802412C8 27A6002C */  addiu     $a2, $sp, 0x2c
/* BEE0BC 802412CC C6000038 */  lwc1      $f0, 0x38($s0)
/* BEE0C0 802412D0 C602003C */  lwc1      $f2, 0x3c($s0)
/* BEE0C4 802412D4 C6040040 */  lwc1      $f4, 0x40($s0)
/* BEE0C8 802412D8 3C01447A */  lui       $at, 0x447a
/* BEE0CC 802412DC 44813000 */  mtc1      $at, $f6
/* BEE0D0 802412E0 27A20034 */  addiu     $v0, $sp, 0x34
/* BEE0D4 802412E4 E7A00028 */  swc1      $f0, 0x28($sp)
/* BEE0D8 802412E8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BEE0DC 802412EC E7A40030 */  swc1      $f4, 0x30($sp)
/* BEE0E0 802412F0 E7A60034 */  swc1      $f6, 0x34($sp)
/* BEE0E4 802412F4 AFA20010 */  sw        $v0, 0x10($sp)
/* BEE0E8 802412F8 8E040080 */  lw        $a0, 0x80($s0)
/* BEE0EC 802412FC 0C0372DF */  jal       func_800DCB7C
/* BEE0F0 80241300 27A70030 */   addiu    $a3, $sp, 0x30
.L80241304:
/* BEE0F4 80241304 10400007 */  beqz      $v0, .L80241324
/* BEE0F8 80241308 00000000 */   nop      
/* BEE0FC 8024130C 4616A082 */  mul.s     $f2, $f20, $f22
/* BEE100 80241310 00000000 */  nop       
/* BEE104 80241314 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BEE108 80241318 46180000 */  add.s     $f0, $f0, $f24
/* BEE10C 8024131C 080904CC */  j         .L80241330
/* BEE110 80241320 46020000 */   add.s    $f0, $f0, $f2
.L80241324:
/* BEE114 80241324 4616A002 */  mul.s     $f0, $f20, $f22
/* BEE118 80241328 00000000 */  nop       
/* BEE11C 8024132C 4600D000 */  add.s     $f0, $f26, $f0
.L80241330:
/* BEE120 80241330 E600003C */  swc1      $f0, 0x3c($s0)
/* BEE124 80241334 8E220074 */  lw        $v0, 0x74($s1)
/* BEE128 80241338 2442000A */  addiu     $v0, $v0, 0xa
/* BEE12C 8024133C 44826000 */  mtc1      $v0, $f12
/* BEE130 80241340 00000000 */  nop       
/* BEE134 80241344 0C00A6C9 */  jal       clamp_angle
/* BEE138 80241348 46806320 */   cvt.s.w  $f12, $f12
/* BEE13C 8024134C 4600020D */  trunc.w.s $f8, $f0
/* BEE140 80241350 E6280074 */  swc1      $f8, 0x74($s1)
.L80241354:
/* BEE144 80241354 8E220090 */  lw        $v0, 0x90($s1)
/* BEE148 80241358 1C400040 */  bgtz      $v0, .L8024145C
/* BEE14C 8024135C 2442FFFF */   addiu    $v0, $v0, -1
/* BEE150 80241360 860200A8 */  lh        $v0, 0xa8($s0)
/* BEE154 80241364 C600003C */  lwc1      $f0, 0x3c($s0)
/* BEE158 80241368 44821000 */  mtc1      $v0, $f2
/* BEE15C 8024136C 00000000 */  nop       
/* BEE160 80241370 468010A0 */  cvt.s.w   $f2, $f2
/* BEE164 80241374 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BEE168 80241378 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BEE16C 8024137C 46020000 */  add.s     $f0, $f0, $f2
/* BEE170 80241380 3C014024 */  lui       $at, 0x4024
/* BEE174 80241384 44812800 */  mtc1      $at, $f5
/* BEE178 80241388 44802000 */  mtc1      $zero, $f4
/* BEE17C 8024138C C442002C */  lwc1      $f2, 0x2c($v0)
/* BEE180 80241390 46000021 */  cvt.d.s   $f0, $f0
/* BEE184 80241394 46240000 */  add.d     $f0, $f0, $f4
/* BEE188 80241398 460010A1 */  cvt.d.s   $f2, $f2
/* BEE18C 8024139C 4620103C */  c.lt.d    $f2, $f0
/* BEE190 802413A0 00000000 */  nop       
/* BEE194 802413A4 4500002E */  bc1f      .L80241460
/* BEE198 802413A8 0280202D */   daddu    $a0, $s4, $zero
/* BEE19C 802413AC 24020001 */  addiu     $v0, $zero, 1
/* BEE1A0 802413B0 AFA20010 */  sw        $v0, 0x10($sp)
/* BEE1A4 802413B4 8E460024 */  lw        $a2, 0x24($s2)
/* BEE1A8 802413B8 8E470028 */  lw        $a3, 0x28($s2)
/* BEE1AC 802413BC 0C01242D */  jal       func_800490B4
/* BEE1B0 802413C0 0220282D */   daddu    $a1, $s1, $zero
/* BEE1B4 802413C4 10400026 */  beqz      $v0, .L80241460
/* BEE1B8 802413C8 0000202D */   daddu    $a0, $zero, $zero
/* BEE1BC 802413CC 0200282D */  daddu     $a1, $s0, $zero
/* BEE1C0 802413D0 0000302D */  daddu     $a2, $zero, $zero
/* BEE1C4 802413D4 2412000C */  addiu     $s2, $zero, 0xc
/* BEE1C8 802413D8 860300A8 */  lh        $v1, 0xa8($s0)
/* BEE1CC 802413DC 3C013F80 */  lui       $at, 0x3f80
/* BEE1D0 802413E0 44810000 */  mtc1      $at, $f0
/* BEE1D4 802413E4 3C014000 */  lui       $at, 0x4000
/* BEE1D8 802413E8 44811000 */  mtc1      $at, $f2
/* BEE1DC 802413EC 3C01C1A0 */  lui       $at, 0xc1a0
/* BEE1E0 802413F0 44812000 */  mtc1      $at, $f4
/* BEE1E4 802413F4 44834000 */  mtc1      $v1, $f8
/* BEE1E8 802413F8 00000000 */  nop       
/* BEE1EC 802413FC 46804220 */  cvt.s.w   $f8, $f8
/* BEE1F0 80241400 44074000 */  mfc1      $a3, $f8
/* BEE1F4 80241404 27A20038 */  addiu     $v0, $sp, 0x38
/* BEE1F8 80241408 AFB2001C */  sw        $s2, 0x1c($sp)
/* BEE1FC 8024140C AFA20020 */  sw        $v0, 0x20($sp)
/* BEE200 80241410 E7A00010 */  swc1      $f0, 0x10($sp)
/* BEE204 80241414 E7A20014 */  swc1      $f2, 0x14($sp)
/* BEE208 80241418 0C01BFA4 */  jal       fx_emote
/* BEE20C 8024141C E7A40018 */   swc1     $f4, 0x18($sp)
/* BEE210 80241420 0200202D */  daddu     $a0, $s0, $zero
/* BEE214 80241424 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BEE218 80241428 C480003C */  lwc1      $f0, 0x3c($a0)
/* BEE21C 8024142C 3C060020 */  lui       $a2, 0x20
/* BEE220 80241430 0C012530 */  jal       func_800494C0
/* BEE224 80241434 E4800064 */   swc1     $f0, 0x64($a0)
/* BEE228 80241438 8E220018 */  lw        $v0, 0x18($s1)
/* BEE22C 8024143C 9442002A */  lhu       $v0, 0x2a($v0)
/* BEE230 80241440 30420001 */  andi      $v0, $v0, 1
/* BEE234 80241444 10400003 */  beqz      $v0, .L80241454
/* BEE238 80241448 2402000A */   addiu    $v0, $zero, 0xa
/* BEE23C 8024144C 0809053F */  j         .L802414FC
/* BEE240 80241450 AE620070 */   sw       $v0, 0x70($s3)
.L80241454:
/* BEE244 80241454 0809053F */  j         .L802414FC
/* BEE248 80241458 AE720070 */   sw       $s2, 0x70($s3)
.L8024145C:
/* BEE24C 8024145C AE220090 */  sw        $v0, 0x90($s1)
.L80241460:
/* BEE250 80241460 8602008C */  lh        $v0, 0x8c($s0)
/* BEE254 80241464 14400025 */  bnez      $v0, .L802414FC
/* BEE258 80241468 00000000 */   nop      
/* BEE25C 8024146C 8602008E */  lh        $v0, 0x8e($s0)
/* BEE260 80241470 1C400022 */  bgtz      $v0, .L802414FC
/* BEE264 80241474 00000000 */   nop      
/* BEE268 80241478 8E620074 */  lw        $v0, 0x74($s3)
/* BEE26C 8024147C 2442FFFF */  addiu     $v0, $v0, -1
/* BEE270 80241480 1840001D */  blez      $v0, .L802414F8
/* BEE274 80241484 AE620074 */   sw       $v0, 0x74($s3)
/* BEE278 80241488 8E220018 */  lw        $v0, 0x18($s1)
/* BEE27C 8024148C 9442002A */  lhu       $v0, 0x2a($v0)
/* BEE280 80241490 30420010 */  andi      $v0, $v0, 0x10
/* BEE284 80241494 14400007 */  bnez      $v0, .L802414B4
/* BEE288 80241498 00000000 */   nop      
/* BEE28C 8024149C C600000C */  lwc1      $f0, 0xc($s0)
/* BEE290 802414A0 3C014334 */  lui       $at, 0x4334
/* BEE294 802414A4 44816000 */  mtc1      $at, $f12
/* BEE298 802414A8 0C00A6C9 */  jal       clamp_angle
/* BEE29C 802414AC 460C0300 */   add.s    $f12, $f0, $f12
/* BEE2A0 802414B0 E600000C */  swc1      $f0, 0xc($s0)
.L802414B4:
/* BEE2A4 802414B4 0C00A67F */  jal       rand_int
/* BEE2A8 802414B8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BEE2AC 802414BC 3C032E8B */  lui       $v1, 0x2e8b
/* BEE2B0 802414C0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BEE2B4 802414C4 00430018 */  mult      $v0, $v1
/* BEE2B8 802414C8 00021FC3 */  sra       $v1, $v0, 0x1f
/* BEE2BC 802414CC 00004010 */  mfhi      $t0
/* BEE2C0 802414D0 00082043 */  sra       $a0, $t0, 1
/* BEE2C4 802414D4 00832023 */  subu      $a0, $a0, $v1
/* BEE2C8 802414D8 00041840 */  sll       $v1, $a0, 1
/* BEE2CC 802414DC 00641821 */  addu      $v1, $v1, $a0
/* BEE2D0 802414E0 00031880 */  sll       $v1, $v1, 2
/* BEE2D4 802414E4 00641823 */  subu      $v1, $v1, $a0
/* BEE2D8 802414E8 00431023 */  subu      $v0, $v0, $v1
/* BEE2DC 802414EC 24420005 */  addiu     $v0, $v0, 5
/* BEE2E0 802414F0 0809053F */  j         .L802414FC
/* BEE2E4 802414F4 A602008E */   sh       $v0, 0x8e($s0)
.L802414F8:
/* BEE2E8 802414F8 AE600070 */  sw        $zero, 0x70($s3)
.L802414FC:
/* BEE2EC 802414FC 8FBF0054 */  lw        $ra, 0x54($sp)
/* BEE2F0 80241500 8FB40050 */  lw        $s4, 0x50($sp)
/* BEE2F4 80241504 8FB3004C */  lw        $s3, 0x4c($sp)
/* BEE2F8 80241508 8FB20048 */  lw        $s2, 0x48($sp)
/* BEE2FC 8024150C 8FB10044 */  lw        $s1, 0x44($sp)
/* BEE300 80241510 8FB00040 */  lw        $s0, 0x40($sp)
/* BEE304 80241514 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* BEE308 80241518 D7B80068 */  ldc1      $f24, 0x68($sp)
/* BEE30C 8024151C D7B60060 */  ldc1      $f22, 0x60($sp)
/* BEE310 80241520 D7B40058 */  ldc1      $f20, 0x58($sp)
/* BEE314 80241524 03E00008 */  jr        $ra
/* BEE318 80241528 27BD0078 */   addiu    $sp, $sp, 0x78
