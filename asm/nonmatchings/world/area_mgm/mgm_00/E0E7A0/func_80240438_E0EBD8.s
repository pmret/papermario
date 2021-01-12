.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240438_E0EBD8
/* E0EBD8 80240438 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* E0EBDC 8024043C AFB20038 */  sw        $s2, 0x38($sp)
/* E0EBE0 80240440 0080902D */  daddu     $s2, $a0, $zero
/* E0EBE4 80240444 AFBF0044 */  sw        $ra, 0x44($sp)
/* E0EBE8 80240448 AFB40040 */  sw        $s4, 0x40($sp)
/* E0EBEC 8024044C AFB3003C */  sw        $s3, 0x3c($sp)
/* E0EBF0 80240450 AFB10034 */  sw        $s1, 0x34($sp)
/* E0EBF4 80240454 AFB00030 */  sw        $s0, 0x30($sp)
/* E0EBF8 80240458 F7B60050 */  sdc1      $f22, 0x50($sp)
/* E0EBFC 8024045C F7B40048 */  sdc1      $f20, 0x48($sp)
/* E0EC00 80240460 8E510148 */  lw        $s1, 0x148($s2)
/* E0EC04 80240464 00A0982D */  daddu     $s3, $a1, $zero
/* E0EC08 80240468 86240008 */  lh        $a0, 8($s1)
/* E0EC0C 8024046C 0C00EABB */  jal       get_npc_unsafe
/* E0EC10 80240470 00C0A02D */   daddu    $s4, $a2, $zero
/* E0EC14 80240474 8E630014 */  lw        $v1, 0x14($s3)
/* E0EC18 80240478 04600030 */  bltz      $v1, .L8024053C
/* E0EC1C 8024047C 0040802D */   daddu    $s0, $v0, $zero
/* E0EC20 80240480 8E420074 */  lw        $v0, 0x74($s2)
/* E0EC24 80240484 1C40002C */  bgtz      $v0, .L80240538
/* E0EC28 80240488 2442FFFF */   addiu    $v0, $v0, -1
/* E0EC2C 8024048C 0280202D */  daddu     $a0, $s4, $zero
/* E0EC30 80240490 AE430074 */  sw        $v1, 0x74($s2)
/* E0EC34 80240494 AFA00010 */  sw        $zero, 0x10($sp)
/* E0EC38 80240498 8E66000C */  lw        $a2, 0xc($s3)
/* E0EC3C 8024049C 8E670010 */  lw        $a3, 0x10($s3)
/* E0EC40 802404A0 0C01242D */  jal       func_800490B4
/* E0EC44 802404A4 0220282D */   daddu    $a1, $s1, $zero
/* E0EC48 802404A8 10400021 */  beqz      $v0, .L80240530
/* E0EC4C 802404AC 0000202D */   daddu    $a0, $zero, $zero
/* E0EC50 802404B0 0200282D */  daddu     $a1, $s0, $zero
/* E0EC54 802404B4 0000302D */  daddu     $a2, $zero, $zero
/* E0EC58 802404B8 860300A8 */  lh        $v1, 0xa8($s0)
/* E0EC5C 802404BC 3C013F80 */  lui       $at, 0x3f80
/* E0EC60 802404C0 44810000 */  mtc1      $at, $f0
/* E0EC64 802404C4 3C014000 */  lui       $at, 0x4000
/* E0EC68 802404C8 44811000 */  mtc1      $at, $f2
/* E0EC6C 802404CC 3C01C1A0 */  lui       $at, 0xc1a0
/* E0EC70 802404D0 44812000 */  mtc1      $at, $f4
/* E0EC74 802404D4 2402000F */  addiu     $v0, $zero, 0xf
/* E0EC78 802404D8 AFA2001C */  sw        $v0, 0x1c($sp)
/* E0EC7C 802404DC 44833000 */  mtc1      $v1, $f6
/* E0EC80 802404E0 00000000 */  nop
/* E0EC84 802404E4 468031A0 */  cvt.s.w   $f6, $f6
/* E0EC88 802404E8 44073000 */  mfc1      $a3, $f6
/* E0EC8C 802404EC 27A20028 */  addiu     $v0, $sp, 0x28
/* E0EC90 802404F0 AFA20020 */  sw        $v0, 0x20($sp)
/* E0EC94 802404F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* E0EC98 802404F8 E7A20014 */  swc1      $f2, 0x14($sp)
/* E0EC9C 802404FC 0C01BFA4 */  jal       fx_emote
/* E0ECA0 80240500 E7A40018 */   swc1     $f4, 0x18($sp)
/* E0ECA4 80240504 0200202D */  daddu     $a0, $s0, $zero
/* E0ECA8 80240508 240502F4 */  addiu     $a1, $zero, 0x2f4
/* E0ECAC 8024050C 0C012530 */  jal       func_800494C0
/* E0ECB0 80240510 3C060020 */   lui      $a2, 0x20
/* E0ECB4 80240514 8E220018 */  lw        $v0, 0x18($s1)
/* E0ECB8 80240518 9442002A */  lhu       $v0, 0x2a($v0)
/* E0ECBC 8024051C 30420001 */  andi      $v0, $v0, 1
/* E0ECC0 80240520 14400064 */  bnez      $v0, .L802406B4
/* E0ECC4 80240524 2402000A */   addiu    $v0, $zero, 0xa
/* E0ECC8 80240528 080901AD */  j         .L802406B4
/* E0ECCC 8024052C 2402000C */   addiu    $v0, $zero, 0xc
.L80240530:
/* E0ECD0 80240530 8E420074 */  lw        $v0, 0x74($s2)
/* E0ECD4 80240534 2442FFFF */  addiu     $v0, $v0, -1
.L80240538:
/* E0ECD8 80240538 AE420074 */  sw        $v0, 0x74($s2)
.L8024053C:
/* E0ECDC 8024053C 8602008C */  lh        $v0, 0x8c($s0)
/* E0ECE0 80240540 1440005D */  bnez      $v0, .L802406B8
/* E0ECE4 80240544 00000000 */   nop
/* E0ECE8 80240548 C6000018 */  lwc1      $f0, 0x18($s0)
/* E0ECEC 8024054C 3C014010 */  lui       $at, 0x4010
/* E0ECF0 80240550 44811800 */  mtc1      $at, $f3
/* E0ECF4 80240554 44801000 */  mtc1      $zero, $f2
/* E0ECF8 80240558 46000021 */  cvt.d.s   $f0, $f0
/* E0ECFC 8024055C 4622003C */  c.lt.d    $f0, $f2
/* E0ED00 80240560 00000000 */  nop
/* E0ED04 80240564 45000003 */  bc1f      .L80240574
/* E0ED08 80240568 0200202D */   daddu    $a0, $s0, $zero
/* E0ED0C 8024056C 0809015E */  j         .L80240578
/* E0ED10 80240570 0000282D */   daddu    $a1, $zero, $zero
.L80240574:
/* E0ED14 80240574 24050001 */  addiu     $a1, $zero, 1
.L80240578:
/* E0ED18 80240578 0C00F598 */  jal       func_8003D660
/* E0ED1C 8024057C 00000000 */   nop
/* E0ED20 80240580 C60C0038 */  lwc1      $f12, 0x38($s0)
/* E0ED24 80240584 8E430078 */  lw        $v1, 0x78($s2)
/* E0ED28 80240588 C60E0040 */  lwc1      $f14, 0x40($s0)
/* E0ED2C 8024058C 00031040 */  sll       $v0, $v1, 1
/* E0ED30 80240590 00431021 */  addu      $v0, $v0, $v1
/* E0ED34 80240594 8E2300D0 */  lw        $v1, 0xd0($s1)
/* E0ED38 80240598 00021080 */  sll       $v0, $v0, 2
/* E0ED3C 8024059C 00431021 */  addu      $v0, $v0, $v1
/* E0ED40 802405A0 C4560004 */  lwc1      $f22, 4($v0)
/* E0ED44 802405A4 4680B5A0 */  cvt.s.w   $f22, $f22
/* E0ED48 802405A8 C454000C */  lwc1      $f20, 0xc($v0)
/* E0ED4C 802405AC 4680A520 */  cvt.s.w   $f20, $f20
/* E0ED50 802405B0 4406B000 */  mfc1      $a2, $f22
/* E0ED54 802405B4 4407A000 */  mfc1      $a3, $f20
/* E0ED58 802405B8 0C00A720 */  jal       atan2
/* E0ED5C 802405BC 00000000 */   nop
/* E0ED60 802405C0 8E050018 */  lw        $a1, 0x18($s0)
/* E0ED64 802405C4 44060000 */  mfc1      $a2, $f0
/* E0ED68 802405C8 0200202D */  daddu     $a0, $s0, $zero
/* E0ED6C 802405CC 0C00EA95 */  jal       npc_move_heading
/* E0ED70 802405D0 AE06000C */   sw       $a2, 0xc($s0)
/* E0ED74 802405D4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* E0ED78 802405D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* E0ED7C 802405DC 4406B000 */  mfc1      $a2, $f22
/* E0ED80 802405E0 4407A000 */  mfc1      $a3, $f20
/* E0ED84 802405E4 0C00A7B5 */  jal       dist2D
/* E0ED88 802405E8 00000000 */   nop
/* E0ED8C 802405EC C6020018 */  lwc1      $f2, 0x18($s0)
/* E0ED90 802405F0 4602003E */  c.le.s    $f0, $f2
/* E0ED94 802405F4 00000000 */  nop
/* E0ED98 802405F8 4500002F */  bc1f      .L802406B8
/* E0ED9C 802405FC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* E0EDA0 80240600 24020002 */  addiu     $v0, $zero, 2
/* E0EDA4 80240604 0C00A67F */  jal       rand_int
/* E0EDA8 80240608 AE420070 */   sw       $v0, 0x70($s2)
/* E0EDAC 8024060C 3C035555 */  lui       $v1, 0x5555
/* E0EDB0 80240610 34635556 */  ori       $v1, $v1, 0x5556
/* E0EDB4 80240614 00430018 */  mult      $v0, $v1
/* E0EDB8 80240618 000227C3 */  sra       $a0, $v0, 0x1f
/* E0EDBC 8024061C 00004010 */  mfhi      $t0
/* E0EDC0 80240620 01042023 */  subu      $a0, $t0, $a0
/* E0EDC4 80240624 00041840 */  sll       $v1, $a0, 1
/* E0EDC8 80240628 00641821 */  addu      $v1, $v1, $a0
/* E0EDCC 8024062C 00431023 */  subu      $v0, $v0, $v1
/* E0EDD0 80240630 24430002 */  addiu     $v1, $v0, 2
/* E0EDD4 80240634 AE430074 */  sw        $v1, 0x74($s2)
/* E0EDD8 80240638 8E62002C */  lw        $v0, 0x2c($s3)
/* E0EDDC 8024063C 18400009 */  blez      $v0, .L80240664
/* E0EDE0 80240640 24020004 */   addiu    $v0, $zero, 4
/* E0EDE4 80240644 8E620004 */  lw        $v0, 4($s3)
/* E0EDE8 80240648 18400006 */  blez      $v0, .L80240664
/* E0EDEC 8024064C 24020004 */   addiu    $v0, $zero, 4
/* E0EDF0 80240650 8E620008 */  lw        $v0, 8($s3)
/* E0EDF4 80240654 18400003 */  blez      $v0, .L80240664
/* E0EDF8 80240658 24020004 */   addiu    $v0, $zero, 4
/* E0EDFC 8024065C 14600002 */  bnez      $v1, .L80240668
/* E0EE00 80240660 00000000 */   nop
.L80240664:
/* E0EE04 80240664 AE420070 */  sw        $v0, 0x70($s2)
.L80240668:
/* E0EE08 80240668 0C00A67F */  jal       rand_int
/* E0EE0C 8024066C 24042710 */   addiu    $a0, $zero, 0x2710
/* E0EE10 80240670 3C0351EB */  lui       $v1, 0x51eb
/* E0EE14 80240674 3463851F */  ori       $v1, $v1, 0x851f
/* E0EE18 80240678 00430018 */  mult      $v0, $v1
/* E0EE1C 8024067C 00021FC3 */  sra       $v1, $v0, 0x1f
/* E0EE20 80240680 00004010 */  mfhi      $t0
/* E0EE24 80240684 00082143 */  sra       $a0, $t0, 5
/* E0EE28 80240688 00832023 */  subu      $a0, $a0, $v1
/* E0EE2C 8024068C 00041840 */  sll       $v1, $a0, 1
/* E0EE30 80240690 00641821 */  addu      $v1, $v1, $a0
/* E0EE34 80240694 000318C0 */  sll       $v1, $v1, 3
/* E0EE38 80240698 00641821 */  addu      $v1, $v1, $a0
/* E0EE3C 8024069C 00031880 */  sll       $v1, $v1, 2
/* E0EE40 802406A0 8E640004 */  lw        $a0, 4($s3)
/* E0EE44 802406A4 00431023 */  subu      $v0, $v0, $v1
/* E0EE48 802406A8 0044102A */  slt       $v0, $v0, $a0
/* E0EE4C 802406AC 10400002 */  beqz      $v0, .L802406B8
/* E0EE50 802406B0 24020004 */   addiu    $v0, $zero, 4
.L802406B4:
/* E0EE54 802406B4 AE420070 */  sw        $v0, 0x70($s2)
.L802406B8:
/* E0EE58 802406B8 8FBF0044 */  lw        $ra, 0x44($sp)
/* E0EE5C 802406BC 8FB40040 */  lw        $s4, 0x40($sp)
/* E0EE60 802406C0 8FB3003C */  lw        $s3, 0x3c($sp)
/* E0EE64 802406C4 8FB20038 */  lw        $s2, 0x38($sp)
/* E0EE68 802406C8 8FB10034 */  lw        $s1, 0x34($sp)
/* E0EE6C 802406CC 8FB00030 */  lw        $s0, 0x30($sp)
/* E0EE70 802406D0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* E0EE74 802406D4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* E0EE78 802406D8 03E00008 */  jr        $ra
/* E0EE7C 802406DC 27BD0058 */   addiu    $sp, $sp, 0x58
