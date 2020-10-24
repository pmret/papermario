.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426B0_9AAAA0
/* 9AAAA0 802426B0 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 9AAAA4 802426B4 AFB3004C */  sw        $s3, 0x4c($sp)
/* 9AAAA8 802426B8 0080982D */  daddu     $s3, $a0, $zero
/* 9AAAAC 802426BC AFBF0054 */  sw        $ra, 0x54($sp)
/* 9AAAB0 802426C0 AFB40050 */  sw        $s4, 0x50($sp)
/* 9AAAB4 802426C4 AFB20048 */  sw        $s2, 0x48($sp)
/* 9AAAB8 802426C8 AFB10044 */  sw        $s1, 0x44($sp)
/* 9AAABC 802426CC AFB00040 */  sw        $s0, 0x40($sp)
/* 9AAAC0 802426D0 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 9AAAC4 802426D4 F7B80068 */  sdc1      $f24, 0x68($sp)
/* 9AAAC8 802426D8 F7B60060 */  sdc1      $f22, 0x60($sp)
/* 9AAACC 802426DC F7B40058 */  sdc1      $f20, 0x58($sp)
/* 9AAAD0 802426E0 8E710148 */  lw        $s1, 0x148($s3)
/* 9AAAD4 802426E4 00A0902D */  daddu     $s2, $a1, $zero
/* 9AAAD8 802426E8 86240008 */  lh        $a0, 8($s1)
/* 9AAADC 802426EC 0C00EABB */  jal       get_npc_unsafe
/* 9AAAE0 802426F0 00C0A02D */   daddu    $s4, $a2, $zero
/* 9AAAE4 802426F4 0040802D */  daddu     $s0, $v0, $zero
/* 9AAAE8 802426F8 C6200078 */  lwc1      $f0, 0x78($s1)
/* 9AAAEC 802426FC 46800020 */  cvt.s.w   $f0, $f0
/* 9AAAF0 80242700 46000021 */  cvt.d.s   $f0, $f0
/* 9AAAF4 80242704 3C014059 */  lui       $at, 0x4059
/* 9AAAF8 80242708 44811800 */  mtc1      $at, $f3
/* 9AAAFC 8024270C 44801000 */  mtc1      $zero, $f2
/* 9AAB00 80242710 8602008E */  lh        $v0, 0x8e($s0)
/* 9AAB04 80242714 9603008E */  lhu       $v1, 0x8e($s0)
/* 9AAB08 80242718 46220003 */  div.d     $f0, $f0, $f2
/* 9AAB0C 8024271C 46200620 */  cvt.s.d   $f24, $f0
/* 9AAB10 80242720 C6200088 */  lwc1      $f0, 0x88($s1)
/* 9AAB14 80242724 46800020 */  cvt.s.w   $f0, $f0
/* 9AAB18 80242728 46000021 */  cvt.d.s   $f0, $f0
/* 9AAB1C 8024272C 46220003 */  div.d     $f0, $f0, $f2
/* 9AAB20 80242730 46200020 */  cvt.s.d   $f0, $f0
/* 9AAB24 80242734 18400003 */  blez      $v0, .L80242744
/* 9AAB28 80242738 4600C680 */   add.s    $f26, $f24, $f0
/* 9AAB2C 8024273C 2462FFFF */  addiu     $v0, $v1, -1
/* 9AAB30 80242740 A602008E */  sh        $v0, 0x8e($s0)
.L80242744:
/* 9AAB34 80242744 8E220070 */  lw        $v0, 0x70($s1)
/* 9AAB38 80242748 18400034 */  blez      $v0, .L8024281C
/* 9AAB3C 8024274C 00000000 */   nop      
/* 9AAB40 80242750 C62C0074 */  lwc1      $f12, 0x74($s1)
/* 9AAB44 80242754 46806320 */  cvt.s.w   $f12, $f12
/* 9AAB48 80242758 44820000 */  mtc1      $v0, $f0
/* 9AAB4C 8024275C 00000000 */  nop       
/* 9AAB50 80242760 46800020 */  cvt.s.w   $f0, $f0
/* 9AAB54 80242764 46000021 */  cvt.d.s   $f0, $f0
/* 9AAB58 80242768 46220003 */  div.d     $f0, $f0, $f2
/* 9AAB5C 8024276C 0C00A8BB */  jal       sin_deg
/* 9AAB60 80242770 462005A0 */   cvt.s.d  $f22, $f0
/* 9AAB64 80242774 8E020000 */  lw        $v0, ($s0)
/* 9AAB68 80242778 30420008 */  andi      $v0, $v0, 8
/* 9AAB6C 8024277C 10400003 */  beqz      $v0, .L8024278C
/* 9AAB70 80242780 46000506 */   mov.s    $f20, $f0
/* 9AAB74 80242784 080909F3 */  j         .L802427CC
/* 9AAB78 80242788 0000102D */   daddu    $v0, $zero, $zero
.L8024278C:
/* 9AAB7C 8024278C 27A50028 */  addiu     $a1, $sp, 0x28
/* 9AAB80 80242790 27A6002C */  addiu     $a2, $sp, 0x2c
/* 9AAB84 80242794 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9AAB88 80242798 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9AAB8C 8024279C C6040040 */  lwc1      $f4, 0x40($s0)
/* 9AAB90 802427A0 3C01447A */  lui       $at, 0x447a
/* 9AAB94 802427A4 44813000 */  mtc1      $at, $f6
/* 9AAB98 802427A8 27A20034 */  addiu     $v0, $sp, 0x34
/* 9AAB9C 802427AC E7A00028 */  swc1      $f0, 0x28($sp)
/* 9AABA0 802427B0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 9AABA4 802427B4 E7A40030 */  swc1      $f4, 0x30($sp)
/* 9AABA8 802427B8 E7A60034 */  swc1      $f6, 0x34($sp)
/* 9AABAC 802427BC AFA20010 */  sw        $v0, 0x10($sp)
/* 9AABB0 802427C0 8E040080 */  lw        $a0, 0x80($s0)
/* 9AABB4 802427C4 0C0372DF */  jal       func_800DCB7C
/* 9AABB8 802427C8 27A70030 */   addiu    $a3, $sp, 0x30
.L802427CC:
/* 9AABBC 802427CC 10400007 */  beqz      $v0, .L802427EC
/* 9AABC0 802427D0 00000000 */   nop      
/* 9AABC4 802427D4 4616A082 */  mul.s     $f2, $f20, $f22
/* 9AABC8 802427D8 00000000 */  nop       
/* 9AABCC 802427DC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 9AABD0 802427E0 46180000 */  add.s     $f0, $f0, $f24
/* 9AABD4 802427E4 080909FE */  j         .L802427F8
/* 9AABD8 802427E8 46020000 */   add.s    $f0, $f0, $f2
.L802427EC:
/* 9AABDC 802427EC 4616A002 */  mul.s     $f0, $f20, $f22
/* 9AABE0 802427F0 00000000 */  nop       
/* 9AABE4 802427F4 4600D000 */  add.s     $f0, $f26, $f0
.L802427F8:
/* 9AABE8 802427F8 E600003C */  swc1      $f0, 0x3c($s0)
/* 9AABEC 802427FC 8E220074 */  lw        $v0, 0x74($s1)
/* 9AABF0 80242800 2442000A */  addiu     $v0, $v0, 0xa
/* 9AABF4 80242804 44826000 */  mtc1      $v0, $f12
/* 9AABF8 80242808 00000000 */  nop       
/* 9AABFC 8024280C 0C00A6C9 */  jal       clamp_angle
/* 9AAC00 80242810 46806320 */   cvt.s.w  $f12, $f12
/* 9AAC04 80242814 4600020D */  trunc.w.s $f8, $f0
/* 9AAC08 80242818 E6280074 */  swc1      $f8, 0x74($s1)
.L8024281C:
/* 9AAC0C 8024281C 8E220090 */  lw        $v0, 0x90($s1)
/* 9AAC10 80242820 1C400040 */  bgtz      $v0, .L80242924
/* 9AAC14 80242824 2442FFFF */   addiu    $v0, $v0, -1
/* 9AAC18 80242828 860200A8 */  lh        $v0, 0xa8($s0)
/* 9AAC1C 8024282C C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AAC20 80242830 44821000 */  mtc1      $v0, $f2
/* 9AAC24 80242834 00000000 */  nop       
/* 9AAC28 80242838 468010A0 */  cvt.s.w   $f2, $f2
/* 9AAC2C 8024283C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9AAC30 80242840 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9AAC34 80242844 46020000 */  add.s     $f0, $f0, $f2
/* 9AAC38 80242848 3C014024 */  lui       $at, 0x4024
/* 9AAC3C 8024284C 44812800 */  mtc1      $at, $f5
/* 9AAC40 80242850 44802000 */  mtc1      $zero, $f4
/* 9AAC44 80242854 C442002C */  lwc1      $f2, 0x2c($v0)
/* 9AAC48 80242858 46000021 */  cvt.d.s   $f0, $f0
/* 9AAC4C 8024285C 46240000 */  add.d     $f0, $f0, $f4
/* 9AAC50 80242860 460010A1 */  cvt.d.s   $f2, $f2
/* 9AAC54 80242864 4620103C */  c.lt.d    $f2, $f0
/* 9AAC58 80242868 00000000 */  nop       
/* 9AAC5C 8024286C 4500002E */  bc1f      .L80242928
/* 9AAC60 80242870 0280202D */   daddu    $a0, $s4, $zero
/* 9AAC64 80242874 24020001 */  addiu     $v0, $zero, 1
/* 9AAC68 80242878 AFA20010 */  sw        $v0, 0x10($sp)
/* 9AAC6C 8024287C 8E460024 */  lw        $a2, 0x24($s2)
/* 9AAC70 80242880 8E470028 */  lw        $a3, 0x28($s2)
/* 9AAC74 80242884 0C01242D */  jal       func_800490B4
/* 9AAC78 80242888 0220282D */   daddu    $a1, $s1, $zero
/* 9AAC7C 8024288C 10400026 */  beqz      $v0, .L80242928
/* 9AAC80 80242890 0000202D */   daddu    $a0, $zero, $zero
/* 9AAC84 80242894 0200282D */  daddu     $a1, $s0, $zero
/* 9AAC88 80242898 0000302D */  daddu     $a2, $zero, $zero
/* 9AAC8C 8024289C 2412000C */  addiu     $s2, $zero, 0xc
/* 9AAC90 802428A0 860300A8 */  lh        $v1, 0xa8($s0)
/* 9AAC94 802428A4 3C013F80 */  lui       $at, 0x3f80
/* 9AAC98 802428A8 44810000 */  mtc1      $at, $f0
/* 9AAC9C 802428AC 3C014000 */  lui       $at, 0x4000
/* 9AACA0 802428B0 44811000 */  mtc1      $at, $f2
/* 9AACA4 802428B4 3C01C1A0 */  lui       $at, 0xc1a0
/* 9AACA8 802428B8 44812000 */  mtc1      $at, $f4
/* 9AACAC 802428BC 44834000 */  mtc1      $v1, $f8
/* 9AACB0 802428C0 00000000 */  nop       
/* 9AACB4 802428C4 46804220 */  cvt.s.w   $f8, $f8
/* 9AACB8 802428C8 44074000 */  mfc1      $a3, $f8
/* 9AACBC 802428CC 27A20038 */  addiu     $v0, $sp, 0x38
/* 9AACC0 802428D0 AFB2001C */  sw        $s2, 0x1c($sp)
/* 9AACC4 802428D4 AFA20020 */  sw        $v0, 0x20($sp)
/* 9AACC8 802428D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9AACCC 802428DC E7A20014 */  swc1      $f2, 0x14($sp)
/* 9AACD0 802428E0 0C01BFA4 */  jal       fx_emote
/* 9AACD4 802428E4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9AACD8 802428E8 0200202D */  daddu     $a0, $s0, $zero
/* 9AACDC 802428EC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9AACE0 802428F0 C480003C */  lwc1      $f0, 0x3c($a0)
/* 9AACE4 802428F4 3C060020 */  lui       $a2, 0x20
/* 9AACE8 802428F8 0C012530 */  jal       func_800494C0
/* 9AACEC 802428FC E4800064 */   swc1     $f0, 0x64($a0)
/* 9AACF0 80242900 8E220018 */  lw        $v0, 0x18($s1)
/* 9AACF4 80242904 9442002A */  lhu       $v0, 0x2a($v0)
/* 9AACF8 80242908 30420001 */  andi      $v0, $v0, 1
/* 9AACFC 8024290C 10400003 */  beqz      $v0, .L8024291C
/* 9AAD00 80242910 2402000A */   addiu    $v0, $zero, 0xa
/* 9AAD04 80242914 08090A71 */  j         .L802429C4
/* 9AAD08 80242918 AE620070 */   sw       $v0, 0x70($s3)
.L8024291C:
/* 9AAD0C 8024291C 08090A71 */  j         .L802429C4
/* 9AAD10 80242920 AE720070 */   sw       $s2, 0x70($s3)
.L80242924:
/* 9AAD14 80242924 AE220090 */  sw        $v0, 0x90($s1)
.L80242928:
/* 9AAD18 80242928 8602008C */  lh        $v0, 0x8c($s0)
/* 9AAD1C 8024292C 14400025 */  bnez      $v0, .L802429C4
/* 9AAD20 80242930 00000000 */   nop      
/* 9AAD24 80242934 8602008E */  lh        $v0, 0x8e($s0)
/* 9AAD28 80242938 1C400022 */  bgtz      $v0, .L802429C4
/* 9AAD2C 8024293C 00000000 */   nop      
/* 9AAD30 80242940 8E620074 */  lw        $v0, 0x74($s3)
/* 9AAD34 80242944 2442FFFF */  addiu     $v0, $v0, -1
/* 9AAD38 80242948 1840001D */  blez      $v0, .L802429C0
/* 9AAD3C 8024294C AE620074 */   sw       $v0, 0x74($s3)
/* 9AAD40 80242950 8E220018 */  lw        $v0, 0x18($s1)
/* 9AAD44 80242954 9442002A */  lhu       $v0, 0x2a($v0)
/* 9AAD48 80242958 30420010 */  andi      $v0, $v0, 0x10
/* 9AAD4C 8024295C 14400007 */  bnez      $v0, .L8024297C
/* 9AAD50 80242960 00000000 */   nop      
/* 9AAD54 80242964 C600000C */  lwc1      $f0, 0xc($s0)
/* 9AAD58 80242968 3C014334 */  lui       $at, 0x4334
/* 9AAD5C 8024296C 44816000 */  mtc1      $at, $f12
/* 9AAD60 80242970 0C00A6C9 */  jal       clamp_angle
/* 9AAD64 80242974 460C0300 */   add.s    $f12, $f0, $f12
/* 9AAD68 80242978 E600000C */  swc1      $f0, 0xc($s0)
.L8024297C:
/* 9AAD6C 8024297C 0C00A67F */  jal       rand_int
/* 9AAD70 80242980 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 9AAD74 80242984 3C032E8B */  lui       $v1, 0x2e8b
/* 9AAD78 80242988 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* 9AAD7C 8024298C 00430018 */  mult      $v0, $v1
/* 9AAD80 80242990 00021FC3 */  sra       $v1, $v0, 0x1f
/* 9AAD84 80242994 00004010 */  mfhi      $t0
/* 9AAD88 80242998 00082043 */  sra       $a0, $t0, 1
/* 9AAD8C 8024299C 00832023 */  subu      $a0, $a0, $v1
/* 9AAD90 802429A0 00041840 */  sll       $v1, $a0, 1
/* 9AAD94 802429A4 00641821 */  addu      $v1, $v1, $a0
/* 9AAD98 802429A8 00031880 */  sll       $v1, $v1, 2
/* 9AAD9C 802429AC 00641823 */  subu      $v1, $v1, $a0
/* 9AADA0 802429B0 00431023 */  subu      $v0, $v0, $v1
/* 9AADA4 802429B4 24420005 */  addiu     $v0, $v0, 5
/* 9AADA8 802429B8 08090A71 */  j         .L802429C4
/* 9AADAC 802429BC A602008E */   sh       $v0, 0x8e($s0)
.L802429C0:
/* 9AADB0 802429C0 AE600070 */  sw        $zero, 0x70($s3)
.L802429C4:
/* 9AADB4 802429C4 8FBF0054 */  lw        $ra, 0x54($sp)
/* 9AADB8 802429C8 8FB40050 */  lw        $s4, 0x50($sp)
/* 9AADBC 802429CC 8FB3004C */  lw        $s3, 0x4c($sp)
/* 9AADC0 802429D0 8FB20048 */  lw        $s2, 0x48($sp)
/* 9AADC4 802429D4 8FB10044 */  lw        $s1, 0x44($sp)
/* 9AADC8 802429D8 8FB00040 */  lw        $s0, 0x40($sp)
/* 9AADCC 802429DC D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 9AADD0 802429E0 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 9AADD4 802429E4 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 9AADD8 802429E8 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 9AADDC 802429EC 03E00008 */  jr        $ra
/* 9AADE0 802429F0 27BD0078 */   addiu    $sp, $sp, 0x78
