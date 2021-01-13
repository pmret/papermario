.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240208_ABB498
/* ABB498 80240208 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* ABB49C 8024020C AFB20038 */  sw        $s2, 0x38($sp)
/* ABB4A0 80240210 0080902D */  daddu     $s2, $a0, $zero
/* ABB4A4 80240214 AFBF0044 */  sw        $ra, 0x44($sp)
/* ABB4A8 80240218 AFB40040 */  sw        $s4, 0x40($sp)
/* ABB4AC 8024021C AFB3003C */  sw        $s3, 0x3c($sp)
/* ABB4B0 80240220 AFB10034 */  sw        $s1, 0x34($sp)
/* ABB4B4 80240224 AFB00030 */  sw        $s0, 0x30($sp)
/* ABB4B8 80240228 F7B60050 */  sdc1      $f22, 0x50($sp)
/* ABB4BC 8024022C F7B40048 */  sdc1      $f20, 0x48($sp)
/* ABB4C0 80240230 8E510148 */  lw        $s1, 0x148($s2)
/* ABB4C4 80240234 00A0982D */  daddu     $s3, $a1, $zero
/* ABB4C8 80240238 86240008 */  lh        $a0, 8($s1)
/* ABB4CC 8024023C 0C00EABB */  jal       get_npc_unsafe
/* ABB4D0 80240240 00C0A02D */   daddu    $s4, $a2, $zero
/* ABB4D4 80240244 8E630014 */  lw        $v1, 0x14($s3)
/* ABB4D8 80240248 04600030 */  bltz      $v1, .L8024030C
/* ABB4DC 8024024C 0040802D */   daddu    $s0, $v0, $zero
/* ABB4E0 80240250 8E420074 */  lw        $v0, 0x74($s2)
/* ABB4E4 80240254 1C40002C */  bgtz      $v0, .L80240308
/* ABB4E8 80240258 2442FFFF */   addiu    $v0, $v0, -1
/* ABB4EC 8024025C 0280202D */  daddu     $a0, $s4, $zero
/* ABB4F0 80240260 AE430074 */  sw        $v1, 0x74($s2)
/* ABB4F4 80240264 AFA00010 */  sw        $zero, 0x10($sp)
/* ABB4F8 80240268 8E66000C */  lw        $a2, 0xc($s3)
/* ABB4FC 8024026C 8E670010 */  lw        $a3, 0x10($s3)
/* ABB500 80240270 0C01242D */  jal       func_800490B4
/* ABB504 80240274 0220282D */   daddu    $a1, $s1, $zero
/* ABB508 80240278 10400021 */  beqz      $v0, .L80240300
/* ABB50C 8024027C 0000202D */   daddu    $a0, $zero, $zero
/* ABB510 80240280 0200282D */  daddu     $a1, $s0, $zero
/* ABB514 80240284 0000302D */  daddu     $a2, $zero, $zero
/* ABB518 80240288 860300A8 */  lh        $v1, 0xa8($s0)
/* ABB51C 8024028C 3C013F80 */  lui       $at, 0x3f80
/* ABB520 80240290 44810000 */  mtc1      $at, $f0
/* ABB524 80240294 3C014000 */  lui       $at, 0x4000
/* ABB528 80240298 44811000 */  mtc1      $at, $f2
/* ABB52C 8024029C 3C01C1A0 */  lui       $at, 0xc1a0
/* ABB530 802402A0 44812000 */  mtc1      $at, $f4
/* ABB534 802402A4 2402000F */  addiu     $v0, $zero, 0xf
/* ABB538 802402A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* ABB53C 802402AC 44833000 */  mtc1      $v1, $f6
/* ABB540 802402B0 00000000 */  nop
/* ABB544 802402B4 468031A0 */  cvt.s.w   $f6, $f6
/* ABB548 802402B8 44073000 */  mfc1      $a3, $f6
/* ABB54C 802402BC 27A20028 */  addiu     $v0, $sp, 0x28
/* ABB550 802402C0 AFA20020 */  sw        $v0, 0x20($sp)
/* ABB554 802402C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* ABB558 802402C8 E7A20014 */  swc1      $f2, 0x14($sp)
/* ABB55C 802402CC 0C01BFA4 */  jal       fx_emote
/* ABB560 802402D0 E7A40018 */   swc1     $f4, 0x18($sp)
/* ABB564 802402D4 0200202D */  daddu     $a0, $s0, $zero
/* ABB568 802402D8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* ABB56C 802402DC 0C012530 */  jal       func_800494C0
/* ABB570 802402E0 3C060020 */   lui      $a2, 0x20
/* ABB574 802402E4 8E220018 */  lw        $v0, 0x18($s1)
/* ABB578 802402E8 9442002A */  lhu       $v0, 0x2a($v0)
/* ABB57C 802402EC 30420001 */  andi      $v0, $v0, 1
/* ABB580 802402F0 14400064 */  bnez      $v0, .L80240484
/* ABB584 802402F4 2402000A */   addiu    $v0, $zero, 0xa
/* ABB588 802402F8 08090121 */  j         .L80240484
/* ABB58C 802402FC 2402000C */   addiu    $v0, $zero, 0xc
.L80240300:
/* ABB590 80240300 8E420074 */  lw        $v0, 0x74($s2)
/* ABB594 80240304 2442FFFF */  addiu     $v0, $v0, -1
.L80240308:
/* ABB598 80240308 AE420074 */  sw        $v0, 0x74($s2)
.L8024030C:
/* ABB59C 8024030C 8602008C */  lh        $v0, 0x8c($s0)
/* ABB5A0 80240310 1440005D */  bnez      $v0, .L80240488
/* ABB5A4 80240314 00000000 */   nop
/* ABB5A8 80240318 C6000018 */  lwc1      $f0, 0x18($s0)
/* ABB5AC 8024031C 3C014010 */  lui       $at, 0x4010
/* ABB5B0 80240320 44811800 */  mtc1      $at, $f3
/* ABB5B4 80240324 44801000 */  mtc1      $zero, $f2
/* ABB5B8 80240328 46000021 */  cvt.d.s   $f0, $f0
/* ABB5BC 8024032C 4622003C */  c.lt.d    $f0, $f2
/* ABB5C0 80240330 00000000 */  nop
/* ABB5C4 80240334 45000003 */  bc1f      .L80240344
/* ABB5C8 80240338 0200202D */   daddu    $a0, $s0, $zero
/* ABB5CC 8024033C 080900D2 */  j         .L80240348
/* ABB5D0 80240340 0000282D */   daddu    $a1, $zero, $zero
.L80240344:
/* ABB5D4 80240344 24050001 */  addiu     $a1, $zero, 1
.L80240348:
/* ABB5D8 80240348 0C00F598 */  jal       func_8003D660
/* ABB5DC 8024034C 00000000 */   nop
/* ABB5E0 80240350 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ABB5E4 80240354 8E430078 */  lw        $v1, 0x78($s2)
/* ABB5E8 80240358 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ABB5EC 8024035C 00031040 */  sll       $v0, $v1, 1
/* ABB5F0 80240360 00431021 */  addu      $v0, $v0, $v1
/* ABB5F4 80240364 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ABB5F8 80240368 00021080 */  sll       $v0, $v0, 2
/* ABB5FC 8024036C 00431021 */  addu      $v0, $v0, $v1
/* ABB600 80240370 C4560004 */  lwc1      $f22, 4($v0)
/* ABB604 80240374 4680B5A0 */  cvt.s.w   $f22, $f22
/* ABB608 80240378 C454000C */  lwc1      $f20, 0xc($v0)
/* ABB60C 8024037C 4680A520 */  cvt.s.w   $f20, $f20
/* ABB610 80240380 4406B000 */  mfc1      $a2, $f22
/* ABB614 80240384 4407A000 */  mfc1      $a3, $f20
/* ABB618 80240388 0C00A720 */  jal       atan2
/* ABB61C 8024038C 00000000 */   nop
/* ABB620 80240390 8E050018 */  lw        $a1, 0x18($s0)
/* ABB624 80240394 44060000 */  mfc1      $a2, $f0
/* ABB628 80240398 0200202D */  daddu     $a0, $s0, $zero
/* ABB62C 8024039C 0C00EA95 */  jal       npc_move_heading
/* ABB630 802403A0 AE06000C */   sw       $a2, 0xc($s0)
/* ABB634 802403A4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ABB638 802403A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ABB63C 802403AC 4406B000 */  mfc1      $a2, $f22
/* ABB640 802403B0 4407A000 */  mfc1      $a3, $f20
/* ABB644 802403B4 0C00A7B5 */  jal       dist2D
/* ABB648 802403B8 00000000 */   nop
/* ABB64C 802403BC C6020018 */  lwc1      $f2, 0x18($s0)
/* ABB650 802403C0 4602003E */  c.le.s    $f0, $f2
/* ABB654 802403C4 00000000 */  nop
/* ABB658 802403C8 4500002F */  bc1f      .L80240488
/* ABB65C 802403CC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* ABB660 802403D0 24020002 */  addiu     $v0, $zero, 2
/* ABB664 802403D4 0C00A67F */  jal       rand_int
/* ABB668 802403D8 AE420070 */   sw       $v0, 0x70($s2)
/* ABB66C 802403DC 3C035555 */  lui       $v1, 0x5555
/* ABB670 802403E0 34635556 */  ori       $v1, $v1, 0x5556
/* ABB674 802403E4 00430018 */  mult      $v0, $v1
/* ABB678 802403E8 000227C3 */  sra       $a0, $v0, 0x1f
/* ABB67C 802403EC 00004010 */  mfhi      $t0
/* ABB680 802403F0 01042023 */  subu      $a0, $t0, $a0
/* ABB684 802403F4 00041840 */  sll       $v1, $a0, 1
/* ABB688 802403F8 00641821 */  addu      $v1, $v1, $a0
/* ABB68C 802403FC 00431023 */  subu      $v0, $v0, $v1
/* ABB690 80240400 24430002 */  addiu     $v1, $v0, 2
/* ABB694 80240404 AE430074 */  sw        $v1, 0x74($s2)
/* ABB698 80240408 8E62002C */  lw        $v0, 0x2c($s3)
/* ABB69C 8024040C 18400009 */  blez      $v0, .L80240434
/* ABB6A0 80240410 24020004 */   addiu    $v0, $zero, 4
/* ABB6A4 80240414 8E620004 */  lw        $v0, 4($s3)
/* ABB6A8 80240418 18400006 */  blez      $v0, .L80240434
/* ABB6AC 8024041C 24020004 */   addiu    $v0, $zero, 4
/* ABB6B0 80240420 8E620008 */  lw        $v0, 8($s3)
/* ABB6B4 80240424 18400003 */  blez      $v0, .L80240434
/* ABB6B8 80240428 24020004 */   addiu    $v0, $zero, 4
/* ABB6BC 8024042C 14600002 */  bnez      $v1, .L80240438
/* ABB6C0 80240430 00000000 */   nop
.L80240434:
/* ABB6C4 80240434 AE420070 */  sw        $v0, 0x70($s2)
.L80240438:
/* ABB6C8 80240438 0C00A67F */  jal       rand_int
/* ABB6CC 8024043C 24042710 */   addiu    $a0, $zero, 0x2710
/* ABB6D0 80240440 3C0351EB */  lui       $v1, 0x51eb
/* ABB6D4 80240444 3463851F */  ori       $v1, $v1, 0x851f
/* ABB6D8 80240448 00430018 */  mult      $v0, $v1
/* ABB6DC 8024044C 00021FC3 */  sra       $v1, $v0, 0x1f
/* ABB6E0 80240450 00004010 */  mfhi      $t0
/* ABB6E4 80240454 00082143 */  sra       $a0, $t0, 5
/* ABB6E8 80240458 00832023 */  subu      $a0, $a0, $v1
/* ABB6EC 8024045C 00041840 */  sll       $v1, $a0, 1
/* ABB6F0 80240460 00641821 */  addu      $v1, $v1, $a0
/* ABB6F4 80240464 000318C0 */  sll       $v1, $v1, 3
/* ABB6F8 80240468 00641821 */  addu      $v1, $v1, $a0
/* ABB6FC 8024046C 00031880 */  sll       $v1, $v1, 2
/* ABB700 80240470 8E640004 */  lw        $a0, 4($s3)
/* ABB704 80240474 00431023 */  subu      $v0, $v0, $v1
/* ABB708 80240478 0044102A */  slt       $v0, $v0, $a0
/* ABB70C 8024047C 10400002 */  beqz      $v0, .L80240488
/* ABB710 80240480 24020004 */   addiu    $v0, $zero, 4
.L80240484:
/* ABB714 80240484 AE420070 */  sw        $v0, 0x70($s2)
.L80240488:
/* ABB718 80240488 8FBF0044 */  lw        $ra, 0x44($sp)
/* ABB71C 8024048C 8FB40040 */  lw        $s4, 0x40($sp)
/* ABB720 80240490 8FB3003C */  lw        $s3, 0x3c($sp)
/* ABB724 80240494 8FB20038 */  lw        $s2, 0x38($sp)
/* ABB728 80240498 8FB10034 */  lw        $s1, 0x34($sp)
/* ABB72C 8024049C 8FB00030 */  lw        $s0, 0x30($sp)
/* ABB730 802404A0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* ABB734 802404A4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* ABB738 802404A8 03E00008 */  jr        $ra
/* ABB73C 802404AC 27BD0058 */   addiu    $sp, $sp, 0x58
