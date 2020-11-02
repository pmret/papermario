.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD638
/* 31B658 802BD638 3C02800B */  lui       $v0, 0x800b
/* 31B65C 802BD63C 80420F18 */  lb        $v0, 0xf18($v0)
/* 31B660 802BD640 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 31B664 802BD644 AFB50044 */  sw        $s5, 0x44($sp)
/* 31B668 802BD648 0080A82D */  daddu     $s5, $a0, $zero
/* 31B66C 802BD64C AFB40040 */  sw        $s4, 0x40($sp)
/* 31B670 802BD650 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* 31B674 802BD654 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* 31B678 802BD658 AFB60048 */  sw        $s6, 0x48($sp)
/* 31B67C 802BD65C 3C168011 */  lui       $s6, %hi(D_8010EBB0)
/* 31B680 802BD660 26D6EBB0 */  addiu     $s6, $s6, %lo(D_8010EBB0)
/* 31B684 802BD664 AFBF004C */  sw        $ra, 0x4c($sp)
/* 31B688 802BD668 AFB3003C */  sw        $s3, 0x3c($sp)
/* 31B68C 802BD66C AFB20038 */  sw        $s2, 0x38($sp)
/* 31B690 802BD670 AFB10034 */  sw        $s1, 0x34($sp)
/* 31B694 802BD674 AFB00030 */  sw        $s0, 0x30($sp)
/* 31B698 802BD678 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 31B69C 802BD67C 8EB0014C */  lw        $s0, 0x14c($s5)
/* 31B6A0 802BD680 1440044C */  bnez      $v0, .L802BE7B4
/* 31B6A4 802BD684 0000102D */   daddu    $v0, $zero, $zero
/* 31B6A8 802BD688 10A00022 */  beqz      $a1, .L802BD714
/* 31B6AC 802BD68C 00000000 */   nop      
/* 31B6B0 802BD690 0C0AF57D */  jal       func_802BD5F4
/* 31B6B4 802BD694 0200202D */   daddu    $a0, $s0, $zero
/* 31B6B8 802BD698 8E820004 */  lw        $v0, 4($s4)
/* 31B6BC 802BD69C 3C030010 */  lui       $v1, 0x10
/* 31B6C0 802BD6A0 00431024 */  and       $v0, $v0, $v1
/* 31B6C4 802BD6A4 10400003 */  beqz      $v0, .L802BD6B4
/* 31B6C8 802BD6A8 00000000 */   nop      
.L802BD6AC:
/* 31B6CC 802BD6AC 080AF9ED */  j         .L802BE7B4
/* 31B6D0 802BD6B0 24020002 */   addiu    $v0, $zero, 2
.L802BD6B4:
/* 31B6D4 802BD6B4 3C02802C */  lui       $v0, 0x802c
/* 31B6D8 802BD6B8 8C42EC54 */  lw        $v0, -0x13ac($v0)
/* 31B6DC 802BD6BC 14400007 */  bnez      $v0, .L802BD6DC
/* 31B6E0 802BD6C0 00000000 */   nop      
/* 31B6E4 802BD6C4 828200B4 */  lb        $v0, 0xb4($s4)
/* 31B6E8 802BD6C8 2C420003 */  sltiu     $v0, $v0, 3
/* 31B6EC 802BD6CC 1040FFF7 */  beqz      $v0, .L802BD6AC
/* 31B6F0 802BD6D0 24020014 */   addiu    $v0, $zero, 0x14
/* 31B6F4 802BD6D4 080AF5C5 */  j         .L802BD714
/* 31B6F8 802BD6D8 AEA20070 */   sw       $v0, 0x70($s5)
.L802BD6DC:
/* 31B6FC 802BD6DC 82C20000 */  lb        $v0, ($s6)
/* 31B700 802BD6E0 1440000C */  bnez      $v0, .L802BD714
/* 31B704 802BD6E4 3C030002 */   lui      $v1, 2
/* 31B708 802BD6E8 34630009 */  ori       $v1, $v1, 9
/* 31B70C 802BD6EC 24020001 */  addiu     $v0, $zero, 1
/* 31B710 802BD6F0 A2C20000 */  sb        $v0, ($s6)
/* 31B714 802BD6F4 24020002 */  addiu     $v0, $zero, 2
/* 31B718 802BD6F8 A2C20003 */  sb        $v0, 3($s6)
/* 31B71C 802BD6FC 24020005 */  addiu     $v0, $zero, 5
/* 31B720 802BD700 AEA20070 */  sw        $v0, 0x70($s5)
/* 31B724 802BD704 2402001E */  addiu     $v0, $zero, 0x1e
/* 31B728 802BD708 AE030028 */  sw        $v1, 0x28($s0)
/* 31B72C 802BD70C 3C01802C */  lui       $at, 0x802c
/* 31B730 802BD710 AC22EC50 */  sw        $v0, -0x13b0($at)
.L802BD714:
/* 31B734 802BD714 8EA20070 */  lw        $v0, 0x70($s5)
/* 31B738 802BD718 2443FFFE */  addiu     $v1, $v0, -2
/* 31B73C 802BD71C 2C620014 */  sltiu     $v0, $v1, 0x14
/* 31B740 802BD720 1040031F */  beqz      $v0, .L802BE3A0
/* 31B744 802BD724 00031080 */   sll      $v0, $v1, 2
/* 31B748 802BD728 3C01802C */  lui       $at, 0x802c
/* 31B74C 802BD72C 00220821 */  addu      $at, $at, $v0
/* 31B750 802BD730 8C22EBC8 */  lw        $v0, -0x1438($at)
/* 31B754 802BD734 00400008 */  jr        $v0
/* 31B758 802BD738 00000000 */   nop      
/* 31B75C 802BD73C 82820015 */  lb        $v0, 0x15($s4)
/* 31B760 802BD740 1440041C */  bnez      $v0, .L802BE7B4
/* 31B764 802BD744 24020002 */   addiu    $v0, $zero, 2
/* 31B768 802BD748 868200C0 */  lh        $v0, 0xc0($s4)
/* 31B76C 802BD74C 14400419 */  bnez      $v0, .L802BE7B4
/* 31B770 802BD750 24020002 */   addiu    $v0, $zero, 2
/* 31B774 802BD754 8E020000 */  lw        $v0, ($s0)
/* 31B778 802BD758 30421000 */  andi      $v0, $v0, 0x1000
/* 31B77C 802BD75C 50400415 */  beql      $v0, $zero, .L802BE7B4
/* 31B780 802BD760 24020002 */   addiu    $v0, $zero, 2
/* 31B784 802BD764 0C03805E */  jal       disable_player_input
/* 31B788 802BD768 00000000 */   nop      
/* 31B78C 802BD76C 82820015 */  lb        $v0, 0x15($s4)
/* 31B790 802BD770 24040001 */  addiu     $a0, $zero, 1
/* 31B794 802BD774 AEA20078 */  sw        $v0, 0x78($s5)
/* 31B798 802BD778 8E020000 */  lw        $v0, ($s0)
/* 31B79C 802BD77C 2403F5F7 */  addiu     $v1, $zero, -0xa09
/* 31B7A0 802BD780 3C01802C */  lui       $at, 0x802c
/* 31B7A4 802BD784 AC24EC64 */  sw        $a0, -0x139c($at)
/* 31B7A8 802BD788 3C01802C */  lui       $at, 0x802c
/* 31B7AC 802BD78C AC20EB40 */  sw        $zero, -0x14c0($at)
/* 31B7B0 802BD790 3C01802C */  lui       $at, 0x802c
/* 31B7B4 802BD794 AC20EC6C */  sw        $zero, -0x1394($at)
/* 31B7B8 802BD798 00431024 */  and       $v0, $v0, $v1
/* 31B7BC 802BD79C 34420140 */  ori       $v0, $v0, 0x140
/* 31B7C0 802BD7A0 AE020000 */  sw        $v0, ($s0)
/* 31B7C4 802BD7A4 24020002 */  addiu     $v0, $zero, 2
/* 31B7C8 802BD7A8 A2C20003 */  sb        $v0, 3($s6)
/* 31B7CC 802BD7AC 0C03BD38 */  jal       func_800EF4E0
/* 31B7D0 802BD7B0 A2C40000 */   sb       $a0, ($s6)
/* 31B7D4 802BD7B4 3C01802C */  lui       $at, 0x802c
/* 31B7D8 802BD7B8 AC22EC58 */  sw        $v0, -0x13a8($at)
/* 31B7DC 802BD7BC 0C00EB49 */  jal       enable_npc_blur
/* 31B7E0 802BD7C0 0200202D */   daddu    $a0, $s0, $zero
/* 31B7E4 802BD7C4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 31B7E8 802BD7C8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 31B7EC 802BD7CC 24020004 */  addiu     $v0, $zero, 4
/* 31B7F0 802BD7D0 A602008E */  sh        $v0, 0x8e($s0)
/* 31B7F4 802BD7D4 8E860028 */  lw        $a2, 0x28($s4)
/* 31B7F8 802BD7D8 0C00A720 */  jal       atan2
/* 31B7FC 802BD7DC 8E870030 */   lw       $a3, 0x30($s4)
/* 31B800 802BD7E0 E600000C */  swc1      $f0, 0xc($s0)
/* 31B804 802BD7E4 8EA20070 */  lw        $v0, 0x70($s5)
/* 31B808 802BD7E8 080AF8E7 */  j         .L802BE39C
/* 31B80C 802BD7EC 24420001 */   addiu    $v0, $v0, 1
/* 31B810 802BD7F0 928200B4 */  lbu       $v0, 0xb4($s4)
/* 31B814 802BD7F4 2442FFEB */  addiu     $v0, $v0, -0x15
/* 31B818 802BD7F8 2C420003 */  sltiu     $v0, $v0, 3
/* 31B81C 802BD7FC 14400004 */  bnez      $v0, .L802BD810
/* 31B820 802BD800 3C040001 */   lui      $a0, 1
/* 31B824 802BD804 868200C0 */  lh        $v0, 0xc0($s4)
/* 31B828 802BD808 10400003 */  beqz      $v0, .L802BD818
/* 31B82C 802BD80C 00000000 */   nop      
.L802BD810:
/* 31B830 802BD810 080AF673 */  j         .L802BD9CC
/* 31B834 802BD814 34840002 */   ori      $a0, $a0, 2
.L802BD818:
/* 31B838 802BD818 0C037FBF */  jal       func_800DFEFC
/* 31B83C 802BD81C 34840006 */   ori      $a0, $a0, 6
/* 31B840 802BD820 C6840028 */  lwc1      $f4, 0x28($s4)
/* 31B844 802BD824 3C020002 */  lui       $v0, 2
/* 31B848 802BD828 E6040060 */  swc1      $f4, 0x60($s0)
/* 31B84C 802BD82C C682002C */  lwc1      $f2, 0x2c($s4)
/* 31B850 802BD830 34420005 */  ori       $v0, $v0, 5
/* 31B854 802BD834 E6020064 */  swc1      $f2, 0x64($s0)
/* 31B858 802BD838 C6800030 */  lwc1      $f0, 0x30($s4)
/* 31B85C 802BD83C 3C065555 */  lui       $a2, 0x5555
/* 31B860 802BD840 AE020028 */  sw        $v0, 0x28($s0)
/* 31B864 802BD844 E6000068 */  swc1      $f0, 0x68($s0)
/* 31B868 802BD848 968200B2 */  lhu       $v0, 0xb2($s4)
/* 31B86C 802BD84C 34C65556 */  ori       $a2, $a2, 0x5556
/* 31B870 802BD850 00021400 */  sll       $v0, $v0, 0x10
/* 31B874 802BD854 00021C03 */  sra       $v1, $v0, 0x10
/* 31B878 802BD858 00660018 */  mult      $v1, $a2
/* 31B87C 802BD85C 26040060 */  addiu     $a0, $s0, 0x60
/* 31B880 802BD860 8E870080 */  lw        $a3, 0x80($s4)
/* 31B884 802BD864 000217C3 */  sra       $v0, $v0, 0x1f
/* 31B888 802BD868 00004010 */  mfhi      $t0
/* 31B88C 802BD86C 01021023 */  subu      $v0, $t0, $v0
/* 31B890 802BD870 00021400 */  sll       $v0, $v0, 0x10
/* 31B894 802BD874 00021403 */  sra       $v0, $v0, 0x10
/* 31B898 802BD878 44828000 */  mtc1      $v0, $f16
/* 31B89C 802BD87C 00000000 */  nop       
/* 31B8A0 802BD880 46808420 */  cvt.s.w   $f16, $f16
/* 31B8A4 802BD884 44068000 */  mfc1      $a2, $f16
/* 31B8A8 802BD888 3C01802C */  lui       $at, 0x802c
/* 31B8AC 802BD88C E424EC70 */  swc1      $f4, -0x1390($at)
/* 31B8B0 802BD890 3C01802C */  lui       $at, 0x802c
/* 31B8B4 802BD894 E422EC74 */  swc1      $f2, -0x138c($at)
/* 31B8B8 802BD898 3C01802C */  lui       $at, 0x802c
/* 31B8BC 802BD89C E420EC78 */  swc1      $f0, -0x1388($at)
/* 31B8C0 802BD8A0 0C00A7E7 */  jal       add_vec2D_polar
/* 31B8C4 802BD8A4 26050068 */   addiu    $a1, $s0, 0x68
/* 31B8C8 802BD8A8 3C02802C */  lui       $v0, 0x802c
/* 31B8CC 802BD8AC 8C42EC58 */  lw        $v0, -0x13a8($v0)
/* 31B8D0 802BD8B0 C68C0080 */  lwc1      $f12, 0x80($s4)
/* 31B8D4 802BD8B4 3C01C2B4 */  lui       $at, 0xc2b4
/* 31B8D8 802BD8B8 44810000 */  mtc1      $at, $f0
/* 31B8DC 802BD8BC 10400003 */  beqz      $v0, .L802BD8CC
/* 31B8E0 802BD8C0 00000000 */   nop      
/* 31B8E4 802BD8C4 3C0142B4 */  lui       $at, 0x42b4
/* 31B8E8 802BD8C8 44810000 */  mtc1      $at, $f0
.L802BD8CC:
/* 31B8EC 802BD8CC 0C00A6C9 */  jal       clamp_angle
/* 31B8F0 802BD8D0 46006300 */   add.s    $f12, $f12, $f0
/* 31B8F4 802BD8D4 868200B2 */  lh        $v0, 0xb2($s4)
/* 31B8F8 802BD8D8 26040060 */  addiu     $a0, $s0, 0x60
/* 31B8FC 802BD8DC 04410002 */  bgez      $v0, .L802BD8E8
/* 31B900 802BD8E0 26050068 */   addiu    $a1, $s0, 0x68
/* 31B904 802BD8E4 24420003 */  addiu     $v0, $v0, 3
.L802BD8E8:
/* 31B908 802BD8E8 00021083 */  sra       $v0, $v0, 2
/* 31B90C 802BD8EC 44828000 */  mtc1      $v0, $f16
/* 31B910 802BD8F0 00000000 */  nop       
/* 31B914 802BD8F4 46808420 */  cvt.s.w   $f16, $f16
/* 31B918 802BD8F8 44070000 */  mfc1      $a3, $f0
/* 31B91C 802BD8FC 44068000 */  mfc1      $a2, $f16
/* 31B920 802BD900 0C00A7E7 */  jal       add_vec2D_polar
/* 31B924 802BD904 00000000 */   nop      
/* 31B928 802BD908 C6000060 */  lwc1      $f0, 0x60($s0)
/* 31B92C 802BD90C C60A0038 */  lwc1      $f10, 0x38($s0)
/* 31B930 802BD910 8602008E */  lh        $v0, 0x8e($s0)
/* 31B934 802BD914 C6040064 */  lwc1      $f4, 0x64($s0)
/* 31B938 802BD918 C608003C */  lwc1      $f8, 0x3c($s0)
/* 31B93C 802BD91C C6060040 */  lwc1      $f6, 0x40($s0)
/* 31B940 802BD920 44821000 */  mtc1      $v0, $f2
/* 31B944 802BD924 00000000 */  nop       
/* 31B948 802BD928 468010A0 */  cvt.s.w   $f2, $f2
/* 31B94C 802BD92C 0040202D */  daddu     $a0, $v0, $zero
/* 31B950 802BD930 460A0001 */  sub.s     $f0, $f0, $f10
/* 31B954 802BD934 0080182D */  daddu     $v1, $a0, $zero
/* 31B958 802BD938 9602008E */  lhu       $v0, 0x8e($s0)
/* 31B95C 802BD93C 46082101 */  sub.s     $f4, $f4, $f8
/* 31B960 802BD940 2442FFFF */  addiu     $v0, $v0, -1
/* 31B964 802BD944 A602008E */  sh        $v0, 0x8e($s0)
/* 31B968 802BD948 46020003 */  div.s     $f0, $f0, $f2
/* 31B96C 802BD94C 46005280 */  add.s     $f10, $f10, $f0
/* 31B970 802BD950 C6020068 */  lwc1      $f2, 0x68($s0)
/* 31B974 802BD954 00021400 */  sll       $v0, $v0, 0x10
/* 31B978 802BD958 46061081 */  sub.s     $f2, $f2, $f6
/* 31B97C 802BD95C 44840000 */  mtc1      $a0, $f0
/* 31B980 802BD960 00000000 */  nop       
/* 31B984 802BD964 46800020 */  cvt.s.w   $f0, $f0
/* 31B988 802BD968 46002103 */  div.s     $f4, $f4, $f0
/* 31B98C 802BD96C 46044200 */  add.s     $f8, $f8, $f4
/* 31B990 802BD970 44830000 */  mtc1      $v1, $f0
/* 31B994 802BD974 00000000 */  nop       
/* 31B998 802BD978 46800020 */  cvt.s.w   $f0, $f0
/* 31B99C 802BD97C 46001083 */  div.s     $f2, $f2, $f0
/* 31B9A0 802BD980 46023180 */  add.s     $f6, $f6, $f2
/* 31B9A4 802BD984 E60A0038 */  swc1      $f10, 0x38($s0)
/* 31B9A8 802BD988 E608003C */  swc1      $f8, 0x3c($s0)
/* 31B9AC 802BD98C 14400284 */  bnez      $v0, .L802BE3A0
/* 31B9B0 802BD990 E6060040 */   swc1     $f6, 0x40($s0)
/* 31B9B4 802BD994 0C00EB6B */  jal       disable_npc_blur
/* 31B9B8 802BD998 0200202D */   daddu    $a0, $s0, $zero
/* 31B9BC 802BD99C 82830015 */  lb        $v1, 0x15($s4)
/* 31B9C0 802BD9A0 8EA20078 */  lw        $v0, 0x78($s5)
/* 31B9C4 802BD9A4 0043102A */  slt       $v0, $v0, $v1
/* 31B9C8 802BD9A8 1040000C */  beqz      $v0, .L802BD9DC
/* 31B9CC 802BD9AC 3C030010 */   lui      $v1, 0x10
/* 31B9D0 802BD9B0 8E820004 */  lw        $v0, 4($s4)
/* 31B9D4 802BD9B4 00431024 */  and       $v0, $v0, $v1
/* 31B9D8 802BD9B8 14400003 */  bnez      $v0, .L802BD9C8
/* 31B9DC 802BD9BC 3C040001 */   lui      $a0, 1
/* 31B9E0 802BD9C0 080AF673 */  j         .L802BD9CC
/* 31B9E4 802BD9C4 34840002 */   ori      $a0, $a0, 2
.L802BD9C8:
/* 31B9E8 802BD9C8 34840005 */  ori       $a0, $a0, 5
.L802BD9CC:
/* 31B9EC 802BD9CC 0C037FBF */  jal       func_800DFEFC
/* 31B9F0 802BD9D0 00000000 */   nop      
/* 31B9F4 802BD9D4 080AF8E8 */  j         .L802BE3A0
/* 31B9F8 802BD9D8 AEA00070 */   sw       $zero, 0x70($s5)
.L802BD9DC:
/* 31B9FC 802BD9DC 3C020002 */  lui       $v0, 2
/* 31BA00 802BD9E0 C6840080 */  lwc1      $f4, 0x80($s4)
/* 31BA04 802BD9E4 3C014190 */  lui       $at, 0x4190
/* 31BA08 802BD9E8 44810000 */  mtc1      $at, $f0
/* 31BA0C 802BD9EC 3C014040 */  lui       $at, 0x4040
/* 31BA10 802BD9F0 44811000 */  mtc1      $at, $f2
/* 31BA14 802BD9F4 3442000A */  ori       $v0, $v0, 0xa
/* 31BA18 802BD9F8 AE020028 */  sw        $v0, 0x28($s0)
/* 31BA1C 802BD9FC 2402000C */  addiu     $v0, $zero, 0xc
/* 31BA20 802BDA00 A60200A8 */  sh        $v0, 0xa8($s0)
/* 31BA24 802BDA04 E604000C */  swc1      $f4, 0xc($s0)
/* 31BA28 802BDA08 E600001C */  swc1      $f0, 0x1c($s0)
/* 31BA2C 802BDA0C E6020014 */  swc1      $f2, 0x14($s0)
/* 31BA30 802BDA10 C680002C */  lwc1      $f0, 0x2c($s4)
/* 31BA34 802BDA14 3C045555 */  lui       $a0, 0x5555
/* 31BA38 802BDA18 E6000064 */  swc1      $f0, 0x64($s0)
/* 31BA3C 802BDA1C 968200B0 */  lhu       $v0, 0xb0($s4)
/* 31BA40 802BDA20 34845556 */  ori       $a0, $a0, 0x5556
/* 31BA44 802BDA24 00021400 */  sll       $v0, $v0, 0x10
/* 31BA48 802BDA28 00021C03 */  sra       $v1, $v0, 0x10
/* 31BA4C 802BDA2C 00640018 */  mult      $v1, $a0
/* 31BA50 802BDA30 3C05800B */  lui       $a1, %hi(gCameras)
/* 31BA54 802BDA34 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 31BA58 802BDA38 C682002C */  lwc1      $f2, 0x2c($s4)
/* 31BA5C 802BDA3C 000217C3 */  sra       $v0, $v0, 0x1f
/* 31BA60 802BDA40 00004010 */  mfhi      $t0
/* 31BA64 802BDA44 01021023 */  subu      $v0, $t0, $v0
/* 31BA68 802BDA48 00021400 */  sll       $v0, $v0, 0x10
/* 31BA6C 802BDA4C 00021403 */  sra       $v0, $v0, 0x10
/* 31BA70 802BDA50 44820000 */  mtc1      $v0, $f0
/* 31BA74 802BDA54 00000000 */  nop       
/* 31BA78 802BDA58 46800020 */  cvt.s.w   $f0, $f0
/* 31BA7C 802BDA5C 46001080 */  add.s     $f2, $f2, $f0
/* 31BA80 802BDA60 3C040001 */  lui       $a0, 1
/* 31BA84 802BDA64 34840007 */  ori       $a0, $a0, 7
/* 31BA88 802BDA68 E6020068 */  swc1      $f2, 0x68($s0)
/* 31BA8C 802BDA6C 8E820000 */  lw        $v0, ($s4)
/* 31BA90 802BDA70 94A30002 */  lhu       $v1, 2($a1)
/* 31BA94 802BDA74 34420002 */  ori       $v0, $v0, 2
/* 31BA98 802BDA78 34630001 */  ori       $v1, $v1, 1
/* 31BA9C 802BDA7C AE820000 */  sw        $v0, ($s4)
/* 31BAA0 802BDA80 0C037FBF */  jal       func_800DFEFC
/* 31BAA4 802BDA84 A4A30002 */   sh       $v1, 2($a1)
/* 31BAA8 802BDA88 24042081 */  addiu     $a0, $zero, 0x2081
/* 31BAAC 802BDA8C 0000282D */  daddu     $a1, $zero, $zero
/* 31BAB0 802BDA90 3C01802C */  lui       $at, 0x802c
/* 31BAB4 802BDA94 AC20EC60 */  sw        $zero, -0x13a0($at)
/* 31BAB8 802BDA98 0C052742 */  jal       play_sound_at_npc
/* 31BABC 802BDA9C 2406FFFC */   addiu    $a2, $zero, -4
/* 31BAC0 802BDAA0 24020002 */  addiu     $v0, $zero, 2
/* 31BAC4 802BDAA4 AEA20070 */  sw        $v0, 0x70($s5)
/* 31BAC8 802BDAA8 928200B4 */  lbu       $v0, 0xb4($s4)
/* 31BACC 802BDAAC 2442FFEB */  addiu     $v0, $v0, -0x15
/* 31BAD0 802BDAB0 2C420003 */  sltiu     $v0, $v0, 3
/* 31BAD4 802BDAB4 5440023A */  bnel      $v0, $zero, .L802BE3A0
/* 31BAD8 802BDAB8 AEA00070 */   sw       $zero, 0x70($s5)
/* 31BADC 802BDABC C602001C */  lwc1      $f2, 0x1c($s0)
/* 31BAE0 802BDAC0 C6000014 */  lwc1      $f0, 0x14($s0)
/* 31BAE4 802BDAC4 46001081 */  sub.s     $f2, $f2, $f0
/* 31BAE8 802BDAC8 E602001C */  swc1      $f2, 0x1c($s0)
/* 31BAEC 802BDACC C680002C */  lwc1      $f0, 0x2c($s4)
/* 31BAF0 802BDAD0 46020000 */  add.s     $f0, $f0, $f2
/* 31BAF4 802BDAD4 E680002C */  swc1      $f0, 0x2c($s4)
/* 31BAF8 802BDAD8 C602001C */  lwc1      $f2, 0x1c($s0)
/* 31BAFC 802BDADC 44800000 */  mtc1      $zero, $f0
/* 31BB00 802BDAE0 00000000 */  nop       
/* 31BB04 802BDAE4 4600103C */  c.lt.s    $f2, $f0
/* 31BB08 802BDAE8 00000000 */  nop       
/* 31BB0C 802BDAEC 4500000C */  bc1f      .L802BDB20
/* 31BB10 802BDAF0 3C040001 */   lui      $a0, 1
/* 31BB14 802BDAF4 3C03802C */  lui       $v1, 0x802c
/* 31BB18 802BDAF8 2463EC60 */  addiu     $v1, $v1, -0x13a0
/* 31BB1C 802BDAFC 8C620000 */  lw        $v0, ($v1)
/* 31BB20 802BDB00 14400008 */  bnez      $v0, .L802BDB24
/* 31BB24 802BDB04 27A50020 */   addiu    $a1, $sp, 0x20
/* 31BB28 802BDB08 24020001 */  addiu     $v0, $zero, 1
/* 31BB2C 802BDB0C AC620000 */  sw        $v0, ($v1)
/* 31BB30 802BDB10 3C040001 */  lui       $a0, 1
/* 31BB34 802BDB14 0C037FBF */  jal       func_800DFEFC
/* 31BB38 802BDB18 34840008 */   ori      $a0, $a0, 8
/* 31BB3C 802BDB1C 3C040001 */  lui       $a0, 1
.L802BDB20:
/* 31BB40 802BDB20 27A50020 */  addiu     $a1, $sp, 0x20
.L802BDB24:
/* 31BB44 802BDB24 27A60024 */  addiu     $a2, $sp, 0x24
/* 31BB48 802BDB28 27A70028 */  addiu     $a3, $sp, 0x28
/* 31BB4C 802BDB2C 968300B0 */  lhu       $v1, 0xb0($s4)
/* 31BB50 802BDB30 C6820028 */  lwc1      $f2, 0x28($s4)
/* 31BB54 802BDB34 00031C00 */  sll       $v1, $v1, 0x10
/* 31BB58 802BDB38 00031403 */  sra       $v0, $v1, 0x10
/* 31BB5C 802BDB3C 00031FC2 */  srl       $v1, $v1, 0x1f
/* 31BB60 802BDB40 00431021 */  addu      $v0, $v0, $v1
/* 31BB64 802BDB44 00021043 */  sra       $v0, $v0, 1
/* 31BB68 802BDB48 44820000 */  mtc1      $v0, $f0
/* 31BB6C 802BDB4C 00000000 */  nop       
/* 31BB70 802BDB50 46800020 */  cvt.s.w   $f0, $f0
/* 31BB74 802BDB54 968300B0 */  lhu       $v1, 0xb0($s4)
/* 31BB78 802BDB58 46000506 */  mov.s     $f20, $f0
/* 31BB7C 802BDB5C E7A20020 */  swc1      $f2, 0x20($sp)
/* 31BB80 802BDB60 C682002C */  lwc1      $f2, 0x2c($s4)
/* 31BB84 802BDB64 C6840030 */  lwc1      $f4, 0x30($s4)
/* 31BB88 802BDB68 00031C00 */  sll       $v1, $v1, 0x10
/* 31BB8C 802BDB6C 00031403 */  sra       $v0, $v1, 0x10
/* 31BB90 802BDB70 00031FC2 */  srl       $v1, $v1, 0x1f
/* 31BB94 802BDB74 00431021 */  addu      $v0, $v0, $v1
/* 31BB98 802BDB78 00021043 */  sra       $v0, $v0, 1
/* 31BB9C 802BDB7C 44820000 */  mtc1      $v0, $f0
/* 31BBA0 802BDB80 00000000 */  nop       
/* 31BBA4 802BDB84 46800020 */  cvt.s.w   $f0, $f0
/* 31BBA8 802BDB88 46001080 */  add.s     $f2, $f2, $f0
/* 31BBAC 802BDB8C C600001C */  lwc1      $f0, 0x1c($s0)
/* 31BBB0 802BDB90 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31BBB4 802BDB94 46001081 */  sub.s     $f2, $f2, $f0
/* 31BBB8 802BDB98 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31BBBC 802BDB9C E7B4002C */  swc1      $f20, 0x2c($sp)
/* 31BBC0 802BDBA0 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31BBC4 802BDBA4 0C03739C */  jal       func_800DCE70
/* 31BBC8 802BDBA8 AFA20010 */   sw       $v0, 0x10($sp)
/* 31BBCC 802BDBAC 10400013 */  beqz      $v0, .L802BDBFC
/* 31BBD0 802BDBB0 00000000 */   nop      
/* 31BBD4 802BDBB4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 31BBD8 802BDBB8 4614003C */  c.lt.s    $f0, $f20
/* 31BBDC 802BDBBC 00000000 */  nop       
/* 31BBE0 802BDBC0 4500000E */  bc1f      .L802BDBFC
/* 31BBE4 802BDBC4 0200202D */   daddu    $a0, $s0, $zero
/* 31BBE8 802BDBC8 868200B0 */  lh        $v0, 0xb0($s4)
/* 31BBEC 802BDBCC C7A20024 */  lwc1      $f2, 0x24($sp)
/* 31BBF0 802BDBD0 3C038011 */  lui       $v1, 0x8011
/* 31BBF4 802BDBD4 9463C97A */  lhu       $v1, -0x3686($v1)
/* 31BBF8 802BDBD8 44820000 */  mtc1      $v0, $f0
/* 31BBFC 802BDBDC 00000000 */  nop       
/* 31BC00 802BDBE0 46800020 */  cvt.s.w   $f0, $f0
/* 31BC04 802BDBE4 46001081 */  sub.s     $f2, $f2, $f0
/* 31BC08 802BDBE8 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* 31BC0C 802BDBEC 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* 31BC10 802BDBF0 A4430008 */  sh        $v1, 8($v0)
/* 31BC14 802BDBF4 0C0AF451 */  jal       func_802BD144
/* 31BC18 802BDBF8 E682002C */   swc1     $f2, 0x2c($s4)
.L802BDBFC:
/* 31BC1C 802BDBFC C600001C */  lwc1      $f0, 0x1c($s0)
/* 31BC20 802BDC00 44802000 */  mtc1      $zero, $f4
/* 31BC24 802BDC04 00000000 */  nop       
/* 31BC28 802BDC08 4600203C */  c.lt.s    $f4, $f0
/* 31BC2C 802BDC0C 00000000 */  nop       
/* 31BC30 802BDC10 450101E3 */  bc1t      .L802BE3A0
/* 31BC34 802BDC14 00000000 */   nop      
/* 31BC38 802BDC18 C682002C */  lwc1      $f2, 0x2c($s4)
/* 31BC3C 802BDC1C C6000068 */  lwc1      $f0, 0x68($s0)
/* 31BC40 802BDC20 4600103C */  c.lt.s    $f2, $f0
/* 31BC44 802BDC24 00000000 */  nop       
/* 31BC48 802BDC28 450001DD */  bc1f      .L802BE3A0
/* 31BC4C 802BDC2C 3C040002 */   lui      $a0, 2
/* 31BC50 802BDC30 34840009 */  ori       $a0, $a0, 9
/* 31BC54 802BDC34 8E020000 */  lw        $v0, ($s0)
/* 31BC58 802BDC38 3C014100 */  lui       $at, 0x4100
/* 31BC5C 802BDC3C 44810000 */  mtc1      $at, $f0
/* 31BC60 802BDC40 2403FEFF */  addiu     $v1, $zero, -0x101
/* 31BC64 802BDC44 3C01802C */  lui       $at, 0x802c
/* 31BC68 802BDC48 AC20EC5C */  sw        $zero, -0x13a4($at)
/* 31BC6C 802BDC4C 00431024 */  and       $v0, $v0, $v1
/* 31BC70 802BDC50 AE020000 */  sw        $v0, ($s0)
/* 31BC74 802BDC54 24020002 */  addiu     $v0, $zero, 2
/* 31BC78 802BDC58 A2C20003 */  sb        $v0, 3($s6)
/* 31BC7C 802BDC5C A2C20000 */  sb        $v0, ($s6)
/* 31BC80 802BDC60 E604004C */  swc1      $f4, 0x4c($s0)
/* 31BC84 802BDC64 E6040010 */  swc1      $f4, 0x10($s0)
/* 31BC88 802BDC68 E6000018 */  swc1      $f0, 0x18($s0)
/* 31BC8C 802BDC6C AE040028 */  sw        $a0, 0x28($s0)
/* 31BC90 802BDC70 C68C0080 */  lwc1      $f12, 0x80($s4)
/* 31BC94 802BDC74 24020001 */  addiu     $v0, $zero, 1
/* 31BC98 802BDC78 3C01802C */  lui       $at, 0x802c
/* 31BC9C 802BDC7C AC22EB40 */  sw        $v0, -0x14c0($at)
/* 31BCA0 802BDC80 0C00A8BB */  jal       sin_deg
/* 31BCA4 802BDC84 24120003 */   addiu    $s2, $zero, 3
/* 31BCA8 802BDC88 C68C0080 */  lwc1      $f12, 0x80($s4)
/* 31BCAC 802BDC8C 0C00A8D4 */  jal       cos_deg
/* 31BCB0 802BDC90 46000506 */   mov.s    $f20, $f0
/* 31BCB4 802BDC94 860200A8 */  lh        $v0, 0xa8($s0)
/* 31BCB8 802BDC98 C604003C */  lwc1      $f4, 0x3c($s0)
/* 31BCBC 802BDC9C 3C01BF80 */  lui       $at, 0xbf80
/* 31BCC0 802BDCA0 44811000 */  mtc1      $at, $f2
/* 31BCC4 802BDCA4 46000007 */  neg.s     $f0, $f0
/* 31BCC8 802BDCA8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 31BCCC 802BDCAC E7A00018 */  swc1      $f0, 0x18($sp)
/* 31BCD0 802BDCB0 AFB2001C */  sw        $s2, 0x1c($sp)
/* 31BCD4 802BDCB4 44820000 */  mtc1      $v0, $f0
/* 31BCD8 802BDCB8 00000000 */  nop       
/* 31BCDC 802BDCBC 46800020 */  cvt.s.w   $f0, $f0
/* 31BCE0 802BDCC0 46002100 */  add.s     $f4, $f4, $f0
/* 31BCE4 802BDCC4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 31BCE8 802BDCC8 8E050038 */  lw        $a1, 0x38($s0)
/* 31BCEC 802BDCCC 8E070040 */  lw        $a3, 0x40($s0)
/* 31BCF0 802BDCD0 44062000 */  mfc1      $a2, $f4
/* 31BCF4 802BDCD4 0C01C064 */  jal       func_80070190
/* 31BCF8 802BDCD8 0240202D */   daddu    $a0, $s2, $zero
/* 31BCFC 802BDCDC 0C039823 */  jal       start_bounce_b
/* 31BD00 802BDCE0 00000000 */   nop      
/* 31BD04 802BDCE4 3C11802C */  lui       $s1, 0x802c
/* 31BD08 802BDCE8 2631EC64 */  addiu     $s1, $s1, -0x139c
/* 31BD0C 802BDCEC 8E220000 */  lw        $v0, ($s1)
/* 31BD10 802BDCF0 10400005 */  beqz      $v0, .L802BDD08
/* 31BD14 802BDCF4 24040283 */   addiu    $a0, $zero, 0x283
/* 31BD18 802BDCF8 0C038069 */  jal       enable_player_input
/* 31BD1C 802BDCFC 00000000 */   nop      
/* 31BD20 802BDD00 AE200000 */  sw        $zero, ($s1)
/* 31BD24 802BDD04 24040283 */  addiu     $a0, $zero, 0x283
.L802BDD08:
/* 31BD28 802BDD08 0000282D */  daddu     $a1, $zero, $zero
/* 31BD2C 802BDD0C 3C03800B */  lui       $v1, %hi(gCameras)
/* 31BD30 802BDD10 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 31BD34 802BDD14 AEB20070 */  sw        $s2, 0x70($s5)
/* 31BD38 802BDD18 94620002 */  lhu       $v0, 2($v1)
/* 31BD3C 802BDD1C 2406FFFC */  addiu     $a2, $zero, -4
/* 31BD40 802BDD20 3C01802C */  lui       $at, 0x802c
/* 31BD44 802BDD24 AC20EC60 */  sw        $zero, -0x13a0($at)
/* 31BD48 802BDD28 34420001 */  ori       $v0, $v0, 1
/* 31BD4C 802BDD2C 0C052742 */  jal       play_sound_at_npc
/* 31BD50 802BDD30 A4620002 */   sh       $v0, 2($v1)
/* 31BD54 802BDD34 24040284 */  addiu     $a0, $zero, 0x284
/* 31BD58 802BDD38 0000282D */  daddu     $a1, $zero, $zero
/* 31BD5C 802BDD3C 0C052742 */  jal       play_sound_at_npc
/* 31BD60 802BDD40 2406FFFC */   addiu    $a2, $zero, -4
/* 31BD64 802BDD44 080AF8E8 */  j         .L802BE3A0
/* 31BD68 802BDD48 00000000 */   nop      
/* 31BD6C 802BDD4C 928200B4 */  lbu       $v0, 0xb4($s4)
/* 31BD70 802BDD50 2442FFEB */  addiu     $v0, $v0, -0x15
/* 31BD74 802BDD54 2C420002 */  sltiu     $v0, $v0, 2
/* 31BD78 802BDD58 54400191 */  bnel      $v0, $zero, .L802BE3A0
/* 31BD7C 802BDD5C AEA00070 */   sw       $zero, 0x70($s5)
/* 31BD80 802BDD60 34048000 */  ori       $a0, $zero, 0x8000
/* 31BD84 802BDD64 C6000038 */  lwc1      $f0, 0x38($s0)
/* 31BD88 802BDD68 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31BD8C 802BDD6C C6040040 */  lwc1      $f4, 0x40($s0)
/* 31BD90 802BDD70 C6060018 */  lwc1      $f6, 0x18($s0)
/* 31BD94 802BDD74 3C0141A0 */  lui       $at, 0x41a0
/* 31BD98 802BDD78 4481A000 */  mtc1      $at, $f20
/* 31BD9C 802BDD7C 27B20020 */  addiu     $s2, $sp, 0x20
/* 31BDA0 802BDD80 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31BDA4 802BDD84 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31BDA8 802BDD88 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31BDAC 802BDD8C E7A60010 */  swc1      $f6, 0x10($sp)
/* 31BDB0 802BDD90 C600000C */  lwc1      $f0, 0xc($s0)
/* 31BDB4 802BDD94 0240282D */  daddu     $a1, $s2, $zero
/* 31BDB8 802BDD98 46140001 */  sub.s     $f0, $f0, $f20
/* 31BDBC 802BDD9C 27B30024 */  addiu     $s3, $sp, 0x24
/* 31BDC0 802BDDA0 0260302D */  daddu     $a2, $s3, $zero
/* 31BDC4 802BDDA4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31BDC8 802BDDA8 860200A8 */  lh        $v0, 0xa8($s0)
/* 31BDCC 802BDDAC 27B10028 */  addiu     $s1, $sp, 0x28
/* 31BDD0 802BDDB0 44820000 */  mtc1      $v0, $f0
/* 31BDD4 802BDDB4 00000000 */  nop       
/* 31BDD8 802BDDB8 46800020 */  cvt.s.w   $f0, $f0
/* 31BDDC 802BDDBC E7A00018 */  swc1      $f0, 0x18($sp)
/* 31BDE0 802BDDC0 960300A6 */  lhu       $v1, 0xa6($s0)
/* 31BDE4 802BDDC4 0220382D */  daddu     $a3, $s1, $zero
/* 31BDE8 802BDDC8 00031C00 */  sll       $v1, $v1, 0x10
/* 31BDEC 802BDDCC 00031403 */  sra       $v0, $v1, 0x10
/* 31BDF0 802BDDD0 00031FC2 */  srl       $v1, $v1, 0x1f
/* 31BDF4 802BDDD4 00431021 */  addu      $v0, $v0, $v1
/* 31BDF8 802BDDD8 00021043 */  sra       $v0, $v0, 1
/* 31BDFC 802BDDDC 44820000 */  mtc1      $v0, $f0
/* 31BE00 802BDDE0 00000000 */  nop       
/* 31BE04 802BDDE4 46800020 */  cvt.s.w   $f0, $f0
/* 31BE08 802BDDE8 0C0376B9 */  jal       func_800DDAE4
/* 31BE0C 802BDDEC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31BE10 802BDDF0 10400027 */  beqz      $v0, .L802BDE90
/* 31BE14 802BDDF4 34048000 */   ori      $a0, $zero, 0x8000
.L802BDDF8:
/* 31BE18 802BDDF8 0C0AF440 */  jal       func_802BD100
/* 31BE1C 802BDDFC 0200202D */   daddu    $a0, $s0, $zero
/* 31BE20 802BDE00 14400004 */  bnez      $v0, .L802BDE14
/* 31BE24 802BDE04 2404010C */   addiu    $a0, $zero, 0x10c
/* 31BE28 802BDE08 0000282D */  daddu     $a1, $zero, $zero
/* 31BE2C 802BDE0C 0C052742 */  jal       play_sound_at_npc
/* 31BE30 802BDE10 2406FFFC */   addiu    $a2, $zero, -4
.L802BDE14:
/* 31BE34 802BDE14 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31BE38 802BDE18 0C00A8BB */  jal       sin_deg
/* 31BE3C 802BDE1C 00000000 */   nop      
/* 31BE40 802BDE20 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31BE44 802BDE24 0C00A8D4 */  jal       cos_deg
/* 31BE48 802BDE28 46000506 */   mov.s    $f20, $f0
/* 31BE4C 802BDE2C 24020001 */  addiu     $v0, $zero, 1
/* 31BE50 802BDE30 860300A8 */  lh        $v1, 0xa8($s0)
/* 31BE54 802BDE34 C604003C */  lwc1      $f4, 0x3c($s0)
/* 31BE58 802BDE38 3C01BF80 */  lui       $at, 0xbf80
/* 31BE5C 802BDE3C 44811000 */  mtc1      $at, $f2
/* 31BE60 802BDE40 46000007 */  neg.s     $f0, $f0
/* 31BE64 802BDE44 E7B40010 */  swc1      $f20, 0x10($sp)
/* 31BE68 802BDE48 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31BE6C 802BDE4C AFA2001C */  sw        $v0, 0x1c($sp)
/* 31BE70 802BDE50 44830000 */  mtc1      $v1, $f0
/* 31BE74 802BDE54 00000000 */  nop       
/* 31BE78 802BDE58 46800020 */  cvt.s.w   $f0, $f0
/* 31BE7C 802BDE5C 46002100 */  add.s     $f4, $f4, $f0
/* 31BE80 802BDE60 E7A20014 */  swc1      $f2, 0x14($sp)
/* 31BE84 802BDE64 8E050038 */  lw        $a1, 0x38($s0)
/* 31BE88 802BDE68 8E070040 */  lw        $a3, 0x40($s0)
/* 31BE8C 802BDE6C 44062000 */  mfc1      $a2, $f4
/* 31BE90 802BDE70 0C01C064 */  jal       func_80070190
/* 31BE94 802BDE74 24040003 */   addiu    $a0, $zero, 3
/* 31BE98 802BDE78 0000202D */  daddu     $a0, $zero, $zero
/* 31BE9C 802BDE7C 0080282D */  daddu     $a1, $a0, $zero
/* 31BEA0 802BDE80 0C052742 */  jal       play_sound_at_npc
/* 31BEA4 802BDE84 2406FFFC */   addiu    $a2, $zero, -4
/* 31BEA8 802BDE88 080AF8E7 */  j         .L802BE39C
/* 31BEAC 802BDE8C 24020007 */   addiu    $v0, $zero, 7
.L802BDE90:
/* 31BEB0 802BDE90 C6000038 */  lwc1      $f0, 0x38($s0)
/* 31BEB4 802BDE94 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31BEB8 802BDE98 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31BEBC 802BDE9C C6060018 */  lwc1      $f6, 0x18($s0)
/* 31BEC0 802BDEA0 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31BEC4 802BDEA4 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31BEC8 802BDEA8 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31BECC 802BDEAC E7A60010 */  swc1      $f6, 0x10($sp)
/* 31BED0 802BDEB0 C600000C */  lwc1      $f0, 0xc($s0)
/* 31BED4 802BDEB4 46140000 */  add.s     $f0, $f0, $f20
/* 31BED8 802BDEB8 0240282D */  daddu     $a1, $s2, $zero
/* 31BEDC 802BDEBC E7A00014 */  swc1      $f0, 0x14($sp)
/* 31BEE0 802BDEC0 860200A8 */  lh        $v0, 0xa8($s0)
/* 31BEE4 802BDEC4 0260302D */  daddu     $a2, $s3, $zero
/* 31BEE8 802BDEC8 44820000 */  mtc1      $v0, $f0
/* 31BEEC 802BDECC 00000000 */  nop       
/* 31BEF0 802BDED0 46800020 */  cvt.s.w   $f0, $f0
/* 31BEF4 802BDED4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31BEF8 802BDED8 960300A6 */  lhu       $v1, 0xa6($s0)
/* 31BEFC 802BDEDC 0220382D */  daddu     $a3, $s1, $zero
/* 31BF00 802BDEE0 00031C00 */  sll       $v1, $v1, 0x10
/* 31BF04 802BDEE4 00031403 */  sra       $v0, $v1, 0x10
/* 31BF08 802BDEE8 00031FC2 */  srl       $v1, $v1, 0x1f
/* 31BF0C 802BDEEC 00431021 */  addu      $v0, $v0, $v1
/* 31BF10 802BDEF0 00021043 */  sra       $v0, $v0, 1
/* 31BF14 802BDEF4 44820000 */  mtc1      $v0, $f0
/* 31BF18 802BDEF8 00000000 */  nop       
/* 31BF1C 802BDEFC 46800020 */  cvt.s.w   $f0, $f0
/* 31BF20 802BDF00 0C0376B9 */  jal       func_800DDAE4
/* 31BF24 802BDF04 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31BF28 802BDF08 1440FFBB */  bnez      $v0, .L802BDDF8
/* 31BF2C 802BDF0C 34048000 */   ori      $a0, $zero, 0x8000
/* 31BF30 802BDF10 C6000038 */  lwc1      $f0, 0x38($s0)
/* 31BF34 802BDF14 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31BF38 802BDF18 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31BF3C 802BDF1C C6060018 */  lwc1      $f6, 0x18($s0)
/* 31BF40 802BDF20 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31BF44 802BDF24 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31BF48 802BDF28 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31BF4C 802BDF2C E7A60010 */  swc1      $f6, 0x10($sp)
/* 31BF50 802BDF30 C600000C */  lwc1      $f0, 0xc($s0)
/* 31BF54 802BDF34 0240282D */  daddu     $a1, $s2, $zero
/* 31BF58 802BDF38 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31BF5C 802BDF3C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31BF60 802BDF40 0260302D */  daddu     $a2, $s3, $zero
/* 31BF64 802BDF44 44820000 */  mtc1      $v0, $f0
/* 31BF68 802BDF48 00000000 */  nop       
/* 31BF6C 802BDF4C 46800020 */  cvt.s.w   $f0, $f0
/* 31BF70 802BDF50 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31BF74 802BDF54 960300A6 */  lhu       $v1, 0xa6($s0)
/* 31BF78 802BDF58 0220382D */  daddu     $a3, $s1, $zero
/* 31BF7C 802BDF5C 00031C00 */  sll       $v1, $v1, 0x10
/* 31BF80 802BDF60 00031403 */  sra       $v0, $v1, 0x10
/* 31BF84 802BDF64 00031FC2 */  srl       $v1, $v1, 0x1f
/* 31BF88 802BDF68 00431021 */  addu      $v0, $v0, $v1
/* 31BF8C 802BDF6C 00021043 */  sra       $v0, $v0, 1
/* 31BF90 802BDF70 44820000 */  mtc1      $v0, $f0
/* 31BF94 802BDF74 00000000 */  nop       
/* 31BF98 802BDF78 46800020 */  cvt.s.w   $f0, $f0
/* 31BF9C 802BDF7C 0C0376B9 */  jal       func_800DDAE4
/* 31BFA0 802BDF80 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31BFA4 802BDF84 1440FF9C */  bnez      $v0, .L802BDDF8
/* 31BFA8 802BDF88 0200202D */   daddu    $a0, $s0, $zero
/* 31BFAC 802BDF8C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 31BFB0 802BDF90 C6020018 */  lwc1      $f2, 0x18($s0)
/* 31BFB4 802BDF94 24050001 */  addiu     $a1, $zero, 1
/* 31BFB8 802BDF98 E6000038 */  swc1      $f0, 0x38($s0)
/* 31BFBC 802BDF9C C7A60024 */  lwc1      $f6, 0x24($sp)
/* 31BFC0 802BDFA0 C6000010 */  lwc1      $f0, 0x10($s0)
/* 31BFC4 802BDFA4 C7A40028 */  lwc1      $f4, 0x28($sp)
/* 31BFC8 802BDFA8 46020000 */  add.s     $f0, $f0, $f2
/* 31BFCC 802BDFAC E606003C */  swc1      $f6, 0x3c($s0)
/* 31BFD0 802BDFB0 E6040040 */  swc1      $f4, 0x40($s0)
/* 31BFD4 802BDFB4 0C00F598 */  jal       func_8003D660
/* 31BFD8 802BDFB8 E6000010 */   swc1     $f0, 0x10($s0)
/* 31BFDC 802BDFBC C6000018 */  lwc1      $f0, 0x18($s0)
/* 31BFE0 802BDFC0 3C014000 */  lui       $at, 0x4000
/* 31BFE4 802BDFC4 44811800 */  mtc1      $at, $f3
/* 31BFE8 802BDFC8 44801000 */  mtc1      $zero, $f2
/* 31BFEC 802BDFCC 46000021 */  cvt.d.s   $f0, $f0
/* 31BFF0 802BDFD0 46220000 */  add.d     $f0, $f0, $f2
/* 31BFF4 802BDFD4 3C01402C */  lui       $at, 0x402c
/* 31BFF8 802BDFD8 44812800 */  mtc1      $at, $f5
/* 31BFFC 802BDFDC 44802000 */  mtc1      $zero, $f4
/* 31C000 802BDFE0 46200020 */  cvt.s.d   $f0, $f0
/* 31C004 802BDFE4 460000A1 */  cvt.d.s   $f2, $f0
/* 31C008 802BDFE8 4622203C */  c.lt.d    $f4, $f2
/* 31C00C 802BDFEC 00000000 */  nop       
/* 31C010 802BDFF0 45000005 */  bc1f      .L802BE008
/* 31C014 802BDFF4 E6000018 */   swc1     $f0, 0x18($s0)
/* 31C018 802BDFF8 3C014160 */  lui       $at, 0x4160
/* 31C01C 802BDFFC 44810000 */  mtc1      $at, $f0
/* 31C020 802BE000 00000000 */  nop       
/* 31C024 802BE004 E6000018 */  swc1      $f0, 0x18($s0)
.L802BE008:
/* 31C028 802BE008 3C0540C0 */  lui       $a1, 0x40c0
/* 31C02C 802BE00C 0C00E5FA */  jal       func_800397E8
/* 31C030 802BE010 0200202D */   daddu    $a0, $s0, $zero
/* 31C034 802BE014 1440000E */  bnez      $v0, .L802BE050
/* 31C038 802BE018 00000000 */   nop      
/* 31C03C 802BE01C 8E820000 */  lw        $v0, ($s4)
/* 31C040 802BE020 30420006 */  andi      $v0, $v0, 6
/* 31C044 802BE024 1440000A */  bnez      $v0, .L802BE050
/* 31C048 802BE028 00000000 */   nop      
/* 31C04C 802BE02C C680002C */  lwc1      $f0, 0x2c($s4)
/* 31C050 802BE030 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31C054 802BE034 46020001 */  sub.s     $f0, $f0, $f2
/* 31C058 802BE038 3C014120 */  lui       $at, 0x4120
/* 31C05C 802BE03C 44812000 */  mtc1      $at, $f4
/* 31C060 802BE040 00000000 */  nop       
/* 31C064 802BE044 46040003 */  div.s     $f0, $f0, $f4
/* 31C068 802BE048 46001080 */  add.s     $f2, $f2, $f0
/* 31C06C 802BE04C E602003C */  swc1      $f2, 0x3c($s0)
.L802BE050:
/* 31C070 802BE050 0C00E403 */  jal       npc_do_other_npc_collision
/* 31C074 802BE054 0200202D */   daddu    $a0, $s0, $zero
/* 31C078 802BE058 8E020000 */  lw        $v0, ($s0)
/* 31C07C 802BE05C 3C030200 */  lui       $v1, 0x200
/* 31C080 802BE060 00431024 */  and       $v0, $v0, $v1
/* 31C084 802BE064 1440004A */  bnez      $v0, .L802BE190
/* 31C088 802BE068 0000202D */   daddu    $a0, $zero, $zero
/* 31C08C 802BE06C 0C0AF45F */  jal       func_802BD17C
/* 31C090 802BE070 0200202D */   daddu    $a0, $s0, $zero
/* 31C094 802BE074 1040002F */  beqz      $v0, .L802BE134
/* 31C098 802BE078 24040286 */   addiu    $a0, $zero, 0x286
/* 31C09C 802BE07C 0000282D */  daddu     $a1, $zero, $zero
/* 31C0A0 802BE080 0C052742 */  jal       play_sound_at_npc
/* 31C0A4 802BE084 2406FFFC */   addiu    $a2, $zero, -4
/* 31C0A8 802BE088 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31C0AC 802BE08C 0C00A8BB */  jal       sin_deg
/* 31C0B0 802BE090 00000000 */   nop      
/* 31C0B4 802BE094 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31C0B8 802BE098 0C00A8D4 */  jal       cos_deg
/* 31C0BC 802BE09C 46000506 */   mov.s    $f20, $f0
/* 31C0C0 802BE0A0 24020001 */  addiu     $v0, $zero, 1
/* 31C0C4 802BE0A4 860300A8 */  lh        $v1, 0xa8($s0)
/* 31C0C8 802BE0A8 C604003C */  lwc1      $f4, 0x3c($s0)
/* 31C0CC 802BE0AC 3C01BF80 */  lui       $at, 0xbf80
/* 31C0D0 802BE0B0 44811000 */  mtc1      $at, $f2
/* 31C0D4 802BE0B4 46000007 */  neg.s     $f0, $f0
/* 31C0D8 802BE0B8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 31C0DC 802BE0BC E7A00018 */  swc1      $f0, 0x18($sp)
/* 31C0E0 802BE0C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 31C0E4 802BE0C4 44830000 */  mtc1      $v1, $f0
/* 31C0E8 802BE0C8 00000000 */  nop       
/* 31C0EC 802BE0CC 46800020 */  cvt.s.w   $f0, $f0
/* 31C0F0 802BE0D0 46002100 */  add.s     $f4, $f4, $f0
/* 31C0F4 802BE0D4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 31C0F8 802BE0D8 8E050038 */  lw        $a1, 0x38($s0)
/* 31C0FC 802BE0DC 8E070040 */  lw        $a3, 0x40($s0)
/* 31C100 802BE0E0 44062000 */  mfc1      $a2, $f4
/* 31C104 802BE0E4 0C01C064 */  jal       func_80070190
/* 31C108 802BE0E8 24040003 */   addiu    $a0, $zero, 3
/* 31C10C 802BE0EC 0000202D */  daddu     $a0, $zero, $zero
/* 31C110 802BE0F0 0080282D */  daddu     $a1, $a0, $zero
/* 31C114 802BE0F4 0C052742 */  jal       play_sound_at_npc
/* 31C118 802BE0F8 2406FFFC */   addiu    $a2, $zero, -4
/* 31C11C 802BE0FC 24020004 */  addiu     $v0, $zero, 4
/* 31C120 802BE100 AEA20070 */  sw        $v0, 0x70($s5)
/* 31C124 802BE104 C6000018 */  lwc1      $f0, 0x18($s0)
/* 31C128 802BE108 3C014010 */  lui       $at, 0x4010
/* 31C12C 802BE10C 44811800 */  mtc1      $at, $f3
/* 31C130 802BE110 44801000 */  mtc1      $zero, $f2
/* 31C134 802BE114 3C01802C */  lui       $at, 0x802c
/* 31C138 802BE118 D424EC18 */  ldc1      $f4, -0x13e8($at)
/* 31C13C 802BE11C 46000021 */  cvt.d.s   $f0, $f0
/* 31C140 802BE120 24020008 */  addiu     $v0, $zero, 8
/* 31C144 802BE124 3C01802C */  lui       $at, 0x802c
/* 31C148 802BE128 AC22EC50 */  sw        $v0, -0x13b0($at)
/* 31C14C 802BE12C 080AF87B */  j         .L802BE1EC
/* 31C150 802BE130 46220001 */   sub.d    $f0, $f0, $f2
.L802BE134:
/* 31C154 802BE134 3C03802C */  lui       $v1, 0x802c
/* 31C158 802BE138 8C63EB40 */  lw        $v1, -0x14c0($v1)
/* 31C15C 802BE13C 24020002 */  addiu     $v0, $zero, 2
/* 31C160 802BE140 1462000B */  bne       $v1, $v0, .L802BE170
/* 31C164 802BE144 0000202D */   daddu    $a0, $zero, $zero
/* 31C168 802BE148 0080282D */  daddu     $a1, $a0, $zero
/* 31C16C 802BE14C 0C052742 */  jal       play_sound_at_npc
/* 31C170 802BE150 2406FFFC */   addiu    $a2, $zero, -4
/* 31C174 802BE154 24020005 */  addiu     $v0, $zero, 5
/* 31C178 802BE158 AEA20070 */  sw        $v0, 0x70($s5)
/* 31C17C 802BE15C 2402001E */  addiu     $v0, $zero, 0x1e
/* 31C180 802BE160 3C01802C */  lui       $at, 0x802c
/* 31C184 802BE164 AC22EC50 */  sw        $v0, -0x13b0($at)
/* 31C188 802BE168 080AF8E8 */  j         .L802BE3A0
/* 31C18C 802BE16C AE000018 */   sw       $zero, 0x18($s0)
.L802BE170:
/* 31C190 802BE170 C6020010 */  lwc1      $f2, 0x10($s0)
/* 31C194 802BE174 3C01430C */  lui       $at, 0x430c
/* 31C198 802BE178 44810000 */  mtc1      $at, $f0
/* 31C19C 802BE17C 00000000 */  nop       
/* 31C1A0 802BE180 4602003C */  c.lt.s    $f0, $f2
/* 31C1A4 802BE184 00000000 */  nop       
/* 31C1A8 802BE188 45000009 */  bc1f      .L802BE1B0
/* 31C1AC 802BE18C 00000000 */   nop      
.L802BE190:
/* 31C1B0 802BE190 0080282D */  daddu     $a1, $a0, $zero
/* 31C1B4 802BE194 2406FFFC */  addiu     $a2, $zero, -4
/* 31C1B8 802BE198 24020007 */  addiu     $v0, $zero, 7
/* 31C1BC 802BE19C AEA20070 */  sw        $v0, 0x70($s5)
/* 31C1C0 802BE1A0 0C052742 */  jal       play_sound_at_npc
/* 31C1C4 802BE1A4 AE000018 */   sw       $zero, 0x18($s0)
/* 31C1C8 802BE1A8 080AF8E8 */  j         .L802BE3A0
/* 31C1CC 802BE1AC 00000000 */   nop      
.L802BE1B0:
/* 31C1D0 802BE1B0 3C0142D2 */  lui       $at, 0x42d2
/* 31C1D4 802BE1B4 44810000 */  mtc1      $at, $f0
/* 31C1D8 802BE1B8 00000000 */  nop       
/* 31C1DC 802BE1BC 4602003C */  c.lt.s    $f0, $f2
/* 31C1E0 802BE1C0 00000000 */  nop       
/* 31C1E4 802BE1C4 45000076 */  bc1f      .L802BE3A0
/* 31C1E8 802BE1C8 00000000 */   nop      
/* 31C1EC 802BE1CC C6000018 */  lwc1      $f0, 0x18($s0)
/* 31C1F0 802BE1D0 3C014010 */  lui       $at, 0x4010
/* 31C1F4 802BE1D4 44811800 */  mtc1      $at, $f3
/* 31C1F8 802BE1D8 44801000 */  mtc1      $zero, $f2
/* 31C1FC 802BE1DC 46000021 */  cvt.d.s   $f0, $f0
/* 31C200 802BE1E0 46220001 */  sub.d     $f0, $f0, $f2
/* 31C204 802BE1E4 3C01802C */  lui       $at, 0x802c
/* 31C208 802BE1E8 D424EC20 */  ldc1      $f4, -0x13e0($at)
.L802BE1EC:
/* 31C20C 802BE1EC 46200020 */  cvt.s.d   $f0, $f0
/* 31C210 802BE1F0 460000A1 */  cvt.d.s   $f2, $f0
/* 31C214 802BE1F4 4624103C */  c.lt.d    $f2, $f4
/* 31C218 802BE1F8 00000000 */  nop       
/* 31C21C 802BE1FC 45000068 */  bc1f      .L802BE3A0
/* 31C220 802BE200 E6000018 */   swc1     $f0, 0x18($s0)
/* 31C224 802BE204 C6000010 */  lwc1      $f0, 0x10($s0)
/* 31C228 802BE208 3C013FF0 */  lui       $at, 0x3ff0
/* 31C22C 802BE20C 44811800 */  mtc1      $at, $f3
/* 31C230 802BE210 44801000 */  mtc1      $zero, $f2
/* 31C234 802BE214 46000021 */  cvt.d.s   $f0, $f0
/* 31C238 802BE218 46220000 */  add.d     $f0, $f0, $f2
/* 31C23C 802BE21C 3C013C23 */  lui       $at, 0x3c23
/* 31C240 802BE220 3421D70A */  ori       $at, $at, 0xd70a
/* 31C244 802BE224 44811000 */  mtc1      $at, $f2
/* 31C248 802BE228 00000000 */  nop       
/* 31C24C 802BE22C E6020018 */  swc1      $f2, 0x18($s0)
/* 31C250 802BE230 46200020 */  cvt.s.d   $f0, $f0
/* 31C254 802BE234 080AF8E8 */  j         .L802BE3A0
/* 31C258 802BE238 E6000010 */   swc1     $f0, 0x10($s0)
/* 31C25C 802BE23C C6000038 */  lwc1      $f0, 0x38($s0)
/* 31C260 802BE240 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31C264 802BE244 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31C268 802BE248 C6060018 */  lwc1      $f6, 0x18($s0)
/* 31C26C 802BE24C 34048000 */  ori       $a0, $zero, 0x8000
/* 31C270 802BE250 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31C274 802BE254 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31C278 802BE258 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31C27C 802BE25C E7A60010 */  swc1      $f6, 0x10($sp)
/* 31C280 802BE260 C600000C */  lwc1      $f0, 0xc($s0)
/* 31C284 802BE264 27A50020 */  addiu     $a1, $sp, 0x20
/* 31C288 802BE268 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31C28C 802BE26C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31C290 802BE270 27A60024 */  addiu     $a2, $sp, 0x24
/* 31C294 802BE274 44820000 */  mtc1      $v0, $f0
/* 31C298 802BE278 00000000 */  nop       
/* 31C29C 802BE27C 46800020 */  cvt.s.w   $f0, $f0
/* 31C2A0 802BE280 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31C2A4 802BE284 960300A6 */  lhu       $v1, 0xa6($s0)
/* 31C2A8 802BE288 27A70028 */  addiu     $a3, $sp, 0x28
/* 31C2AC 802BE28C 00031C00 */  sll       $v1, $v1, 0x10
/* 31C2B0 802BE290 00031403 */  sra       $v0, $v1, 0x10
/* 31C2B4 802BE294 00031FC2 */  srl       $v1, $v1, 0x1f
/* 31C2B8 802BE298 00431021 */  addu      $v0, $v0, $v1
/* 31C2BC 802BE29C 00021043 */  sra       $v0, $v0, 1
/* 31C2C0 802BE2A0 44820000 */  mtc1      $v0, $f0
/* 31C2C4 802BE2A4 00000000 */  nop       
/* 31C2C8 802BE2A8 46800020 */  cvt.s.w   $f0, $f0
/* 31C2CC 802BE2AC 0C0376B9 */  jal       func_800DDAE4
/* 31C2D0 802BE2B0 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31C2D4 802BE2B4 0200202D */  daddu     $a0, $s0, $zero
/* 31C2D8 802BE2B8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 31C2DC 802BE2BC C6020018 */  lwc1      $f2, 0x18($s0)
/* 31C2E0 802BE2C0 24050001 */  addiu     $a1, $zero, 1
/* 31C2E4 802BE2C4 E6000038 */  swc1      $f0, 0x38($s0)
/* 31C2E8 802BE2C8 C7A60024 */  lwc1      $f6, 0x24($sp)
/* 31C2EC 802BE2CC C6000010 */  lwc1      $f0, 0x10($s0)
/* 31C2F0 802BE2D0 C7A40028 */  lwc1      $f4, 0x28($sp)
/* 31C2F4 802BE2D4 46020000 */  add.s     $f0, $f0, $f2
/* 31C2F8 802BE2D8 E606003C */  swc1      $f6, 0x3c($s0)
/* 31C2FC 802BE2DC E6040040 */  swc1      $f4, 0x40($s0)
/* 31C300 802BE2E0 0C00F598 */  jal       func_8003D660
/* 31C304 802BE2E4 E6000010 */   swc1     $f0, 0x10($s0)
/* 31C308 802BE2E8 C6000018 */  lwc1      $f0, 0x18($s0)
/* 31C30C 802BE2EC 3C014018 */  lui       $at, 0x4018
/* 31C310 802BE2F0 44811800 */  mtc1      $at, $f3
/* 31C314 802BE2F4 44801000 */  mtc1      $zero, $f2
/* 31C318 802BE2F8 46000021 */  cvt.d.s   $f0, $f0
/* 31C31C 802BE2FC 46220001 */  sub.d     $f0, $f0, $f2
/* 31C320 802BE300 3C01802C */  lui       $at, 0x802c
/* 31C324 802BE304 D424EC28 */  ldc1      $f4, -0x13d8($at)
/* 31C328 802BE308 46200020 */  cvt.s.d   $f0, $f0
/* 31C32C 802BE30C 460000A1 */  cvt.d.s   $f2, $f0
/* 31C330 802BE310 4624103C */  c.lt.d    $f2, $f4
/* 31C334 802BE314 00000000 */  nop       
/* 31C338 802BE318 4500000E */  bc1f      .L802BE354
/* 31C33C 802BE31C E6000018 */   swc1     $f0, 0x18($s0)
/* 31C340 802BE320 C6000010 */  lwc1      $f0, 0x10($s0)
/* 31C344 802BE324 3C013FF0 */  lui       $at, 0x3ff0
/* 31C348 802BE328 44811800 */  mtc1      $at, $f3
/* 31C34C 802BE32C 44801000 */  mtc1      $zero, $f2
/* 31C350 802BE330 46000021 */  cvt.d.s   $f0, $f0
/* 31C354 802BE334 46220000 */  add.d     $f0, $f0, $f2
/* 31C358 802BE338 3C013C23 */  lui       $at, 0x3c23
/* 31C35C 802BE33C 3421D70A */  ori       $at, $at, 0xd70a
/* 31C360 802BE340 44811000 */  mtc1      $at, $f2
/* 31C364 802BE344 00000000 */  nop       
/* 31C368 802BE348 E6020018 */  swc1      $f2, 0x18($s0)
/* 31C36C 802BE34C 46200020 */  cvt.s.d   $f0, $f0
/* 31C370 802BE350 E6000010 */  swc1      $f0, 0x10($s0)
.L802BE354:
/* 31C374 802BE354 3C03802C */  lui       $v1, 0x802c
/* 31C378 802BE358 2463EC50 */  addiu     $v1, $v1, -0x13b0
/* 31C37C 802BE35C 8C620000 */  lw        $v0, ($v1)
/* 31C380 802BE360 1440000B */  bnez      $v0, .L802BE390
/* 31C384 802BE364 2442FFFF */   addiu    $v0, $v0, -1
/* 31C388 802BE368 24020007 */  addiu     $v0, $zero, 7
/* 31C38C 802BE36C AEA20070 */  sw        $v0, 0x70($s5)
/* 31C390 802BE370 8C620000 */  lw        $v0, ($v1)
/* 31C394 802BE374 080AF8E4 */  j         .L802BE390
/* 31C398 802BE378 2442FFFF */   addiu    $v0, $v0, -1
/* 31C39C 802BE37C 3C03802C */  lui       $v1, 0x802c
/* 31C3A0 802BE380 2463EC50 */  addiu     $v1, $v1, -0x13b0
/* 31C3A4 802BE384 8C620000 */  lw        $v0, ($v1)
/* 31C3A8 802BE388 10400003 */  beqz      $v0, .L802BE398
/* 31C3AC 802BE38C 2442FFFF */   addiu    $v0, $v0, -1
.L802BE390:
/* 31C3B0 802BE390 080AF8E8 */  j         .L802BE3A0
/* 31C3B4 802BE394 AC620000 */   sw       $v0, ($v1)
.L802BE398:
/* 31C3B8 802BE398 24020007 */  addiu     $v0, $zero, 7
.L802BE39C:
/* 31C3BC 802BE39C AEA20070 */  sw        $v0, 0x70($s5)
.L802BE3A0:
/* 31C3C0 802BE3A0 8EA30070 */  lw        $v1, 0x70($s5)
/* 31C3C4 802BE3A4 24020007 */  addiu     $v0, $zero, 7
/* 31C3C8 802BE3A8 146200D5 */  bne       $v1, $v0, .L802BE700
/* 31C3CC 802BE3AC 00000000 */   nop      
/* 31C3D0 802BE3B0 8E020000 */  lw        $v0, ($s0)
/* 31C3D4 802BE3B4 34420100 */  ori       $v0, $v0, 0x100
/* 31C3D8 802BE3B8 AE020000 */  sw        $v0, ($s0)
/* 31C3DC 802BE3BC 928200B4 */  lbu       $v0, 0xb4($s4)
/* 31C3E0 802BE3C0 2442FFEB */  addiu     $v0, $v0, -0x15
/* 31C3E4 802BE3C4 2C420002 */  sltiu     $v0, $v0, 2
/* 31C3E8 802BE3C8 544000CD */  bnel      $v0, $zero, .L802BE700
/* 31C3EC 802BE3CC AEA00070 */   sw       $zero, 0x70($s5)
/* 31C3F0 802BE3D0 3C01802C */  lui       $at, 0x802c
/* 31C3F4 802BE3D4 C42CEC70 */  lwc1      $f12, -0x1390($at)
/* 31C3F8 802BE3D8 3C01802C */  lui       $at, 0x802c
/* 31C3FC 802BE3DC C42EEC78 */  lwc1      $f14, -0x1388($at)
/* 31C400 802BE3E0 8E060038 */  lw        $a2, 0x38($s0)
/* 31C404 802BE3E4 0C00A720 */  jal       atan2
/* 31C408 802BE3E8 8E070040 */   lw       $a3, 0x40($s0)
/* 31C40C 802BE3EC 46000506 */  mov.s     $f20, $f0
/* 31C410 802BE3F0 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31C414 802BE3F4 0C00A70A */  jal       get_clamped_angle_diff
/* 31C418 802BE3F8 4600A386 */   mov.s    $f14, $f20
/* 31C41C 802BE3FC 3C013E00 */  lui       $at, 0x3e00
/* 31C420 802BE400 44811000 */  mtc1      $at, $f2
/* 31C424 802BE404 00000000 */  nop       
/* 31C428 802BE408 46020002 */  mul.s     $f0, $f0, $f2
/* 31C42C 802BE40C 00000000 */  nop       
/* 31C430 802BE410 4600A500 */  add.s     $f20, $f20, $f0
/* 31C434 802BE414 C6000018 */  lwc1      $f0, 0x18($s0)
/* 31C438 802BE418 46000007 */  neg.s     $f0, $f0
/* 31C43C 802BE41C 44050000 */  mfc1      $a1, $f0
/* 31C440 802BE420 4406A000 */  mfc1      $a2, $f20
/* 31C444 802BE424 0200202D */  daddu     $a0, $s0, $zero
/* 31C448 802BE428 0C00EA95 */  jal       npc_move_heading
/* 31C44C 802BE42C AE06000C */   sw       $a2, 0xc($s0)
/* 31C450 802BE430 C6020010 */  lwc1      $f2, 0x10($s0)
/* 31C454 802BE434 C6000018 */  lwc1      $f0, 0x18($s0)
/* 31C458 802BE438 46001081 */  sub.s     $f2, $f2, $f0
/* 31C45C 802BE43C 0200202D */  daddu     $a0, $s0, $zero
/* 31C460 802BE440 24050001 */  addiu     $a1, $zero, 1
/* 31C464 802BE444 0C00F598 */  jal       func_8003D660
/* 31C468 802BE448 E6020010 */   swc1     $f2, 0x10($s0)
/* 31C46C 802BE44C C6000018 */  lwc1      $f0, 0x18($s0)
/* 31C470 802BE450 3C01802C */  lui       $at, 0x802c
/* 31C474 802BE454 D422EC30 */  ldc1      $f2, -0x13d0($at)
/* 31C478 802BE458 46000021 */  cvt.d.s   $f0, $f0
/* 31C47C 802BE45C 46220000 */  add.d     $f0, $f0, $f2
/* 31C480 802BE460 3C01402C */  lui       $at, 0x402c
/* 31C484 802BE464 44812800 */  mtc1      $at, $f5
/* 31C488 802BE468 44802000 */  mtc1      $zero, $f4
/* 31C48C 802BE46C 46200020 */  cvt.s.d   $f0, $f0
/* 31C490 802BE470 460000A1 */  cvt.d.s   $f2, $f0
/* 31C494 802BE474 4622203C */  c.lt.d    $f4, $f2
/* 31C498 802BE478 00000000 */  nop       
/* 31C49C 802BE47C 45000005 */  bc1f      .L802BE494
/* 31C4A0 802BE480 E6000018 */   swc1     $f0, 0x18($s0)
/* 31C4A4 802BE484 3C014160 */  lui       $at, 0x4160
/* 31C4A8 802BE488 44810000 */  mtc1      $at, $f0
/* 31C4AC 802BE48C 00000000 */  nop       
/* 31C4B0 802BE490 E6000018 */  swc1      $f0, 0x18($s0)
.L802BE494:
/* 31C4B4 802BE494 3C0540C0 */  lui       $a1, 0x40c0
/* 31C4B8 802BE498 0C00E5FA */  jal       func_800397E8
/* 31C4BC 802BE49C 0200202D */   daddu    $a0, $s0, $zero
/* 31C4C0 802BE4A0 1440000A */  bnez      $v0, .L802BE4CC
/* 31C4C4 802BE4A4 00000000 */   nop      
/* 31C4C8 802BE4A8 C680002C */  lwc1      $f0, 0x2c($s4)
/* 31C4CC 802BE4AC C602003C */  lwc1      $f2, 0x3c($s0)
/* 31C4D0 802BE4B0 46020001 */  sub.s     $f0, $f0, $f2
/* 31C4D4 802BE4B4 3C014120 */  lui       $at, 0x4120
/* 31C4D8 802BE4B8 44812000 */  mtc1      $at, $f4
/* 31C4DC 802BE4BC 00000000 */  nop       
/* 31C4E0 802BE4C0 46040003 */  div.s     $f0, $f0, $f4
/* 31C4E4 802BE4C4 46001080 */  add.s     $f2, $f2, $f0
/* 31C4E8 802BE4C8 E602003C */  swc1      $f2, 0x3c($s0)
.L802BE4CC:
/* 31C4EC 802BE4CC C6020038 */  lwc1      $f2, 0x38($s0)
/* 31C4F0 802BE4D0 C604003C */  lwc1      $f4, 0x3c($s0)
/* 31C4F4 802BE4D4 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31C4F8 802BE4D8 3C014334 */  lui       $at, 0x4334
/* 31C4FC 802BE4DC 4481A000 */  mtc1      $at, $f20
/* 31C500 802BE4E0 C6000040 */  lwc1      $f0, 0x40($s0)
/* 31C504 802BE4E4 46146300 */  add.s     $f12, $f12, $f20
/* 31C508 802BE4E8 E7A20020 */  swc1      $f2, 0x20($sp)
/* 31C50C 802BE4EC E7A40024 */  swc1      $f4, 0x24($sp)
/* 31C510 802BE4F0 0C00A6C9 */  jal       clamp_angle
/* 31C514 802BE4F4 E7A00028 */   swc1     $f0, 0x28($sp)
/* 31C518 802BE4F8 34048000 */  ori       $a0, $zero, 0x8000
/* 31C51C 802BE4FC C6020018 */  lwc1      $f2, 0x18($s0)
/* 31C520 802BE500 27A50020 */  addiu     $a1, $sp, 0x20
/* 31C524 802BE504 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31C528 802BE508 E7A20010 */  swc1      $f2, 0x10($sp)
/* 31C52C 802BE50C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31C530 802BE510 27A60024 */  addiu     $a2, $sp, 0x24
/* 31C534 802BE514 44820000 */  mtc1      $v0, $f0
/* 31C538 802BE518 00000000 */  nop       
/* 31C53C 802BE51C 46800020 */  cvt.s.w   $f0, $f0
/* 31C540 802BE520 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31C544 802BE524 860200A6 */  lh        $v0, 0xa6($s0)
/* 31C548 802BE528 27A70028 */  addiu     $a3, $sp, 0x28
/* 31C54C 802BE52C 44820000 */  mtc1      $v0, $f0
/* 31C550 802BE530 00000000 */  nop       
/* 31C554 802BE534 46800020 */  cvt.s.w   $f0, $f0
/* 31C558 802BE538 0C0376B9 */  jal       func_800DDAE4
/* 31C55C 802BE53C E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31C560 802BE540 10400026 */  beqz      $v0, .L802BE5DC
/* 31C564 802BE544 2404010C */   addiu    $a0, $zero, 0x10c
/* 31C568 802BE548 0000282D */  daddu     $a1, $zero, $zero
/* 31C56C 802BE54C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 31C570 802BE550 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 31C574 802BE554 C7A40028 */  lwc1      $f4, 0x28($sp)
/* 31C578 802BE558 2406FFFC */  addiu     $a2, $zero, -4
/* 31C57C 802BE55C E6000038 */  swc1      $f0, 0x38($s0)
/* 31C580 802BE560 E602003C */  swc1      $f2, 0x3c($s0)
/* 31C584 802BE564 0C052742 */  jal       play_sound_at_npc
/* 31C588 802BE568 E6040040 */   swc1     $f4, 0x40($s0)
/* 31C58C 802BE56C C60C000C */  lwc1      $f12, 0xc($s0)
/* 31C590 802BE570 0C00A8BB */  jal       sin_deg
/* 31C594 802BE574 46146300 */   add.s    $f12, $f12, $f20
/* 31C598 802BE578 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31C59C 802BE57C 46146300 */  add.s     $f12, $f12, $f20
/* 31C5A0 802BE580 0C00A8D4 */  jal       cos_deg
/* 31C5A4 802BE584 46000506 */   mov.s    $f20, $f0
/* 31C5A8 802BE588 24020001 */  addiu     $v0, $zero, 1
/* 31C5AC 802BE58C 860300A8 */  lh        $v1, 0xa8($s0)
/* 31C5B0 802BE590 C604003C */  lwc1      $f4, 0x3c($s0)
/* 31C5B4 802BE594 3C01BF80 */  lui       $at, 0xbf80
/* 31C5B8 802BE598 44811000 */  mtc1      $at, $f2
/* 31C5BC 802BE59C 46000007 */  neg.s     $f0, $f0
/* 31C5C0 802BE5A0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 31C5C4 802BE5A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31C5C8 802BE5A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 31C5CC 802BE5AC 44830000 */  mtc1      $v1, $f0
/* 31C5D0 802BE5B0 00000000 */  nop       
/* 31C5D4 802BE5B4 46800020 */  cvt.s.w   $f0, $f0
/* 31C5D8 802BE5B8 46002100 */  add.s     $f4, $f4, $f0
/* 31C5DC 802BE5BC E7A20014 */  swc1      $f2, 0x14($sp)
/* 31C5E0 802BE5C0 8E050038 */  lw        $a1, 0x38($s0)
/* 31C5E4 802BE5C4 8E070040 */  lw        $a3, 0x40($s0)
/* 31C5E8 802BE5C8 44062000 */  mfc1      $a2, $f4
/* 31C5EC 802BE5CC 0C01C064 */  jal       func_80070190
/* 31C5F0 802BE5D0 24040003 */   addiu    $a0, $zero, 3
/* 31C5F4 802BE5D4 080AF9C0 */  j         .L802BE700
/* 31C5F8 802BE5D8 AEA00070 */   sw       $zero, 0x70($s5)
.L802BE5DC:
/* 31C5FC 802BE5DC 3C02802C */  lui       $v0, 0x802c
/* 31C600 802BE5E0 8C42EC6C */  lw        $v0, -0x1394($v0)
/* 31C604 802BE5E4 10400025 */  beqz      $v0, .L802BE67C
/* 31C608 802BE5E8 00000000 */   nop      
/* 31C60C 802BE5EC 3C04802C */  lui       $a0, 0x802c
/* 31C610 802BE5F0 8C84EC68 */  lw        $a0, -0x1398($a0)
/* 31C614 802BE5F4 0C04C3D6 */  jal       get_item_entity
/* 31C618 802BE5F8 00000000 */   nop      
/* 31C61C 802BE5FC 0040882D */  daddu     $s1, $v0, $zero
/* 31C620 802BE600 C6060038 */  lwc1      $f6, 0x38($s0)
/* 31C624 802BE604 C600003C */  lwc1      $f0, 0x3c($s0)
/* 31C628 802BE608 3C014100 */  lui       $at, 0x4100
/* 31C62C 802BE60C 44811000 */  mtc1      $at, $f2
/* 31C630 802BE610 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31C634 802BE614 3C02802C */  lui       $v0, 0x802c
/* 31C638 802BE618 8C42EC58 */  lw        $v0, -0x13a8($v0)
/* 31C63C 802BE61C 46020000 */  add.s     $f0, $f0, $f2
/* 31C640 802BE620 E7A60020 */  swc1      $f6, 0x20($sp)
/* 31C644 802BE624 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31C648 802BE628 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31C64C 802BE62C C68C0080 */  lwc1      $f12, 0x80($s4)
/* 31C650 802BE630 3C01C2B4 */  lui       $at, 0xc2b4
/* 31C654 802BE634 44810000 */  mtc1      $at, $f0
/* 31C658 802BE638 10400003 */  beqz      $v0, .L802BE648
/* 31C65C 802BE63C 00000000 */   nop      
/* 31C660 802BE640 3C0142B4 */  lui       $at, 0x42b4
/* 31C664 802BE644 44810000 */  mtc1      $at, $f0
.L802BE648:
/* 31C668 802BE648 0C00A6C9 */  jal       clamp_angle
/* 31C66C 802BE64C 46006301 */   sub.s    $f12, $f12, $f0
/* 31C670 802BE650 27A40020 */  addiu     $a0, $sp, 0x20
/* 31C674 802BE654 3C064080 */  lui       $a2, 0x4080
/* 31C678 802BE658 44070000 */  mfc1      $a3, $f0
/* 31C67C 802BE65C 0C00A7E7 */  jal       add_vec2D_polar
/* 31C680 802BE660 27A50028 */   addiu    $a1, $sp, 0x28
/* 31C684 802BE664 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 31C688 802BE668 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 31C68C 802BE66C C7A40028 */  lwc1      $f4, 0x28($sp)
/* 31C690 802BE670 E6200008 */  swc1      $f0, 8($s1)
/* 31C694 802BE674 E622000C */  swc1      $f2, 0xc($s1)
/* 31C698 802BE678 E6240010 */  swc1      $f4, 0x10($s1)
.L802BE67C:
/* 31C69C 802BE67C C6020010 */  lwc1      $f2, 0x10($s0)
/* 31C6A0 802BE680 3C014170 */  lui       $at, 0x4170
/* 31C6A4 802BE684 44810000 */  mtc1      $at, $f0
/* 31C6A8 802BE688 00000000 */  nop       
/* 31C6AC 802BE68C 46001080 */  add.s     $f2, $f2, $f0
/* 31C6B0 802BE690 C6040018 */  lwc1      $f4, 0x18($s0)
/* 31C6B4 802BE694 4604103C */  c.lt.s    $f2, $f4
/* 31C6B8 802BE698 00000000 */  nop       
/* 31C6BC 802BE69C 45030018 */  bc1tl     .L802BE700
/* 31C6C0 802BE6A0 AEA00070 */   sw       $zero, 0x70($s5)
/* 31C6C4 802BE6A4 3C01420C */  lui       $at, 0x420c
/* 31C6C8 802BE6A8 44810000 */  mtc1      $at, $f0
/* 31C6CC 802BE6AC 00000000 */  nop       
/* 31C6D0 802BE6B0 4600103C */  c.lt.s    $f2, $f0
/* 31C6D4 802BE6B4 00000000 */  nop       
/* 31C6D8 802BE6B8 45000011 */  bc1f      .L802BE700
/* 31C6DC 802BE6BC 00000000 */   nop      
/* 31C6E0 802BE6C0 3C014010 */  lui       $at, 0x4010
/* 31C6E4 802BE6C4 44810800 */  mtc1      $at, $f1
/* 31C6E8 802BE6C8 44800000 */  mtc1      $zero, $f0
/* 31C6EC 802BE6CC 460020A1 */  cvt.d.s   $f2, $f4
/* 31C6F0 802BE6D0 46201081 */  sub.d     $f2, $f2, $f0
/* 31C6F4 802BE6D4 462010A0 */  cvt.s.d   $f2, $f2
/* 31C6F8 802BE6D8 E6020018 */  swc1      $f2, 0x18($s0)
/* 31C6FC 802BE6DC 460010A1 */  cvt.d.s   $f2, $f2
/* 31C700 802BE6E0 4620103C */  c.lt.d    $f2, $f0
/* 31C704 802BE6E4 00000000 */  nop       
/* 31C708 802BE6E8 45000005 */  bc1f      .L802BE700
/* 31C70C 802BE6EC 00000000 */   nop      
/* 31C710 802BE6F0 3C014080 */  lui       $at, 0x4080
/* 31C714 802BE6F4 44810000 */  mtc1      $at, $f0
/* 31C718 802BE6F8 00000000 */  nop       
/* 31C71C 802BE6FC E6000018 */  swc1      $f0, 0x18($s0)
.L802BE700:
/* 31C720 802BE700 8EA20070 */  lw        $v0, 0x70($s5)
/* 31C724 802BE704 1440002B */  bnez      $v0, .L802BE7B4
/* 31C728 802BE708 0000102D */   daddu    $v0, $zero, $zero
/* 31C72C 802BE70C 3C11802C */  lui       $s1, 0x802c
/* 31C730 802BE710 2631EC64 */  addiu     $s1, $s1, -0x139c
/* 31C734 802BE714 8E220000 */  lw        $v0, ($s1)
/* 31C738 802BE718 10400005 */  beqz      $v0, .L802BE730
/* 31C73C 802BE71C 3C050002 */   lui      $a1, 2
/* 31C740 802BE720 0C038069 */  jal       enable_player_input
/* 31C744 802BE724 00000000 */   nop      
/* 31C748 802BE728 AE200000 */  sw        $zero, ($s1)
/* 31C74C 802BE72C 3C050002 */  lui       $a1, 2
.L802BE730:
/* 31C750 802BE730 34A50004 */  ori       $a1, $a1, 4
/* 31C754 802BE734 24040284 */  addiu     $a0, $zero, 0x284
/* 31C758 802BE738 8E020000 */  lw        $v0, ($s0)
/* 31C75C 802BE73C 2403F7BF */  addiu     $v1, $zero, -0x841
/* 31C760 802BE740 3C01802C */  lui       $at, 0x802c
/* 31C764 802BE744 AC20EB40 */  sw        $zero, -0x14c0($at)
/* 31C768 802BE748 34420100 */  ori       $v0, $v0, 0x100
/* 31C76C 802BE74C 00431024 */  and       $v0, $v0, $v1
/* 31C770 802BE750 AE020000 */  sw        $v0, ($s0)
/* 31C774 802BE754 24020018 */  addiu     $v0, $zero, 0x18
/* 31C778 802BE758 A2C00003 */  sb        $zero, 3($s6)
/* 31C77C 802BE75C A2C00000 */  sb        $zero, ($s6)
/* 31C780 802BE760 AE00001C */  sw        $zero, 0x1c($s0)
/* 31C784 802BE764 A60200A8 */  sh        $v0, 0xa8($s0)
/* 31C788 802BE768 0C05271B */  jal       stop_sound
/* 31C78C 802BE76C AE050028 */   sw       $a1, 0x28($s0)
/* 31C790 802BE770 0C00EB6B */  jal       disable_npc_blur
/* 31C794 802BE774 0200202D */   daddu    $a0, $s0, $zero
/* 31C798 802BE778 3C11802C */  lui       $s1, 0x802c
/* 31C79C 802BE77C 2631EC6C */  addiu     $s1, $s1, -0x1394
/* 31C7A0 802BE780 8E220000 */  lw        $v0, ($s1)
/* 31C7A4 802BE784 10400006 */  beqz      $v0, .L802BE7A0
/* 31C7A8 802BE788 00000000 */   nop      
/* 31C7AC 802BE78C 3C04802C */  lui       $a0, 0x802c
/* 31C7B0 802BE790 8C84EC68 */  lw        $a0, -0x1398($a0)
/* 31C7B4 802BE794 0C04D06C */  jal       func_801341B0
/* 31C7B8 802BE798 00000000 */   nop      
/* 31C7BC 802BE79C AE200000 */  sw        $zero, ($s1)
.L802BE7A0:
/* 31C7C0 802BE7A0 3C01802C */  lui       $at, 0x802c
/* 31C7C4 802BE7A4 AC20EC54 */  sw        $zero, -0x13ac($at)
/* 31C7C8 802BE7A8 0C03BD17 */  jal       clear_partner_move_history
/* 31C7CC 802BE7AC 0200202D */   daddu    $a0, $s0, $zero
/* 31C7D0 802BE7B0 24020002 */  addiu     $v0, $zero, 2
.L802BE7B4:
/* 31C7D4 802BE7B4 8FBF004C */  lw        $ra, 0x4c($sp)
/* 31C7D8 802BE7B8 8FB60048 */  lw        $s6, 0x48($sp)
/* 31C7DC 802BE7BC 8FB50044 */  lw        $s5, 0x44($sp)
/* 31C7E0 802BE7C0 8FB40040 */  lw        $s4, 0x40($sp)
/* 31C7E4 802BE7C4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 31C7E8 802BE7C8 8FB20038 */  lw        $s2, 0x38($sp)
/* 31C7EC 802BE7CC 8FB10034 */  lw        $s1, 0x34($sp)
/* 31C7F0 802BE7D0 8FB00030 */  lw        $s0, 0x30($sp)
/* 31C7F4 802BE7D4 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 31C7F8 802BE7D8 03E00008 */  jr        $ra
/* 31C7FC 802BE7DC 27BD0058 */   addiu    $sp, $sp, 0x58
