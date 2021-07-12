.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244480_B70810
.double 1.2

.section .text

glabel func_80240540_B6C8D0
/* B6C8D0 80240540 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B6C8D4 80240544 AFB3004C */  sw        $s3, 0x4c($sp)
/* B6C8D8 80240548 0080982D */  daddu     $s3, $a0, $zero
/* B6C8DC 8024054C AFBF0054 */  sw        $ra, 0x54($sp)
/* B6C8E0 80240550 AFB40050 */  sw        $s4, 0x50($sp)
/* B6C8E4 80240554 AFB20048 */  sw        $s2, 0x48($sp)
/* B6C8E8 80240558 AFB10044 */  sw        $s1, 0x44($sp)
/* B6C8EC 8024055C AFB00040 */  sw        $s0, 0x40($sp)
/* B6C8F0 80240560 F7B40058 */  sdc1      $f20, 0x58($sp)
/* B6C8F4 80240564 8E710148 */  lw        $s1, 0x148($s3)
/* B6C8F8 80240568 00A0A02D */  daddu     $s4, $a1, $zero
/* B6C8FC 8024056C 86240008 */  lh        $a0, 8($s1)
/* B6C900 80240570 0C00EABB */  jal       get_npc_unsafe
/* B6C904 80240574 00C0902D */   daddu    $s2, $a2, $zero
/* B6C908 80240578 8E830014 */  lw        $v1, 0x14($s4)
/* B6C90C 8024057C 04600034 */  bltz      $v1, .L80240650
/* B6C910 80240580 0040802D */   daddu    $s0, $v0, $zero
/* B6C914 80240584 8E620074 */  lw        $v0, 0x74($s3)
/* B6C918 80240588 1C400030 */  bgtz      $v0, .L8024064C
/* B6C91C 8024058C 2442FFFF */   addiu    $v0, $v0, -1
/* B6C920 80240590 0240202D */  daddu     $a0, $s2, $zero
/* B6C924 80240594 AE630074 */  sw        $v1, 0x74($s3)
/* B6C928 80240598 AFA00010 */  sw        $zero, 0x10($sp)
/* B6C92C 8024059C 8E86000C */  lw        $a2, 0xc($s4)
/* B6C930 802405A0 8E870010 */  lw        $a3, 0x10($s4)
/* B6C934 802405A4 0C01242D */  jal       func_800490B4
/* B6C938 802405A8 0220282D */   daddu    $a1, $s1, $zero
/* B6C93C 802405AC 10400025 */  beqz      $v0, .L80240644
/* B6C940 802405B0 0000202D */   daddu    $a0, $zero, $zero
/* B6C944 802405B4 0200282D */  daddu     $a1, $s0, $zero
/* B6C948 802405B8 0000302D */  daddu     $a2, $zero, $zero
/* B6C94C 802405BC 860300A8 */  lh        $v1, 0xa8($s0)
/* B6C950 802405C0 3C013F80 */  lui       $at, 0x3f80
/* B6C954 802405C4 44810000 */  mtc1      $at, $f0
/* B6C958 802405C8 3C014000 */  lui       $at, 0x4000
/* B6C95C 802405CC 44811000 */  mtc1      $at, $f2
/* B6C960 802405D0 3C01C1A0 */  lui       $at, 0xc1a0
/* B6C964 802405D4 44812000 */  mtc1      $at, $f4
/* B6C968 802405D8 2402000F */  addiu     $v0, $zero, 0xf
/* B6C96C 802405DC AFA2001C */  sw        $v0, 0x1c($sp)
/* B6C970 802405E0 44835000 */  mtc1      $v1, $f10
/* B6C974 802405E4 00000000 */  nop
/* B6C978 802405E8 468052A0 */  cvt.s.w   $f10, $f10
/* B6C97C 802405EC 44075000 */  mfc1      $a3, $f10
/* B6C980 802405F0 27A20028 */  addiu     $v0, $sp, 0x28
/* B6C984 802405F4 AFA20020 */  sw        $v0, 0x20($sp)
/* B6C988 802405F8 E7A00010 */  swc1      $f0, 0x10($sp)
/* B6C98C 802405FC E7A20014 */  swc1      $f2, 0x14($sp)
/* B6C990 80240600 0C01BFA4 */  jal       fx_emote
/* B6C994 80240604 E7A40018 */   swc1     $f4, 0x18($sp)
/* B6C998 80240608 0200202D */  daddu     $a0, $s0, $zero
/* B6C99C 8024060C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B6C9A0 80240610 0C012530 */  jal       ai_enemy_play_sound
/* B6C9A4 80240614 3C060020 */   lui      $a2, 0x20
/* B6C9A8 80240618 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B6C9AC 8024061C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B6C9B0 80240620 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B6C9B4 80240624 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B6C9B8 80240628 8C460028 */  lw        $a2, 0x28($v0)
/* B6C9BC 8024062C 0C00A720 */  jal       atan2
/* B6C9C0 80240630 8C470030 */   lw       $a3, 0x30($v0)
/* B6C9C4 80240634 2402000C */  addiu     $v0, $zero, 0xc
/* B6C9C8 80240638 E600000C */  swc1      $f0, 0xc($s0)
/* B6C9CC 8024063C 08090215 */  j         .L80240854
/* B6C9D0 80240640 AE620070 */   sw       $v0, 0x70($s3)
.L80240644:
/* B6C9D4 80240644 8E620074 */  lw        $v0, 0x74($s3)
/* B6C9D8 80240648 2442FFFF */  addiu     $v0, $v0, -1
.L8024064C:
/* B6C9DC 8024064C AE620074 */  sw        $v0, 0x74($s3)
.L80240650:
/* B6C9E0 80240650 C6000018 */  lwc1      $f0, 0x18($s0)
/* B6C9E4 80240654 44801000 */  mtc1      $zero, $f2
/* B6C9E8 80240658 44801800 */  mtc1      $zero, $f3
/* B6C9EC 8024065C 46000021 */  cvt.d.s   $f0, $f0
/* B6C9F0 80240660 4620103C */  c.lt.d    $f2, $f0
/* B6C9F4 80240664 00000000 */  nop
/* B6C9F8 80240668 45000025 */  bc1f      .L80240700
/* B6C9FC 8024066C 27A5002C */   addiu    $a1, $sp, 0x2c
/* B6CA00 80240670 C6000038 */  lwc1      $f0, 0x38($s0)
/* B6CA04 80240674 860200A6 */  lh        $v0, 0xa6($s0)
/* B6CA08 80240678 3C018024 */  lui       $at, %hi(D_80244480_B70810)
/* B6CA0C 8024067C D4224480 */  ldc1      $f2, %lo(D_80244480_B70810)($at)
/* B6CA10 80240680 27A60030 */  addiu     $a2, $sp, 0x30
/* B6CA14 80240684 E7A0002C */  swc1      $f0, 0x2c($sp)
/* B6CA18 80240688 44820000 */  mtc1      $v0, $f0
/* B6CA1C 8024068C 00000000 */  nop
/* B6CA20 80240690 46800020 */  cvt.s.w   $f0, $f0
/* B6CA24 80240694 46000021 */  cvt.d.s   $f0, $f0
/* B6CA28 80240698 C604003C */  lwc1      $f4, 0x3c($s0)
/* B6CA2C 8024069C C6060040 */  lwc1      $f6, 0x40($s0)
/* B6CA30 802406A0 C6080018 */  lwc1      $f8, 0x18($s0)
/* B6CA34 802406A4 860200A8 */  lh        $v0, 0xa8($s0)
/* B6CA38 802406A8 46220002 */  mul.d     $f0, $f0, $f2
/* B6CA3C 802406AC 00000000 */  nop
/* B6CA40 802406B0 E7A40030 */  swc1      $f4, 0x30($sp)
/* B6CA44 802406B4 E7A60034 */  swc1      $f6, 0x34($sp)
/* B6CA48 802406B8 E7A80010 */  swc1      $f8, 0x10($sp)
/* B6CA4C 802406BC C604000C */  lwc1      $f4, 0xc($s0)
/* B6CA50 802406C0 44821000 */  mtc1      $v0, $f2
/* B6CA54 802406C4 00000000 */  nop
/* B6CA58 802406C8 468010A0 */  cvt.s.w   $f2, $f2
/* B6CA5C 802406CC E7A20018 */  swc1      $f2, 0x18($sp)
/* B6CA60 802406D0 E7A40014 */  swc1      $f4, 0x14($sp)
/* B6CA64 802406D4 46200020 */  cvt.s.d   $f0, $f0
/* B6CA68 802406D8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B6CA6C 802406DC 8E040080 */  lw        $a0, 0x80($s0)
/* B6CA70 802406E0 0C037711 */  jal       npc_test_move_simple_with_slipping
/* B6CA74 802406E4 27A70034 */   addiu    $a3, $sp, 0x34
/* B6CA78 802406E8 54400005 */  bnel      $v0, $zero, .L80240700
/* B6CA7C 802406EC AE000018 */   sw       $zero, 0x18($s0)
/* B6CA80 802406F0 8E050018 */  lw        $a1, 0x18($s0)
/* B6CA84 802406F4 8E06000C */  lw        $a2, 0xc($s0)
/* B6CA88 802406F8 0C00EA95 */  jal       npc_move_heading
/* B6CA8C 802406FC 0200202D */   daddu    $a0, $s0, $zero
.L80240700:
/* B6CA90 80240700 C600001C */  lwc1      $f0, 0x1c($s0)
/* B6CA94 80240704 44801000 */  mtc1      $zero, $f2
/* B6CA98 80240708 44801800 */  mtc1      $zero, $f3
/* B6CA9C 8024070C 46000021 */  cvt.d.s   $f0, $f0
/* B6CAA0 80240710 4622003C */  c.lt.d    $f0, $f2
/* B6CAA4 80240714 00000000 */  nop
/* B6CAA8 80240718 45000047 */  bc1f      .L80240838
/* B6CAAC 8024071C 27A5002C */   addiu    $a1, $sp, 0x2c
/* B6CAB0 80240720 27A60030 */  addiu     $a2, $sp, 0x30
/* B6CAB4 80240724 27A20038 */  addiu     $v0, $sp, 0x38
/* B6CAB8 80240728 C602003C */  lwc1      $f2, 0x3c($s0)
/* B6CABC 8024072C C6060038 */  lwc1      $f6, 0x38($s0)
/* B6CAC0 80240730 3C01402A */  lui       $at, 0x402a
/* B6CAC4 80240734 4481A800 */  mtc1      $at, $f21
/* B6CAC8 80240738 4480A000 */  mtc1      $zero, $f20
/* B6CACC 8024073C 460010A1 */  cvt.d.s   $f2, $f2
/* B6CAD0 80240740 46341080 */  add.d     $f2, $f2, $f20
/* B6CAD4 80240744 C600001C */  lwc1      $f0, 0x1c($s0)
/* B6CAD8 80240748 C6040040 */  lwc1      $f4, 0x40($s0)
/* B6CADC 8024074C 46000005 */  abs.s     $f0, $f0
/* B6CAE0 80240750 E7A40034 */  swc1      $f4, 0x34($sp)
/* B6CAE4 80240754 3C014030 */  lui       $at, 0x4030
/* B6CAE8 80240758 44812800 */  mtc1      $at, $f5
/* B6CAEC 8024075C 44802000 */  mtc1      $zero, $f4
/* B6CAF0 80240760 46000021 */  cvt.d.s   $f0, $f0
/* B6CAF4 80240764 E7A6002C */  swc1      $f6, 0x2c($sp)
/* B6CAF8 80240768 46240000 */  add.d     $f0, $f0, $f4
/* B6CAFC 8024076C 462010A0 */  cvt.s.d   $f2, $f2
/* B6CB00 80240770 E7A20030 */  swc1      $f2, 0x30($sp)
/* B6CB04 80240774 46200020 */  cvt.s.d   $f0, $f0
/* B6CB08 80240778 E7A00038 */  swc1      $f0, 0x38($sp)
/* B6CB0C 8024077C AFA20010 */  sw        $v0, 0x10($sp)
/* B6CB10 80240780 8E040080 */  lw        $a0, 0x80($s0)
/* B6CB14 80240784 0C0372DF */  jal       npc_raycast_down_sides
/* B6CB18 80240788 27A70034 */   addiu    $a3, $sp, 0x34
/* B6CB1C 8024078C 1040002A */  beqz      $v0, .L80240838
/* B6CB20 80240790 00000000 */   nop
/* B6CB24 80240794 C600001C */  lwc1      $f0, 0x1c($s0)
/* B6CB28 80240798 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B6CB2C 8024079C 46000005 */  abs.s     $f0, $f0
/* B6CB30 802407A0 46000021 */  cvt.d.s   $f0, $f0
/* B6CB34 802407A4 46340000 */  add.d     $f0, $f0, $f20
/* B6CB38 802407A8 460010A1 */  cvt.d.s   $f2, $f2
/* B6CB3C 802407AC 4620103E */  c.le.d    $f2, $f0
/* B6CB40 802407B0 00000000 */  nop
/* B6CB44 802407B4 45000020 */  bc1f      .L80240838
/* B6CB48 802407B8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B6CB4C 802407BC C7A00030 */  lwc1      $f0, 0x30($sp)
/* B6CB50 802407C0 8E020000 */  lw        $v0, ($s0)
/* B6CB54 802407C4 2403F7FF */  addiu     $v1, $zero, -0x801
/* B6CB58 802407C8 AE00001C */  sw        $zero, 0x1c($s0)
/* B6CB5C 802407CC 00431024 */  and       $v0, $v0, $v1
/* B6CB60 802407D0 AE020000 */  sw        $v0, ($s0)
/* B6CB64 802407D4 24020002 */  addiu     $v0, $zero, 2
/* B6CB68 802407D8 E600003C */  swc1      $f0, 0x3c($s0)
/* B6CB6C 802407DC 0C00A67F */  jal       rand_int
/* B6CB70 802407E0 AE620070 */   sw       $v0, 0x70($s3)
/* B6CB74 802407E4 3C035555 */  lui       $v1, 0x5555
/* B6CB78 802407E8 34635556 */  ori       $v1, $v1, 0x5556
/* B6CB7C 802407EC 00430018 */  mult      $v0, $v1
/* B6CB80 802407F0 000227C3 */  sra       $a0, $v0, 0x1f
/* B6CB84 802407F4 00004010 */  mfhi      $t0
/* B6CB88 802407F8 01042023 */  subu      $a0, $t0, $a0
/* B6CB8C 802407FC 00041840 */  sll       $v1, $a0, 1
/* B6CB90 80240800 00641821 */  addu      $v1, $v1, $a0
/* B6CB94 80240804 00431023 */  subu      $v0, $v0, $v1
/* B6CB98 80240808 24430002 */  addiu     $v1, $v0, 2
/* B6CB9C 8024080C AE630074 */  sw        $v1, 0x74($s3)
/* B6CBA0 80240810 8E82002C */  lw        $v0, 0x2c($s4)
/* B6CBA4 80240814 5840000F */  blezl     $v0, .L80240854
/* B6CBA8 80240818 AE600070 */   sw       $zero, 0x70($s3)
/* B6CBAC 8024081C 8E820004 */  lw        $v0, 4($s4)
/* B6CBB0 80240820 5840000C */  blezl     $v0, .L80240854
/* B6CBB4 80240824 AE600070 */   sw       $zero, 0x70($s3)
/* B6CBB8 80240828 1460000A */  bnez      $v1, .L80240854
/* B6CBBC 8024082C 00000000 */   nop
/* B6CBC0 80240830 08090215 */  j         .L80240854
/* B6CBC4 80240834 AE600070 */   sw       $zero, 0x70($s3)
.L80240838:
/* B6CBC8 80240838 C604003C */  lwc1      $f4, 0x3c($s0)
/* B6CBCC 8024083C C600001C */  lwc1      $f0, 0x1c($s0)
/* B6CBD0 80240840 46002100 */  add.s     $f4, $f4, $f0
/* B6CBD4 80240844 C6020014 */  lwc1      $f2, 0x14($s0)
/* B6CBD8 80240848 46020001 */  sub.s     $f0, $f0, $f2
/* B6CBDC 8024084C E604003C */  swc1      $f4, 0x3c($s0)
/* B6CBE0 80240850 E600001C */  swc1      $f0, 0x1c($s0)
.L80240854:
/* B6CBE4 80240854 8FBF0054 */  lw        $ra, 0x54($sp)
/* B6CBE8 80240858 8FB40050 */  lw        $s4, 0x50($sp)
/* B6CBEC 8024085C 8FB3004C */  lw        $s3, 0x4c($sp)
/* B6CBF0 80240860 8FB20048 */  lw        $s2, 0x48($sp)
/* B6CBF4 80240864 8FB10044 */  lw        $s1, 0x44($sp)
/* B6CBF8 80240868 8FB00040 */  lw        $s0, 0x40($sp)
/* B6CBFC 8024086C D7B40058 */  ldc1      $f20, 0x58($sp)
/* B6CC00 80240870 03E00008 */  jr        $ra
/* B6CC04 80240874 27BD0060 */   addiu    $sp, $sp, 0x60
