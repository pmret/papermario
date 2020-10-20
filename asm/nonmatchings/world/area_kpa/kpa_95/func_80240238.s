.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240238
/* A8CCB8 80240238 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A8CCBC 8024023C AFB20038 */  sw        $s2, 0x38($sp)
/* A8CCC0 80240240 0080902D */  daddu     $s2, $a0, $zero
/* A8CCC4 80240244 AFBF0044 */  sw        $ra, 0x44($sp)
/* A8CCC8 80240248 AFB40040 */  sw        $s4, 0x40($sp)
/* A8CCCC 8024024C AFB3003C */  sw        $s3, 0x3c($sp)
/* A8CCD0 80240250 AFB10034 */  sw        $s1, 0x34($sp)
/* A8CCD4 80240254 AFB00030 */  sw        $s0, 0x30($sp)
/* A8CCD8 80240258 F7B60050 */  sdc1      $f22, 0x50($sp)
/* A8CCDC 8024025C F7B40048 */  sdc1      $f20, 0x48($sp)
/* A8CCE0 80240260 8E510148 */  lw        $s1, 0x148($s2)
/* A8CCE4 80240264 00A0982D */  daddu     $s3, $a1, $zero
/* A8CCE8 80240268 86240008 */  lh        $a0, 8($s1)
/* A8CCEC 8024026C 0C00EABB */  jal       get_npc_unsafe
/* A8CCF0 80240270 00C0A02D */   daddu    $s4, $a2, $zero
/* A8CCF4 80240274 8E630014 */  lw        $v1, 0x14($s3)
/* A8CCF8 80240278 04600030 */  bltz      $v1, .L8024033C
/* A8CCFC 8024027C 0040802D */   daddu    $s0, $v0, $zero
/* A8CD00 80240280 8E420074 */  lw        $v0, 0x74($s2)
/* A8CD04 80240284 1C40002C */  bgtz      $v0, .L80240338
/* A8CD08 80240288 2442FFFF */   addiu    $v0, $v0, -1
/* A8CD0C 8024028C 0280202D */  daddu     $a0, $s4, $zero
/* A8CD10 80240290 AE430074 */  sw        $v1, 0x74($s2)
/* A8CD14 80240294 AFA00010 */  sw        $zero, 0x10($sp)
/* A8CD18 80240298 8E66000C */  lw        $a2, 0xc($s3)
/* A8CD1C 8024029C 8E670010 */  lw        $a3, 0x10($s3)
/* A8CD20 802402A0 0C01242D */  jal       func_800490B4
/* A8CD24 802402A4 0220282D */   daddu    $a1, $s1, $zero
/* A8CD28 802402A8 10400021 */  beqz      $v0, .L80240330
/* A8CD2C 802402AC 0000202D */   daddu    $a0, $zero, $zero
/* A8CD30 802402B0 0200282D */  daddu     $a1, $s0, $zero
/* A8CD34 802402B4 0000302D */  daddu     $a2, $zero, $zero
/* A8CD38 802402B8 860300A8 */  lh        $v1, 0xa8($s0)
/* A8CD3C 802402BC 3C013F80 */  lui       $at, 0x3f80
/* A8CD40 802402C0 44810000 */  mtc1      $at, $f0
/* A8CD44 802402C4 3C014000 */  lui       $at, 0x4000
/* A8CD48 802402C8 44811000 */  mtc1      $at, $f2
/* A8CD4C 802402CC 3C01C1A0 */  lui       $at, 0xc1a0
/* A8CD50 802402D0 44812000 */  mtc1      $at, $f4
/* A8CD54 802402D4 2402000F */  addiu     $v0, $zero, 0xf
/* A8CD58 802402D8 AFA2001C */  sw        $v0, 0x1c($sp)
/* A8CD5C 802402DC 44833000 */  mtc1      $v1, $f6
/* A8CD60 802402E0 00000000 */  nop       
/* A8CD64 802402E4 468031A0 */  cvt.s.w   $f6, $f6
/* A8CD68 802402E8 44073000 */  mfc1      $a3, $f6
/* A8CD6C 802402EC 27A20028 */  addiu     $v0, $sp, 0x28
/* A8CD70 802402F0 AFA20020 */  sw        $v0, 0x20($sp)
/* A8CD74 802402F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* A8CD78 802402F8 E7A20014 */  swc1      $f2, 0x14($sp)
/* A8CD7C 802402FC 0C01BFA4 */  jal       fx_emote
/* A8CD80 80240300 E7A40018 */   swc1     $f4, 0x18($sp)
/* A8CD84 80240304 0200202D */  daddu     $a0, $s0, $zero
/* A8CD88 80240308 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A8CD8C 8024030C 0C012530 */  jal       func_800494C0
/* A8CD90 80240310 3C060020 */   lui      $a2, 0x20
/* A8CD94 80240314 8E220018 */  lw        $v0, 0x18($s1)
/* A8CD98 80240318 9442002A */  lhu       $v0, 0x2a($v0)
/* A8CD9C 8024031C 30420001 */  andi      $v0, $v0, 1
/* A8CDA0 80240320 14400064 */  bnez      $v0, .L802404B4
/* A8CDA4 80240324 2402000A */   addiu    $v0, $zero, 0xa
/* A8CDA8 80240328 0809012D */  j         .L802404B4
/* A8CDAC 8024032C 2402000C */   addiu    $v0, $zero, 0xc
.L80240330:
/* A8CDB0 80240330 8E420074 */  lw        $v0, 0x74($s2)
/* A8CDB4 80240334 2442FFFF */  addiu     $v0, $v0, -1
.L80240338:
/* A8CDB8 80240338 AE420074 */  sw        $v0, 0x74($s2)
.L8024033C:
/* A8CDBC 8024033C 8602008C */  lh        $v0, 0x8c($s0)
/* A8CDC0 80240340 1440005D */  bnez      $v0, .L802404B8
/* A8CDC4 80240344 00000000 */   nop      
/* A8CDC8 80240348 C6000018 */  lwc1      $f0, 0x18($s0)
/* A8CDCC 8024034C 3C014010 */  lui       $at, 0x4010
/* A8CDD0 80240350 44811800 */  mtc1      $at, $f3
/* A8CDD4 80240354 44801000 */  mtc1      $zero, $f2
/* A8CDD8 80240358 46000021 */  cvt.d.s   $f0, $f0
/* A8CDDC 8024035C 4622003C */  c.lt.d    $f0, $f2
/* A8CDE0 80240360 00000000 */  nop       
/* A8CDE4 80240364 45000003 */  bc1f      .L80240374
/* A8CDE8 80240368 0200202D */   daddu    $a0, $s0, $zero
/* A8CDEC 8024036C 080900DE */  j         .L80240378
/* A8CDF0 80240370 0000282D */   daddu    $a1, $zero, $zero
.L80240374:
/* A8CDF4 80240374 24050001 */  addiu     $a1, $zero, 1
.L80240378:
/* A8CDF8 80240378 0C00F598 */  jal       func_8003D660
/* A8CDFC 8024037C 00000000 */   nop      
/* A8CE00 80240380 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A8CE04 80240384 8E430078 */  lw        $v1, 0x78($s2)
/* A8CE08 80240388 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A8CE0C 8024038C 00031040 */  sll       $v0, $v1, 1
/* A8CE10 80240390 00431021 */  addu      $v0, $v0, $v1
/* A8CE14 80240394 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8CE18 80240398 00021080 */  sll       $v0, $v0, 2
/* A8CE1C 8024039C 00431021 */  addu      $v0, $v0, $v1
/* A8CE20 802403A0 C4560004 */  lwc1      $f22, 4($v0)
/* A8CE24 802403A4 4680B5A0 */  cvt.s.w   $f22, $f22
/* A8CE28 802403A8 C454000C */  lwc1      $f20, 0xc($v0)
/* A8CE2C 802403AC 4680A520 */  cvt.s.w   $f20, $f20
/* A8CE30 802403B0 4406B000 */  mfc1      $a2, $f22
/* A8CE34 802403B4 4407A000 */  mfc1      $a3, $f20
/* A8CE38 802403B8 0C00A720 */  jal       atan2
/* A8CE3C 802403BC 00000000 */   nop      
/* A8CE40 802403C0 8E050018 */  lw        $a1, 0x18($s0)
/* A8CE44 802403C4 44060000 */  mfc1      $a2, $f0
/* A8CE48 802403C8 0200202D */  daddu     $a0, $s0, $zero
/* A8CE4C 802403CC 0C00EA95 */  jal       npc_move_heading
/* A8CE50 802403D0 AE06000C */   sw       $a2, 0xc($s0)
/* A8CE54 802403D4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A8CE58 802403D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A8CE5C 802403DC 4406B000 */  mfc1      $a2, $f22
/* A8CE60 802403E0 4407A000 */  mfc1      $a3, $f20
/* A8CE64 802403E4 0C00A7B5 */  jal       dist2D
/* A8CE68 802403E8 00000000 */   nop      
/* A8CE6C 802403EC C6020018 */  lwc1      $f2, 0x18($s0)
/* A8CE70 802403F0 4602003E */  c.le.s    $f0, $f2
/* A8CE74 802403F4 00000000 */  nop       
/* A8CE78 802403F8 4500002F */  bc1f      .L802404B8
/* A8CE7C 802403FC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* A8CE80 80240400 24020002 */  addiu     $v0, $zero, 2
/* A8CE84 80240404 0C00A67F */  jal       rand_int
/* A8CE88 80240408 AE420070 */   sw       $v0, 0x70($s2)
/* A8CE8C 8024040C 3C035555 */  lui       $v1, 0x5555
/* A8CE90 80240410 34635556 */  ori       $v1, $v1, 0x5556
/* A8CE94 80240414 00430018 */  mult      $v0, $v1
/* A8CE98 80240418 000227C3 */  sra       $a0, $v0, 0x1f
/* A8CE9C 8024041C 00004010 */  mfhi      $t0
/* A8CEA0 80240420 01042023 */  subu      $a0, $t0, $a0
/* A8CEA4 80240424 00041840 */  sll       $v1, $a0, 1
/* A8CEA8 80240428 00641821 */  addu      $v1, $v1, $a0
/* A8CEAC 8024042C 00431023 */  subu      $v0, $v0, $v1
/* A8CEB0 80240430 24430002 */  addiu     $v1, $v0, 2
/* A8CEB4 80240434 AE430074 */  sw        $v1, 0x74($s2)
/* A8CEB8 80240438 8E62002C */  lw        $v0, 0x2c($s3)
/* A8CEBC 8024043C 18400009 */  blez      $v0, .L80240464
/* A8CEC0 80240440 24020004 */   addiu    $v0, $zero, 4
/* A8CEC4 80240444 8E620004 */  lw        $v0, 4($s3)
/* A8CEC8 80240448 18400006 */  blez      $v0, .L80240464
/* A8CECC 8024044C 24020004 */   addiu    $v0, $zero, 4
/* A8CED0 80240450 8E620008 */  lw        $v0, 8($s3)
/* A8CED4 80240454 18400003 */  blez      $v0, .L80240464
/* A8CED8 80240458 24020004 */   addiu    $v0, $zero, 4
/* A8CEDC 8024045C 14600002 */  bnez      $v1, .L80240468
/* A8CEE0 80240460 00000000 */   nop      
.L80240464:
/* A8CEE4 80240464 AE420070 */  sw        $v0, 0x70($s2)
.L80240468:
/* A8CEE8 80240468 0C00A67F */  jal       rand_int
/* A8CEEC 8024046C 24042710 */   addiu    $a0, $zero, 0x2710
/* A8CEF0 80240470 3C0351EB */  lui       $v1, 0x51eb
/* A8CEF4 80240474 3463851F */  ori       $v1, $v1, 0x851f
/* A8CEF8 80240478 00430018 */  mult      $v0, $v1
/* A8CEFC 8024047C 00021FC3 */  sra       $v1, $v0, 0x1f
/* A8CF00 80240480 00004010 */  mfhi      $t0
/* A8CF04 80240484 00082143 */  sra       $a0, $t0, 5
/* A8CF08 80240488 00832023 */  subu      $a0, $a0, $v1
/* A8CF0C 8024048C 00041840 */  sll       $v1, $a0, 1
/* A8CF10 80240490 00641821 */  addu      $v1, $v1, $a0
/* A8CF14 80240494 000318C0 */  sll       $v1, $v1, 3
/* A8CF18 80240498 00641821 */  addu      $v1, $v1, $a0
/* A8CF1C 8024049C 00031880 */  sll       $v1, $v1, 2
/* A8CF20 802404A0 8E640004 */  lw        $a0, 4($s3)
/* A8CF24 802404A4 00431023 */  subu      $v0, $v0, $v1
/* A8CF28 802404A8 0044102A */  slt       $v0, $v0, $a0
/* A8CF2C 802404AC 10400002 */  beqz      $v0, .L802404B8
/* A8CF30 802404B0 24020004 */   addiu    $v0, $zero, 4
.L802404B4:
/* A8CF34 802404B4 AE420070 */  sw        $v0, 0x70($s2)
.L802404B8:
/* A8CF38 802404B8 8FBF0044 */  lw        $ra, 0x44($sp)
/* A8CF3C 802404BC 8FB40040 */  lw        $s4, 0x40($sp)
/* A8CF40 802404C0 8FB3003C */  lw        $s3, 0x3c($sp)
/* A8CF44 802404C4 8FB20038 */  lw        $s2, 0x38($sp)
/* A8CF48 802404C8 8FB10034 */  lw        $s1, 0x34($sp)
/* A8CF4C 802404CC 8FB00030 */  lw        $s0, 0x30($sp)
/* A8CF50 802404D0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* A8CF54 802404D4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A8CF58 802404D8 03E00008 */  jr        $ra
/* A8CF5C 802404DC 27BD0058 */   addiu    $sp, $sp, 0x58
