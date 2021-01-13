.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024140C_DCE0DC
/* DCE0DC 8024140C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DCE0E0 80241410 AFB40040 */  sw        $s4, 0x40($sp)
/* DCE0E4 80241414 0080A02D */  daddu     $s4, $a0, $zero
/* DCE0E8 80241418 AFBF0044 */  sw        $ra, 0x44($sp)
/* DCE0EC 8024141C AFB3003C */  sw        $s3, 0x3c($sp)
/* DCE0F0 80241420 AFB20038 */  sw        $s2, 0x38($sp)
/* DCE0F4 80241424 AFB10034 */  sw        $s1, 0x34($sp)
/* DCE0F8 80241428 AFB00030 */  sw        $s0, 0x30($sp)
/* DCE0FC 8024142C 8E910148 */  lw        $s1, 0x148($s4)
/* DCE100 80241430 00A0902D */  daddu     $s2, $a1, $zero
/* DCE104 80241434 86240008 */  lh        $a0, 8($s1)
/* DCE108 80241438 0C00EABB */  jal       get_npc_unsafe
/* DCE10C 8024143C 00C0982D */   daddu    $s3, $a2, $zero
/* DCE110 80241440 8E430014 */  lw        $v1, 0x14($s2)
/* DCE114 80241444 04600031 */  bltz      $v1, .L8024150C
/* DCE118 80241448 0040802D */   daddu    $s0, $v0, $zero
/* DCE11C 8024144C 0260202D */  daddu     $a0, $s3, $zero
/* DCE120 80241450 AFA00010 */  sw        $zero, 0x10($sp)
/* DCE124 80241454 8E460024 */  lw        $a2, 0x24($s2)
/* DCE128 80241458 8E470028 */  lw        $a3, 0x28($s2)
/* DCE12C 8024145C 0C01242D */  jal       func_800490B4
/* DCE130 80241460 0220282D */   daddu    $a1, $s1, $zero
/* DCE134 80241464 10400029 */  beqz      $v0, .L8024150C
/* DCE138 80241468 0000202D */   daddu    $a0, $zero, $zero
/* DCE13C 8024146C 0200282D */  daddu     $a1, $s0, $zero
/* DCE140 80241470 0000302D */  daddu     $a2, $zero, $zero
/* DCE144 80241474 860300A8 */  lh        $v1, 0xa8($s0)
/* DCE148 80241478 3C013F80 */  lui       $at, 0x3f80
/* DCE14C 8024147C 44810000 */  mtc1      $at, $f0
/* DCE150 80241480 3C014000 */  lui       $at, 0x4000
/* DCE154 80241484 44811000 */  mtc1      $at, $f2
/* DCE158 80241488 3C01C1A0 */  lui       $at, 0xc1a0
/* DCE15C 8024148C 44812000 */  mtc1      $at, $f4
/* DCE160 80241490 2402000F */  addiu     $v0, $zero, 0xf
/* DCE164 80241494 AFA2001C */  sw        $v0, 0x1c($sp)
/* DCE168 80241498 44833000 */  mtc1      $v1, $f6
/* DCE16C 8024149C 00000000 */  nop
/* DCE170 802414A0 468031A0 */  cvt.s.w   $f6, $f6
/* DCE174 802414A4 44073000 */  mfc1      $a3, $f6
/* DCE178 802414A8 27A20028 */  addiu     $v0, $sp, 0x28
/* DCE17C 802414AC AFA20020 */  sw        $v0, 0x20($sp)
/* DCE180 802414B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* DCE184 802414B4 E7A20014 */  swc1      $f2, 0x14($sp)
/* DCE188 802414B8 0C01BFA4 */  jal       fx_emote
/* DCE18C 802414BC E7A40018 */   swc1     $f4, 0x18($sp)
/* DCE190 802414C0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DCE194 802414C4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DCE198 802414C8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DCE19C 802414CC C60E0040 */  lwc1      $f14, 0x40($s0)
/* DCE1A0 802414D0 8C460028 */  lw        $a2, 0x28($v0)
/* DCE1A4 802414D4 0C00A720 */  jal       atan2
/* DCE1A8 802414D8 8C470030 */   lw       $a3, 0x30($v0)
/* DCE1AC 802414DC 0200202D */  daddu     $a0, $s0, $zero
/* DCE1B0 802414E0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DCE1B4 802414E4 3C060020 */  lui       $a2, 0x20
/* DCE1B8 802414E8 0C012530 */  jal       func_800494C0
/* DCE1BC 802414EC E480000C */   swc1     $f0, 0xc($a0)
/* DCE1C0 802414F0 8E220018 */  lw        $v0, 0x18($s1)
/* DCE1C4 802414F4 9442002A */  lhu       $v0, 0x2a($v0)
/* DCE1C8 802414F8 30420001 */  andi      $v0, $v0, 1
/* DCE1CC 802414FC 14400029 */  bnez      $v0, .L802415A4
/* DCE1D0 80241500 2402000A */   addiu    $v0, $zero, 0xa
/* DCE1D4 80241504 08090569 */  j         .L802415A4
/* DCE1D8 80241508 2402000C */   addiu    $v0, $zero, 0xc
.L8024150C:
/* DCE1DC 8024150C 8602008C */  lh        $v0, 0x8c($s0)
/* DCE1E0 80241510 14400025 */  bnez      $v0, .L802415A8
/* DCE1E4 80241514 00000000 */   nop
/* DCE1E8 80241518 9602008E */  lhu       $v0, 0x8e($s0)
/* DCE1EC 8024151C 2442FFFF */  addiu     $v0, $v0, -1
/* DCE1F0 80241520 A602008E */  sh        $v0, 0x8e($s0)
/* DCE1F4 80241524 00021400 */  sll       $v0, $v0, 0x10
/* DCE1F8 80241528 1440001F */  bnez      $v0, .L802415A8
/* DCE1FC 8024152C 00000000 */   nop
/* DCE200 80241530 8E820074 */  lw        $v0, 0x74($s4)
/* DCE204 80241534 2442FFFF */  addiu     $v0, $v0, -1
/* DCE208 80241538 10400019 */  beqz      $v0, .L802415A0
/* DCE20C 8024153C AE820074 */   sw       $v0, 0x74($s4)
/* DCE210 80241540 8E220018 */  lw        $v0, 0x18($s1)
/* DCE214 80241544 9442002A */  lhu       $v0, 0x2a($v0)
/* DCE218 80241548 30420010 */  andi      $v0, $v0, 0x10
/* DCE21C 8024154C 14400007 */  bnez      $v0, .L8024156C
/* DCE220 80241550 00000000 */   nop
/* DCE224 80241554 C600000C */  lwc1      $f0, 0xc($s0)
/* DCE228 80241558 3C014334 */  lui       $at, 0x4334
/* DCE22C 8024155C 44816000 */  mtc1      $at, $f12
/* DCE230 80241560 0C00A6C9 */  jal       clamp_angle
/* DCE234 80241564 460C0300 */   add.s    $f12, $f0, $f12
/* DCE238 80241568 E600000C */  swc1      $f0, 0xc($s0)
.L8024156C:
/* DCE23C 8024156C 8E440008 */  lw        $a0, 8($s2)
/* DCE240 80241570 000417C2 */  srl       $v0, $a0, 0x1f
/* DCE244 80241574 00822021 */  addu      $a0, $a0, $v0
/* DCE248 80241578 00042043 */  sra       $a0, $a0, 1
/* DCE24C 8024157C 0C00A67F */  jal       rand_int
/* DCE250 80241580 24840001 */   addiu    $a0, $a0, 1
/* DCE254 80241584 8E430008 */  lw        $v1, 8($s2)
/* DCE258 80241588 000327C2 */  srl       $a0, $v1, 0x1f
/* DCE25C 8024158C 00641821 */  addu      $v1, $v1, $a0
/* DCE260 80241590 00031843 */  sra       $v1, $v1, 1
/* DCE264 80241594 00621821 */  addu      $v1, $v1, $v0
/* DCE268 80241598 0809056A */  j         .L802415A8
/* DCE26C 8024159C A603008E */   sh       $v1, 0x8e($s0)
.L802415A0:
/* DCE270 802415A0 24020004 */  addiu     $v0, $zero, 4
.L802415A4:
/* DCE274 802415A4 AE820070 */  sw        $v0, 0x70($s4)
.L802415A8:
/* DCE278 802415A8 8FBF0044 */  lw        $ra, 0x44($sp)
/* DCE27C 802415AC 8FB40040 */  lw        $s4, 0x40($sp)
/* DCE280 802415B0 8FB3003C */  lw        $s3, 0x3c($sp)
/* DCE284 802415B4 8FB20038 */  lw        $s2, 0x38($sp)
/* DCE288 802415B8 8FB10034 */  lw        $s1, 0x34($sp)
/* DCE28C 802415BC 8FB00030 */  lw        $s0, 0x30($sp)
/* DCE290 802415C0 03E00008 */  jr        $ra
/* DCE294 802415C4 27BD0048 */   addiu    $sp, $sp, 0x48
