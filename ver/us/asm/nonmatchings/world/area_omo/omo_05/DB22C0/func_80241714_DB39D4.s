.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241714_DB39D4
/* DB39D4 80241714 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DB39D8 80241718 AFB3001C */  sw        $s3, 0x1c($sp)
/* DB39DC 8024171C 0080982D */  daddu     $s3, $a0, $zero
/* DB39E0 80241720 AFBF0020 */  sw        $ra, 0x20($sp)
/* DB39E4 80241724 AFB20018 */  sw        $s2, 0x18($sp)
/* DB39E8 80241728 AFB10014 */  sw        $s1, 0x14($sp)
/* DB39EC 8024172C AFB00010 */  sw        $s0, 0x10($sp)
/* DB39F0 80241730 8E720148 */  lw        $s2, 0x148($s3)
/* DB39F4 80241734 86440008 */  lh        $a0, 8($s2)
/* DB39F8 80241738 0C00EABB */  jal       get_npc_unsafe
/* DB39FC 8024173C 00A0802D */   daddu    $s0, $a1, $zero
/* DB3A00 80241740 0040882D */  daddu     $s1, $v0, $zero
/* DB3A04 80241744 C6420080 */  lwc1      $f2, 0x80($s2)
/* DB3A08 80241748 468010A0 */  cvt.s.w   $f2, $f2
/* DB3A0C 8024174C 460010A1 */  cvt.d.s   $f2, $f2
/* DB3A10 80241750 C6400084 */  lwc1      $f0, 0x84($s2)
/* DB3A14 80241754 46800020 */  cvt.s.w   $f0, $f0
/* DB3A18 80241758 46000021 */  cvt.d.s   $f0, $f0
/* DB3A1C 8024175C 3C014059 */  lui       $at, 0x4059
/* DB3A20 80241760 44812800 */  mtc1      $at, $f5
/* DB3A24 80241764 44802000 */  mtc1      $zero, $f4
/* DB3A28 80241768 8E4200CC */  lw        $v0, 0xcc($s2)
/* DB3A2C 8024176C C62C0038 */  lwc1      $f12, 0x38($s1)
/* DB3A30 80241770 C62E0040 */  lwc1      $f14, 0x40($s1)
/* DB3A34 80241774 46241083 */  div.d     $f2, $f2, $f4
/* DB3A38 80241778 462010A0 */  cvt.s.d   $f2, $f2
/* DB3A3C 8024177C 46240003 */  div.d     $f0, $f0, $f4
/* DB3A40 80241780 8C420020 */  lw        $v0, 0x20($v0)
/* DB3A44 80241784 46200020 */  cvt.s.d   $f0, $f0
/* DB3A48 80241788 E622001C */  swc1      $f2, 0x1c($s1)
/* DB3A4C 8024178C E6200014 */  swc1      $f0, 0x14($s1)
/* DB3A50 80241790 AE220028 */  sw        $v0, 0x28($s1)
/* DB3A54 80241794 C6000018 */  lwc1      $f0, 0x18($s0)
/* DB3A58 80241798 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DB3A5C 8024179C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DB3A60 802417A0 E6200018 */  swc1      $f0, 0x18($s1)
/* DB3A64 802417A4 8C460028 */  lw        $a2, 0x28($v0)
/* DB3A68 802417A8 0C00A720 */  jal       atan2
/* DB3A6C 802417AC 8C470030 */   lw       $a3, 0x30($v0)
/* DB3A70 802417B0 E620000C */  swc1      $f0, 0xc($s1)
/* DB3A74 802417B4 8E420018 */  lw        $v0, 0x18($s2)
/* DB3A78 802417B8 AE400074 */  sw        $zero, 0x74($s2)
/* DB3A7C 802417BC 9442002A */  lhu       $v0, 0x2a($v0)
/* DB3A80 802417C0 30420002 */  andi      $v0, $v0, 2
/* DB3A84 802417C4 10400005 */  beqz      $v0, .L802417DC
/* DB3A88 802417C8 24020003 */   addiu    $v0, $zero, 3
/* DB3A8C 802417CC A622008E */  sh        $v0, 0x8e($s1)
/* DB3A90 802417D0 2402000D */  addiu     $v0, $zero, 0xd
/* DB3A94 802417D4 0809060B */  j         .L8024182C
/* DB3A98 802417D8 AE620070 */   sw       $v0, 0x70($s3)
.L802417DC:
/* DB3A9C 802417DC 24030001 */  addiu     $v1, $zero, 1
/* DB3AA0 802417E0 2402000E */  addiu     $v0, $zero, 0xe
/* DB3AA4 802417E4 A623008E */  sh        $v1, 0x8e($s1)
/* DB3AA8 802417E8 AE620070 */  sw        $v0, 0x70($s3)
/* DB3AAC 802417EC C6200038 */  lwc1      $f0, 0x38($s1)
/* DB3AB0 802417F0 4600018D */  trunc.w.s $f6, $f0
/* DB3AB4 802417F4 44023000 */  mfc1      $v0, $f6
/* DB3AB8 802417F8 00000000 */  nop
/* DB3ABC 802417FC A6420010 */  sh        $v0, 0x10($s2)
/* DB3AC0 80241800 C620003C */  lwc1      $f0, 0x3c($s1)
/* DB3AC4 80241804 4600018D */  trunc.w.s $f6, $f0
/* DB3AC8 80241808 44023000 */  mfc1      $v0, $f6
/* DB3ACC 8024180C 00000000 */  nop
/* DB3AD0 80241810 A6420012 */  sh        $v0, 0x12($s2)
/* DB3AD4 80241814 C6200040 */  lwc1      $f0, 0x40($s1)
/* DB3AD8 80241818 A2430007 */  sb        $v1, 7($s2)
/* DB3ADC 8024181C 4600018D */  trunc.w.s $f6, $f0
/* DB3AE0 80241820 44023000 */  mfc1      $v0, $f6
/* DB3AE4 80241824 00000000 */  nop
/* DB3AE8 80241828 A6420014 */  sh        $v0, 0x14($s2)
.L8024182C:
/* DB3AEC 8024182C 8FBF0020 */  lw        $ra, 0x20($sp)
/* DB3AF0 80241830 8FB3001C */  lw        $s3, 0x1c($sp)
/* DB3AF4 80241834 8FB20018 */  lw        $s2, 0x18($sp)
/* DB3AF8 80241838 8FB10014 */  lw        $s1, 0x14($sp)
/* DB3AFC 8024183C 8FB00010 */  lw        $s0, 0x10($sp)
/* DB3B00 80241840 03E00008 */  jr        $ra
/* DB3B04 80241844 27BD0028 */   addiu    $sp, $sp, 0x28
