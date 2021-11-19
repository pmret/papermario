.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80243880_B7D8D0
.double 1.2

.section .text

glabel func_802406F0_B7A740
/* B7A740 802406F0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B7A744 802406F4 AFB3004C */  sw        $s3, 0x4c($sp)
/* B7A748 802406F8 0080982D */  daddu     $s3, $a0, $zero
/* B7A74C 802406FC AFBF0054 */  sw        $ra, 0x54($sp)
/* B7A750 80240700 AFB40050 */  sw        $s4, 0x50($sp)
/* B7A754 80240704 AFB20048 */  sw        $s2, 0x48($sp)
/* B7A758 80240708 AFB10044 */  sw        $s1, 0x44($sp)
/* B7A75C 8024070C AFB00040 */  sw        $s0, 0x40($sp)
/* B7A760 80240710 F7B40058 */  sdc1      $f20, 0x58($sp)
/* B7A764 80240714 8E710148 */  lw        $s1, 0x148($s3)
/* B7A768 80240718 00A0A02D */  daddu     $s4, $a1, $zero
/* B7A76C 8024071C 86240008 */  lh        $a0, 8($s1)
/* B7A770 80240720 0C00EABB */  jal       get_npc_unsafe
/* B7A774 80240724 00C0902D */   daddu    $s2, $a2, $zero
/* B7A778 80240728 8E830014 */  lw        $v1, 0x14($s4)
/* B7A77C 8024072C 04600034 */  bltz      $v1, .L80240800
/* B7A780 80240730 0040802D */   daddu    $s0, $v0, $zero
/* B7A784 80240734 8E620074 */  lw        $v0, 0x74($s3)
/* B7A788 80240738 1C400030 */  bgtz      $v0, .L802407FC
/* B7A78C 8024073C 2442FFFF */   addiu    $v0, $v0, -1
/* B7A790 80240740 0240202D */  daddu     $a0, $s2, $zero
/* B7A794 80240744 AE630074 */  sw        $v1, 0x74($s3)
/* B7A798 80240748 AFA00010 */  sw        $zero, 0x10($sp)
/* B7A79C 8024074C 8E86000C */  lw        $a2, 0xc($s4)
/* B7A7A0 80240750 8E870010 */  lw        $a3, 0x10($s4)
/* B7A7A4 80240754 0C01242D */  jal       func_800490B4
/* B7A7A8 80240758 0220282D */   daddu    $a1, $s1, $zero
/* B7A7AC 8024075C 10400025 */  beqz      $v0, .L802407F4
/* B7A7B0 80240760 0000202D */   daddu    $a0, $zero, $zero
/* B7A7B4 80240764 0200282D */  daddu     $a1, $s0, $zero
/* B7A7B8 80240768 0000302D */  daddu     $a2, $zero, $zero
/* B7A7BC 8024076C 860300A8 */  lh        $v1, 0xa8($s0)
/* B7A7C0 80240770 3C013F80 */  lui       $at, 0x3f80
/* B7A7C4 80240774 44810000 */  mtc1      $at, $f0
/* B7A7C8 80240778 3C014000 */  lui       $at, 0x4000
/* B7A7CC 8024077C 44811000 */  mtc1      $at, $f2
/* B7A7D0 80240780 3C01C1A0 */  lui       $at, 0xc1a0
/* B7A7D4 80240784 44812000 */  mtc1      $at, $f4
/* B7A7D8 80240788 2402000F */  addiu     $v0, $zero, 0xf
/* B7A7DC 8024078C AFA2001C */  sw        $v0, 0x1c($sp)
/* B7A7E0 80240790 44835000 */  mtc1      $v1, $f10
/* B7A7E4 80240794 00000000 */  nop
/* B7A7E8 80240798 468052A0 */  cvt.s.w   $f10, $f10
/* B7A7EC 8024079C 44075000 */  mfc1      $a3, $f10
/* B7A7F0 802407A0 27A20028 */  addiu     $v0, $sp, 0x28
/* B7A7F4 802407A4 AFA20020 */  sw        $v0, 0x20($sp)
/* B7A7F8 802407A8 E7A00010 */  swc1      $f0, 0x10($sp)
/* B7A7FC 802407AC E7A20014 */  swc1      $f2, 0x14($sp)
/* B7A800 802407B0 0C01BFA4 */  jal       fx_emote
/* B7A804 802407B4 E7A40018 */   swc1     $f4, 0x18($sp)
/* B7A808 802407B8 0200202D */  daddu     $a0, $s0, $zero
/* B7A80C 802407BC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B7A810 802407C0 0C012530 */  jal       ai_enemy_play_sound
/* B7A814 802407C4 3C060020 */   lui      $a2, 0x20
/* B7A818 802407C8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B7A81C 802407CC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B7A820 802407D0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B7A824 802407D4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B7A828 802407D8 8C460028 */  lw        $a2, 0x28($v0)
/* B7A82C 802407DC 0C00A720 */  jal       atan2
/* B7A830 802407E0 8C470030 */   lw       $a3, 0x30($v0)
/* B7A834 802407E4 2402000C */  addiu     $v0, $zero, 0xc
/* B7A838 802407E8 E600000C */  swc1      $f0, 0xc($s0)
/* B7A83C 802407EC 08090281 */  j         .L80240A04
/* B7A840 802407F0 AE620070 */   sw       $v0, 0x70($s3)
.L802407F4:
/* B7A844 802407F4 8E620074 */  lw        $v0, 0x74($s3)
/* B7A848 802407F8 2442FFFF */  addiu     $v0, $v0, -1
.L802407FC:
/* B7A84C 802407FC AE620074 */  sw        $v0, 0x74($s3)
.L80240800:
/* B7A850 80240800 C6000018 */  lwc1      $f0, 0x18($s0)
/* B7A854 80240804 44801000 */  mtc1      $zero, $f2
/* B7A858 80240808 44801800 */  mtc1      $zero, $f3
/* B7A85C 8024080C 46000021 */  cvt.d.s   $f0, $f0
/* B7A860 80240810 4620103C */  c.lt.d    $f2, $f0
/* B7A864 80240814 00000000 */  nop
/* B7A868 80240818 45000025 */  bc1f      .L802408B0
/* B7A86C 8024081C 27A5002C */   addiu    $a1, $sp, 0x2c
/* B7A870 80240820 C6000038 */  lwc1      $f0, 0x38($s0)
/* B7A874 80240824 860200A6 */  lh        $v0, 0xa6($s0)
/* B7A878 80240828 3C018024 */  lui       $at, %hi(D_80243880_B7D8D0)
/* B7A87C 8024082C D4223880 */  ldc1      $f2, %lo(D_80243880_B7D8D0)($at)
/* B7A880 80240830 27A60030 */  addiu     $a2, $sp, 0x30
/* B7A884 80240834 E7A0002C */  swc1      $f0, 0x2c($sp)
/* B7A888 80240838 44820000 */  mtc1      $v0, $f0
/* B7A88C 8024083C 00000000 */  nop
/* B7A890 80240840 46800020 */  cvt.s.w   $f0, $f0
/* B7A894 80240844 46000021 */  cvt.d.s   $f0, $f0
/* B7A898 80240848 C604003C */  lwc1      $f4, 0x3c($s0)
/* B7A89C 8024084C C6060040 */  lwc1      $f6, 0x40($s0)
/* B7A8A0 80240850 C6080018 */  lwc1      $f8, 0x18($s0)
/* B7A8A4 80240854 860200A8 */  lh        $v0, 0xa8($s0)
/* B7A8A8 80240858 46220002 */  mul.d     $f0, $f0, $f2
/* B7A8AC 8024085C 00000000 */  nop
/* B7A8B0 80240860 E7A40030 */  swc1      $f4, 0x30($sp)
/* B7A8B4 80240864 E7A60034 */  swc1      $f6, 0x34($sp)
/* B7A8B8 80240868 E7A80010 */  swc1      $f8, 0x10($sp)
/* B7A8BC 8024086C C604000C */  lwc1      $f4, 0xc($s0)
/* B7A8C0 80240870 44821000 */  mtc1      $v0, $f2
/* B7A8C4 80240874 00000000 */  nop
/* B7A8C8 80240878 468010A0 */  cvt.s.w   $f2, $f2
/* B7A8CC 8024087C E7A20018 */  swc1      $f2, 0x18($sp)
/* B7A8D0 80240880 E7A40014 */  swc1      $f4, 0x14($sp)
/* B7A8D4 80240884 46200020 */  cvt.s.d   $f0, $f0
/* B7A8D8 80240888 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B7A8DC 8024088C 8E040080 */  lw        $a0, 0x80($s0)
/* B7A8E0 80240890 0C037711 */  jal       npc_test_move_simple_with_slipping
/* B7A8E4 80240894 27A70034 */   addiu    $a3, $sp, 0x34
/* B7A8E8 80240898 54400005 */  bnel      $v0, $zero, .L802408B0
/* B7A8EC 8024089C AE000018 */   sw       $zero, 0x18($s0)
/* B7A8F0 802408A0 8E050018 */  lw        $a1, 0x18($s0)
/* B7A8F4 802408A4 8E06000C */  lw        $a2, 0xc($s0)
/* B7A8F8 802408A8 0C00EA95 */  jal       npc_move_heading
/* B7A8FC 802408AC 0200202D */   daddu    $a0, $s0, $zero
.L802408B0:
/* B7A900 802408B0 C600001C */  lwc1      $f0, 0x1c($s0)
/* B7A904 802408B4 44801000 */  mtc1      $zero, $f2
/* B7A908 802408B8 44801800 */  mtc1      $zero, $f3
/* B7A90C 802408BC 46000021 */  cvt.d.s   $f0, $f0
/* B7A910 802408C0 4622003C */  c.lt.d    $f0, $f2
/* B7A914 802408C4 00000000 */  nop
/* B7A918 802408C8 45000047 */  bc1f      .L802409E8
/* B7A91C 802408CC 27A5002C */   addiu    $a1, $sp, 0x2c
/* B7A920 802408D0 27A60030 */  addiu     $a2, $sp, 0x30
/* B7A924 802408D4 27A20038 */  addiu     $v0, $sp, 0x38
/* B7A928 802408D8 C602003C */  lwc1      $f2, 0x3c($s0)
/* B7A92C 802408DC C6060038 */  lwc1      $f6, 0x38($s0)
/* B7A930 802408E0 3C01402A */  lui       $at, 0x402a
/* B7A934 802408E4 4481A800 */  mtc1      $at, $f21
/* B7A938 802408E8 4480A000 */  mtc1      $zero, $f20
/* B7A93C 802408EC 460010A1 */  cvt.d.s   $f2, $f2
/* B7A940 802408F0 46341080 */  add.d     $f2, $f2, $f20
/* B7A944 802408F4 C600001C */  lwc1      $f0, 0x1c($s0)
/* B7A948 802408F8 C6040040 */  lwc1      $f4, 0x40($s0)
/* B7A94C 802408FC 46000005 */  abs.s     $f0, $f0
/* B7A950 80240900 E7A40034 */  swc1      $f4, 0x34($sp)
/* B7A954 80240904 3C014030 */  lui       $at, 0x4030
/* B7A958 80240908 44812800 */  mtc1      $at, $f5
/* B7A95C 8024090C 44802000 */  mtc1      $zero, $f4
/* B7A960 80240910 46000021 */  cvt.d.s   $f0, $f0
/* B7A964 80240914 E7A6002C */  swc1      $f6, 0x2c($sp)
/* B7A968 80240918 46240000 */  add.d     $f0, $f0, $f4
/* B7A96C 8024091C 462010A0 */  cvt.s.d   $f2, $f2
/* B7A970 80240920 E7A20030 */  swc1      $f2, 0x30($sp)
/* B7A974 80240924 46200020 */  cvt.s.d   $f0, $f0
/* B7A978 80240928 E7A00038 */  swc1      $f0, 0x38($sp)
/* B7A97C 8024092C AFA20010 */  sw        $v0, 0x10($sp)
/* B7A980 80240930 8E040080 */  lw        $a0, 0x80($s0)
/* B7A984 80240934 0C0372DF */  jal       npc_raycast_down_sides
/* B7A988 80240938 27A70034 */   addiu    $a3, $sp, 0x34
/* B7A98C 8024093C 1040002A */  beqz      $v0, .L802409E8
/* B7A990 80240940 00000000 */   nop
/* B7A994 80240944 C600001C */  lwc1      $f0, 0x1c($s0)
/* B7A998 80240948 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B7A99C 8024094C 46000005 */  abs.s     $f0, $f0
/* B7A9A0 80240950 46000021 */  cvt.d.s   $f0, $f0
/* B7A9A4 80240954 46340000 */  add.d     $f0, $f0, $f20
/* B7A9A8 80240958 460010A1 */  cvt.d.s   $f2, $f2
/* B7A9AC 8024095C 4620103E */  c.le.d    $f2, $f0
/* B7A9B0 80240960 00000000 */  nop
/* B7A9B4 80240964 45000020 */  bc1f      .L802409E8
/* B7A9B8 80240968 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B7A9BC 8024096C C7A00030 */  lwc1      $f0, 0x30($sp)
/* B7A9C0 80240970 8E020000 */  lw        $v0, ($s0)
/* B7A9C4 80240974 2403F7FF */  addiu     $v1, $zero, -0x801
/* B7A9C8 80240978 AE00001C */  sw        $zero, 0x1c($s0)
/* B7A9CC 8024097C 00431024 */  and       $v0, $v0, $v1
/* B7A9D0 80240980 AE020000 */  sw        $v0, ($s0)
/* B7A9D4 80240984 24020002 */  addiu     $v0, $zero, 2
/* B7A9D8 80240988 E600003C */  swc1      $f0, 0x3c($s0)
/* B7A9DC 8024098C 0C00A67F */  jal       rand_int
/* B7A9E0 80240990 AE620070 */   sw       $v0, 0x70($s3)
/* B7A9E4 80240994 3C035555 */  lui       $v1, 0x5555
/* B7A9E8 80240998 34635556 */  ori       $v1, $v1, 0x5556
/* B7A9EC 8024099C 00430018 */  mult      $v0, $v1
/* B7A9F0 802409A0 000227C3 */  sra       $a0, $v0, 0x1f
/* B7A9F4 802409A4 00004010 */  mfhi      $t0
/* B7A9F8 802409A8 01042023 */  subu      $a0, $t0, $a0
/* B7A9FC 802409AC 00041840 */  sll       $v1, $a0, 1
/* B7AA00 802409B0 00641821 */  addu      $v1, $v1, $a0
/* B7AA04 802409B4 00431023 */  subu      $v0, $v0, $v1
/* B7AA08 802409B8 24430002 */  addiu     $v1, $v0, 2
/* B7AA0C 802409BC AE630074 */  sw        $v1, 0x74($s3)
/* B7AA10 802409C0 8E82002C */  lw        $v0, 0x2c($s4)
/* B7AA14 802409C4 5840000F */  blezl     $v0, .L80240A04
/* B7AA18 802409C8 AE600070 */   sw       $zero, 0x70($s3)
/* B7AA1C 802409CC 8E820004 */  lw        $v0, 4($s4)
/* B7AA20 802409D0 5840000C */  blezl     $v0, .L80240A04
/* B7AA24 802409D4 AE600070 */   sw       $zero, 0x70($s3)
/* B7AA28 802409D8 1460000A */  bnez      $v1, .L80240A04
/* B7AA2C 802409DC 00000000 */   nop
/* B7AA30 802409E0 08090281 */  j         .L80240A04
/* B7AA34 802409E4 AE600070 */   sw       $zero, 0x70($s3)
.L802409E8:
/* B7AA38 802409E8 C604003C */  lwc1      $f4, 0x3c($s0)
/* B7AA3C 802409EC C600001C */  lwc1      $f0, 0x1c($s0)
/* B7AA40 802409F0 46002100 */  add.s     $f4, $f4, $f0
/* B7AA44 802409F4 C6020014 */  lwc1      $f2, 0x14($s0)
/* B7AA48 802409F8 46020001 */  sub.s     $f0, $f0, $f2
/* B7AA4C 802409FC E604003C */  swc1      $f4, 0x3c($s0)
/* B7AA50 80240A00 E600001C */  swc1      $f0, 0x1c($s0)
.L80240A04:
/* B7AA54 80240A04 8FBF0054 */  lw        $ra, 0x54($sp)
/* B7AA58 80240A08 8FB40050 */  lw        $s4, 0x50($sp)
/* B7AA5C 80240A0C 8FB3004C */  lw        $s3, 0x4c($sp)
/* B7AA60 80240A10 8FB20048 */  lw        $s2, 0x48($sp)
/* B7AA64 80240A14 8FB10044 */  lw        $s1, 0x44($sp)
/* B7AA68 80240A18 8FB00040 */  lw        $s0, 0x40($sp)
/* B7AA6C 80240A1C D7B40058 */  ldc1      $f20, 0x58($sp)
/* B7AA70 80240A20 03E00008 */  jr        $ra
/* B7AA74 80240A24 27BD0060 */   addiu    $sp, $sp, 0x60
