.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_BDEEE8
/* BDEEE8 80240158 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BDEEEC 8024015C AFB20038 */  sw        $s2, 0x38($sp)
/* BDEEF0 80240160 0080902D */  daddu     $s2, $a0, $zero
/* BDEEF4 80240164 AFBF0044 */  sw        $ra, 0x44($sp)
/* BDEEF8 80240168 AFB40040 */  sw        $s4, 0x40($sp)
/* BDEEFC 8024016C AFB3003C */  sw        $s3, 0x3c($sp)
/* BDEF00 80240170 AFB10034 */  sw        $s1, 0x34($sp)
/* BDEF04 80240174 AFB00030 */  sw        $s0, 0x30($sp)
/* BDEF08 80240178 F7B60050 */  sdc1      $f22, 0x50($sp)
/* BDEF0C 8024017C F7B40048 */  sdc1      $f20, 0x48($sp)
/* BDEF10 80240180 8E510148 */  lw        $s1, 0x148($s2)
/* BDEF14 80240184 00A0982D */  daddu     $s3, $a1, $zero
/* BDEF18 80240188 86240008 */  lh        $a0, 8($s1)
/* BDEF1C 8024018C 0C00EABB */  jal       get_npc_unsafe
/* BDEF20 80240190 00C0A02D */   daddu    $s4, $a2, $zero
/* BDEF24 80240194 8E630014 */  lw        $v1, 0x14($s3)
/* BDEF28 80240198 04600030 */  bltz      $v1, .L8024025C
/* BDEF2C 8024019C 0040802D */   daddu    $s0, $v0, $zero
/* BDEF30 802401A0 8E420074 */  lw        $v0, 0x74($s2)
/* BDEF34 802401A4 1C40002C */  bgtz      $v0, .L80240258
/* BDEF38 802401A8 2442FFFF */   addiu    $v0, $v0, -1
/* BDEF3C 802401AC 0280202D */  daddu     $a0, $s4, $zero
/* BDEF40 802401B0 AE430074 */  sw        $v1, 0x74($s2)
/* BDEF44 802401B4 AFA00010 */  sw        $zero, 0x10($sp)
/* BDEF48 802401B8 8E66000C */  lw        $a2, 0xc($s3)
/* BDEF4C 802401BC 8E670010 */  lw        $a3, 0x10($s3)
/* BDEF50 802401C0 0C01242D */  jal       func_800490B4
/* BDEF54 802401C4 0220282D */   daddu    $a1, $s1, $zero
/* BDEF58 802401C8 10400021 */  beqz      $v0, .L80240250
/* BDEF5C 802401CC 0000202D */   daddu    $a0, $zero, $zero
/* BDEF60 802401D0 0200282D */  daddu     $a1, $s0, $zero
/* BDEF64 802401D4 0000302D */  daddu     $a2, $zero, $zero
/* BDEF68 802401D8 860300A8 */  lh        $v1, 0xa8($s0)
/* BDEF6C 802401DC 3C013F80 */  lui       $at, 0x3f80
/* BDEF70 802401E0 44810000 */  mtc1      $at, $f0
/* BDEF74 802401E4 3C014000 */  lui       $at, 0x4000
/* BDEF78 802401E8 44811000 */  mtc1      $at, $f2
/* BDEF7C 802401EC 3C01C1A0 */  lui       $at, 0xc1a0
/* BDEF80 802401F0 44812000 */  mtc1      $at, $f4
/* BDEF84 802401F4 2402000F */  addiu     $v0, $zero, 0xf
/* BDEF88 802401F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* BDEF8C 802401FC 44833000 */  mtc1      $v1, $f6
/* BDEF90 80240200 00000000 */  nop       
/* BDEF94 80240204 468031A0 */  cvt.s.w   $f6, $f6
/* BDEF98 80240208 44073000 */  mfc1      $a3, $f6
/* BDEF9C 8024020C 27A20028 */  addiu     $v0, $sp, 0x28
/* BDEFA0 80240210 AFA20020 */  sw        $v0, 0x20($sp)
/* BDEFA4 80240214 E7A00010 */  swc1      $f0, 0x10($sp)
/* BDEFA8 80240218 E7A20014 */  swc1      $f2, 0x14($sp)
/* BDEFAC 8024021C 0C01BFA4 */  jal       fx_emote
/* BDEFB0 80240220 E7A40018 */   swc1     $f4, 0x18($sp)
/* BDEFB4 80240224 0200202D */  daddu     $a0, $s0, $zero
/* BDEFB8 80240228 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BDEFBC 8024022C 0C012530 */  jal       func_800494C0
/* BDEFC0 80240230 3C060020 */   lui      $a2, 0x20
/* BDEFC4 80240234 8E220018 */  lw        $v0, 0x18($s1)
/* BDEFC8 80240238 9442002A */  lhu       $v0, 0x2a($v0)
/* BDEFCC 8024023C 30420001 */  andi      $v0, $v0, 1
/* BDEFD0 80240240 14400064 */  bnez      $v0, .L802403D4
/* BDEFD4 80240244 2402000A */   addiu    $v0, $zero, 0xa
/* BDEFD8 80240248 080900F5 */  j         .L802403D4
/* BDEFDC 8024024C 2402000C */   addiu    $v0, $zero, 0xc
.L80240250:
/* BDEFE0 80240250 8E420074 */  lw        $v0, 0x74($s2)
/* BDEFE4 80240254 2442FFFF */  addiu     $v0, $v0, -1
.L80240258:
/* BDEFE8 80240258 AE420074 */  sw        $v0, 0x74($s2)
.L8024025C:
/* BDEFEC 8024025C 8602008C */  lh        $v0, 0x8c($s0)
/* BDEFF0 80240260 1440005D */  bnez      $v0, .L802403D8
/* BDEFF4 80240264 00000000 */   nop      
/* BDEFF8 80240268 C6000018 */  lwc1      $f0, 0x18($s0)
/* BDEFFC 8024026C 3C014010 */  lui       $at, 0x4010
/* BDF000 80240270 44811800 */  mtc1      $at, $f3
/* BDF004 80240274 44801000 */  mtc1      $zero, $f2
/* BDF008 80240278 46000021 */  cvt.d.s   $f0, $f0
/* BDF00C 8024027C 4622003C */  c.lt.d    $f0, $f2
/* BDF010 80240280 00000000 */  nop       
/* BDF014 80240284 45000003 */  bc1f      .L80240294
/* BDF018 80240288 0200202D */   daddu    $a0, $s0, $zero
/* BDF01C 8024028C 080900A6 */  j         .L80240298
/* BDF020 80240290 0000282D */   daddu    $a1, $zero, $zero
.L80240294:
/* BDF024 80240294 24050001 */  addiu     $a1, $zero, 1
.L80240298:
/* BDF028 80240298 0C00F598 */  jal       func_8003D660
/* BDF02C 8024029C 00000000 */   nop      
/* BDF030 802402A0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDF034 802402A4 8E430078 */  lw        $v1, 0x78($s2)
/* BDF038 802402A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDF03C 802402AC 00031040 */  sll       $v0, $v1, 1
/* BDF040 802402B0 00431021 */  addu      $v0, $v0, $v1
/* BDF044 802402B4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BDF048 802402B8 00021080 */  sll       $v0, $v0, 2
/* BDF04C 802402BC 00431021 */  addu      $v0, $v0, $v1
/* BDF050 802402C0 C4560004 */  lwc1      $f22, 4($v0)
/* BDF054 802402C4 4680B5A0 */  cvt.s.w   $f22, $f22
/* BDF058 802402C8 C454000C */  lwc1      $f20, 0xc($v0)
/* BDF05C 802402CC 4680A520 */  cvt.s.w   $f20, $f20
/* BDF060 802402D0 4406B000 */  mfc1      $a2, $f22
/* BDF064 802402D4 4407A000 */  mfc1      $a3, $f20
/* BDF068 802402D8 0C00A720 */  jal       atan2
/* BDF06C 802402DC 00000000 */   nop      
/* BDF070 802402E0 8E050018 */  lw        $a1, 0x18($s0)
/* BDF074 802402E4 44060000 */  mfc1      $a2, $f0
/* BDF078 802402E8 0200202D */  daddu     $a0, $s0, $zero
/* BDF07C 802402EC 0C00EA95 */  jal       npc_move_heading
/* BDF080 802402F0 AE06000C */   sw       $a2, 0xc($s0)
/* BDF084 802402F4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDF088 802402F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDF08C 802402FC 4406B000 */  mfc1      $a2, $f22
/* BDF090 80240300 4407A000 */  mfc1      $a3, $f20
/* BDF094 80240304 0C00A7B5 */  jal       dist2D
/* BDF098 80240308 00000000 */   nop      
/* BDF09C 8024030C C6020018 */  lwc1      $f2, 0x18($s0)
/* BDF0A0 80240310 4602003E */  c.le.s    $f0, $f2
/* BDF0A4 80240314 00000000 */  nop       
/* BDF0A8 80240318 4500002F */  bc1f      .L802403D8
/* BDF0AC 8024031C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BDF0B0 80240320 24020002 */  addiu     $v0, $zero, 2
/* BDF0B4 80240324 0C00A67F */  jal       rand_int
/* BDF0B8 80240328 AE420070 */   sw       $v0, 0x70($s2)
/* BDF0BC 8024032C 3C035555 */  lui       $v1, 0x5555
/* BDF0C0 80240330 34635556 */  ori       $v1, $v1, 0x5556
/* BDF0C4 80240334 00430018 */  mult      $v0, $v1
/* BDF0C8 80240338 000227C3 */  sra       $a0, $v0, 0x1f
/* BDF0CC 8024033C 00004010 */  mfhi      $t0
/* BDF0D0 80240340 01042023 */  subu      $a0, $t0, $a0
/* BDF0D4 80240344 00041840 */  sll       $v1, $a0, 1
/* BDF0D8 80240348 00641821 */  addu      $v1, $v1, $a0
/* BDF0DC 8024034C 00431023 */  subu      $v0, $v0, $v1
/* BDF0E0 80240350 24430002 */  addiu     $v1, $v0, 2
/* BDF0E4 80240354 AE430074 */  sw        $v1, 0x74($s2)
/* BDF0E8 80240358 8E62002C */  lw        $v0, 0x2c($s3)
/* BDF0EC 8024035C 18400009 */  blez      $v0, .L80240384
/* BDF0F0 80240360 24020004 */   addiu    $v0, $zero, 4
/* BDF0F4 80240364 8E620004 */  lw        $v0, 4($s3)
/* BDF0F8 80240368 18400006 */  blez      $v0, .L80240384
/* BDF0FC 8024036C 24020004 */   addiu    $v0, $zero, 4
/* BDF100 80240370 8E620008 */  lw        $v0, 8($s3)
/* BDF104 80240374 18400003 */  blez      $v0, .L80240384
/* BDF108 80240378 24020004 */   addiu    $v0, $zero, 4
/* BDF10C 8024037C 14600002 */  bnez      $v1, .L80240388
/* BDF110 80240380 00000000 */   nop      
.L80240384:
/* BDF114 80240384 AE420070 */  sw        $v0, 0x70($s2)
.L80240388:
/* BDF118 80240388 0C00A67F */  jal       rand_int
/* BDF11C 8024038C 24042710 */   addiu    $a0, $zero, 0x2710
/* BDF120 80240390 3C0351EB */  lui       $v1, 0x51eb
/* BDF124 80240394 3463851F */  ori       $v1, $v1, 0x851f
/* BDF128 80240398 00430018 */  mult      $v0, $v1
/* BDF12C 8024039C 00021FC3 */  sra       $v1, $v0, 0x1f
/* BDF130 802403A0 00004010 */  mfhi      $t0
/* BDF134 802403A4 00082143 */  sra       $a0, $t0, 5
/* BDF138 802403A8 00832023 */  subu      $a0, $a0, $v1
/* BDF13C 802403AC 00041840 */  sll       $v1, $a0, 1
/* BDF140 802403B0 00641821 */  addu      $v1, $v1, $a0
/* BDF144 802403B4 000318C0 */  sll       $v1, $v1, 3
/* BDF148 802403B8 00641821 */  addu      $v1, $v1, $a0
/* BDF14C 802403BC 00031880 */  sll       $v1, $v1, 2
/* BDF150 802403C0 8E640004 */  lw        $a0, 4($s3)
/* BDF154 802403C4 00431023 */  subu      $v0, $v0, $v1
/* BDF158 802403C8 0044102A */  slt       $v0, $v0, $a0
/* BDF15C 802403CC 10400002 */  beqz      $v0, .L802403D8
/* BDF160 802403D0 24020004 */   addiu    $v0, $zero, 4
.L802403D4:
/* BDF164 802403D4 AE420070 */  sw        $v0, 0x70($s2)
.L802403D8:
/* BDF168 802403D8 8FBF0044 */  lw        $ra, 0x44($sp)
/* BDF16C 802403DC 8FB40040 */  lw        $s4, 0x40($sp)
/* BDF170 802403E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDF174 802403E4 8FB20038 */  lw        $s2, 0x38($sp)
/* BDF178 802403E8 8FB10034 */  lw        $s1, 0x34($sp)
/* BDF17C 802403EC 8FB00030 */  lw        $s0, 0x30($sp)
/* BDF180 802403F0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* BDF184 802403F4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* BDF188 802403F8 03E00008 */  jr        $ra
/* BDF18C 802403FC 27BD0058 */   addiu    $sp, $sp, 0x58
