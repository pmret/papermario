.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240720_C6EA50
/* C6EA50 80240720 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C6EA54 80240724 AFB1001C */  sw        $s1, 0x1c($sp)
/* C6EA58 80240728 00A0882D */  daddu     $s1, $a1, $zero
/* C6EA5C 8024072C AFBF0020 */  sw        $ra, 0x20($sp)
/* C6EA60 80240730 AFB00018 */  sw        $s0, 0x18($sp)
/* C6EA64 80240734 8E220070 */  lw        $v0, 0x70($s1)
/* C6EA68 80240738 3C0141C8 */  lui       $at, 0x41c8
/* C6EA6C 8024073C 44810000 */  mtc1      $at, $f0
/* C6EA70 80240740 00021080 */  sll       $v0, $v0, 2
/* C6EA74 80240744 3C018024 */  lui       $at, %hi(D_80242930_C70C60)
/* C6EA78 80240748 00220821 */  addu      $at, $at, $v0
/* C6EA7C 8024074C C4222930 */  lwc1      $f2, %lo(D_80242930_C70C60)($at)
/* C6EA80 80240750 46001082 */  mul.s     $f2, $f2, $f0
/* C6EA84 80240754 00000000 */  nop
/* C6EA88 80240758 C6200084 */  lwc1      $f0, 0x84($s1)
/* C6EA8C 8024075C 46800020 */  cvt.s.w   $f0, $f0
/* C6EA90 80240760 46020001 */  sub.s     $f0, $f0, $f2
/* C6EA94 80240764 0080802D */  daddu     $s0, $a0, $zero
/* C6EA98 80240768 E600004C */  swc1      $f0, 0x4c($s0)
/* C6EA9C 8024076C 8E220070 */  lw        $v0, 0x70($s1)
/* C6EAA0 80240770 14400007 */  bnez      $v0, .L80240790
/* C6EAA4 80240774 240401DA */   addiu    $a0, $zero, 0x1da
/* C6EAA8 80240778 C6000050 */  lwc1      $f0, 0x50($s0)
/* C6EAAC 8024077C E7A00010 */  swc1      $f0, 0x10($sp)
/* C6EAB0 80240780 8E060048 */  lw        $a2, 0x48($s0)
/* C6EAB4 80240784 8E07004C */  lw        $a3, 0x4c($s0)
/* C6EAB8 80240788 0C052757 */  jal       play_sound_at_position
/* C6EABC 8024078C 0000282D */   daddu    $a1, $zero, $zero
.L80240790:
/* C6EAC0 80240790 8E230070 */  lw        $v1, 0x70($s1)
/* C6EAC4 80240794 28620005 */  slti      $v0, $v1, 5
/* C6EAC8 80240798 1440000C */  bnez      $v0, .L802407CC
/* C6EACC 8024079C 30620001 */   andi     $v0, $v1, 1
/* C6EAD0 802407A0 1040000A */  beqz      $v0, .L802407CC
/* C6EAD4 802407A4 24020014 */   addiu    $v0, $zero, 0x14
/* C6EAD8 802407A8 3C013F80 */  lui       $at, 0x3f80
/* C6EADC 802407AC 44810000 */  mtc1      $at, $f0
/* C6EAE0 802407B0 AFA20014 */  sw        $v0, 0x14($sp)
/* C6EAE4 802407B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C6EAE8 802407B8 8E050048 */  lw        $a1, 0x48($s0)
/* C6EAEC 802407BC 8E06004C */  lw        $a2, 0x4c($s0)
/* C6EAF0 802407C0 8E070050 */  lw        $a3, 0x50($s0)
/* C6EAF4 802407C4 0C01C1CC */  jal       func_80070730
/* C6EAF8 802407C8 24040001 */   addiu    $a0, $zero, 1
.L802407CC:
/* C6EAFC 802407CC 8E220070 */  lw        $v0, 0x70($s1)
/* C6EB00 802407D0 24420001 */  addiu     $v0, $v0, 1
/* C6EB04 802407D4 AE220070 */  sw        $v0, 0x70($s1)
/* C6EB08 802407D8 3842001C */  xori      $v0, $v0, 0x1c
/* C6EB0C 802407DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C6EB10 802407E0 8FB1001C */  lw        $s1, 0x1c($sp)
/* C6EB14 802407E4 8FB00018 */  lw        $s0, 0x18($sp)
/* C6EB18 802407E8 2C420001 */  sltiu     $v0, $v0, 1
/* C6EB1C 802407EC 03E00008 */  jr        $ra
/* C6EB20 802407F0 27BD0028 */   addiu    $sp, $sp, 0x28
