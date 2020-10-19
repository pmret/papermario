.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242684
/* BFFF04 80242684 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BFFF08 80242688 AFB20038 */  sw        $s2, 0x38($sp)
/* BFFF0C 8024268C 0080902D */  daddu     $s2, $a0, $zero
/* BFFF10 80242690 AFBF0044 */  sw        $ra, 0x44($sp)
/* BFFF14 80242694 AFB40040 */  sw        $s4, 0x40($sp)
/* BFFF18 80242698 AFB3003C */  sw        $s3, 0x3c($sp)
/* BFFF1C 8024269C AFB10034 */  sw        $s1, 0x34($sp)
/* BFFF20 802426A0 AFB00030 */  sw        $s0, 0x30($sp)
/* BFFF24 802426A4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* BFFF28 802426A8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* BFFF2C 802426AC 8E510148 */  lw        $s1, 0x148($s2)
/* BFFF30 802426B0 00A0982D */  daddu     $s3, $a1, $zero
/* BFFF34 802426B4 86240008 */  lh        $a0, 8($s1)
/* BFFF38 802426B8 0C00EABB */  jal       get_npc_unsafe
/* BFFF3C 802426BC 00C0A02D */   daddu    $s4, $a2, $zero
/* BFFF40 802426C0 8E630014 */  lw        $v1, 0x14($s3)
/* BFFF44 802426C4 04600030 */  bltz      $v1, .L80242788
/* BFFF48 802426C8 0040802D */   daddu    $s0, $v0, $zero
/* BFFF4C 802426CC 8E420074 */  lw        $v0, 0x74($s2)
/* BFFF50 802426D0 1C40002C */  bgtz      $v0, .L80242784
/* BFFF54 802426D4 2442FFFF */   addiu    $v0, $v0, -1
/* BFFF58 802426D8 0280202D */  daddu     $a0, $s4, $zero
/* BFFF5C 802426DC AE430074 */  sw        $v1, 0x74($s2)
/* BFFF60 802426E0 AFA00010 */  sw        $zero, 0x10($sp)
/* BFFF64 802426E4 8E66000C */  lw        $a2, 0xc($s3)
/* BFFF68 802426E8 8E670010 */  lw        $a3, 0x10($s3)
/* BFFF6C 802426EC 0C01242D */  jal       func_800490B4
/* BFFF70 802426F0 0220282D */   daddu    $a1, $s1, $zero
/* BFFF74 802426F4 10400021 */  beqz      $v0, .L8024277C
/* BFFF78 802426F8 0000202D */   daddu    $a0, $zero, $zero
/* BFFF7C 802426FC 0200282D */  daddu     $a1, $s0, $zero
/* BFFF80 80242700 0000302D */  daddu     $a2, $zero, $zero
/* BFFF84 80242704 860300A8 */  lh        $v1, 0xa8($s0)
/* BFFF88 80242708 3C013F80 */  lui       $at, 0x3f80
/* BFFF8C 8024270C 44810000 */  mtc1      $at, $f0
/* BFFF90 80242710 3C014000 */  lui       $at, 0x4000
/* BFFF94 80242714 44811000 */  mtc1      $at, $f2
/* BFFF98 80242718 3C01C1A0 */  lui       $at, 0xc1a0
/* BFFF9C 8024271C 44812000 */  mtc1      $at, $f4
/* BFFFA0 80242720 2402000F */  addiu     $v0, $zero, 0xf
/* BFFFA4 80242724 AFA2001C */  sw        $v0, 0x1c($sp)
/* BFFFA8 80242728 44833000 */  mtc1      $v1, $f6
/* BFFFAC 8024272C 00000000 */  nop       
/* BFFFB0 80242730 468031A0 */  cvt.s.w   $f6, $f6
/* BFFFB4 80242734 44073000 */  mfc1      $a3, $f6
/* BFFFB8 80242738 27A20028 */  addiu     $v0, $sp, 0x28
/* BFFFBC 8024273C AFA20020 */  sw        $v0, 0x20($sp)
/* BFFFC0 80242740 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFFFC4 80242744 E7A20014 */  swc1      $f2, 0x14($sp)
/* BFFFC8 80242748 0C01BFA4 */  jal       fx_emote
/* BFFFCC 8024274C E7A40018 */   swc1     $f4, 0x18($sp)
/* BFFFD0 80242750 0200202D */  daddu     $a0, $s0, $zero
/* BFFFD4 80242754 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BFFFD8 80242758 0C012530 */  jal       func_800494C0
/* BFFFDC 8024275C 3C060020 */   lui      $a2, 0x20
/* BFFFE0 80242760 8E220018 */  lw        $v0, 0x18($s1)
/* BFFFE4 80242764 9442002A */  lhu       $v0, 0x2a($v0)
/* BFFFE8 80242768 30420001 */  andi      $v0, $v0, 1
/* BFFFEC 8024276C 14400064 */  bnez      $v0, .L80242900
/* BFFFF0 80242770 2402000A */   addiu    $v0, $zero, 0xa
/* BFFFF4 80242774 08090A40 */  j         .L80242900
/* BFFFF8 80242778 2402000C */   addiu    $v0, $zero, 0xc
.L8024277C:
/* BFFFFC 8024277C 8E420074 */  lw        $v0, 0x74($s2)
/* C00000 80242780 2442FFFF */  addiu     $v0, $v0, -1
.L80242784:
/* C00004 80242784 AE420074 */  sw        $v0, 0x74($s2)
.L80242788:
/* C00008 80242788 8602008C */  lh        $v0, 0x8c($s0)
/* C0000C 8024278C 1440005D */  bnez      $v0, .L80242904
/* C00010 80242790 00000000 */   nop      
/* C00014 80242794 C6000018 */  lwc1      $f0, 0x18($s0)
/* C00018 80242798 3C014010 */  lui       $at, 0x4010
/* C0001C 8024279C 44811800 */  mtc1      $at, $f3
/* C00020 802427A0 44801000 */  mtc1      $zero, $f2
/* C00024 802427A4 46000021 */  cvt.d.s   $f0, $f0
/* C00028 802427A8 4622003C */  c.lt.d    $f0, $f2
/* C0002C 802427AC 00000000 */  nop       
/* C00030 802427B0 45000003 */  bc1f      .L802427C0
/* C00034 802427B4 0200202D */   daddu    $a0, $s0, $zero
/* C00038 802427B8 080909F1 */  j         .L802427C4
/* C0003C 802427BC 0000282D */   daddu    $a1, $zero, $zero
.L802427C0:
/* C00040 802427C0 24050001 */  addiu     $a1, $zero, 1
.L802427C4:
/* C00044 802427C4 0C00F598 */  jal       func_8003D660
/* C00048 802427C8 00000000 */   nop      
/* C0004C 802427CC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C00050 802427D0 8E430078 */  lw        $v1, 0x78($s2)
/* C00054 802427D4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C00058 802427D8 00031040 */  sll       $v0, $v1, 1
/* C0005C 802427DC 00431021 */  addu      $v0, $v0, $v1
/* C00060 802427E0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C00064 802427E4 00021080 */  sll       $v0, $v0, 2
/* C00068 802427E8 00431021 */  addu      $v0, $v0, $v1
/* C0006C 802427EC C4560004 */  lwc1      $f22, 4($v0)
/* C00070 802427F0 4680B5A0 */  cvt.s.w   $f22, $f22
/* C00074 802427F4 C454000C */  lwc1      $f20, 0xc($v0)
/* C00078 802427F8 4680A520 */  cvt.s.w   $f20, $f20
/* C0007C 802427FC 4406B000 */  mfc1      $a2, $f22
/* C00080 80242800 4407A000 */  mfc1      $a3, $f20
/* C00084 80242804 0C00A720 */  jal       atan2
/* C00088 80242808 00000000 */   nop      
/* C0008C 8024280C 8E050018 */  lw        $a1, 0x18($s0)
/* C00090 80242810 44060000 */  mfc1      $a2, $f0
/* C00094 80242814 0200202D */  daddu     $a0, $s0, $zero
/* C00098 80242818 0C00EA95 */  jal       npc_move_heading
/* C0009C 8024281C AE06000C */   sw       $a2, 0xc($s0)
/* C000A0 80242820 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C000A4 80242824 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C000A8 80242828 4406B000 */  mfc1      $a2, $f22
/* C000AC 8024282C 4407A000 */  mfc1      $a3, $f20
/* C000B0 80242830 0C00A7B5 */  jal       dist2D
/* C000B4 80242834 00000000 */   nop      
/* C000B8 80242838 C6020018 */  lwc1      $f2, 0x18($s0)
/* C000BC 8024283C 4602003E */  c.le.s    $f0, $f2
/* C000C0 80242840 00000000 */  nop       
/* C000C4 80242844 4500002F */  bc1f      .L80242904
/* C000C8 80242848 240403E8 */   addiu    $a0, $zero, 0x3e8
/* C000CC 8024284C 24020002 */  addiu     $v0, $zero, 2
/* C000D0 80242850 0C00A67F */  jal       rand_int
/* C000D4 80242854 AE420070 */   sw       $v0, 0x70($s2)
/* C000D8 80242858 3C035555 */  lui       $v1, 0x5555
/* C000DC 8024285C 34635556 */  ori       $v1, $v1, 0x5556
/* C000E0 80242860 00430018 */  mult      $v0, $v1
/* C000E4 80242864 000227C3 */  sra       $a0, $v0, 0x1f
/* C000E8 80242868 00004010 */  mfhi      $t0
/* C000EC 8024286C 01042023 */  subu      $a0, $t0, $a0
/* C000F0 80242870 00041840 */  sll       $v1, $a0, 1
/* C000F4 80242874 00641821 */  addu      $v1, $v1, $a0
/* C000F8 80242878 00431023 */  subu      $v0, $v0, $v1
/* C000FC 8024287C 24430002 */  addiu     $v1, $v0, 2
/* C00100 80242880 AE430074 */  sw        $v1, 0x74($s2)
/* C00104 80242884 8E62002C */  lw        $v0, 0x2c($s3)
/* C00108 80242888 18400009 */  blez      $v0, .L802428B0
/* C0010C 8024288C 24020004 */   addiu    $v0, $zero, 4
/* C00110 80242890 8E620004 */  lw        $v0, 4($s3)
/* C00114 80242894 18400006 */  blez      $v0, .L802428B0
/* C00118 80242898 24020004 */   addiu    $v0, $zero, 4
/* C0011C 8024289C 8E620008 */  lw        $v0, 8($s3)
/* C00120 802428A0 18400003 */  blez      $v0, .L802428B0
/* C00124 802428A4 24020004 */   addiu    $v0, $zero, 4
/* C00128 802428A8 14600002 */  bnez      $v1, .L802428B4
/* C0012C 802428AC 00000000 */   nop      
.L802428B0:
/* C00130 802428B0 AE420070 */  sw        $v0, 0x70($s2)
.L802428B4:
/* C00134 802428B4 0C00A67F */  jal       rand_int
/* C00138 802428B8 24042710 */   addiu    $a0, $zero, 0x2710
/* C0013C 802428BC 3C0351EB */  lui       $v1, 0x51eb
/* C00140 802428C0 3463851F */  ori       $v1, $v1, 0x851f
/* C00144 802428C4 00430018 */  mult      $v0, $v1
/* C00148 802428C8 00021FC3 */  sra       $v1, $v0, 0x1f
/* C0014C 802428CC 00004010 */  mfhi      $t0
/* C00150 802428D0 00082143 */  sra       $a0, $t0, 5
/* C00154 802428D4 00832023 */  subu      $a0, $a0, $v1
/* C00158 802428D8 00041840 */  sll       $v1, $a0, 1
/* C0015C 802428DC 00641821 */  addu      $v1, $v1, $a0
/* C00160 802428E0 000318C0 */  sll       $v1, $v1, 3
/* C00164 802428E4 00641821 */  addu      $v1, $v1, $a0
/* C00168 802428E8 00031880 */  sll       $v1, $v1, 2
/* C0016C 802428EC 8E640004 */  lw        $a0, 4($s3)
/* C00170 802428F0 00431023 */  subu      $v0, $v0, $v1
/* C00174 802428F4 0044102A */  slt       $v0, $v0, $a0
/* C00178 802428F8 10400002 */  beqz      $v0, .L80242904
/* C0017C 802428FC 24020004 */   addiu    $v0, $zero, 4
.L80242900:
/* C00180 80242900 AE420070 */  sw        $v0, 0x70($s2)
.L80242904:
/* C00184 80242904 8FBF0044 */  lw        $ra, 0x44($sp)
/* C00188 80242908 8FB40040 */  lw        $s4, 0x40($sp)
/* C0018C 8024290C 8FB3003C */  lw        $s3, 0x3c($sp)
/* C00190 80242910 8FB20038 */  lw        $s2, 0x38($sp)
/* C00194 80242914 8FB10034 */  lw        $s1, 0x34($sp)
/* C00198 80242918 8FB00030 */  lw        $s0, 0x30($sp)
/* C0019C 8024291C D7B60050 */  ldc1      $f22, 0x50($sp)
/* C001A0 80242920 D7B40048 */  ldc1      $f20, 0x48($sp)
/* C001A4 80242924 03E00008 */  jr        $ra
/* C001A8 80242928 27BD0058 */   addiu    $sp, $sp, 0x58
