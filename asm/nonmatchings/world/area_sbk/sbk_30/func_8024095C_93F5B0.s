.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_93FF0C
/* 93FF0C 8024095C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 93FF10 80240960 AFB3003C */  sw        $s3, 0x3c($sp)
/* 93FF14 80240964 0080982D */  daddu     $s3, $a0, $zero
/* 93FF18 80240968 AFBF0044 */  sw        $ra, 0x44($sp)
/* 93FF1C 8024096C AFB40040 */  sw        $s4, 0x40($sp)
/* 93FF20 80240970 AFB20038 */  sw        $s2, 0x38($sp)
/* 93FF24 80240974 AFB10034 */  sw        $s1, 0x34($sp)
/* 93FF28 80240978 AFB00030 */  sw        $s0, 0x30($sp)
/* 93FF2C 8024097C 8E710148 */  lw        $s1, 0x148($s3)
/* 93FF30 80240980 00A0902D */  daddu     $s2, $a1, $zero
/* 93FF34 80240984 86240008 */  lh        $a0, 8($s1)
/* 93FF38 80240988 0C00EABB */  jal       get_npc_unsafe
/* 93FF3C 8024098C 00C0A02D */   daddu    $s4, $a2, $zero
/* 93FF40 80240990 8E430008 */  lw        $v1, 8($s2)
/* 93FF44 80240994 0460003B */  bltz      $v1, .L80240A84
/* 93FF48 80240998 0040802D */   daddu    $s0, $v0, $zero
/* 93FF4C 8024099C 8E620074 */  lw        $v0, 0x74($s3)
/* 93FF50 802409A0 1C400037 */  bgtz      $v0, .L80240A80
/* 93FF54 802409A4 2442FFFF */   addiu    $v0, $v0, -1
/* 93FF58 802409A8 0280202D */  daddu     $a0, $s4, $zero
/* 93FF5C 802409AC AE630074 */  sw        $v1, 0x74($s3)
/* 93FF60 802409B0 AFA00010 */  sw        $zero, 0x10($sp)
/* 93FF64 802409B4 8E460018 */  lw        $a2, 0x18($s2)
/* 93FF68 802409B8 8E47001C */  lw        $a3, 0x1c($s2)
/* 93FF6C 802409BC 0C01242D */  jal       func_800490B4
/* 93FF70 802409C0 0220282D */   daddu    $a1, $s1, $zero
/* 93FF74 802409C4 1040002C */  beqz      $v0, .L80240A78
/* 93FF78 802409C8 0000202D */   daddu    $a0, $zero, $zero
/* 93FF7C 802409CC 0200282D */  daddu     $a1, $s0, $zero
/* 93FF80 802409D0 0000302D */  daddu     $a2, $zero, $zero
/* 93FF84 802409D4 860300A8 */  lh        $v1, 0xa8($s0)
/* 93FF88 802409D8 3C013F80 */  lui       $at, 0x3f80
/* 93FF8C 802409DC 44810000 */  mtc1      $at, $f0
/* 93FF90 802409E0 3C014000 */  lui       $at, 0x4000
/* 93FF94 802409E4 44811000 */  mtc1      $at, $f2
/* 93FF98 802409E8 3C01C1A0 */  lui       $at, 0xc1a0
/* 93FF9C 802409EC 44812000 */  mtc1      $at, $f4
/* 93FFA0 802409F0 2402000F */  addiu     $v0, $zero, 0xf
/* 93FFA4 802409F4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 93FFA8 802409F8 44833000 */  mtc1      $v1, $f6
/* 93FFAC 802409FC 00000000 */  nop       
/* 93FFB0 80240A00 468031A0 */  cvt.s.w   $f6, $f6
/* 93FFB4 80240A04 44073000 */  mfc1      $a3, $f6
/* 93FFB8 80240A08 27A20028 */  addiu     $v0, $sp, 0x28
/* 93FFBC 80240A0C AFA20020 */  sw        $v0, 0x20($sp)
/* 93FFC0 80240A10 E7A00010 */  swc1      $f0, 0x10($sp)
/* 93FFC4 80240A14 E7A20014 */  swc1      $f2, 0x14($sp)
/* 93FFC8 80240A18 0C01BFA4 */  jal       fx_emote
/* 93FFCC 80240A1C E7A40018 */   swc1     $f4, 0x18($sp)
/* 93FFD0 80240A20 0200202D */  daddu     $a0, $s0, $zero
/* 93FFD4 80240A24 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 93FFD8 80240A28 0C012530 */  jal       func_800494C0
/* 93FFDC 80240A2C 3C060020 */   lui      $a2, 0x20
/* 93FFE0 80240A30 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 93FFE4 80240A34 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 93FFE8 80240A38 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 93FFEC 80240A3C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 93FFF0 80240A40 8C460028 */  lw        $a2, 0x28($v0)
/* 93FFF4 80240A44 0C00A720 */  jal       atan2
/* 93FFF8 80240A48 8C470030 */   lw       $a3, 0x30($v0)
/* 93FFFC 80240A4C E600000C */  swc1      $f0, 0xc($s0)
/* 940000 80240A50 8E220018 */  lw        $v0, 0x18($s1)
/* 940004 80240A54 9442002A */  lhu       $v0, 0x2a($v0)
/* 940008 80240A58 30420001 */  andi      $v0, $v0, 1
/* 94000C 80240A5C 10400003 */  beqz      $v0, .L80240A6C
/* 940010 80240A60 2402000A */   addiu    $v0, $zero, 0xa
/* 940014 80240A64 080902D1 */  j         .L80240B44
/* 940018 80240A68 AE620070 */   sw       $v0, 0x70($s3)
.L80240A6C:
/* 94001C 80240A6C 2402000C */  addiu     $v0, $zero, 0xc
/* 940020 80240A70 080902D1 */  j         .L80240B44
/* 940024 80240A74 AE620070 */   sw       $v0, 0x70($s3)
.L80240A78:
/* 940028 80240A78 8E620074 */  lw        $v0, 0x74($s3)
/* 94002C 80240A7C 2442FFFF */  addiu     $v0, $v0, -1
.L80240A80:
/* 940030 80240A80 AE620074 */  sw        $v0, 0x74($s3)
.L80240A84:
/* 940034 80240A84 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 940038 80240A88 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 94003C 80240A8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 940040 80240A90 C4460000 */  lwc1      $f6, ($v0)
/* 940044 80240A94 468031A0 */  cvt.s.w   $f6, $f6
/* 940048 80240A98 44063000 */  mfc1      $a2, $f6
/* 94004C 80240A9C C4460008 */  lwc1      $f6, 8($v0)
/* 940050 80240AA0 468031A0 */  cvt.s.w   $f6, $f6
/* 940054 80240AA4 44073000 */  mfc1      $a3, $f6
/* 940058 80240AA8 0C00A7B5 */  jal       dist2D
/* 94005C 80240AAC 00000000 */   nop      
/* 940060 80240AB0 C6020018 */  lwc1      $f2, 0x18($s0)
/* 940064 80240AB4 4602003C */  c.lt.s    $f0, $f2
/* 940068 80240AB8 00000000 */  nop       
/* 94006C 80240ABC 4500000E */  bc1f      .L80240AF8
/* 940070 80240AC0 00000000 */   nop      
/* 940074 80240AC4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 940078 80240AC8 C4400000 */  lwc1      $f0, ($v0)
/* 94007C 80240ACC 46800020 */  cvt.s.w   $f0, $f0
/* 940080 80240AD0 E6000038 */  swc1      $f0, 0x38($s0)
/* 940084 80240AD4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 940088 80240AD8 C4400008 */  lwc1      $f0, 8($v0)
/* 94008C 80240ADC 46800020 */  cvt.s.w   $f0, $f0
/* 940090 80240AE0 E6000040 */  swc1      $f0, 0x40($s0)
/* 940094 80240AE4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 940098 80240AE8 C440000C */  lwc1      $f0, 0xc($v0)
/* 94009C 80240AEC 46800020 */  cvt.s.w   $f0, $f0
/* 9400A0 80240AF0 E600000C */  swc1      $f0, 0xc($s0)
/* 9400A4 80240AF4 AE600070 */  sw        $zero, 0x70($s3)
.L80240AF8:
/* 9400A8 80240AF8 8602008C */  lh        $v0, 0x8c($s0)
/* 9400AC 80240AFC 14400011 */  bnez      $v0, .L80240B44
/* 9400B0 80240B00 00000000 */   nop      
/* 9400B4 80240B04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9400B8 80240B08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9400BC 80240B0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9400C0 80240B10 C4460000 */  lwc1      $f6, ($v0)
/* 9400C4 80240B14 468031A0 */  cvt.s.w   $f6, $f6
/* 9400C8 80240B18 44063000 */  mfc1      $a2, $f6
/* 9400CC 80240B1C C4460008 */  lwc1      $f6, 8($v0)
/* 9400D0 80240B20 468031A0 */  cvt.s.w   $f6, $f6
/* 9400D4 80240B24 44073000 */  mfc1      $a3, $f6
/* 9400D8 80240B28 0C00A720 */  jal       atan2
/* 9400DC 80240B2C 00000000 */   nop      
/* 9400E0 80240B30 8E050018 */  lw        $a1, 0x18($s0)
/* 9400E4 80240B34 44060000 */  mfc1      $a2, $f0
/* 9400E8 80240B38 0200202D */  daddu     $a0, $s0, $zero
/* 9400EC 80240B3C 0C00EA95 */  jal       npc_move_heading
/* 9400F0 80240B40 AC86000C */   sw       $a2, 0xc($a0)
.L80240B44:
/* 9400F4 80240B44 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9400F8 80240B48 8FB40040 */  lw        $s4, 0x40($sp)
/* 9400FC 80240B4C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 940100 80240B50 8FB20038 */  lw        $s2, 0x38($sp)
/* 940104 80240B54 8FB10034 */  lw        $s1, 0x34($sp)
/* 940108 80240B58 8FB00030 */  lw        $s0, 0x30($sp)
/* 94010C 80240B5C 03E00008 */  jr        $ra
/* 940110 80240B60 27BD0048 */   addiu    $sp, $sp, 0x48
