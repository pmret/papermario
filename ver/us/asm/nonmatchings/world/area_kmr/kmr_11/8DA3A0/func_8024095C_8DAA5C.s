.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_8DAA5C
/* 8DAA5C 8024095C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8DAA60 80240960 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8DAA64 80240964 0080982D */  daddu     $s3, $a0, $zero
/* 8DAA68 80240968 AFBF0044 */  sw        $ra, 0x44($sp)
/* 8DAA6C 8024096C AFB40040 */  sw        $s4, 0x40($sp)
/* 8DAA70 80240970 AFB20038 */  sw        $s2, 0x38($sp)
/* 8DAA74 80240974 AFB10034 */  sw        $s1, 0x34($sp)
/* 8DAA78 80240978 AFB00030 */  sw        $s0, 0x30($sp)
/* 8DAA7C 8024097C 8E710148 */  lw        $s1, 0x148($s3)
/* 8DAA80 80240980 00A0902D */  daddu     $s2, $a1, $zero
/* 8DAA84 80240984 86240008 */  lh        $a0, 8($s1)
/* 8DAA88 80240988 0C00EABB */  jal       get_npc_unsafe
/* 8DAA8C 8024098C 00C0A02D */   daddu    $s4, $a2, $zero
/* 8DAA90 80240990 8E430008 */  lw        $v1, 8($s2)
/* 8DAA94 80240994 0460003B */  bltz      $v1, .L80240A84
/* 8DAA98 80240998 0040802D */   daddu    $s0, $v0, $zero
/* 8DAA9C 8024099C 8E620074 */  lw        $v0, 0x74($s3)
/* 8DAAA0 802409A0 1C400037 */  bgtz      $v0, .L80240A80
/* 8DAAA4 802409A4 2442FFFF */   addiu    $v0, $v0, -1
/* 8DAAA8 802409A8 0280202D */  daddu     $a0, $s4, $zero
/* 8DAAAC 802409AC AE630074 */  sw        $v1, 0x74($s3)
/* 8DAAB0 802409B0 AFA00010 */  sw        $zero, 0x10($sp)
/* 8DAAB4 802409B4 8E460018 */  lw        $a2, 0x18($s2)
/* 8DAAB8 802409B8 8E47001C */  lw        $a3, 0x1c($s2)
/* 8DAABC 802409BC 0C01242D */  jal       func_800490B4
/* 8DAAC0 802409C0 0220282D */   daddu    $a1, $s1, $zero
/* 8DAAC4 802409C4 1040002C */  beqz      $v0, .L80240A78
/* 8DAAC8 802409C8 0000202D */   daddu    $a0, $zero, $zero
/* 8DAACC 802409CC 0200282D */  daddu     $a1, $s0, $zero
/* 8DAAD0 802409D0 0000302D */  daddu     $a2, $zero, $zero
/* 8DAAD4 802409D4 860300A8 */  lh        $v1, 0xa8($s0)
/* 8DAAD8 802409D8 3C013F80 */  lui       $at, 0x3f80
/* 8DAADC 802409DC 44810000 */  mtc1      $at, $f0
/* 8DAAE0 802409E0 3C014000 */  lui       $at, 0x4000
/* 8DAAE4 802409E4 44811000 */  mtc1      $at, $f2
/* 8DAAE8 802409E8 3C01C1A0 */  lui       $at, 0xc1a0
/* 8DAAEC 802409EC 44812000 */  mtc1      $at, $f4
/* 8DAAF0 802409F0 2402000F */  addiu     $v0, $zero, 0xf
/* 8DAAF4 802409F4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8DAAF8 802409F8 44833000 */  mtc1      $v1, $f6
/* 8DAAFC 802409FC 00000000 */  nop
/* 8DAB00 80240A00 468031A0 */  cvt.s.w   $f6, $f6
/* 8DAB04 80240A04 44073000 */  mfc1      $a3, $f6
/* 8DAB08 80240A08 27A20028 */  addiu     $v0, $sp, 0x28
/* 8DAB0C 80240A0C AFA20020 */  sw        $v0, 0x20($sp)
/* 8DAB10 80240A10 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8DAB14 80240A14 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8DAB18 80240A18 0C01BFA4 */  jal       fx_emote
/* 8DAB1C 80240A1C E7A40018 */   swc1     $f4, 0x18($sp)
/* 8DAB20 80240A20 0200202D */  daddu     $a0, $s0, $zero
/* 8DAB24 80240A24 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 8DAB28 80240A28 0C012530 */  jal       func_800494C0
/* 8DAB2C 80240A2C 3C060020 */   lui      $a2, 0x20
/* 8DAB30 80240A30 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8DAB34 80240A34 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8DAB38 80240A38 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8DAB3C 80240A3C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8DAB40 80240A40 8C460028 */  lw        $a2, 0x28($v0)
/* 8DAB44 80240A44 0C00A720 */  jal       atan2
/* 8DAB48 80240A48 8C470030 */   lw       $a3, 0x30($v0)
/* 8DAB4C 80240A4C E600000C */  swc1      $f0, 0xc($s0)
/* 8DAB50 80240A50 8E220018 */  lw        $v0, 0x18($s1)
/* 8DAB54 80240A54 9442002A */  lhu       $v0, 0x2a($v0)
/* 8DAB58 80240A58 30420001 */  andi      $v0, $v0, 1
/* 8DAB5C 80240A5C 10400003 */  beqz      $v0, .L80240A6C
/* 8DAB60 80240A60 2402000A */   addiu    $v0, $zero, 0xa
/* 8DAB64 80240A64 080902D1 */  j         .L80240B44
/* 8DAB68 80240A68 AE620070 */   sw       $v0, 0x70($s3)
.L80240A6C:
/* 8DAB6C 80240A6C 2402000C */  addiu     $v0, $zero, 0xc
/* 8DAB70 80240A70 080902D1 */  j         .L80240B44
/* 8DAB74 80240A74 AE620070 */   sw       $v0, 0x70($s3)
.L80240A78:
/* 8DAB78 80240A78 8E620074 */  lw        $v0, 0x74($s3)
/* 8DAB7C 80240A7C 2442FFFF */  addiu     $v0, $v0, -1
.L80240A80:
/* 8DAB80 80240A80 AE620074 */  sw        $v0, 0x74($s3)
.L80240A84:
/* 8DAB84 80240A84 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8DAB88 80240A88 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8DAB8C 80240A8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8DAB90 80240A90 C4460000 */  lwc1      $f6, ($v0)
/* 8DAB94 80240A94 468031A0 */  cvt.s.w   $f6, $f6
/* 8DAB98 80240A98 44063000 */  mfc1      $a2, $f6
/* 8DAB9C 80240A9C C4460008 */  lwc1      $f6, 8($v0)
/* 8DABA0 80240AA0 468031A0 */  cvt.s.w   $f6, $f6
/* 8DABA4 80240AA4 44073000 */  mfc1      $a3, $f6
/* 8DABA8 80240AA8 0C00A7B5 */  jal       dist2D
/* 8DABAC 80240AAC 00000000 */   nop
/* 8DABB0 80240AB0 C6020018 */  lwc1      $f2, 0x18($s0)
/* 8DABB4 80240AB4 4602003C */  c.lt.s    $f0, $f2
/* 8DABB8 80240AB8 00000000 */  nop
/* 8DABBC 80240ABC 4500000E */  bc1f      .L80240AF8
/* 8DABC0 80240AC0 00000000 */   nop
/* 8DABC4 80240AC4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8DABC8 80240AC8 C4400000 */  lwc1      $f0, ($v0)
/* 8DABCC 80240ACC 46800020 */  cvt.s.w   $f0, $f0
/* 8DABD0 80240AD0 E6000038 */  swc1      $f0, 0x38($s0)
/* 8DABD4 80240AD4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8DABD8 80240AD8 C4400008 */  lwc1      $f0, 8($v0)
/* 8DABDC 80240ADC 46800020 */  cvt.s.w   $f0, $f0
/* 8DABE0 80240AE0 E6000040 */  swc1      $f0, 0x40($s0)
/* 8DABE4 80240AE4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8DABE8 80240AE8 C440000C */  lwc1      $f0, 0xc($v0)
/* 8DABEC 80240AEC 46800020 */  cvt.s.w   $f0, $f0
/* 8DABF0 80240AF0 E600000C */  swc1      $f0, 0xc($s0)
/* 8DABF4 80240AF4 AE600070 */  sw        $zero, 0x70($s3)
.L80240AF8:
/* 8DABF8 80240AF8 8602008C */  lh        $v0, 0x8c($s0)
/* 8DABFC 80240AFC 14400011 */  bnez      $v0, .L80240B44
/* 8DAC00 80240B00 00000000 */   nop
/* 8DAC04 80240B04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8DAC08 80240B08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8DAC0C 80240B0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8DAC10 80240B10 C4460000 */  lwc1      $f6, ($v0)
/* 8DAC14 80240B14 468031A0 */  cvt.s.w   $f6, $f6
/* 8DAC18 80240B18 44063000 */  mfc1      $a2, $f6
/* 8DAC1C 80240B1C C4460008 */  lwc1      $f6, 8($v0)
/* 8DAC20 80240B20 468031A0 */  cvt.s.w   $f6, $f6
/* 8DAC24 80240B24 44073000 */  mfc1      $a3, $f6
/* 8DAC28 80240B28 0C00A720 */  jal       atan2
/* 8DAC2C 80240B2C 00000000 */   nop
/* 8DAC30 80240B30 8E050018 */  lw        $a1, 0x18($s0)
/* 8DAC34 80240B34 44060000 */  mfc1      $a2, $f0
/* 8DAC38 80240B38 0200202D */  daddu     $a0, $s0, $zero
/* 8DAC3C 80240B3C 0C00EA95 */  jal       npc_move_heading
/* 8DAC40 80240B40 AC86000C */   sw       $a2, 0xc($a0)
.L80240B44:
/* 8DAC44 80240B44 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8DAC48 80240B48 8FB40040 */  lw        $s4, 0x40($sp)
/* 8DAC4C 80240B4C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8DAC50 80240B50 8FB20038 */  lw        $s2, 0x38($sp)
/* 8DAC54 80240B54 8FB10034 */  lw        $s1, 0x34($sp)
/* 8DAC58 80240B58 8FB00030 */  lw        $s0, 0x30($sp)
/* 8DAC5C 80240B5C 03E00008 */  jr        $ra
/* 8DAC60 80240B60 27BD0048 */   addiu    $sp, $sp, 0x48
