.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD758
/* 3184A8 802BD758 3C02800B */  lui       $v0, 0x800b
/* 3184AC 802BD75C 80420F18 */  lb        $v0, 0xf18($v0)
/* 3184B0 802BD760 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3184B4 802BD764 AFB20038 */  sw        $s2, 0x38($sp)
/* 3184B8 802BD768 0080902D */  daddu     $s2, $a0, $zero
/* 3184BC 802BD76C AFB3003C */  sw        $s3, 0x3c($sp)
/* 3184C0 802BD770 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 3184C4 802BD774 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 3184C8 802BD778 AFB40040 */  sw        $s4, 0x40($sp)
/* 3184CC 802BD77C 3C148016 */  lui       $s4, 0x8016
/* 3184D0 802BD780 2694A550 */  addiu     $s4, $s4, -0x5ab0
/* 3184D4 802BD784 AFB50044 */  sw        $s5, 0x44($sp)
/* 3184D8 802BD788 3C158011 */  lui       $s5, %hi(D_8010EBB0)
/* 3184DC 802BD78C 26B5EBB0 */  addiu     $s5, $s5, %lo(D_8010EBB0)
/* 3184E0 802BD790 AFBF0048 */  sw        $ra, 0x48($sp)
/* 3184E4 802BD794 AFB10034 */  sw        $s1, 0x34($sp)
/* 3184E8 802BD798 AFB00030 */  sw        $s0, 0x30($sp)
/* 3184EC 802BD79C F7B40050 */  sdc1      $f20, 0x50($sp)
/* 3184F0 802BD7A0 8E51014C */  lw        $s1, 0x14c($s2)
/* 3184F4 802BD7A4 14400346 */  bnez      $v0, .L802BE4C0
/* 3184F8 802BD7A8 0000102D */   daddu    $v0, $zero, $zero
/* 3184FC 802BD7AC 10A00005 */  beqz      $a1, .L802BD7C4
/* 318500 802BD7B0 00000000 */   nop      
/* 318504 802BD7B4 0C0AF5B7 */  jal       func_802BD6DC
/* 318508 802BD7B8 0220202D */   daddu    $a0, $s1, $zero
/* 31850C 802BD7BC 24020014 */  addiu     $v0, $zero, 0x14
/* 318510 802BD7C0 AE420070 */  sw        $v0, 0x70($s2)
.L802BD7C4:
/* 318514 802BD7C4 8E430070 */  lw        $v1, 0x70($s2)
/* 318518 802BD7C8 24020002 */  addiu     $v0, $zero, 2
/* 31851C 802BD7CC 106200E7 */  beq       $v1, $v0, .L802BDB6C
/* 318520 802BD7D0 28620003 */   slti     $v0, $v1, 3
/* 318524 802BD7D4 10400005 */  beqz      $v0, .L802BD7EC
/* 318528 802BD7D8 24020001 */   addiu    $v0, $zero, 1
/* 31852C 802BD7DC 106200AD */  beq       $v1, $v0, .L802BDA94
/* 318530 802BD7E0 24020004 */   addiu    $v0, $zero, 4
/* 318534 802BD7E4 080AF77C */  j         .L802BDDF0
/* 318538 802BD7E8 00000000 */   nop      
.L802BD7EC:
/* 31853C 802BD7EC 24020014 */  addiu     $v0, $zero, 0x14
/* 318540 802BD7F0 10620005 */  beq       $v1, $v0, .L802BD808
/* 318544 802BD7F4 24020015 */   addiu    $v0, $zero, 0x15
/* 318548 802BD7F8 10620034 */  beq       $v1, $v0, .L802BD8CC
/* 31854C 802BD7FC 00000000 */   nop      
/* 318550 802BD800 080AF77A */  j         .L802BDDE8
/* 318554 802BD804 00000000 */   nop      
.L802BD808:
/* 318558 802BD808 82620015 */  lb        $v0, 0x15($s3)
/* 31855C 802BD80C 1440032C */  bnez      $v0, .L802BE4C0
/* 318560 802BD810 24020002 */   addiu    $v0, $zero, 2
/* 318564 802BD814 8E620000 */  lw        $v0, ($s3)
/* 318568 802BD818 30420002 */  andi      $v0, $v0, 2
/* 31856C 802BD81C 14400328 */  bnez      $v0, .L802BE4C0
/* 318570 802BD820 24020002 */   addiu    $v0, $zero, 2
/* 318574 802BD824 8E220000 */  lw        $v0, ($s1)
/* 318578 802BD828 30421000 */  andi      $v0, $v0, 0x1000
/* 31857C 802BD82C 10400324 */  beqz      $v0, .L802BE4C0
/* 318580 802BD830 24020002 */   addiu    $v0, $zero, 2
/* 318584 802BD834 0C03805E */  jal       disable_player_input
/* 318588 802BD838 00000000 */   nop      
/* 31858C 802BD83C 82620015 */  lb        $v0, 0x15($s3)
/* 318590 802BD840 24040001 */  addiu     $a0, $zero, 1
/* 318594 802BD844 AE42007C */  sw        $v0, 0x7c($s2)
/* 318598 802BD848 8E220000 */  lw        $v0, ($s1)
/* 31859C 802BD84C 2403F5B7 */  addiu     $v1, $zero, -0xa49
/* 3185A0 802BD850 3C01802C */  lui       $at, 0x802c
/* 3185A4 802BD854 AC24E92C */  sw        $a0, -0x16d4($at)
/* 3185A8 802BD858 3C01802C */  lui       $at, 0x802c
/* 3185AC 802BD85C AC20E928 */  sw        $zero, -0x16d8($at)
/* 3185B0 802BD860 3C01802C */  lui       $at, 0x802c
/* 3185B4 802BD864 AC20E930 */  sw        $zero, -0x16d0($at)
/* 3185B8 802BD868 3C01802C */  lui       $at, 0x802c
/* 3185BC 802BD86C AC20E934 */  sw        $zero, -0x16cc($at)
/* 3185C0 802BD870 00431024 */  and       $v0, $v0, $v1
/* 3185C4 802BD874 AE220000 */  sw        $v0, ($s1)
/* 3185C8 802BD878 24020003 */  addiu     $v0, $zero, 3
/* 3185CC 802BD87C A2A40000 */  sb        $a0, ($s5)
/* 3185D0 802BD880 0C03BD38 */  jal       func_800EF4E0
/* 3185D4 802BD884 A2A20003 */   sb       $v0, 3($s5)
/* 3185D8 802BD888 3C01802C */  lui       $at, 0x802c
/* 3185DC 802BD88C AC22E920 */  sw        $v0, -0x16e0($at)
/* 3185E0 802BD890 0C00EB49 */  jal       enable_npc_blur
/* 3185E4 802BD894 0220202D */   daddu    $a0, $s1, $zero
/* 3185E8 802BD898 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 3185EC 802BD89C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 3185F0 802BD8A0 24020004 */  addiu     $v0, $zero, 4
/* 3185F4 802BD8A4 A622008E */  sh        $v0, 0x8e($s1)
/* 3185F8 802BD8A8 8E660028 */  lw        $a2, 0x28($s3)
/* 3185FC 802BD8AC 0C00A720 */  jal       atan2
/* 318600 802BD8B0 8E670030 */   lw       $a3, 0x30($s3)
/* 318604 802BD8B4 3C040001 */  lui       $a0, 1
/* 318608 802BD8B8 34840002 */  ori       $a0, $a0, 2
/* 31860C 802BD8BC 0C037FBF */  jal       func_800DFEFC
/* 318610 802BD8C0 E620000C */   swc1     $f0, 0xc($s1)
/* 318614 802BD8C4 24020015 */  addiu     $v0, $zero, 0x15
/* 318618 802BD8C8 AE420070 */  sw        $v0, 0x70($s2)
.L802BD8CC:
/* 31861C 802BD8CC 926200B4 */  lbu       $v0, 0xb4($s3)
/* 318620 802BD8D0 2442FFEB */  addiu     $v0, $v0, -0x15
/* 318624 802BD8D4 2C420002 */  sltiu     $v0, $v0, 2
/* 318628 802BD8D8 10400005 */  beqz      $v0, .L802BD8F0
/* 31862C 802BD8DC 00000000 */   nop      
/* 318630 802BD8E0 0C00EB6B */  jal       disable_npc_blur
/* 318634 802BD8E4 0220202D */   daddu    $a0, $s1, $zero
/* 318638 802BD8E8 080AF6E4 */  j         .L802BDB90
/* 31863C 802BD8EC 24020007 */   addiu    $v0, $zero, 7
.L802BD8F0:
/* 318640 802BD8F0 8E620000 */  lw        $v0, ($s3)
/* 318644 802BD8F4 30420002 */  andi      $v0, $v0, 2
/* 318648 802BD8F8 144000A5 */  bnez      $v0, .L802BDB90
/* 31864C 802BD8FC 24020007 */   addiu    $v0, $zero, 7
/* 318650 802BD900 3C020003 */  lui       $v0, 3
/* 318654 802BD904 C6600028 */  lwc1      $f0, 0x28($s3)
/* 318658 802BD908 34420007 */  ori       $v0, $v0, 7
/* 31865C 802BD90C E6200060 */  swc1      $f0, 0x60($s1)
/* 318660 802BD910 C660002C */  lwc1      $f0, 0x2c($s3)
/* 318664 802BD914 26240060 */  addiu     $a0, $s1, 0x60
/* 318668 802BD918 E6200064 */  swc1      $f0, 0x64($s1)
/* 31866C 802BD91C C6600030 */  lwc1      $f0, 0x30($s3)
/* 318670 802BD920 26250068 */  addiu     $a1, $s1, 0x68
/* 318674 802BD924 AE220028 */  sw        $v0, 0x28($s1)
/* 318678 802BD928 E6200068 */  swc1      $f0, 0x68($s1)
/* 31867C 802BD92C 8E670080 */  lw        $a3, 0x80($s3)
/* 318680 802BD930 0C00A7E7 */  jal       add_vec2D_polar
/* 318684 802BD934 0000302D */   daddu    $a2, $zero, $zero
/* 318688 802BD938 3C02802C */  lui       $v0, 0x802c
/* 31868C 802BD93C 8C42E920 */  lw        $v0, -0x16e0($v0)
/* 318690 802BD940 C66C0080 */  lwc1      $f12, 0x80($s3)
/* 318694 802BD944 3C0142B4 */  lui       $at, 0x42b4
/* 318698 802BD948 44810000 */  mtc1      $at, $f0
/* 31869C 802BD94C 10400003 */  beqz      $v0, .L802BD95C
/* 3186A0 802BD950 00000000 */   nop      
/* 3186A4 802BD954 3C01C2B4 */  lui       $at, 0xc2b4
/* 3186A8 802BD958 44810000 */  mtc1      $at, $f0
.L802BD95C:
/* 3186AC 802BD95C 0C00A6C9 */  jal       clamp_angle
/* 3186B0 802BD960 46006300 */   add.s    $f12, $f12, $f0
/* 3186B4 802BD964 866200B2 */  lh        $v0, 0xb2($s3)
/* 3186B8 802BD968 26240060 */  addiu     $a0, $s1, 0x60
/* 3186BC 802BD96C 04410002 */  bgez      $v0, .L802BD978
/* 3186C0 802BD970 26250068 */   addiu    $a1, $s1, 0x68
/* 3186C4 802BD974 24420003 */  addiu     $v0, $v0, 3
.L802BD978:
/* 3186C8 802BD978 00021083 */  sra       $v0, $v0, 2
/* 3186CC 802BD97C 44828000 */  mtc1      $v0, $f16
/* 3186D0 802BD980 00000000 */  nop       
/* 3186D4 802BD984 46808420 */  cvt.s.w   $f16, $f16
/* 3186D8 802BD988 44070000 */  mfc1      $a3, $f0
/* 3186DC 802BD98C 44068000 */  mfc1      $a2, $f16
/* 3186E0 802BD990 0C00A7E7 */  jal       add_vec2D_polar
/* 3186E4 802BD994 00000000 */   nop      
/* 3186E8 802BD998 C6200060 */  lwc1      $f0, 0x60($s1)
/* 3186EC 802BD99C C62A0038 */  lwc1      $f10, 0x38($s1)
/* 3186F0 802BD9A0 8622008E */  lh        $v0, 0x8e($s1)
/* 3186F4 802BD9A4 C6240064 */  lwc1      $f4, 0x64($s1)
/* 3186F8 802BD9A8 C628003C */  lwc1      $f8, 0x3c($s1)
/* 3186FC 802BD9AC C6260040 */  lwc1      $f6, 0x40($s1)
/* 318700 802BD9B0 44821000 */  mtc1      $v0, $f2
/* 318704 802BD9B4 00000000 */  nop       
/* 318708 802BD9B8 468010A0 */  cvt.s.w   $f2, $f2
/* 31870C 802BD9BC 0040202D */  daddu     $a0, $v0, $zero
/* 318710 802BD9C0 460A0001 */  sub.s     $f0, $f0, $f10
/* 318714 802BD9C4 0080182D */  daddu     $v1, $a0, $zero
/* 318718 802BD9C8 9622008E */  lhu       $v0, 0x8e($s1)
/* 31871C 802BD9CC 46082101 */  sub.s     $f4, $f4, $f8
/* 318720 802BD9D0 2442FFFF */  addiu     $v0, $v0, -1
/* 318724 802BD9D4 A622008E */  sh        $v0, 0x8e($s1)
/* 318728 802BD9D8 46020003 */  div.s     $f0, $f0, $f2
/* 31872C 802BD9DC 46005280 */  add.s     $f10, $f10, $f0
/* 318730 802BD9E0 C6220068 */  lwc1      $f2, 0x68($s1)
/* 318734 802BD9E4 00021400 */  sll       $v0, $v0, 0x10
/* 318738 802BD9E8 46061081 */  sub.s     $f2, $f2, $f6
/* 31873C 802BD9EC 44840000 */  mtc1      $a0, $f0
/* 318740 802BD9F0 00000000 */  nop       
/* 318744 802BD9F4 46800020 */  cvt.s.w   $f0, $f0
/* 318748 802BD9F8 46002103 */  div.s     $f4, $f4, $f0
/* 31874C 802BD9FC 46044200 */  add.s     $f8, $f8, $f4
/* 318750 802BDA00 44830000 */  mtc1      $v1, $f0
/* 318754 802BDA04 00000000 */  nop       
/* 318758 802BDA08 46800020 */  cvt.s.w   $f0, $f0
/* 31875C 802BDA0C 46001083 */  div.s     $f2, $f2, $f0
/* 318760 802BDA10 46023180 */  add.s     $f6, $f6, $f2
/* 318764 802BDA14 E62A0038 */  swc1      $f10, 0x38($s1)
/* 318768 802BDA18 E628003C */  swc1      $f8, 0x3c($s1)
/* 31876C 802BDA1C 144000F2 */  bnez      $v0, .L802BDDE8
/* 318770 802BDA20 E6260040 */   swc1     $f6, 0x40($s1)
/* 318774 802BDA24 82630015 */  lb        $v1, 0x15($s3)
/* 318778 802BDA28 8E42007C */  lw        $v0, 0x7c($s2)
/* 31877C 802BDA2C 0043102A */  slt       $v0, $v0, $v1
/* 318780 802BDA30 10400005 */  beqz      $v0, .L802BDA48
/* 318784 802BDA34 0220202D */   daddu    $a0, $s1, $zero
/* 318788 802BDA38 0C00EB6B */  jal       disable_npc_blur
/* 31878C 802BDA3C 0220202D */   daddu    $a0, $s1, $zero
/* 318790 802BDA40 080AF6E4 */  j         .L802BDB90
/* 318794 802BDA44 24020007 */   addiu    $v0, $zero, 7
.L802BDA48:
/* 318798 802BDA48 C6200060 */  lwc1      $f0, 0x60($s1)
/* 31879C 802BDA4C C6220064 */  lwc1      $f2, 0x64($s1)
/* 3187A0 802BDA50 C6240068 */  lwc1      $f4, 0x68($s1)
/* 3187A4 802BDA54 E6200038 */  swc1      $f0, 0x38($s1)
/* 3187A8 802BDA58 E622003C */  swc1      $f2, 0x3c($s1)
/* 3187AC 802BDA5C 0C00EB6B */  jal       disable_npc_blur
/* 3187B0 802BDA60 E6240040 */   swc1     $f4, 0x40($s1)
/* 3187B4 802BDA64 3C040006 */  lui       $a0, 6
/* 3187B8 802BDA68 0C037FBF */  jal       func_800DFEFC
/* 3187BC 802BDA6C 3484000C */   ori      $a0, $a0, 0xc
/* 3187C0 802BDA70 3C020003 */  lui       $v0, 3
/* 3187C4 802BDA74 C6600080 */  lwc1      $f0, 0x80($s3)
/* 3187C8 802BDA78 34420005 */  ori       $v0, $v0, 5
/* 3187CC 802BDA7C AE220028 */  sw        $v0, 0x28($s1)
/* 3187D0 802BDA80 24020001 */  addiu     $v0, $zero, 1
/* 3187D4 802BDA84 E620000C */  swc1      $f0, 0xc($s1)
/* 3187D8 802BDA88 AE420070 */  sw        $v0, 0x70($s2)
/* 3187DC 802BDA8C 2402000A */  addiu     $v0, $zero, 0xa
/* 3187E0 802BDA90 AE420074 */  sw        $v0, 0x74($s2)
.L802BDA94:
/* 3187E4 802BDA94 926200B4 */  lbu       $v0, 0xb4($s3)
/* 3187E8 802BDA98 2442FFEB */  addiu     $v0, $v0, -0x15
/* 3187EC 802BDA9C 2C420002 */  sltiu     $v0, $v0, 2
/* 3187F0 802BDAA0 1440003B */  bnez      $v0, .L802BDB90
/* 3187F4 802BDAA4 24020007 */   addiu    $v0, $zero, 7
/* 3187F8 802BDAA8 866200B0 */  lh        $v0, 0xb0($s3)
/* 3187FC 802BDAAC C660002C */  lwc1      $f0, 0x2c($s3)
/* 318800 802BDAB0 44821000 */  mtc1      $v0, $f2
/* 318804 802BDAB4 00000000 */  nop       
/* 318808 802BDAB8 468010A0 */  cvt.s.w   $f2, $f2
/* 31880C 802BDABC 46020000 */  add.s     $f0, $f0, $f2
/* 318810 802BDAC0 E620003C */  swc1      $f0, 0x3c($s1)
/* 318814 802BDAC4 C6600080 */  lwc1      $f0, 0x80($s3)
/* 318818 802BDAC8 E620000C */  swc1      $f0, 0xc($s1)
/* 31881C 802BDACC 8E420074 */  lw        $v0, 0x74($s2)
/* 318820 802BDAD0 24100001 */  addiu     $s0, $zero, 1
/* 318824 802BDAD4 14500005 */  bne       $v0, $s0, .L802BDAEC
/* 318828 802BDAD8 00000000 */   nop      
/* 31882C 802BDADC 3C040006 */  lui       $a0, 6
/* 318830 802BDAE0 0C037FBF */  jal       func_800DFEFC
/* 318834 802BDAE4 34840006 */   ori      $a0, $a0, 6
/* 318838 802BDAE8 8E420074 */  lw        $v0, 0x74($s2)
.L802BDAEC:
/* 31883C 802BDAEC 144000A8 */  bnez      $v0, .L802BDD90
/* 318840 802BDAF0 2442FFFF */   addiu    $v0, $v0, -1
/* 318844 802BDAF4 3C048000 */  lui       $a0, 0x8000
/* 318848 802BDAF8 0000282D */  daddu     $a1, $zero, $zero
/* 31884C 802BDAFC 0C052742 */  jal       play_sound_at_npc
/* 318850 802BDB00 2406FFFC */   addiu    $a2, $zero, -4
/* 318854 802BDB04 26240038 */  addiu     $a0, $s1, 0x38
/* 318858 802BDB08 4480A000 */  mtc1      $zero, $f20
/* 31885C 802BDB0C 8E27000C */  lw        $a3, 0xc($s1)
/* 318860 802BDB10 4406A000 */  mfc1      $a2, $f20
/* 318864 802BDB14 3C01802C */  lui       $at, 0x802c
/* 318868 802BDB18 AC30E924 */  sw        $s0, -0x16dc($at)
/* 31886C 802BDB1C 0C00A7E7 */  jal       add_vec2D_polar
/* 318870 802BDB20 26250040 */   addiu    $a1, $s1, 0x40
/* 318874 802BDB24 3C030003 */  lui       $v1, 3
/* 318878 802BDB28 8E220000 */  lw        $v0, ($s1)
/* 31887C 802BDB2C 3C013F80 */  lui       $at, 0x3f80
/* 318880 802BDB30 44810000 */  mtc1      $at, $f0
/* 318884 802BDB34 34630006 */  ori       $v1, $v1, 6
/* 318888 802BDB38 AE230028 */  sw        $v1, 0x28($s1)
/* 31888C 802BDB3C 2403FEFF */  addiu     $v1, $zero, -0x101
/* 318890 802BDB40 E634001C */  swc1      $f20, 0x1c($s1)
/* 318894 802BDB44 3C01802C */  lui       $at, 0x802c
/* 318898 802BDB48 AC20E938 */  sw        $zero, -0x16c8($at)
/* 31889C 802BDB4C 34420200 */  ori       $v0, $v0, 0x200
/* 3188A0 802BDB50 00431024 */  and       $v0, $v0, $v1
/* 3188A4 802BDB54 AE220000 */  sw        $v0, ($s1)
/* 3188A8 802BDB58 24020002 */  addiu     $v0, $zero, 2
/* 3188AC 802BDB5C E6200018 */  swc1      $f0, 0x18($s1)
/* 3188B0 802BDB60 AE420070 */  sw        $v0, 0x70($s2)
/* 3188B4 802BDB64 24020032 */  addiu     $v0, $zero, 0x32
/* 3188B8 802BDB68 AE420074 */  sw        $v0, 0x74($s2)
.L802BDB6C:
/* 3188BC 802BDB6C 8E620004 */  lw        $v0, 4($s3)
/* 3188C0 802BDB70 30420004 */  andi      $v0, $v0, 4
/* 3188C4 802BDB74 14400006 */  bnez      $v0, .L802BDB90
/* 3188C8 802BDB78 24020007 */   addiu    $v0, $zero, 7
/* 3188CC 802BDB7C 926200B4 */  lbu       $v0, 0xb4($s3)
/* 3188D0 802BDB80 2442FFEB */  addiu     $v0, $v0, -0x15
/* 3188D4 802BDB84 2C420002 */  sltiu     $v0, $v0, 2
/* 3188D8 802BDB88 10400003 */  beqz      $v0, .L802BDB98
/* 3188DC 802BDB8C 24020007 */   addiu    $v0, $zero, 7
.L802BDB90:
/* 3188E0 802BDB90 080AF77A */  j         .L802BDDE8
/* 3188E4 802BDB94 AE420070 */   sw       $v0, 0x70($s2)
.L802BDB98:
/* 3188E8 802BDB98 8E420074 */  lw        $v0, 0x74($s2)
/* 3188EC 802BDB9C 2842002D */  slti      $v0, $v0, 0x2d
/* 3188F0 802BDBA0 10400015 */  beqz      $v0, .L802BDBF8
/* 3188F4 802BDBA4 3C040001 */   lui      $a0, 1
/* 3188F8 802BDBA8 8E220000 */  lw        $v0, ($s1)
/* 3188FC 802BDBAC 30422000 */  andi      $v0, $v0, 0x2000
/* 318900 802BDBB0 1440000E */  bnez      $v0, .L802BDBEC
/* 318904 802BDBB4 24020001 */   addiu    $v0, $zero, 1
/* 318908 802BDBB8 3C02802C */  lui       $v0, 0x802c
/* 31890C 802BDBBC 8C42E938 */  lw        $v0, -0x16c8($v0)
/* 318910 802BDBC0 1440000A */  bnez      $v0, .L802BDBEC
/* 318914 802BDBC4 24020001 */   addiu    $v0, $zero, 1
/* 318918 802BDBC8 8E250018 */  lw        $a1, 0x18($s1)
/* 31891C 802BDBCC 8E26000C */  lw        $a2, 0xc($s1)
/* 318920 802BDBD0 0C00EA95 */  jal       npc_move_heading
/* 318924 802BDBD4 0220202D */   daddu    $a0, $s1, $zero
/* 318928 802BDBD8 0220202D */  daddu     $a0, $s1, $zero
/* 31892C 802BDBDC 0C00F598 */  jal       func_8003D660
/* 318930 802BDBE0 0000282D */   daddu    $a1, $zero, $zero
/* 318934 802BDBE4 080AF6FE */  j         .L802BDBF8
/* 318938 802BDBE8 3C040001 */   lui      $a0, 1
.L802BDBEC:
/* 31893C 802BDBEC 3C01802C */  lui       $at, 0x802c
/* 318940 802BDBF0 AC22E938 */  sw        $v0, -0x16c8($at)
/* 318944 802BDBF4 3C040001 */  lui       $a0, 1
.L802BDBF8:
/* 318948 802BDBF8 27A50020 */  addiu     $a1, $sp, 0x20
/* 31894C 802BDBFC C6200038 */  lwc1      $f0, 0x38($s1)
/* 318950 802BDC00 3C014160 */  lui       $at, 0x4160
/* 318954 802BDC04 44811000 */  mtc1      $at, $f2
/* 318958 802BDC08 3C014180 */  lui       $at, 0x4180
/* 31895C 802BDC0C 44813000 */  mtc1      $at, $f6
/* 318960 802BDC10 27A2002C */  addiu     $v0, $sp, 0x2c
/* 318964 802BDC14 E7A00020 */  swc1      $f0, 0x20($sp)
/* 318968 802BDC18 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31896C 802BDC1C C6240040 */  lwc1      $f4, 0x40($s1)
/* 318970 802BDC20 46020000 */  add.s     $f0, $f0, $f2
/* 318974 802BDC24 E7A6002C */  swc1      $f6, 0x2c($sp)
/* 318978 802BDC28 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31897C 802BDC2C E7A00024 */  swc1      $f0, 0x24($sp)
/* 318980 802BDC30 AFA20010 */  sw        $v0, 0x10($sp)
/* 318984 802BDC34 C620000C */  lwc1      $f0, 0xc($s1)
/* 318988 802BDC38 27A60024 */  addiu     $a2, $sp, 0x24
/* 31898C 802BDC3C E7A00014 */  swc1      $f0, 0x14($sp)
/* 318990 802BDC40 862200A6 */  lh        $v0, 0xa6($s1)
/* 318994 802BDC44 27A70028 */  addiu     $a3, $sp, 0x28
/* 318998 802BDC48 44820000 */  mtc1      $v0, $f0
/* 31899C 802BDC4C 00000000 */  nop       
/* 3189A0 802BDC50 46800020 */  cvt.s.w   $f0, $f0
/* 3189A4 802BDC54 0C0371DE */  jal       func_800DC778
/* 3189A8 802BDC58 E7A00018 */   swc1     $f0, 0x18($sp)
/* 3189AC 802BDC5C 10400023 */  beqz      $v0, .L802BDCEC
/* 3189B0 802BDC60 00000000 */   nop      
/* 3189B4 802BDC64 3C048011 */  lui       $a0, 0x8011
/* 3189B8 802BDC68 8C84C978 */  lw        $a0, -0x3688($a0)
/* 3189BC 802BDC6C 0C016F6A */  jal       get_collider_type_by_id
/* 3189C0 802BDC70 00000000 */   nop      
/* 3189C4 802BDC74 304200FF */  andi      $v0, $v0, 0xff
/* 3189C8 802BDC78 2442FFFE */  addiu     $v0, $v0, -2
/* 3189CC 802BDC7C 2C420002 */  sltiu     $v0, $v0, 2
/* 3189D0 802BDC80 1040001A */  beqz      $v0, .L802BDCEC
/* 3189D4 802BDC84 00000000 */   nop      
/* 3189D8 802BDC88 826200B4 */  lb        $v0, 0xb4($s3)
/* 3189DC 802BDC8C 14400005 */  bnez      $v0, .L802BDCA4
/* 3189E0 802BDC90 3C020003 */   lui      $v0, 3
/* 3189E4 802BDC94 3C040001 */  lui       $a0, 1
/* 3189E8 802BDC98 0C037FBF */  jal       func_800DFEFC
/* 3189EC 802BDC9C 34840002 */   ori      $a0, $a0, 2
/* 3189F0 802BDCA0 3C020003 */  lui       $v0, 3
.L802BDCA4:
/* 3189F4 802BDCA4 34420010 */  ori       $v0, $v0, 0x10
/* 3189F8 802BDCA8 2403FDFF */  addiu     $v1, $zero, -0x201
/* 3189FC 802BDCAC AE220028 */  sw        $v0, 0x28($s1)
/* 318A00 802BDCB0 8E220000 */  lw        $v0, ($s1)
/* 318A04 802BDCB4 3C04802C */  lui       $a0, 0x802c
/* 318A08 802BDCB8 2484E92C */  addiu     $a0, $a0, -0x16d4
/* 318A0C 802BDCBC 00431024 */  and       $v0, $v0, $v1
/* 318A10 802BDCC0 AE220000 */  sw        $v0, ($s1)
/* 318A14 802BDCC4 24020002 */  addiu     $v0, $zero, 2
/* 318A18 802BDCC8 AE420074 */  sw        $v0, 0x74($s2)
/* 318A1C 802BDCCC 8C830000 */  lw        $v1, ($a0)
/* 318A20 802BDCD0 24020003 */  addiu     $v0, $zero, 3
/* 318A24 802BDCD4 10600044 */  beqz      $v1, .L802BDDE8
/* 318A28 802BDCD8 AE420070 */   sw       $v0, 0x70($s2)
/* 318A2C 802BDCDC 0C038069 */  jal       enable_player_input
/* 318A30 802BDCE0 AC800000 */   sw       $zero, ($a0)
/* 318A34 802BDCE4 080AF77A */  j         .L802BDDE8
/* 318A38 802BDCE8 00000000 */   nop      
.L802BDCEC:
/* 318A3C 802BDCEC 8E420074 */  lw        $v0, 0x74($s2)
/* 318A40 802BDCF0 30420003 */  andi      $v0, $v0, 3
/* 318A44 802BDCF4 1440000B */  bnez      $v0, .L802BDD24
/* 318A48 802BDCF8 00000000 */   nop      
/* 318A4C 802BDCFC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 318A50 802BDD00 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 318A54 802BDD04 94420134 */  lhu       $v0, 0x134($v0)
/* 318A58 802BDD08 30420001 */  andi      $v0, $v0, 1
/* 318A5C 802BDD0C 10400002 */  beqz      $v0, .L802BDD18
/* 318A60 802BDD10 24040142 */   addiu    $a0, $zero, 0x142
/* 318A64 802BDD14 24040141 */  addiu     $a0, $zero, 0x141
.L802BDD18:
/* 318A68 802BDD18 0000282D */  daddu     $a1, $zero, $zero
/* 318A6C 802BDD1C 0C052742 */  jal       play_sound_at_npc
/* 318A70 802BDD20 2406FFFC */   addiu    $a2, $zero, -4
.L802BDD24:
/* 318A74 802BDD24 8E430074 */  lw        $v1, 0x74($s2)
/* 318A78 802BDD28 24020028 */  addiu     $v0, $zero, 0x28
/* 318A7C 802BDD2C 1462000A */  bne       $v1, $v0, .L802BDD58
/* 318A80 802BDD30 00000000 */   nop      
/* 318A84 802BDD34 826200B4 */  lb        $v0, 0xb4($s3)
/* 318A88 802BDD38 14400003 */  bnez      $v0, .L802BDD48
/* 318A8C 802BDD3C 3C040001 */   lui      $a0, 1
/* 318A90 802BDD40 0C037FBF */  jal       func_800DFEFC
/* 318A94 802BDD44 34840002 */   ori      $a0, $a0, 2
.L802BDD48:
/* 318A98 802BDD48 0C038069 */  jal       enable_player_input
/* 318A9C 802BDD4C 00000000 */   nop      
/* 318AA0 802BDD50 3C01802C */  lui       $at, 0x802c
/* 318AA4 802BDD54 AC20E92C */  sw        $zero, -0x16d4($at)
.L802BDD58:
/* 318AA8 802BDD58 0C00E403 */  jal       npc_do_other_npc_collision
/* 318AAC 802BDD5C 0220202D */   daddu    $a0, $s1, $zero
/* 318AB0 802BDD60 8E220000 */  lw        $v0, ($s1)
/* 318AB4 802BDD64 3C030200 */  lui       $v1, 0x200
/* 318AB8 802BDD68 00431024 */  and       $v0, $v0, $v1
/* 318ABC 802BDD6C 1440000A */  bnez      $v0, .L802BDD98
/* 318AC0 802BDD70 00000000 */   nop      
/* 318AC4 802BDD74 3C02802C */  lui       $v0, 0x802c
/* 318AC8 802BDD78 8C42E934 */  lw        $v0, -0x16cc($v0)
/* 318ACC 802BDD7C 1440000E */  bnez      $v0, .L802BDDB8
/* 318AD0 802BDD80 3C020003 */   lui      $v0, 3
/* 318AD4 802BDD84 8E420074 */  lw        $v0, 0x74($s2)
/* 318AD8 802BDD88 1040000A */  beqz      $v0, .L802BDDB4
/* 318ADC 802BDD8C 2442FFFF */   addiu    $v0, $v0, -1
.L802BDD90:
/* 318AE0 802BDD90 080AF77A */  j         .L802BDDE8
/* 318AE4 802BDD94 AE420074 */   sw       $v0, 0x74($s2)
.L802BDD98:
/* 318AE8 802BDD98 3C03802C */  lui       $v1, 0x802c
/* 318AEC 802BDD9C 2463E92C */  addiu     $v1, $v1, -0x16d4
/* 318AF0 802BDDA0 8C620000 */  lw        $v0, ($v1)
/* 318AF4 802BDDA4 10400004 */  beqz      $v0, .L802BDDB8
/* 318AF8 802BDDA8 3C020003 */   lui      $v0, 3
/* 318AFC 802BDDAC 0C038069 */  jal       enable_player_input
/* 318B00 802BDDB0 AC600000 */   sw       $zero, ($v1)
.L802BDDB4:
/* 318B04 802BDDB4 3C020003 */  lui       $v0, 3
.L802BDDB8:
/* 318B08 802BDDB8 34420010 */  ori       $v0, $v0, 0x10
/* 318B0C 802BDDBC AE220028 */  sw        $v0, 0x28($s1)
/* 318B10 802BDDC0 24020014 */  addiu     $v0, $zero, 0x14
/* 318B14 802BDDC4 AE420074 */  sw        $v0, 0x74($s2)
/* 318B18 802BDDC8 24020003 */  addiu     $v0, $zero, 3
/* 318B1C 802BDDCC AE420070 */  sw        $v0, 0x70($s2)
/* 318B20 802BDDD0 826200B4 */  lb        $v0, 0xb4($s3)
/* 318B24 802BDDD4 14400004 */  bnez      $v0, .L802BDDE8
/* 318B28 802BDDD8 00000000 */   nop      
/* 318B2C 802BDDDC 3C040001 */  lui       $a0, 1
/* 318B30 802BDDE0 0C037FBF */  jal       func_800DFEFC
/* 318B34 802BDDE4 34840002 */   ori      $a0, $a0, 2
.L802BDDE8:
/* 318B38 802BDDE8 8E430070 */  lw        $v1, 0x70($s2)
/* 318B3C 802BDDEC 24020004 */  addiu     $v0, $zero, 4
.L802BDDF0:
/* 318B40 802BDDF0 10620062 */  beq       $v1, $v0, .L802BDF7C
/* 318B44 802BDDF4 28620005 */   slti     $v0, $v1, 5
/* 318B48 802BDDF8 10400005 */  beqz      $v0, .L802BDE10
/* 318B4C 802BDDFC 24020003 */   addiu    $v0, $zero, 3
/* 318B50 802BDE00 1062000A */  beq       $v1, $v0, .L802BDE2C
/* 318B54 802BDE04 00000000 */   nop      
/* 318B58 802BDE08 080AF8BE */  j         .L802BE2F8
/* 318B5C 802BDE0C 00000000 */   nop      
.L802BDE10:
/* 318B60 802BDE10 24020005 */  addiu     $v0, $zero, 5
/* 318B64 802BDE14 106200A0 */  beq       $v1, $v0, .L802BE098
/* 318B68 802BDE18 24020006 */   addiu    $v0, $zero, 6
/* 318B6C 802BDE1C 106200E3 */  beq       $v1, $v0, .L802BE1AC
/* 318B70 802BDE20 00000000 */   nop      
/* 318B74 802BDE24 080AF8BE */  j         .L802BE2F8
/* 318B78 802BDE28 00000000 */   nop      
.L802BDE2C:
/* 318B7C 802BDE2C 8E420074 */  lw        $v0, 0x74($s2)
/* 318B80 802BDE30 144000BF */  bnez      $v0, .L802BE130
/* 318B84 802BDE34 2442FFFF */   addiu    $v0, $v0, -1
/* 318B88 802BDE38 3C03802C */  lui       $v1, 0x802c
/* 318B8C 802BDE3C 2463E924 */  addiu     $v1, $v1, -0x16dc
/* 318B90 802BDE40 8C620000 */  lw        $v0, ($v1)
/* 318B94 802BDE44 10400004 */  beqz      $v0, .L802BDE58
/* 318B98 802BDE48 00000000 */   nop      
/* 318B9C 802BDE4C AC600000 */  sw        $zero, ($v1)
/* 318BA0 802BDE50 0C05271B */  jal       stop_sound
/* 318BA4 802BDE54 3C048000 */   lui      $a0, 0x8000
.L802BDE58:
/* 318BA8 802BDE58 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 318BAC 802BDE5C 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 318BB0 802BDE60 8E250038 */  lw        $a1, 0x38($s1)
/* 318BB4 802BDE64 862200A8 */  lh        $v0, 0xa8($s1)
/* 318BB8 802BDE68 3C013F00 */  lui       $at, 0x3f00
/* 318BBC 802BDE6C 44811000 */  mtc1      $at, $f2
/* 318BC0 802BDE70 44820000 */  mtc1      $v0, $f0
/* 318BC4 802BDE74 00000000 */  nop       
/* 318BC8 802BDE78 46800020 */  cvt.s.w   $f0, $f0
/* 318BCC 802BDE7C 46020002 */  mul.s     $f0, $f0, $f2
/* 318BD0 802BDE80 00000000 */  nop       
/* 318BD4 802BDE84 8E270040 */  lw        $a3, 0x40($s1)
/* 318BD8 802BDE88 82020012 */  lb        $v0, 0x12($s0)
/* 318BDC 802BDE8C C622003C */  lwc1      $f2, 0x3c($s1)
/* 318BE0 802BDE90 000210C0 */  sll       $v0, $v0, 3
/* 318BE4 802BDE94 46001080 */  add.s     $f2, $f2, $f0
/* 318BE8 802BDE98 00501021 */  addu      $v0, $v0, $s0
/* 318BEC 802BDE9C 80440015 */  lb        $a0, 0x15($v0)
/* 318BF0 802BDEA0 44061000 */  mfc1      $a2, $f2
/* 318BF4 802BDEA4 0C01C07C */  jal       func_800701F0
/* 318BF8 802BDEA8 00000000 */   nop      
/* 318BFC 802BDEAC 82020012 */  lb        $v0, 0x12($s0)
/* 318C00 802BDEB0 000210C0 */  sll       $v0, $v0, 3
/* 318C04 802BDEB4 00501021 */  addu      $v0, $v0, $s0
/* 318C08 802BDEB8 80430015 */  lb        $v1, 0x15($v0)
/* 318C0C 802BDEBC 24020001 */  addiu     $v0, $zero, 1
/* 318C10 802BDEC0 1062000D */  beq       $v1, $v0, .L802BDEF8
/* 318C14 802BDEC4 28620002 */   slti     $v0, $v1, 2
/* 318C18 802BDEC8 10400005 */  beqz      $v0, .L802BDEE0
/* 318C1C 802BDECC 24020002 */   addiu    $v0, $zero, 2
/* 318C20 802BDED0 10600007 */  beqz      $v1, .L802BDEF0
/* 318C24 802BDED4 0000202D */   daddu    $a0, $zero, $zero
/* 318C28 802BDED8 080AF7C6 */  j         .L802BDF18
/* 318C2C 802BDEDC 0080282D */   daddu    $a1, $a0, $zero
.L802BDEE0:
/* 318C30 802BDEE0 10620007 */  beq       $v1, $v0, .L802BDF00
/* 318C34 802BDEE4 0000202D */   daddu    $a0, $zero, $zero
/* 318C38 802BDEE8 080AF7C6 */  j         .L802BDF18
/* 318C3C 802BDEEC 0080282D */   daddu    $a1, $a0, $zero
.L802BDEF0:
/* 318C40 802BDEF0 080AF7C1 */  j         .L802BDF04
/* 318C44 802BDEF4 24042016 */   addiu    $a0, $zero, 0x2016
.L802BDEF8:
/* 318C48 802BDEF8 080AF7C1 */  j         .L802BDF04
/* 318C4C 802BDEFC 24042017 */   addiu    $a0, $zero, 0x2017
.L802BDF00:
/* 318C50 802BDF00 24042018 */  addiu     $a0, $zero, 0x2018
.L802BDF04:
/* 318C54 802BDF04 0000282D */  daddu     $a1, $zero, $zero
/* 318C58 802BDF08 0C052742 */  jal       play_sound_at_npc
/* 318C5C 802BDF0C 2406FFFC */   addiu    $a2, $zero, -4
/* 318C60 802BDF10 0000202D */  daddu     $a0, $zero, $zero
/* 318C64 802BDF14 0080282D */  daddu     $a1, $a0, $zero
.L802BDF18:
/* 318C68 802BDF18 0C0B2D5B */  jal       exec_ShakeCam1
/* 318C6C 802BDF1C 24060014 */   addiu    $a2, $zero, 0x14
/* 318C70 802BDF20 0220202D */  daddu     $a0, $s1, $zero
/* 318C74 802BDF24 0C00F598 */  jal       func_8003D660
/* 318C78 802BDF28 24050002 */   addiu    $a1, $zero, 2
/* 318C7C 802BDF2C A6800018 */  sh        $zero, 0x18($s4)
/* 318C80 802BDF30 C6200038 */  lwc1      $f0, 0x38($s1)
/* 318C84 802BDF34 E680001C */  swc1      $f0, 0x1c($s4)
/* 318C88 802BDF38 C620003C */  lwc1      $f0, 0x3c($s1)
/* 318C8C 802BDF3C E6800020 */  swc1      $f0, 0x20($s4)
/* 318C90 802BDF40 C6200040 */  lwc1      $f0, 0x40($s1)
/* 318C94 802BDF44 0220202D */  daddu     $a0, $s1, $zero
/* 318C98 802BDF48 0C0AF440 */  jal       func_802BD100
/* 318C9C 802BDF4C E6800024 */   swc1     $f0, 0x24($s4)
/* 318CA0 802BDF50 24020001 */  addiu     $v0, $zero, 1
/* 318CA4 802BDF54 3C01802C */  lui       $at, 0x802c
/* 318CA8 802BDF58 AC22E928 */  sw        $v0, -0x16d8($at)
/* 318CAC 802BDF5C 24020002 */  addiu     $v0, $zero, 2
/* 318CB0 802BDF60 A2A20000 */  sb        $v0, ($s5)
/* 318CB4 802BDF64 8E420070 */  lw        $v0, 0x70($s2)
/* 318CB8 802BDF68 24030003 */  addiu     $v1, $zero, 3
/* 318CBC 802BDF6C AE430074 */  sw        $v1, 0x74($s2)
/* 318CC0 802BDF70 24420001 */  addiu     $v0, $v0, 1
/* 318CC4 802BDF74 080AF8BE */  j         .L802BE2F8
/* 318CC8 802BDF78 AE420070 */   sw       $v0, 0x70($s2)
.L802BDF7C:
/* 318CCC 802BDF7C 8E420074 */  lw        $v0, 0x74($s2)
/* 318CD0 802BDF80 1440006B */  bnez      $v0, .L802BE130
/* 318CD4 802BDF84 2442FFFF */   addiu    $v0, $v0, -1
/* 318CD8 802BDF88 24020003 */  addiu     $v0, $zero, 3
/* 318CDC 802BDF8C A2A20000 */  sb        $v0, ($s5)
/* 318CE0 802BDF90 C660002C */  lwc1      $f0, 0x2c($s3)
/* 318CE4 802BDF94 C622003C */  lwc1      $f2, 0x3c($s1)
/* 318CE8 802BDF98 24040168 */  addiu     $a0, $zero, 0x168
/* 318CEC 802BDF9C 46020001 */  sub.s     $f0, $f0, $f2
/* 318CF0 802BDFA0 3C0141A0 */  lui       $at, 0x41a0
/* 318CF4 802BDFA4 44811000 */  mtc1      $at, $f2
/* 318CF8 802BDFA8 3C013F4C */  lui       $at, 0x3f4c
/* 318CFC 802BDFAC 3421CCCD */  ori       $at, $at, 0xcccd
/* 318D00 802BDFB0 4481A000 */  mtc1      $at, $f20
/* 318D04 802BDFB4 46020003 */  div.s     $f0, $f0, $f2
/* 318D08 802BDFB8 3C01403E */  lui       $at, 0x403e
/* 318D0C 802BDFBC 44811800 */  mtc1      $at, $f3
/* 318D10 802BDFC0 44801000 */  mtc1      $zero, $f2
/* 318D14 802BDFC4 46000021 */  cvt.d.s   $f0, $f0
/* 318D18 802BDFC8 46220000 */  add.d     $f0, $f0, $f2
/* 318D1C 802BDFCC 3C01802C */  lui       $at, 0x802c
/* 318D20 802BDFD0 AC20E928 */  sw        $zero, -0x16d8($at)
/* 318D24 802BDFD4 E6340018 */  swc1      $f20, 0x18($s1)
/* 318D28 802BDFD8 46200020 */  cvt.s.d   $f0, $f0
/* 318D2C 802BDFDC 0C00A67F */  jal       rand_int
/* 318D30 802BDFE0 E620001C */   swc1     $f0, 0x1c($s1)
/* 318D34 802BDFE4 44822000 */  mtc1      $v0, $f4
/* 318D38 802BDFE8 00000000 */  nop       
/* 318D3C 802BDFEC 46802120 */  cvt.s.w   $f4, $f4
/* 318D40 802BDFF0 C620003C */  lwc1      $f0, 0x3c($s1)
/* 318D44 802BDFF4 3C014120 */  lui       $at, 0x4120
/* 318D48 802BDFF8 44811000 */  mtc1      $at, $f2
/* 318D4C 802BDFFC 2402FFFF */  addiu     $v0, $zero, -1
/* 318D50 802BE000 46020000 */  add.s     $f0, $f0, $f2
/* 318D54 802BE004 E624000C */  swc1      $f4, 0xc($s1)
/* 318D58 802BE008 E6340014 */  swc1      $f20, 0x14($s1)
/* 318D5C 802BE00C E620003C */  swc1      $f0, 0x3c($s1)
/* 318D60 802BE010 E6200064 */  swc1      $f0, 0x64($s1)
/* 318D64 802BE014 A6820018 */  sh        $v0, 0x18($s4)
/* 318D68 802BE018 C6200038 */  lwc1      $f0, 0x38($s1)
/* 318D6C 802BE01C E680001C */  swc1      $f0, 0x1c($s4)
/* 318D70 802BE020 C620003C */  lwc1      $f0, 0x3c($s1)
/* 318D74 802BE024 E6800020 */  swc1      $f0, 0x20($s4)
/* 318D78 802BE028 C6200040 */  lwc1      $f0, 0x40($s1)
/* 318D7C 802BE02C 3C020003 */  lui       $v0, 3
/* 318D80 802BE030 E6800024 */  swc1      $f0, 0x24($s4)
/* 318D84 802BE034 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 318D88 802BE038 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 318D8C 802BE03C 34420011 */  ori       $v0, $v0, 0x11
/* 318D90 802BE040 AE220028 */  sw        $v0, 0x28($s1)
/* 318D94 802BE044 8E660028 */  lw        $a2, 0x28($s3)
/* 318D98 802BE048 0C00A720 */  jal       atan2
/* 318D9C 802BE04C 8E670030 */   lw       $a3, 0x30($s3)
/* 318DA0 802BE050 3C02800B */  lui       $v0, %hi(gCameras)
/* 318DA4 802BE054 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 318DA8 802BE058 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 318DAC 802BE05C 0C00A70A */  jal       get_clamped_angle_diff
/* 318DB0 802BE060 46000386 */   mov.s    $f14, $f0
/* 318DB4 802BE064 44801000 */  mtc1      $zero, $f2
/* 318DB8 802BE068 00000000 */  nop       
/* 318DBC 802BE06C 4602003C */  c.lt.s    $f0, $f2
/* 318DC0 802BE070 00000000 */  nop       
/* 318DC4 802BE074 45010002 */  bc1t      .L802BE080
/* 318DC8 802BE078 2402FFFF */   addiu    $v0, $zero, -1
/* 318DCC 802BE07C 24020001 */  addiu     $v0, $zero, 1
.L802BE080:
/* 318DD0 802BE080 AE420078 */  sw        $v0, 0x78($s2)
/* 318DD4 802BE084 2402000A */  addiu     $v0, $zero, 0xa
/* 318DD8 802BE088 AE420074 */  sw        $v0, 0x74($s2)
/* 318DDC 802BE08C 24020005 */  addiu     $v0, $zero, 5
/* 318DE0 802BE090 080AF8BE */  j         .L802BE2F8
/* 318DE4 802BE094 AE420070 */   sw       $v0, 0x70($s2)
.L802BE098:
/* 318DE8 802BE098 C624003C */  lwc1      $f4, 0x3c($s1)
/* 318DEC 802BE09C C620001C */  lwc1      $f0, 0x1c($s1)
/* 318DF0 802BE0A0 46002100 */  add.s     $f4, $f4, $f0
/* 318DF4 802BE0A4 C6220014 */  lwc1      $f2, 0x14($s1)
/* 318DF8 802BE0A8 46020001 */  sub.s     $f0, $f0, $f2
/* 318DFC 802BE0AC E624003C */  swc1      $f4, 0x3c($s1)
/* 318E00 802BE0B0 E620001C */  swc1      $f0, 0x1c($s1)
/* 318E04 802BE0B4 8E430078 */  lw        $v1, 0x78($s2)
/* 318E08 802BE0B8 C620004C */  lwc1      $f0, 0x4c($s1)
/* 318E0C 802BE0BC 00031080 */  sll       $v0, $v1, 2
/* 318E10 802BE0C0 00431021 */  addu      $v0, $v0, $v1
/* 318E14 802BE0C4 00021100 */  sll       $v0, $v0, 4
/* 318E18 802BE0C8 00431023 */  subu      $v0, $v0, $v1
/* 318E1C 802BE0CC 00021FC2 */  srl       $v1, $v0, 0x1f
/* 318E20 802BE0D0 00431021 */  addu      $v0, $v0, $v1
/* 318E24 802BE0D4 00021043 */  sra       $v0, $v0, 1
/* 318E28 802BE0D8 44821000 */  mtc1      $v0, $f2
/* 318E2C 802BE0DC 00000000 */  nop       
/* 318E30 802BE0E0 468010A0 */  cvt.s.w   $f2, $f2
/* 318E34 802BE0E4 46020001 */  sub.s     $f0, $f0, $f2
/* 318E38 802BE0E8 E620004C */  swc1      $f0, 0x4c($s1)
/* 318E3C 802BE0EC 8E430078 */  lw        $v1, 0x78($s2)
/* 318E40 802BE0F0 C6200044 */  lwc1      $f0, 0x44($s1)
/* 318E44 802BE0F4 00031100 */  sll       $v0, $v1, 4
/* 318E48 802BE0F8 00431021 */  addu      $v0, $v0, $v1
/* 318E4C 802BE0FC 00021080 */  sll       $v0, $v0, 2
/* 318E50 802BE100 00431023 */  subu      $v0, $v0, $v1
/* 318E54 802BE104 00021FC2 */  srl       $v1, $v0, 0x1f
/* 318E58 802BE108 00431021 */  addu      $v0, $v0, $v1
/* 318E5C 802BE10C 00021043 */  sra       $v0, $v0, 1
/* 318E60 802BE110 44821000 */  mtc1      $v0, $f2
/* 318E64 802BE114 00000000 */  nop       
/* 318E68 802BE118 468010A0 */  cvt.s.w   $f2, $f2
/* 318E6C 802BE11C 46020001 */  sub.s     $f0, $f0, $f2
/* 318E70 802BE120 E6200044 */  swc1      $f0, 0x44($s1)
/* 318E74 802BE124 8E420074 */  lw        $v0, 0x74($s2)
/* 318E78 802BE128 10400003 */  beqz      $v0, .L802BE138
/* 318E7C 802BE12C 2442FFFF */   addiu    $v0, $v0, -1
.L802BE130:
/* 318E80 802BE130 080AF8BE */  j         .L802BE2F8
/* 318E84 802BE134 AE420074 */   sw       $v0, 0x74($s2)
.L802BE138:
/* 318E88 802BE138 3C02802C */  lui       $v0, 0x802c
/* 318E8C 802BE13C 8C42E930 */  lw        $v0, -0x16d0($v0)
/* 318E90 802BE140 14400005 */  bnez      $v0, .L802BE158
/* 318E94 802BE144 00000000 */   nop      
/* 318E98 802BE148 C6600028 */  lwc1      $f0, 0x28($s3)
/* 318E9C 802BE14C E6200038 */  swc1      $f0, 0x38($s1)
/* 318EA0 802BE150 C6600030 */  lwc1      $f0, 0x30($s3)
/* 318EA4 802BE154 E6200040 */  swc1      $f0, 0x40($s1)
.L802BE158:
/* 318EA8 802BE158 3C01800B */  lui       $at, 0x800b
/* 318EAC 802BE15C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 318EB0 802BE160 C66C00A8 */  lwc1      $f12, 0xa8($s3)
/* 318EB4 802BE164 0C00A6C9 */  jal       clamp_angle
/* 318EB8 802BE168 460C0300 */   add.s    $f12, $f0, $f12
/* 318EBC 802BE16C 26240038 */  addiu     $a0, $s1, 0x38
/* 318EC0 802BE170 3C064120 */  lui       $a2, 0x4120
/* 318EC4 802BE174 44070000 */  mfc1      $a3, $f0
/* 318EC8 802BE178 26250040 */  addiu     $a1, $s1, 0x40
/* 318ECC 802BE17C 0C00A7E7 */  jal       add_vec2D_polar
/* 318ED0 802BE180 AE27000C */   sw       $a3, 0xc($s1)
/* 318ED4 802BE184 3C030003 */  lui       $v1, 3
/* 318ED8 802BE188 8E220000 */  lw        $v0, ($s1)
/* 318EDC 802BE18C 34630011 */  ori       $v1, $v1, 0x11
/* 318EE0 802BE190 AE20001C */  sw        $zero, 0x1c($s1)
/* 318EE4 802BE194 AE230028 */  sw        $v1, 0x28($s1)
/* 318EE8 802BE198 34420800 */  ori       $v0, $v0, 0x800
/* 318EEC 802BE19C AE220000 */  sw        $v0, ($s1)
/* 318EF0 802BE1A0 24020006 */  addiu     $v0, $zero, 6
/* 318EF4 802BE1A4 080AF8BE */  j         .L802BE2F8
/* 318EF8 802BE1A8 AE420070 */   sw       $v0, 0x70($s2)
.L802BE1AC:
/* 318EFC 802BE1AC C624003C */  lwc1      $f4, 0x3c($s1)
/* 318F00 802BE1B0 3C014120 */  lui       $at, 0x4120
/* 318F04 802BE1B4 44810000 */  mtc1      $at, $f0
/* 318F08 802BE1B8 866200B0 */  lh        $v0, 0xb0($s3)
/* 318F0C 802BE1BC 46002100 */  add.s     $f4, $f4, $f0
/* 318F10 802BE1C0 C660002C */  lwc1      $f0, 0x2c($s3)
/* 318F14 802BE1C4 44821000 */  mtc1      $v0, $f2
/* 318F18 802BE1C8 00000000 */  nop       
/* 318F1C 802BE1CC 468010A0 */  cvt.s.w   $f2, $f2
/* 318F20 802BE1D0 46020000 */  add.s     $f0, $f0, $f2
/* 318F24 802BE1D4 4600203C */  c.lt.s    $f4, $f0
/* 318F28 802BE1D8 00000000 */  nop       
/* 318F2C 802BE1DC 45000018 */  bc1f      .L802BE240
/* 318F30 802BE1E0 2403F7FF */   addiu    $v1, $zero, -0x801
/* 318F34 802BE1E4 8E220000 */  lw        $v0, ($s1)
/* 318F38 802BE1E8 C622003C */  lwc1      $f2, 0x3c($s1)
/* 318F3C 802BE1EC 00431024 */  and       $v0, $v0, $v1
/* 318F40 802BE1F0 AE220000 */  sw        $v0, ($s1)
/* 318F44 802BE1F4 C660002C */  lwc1      $f0, 0x2c($s3)
/* 318F48 802BE1F8 46020001 */  sub.s     $f0, $f0, $f2
/* 318F4C 802BE1FC 3C01802C */  lui       $at, 0x802c
/* 318F50 802BE200 D422E908 */  ldc1      $f2, -0x16f8($at)
/* 318F54 802BE204 46000005 */  abs.s     $f0, $f0
/* 318F58 802BE208 46000021 */  cvt.d.s   $f0, $f0
/* 318F5C 802BE20C 4622003C */  c.lt.d    $f0, $f2
/* 318F60 802BE210 00000000 */  nop       
/* 318F64 802BE214 45000003 */  bc1f      .L802BE224
/* 318F68 802BE218 24020008 */   addiu    $v0, $zero, 8
/* 318F6C 802BE21C 080AF8BE */  j         .L802BE2F8
/* 318F70 802BE220 AE420070 */   sw       $v0, 0x70($s2)
.L802BE224:
/* 318F74 802BE224 8E25001C */  lw        $a1, 0x1c($s1)
/* 318F78 802BE228 0C00E5FA */  jal       func_800397E8
/* 318F7C 802BE22C 0220202D */   daddu    $a0, $s1, $zero
/* 318F80 802BE230 10400003 */  beqz      $v0, .L802BE240
/* 318F84 802BE234 24020007 */   addiu    $v0, $zero, 7
/* 318F88 802BE238 080AF8BE */  j         .L802BE2F8
/* 318F8C 802BE23C AE420070 */   sw       $v0, 0x70($s2)
.L802BE240:
/* 318F90 802BE240 C626001C */  lwc1      $f6, 0x1c($s1)
/* 318F94 802BE244 C6200014 */  lwc1      $f0, 0x14($s1)
/* 318F98 802BE248 C624003C */  lwc1      $f4, 0x3c($s1)
/* 318F9C 802BE24C 46003181 */  sub.s     $f6, $f6, $f0
/* 318FA0 802BE250 C620001C */  lwc1      $f0, 0x1c($s1)
/* 318FA4 802BE254 46002100 */  add.s     $f4, $f4, $f0
/* 318FA8 802BE258 3C01C020 */  lui       $at, 0xc020
/* 318FAC 802BE25C 44811800 */  mtc1      $at, $f3
/* 318FB0 802BE260 44801000 */  mtc1      $zero, $f2
/* 318FB4 802BE264 46003021 */  cvt.d.s   $f0, $f6
/* 318FB8 802BE268 4622003C */  c.lt.d    $f0, $f2
/* 318FBC 802BE26C E626001C */  swc1      $f6, 0x1c($s1)
/* 318FC0 802BE270 45000005 */  bc1f      .L802BE288
/* 318FC4 802BE274 E624003C */   swc1     $f4, 0x3c($s1)
/* 318FC8 802BE278 3C01C100 */  lui       $at, 0xc100
/* 318FCC 802BE27C 44810000 */  mtc1      $at, $f0
/* 318FD0 802BE280 00000000 */  nop       
/* 318FD4 802BE284 E620001C */  swc1      $f0, 0x1c($s1)
.L802BE288:
/* 318FD8 802BE288 8E430078 */  lw        $v1, 0x78($s2)
/* 318FDC 802BE28C C620004C */  lwc1      $f0, 0x4c($s1)
/* 318FE0 802BE290 00031080 */  sll       $v0, $v1, 2
/* 318FE4 802BE294 00431021 */  addu      $v0, $v0, $v1
/* 318FE8 802BE298 00021100 */  sll       $v0, $v0, 4
/* 318FEC 802BE29C 00431023 */  subu      $v0, $v0, $v1
/* 318FF0 802BE2A0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 318FF4 802BE2A4 00431021 */  addu      $v0, $v0, $v1
/* 318FF8 802BE2A8 00021043 */  sra       $v0, $v0, 1
/* 318FFC 802BE2AC 44821000 */  mtc1      $v0, $f2
/* 319000 802BE2B0 00000000 */  nop       
/* 319004 802BE2B4 468010A0 */  cvt.s.w   $f2, $f2
/* 319008 802BE2B8 46020001 */  sub.s     $f0, $f0, $f2
/* 31900C 802BE2BC E620004C */  swc1      $f0, 0x4c($s1)
/* 319010 802BE2C0 8E430078 */  lw        $v1, 0x78($s2)
/* 319014 802BE2C4 C6200044 */  lwc1      $f0, 0x44($s1)
/* 319018 802BE2C8 00031100 */  sll       $v0, $v1, 4
/* 31901C 802BE2CC 00431021 */  addu      $v0, $v0, $v1
/* 319020 802BE2D0 00021080 */  sll       $v0, $v0, 2
/* 319024 802BE2D4 00431023 */  subu      $v0, $v0, $v1
/* 319028 802BE2D8 00021FC2 */  srl       $v1, $v0, 0x1f
/* 31902C 802BE2DC 00431021 */  addu      $v0, $v0, $v1
/* 319030 802BE2E0 00021043 */  sra       $v0, $v0, 1
/* 319034 802BE2E4 44821000 */  mtc1      $v0, $f2
/* 319038 802BE2E8 00000000 */  nop       
/* 31903C 802BE2EC 468010A0 */  cvt.s.w   $f2, $f2
/* 319040 802BE2F0 46020001 */  sub.s     $f0, $f0, $f2
/* 319044 802BE2F4 E6200044 */  swc1      $f0, 0x44($s1)
.L802BE2F8:
/* 319048 802BE2F8 8E440070 */  lw        $a0, 0x70($s2)
/* 31904C 802BE2FC 24020007 */  addiu     $v0, $zero, 7
/* 319050 802BE300 10820005 */  beq       $a0, $v0, .L802BE318
/* 319054 802BE304 24020008 */   addiu    $v0, $zero, 8
/* 319058 802BE308 10820029 */  beq       $a0, $v0, .L802BE3B0
/* 31905C 802BE30C 0000102D */   daddu    $v0, $zero, $zero
/* 319060 802BE310 080AF930 */  j         .L802BE4C0
/* 319064 802BE314 00000000 */   nop      
.L802BE318:
/* 319068 802BE318 826200B4 */  lb        $v0, 0xb4($s3)
/* 31906C 802BE31C 14400003 */  bnez      $v0, .L802BE32C
/* 319070 802BE320 3C040001 */   lui      $a0, 1
/* 319074 802BE324 0C037FBF */  jal       func_800DFEFC
/* 319078 802BE328 34840002 */   ori      $a0, $a0, 2
.L802BE32C:
/* 31907C 802BE32C 3C03802C */  lui       $v1, 0x802c
/* 319080 802BE330 2463E92C */  addiu     $v1, $v1, -0x16d4
/* 319084 802BE334 8C620000 */  lw        $v0, ($v1)
/* 319088 802BE338 10400004 */  beqz      $v0, .L802BE34C
/* 31908C 802BE33C 3C020003 */   lui      $v0, 3
/* 319090 802BE340 0C038069 */  jal       enable_player_input
/* 319094 802BE344 AC600000 */   sw       $zero, ($v1)
/* 319098 802BE348 3C020003 */  lui       $v0, 3
.L802BE34C:
/* 31909C 802BE34C 34420003 */  ori       $v0, $v0, 3
/* 3190A0 802BE350 A2A00000 */  sb        $zero, ($s5)
/* 3190A4 802BE354 A2A00003 */  sb        $zero, 3($s5)
/* 3190A8 802BE358 AE20001C */  sw        $zero, 0x1c($s1)
/* 3190AC 802BE35C C660002C */  lwc1      $f0, 0x2c($s3)
/* 3190B0 802BE360 0220202D */  daddu     $a0, $s1, $zero
/* 3190B4 802BE364 3C01802C */  lui       $at, 0x802c
/* 3190B8 802BE368 AC20E928 */  sw        $zero, -0x16d8($at)
/* 3190BC 802BE36C 3C01802C */  lui       $at, 0x802c
/* 3190C0 802BE370 AC20E934 */  sw        $zero, -0x16cc($at)
/* 3190C4 802BE374 AC800044 */  sw        $zero, 0x44($a0)
/* 3190C8 802BE378 AC80004C */  sw        $zero, 0x4c($a0)
/* 3190CC 802BE37C AC820028 */  sw        $v0, 0x28($a0)
/* 3190D0 802BE380 0C03BD17 */  jal       clear_partner_move_history
/* 3190D4 802BE384 E480003C */   swc1     $f0, 0x3c($a0)
/* 3190D8 802BE388 3C03802C */  lui       $v1, 0x802c
/* 3190DC 802BE38C 2463E924 */  addiu     $v1, $v1, -0x16dc
/* 3190E0 802BE390 8C620000 */  lw        $v0, ($v1)
/* 3190E4 802BE394 1040004A */  beqz      $v0, .L802BE4C0
/* 3190E8 802BE398 24020002 */   addiu    $v0, $zero, 2
/* 3190EC 802BE39C AC600000 */  sw        $zero, ($v1)
/* 3190F0 802BE3A0 0C05271B */  jal       stop_sound
/* 3190F4 802BE3A4 3C048000 */   lui      $a0, 0x8000
/* 3190F8 802BE3A8 080AF930 */  j         .L802BE4C0
/* 3190FC 802BE3AC 24020002 */   addiu    $v0, $zero, 2
.L802BE3B0:
/* 319100 802BE3B0 3C03802C */  lui       $v1, 0x802c
/* 319104 802BE3B4 2463E92C */  addiu     $v1, $v1, -0x16d4
/* 319108 802BE3B8 8C620000 */  lw        $v0, ($v1)
/* 31910C 802BE3BC 10400004 */  beqz      $v0, .L802BE3D0
/* 319110 802BE3C0 3C020003 */   lui      $v0, 3
/* 319114 802BE3C4 0C038069 */  jal       enable_player_input
/* 319118 802BE3C8 AC600000 */   sw       $zero, ($v1)
/* 31911C 802BE3CC 3C020003 */  lui       $v0, 3
.L802BE3D0:
/* 319120 802BE3D0 A2A00000 */  sb        $zero, ($s5)
/* 319124 802BE3D4 A2A00003 */  sb        $zero, 3($s5)
/* 319128 802BE3D8 AE20001C */  sw        $zero, 0x1c($s1)
/* 31912C 802BE3DC C660002C */  lwc1      $f0, 0x2c($s3)
/* 319130 802BE3E0 34420003 */  ori       $v0, $v0, 3
/* 319134 802BE3E4 AE220028 */  sw        $v0, 0x28($s1)
/* 319138 802BE3E8 3C02802C */  lui       $v0, 0x802c
/* 31913C 802BE3EC 8C42E920 */  lw        $v0, -0x16e0($v0)
/* 319140 802BE3F0 AE200044 */  sw        $zero, 0x44($s1)
/* 319144 802BE3F4 AE20004C */  sw        $zero, 0x4c($s1)
/* 319148 802BE3F8 E620003C */  swc1      $f0, 0x3c($s1)
/* 31914C 802BE3FC C6600028 */  lwc1      $f0, 0x28($s3)
/* 319150 802BE400 E6200038 */  swc1      $f0, 0x38($s1)
/* 319154 802BE404 C660002C */  lwc1      $f0, 0x2c($s3)
/* 319158 802BE408 26300038 */  addiu     $s0, $s1, 0x38
/* 31915C 802BE40C E620003C */  swc1      $f0, 0x3c($s1)
/* 319160 802BE410 C6600030 */  lwc1      $f0, 0x30($s3)
/* 319164 802BE414 26320040 */  addiu     $s2, $s1, 0x40
/* 319168 802BE418 3C01802C */  lui       $at, 0x802c
/* 31916C 802BE41C AC20E928 */  sw        $zero, -0x16d8($at)
/* 319170 802BE420 3C01802C */  lui       $at, 0x802c
/* 319174 802BE424 AC20E934 */  sw        $zero, -0x16cc($at)
/* 319178 802BE428 14400006 */  bnez      $v0, .L802BE444
/* 31917C 802BE42C E6200040 */   swc1     $f0, 0x40($s1)
/* 319180 802BE430 C6600080 */  lwc1      $f0, 0x80($s3)
/* 319184 802BE434 3C0142B4 */  lui       $at, 0x42b4
/* 319188 802BE438 44816000 */  mtc1      $at, $f12
/* 31918C 802BE43C 080AF916 */  j         .L802BE458
/* 319190 802BE440 460C0300 */   add.s    $f12, $f0, $f12
.L802BE444:
/* 319194 802BE444 C6600080 */  lwc1      $f0, 0x80($s3)
/* 319198 802BE448 3C0142B4 */  lui       $at, 0x42b4
/* 31919C 802BE44C 44816000 */  mtc1      $at, $f12
/* 3191A0 802BE450 00000000 */  nop       
/* 3191A4 802BE454 460C0301 */  sub.s     $f12, $f0, $f12
.L802BE458:
/* 3191A8 802BE458 0C00A6C9 */  jal       clamp_angle
/* 3191AC 802BE45C 00000000 */   nop      
/* 3191B0 802BE460 866200B2 */  lh        $v0, 0xb2($s3)
/* 3191B4 802BE464 04420001 */  bltzl     $v0, .L802BE46C
/* 3191B8 802BE468 24420003 */   addiu    $v0, $v0, 3
.L802BE46C:
/* 3191BC 802BE46C 0200202D */  daddu     $a0, $s0, $zero
/* 3191C0 802BE470 00021083 */  sra       $v0, $v0, 2
/* 3191C4 802BE474 44828000 */  mtc1      $v0, $f16
/* 3191C8 802BE478 00000000 */  nop       
/* 3191CC 802BE47C 46808420 */  cvt.s.w   $f16, $f16
/* 3191D0 802BE480 44070000 */  mfc1      $a3, $f0
/* 3191D4 802BE484 44068000 */  mfc1      $a2, $f16
/* 3191D8 802BE488 0C00A7E7 */  jal       add_vec2D_polar
/* 3191DC 802BE48C 0240282D */   daddu    $a1, $s2, $zero
/* 3191E0 802BE490 0220202D */  daddu     $a0, $s1, $zero
/* 3191E4 802BE494 0C03BD17 */  jal       clear_partner_move_history
/* 3191E8 802BE498 AC80001C */   sw       $zero, 0x1c($a0)
/* 3191EC 802BE49C 3C03802C */  lui       $v1, 0x802c
/* 3191F0 802BE4A0 2463E924 */  addiu     $v1, $v1, -0x16dc
/* 3191F4 802BE4A4 8C620000 */  lw        $v0, ($v1)
/* 3191F8 802BE4A8 10400005 */  beqz      $v0, .L802BE4C0
/* 3191FC 802BE4AC 24020002 */   addiu    $v0, $zero, 2
/* 319200 802BE4B0 AC600000 */  sw        $zero, ($v1)
/* 319204 802BE4B4 0C05271B */  jal       stop_sound
/* 319208 802BE4B8 3C048000 */   lui      $a0, 0x8000
/* 31920C 802BE4BC 24020002 */  addiu     $v0, $zero, 2
.L802BE4C0:
/* 319210 802BE4C0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 319214 802BE4C4 8FB50044 */  lw        $s5, 0x44($sp)
/* 319218 802BE4C8 8FB40040 */  lw        $s4, 0x40($sp)
/* 31921C 802BE4CC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 319220 802BE4D0 8FB20038 */  lw        $s2, 0x38($sp)
/* 319224 802BE4D4 8FB10034 */  lw        $s1, 0x34($sp)
/* 319228 802BE4D8 8FB00030 */  lw        $s0, 0x30($sp)
/* 31922C 802BE4DC D7B40050 */  ldc1      $f20, 0x50($sp)
/* 319230 802BE4E0 03E00008 */  jr        $ra
/* 319234 802BE4E4 27BD0058 */   addiu    $sp, $sp, 0x58
