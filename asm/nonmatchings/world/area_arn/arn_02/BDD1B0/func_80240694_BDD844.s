.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240694_BDD844
/* BDD844 80240694 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BDD848 80240698 AFB30024 */  sw        $s3, 0x24($sp)
/* BDD84C 8024069C 0080982D */  daddu     $s3, $a0, $zero
/* BDD850 802406A0 AFBF002C */  sw        $ra, 0x2c($sp)
/* BDD854 802406A4 AFB40028 */  sw        $s4, 0x28($sp)
/* BDD858 802406A8 AFB20020 */  sw        $s2, 0x20($sp)
/* BDD85C 802406AC AFB1001C */  sw        $s1, 0x1c($sp)
/* BDD860 802406B0 AFB00018 */  sw        $s0, 0x18($sp)
/* BDD864 802406B4 8E710148 */  lw        $s1, 0x148($s3)
/* BDD868 802406B8 86240008 */  lh        $a0, 8($s1)
/* BDD86C 802406BC 0C00EABB */  jal       get_npc_unsafe
/* BDD870 802406C0 00A0A02D */   daddu    $s4, $a1, $zero
/* BDD874 802406C4 0040802D */  daddu     $s0, $v0, $zero
/* BDD878 802406C8 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* BDD87C 802406CC 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* BDD880 802406D0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDD884 802406D4 8E420000 */  lw        $v0, ($s2)
/* BDD888 802406D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDD88C 802406DC 8C460028 */  lw        $a2, 0x28($v0)
/* BDD890 802406E0 0C00A720 */  jal       atan2
/* BDD894 802406E4 8C470030 */   lw       $a3, 0x30($v0)
/* BDD898 802406E8 3C025555 */  lui       $v0, 0x5555
/* BDD89C 802406EC 9603008E */  lhu       $v1, 0x8e($s0)
/* BDD8A0 802406F0 34425556 */  ori       $v0, $v0, 0x5556
/* BDD8A4 802406F4 00031C00 */  sll       $v1, $v1, 0x10
/* BDD8A8 802406F8 00032403 */  sra       $a0, $v1, 0x10
/* BDD8AC 802406FC 00820018 */  mult      $a0, $v0
/* BDD8B0 80240700 00031FC3 */  sra       $v1, $v1, 0x1f
/* BDD8B4 80240704 00004010 */  mfhi      $t0
/* BDD8B8 80240708 01031823 */  subu      $v1, $t0, $v1
/* BDD8BC 8024070C 00031040 */  sll       $v0, $v1, 1
/* BDD8C0 80240710 00431021 */  addu      $v0, $v0, $v1
/* BDD8C4 80240714 00822023 */  subu      $a0, $a0, $v0
/* BDD8C8 80240718 00042400 */  sll       $a0, $a0, 0x10
/* BDD8CC 8024071C 1480000C */  bnez      $a0, .L80240750
/* BDD8D0 80240720 E600000C */   swc1     $f0, 0xc($s0)
/* BDD8D4 80240724 C6020040 */  lwc1      $f2, 0x40($s0)
/* BDD8D8 80240728 3C014000 */  lui       $at, 0x4000
/* BDD8DC 8024072C 44810000 */  mtc1      $at, $f0
/* BDD8E0 80240730 AFA00010 */  sw        $zero, 0x10($sp)
/* BDD8E4 80240734 AFA00014 */  sw        $zero, 0x14($sp)
/* BDD8E8 80240738 46001080 */  add.s     $f2, $f2, $f0
/* BDD8EC 8024073C 8E06003C */  lw        $a2, 0x3c($s0)
/* BDD8F0 80240740 8E050038 */  lw        $a1, 0x38($s0)
/* BDD8F4 80240744 44071000 */  mfc1      $a3, $f2
/* BDD8F8 80240748 0C01BECC */  jal       fx_walk_normal
/* BDD8FC 8024074C 24040002 */   addiu    $a0, $zero, 2
.L80240750:
/* BDD900 80240750 9602008E */  lhu       $v0, 0x8e($s0)
/* BDD904 80240754 2442FFFF */  addiu     $v0, $v0, -1
/* BDD908 80240758 A602008E */  sh        $v0, 0x8e($s0)
/* BDD90C 8024075C 00021400 */  sll       $v0, $v0, 0x10
/* BDD910 80240760 1C40002C */  bgtz      $v0, .L80240814
/* BDD914 80240764 00000000 */   nop      
/* BDD918 80240768 C6000038 */  lwc1      $f0, 0x38($s0)
/* BDD91C 8024076C 4600010D */  trunc.w.s $f4, $f0
/* BDD920 80240770 44022000 */  mfc1      $v0, $f4
/* BDD924 80240774 00000000 */  nop       
/* BDD928 80240778 A6220010 */  sh        $v0, 0x10($s1)
/* BDD92C 8024077C C600003C */  lwc1      $f0, 0x3c($s0)
/* BDD930 80240780 4600010D */  trunc.w.s $f4, $f0
/* BDD934 80240784 44022000 */  mfc1      $v0, $f4
/* BDD938 80240788 00000000 */  nop       
/* BDD93C 8024078C A6220012 */  sh        $v0, 0x12($s1)
/* BDD940 80240790 C6000040 */  lwc1      $f0, 0x40($s0)
/* BDD944 80240794 24020001 */  addiu     $v0, $zero, 1
/* BDD948 80240798 A2220007 */  sb        $v0, 7($s1)
/* BDD94C 8024079C 4600010D */  trunc.w.s $f4, $f0
/* BDD950 802407A0 44022000 */  mfc1      $v0, $f4
/* BDD954 802407A4 00000000 */  nop       
/* BDD958 802407A8 A6220014 */  sh        $v0, 0x14($s1)
/* BDD95C 802407AC C6800018 */  lwc1      $f0, 0x18($s4)
/* BDD960 802407B0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDD964 802407B4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDD968 802407B8 8E420000 */  lw        $v0, ($s2)
/* BDD96C 802407BC E6000018 */  swc1      $f0, 0x18($s0)
/* BDD970 802407C0 8C460028 */  lw        $a2, 0x28($v0)
/* BDD974 802407C4 0C00A7B5 */  jal       dist2D
/* BDD978 802407C8 8C470030 */   lw       $a3, 0x30($v0)
/* BDD97C 802407CC C6020018 */  lwc1      $f2, 0x18($s0)
/* BDD980 802407D0 46020003 */  div.s     $f0, $f0, $f2
/* BDD984 802407D4 3C018024 */  lui       $at, %hi(D_80241AF8)
/* BDD988 802407D8 D4221AF8 */  ldc1      $f2, %lo(D_80241AF8)($at)
/* BDD98C 802407DC 46000021 */  cvt.d.s   $f0, $f0
/* BDD990 802407E0 46220000 */  add.d     $f0, $f0, $f2
/* BDD994 802407E4 4620010D */  trunc.w.d $f4, $f0
/* BDD998 802407E8 44022000 */  mfc1      $v0, $f4
/* BDD99C 802407EC 00000000 */  nop       
/* BDD9A0 802407F0 A602008E */  sh        $v0, 0x8e($s0)
/* BDD9A4 802407F4 00021400 */  sll       $v0, $v0, 0x10
/* BDD9A8 802407F8 00021403 */  sra       $v0, $v0, 0x10
/* BDD9AC 802407FC 2842000F */  slti      $v0, $v0, 0xf
/* BDD9B0 80240800 10400002 */  beqz      $v0, .L8024080C
/* BDD9B4 80240804 2402000F */   addiu    $v0, $zero, 0xf
/* BDD9B8 80240808 A602008E */  sh        $v0, 0x8e($s0)
.L8024080C:
/* BDD9BC 8024080C 24020016 */  addiu     $v0, $zero, 0x16
/* BDD9C0 80240810 AE620070 */  sw        $v0, 0x70($s3)
.L80240814:
/* BDD9C4 80240814 8FBF002C */  lw        $ra, 0x2c($sp)
/* BDD9C8 80240818 8FB40028 */  lw        $s4, 0x28($sp)
/* BDD9CC 8024081C 8FB30024 */  lw        $s3, 0x24($sp)
/* BDD9D0 80240820 8FB20020 */  lw        $s2, 0x20($sp)
/* BDD9D4 80240824 8FB1001C */  lw        $s1, 0x1c($sp)
/* BDD9D8 80240828 8FB00018 */  lw        $s0, 0x18($sp)
/* BDD9DC 8024082C 03E00008 */  jr        $ra
/* BDD9E0 80240830 27BD0030 */   addiu    $sp, $sp, 0x30
