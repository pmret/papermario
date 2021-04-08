.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_02_UnkFunc13
/* B2C9F8 80240588 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* B2C9FC 8024058C AFB20038 */  sw        $s2, 0x38($sp)
/* B2CA00 80240590 0080902D */  daddu     $s2, $a0, $zero
/* B2CA04 80240594 AFBF0044 */  sw        $ra, 0x44($sp)
/* B2CA08 80240598 AFB40040 */  sw        $s4, 0x40($sp)
/* B2CA0C 8024059C AFB3003C */  sw        $s3, 0x3c($sp)
/* B2CA10 802405A0 AFB10034 */  sw        $s1, 0x34($sp)
/* B2CA14 802405A4 AFB00030 */  sw        $s0, 0x30($sp)
/* B2CA18 802405A8 F7B60050 */  sdc1      $f22, 0x50($sp)
/* B2CA1C 802405AC F7B40048 */  sdc1      $f20, 0x48($sp)
/* B2CA20 802405B0 8E510148 */  lw        $s1, 0x148($s2)
/* B2CA24 802405B4 00A0982D */  daddu     $s3, $a1, $zero
/* B2CA28 802405B8 86240008 */  lh        $a0, 8($s1)
/* B2CA2C 802405BC 0C00EABB */  jal       get_npc_unsafe
/* B2CA30 802405C0 00C0A02D */   daddu    $s4, $a2, $zero
/* B2CA34 802405C4 8E630014 */  lw        $v1, 0x14($s3)
/* B2CA38 802405C8 04600030 */  bltz      $v1, .L8024068C
/* B2CA3C 802405CC 0040802D */   daddu    $s0, $v0, $zero
/* B2CA40 802405D0 8E420074 */  lw        $v0, 0x74($s2)
/* B2CA44 802405D4 1C40002C */  bgtz      $v0, .L80240688
/* B2CA48 802405D8 2442FFFF */   addiu    $v0, $v0, -1
/* B2CA4C 802405DC 0280202D */  daddu     $a0, $s4, $zero
/* B2CA50 802405E0 AE430074 */  sw        $v1, 0x74($s2)
/* B2CA54 802405E4 AFA00010 */  sw        $zero, 0x10($sp)
/* B2CA58 802405E8 8E66000C */  lw        $a2, 0xc($s3)
/* B2CA5C 802405EC 8E670010 */  lw        $a3, 0x10($s3)
/* B2CA60 802405F0 0C01242D */  jal       func_800490B4
/* B2CA64 802405F4 0220282D */   daddu    $a1, $s1, $zero
/* B2CA68 802405F8 10400021 */  beqz      $v0, .L80240680
/* B2CA6C 802405FC 0000202D */   daddu    $a0, $zero, $zero
/* B2CA70 80240600 0200282D */  daddu     $a1, $s0, $zero
/* B2CA74 80240604 0000302D */  daddu     $a2, $zero, $zero
/* B2CA78 80240608 860300A8 */  lh        $v1, 0xa8($s0)
/* B2CA7C 8024060C 3C013F80 */  lui       $at, 0x3f80
/* B2CA80 80240610 44810000 */  mtc1      $at, $f0
/* B2CA84 80240614 3C014000 */  lui       $at, 0x4000
/* B2CA88 80240618 44811000 */  mtc1      $at, $f2
/* B2CA8C 8024061C 3C01C1A0 */  lui       $at, 0xc1a0
/* B2CA90 80240620 44812000 */  mtc1      $at, $f4
/* B2CA94 80240624 2402000F */  addiu     $v0, $zero, 0xf
/* B2CA98 80240628 AFA2001C */  sw        $v0, 0x1c($sp)
/* B2CA9C 8024062C 44833000 */  mtc1      $v1, $f6
/* B2CAA0 80240630 00000000 */  nop
/* B2CAA4 80240634 468031A0 */  cvt.s.w   $f6, $f6
/* B2CAA8 80240638 44073000 */  mfc1      $a3, $f6
/* B2CAAC 8024063C 27A20028 */  addiu     $v0, $sp, 0x28
/* B2CAB0 80240640 AFA20020 */  sw        $v0, 0x20($sp)
/* B2CAB4 80240644 E7A00010 */  swc1      $f0, 0x10($sp)
/* B2CAB8 80240648 E7A20014 */  swc1      $f2, 0x14($sp)
/* B2CABC 8024064C 0C01BFA4 */  jal       fx_emote
/* B2CAC0 80240650 E7A40018 */   swc1     $f4, 0x18($sp)
/* B2CAC4 80240654 0200202D */  daddu     $a0, $s0, $zero
/* B2CAC8 80240658 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B2CACC 8024065C 0C012530 */  jal       func_800494C0
/* B2CAD0 80240660 3C060020 */   lui      $a2, 0x20
/* B2CAD4 80240664 8E220018 */  lw        $v0, 0x18($s1)
/* B2CAD8 80240668 9442002A */  lhu       $v0, 0x2a($v0)
/* B2CADC 8024066C 30420001 */  andi      $v0, $v0, 1
/* B2CAE0 80240670 14400064 */  bnez      $v0, .L80240804
/* B2CAE4 80240674 2402000A */   addiu    $v0, $zero, 0xa
/* B2CAE8 80240678 08090201 */  j         .L80240804
/* B2CAEC 8024067C 2402000C */   addiu    $v0, $zero, 0xc
.L80240680:
/* B2CAF0 80240680 8E420074 */  lw        $v0, 0x74($s2)
/* B2CAF4 80240684 2442FFFF */  addiu     $v0, $v0, -1
.L80240688:
/* B2CAF8 80240688 AE420074 */  sw        $v0, 0x74($s2)
.L8024068C:
/* B2CAFC 8024068C 8602008C */  lh        $v0, 0x8c($s0)
/* B2CB00 80240690 1440005D */  bnez      $v0, .L80240808
/* B2CB04 80240694 00000000 */   nop
/* B2CB08 80240698 C6000018 */  lwc1      $f0, 0x18($s0)
/* B2CB0C 8024069C 3C014010 */  lui       $at, 0x4010
/* B2CB10 802406A0 44811800 */  mtc1      $at, $f3
/* B2CB14 802406A4 44801000 */  mtc1      $zero, $f2
/* B2CB18 802406A8 46000021 */  cvt.d.s   $f0, $f0
/* B2CB1C 802406AC 4622003C */  c.lt.d    $f0, $f2
/* B2CB20 802406B0 00000000 */  nop
/* B2CB24 802406B4 45000003 */  bc1f      .L802406C4
/* B2CB28 802406B8 0200202D */   daddu    $a0, $s0, $zero
/* B2CB2C 802406BC 080901B2 */  j         .L802406C8
/* B2CB30 802406C0 0000282D */   daddu    $a1, $zero, $zero
.L802406C4:
/* B2CB34 802406C4 24050001 */  addiu     $a1, $zero, 1
.L802406C8:
/* B2CB38 802406C8 0C00F598 */  jal       func_8003D660
/* B2CB3C 802406CC 00000000 */   nop
/* B2CB40 802406D0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B2CB44 802406D4 8E430078 */  lw        $v1, 0x78($s2)
/* B2CB48 802406D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B2CB4C 802406DC 00031040 */  sll       $v0, $v1, 1
/* B2CB50 802406E0 00431021 */  addu      $v0, $v0, $v1
/* B2CB54 802406E4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B2CB58 802406E8 00021080 */  sll       $v0, $v0, 2
/* B2CB5C 802406EC 00431021 */  addu      $v0, $v0, $v1
/* B2CB60 802406F0 C4560004 */  lwc1      $f22, 4($v0)
/* B2CB64 802406F4 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2CB68 802406F8 C454000C */  lwc1      $f20, 0xc($v0)
/* B2CB6C 802406FC 4680A520 */  cvt.s.w   $f20, $f20
/* B2CB70 80240700 4406B000 */  mfc1      $a2, $f22
/* B2CB74 80240704 4407A000 */  mfc1      $a3, $f20
/* B2CB78 80240708 0C00A720 */  jal       atan2
/* B2CB7C 8024070C 00000000 */   nop
/* B2CB80 80240710 8E050018 */  lw        $a1, 0x18($s0)
/* B2CB84 80240714 44060000 */  mfc1      $a2, $f0
/* B2CB88 80240718 0200202D */  daddu     $a0, $s0, $zero
/* B2CB8C 8024071C 0C00EA95 */  jal       npc_move_heading
/* B2CB90 80240720 AE06000C */   sw       $a2, 0xc($s0)
/* B2CB94 80240724 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B2CB98 80240728 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B2CB9C 8024072C 4406B000 */  mfc1      $a2, $f22
/* B2CBA0 80240730 4407A000 */  mfc1      $a3, $f20
/* B2CBA4 80240734 0C00A7B5 */  jal       dist2D
/* B2CBA8 80240738 00000000 */   nop
/* B2CBAC 8024073C C6020018 */  lwc1      $f2, 0x18($s0)
/* B2CBB0 80240740 4602003E */  c.le.s    $f0, $f2
/* B2CBB4 80240744 00000000 */  nop
/* B2CBB8 80240748 4500002F */  bc1f      .L80240808
/* B2CBBC 8024074C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B2CBC0 80240750 24020002 */  addiu     $v0, $zero, 2
/* B2CBC4 80240754 0C00A67F */  jal       rand_int
/* B2CBC8 80240758 AE420070 */   sw       $v0, 0x70($s2)
/* B2CBCC 8024075C 3C035555 */  lui       $v1, 0x5555
/* B2CBD0 80240760 34635556 */  ori       $v1, $v1, 0x5556
/* B2CBD4 80240764 00430018 */  mult      $v0, $v1
/* B2CBD8 80240768 000227C3 */  sra       $a0, $v0, 0x1f
/* B2CBDC 8024076C 00004010 */  mfhi      $t0
/* B2CBE0 80240770 01042023 */  subu      $a0, $t0, $a0
/* B2CBE4 80240774 00041840 */  sll       $v1, $a0, 1
/* B2CBE8 80240778 00641821 */  addu      $v1, $v1, $a0
/* B2CBEC 8024077C 00431023 */  subu      $v0, $v0, $v1
/* B2CBF0 80240780 24430002 */  addiu     $v1, $v0, 2
/* B2CBF4 80240784 AE430074 */  sw        $v1, 0x74($s2)
/* B2CBF8 80240788 8E62002C */  lw        $v0, 0x2c($s3)
/* B2CBFC 8024078C 18400009 */  blez      $v0, .L802407B4
/* B2CC00 80240790 24020004 */   addiu    $v0, $zero, 4
/* B2CC04 80240794 8E620004 */  lw        $v0, 4($s3)
/* B2CC08 80240798 18400006 */  blez      $v0, .L802407B4
/* B2CC0C 8024079C 24020004 */   addiu    $v0, $zero, 4
/* B2CC10 802407A0 8E620008 */  lw        $v0, 8($s3)
/* B2CC14 802407A4 18400003 */  blez      $v0, .L802407B4
/* B2CC18 802407A8 24020004 */   addiu    $v0, $zero, 4
/* B2CC1C 802407AC 14600002 */  bnez      $v1, .L802407B8
/* B2CC20 802407B0 00000000 */   nop
.L802407B4:
/* B2CC24 802407B4 AE420070 */  sw        $v0, 0x70($s2)
.L802407B8:
/* B2CC28 802407B8 0C00A67F */  jal       rand_int
/* B2CC2C 802407BC 24042710 */   addiu    $a0, $zero, 0x2710
/* B2CC30 802407C0 3C0351EB */  lui       $v1, 0x51eb
/* B2CC34 802407C4 3463851F */  ori       $v1, $v1, 0x851f
/* B2CC38 802407C8 00430018 */  mult      $v0, $v1
/* B2CC3C 802407CC 00021FC3 */  sra       $v1, $v0, 0x1f
/* B2CC40 802407D0 00004010 */  mfhi      $t0
/* B2CC44 802407D4 00082143 */  sra       $a0, $t0, 5
/* B2CC48 802407D8 00832023 */  subu      $a0, $a0, $v1
/* B2CC4C 802407DC 00041840 */  sll       $v1, $a0, 1
/* B2CC50 802407E0 00641821 */  addu      $v1, $v1, $a0
/* B2CC54 802407E4 000318C0 */  sll       $v1, $v1, 3
/* B2CC58 802407E8 00641821 */  addu      $v1, $v1, $a0
/* B2CC5C 802407EC 00031880 */  sll       $v1, $v1, 2
/* B2CC60 802407F0 8E640004 */  lw        $a0, 4($s3)
/* B2CC64 802407F4 00431023 */  subu      $v0, $v0, $v1
/* B2CC68 802407F8 0044102A */  slt       $v0, $v0, $a0
/* B2CC6C 802407FC 10400002 */  beqz      $v0, .L80240808
/* B2CC70 80240800 24020004 */   addiu    $v0, $zero, 4
.L80240804:
/* B2CC74 80240804 AE420070 */  sw        $v0, 0x70($s2)
.L80240808:
/* B2CC78 80240808 8FBF0044 */  lw        $ra, 0x44($sp)
/* B2CC7C 8024080C 8FB40040 */  lw        $s4, 0x40($sp)
/* B2CC80 80240810 8FB3003C */  lw        $s3, 0x3c($sp)
/* B2CC84 80240814 8FB20038 */  lw        $s2, 0x38($sp)
/* B2CC88 80240818 8FB10034 */  lw        $s1, 0x34($sp)
/* B2CC8C 8024081C 8FB00030 */  lw        $s0, 0x30($sp)
/* B2CC90 80240820 D7B60050 */  ldc1      $f22, 0x50($sp)
/* B2CC94 80240824 D7B40048 */  ldc1      $f20, 0x48($sp)
/* B2CC98 80240828 03E00008 */  jr        $ra
/* B2CC9C 8024082C 27BD0058 */   addiu    $sp, $sp, 0x58
