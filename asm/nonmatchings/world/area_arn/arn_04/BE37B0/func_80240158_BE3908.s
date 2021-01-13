.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_BE3908
/* BE3908 80240158 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BE390C 8024015C AFB20038 */  sw        $s2, 0x38($sp)
/* BE3910 80240160 0080902D */  daddu     $s2, $a0, $zero
/* BE3914 80240164 AFBF0044 */  sw        $ra, 0x44($sp)
/* BE3918 80240168 AFB40040 */  sw        $s4, 0x40($sp)
/* BE391C 8024016C AFB3003C */  sw        $s3, 0x3c($sp)
/* BE3920 80240170 AFB10034 */  sw        $s1, 0x34($sp)
/* BE3924 80240174 AFB00030 */  sw        $s0, 0x30($sp)
/* BE3928 80240178 F7B60050 */  sdc1      $f22, 0x50($sp)
/* BE392C 8024017C F7B40048 */  sdc1      $f20, 0x48($sp)
/* BE3930 80240180 8E510148 */  lw        $s1, 0x148($s2)
/* BE3934 80240184 00A0982D */  daddu     $s3, $a1, $zero
/* BE3938 80240188 86240008 */  lh        $a0, 8($s1)
/* BE393C 8024018C 0C00EABB */  jal       get_npc_unsafe
/* BE3940 80240190 00C0A02D */   daddu    $s4, $a2, $zero
/* BE3944 80240194 8E630014 */  lw        $v1, 0x14($s3)
/* BE3948 80240198 04600030 */  bltz      $v1, .L8024025C
/* BE394C 8024019C 0040802D */   daddu    $s0, $v0, $zero
/* BE3950 802401A0 8E420074 */  lw        $v0, 0x74($s2)
/* BE3954 802401A4 1C40002C */  bgtz      $v0, .L80240258
/* BE3958 802401A8 2442FFFF */   addiu    $v0, $v0, -1
/* BE395C 802401AC 0280202D */  daddu     $a0, $s4, $zero
/* BE3960 802401B0 AE430074 */  sw        $v1, 0x74($s2)
/* BE3964 802401B4 AFA00010 */  sw        $zero, 0x10($sp)
/* BE3968 802401B8 8E66000C */  lw        $a2, 0xc($s3)
/* BE396C 802401BC 8E670010 */  lw        $a3, 0x10($s3)
/* BE3970 802401C0 0C01242D */  jal       func_800490B4
/* BE3974 802401C4 0220282D */   daddu    $a1, $s1, $zero
/* BE3978 802401C8 10400021 */  beqz      $v0, .L80240250
/* BE397C 802401CC 0000202D */   daddu    $a0, $zero, $zero
/* BE3980 802401D0 0200282D */  daddu     $a1, $s0, $zero
/* BE3984 802401D4 0000302D */  daddu     $a2, $zero, $zero
/* BE3988 802401D8 860300A8 */  lh        $v1, 0xa8($s0)
/* BE398C 802401DC 3C013F80 */  lui       $at, 0x3f80
/* BE3990 802401E0 44810000 */  mtc1      $at, $f0
/* BE3994 802401E4 3C014000 */  lui       $at, 0x4000
/* BE3998 802401E8 44811000 */  mtc1      $at, $f2
/* BE399C 802401EC 3C01C1A0 */  lui       $at, 0xc1a0
/* BE39A0 802401F0 44812000 */  mtc1      $at, $f4
/* BE39A4 802401F4 2402000F */  addiu     $v0, $zero, 0xf
/* BE39A8 802401F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE39AC 802401FC 44833000 */  mtc1      $v1, $f6
/* BE39B0 80240200 00000000 */  nop
/* BE39B4 80240204 468031A0 */  cvt.s.w   $f6, $f6
/* BE39B8 80240208 44073000 */  mfc1      $a3, $f6
/* BE39BC 8024020C 27A20028 */  addiu     $v0, $sp, 0x28
/* BE39C0 80240210 AFA20020 */  sw        $v0, 0x20($sp)
/* BE39C4 80240214 E7A00010 */  swc1      $f0, 0x10($sp)
/* BE39C8 80240218 E7A20014 */  swc1      $f2, 0x14($sp)
/* BE39CC 8024021C 0C01BFA4 */  jal       fx_emote
/* BE39D0 80240220 E7A40018 */   swc1     $f4, 0x18($sp)
/* BE39D4 80240224 0200202D */  daddu     $a0, $s0, $zero
/* BE39D8 80240228 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BE39DC 8024022C 0C012530 */  jal       func_800494C0
/* BE39E0 80240230 3C060020 */   lui      $a2, 0x20
/* BE39E4 80240234 8E220018 */  lw        $v0, 0x18($s1)
/* BE39E8 80240238 9442002A */  lhu       $v0, 0x2a($v0)
/* BE39EC 8024023C 30420001 */  andi      $v0, $v0, 1
/* BE39F0 80240240 14400064 */  bnez      $v0, .L802403D4
/* BE39F4 80240244 2402000A */   addiu    $v0, $zero, 0xa
/* BE39F8 80240248 080900F5 */  j         .L802403D4
/* BE39FC 8024024C 2402000C */   addiu    $v0, $zero, 0xc
.L80240250:
/* BE3A00 80240250 8E420074 */  lw        $v0, 0x74($s2)
/* BE3A04 80240254 2442FFFF */  addiu     $v0, $v0, -1
.L80240258:
/* BE3A08 80240258 AE420074 */  sw        $v0, 0x74($s2)
.L8024025C:
/* BE3A0C 8024025C 8602008C */  lh        $v0, 0x8c($s0)
/* BE3A10 80240260 1440005D */  bnez      $v0, .L802403D8
/* BE3A14 80240264 00000000 */   nop
/* BE3A18 80240268 C6000018 */  lwc1      $f0, 0x18($s0)
/* BE3A1C 8024026C 3C014010 */  lui       $at, 0x4010
/* BE3A20 80240270 44811800 */  mtc1      $at, $f3
/* BE3A24 80240274 44801000 */  mtc1      $zero, $f2
/* BE3A28 80240278 46000021 */  cvt.d.s   $f0, $f0
/* BE3A2C 8024027C 4622003C */  c.lt.d    $f0, $f2
/* BE3A30 80240280 00000000 */  nop
/* BE3A34 80240284 45000003 */  bc1f      .L80240294
/* BE3A38 80240288 0200202D */   daddu    $a0, $s0, $zero
/* BE3A3C 8024028C 080900A6 */  j         .L80240298
/* BE3A40 80240290 0000282D */   daddu    $a1, $zero, $zero
.L80240294:
/* BE3A44 80240294 24050001 */  addiu     $a1, $zero, 1
.L80240298:
/* BE3A48 80240298 0C00F598 */  jal       func_8003D660
/* BE3A4C 8024029C 00000000 */   nop
/* BE3A50 802402A0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE3A54 802402A4 8E430078 */  lw        $v1, 0x78($s2)
/* BE3A58 802402A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE3A5C 802402AC 00031040 */  sll       $v0, $v1, 1
/* BE3A60 802402B0 00431021 */  addu      $v0, $v0, $v1
/* BE3A64 802402B4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE3A68 802402B8 00021080 */  sll       $v0, $v0, 2
/* BE3A6C 802402BC 00431021 */  addu      $v0, $v0, $v1
/* BE3A70 802402C0 C4560004 */  lwc1      $f22, 4($v0)
/* BE3A74 802402C4 4680B5A0 */  cvt.s.w   $f22, $f22
/* BE3A78 802402C8 C454000C */  lwc1      $f20, 0xc($v0)
/* BE3A7C 802402CC 4680A520 */  cvt.s.w   $f20, $f20
/* BE3A80 802402D0 4406B000 */  mfc1      $a2, $f22
/* BE3A84 802402D4 4407A000 */  mfc1      $a3, $f20
/* BE3A88 802402D8 0C00A720 */  jal       atan2
/* BE3A8C 802402DC 00000000 */   nop
/* BE3A90 802402E0 8E050018 */  lw        $a1, 0x18($s0)
/* BE3A94 802402E4 44060000 */  mfc1      $a2, $f0
/* BE3A98 802402E8 0200202D */  daddu     $a0, $s0, $zero
/* BE3A9C 802402EC 0C00EA95 */  jal       npc_move_heading
/* BE3AA0 802402F0 AE06000C */   sw       $a2, 0xc($s0)
/* BE3AA4 802402F4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE3AA8 802402F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE3AAC 802402FC 4406B000 */  mfc1      $a2, $f22
/* BE3AB0 80240300 4407A000 */  mfc1      $a3, $f20
/* BE3AB4 80240304 0C00A7B5 */  jal       dist2D
/* BE3AB8 80240308 00000000 */   nop
/* BE3ABC 8024030C C6020018 */  lwc1      $f2, 0x18($s0)
/* BE3AC0 80240310 4602003E */  c.le.s    $f0, $f2
/* BE3AC4 80240314 00000000 */  nop
/* BE3AC8 80240318 4500002F */  bc1f      .L802403D8
/* BE3ACC 8024031C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BE3AD0 80240320 24020002 */  addiu     $v0, $zero, 2
/* BE3AD4 80240324 0C00A67F */  jal       rand_int
/* BE3AD8 80240328 AE420070 */   sw       $v0, 0x70($s2)
/* BE3ADC 8024032C 3C035555 */  lui       $v1, 0x5555
/* BE3AE0 80240330 34635556 */  ori       $v1, $v1, 0x5556
/* BE3AE4 80240334 00430018 */  mult      $v0, $v1
/* BE3AE8 80240338 000227C3 */  sra       $a0, $v0, 0x1f
/* BE3AEC 8024033C 00004010 */  mfhi      $t0
/* BE3AF0 80240340 01042023 */  subu      $a0, $t0, $a0
/* BE3AF4 80240344 00041840 */  sll       $v1, $a0, 1
/* BE3AF8 80240348 00641821 */  addu      $v1, $v1, $a0
/* BE3AFC 8024034C 00431023 */  subu      $v0, $v0, $v1
/* BE3B00 80240350 24430002 */  addiu     $v1, $v0, 2
/* BE3B04 80240354 AE430074 */  sw        $v1, 0x74($s2)
/* BE3B08 80240358 8E62002C */  lw        $v0, 0x2c($s3)
/* BE3B0C 8024035C 18400009 */  blez      $v0, .L80240384
/* BE3B10 80240360 24020004 */   addiu    $v0, $zero, 4
/* BE3B14 80240364 8E620004 */  lw        $v0, 4($s3)
/* BE3B18 80240368 18400006 */  blez      $v0, .L80240384
/* BE3B1C 8024036C 24020004 */   addiu    $v0, $zero, 4
/* BE3B20 80240370 8E620008 */  lw        $v0, 8($s3)
/* BE3B24 80240374 18400003 */  blez      $v0, .L80240384
/* BE3B28 80240378 24020004 */   addiu    $v0, $zero, 4
/* BE3B2C 8024037C 14600002 */  bnez      $v1, .L80240388
/* BE3B30 80240380 00000000 */   nop
.L80240384:
/* BE3B34 80240384 AE420070 */  sw        $v0, 0x70($s2)
.L80240388:
/* BE3B38 80240388 0C00A67F */  jal       rand_int
/* BE3B3C 8024038C 24042710 */   addiu    $a0, $zero, 0x2710
/* BE3B40 80240390 3C0351EB */  lui       $v1, 0x51eb
/* BE3B44 80240394 3463851F */  ori       $v1, $v1, 0x851f
/* BE3B48 80240398 00430018 */  mult      $v0, $v1
/* BE3B4C 8024039C 00021FC3 */  sra       $v1, $v0, 0x1f
/* BE3B50 802403A0 00004010 */  mfhi      $t0
/* BE3B54 802403A4 00082143 */  sra       $a0, $t0, 5
/* BE3B58 802403A8 00832023 */  subu      $a0, $a0, $v1
/* BE3B5C 802403AC 00041840 */  sll       $v1, $a0, 1
/* BE3B60 802403B0 00641821 */  addu      $v1, $v1, $a0
/* BE3B64 802403B4 000318C0 */  sll       $v1, $v1, 3
/* BE3B68 802403B8 00641821 */  addu      $v1, $v1, $a0
/* BE3B6C 802403BC 00031880 */  sll       $v1, $v1, 2
/* BE3B70 802403C0 8E640004 */  lw        $a0, 4($s3)
/* BE3B74 802403C4 00431023 */  subu      $v0, $v0, $v1
/* BE3B78 802403C8 0044102A */  slt       $v0, $v0, $a0
/* BE3B7C 802403CC 10400002 */  beqz      $v0, .L802403D8
/* BE3B80 802403D0 24020004 */   addiu    $v0, $zero, 4
.L802403D4:
/* BE3B84 802403D4 AE420070 */  sw        $v0, 0x70($s2)
.L802403D8:
/* BE3B88 802403D8 8FBF0044 */  lw        $ra, 0x44($sp)
/* BE3B8C 802403DC 8FB40040 */  lw        $s4, 0x40($sp)
/* BE3B90 802403E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE3B94 802403E4 8FB20038 */  lw        $s2, 0x38($sp)
/* BE3B98 802403E8 8FB10034 */  lw        $s1, 0x34($sp)
/* BE3B9C 802403EC 8FB00030 */  lw        $s0, 0x30($sp)
/* BE3BA0 802403F0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* BE3BA4 802403F4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* BE3BA8 802403F8 03E00008 */  jr        $ra
/* BE3BAC 802403FC 27BD0058 */   addiu    $sp, $sp, 0x58
