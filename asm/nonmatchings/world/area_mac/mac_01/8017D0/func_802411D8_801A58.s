.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D8_801A58
/* 801A58 802411D8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 801A5C 802411DC AFB20038 */  sw        $s2, 0x38($sp)
/* 801A60 802411E0 0080902D */  daddu     $s2, $a0, $zero
/* 801A64 802411E4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 801A68 802411E8 AFB40040 */  sw        $s4, 0x40($sp)
/* 801A6C 802411EC AFB3003C */  sw        $s3, 0x3c($sp)
/* 801A70 802411F0 AFB10034 */  sw        $s1, 0x34($sp)
/* 801A74 802411F4 AFB00030 */  sw        $s0, 0x30($sp)
/* 801A78 802411F8 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 801A7C 802411FC F7B40048 */  sdc1      $f20, 0x48($sp)
/* 801A80 80241200 8E510148 */  lw        $s1, 0x148($s2)
/* 801A84 80241204 00A0982D */  daddu     $s3, $a1, $zero
/* 801A88 80241208 86240008 */  lh        $a0, 8($s1)
/* 801A8C 8024120C 0C00EABB */  jal       get_npc_unsafe
/* 801A90 80241210 00C0A02D */   daddu    $s4, $a2, $zero
/* 801A94 80241214 8E630014 */  lw        $v1, 0x14($s3)
/* 801A98 80241218 04600030 */  bltz      $v1, .L802412DC
/* 801A9C 8024121C 0040802D */   daddu    $s0, $v0, $zero
/* 801AA0 80241220 8E420074 */  lw        $v0, 0x74($s2)
/* 801AA4 80241224 1C40002C */  bgtz      $v0, .L802412D8
/* 801AA8 80241228 2442FFFF */   addiu    $v0, $v0, -1
/* 801AAC 8024122C 0280202D */  daddu     $a0, $s4, $zero
/* 801AB0 80241230 AE430074 */  sw        $v1, 0x74($s2)
/* 801AB4 80241234 AFA00010 */  sw        $zero, 0x10($sp)
/* 801AB8 80241238 8E66000C */  lw        $a2, 0xc($s3)
/* 801ABC 8024123C 8E670010 */  lw        $a3, 0x10($s3)
/* 801AC0 80241240 0C01242D */  jal       func_800490B4
/* 801AC4 80241244 0220282D */   daddu    $a1, $s1, $zero
/* 801AC8 80241248 10400021 */  beqz      $v0, .L802412D0
/* 801ACC 8024124C 0000202D */   daddu    $a0, $zero, $zero
/* 801AD0 80241250 0200282D */  daddu     $a1, $s0, $zero
/* 801AD4 80241254 0000302D */  daddu     $a2, $zero, $zero
/* 801AD8 80241258 860300A8 */  lh        $v1, 0xa8($s0)
/* 801ADC 8024125C 3C013F80 */  lui       $at, 0x3f80
/* 801AE0 80241260 44810000 */  mtc1      $at, $f0
/* 801AE4 80241264 3C014000 */  lui       $at, 0x4000
/* 801AE8 80241268 44811000 */  mtc1      $at, $f2
/* 801AEC 8024126C 3C01C1A0 */  lui       $at, 0xc1a0
/* 801AF0 80241270 44812000 */  mtc1      $at, $f4
/* 801AF4 80241274 2402000F */  addiu     $v0, $zero, 0xf
/* 801AF8 80241278 AFA2001C */  sw        $v0, 0x1c($sp)
/* 801AFC 8024127C 44833000 */  mtc1      $v1, $f6
/* 801B00 80241280 00000000 */  nop
/* 801B04 80241284 468031A0 */  cvt.s.w   $f6, $f6
/* 801B08 80241288 44073000 */  mfc1      $a3, $f6
/* 801B0C 8024128C 27A20028 */  addiu     $v0, $sp, 0x28
/* 801B10 80241290 AFA20020 */  sw        $v0, 0x20($sp)
/* 801B14 80241294 E7A00010 */  swc1      $f0, 0x10($sp)
/* 801B18 80241298 E7A20014 */  swc1      $f2, 0x14($sp)
/* 801B1C 8024129C 0C01BFA4 */  jal       fx_emote
/* 801B20 802412A0 E7A40018 */   swc1     $f4, 0x18($sp)
/* 801B24 802412A4 0200202D */  daddu     $a0, $s0, $zero
/* 801B28 802412A8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 801B2C 802412AC 0C012530 */  jal       func_800494C0
/* 801B30 802412B0 3C060020 */   lui      $a2, 0x20
/* 801B34 802412B4 8E220018 */  lw        $v0, 0x18($s1)
/* 801B38 802412B8 9442002A */  lhu       $v0, 0x2a($v0)
/* 801B3C 802412BC 30420001 */  andi      $v0, $v0, 1
/* 801B40 802412C0 14400064 */  bnez      $v0, .L80241454
/* 801B44 802412C4 2402000A */   addiu    $v0, $zero, 0xa
/* 801B48 802412C8 08090515 */  j         .L80241454
/* 801B4C 802412CC 2402000C */   addiu    $v0, $zero, 0xc
.L802412D0:
/* 801B50 802412D0 8E420074 */  lw        $v0, 0x74($s2)
/* 801B54 802412D4 2442FFFF */  addiu     $v0, $v0, -1
.L802412D8:
/* 801B58 802412D8 AE420074 */  sw        $v0, 0x74($s2)
.L802412DC:
/* 801B5C 802412DC 8602008C */  lh        $v0, 0x8c($s0)
/* 801B60 802412E0 1440005D */  bnez      $v0, .L80241458
/* 801B64 802412E4 00000000 */   nop
/* 801B68 802412E8 C6000018 */  lwc1      $f0, 0x18($s0)
/* 801B6C 802412EC 3C014010 */  lui       $at, 0x4010
/* 801B70 802412F0 44811800 */  mtc1      $at, $f3
/* 801B74 802412F4 44801000 */  mtc1      $zero, $f2
/* 801B78 802412F8 46000021 */  cvt.d.s   $f0, $f0
/* 801B7C 802412FC 4622003C */  c.lt.d    $f0, $f2
/* 801B80 80241300 00000000 */  nop
/* 801B84 80241304 45000003 */  bc1f      .L80241314
/* 801B88 80241308 0200202D */   daddu    $a0, $s0, $zero
/* 801B8C 8024130C 080904C6 */  j         .L80241318
/* 801B90 80241310 0000282D */   daddu    $a1, $zero, $zero
.L80241314:
/* 801B94 80241314 24050001 */  addiu     $a1, $zero, 1
.L80241318:
/* 801B98 80241318 0C00F598 */  jal       func_8003D660
/* 801B9C 8024131C 00000000 */   nop
/* 801BA0 80241320 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 801BA4 80241324 8E430078 */  lw        $v1, 0x78($s2)
/* 801BA8 80241328 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 801BAC 8024132C 00031040 */  sll       $v0, $v1, 1
/* 801BB0 80241330 00431021 */  addu      $v0, $v0, $v1
/* 801BB4 80241334 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 801BB8 80241338 00021080 */  sll       $v0, $v0, 2
/* 801BBC 8024133C 00431021 */  addu      $v0, $v0, $v1
/* 801BC0 80241340 C4560004 */  lwc1      $f22, 4($v0)
/* 801BC4 80241344 4680B5A0 */  cvt.s.w   $f22, $f22
/* 801BC8 80241348 C454000C */  lwc1      $f20, 0xc($v0)
/* 801BCC 8024134C 4680A520 */  cvt.s.w   $f20, $f20
/* 801BD0 80241350 4406B000 */  mfc1      $a2, $f22
/* 801BD4 80241354 4407A000 */  mfc1      $a3, $f20
/* 801BD8 80241358 0C00A720 */  jal       atan2
/* 801BDC 8024135C 00000000 */   nop
/* 801BE0 80241360 8E050018 */  lw        $a1, 0x18($s0)
/* 801BE4 80241364 44060000 */  mfc1      $a2, $f0
/* 801BE8 80241368 0200202D */  daddu     $a0, $s0, $zero
/* 801BEC 8024136C 0C00EA95 */  jal       npc_move_heading
/* 801BF0 80241370 AE06000C */   sw       $a2, 0xc($s0)
/* 801BF4 80241374 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 801BF8 80241378 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 801BFC 8024137C 4406B000 */  mfc1      $a2, $f22
/* 801C00 80241380 4407A000 */  mfc1      $a3, $f20
/* 801C04 80241384 0C00A7B5 */  jal       dist2D
/* 801C08 80241388 00000000 */   nop
/* 801C0C 8024138C C6020018 */  lwc1      $f2, 0x18($s0)
/* 801C10 80241390 4602003E */  c.le.s    $f0, $f2
/* 801C14 80241394 00000000 */  nop
/* 801C18 80241398 4500002F */  bc1f      .L80241458
/* 801C1C 8024139C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 801C20 802413A0 24020002 */  addiu     $v0, $zero, 2
/* 801C24 802413A4 0C00A67F */  jal       rand_int
/* 801C28 802413A8 AE420070 */   sw       $v0, 0x70($s2)
/* 801C2C 802413AC 3C035555 */  lui       $v1, 0x5555
/* 801C30 802413B0 34635556 */  ori       $v1, $v1, 0x5556
/* 801C34 802413B4 00430018 */  mult      $v0, $v1
/* 801C38 802413B8 000227C3 */  sra       $a0, $v0, 0x1f
/* 801C3C 802413BC 00004010 */  mfhi      $t0
/* 801C40 802413C0 01042023 */  subu      $a0, $t0, $a0
/* 801C44 802413C4 00041840 */  sll       $v1, $a0, 1
/* 801C48 802413C8 00641821 */  addu      $v1, $v1, $a0
/* 801C4C 802413CC 00431023 */  subu      $v0, $v0, $v1
/* 801C50 802413D0 24430002 */  addiu     $v1, $v0, 2
/* 801C54 802413D4 AE430074 */  sw        $v1, 0x74($s2)
/* 801C58 802413D8 8E62002C */  lw        $v0, 0x2c($s3)
/* 801C5C 802413DC 18400009 */  blez      $v0, .L80241404
/* 801C60 802413E0 24020004 */   addiu    $v0, $zero, 4
/* 801C64 802413E4 8E620004 */  lw        $v0, 4($s3)
/* 801C68 802413E8 18400006 */  blez      $v0, .L80241404
/* 801C6C 802413EC 24020004 */   addiu    $v0, $zero, 4
/* 801C70 802413F0 8E620008 */  lw        $v0, 8($s3)
/* 801C74 802413F4 18400003 */  blez      $v0, .L80241404
/* 801C78 802413F8 24020004 */   addiu    $v0, $zero, 4
/* 801C7C 802413FC 14600002 */  bnez      $v1, .L80241408
/* 801C80 80241400 00000000 */   nop
.L80241404:
/* 801C84 80241404 AE420070 */  sw        $v0, 0x70($s2)
.L80241408:
/* 801C88 80241408 0C00A67F */  jal       rand_int
/* 801C8C 8024140C 24042710 */   addiu    $a0, $zero, 0x2710
/* 801C90 80241410 3C0351EB */  lui       $v1, 0x51eb
/* 801C94 80241414 3463851F */  ori       $v1, $v1, 0x851f
/* 801C98 80241418 00430018 */  mult      $v0, $v1
/* 801C9C 8024141C 00021FC3 */  sra       $v1, $v0, 0x1f
/* 801CA0 80241420 00004010 */  mfhi      $t0
/* 801CA4 80241424 00082143 */  sra       $a0, $t0, 5
/* 801CA8 80241428 00832023 */  subu      $a0, $a0, $v1
/* 801CAC 8024142C 00041840 */  sll       $v1, $a0, 1
/* 801CB0 80241430 00641821 */  addu      $v1, $v1, $a0
/* 801CB4 80241434 000318C0 */  sll       $v1, $v1, 3
/* 801CB8 80241438 00641821 */  addu      $v1, $v1, $a0
/* 801CBC 8024143C 00031880 */  sll       $v1, $v1, 2
/* 801CC0 80241440 8E640004 */  lw        $a0, 4($s3)
/* 801CC4 80241444 00431023 */  subu      $v0, $v0, $v1
/* 801CC8 80241448 0044102A */  slt       $v0, $v0, $a0
/* 801CCC 8024144C 10400002 */  beqz      $v0, .L80241458
/* 801CD0 80241450 24020004 */   addiu    $v0, $zero, 4
.L80241454:
/* 801CD4 80241454 AE420070 */  sw        $v0, 0x70($s2)
.L80241458:
/* 801CD8 80241458 8FBF0044 */  lw        $ra, 0x44($sp)
/* 801CDC 8024145C 8FB40040 */  lw        $s4, 0x40($sp)
/* 801CE0 80241460 8FB3003C */  lw        $s3, 0x3c($sp)
/* 801CE4 80241464 8FB20038 */  lw        $s2, 0x38($sp)
/* 801CE8 80241468 8FB10034 */  lw        $s1, 0x34($sp)
/* 801CEC 8024146C 8FB00030 */  lw        $s0, 0x30($sp)
/* 801CF0 80241470 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 801CF4 80241474 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 801CF8 80241478 03E00008 */  jr        $ra
/* 801CFC 8024147C 27BD0058 */   addiu    $sp, $sp, 0x58
