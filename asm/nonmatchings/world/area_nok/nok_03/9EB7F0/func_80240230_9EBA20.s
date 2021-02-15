.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240230_9EBA20
/* 9EBA20 80240230 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 9EBA24 80240234 AFB3004C */  sw        $s3, 0x4c($sp)
/* 9EBA28 80240238 0080982D */  daddu     $s3, $a0, $zero
/* 9EBA2C 8024023C AFBF0054 */  sw        $ra, 0x54($sp)
/* 9EBA30 80240240 AFB40050 */  sw        $s4, 0x50($sp)
/* 9EBA34 80240244 AFB20048 */  sw        $s2, 0x48($sp)
/* 9EBA38 80240248 AFB10044 */  sw        $s1, 0x44($sp)
/* 9EBA3C 8024024C AFB00040 */  sw        $s0, 0x40($sp)
/* 9EBA40 80240250 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 9EBA44 80240254 8E710148 */  lw        $s1, 0x148($s3)
/* 9EBA48 80240258 00A0A02D */  daddu     $s4, $a1, $zero
/* 9EBA4C 8024025C 86240008 */  lh        $a0, 8($s1)
/* 9EBA50 80240260 0C00EABB */  jal       get_npc_unsafe
/* 9EBA54 80240264 00C0902D */   daddu    $s2, $a2, $zero
/* 9EBA58 80240268 8E830014 */  lw        $v1, 0x14($s4)
/* 9EBA5C 8024026C 04600034 */  bltz      $v1, .L80240340
/* 9EBA60 80240270 0040802D */   daddu    $s0, $v0, $zero
/* 9EBA64 80240274 8E620074 */  lw        $v0, 0x74($s3)
/* 9EBA68 80240278 1C400030 */  bgtz      $v0, .L8024033C
/* 9EBA6C 8024027C 2442FFFF */   addiu    $v0, $v0, -1
/* 9EBA70 80240280 0240202D */  daddu     $a0, $s2, $zero
/* 9EBA74 80240284 AE630074 */  sw        $v1, 0x74($s3)
/* 9EBA78 80240288 AFA00010 */  sw        $zero, 0x10($sp)
/* 9EBA7C 8024028C 8E86000C */  lw        $a2, 0xc($s4)
/* 9EBA80 80240290 8E870010 */  lw        $a3, 0x10($s4)
/* 9EBA84 80240294 0C01242D */  jal       func_800490B4
/* 9EBA88 80240298 0220282D */   daddu    $a1, $s1, $zero
/* 9EBA8C 8024029C 10400025 */  beqz      $v0, .L80240334
/* 9EBA90 802402A0 0000202D */   daddu    $a0, $zero, $zero
/* 9EBA94 802402A4 0200282D */  daddu     $a1, $s0, $zero
/* 9EBA98 802402A8 0000302D */  daddu     $a2, $zero, $zero
/* 9EBA9C 802402AC 860300A8 */  lh        $v1, 0xa8($s0)
/* 9EBAA0 802402B0 3C013F80 */  lui       $at, 0x3f80
/* 9EBAA4 802402B4 44810000 */  mtc1      $at, $f0
/* 9EBAA8 802402B8 3C014000 */  lui       $at, 0x4000
/* 9EBAAC 802402BC 44811000 */  mtc1      $at, $f2
/* 9EBAB0 802402C0 3C01C1A0 */  lui       $at, 0xc1a0
/* 9EBAB4 802402C4 44812000 */  mtc1      $at, $f4
/* 9EBAB8 802402C8 2402000F */  addiu     $v0, $zero, 0xf
/* 9EBABC 802402CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 9EBAC0 802402D0 44835000 */  mtc1      $v1, $f10
/* 9EBAC4 802402D4 00000000 */  nop
/* 9EBAC8 802402D8 468052A0 */  cvt.s.w   $f10, $f10
/* 9EBACC 802402DC 44075000 */  mfc1      $a3, $f10
/* 9EBAD0 802402E0 27A20028 */  addiu     $v0, $sp, 0x28
/* 9EBAD4 802402E4 AFA20020 */  sw        $v0, 0x20($sp)
/* 9EBAD8 802402E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9EBADC 802402EC E7A20014 */  swc1      $f2, 0x14($sp)
/* 9EBAE0 802402F0 0C01BFA4 */  jal       fx_emote
/* 9EBAE4 802402F4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9EBAE8 802402F8 0200202D */  daddu     $a0, $s0, $zero
/* 9EBAEC 802402FC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9EBAF0 80240300 0C012530 */  jal       func_800494C0
/* 9EBAF4 80240304 3C060020 */   lui      $a2, 0x20
/* 9EBAF8 80240308 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9EBAFC 8024030C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9EBB00 80240310 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9EBB04 80240314 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9EBB08 80240318 8C460028 */  lw        $a2, 0x28($v0)
/* 9EBB0C 8024031C 0C00A720 */  jal       atan2
/* 9EBB10 80240320 8C470030 */   lw       $a3, 0x30($v0)
/* 9EBB14 80240324 2402000C */  addiu     $v0, $zero, 0xc
/* 9EBB18 80240328 E600000C */  swc1      $f0, 0xc($s0)
/* 9EBB1C 8024032C 08090151 */  j         .L80240544
/* 9EBB20 80240330 AE620070 */   sw       $v0, 0x70($s3)
.L80240334:
/* 9EBB24 80240334 8E620074 */  lw        $v0, 0x74($s3)
/* 9EBB28 80240338 2442FFFF */  addiu     $v0, $v0, -1
.L8024033C:
/* 9EBB2C 8024033C AE620074 */  sw        $v0, 0x74($s3)
.L80240340:
/* 9EBB30 80240340 C6000018 */  lwc1      $f0, 0x18($s0)
/* 9EBB34 80240344 44801000 */  mtc1      $zero, $f2
/* 9EBB38 80240348 44801800 */  mtc1      $zero, $f3
/* 9EBB3C 8024034C 46000021 */  cvt.d.s   $f0, $f0
/* 9EBB40 80240350 4620103C */  c.lt.d    $f2, $f0
/* 9EBB44 80240354 00000000 */  nop
/* 9EBB48 80240358 45000025 */  bc1f      .L802403F0
/* 9EBB4C 8024035C 27A5002C */   addiu    $a1, $sp, 0x2c
/* 9EBB50 80240360 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9EBB54 80240364 860200A6 */  lh        $v0, 0xa6($s0)
/* 9EBB58 80240368 3C018024 */  lui       $at, %hi(D_802423B0_9EDBA0)
/* 9EBB5C 8024036C D42223B0 */  ldc1      $f2, %lo(D_802423B0_9EDBA0)($at)
/* 9EBB60 80240370 27A60030 */  addiu     $a2, $sp, 0x30
/* 9EBB64 80240374 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 9EBB68 80240378 44820000 */  mtc1      $v0, $f0
/* 9EBB6C 8024037C 00000000 */  nop
/* 9EBB70 80240380 46800020 */  cvt.s.w   $f0, $f0
/* 9EBB74 80240384 46000021 */  cvt.d.s   $f0, $f0
/* 9EBB78 80240388 C604003C */  lwc1      $f4, 0x3c($s0)
/* 9EBB7C 8024038C C6060040 */  lwc1      $f6, 0x40($s0)
/* 9EBB80 80240390 C6080018 */  lwc1      $f8, 0x18($s0)
/* 9EBB84 80240394 860200A8 */  lh        $v0, 0xa8($s0)
/* 9EBB88 80240398 46220002 */  mul.d     $f0, $f0, $f2
/* 9EBB8C 8024039C 00000000 */  nop
/* 9EBB90 802403A0 E7A40030 */  swc1      $f4, 0x30($sp)
/* 9EBB94 802403A4 E7A60034 */  swc1      $f6, 0x34($sp)
/* 9EBB98 802403A8 E7A80010 */  swc1      $f8, 0x10($sp)
/* 9EBB9C 802403AC C604000C */  lwc1      $f4, 0xc($s0)
/* 9EBBA0 802403B0 44821000 */  mtc1      $v0, $f2
/* 9EBBA4 802403B4 00000000 */  nop
/* 9EBBA8 802403B8 468010A0 */  cvt.s.w   $f2, $f2
/* 9EBBAC 802403BC E7A20018 */  swc1      $f2, 0x18($sp)
/* 9EBBB0 802403C0 E7A40014 */  swc1      $f4, 0x14($sp)
/* 9EBBB4 802403C4 46200020 */  cvt.s.d   $f0, $f0
/* 9EBBB8 802403C8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 9EBBBC 802403CC 8E040080 */  lw        $a0, 0x80($s0)
/* 9EBBC0 802403D0 0C037711 */  jal       func_800DDC44
/* 9EBBC4 802403D4 27A70034 */   addiu    $a3, $sp, 0x34
/* 9EBBC8 802403D8 54400005 */  bnel      $v0, $zero, .L802403F0
/* 9EBBCC 802403DC AE000018 */   sw       $zero, 0x18($s0)
/* 9EBBD0 802403E0 8E050018 */  lw        $a1, 0x18($s0)
/* 9EBBD4 802403E4 8E06000C */  lw        $a2, 0xc($s0)
/* 9EBBD8 802403E8 0C00EA95 */  jal       npc_move_heading
/* 9EBBDC 802403EC 0200202D */   daddu    $a0, $s0, $zero
.L802403F0:
/* 9EBBE0 802403F0 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9EBBE4 802403F4 44801000 */  mtc1      $zero, $f2
/* 9EBBE8 802403F8 44801800 */  mtc1      $zero, $f3
/* 9EBBEC 802403FC 46000021 */  cvt.d.s   $f0, $f0
/* 9EBBF0 80240400 4622003C */  c.lt.d    $f0, $f2
/* 9EBBF4 80240404 00000000 */  nop
/* 9EBBF8 80240408 45000047 */  bc1f      .L80240528
/* 9EBBFC 8024040C 27A5002C */   addiu    $a1, $sp, 0x2c
/* 9EBC00 80240410 27A60030 */  addiu     $a2, $sp, 0x30
/* 9EBC04 80240414 27A20038 */  addiu     $v0, $sp, 0x38
/* 9EBC08 80240418 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9EBC0C 8024041C C6060038 */  lwc1      $f6, 0x38($s0)
/* 9EBC10 80240420 3C01402A */  lui       $at, 0x402a
/* 9EBC14 80240424 4481A800 */  mtc1      $at, $f21
/* 9EBC18 80240428 4480A000 */  mtc1      $zero, $f20
/* 9EBC1C 8024042C 460010A1 */  cvt.d.s   $f2, $f2
/* 9EBC20 80240430 46341080 */  add.d     $f2, $f2, $f20
/* 9EBC24 80240434 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9EBC28 80240438 C6040040 */  lwc1      $f4, 0x40($s0)
/* 9EBC2C 8024043C 46000005 */  abs.s     $f0, $f0
/* 9EBC30 80240440 E7A40034 */  swc1      $f4, 0x34($sp)
/* 9EBC34 80240444 3C014030 */  lui       $at, 0x4030
/* 9EBC38 80240448 44812800 */  mtc1      $at, $f5
/* 9EBC3C 8024044C 44802000 */  mtc1      $zero, $f4
/* 9EBC40 80240450 46000021 */  cvt.d.s   $f0, $f0
/* 9EBC44 80240454 E7A6002C */  swc1      $f6, 0x2c($sp)
/* 9EBC48 80240458 46240000 */  add.d     $f0, $f0, $f4
/* 9EBC4C 8024045C 462010A0 */  cvt.s.d   $f2, $f2
/* 9EBC50 80240460 E7A20030 */  swc1      $f2, 0x30($sp)
/* 9EBC54 80240464 46200020 */  cvt.s.d   $f0, $f0
/* 9EBC58 80240468 E7A00038 */  swc1      $f0, 0x38($sp)
/* 9EBC5C 8024046C AFA20010 */  sw        $v0, 0x10($sp)
/* 9EBC60 80240470 8E040080 */  lw        $a0, 0x80($s0)
/* 9EBC64 80240474 0C0372DF */  jal       func_800DCB7C
/* 9EBC68 80240478 27A70034 */   addiu    $a3, $sp, 0x34
/* 9EBC6C 8024047C 1040002A */  beqz      $v0, .L80240528
/* 9EBC70 80240480 00000000 */   nop
/* 9EBC74 80240484 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9EBC78 80240488 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 9EBC7C 8024048C 46000005 */  abs.s     $f0, $f0
/* 9EBC80 80240490 46000021 */  cvt.d.s   $f0, $f0
/* 9EBC84 80240494 46340000 */  add.d     $f0, $f0, $f20
/* 9EBC88 80240498 460010A1 */  cvt.d.s   $f2, $f2
/* 9EBC8C 8024049C 4620103E */  c.le.d    $f2, $f0
/* 9EBC90 802404A0 00000000 */  nop
/* 9EBC94 802404A4 45000020 */  bc1f      .L80240528
/* 9EBC98 802404A8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 9EBC9C 802404AC C7A00030 */  lwc1      $f0, 0x30($sp)
/* 9EBCA0 802404B0 8E020000 */  lw        $v0, ($s0)
/* 9EBCA4 802404B4 2403F7FF */  addiu     $v1, $zero, -0x801
/* 9EBCA8 802404B8 AE00001C */  sw        $zero, 0x1c($s0)
/* 9EBCAC 802404BC 00431024 */  and       $v0, $v0, $v1
/* 9EBCB0 802404C0 AE020000 */  sw        $v0, ($s0)
/* 9EBCB4 802404C4 24020002 */  addiu     $v0, $zero, 2
/* 9EBCB8 802404C8 E600003C */  swc1      $f0, 0x3c($s0)
/* 9EBCBC 802404CC 0C00A67F */  jal       rand_int
/* 9EBCC0 802404D0 AE620070 */   sw       $v0, 0x70($s3)
/* 9EBCC4 802404D4 3C035555 */  lui       $v1, 0x5555
/* 9EBCC8 802404D8 34635556 */  ori       $v1, $v1, 0x5556
/* 9EBCCC 802404DC 00430018 */  mult      $v0, $v1
/* 9EBCD0 802404E0 000227C3 */  sra       $a0, $v0, 0x1f
/* 9EBCD4 802404E4 00004010 */  mfhi      $t0
/* 9EBCD8 802404E8 01042023 */  subu      $a0, $t0, $a0
/* 9EBCDC 802404EC 00041840 */  sll       $v1, $a0, 1
/* 9EBCE0 802404F0 00641821 */  addu      $v1, $v1, $a0
/* 9EBCE4 802404F4 00431023 */  subu      $v0, $v0, $v1
/* 9EBCE8 802404F8 24430002 */  addiu     $v1, $v0, 2
/* 9EBCEC 802404FC AE630074 */  sw        $v1, 0x74($s3)
/* 9EBCF0 80240500 8E82002C */  lw        $v0, 0x2c($s4)
/* 9EBCF4 80240504 5840000F */  blezl     $v0, .L80240544
/* 9EBCF8 80240508 AE600070 */   sw       $zero, 0x70($s3)
/* 9EBCFC 8024050C 8E820004 */  lw        $v0, 4($s4)
/* 9EBD00 80240510 5840000C */  blezl     $v0, .L80240544
/* 9EBD04 80240514 AE600070 */   sw       $zero, 0x70($s3)
/* 9EBD08 80240518 1460000A */  bnez      $v1, .L80240544
/* 9EBD0C 8024051C 00000000 */   nop
/* 9EBD10 80240520 08090151 */  j         .L80240544
/* 9EBD14 80240524 AE600070 */   sw       $zero, 0x70($s3)
.L80240528:
/* 9EBD18 80240528 C604003C */  lwc1      $f4, 0x3c($s0)
/* 9EBD1C 8024052C C600001C */  lwc1      $f0, 0x1c($s0)
/* 9EBD20 80240530 46002100 */  add.s     $f4, $f4, $f0
/* 9EBD24 80240534 C6020014 */  lwc1      $f2, 0x14($s0)
/* 9EBD28 80240538 46020001 */  sub.s     $f0, $f0, $f2
/* 9EBD2C 8024053C E604003C */  swc1      $f4, 0x3c($s0)
/* 9EBD30 80240540 E600001C */  swc1      $f0, 0x1c($s0)
.L80240544:
/* 9EBD34 80240544 8FBF0054 */  lw        $ra, 0x54($sp)
/* 9EBD38 80240548 8FB40050 */  lw        $s4, 0x50($sp)
/* 9EBD3C 8024054C 8FB3004C */  lw        $s3, 0x4c($sp)
/* 9EBD40 80240550 8FB20048 */  lw        $s2, 0x48($sp)
/* 9EBD44 80240554 8FB10044 */  lw        $s1, 0x44($sp)
/* 9EBD48 80240558 8FB00040 */  lw        $s0, 0x40($sp)
/* 9EBD4C 8024055C D7B40058 */  ldc1      $f20, 0x58($sp)
/* 9EBD50 80240560 03E00008 */  jr        $ra
/* 9EBD54 80240564 27BD0060 */   addiu    $sp, $sp, 0x60
