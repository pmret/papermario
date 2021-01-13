.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405E8_852758
/* 852758 802405E8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 85275C 802405EC AFB20038 */  sw        $s2, 0x38($sp)
/* 852760 802405F0 0080902D */  daddu     $s2, $a0, $zero
/* 852764 802405F4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 852768 802405F8 AFB40040 */  sw        $s4, 0x40($sp)
/* 85276C 802405FC AFB3003C */  sw        $s3, 0x3c($sp)
/* 852770 80240600 AFB10034 */  sw        $s1, 0x34($sp)
/* 852774 80240604 AFB00030 */  sw        $s0, 0x30($sp)
/* 852778 80240608 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 85277C 8024060C F7B40048 */  sdc1      $f20, 0x48($sp)
/* 852780 80240610 8E510148 */  lw        $s1, 0x148($s2)
/* 852784 80240614 00A0982D */  daddu     $s3, $a1, $zero
/* 852788 80240618 86240008 */  lh        $a0, 8($s1)
/* 85278C 8024061C 0C00EABB */  jal       get_npc_unsafe
/* 852790 80240620 00C0A02D */   daddu    $s4, $a2, $zero
/* 852794 80240624 8E630014 */  lw        $v1, 0x14($s3)
/* 852798 80240628 04600030 */  bltz      $v1, .L802406EC
/* 85279C 8024062C 0040802D */   daddu    $s0, $v0, $zero
/* 8527A0 80240630 8E420074 */  lw        $v0, 0x74($s2)
/* 8527A4 80240634 1C40002C */  bgtz      $v0, .L802406E8
/* 8527A8 80240638 2442FFFF */   addiu    $v0, $v0, -1
/* 8527AC 8024063C 0280202D */  daddu     $a0, $s4, $zero
/* 8527B0 80240640 AE430074 */  sw        $v1, 0x74($s2)
/* 8527B4 80240644 AFA00010 */  sw        $zero, 0x10($sp)
/* 8527B8 80240648 8E66000C */  lw        $a2, 0xc($s3)
/* 8527BC 8024064C 8E670010 */  lw        $a3, 0x10($s3)
/* 8527C0 80240650 0C01242D */  jal       func_800490B4
/* 8527C4 80240654 0220282D */   daddu    $a1, $s1, $zero
/* 8527C8 80240658 10400021 */  beqz      $v0, .L802406E0
/* 8527CC 8024065C 0000202D */   daddu    $a0, $zero, $zero
/* 8527D0 80240660 0200282D */  daddu     $a1, $s0, $zero
/* 8527D4 80240664 0000302D */  daddu     $a2, $zero, $zero
/* 8527D8 80240668 860300A8 */  lh        $v1, 0xa8($s0)
/* 8527DC 8024066C 3C013F80 */  lui       $at, 0x3f80
/* 8527E0 80240670 44810000 */  mtc1      $at, $f0
/* 8527E4 80240674 3C014000 */  lui       $at, 0x4000
/* 8527E8 80240678 44811000 */  mtc1      $at, $f2
/* 8527EC 8024067C 3C01C1A0 */  lui       $at, 0xc1a0
/* 8527F0 80240680 44812000 */  mtc1      $at, $f4
/* 8527F4 80240684 2402000F */  addiu     $v0, $zero, 0xf
/* 8527F8 80240688 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8527FC 8024068C 44833000 */  mtc1      $v1, $f6
/* 852800 80240690 00000000 */  nop
/* 852804 80240694 468031A0 */  cvt.s.w   $f6, $f6
/* 852808 80240698 44073000 */  mfc1      $a3, $f6
/* 85280C 8024069C 27A20028 */  addiu     $v0, $sp, 0x28
/* 852810 802406A0 AFA20020 */  sw        $v0, 0x20($sp)
/* 852814 802406A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 852818 802406A8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 85281C 802406AC 0C01BFA4 */  jal       fx_emote
/* 852820 802406B0 E7A40018 */   swc1     $f4, 0x18($sp)
/* 852824 802406B4 0200202D */  daddu     $a0, $s0, $zero
/* 852828 802406B8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 85282C 802406BC 0C012530 */  jal       func_800494C0
/* 852830 802406C0 3C060020 */   lui      $a2, 0x20
/* 852834 802406C4 8E220018 */  lw        $v0, 0x18($s1)
/* 852838 802406C8 9442002A */  lhu       $v0, 0x2a($v0)
/* 85283C 802406CC 30420001 */  andi      $v0, $v0, 1
/* 852840 802406D0 14400064 */  bnez      $v0, .L80240864
/* 852844 802406D4 2402000A */   addiu    $v0, $zero, 0xa
/* 852848 802406D8 08090219 */  j         .L80240864
/* 85284C 802406DC 2402000C */   addiu    $v0, $zero, 0xc
.L802406E0:
/* 852850 802406E0 8E420074 */  lw        $v0, 0x74($s2)
/* 852854 802406E4 2442FFFF */  addiu     $v0, $v0, -1
.L802406E8:
/* 852858 802406E8 AE420074 */  sw        $v0, 0x74($s2)
.L802406EC:
/* 85285C 802406EC 8602008C */  lh        $v0, 0x8c($s0)
/* 852860 802406F0 1440005D */  bnez      $v0, .L80240868
/* 852864 802406F4 00000000 */   nop
/* 852868 802406F8 C6000018 */  lwc1      $f0, 0x18($s0)
/* 85286C 802406FC 3C014010 */  lui       $at, 0x4010
/* 852870 80240700 44811800 */  mtc1      $at, $f3
/* 852874 80240704 44801000 */  mtc1      $zero, $f2
/* 852878 80240708 46000021 */  cvt.d.s   $f0, $f0
/* 85287C 8024070C 4622003C */  c.lt.d    $f0, $f2
/* 852880 80240710 00000000 */  nop
/* 852884 80240714 45000003 */  bc1f      .L80240724
/* 852888 80240718 0200202D */   daddu    $a0, $s0, $zero
/* 85288C 8024071C 080901CA */  j         .L80240728
/* 852890 80240720 0000282D */   daddu    $a1, $zero, $zero
.L80240724:
/* 852894 80240724 24050001 */  addiu     $a1, $zero, 1
.L80240728:
/* 852898 80240728 0C00F598 */  jal       func_8003D660
/* 85289C 8024072C 00000000 */   nop
/* 8528A0 80240730 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8528A4 80240734 8E430078 */  lw        $v1, 0x78($s2)
/* 8528A8 80240738 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8528AC 8024073C 00031040 */  sll       $v0, $v1, 1
/* 8528B0 80240740 00431021 */  addu      $v0, $v0, $v1
/* 8528B4 80240744 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 8528B8 80240748 00021080 */  sll       $v0, $v0, 2
/* 8528BC 8024074C 00431021 */  addu      $v0, $v0, $v1
/* 8528C0 80240750 C4560004 */  lwc1      $f22, 4($v0)
/* 8528C4 80240754 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8528C8 80240758 C454000C */  lwc1      $f20, 0xc($v0)
/* 8528CC 8024075C 4680A520 */  cvt.s.w   $f20, $f20
/* 8528D0 80240760 4406B000 */  mfc1      $a2, $f22
/* 8528D4 80240764 4407A000 */  mfc1      $a3, $f20
/* 8528D8 80240768 0C00A720 */  jal       atan2
/* 8528DC 8024076C 00000000 */   nop
/* 8528E0 80240770 8E050018 */  lw        $a1, 0x18($s0)
/* 8528E4 80240774 44060000 */  mfc1      $a2, $f0
/* 8528E8 80240778 0200202D */  daddu     $a0, $s0, $zero
/* 8528EC 8024077C 0C00EA95 */  jal       npc_move_heading
/* 8528F0 80240780 AE06000C */   sw       $a2, 0xc($s0)
/* 8528F4 80240784 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8528F8 80240788 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8528FC 8024078C 4406B000 */  mfc1      $a2, $f22
/* 852900 80240790 4407A000 */  mfc1      $a3, $f20
/* 852904 80240794 0C00A7B5 */  jal       dist2D
/* 852908 80240798 00000000 */   nop
/* 85290C 8024079C C6020018 */  lwc1      $f2, 0x18($s0)
/* 852910 802407A0 4602003E */  c.le.s    $f0, $f2
/* 852914 802407A4 00000000 */  nop
/* 852918 802407A8 4500002F */  bc1f      .L80240868
/* 85291C 802407AC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 852920 802407B0 24020002 */  addiu     $v0, $zero, 2
/* 852924 802407B4 0C00A67F */  jal       rand_int
/* 852928 802407B8 AE420070 */   sw       $v0, 0x70($s2)
/* 85292C 802407BC 3C035555 */  lui       $v1, 0x5555
/* 852930 802407C0 34635556 */  ori       $v1, $v1, 0x5556
/* 852934 802407C4 00430018 */  mult      $v0, $v1
/* 852938 802407C8 000227C3 */  sra       $a0, $v0, 0x1f
/* 85293C 802407CC 00004010 */  mfhi      $t0
/* 852940 802407D0 01042023 */  subu      $a0, $t0, $a0
/* 852944 802407D4 00041840 */  sll       $v1, $a0, 1
/* 852948 802407D8 00641821 */  addu      $v1, $v1, $a0
/* 85294C 802407DC 00431023 */  subu      $v0, $v0, $v1
/* 852950 802407E0 24430002 */  addiu     $v1, $v0, 2
/* 852954 802407E4 AE430074 */  sw        $v1, 0x74($s2)
/* 852958 802407E8 8E62002C */  lw        $v0, 0x2c($s3)
/* 85295C 802407EC 18400009 */  blez      $v0, .L80240814
/* 852960 802407F0 24020004 */   addiu    $v0, $zero, 4
/* 852964 802407F4 8E620004 */  lw        $v0, 4($s3)
/* 852968 802407F8 18400006 */  blez      $v0, .L80240814
/* 85296C 802407FC 24020004 */   addiu    $v0, $zero, 4
/* 852970 80240800 8E620008 */  lw        $v0, 8($s3)
/* 852974 80240804 18400003 */  blez      $v0, .L80240814
/* 852978 80240808 24020004 */   addiu    $v0, $zero, 4
/* 85297C 8024080C 14600002 */  bnez      $v1, .L80240818
/* 852980 80240810 00000000 */   nop
.L80240814:
/* 852984 80240814 AE420070 */  sw        $v0, 0x70($s2)
.L80240818:
/* 852988 80240818 0C00A67F */  jal       rand_int
/* 85298C 8024081C 24042710 */   addiu    $a0, $zero, 0x2710
/* 852990 80240820 3C0351EB */  lui       $v1, 0x51eb
/* 852994 80240824 3463851F */  ori       $v1, $v1, 0x851f
/* 852998 80240828 00430018 */  mult      $v0, $v1
/* 85299C 8024082C 00021FC3 */  sra       $v1, $v0, 0x1f
/* 8529A0 80240830 00004010 */  mfhi      $t0
/* 8529A4 80240834 00082143 */  sra       $a0, $t0, 5
/* 8529A8 80240838 00832023 */  subu      $a0, $a0, $v1
/* 8529AC 8024083C 00041840 */  sll       $v1, $a0, 1
/* 8529B0 80240840 00641821 */  addu      $v1, $v1, $a0
/* 8529B4 80240844 000318C0 */  sll       $v1, $v1, 3
/* 8529B8 80240848 00641821 */  addu      $v1, $v1, $a0
/* 8529BC 8024084C 00031880 */  sll       $v1, $v1, 2
/* 8529C0 80240850 8E640004 */  lw        $a0, 4($s3)
/* 8529C4 80240854 00431023 */  subu      $v0, $v0, $v1
/* 8529C8 80240858 0044102A */  slt       $v0, $v0, $a0
/* 8529CC 8024085C 10400002 */  beqz      $v0, .L80240868
/* 8529D0 80240860 24020004 */   addiu    $v0, $zero, 4
.L80240864:
/* 8529D4 80240864 AE420070 */  sw        $v0, 0x70($s2)
.L80240868:
/* 8529D8 80240868 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8529DC 8024086C 8FB40040 */  lw        $s4, 0x40($sp)
/* 8529E0 80240870 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8529E4 80240874 8FB20038 */  lw        $s2, 0x38($sp)
/* 8529E8 80240878 8FB10034 */  lw        $s1, 0x34($sp)
/* 8529EC 8024087C 8FB00030 */  lw        $s0, 0x30($sp)
/* 8529F0 80240880 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 8529F4 80240884 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 8529F8 80240888 03E00008 */  jr        $ra
/* 8529FC 8024088C 27BD0058 */   addiu    $sp, $sp, 0x58
