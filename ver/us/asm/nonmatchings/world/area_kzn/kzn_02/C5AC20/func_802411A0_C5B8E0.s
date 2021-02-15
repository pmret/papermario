.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A0_C5B8E0
/* C5B8E0 802411A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C5B8E4 802411A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* C5B8E8 802411A8 0080982D */  daddu     $s3, $a0, $zero
/* C5B8EC 802411AC AFBF0020 */  sw        $ra, 0x20($sp)
/* C5B8F0 802411B0 AFB20018 */  sw        $s2, 0x18($sp)
/* C5B8F4 802411B4 AFB10014 */  sw        $s1, 0x14($sp)
/* C5B8F8 802411B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C5B8FC 802411BC 8E720148 */  lw        $s2, 0x148($s3)
/* C5B900 802411C0 86440008 */  lh        $a0, 8($s2)
/* C5B904 802411C4 0C00EABB */  jal       get_npc_unsafe
/* C5B908 802411C8 00A0802D */   daddu    $s0, $a1, $zero
/* C5B90C 802411CC 0040882D */  daddu     $s1, $v0, $zero
/* C5B910 802411D0 C6420080 */  lwc1      $f2, 0x80($s2)
/* C5B914 802411D4 468010A0 */  cvt.s.w   $f2, $f2
/* C5B918 802411D8 460010A1 */  cvt.d.s   $f2, $f2
/* C5B91C 802411DC C6400084 */  lwc1      $f0, 0x84($s2)
/* C5B920 802411E0 46800020 */  cvt.s.w   $f0, $f0
/* C5B924 802411E4 46000021 */  cvt.d.s   $f0, $f0
/* C5B928 802411E8 3C014059 */  lui       $at, 0x4059
/* C5B92C 802411EC 44812800 */  mtc1      $at, $f5
/* C5B930 802411F0 44802000 */  mtc1      $zero, $f4
/* C5B934 802411F4 8E4200CC */  lw        $v0, 0xcc($s2)
/* C5B938 802411F8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* C5B93C 802411FC C62E0040 */  lwc1      $f14, 0x40($s1)
/* C5B940 80241200 46241083 */  div.d     $f2, $f2, $f4
/* C5B944 80241204 462010A0 */  cvt.s.d   $f2, $f2
/* C5B948 80241208 46240003 */  div.d     $f0, $f0, $f4
/* C5B94C 8024120C 8C420020 */  lw        $v0, 0x20($v0)
/* C5B950 80241210 46200020 */  cvt.s.d   $f0, $f0
/* C5B954 80241214 E622001C */  swc1      $f2, 0x1c($s1)
/* C5B958 80241218 E6200014 */  swc1      $f0, 0x14($s1)
/* C5B95C 8024121C AE220028 */  sw        $v0, 0x28($s1)
/* C5B960 80241220 C6000018 */  lwc1      $f0, 0x18($s0)
/* C5B964 80241224 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5B968 80241228 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5B96C 8024122C E6200018 */  swc1      $f0, 0x18($s1)
/* C5B970 80241230 8C460028 */  lw        $a2, 0x28($v0)
/* C5B974 80241234 0C00A720 */  jal       atan2
/* C5B978 80241238 8C470030 */   lw       $a3, 0x30($v0)
/* C5B97C 8024123C E620000C */  swc1      $f0, 0xc($s1)
/* C5B980 80241240 8E420018 */  lw        $v0, 0x18($s2)
/* C5B984 80241244 AE400074 */  sw        $zero, 0x74($s2)
/* C5B988 80241248 9442002A */  lhu       $v0, 0x2a($v0)
/* C5B98C 8024124C 30420002 */  andi      $v0, $v0, 2
/* C5B990 80241250 10400005 */  beqz      $v0, .L80241268
/* C5B994 80241254 24020003 */   addiu    $v0, $zero, 3
/* C5B998 80241258 A622008E */  sh        $v0, 0x8e($s1)
/* C5B99C 8024125C 2402000D */  addiu     $v0, $zero, 0xd
/* C5B9A0 80241260 080904AE */  j         .L802412B8
/* C5B9A4 80241264 AE620070 */   sw       $v0, 0x70($s3)
.L80241268:
/* C5B9A8 80241268 24030001 */  addiu     $v1, $zero, 1
/* C5B9AC 8024126C 2402000E */  addiu     $v0, $zero, 0xe
/* C5B9B0 80241270 A623008E */  sh        $v1, 0x8e($s1)
/* C5B9B4 80241274 AE620070 */  sw        $v0, 0x70($s3)
/* C5B9B8 80241278 C6200038 */  lwc1      $f0, 0x38($s1)
/* C5B9BC 8024127C 4600018D */  trunc.w.s $f6, $f0
/* C5B9C0 80241280 44023000 */  mfc1      $v0, $f6
/* C5B9C4 80241284 00000000 */  nop
/* C5B9C8 80241288 A6420010 */  sh        $v0, 0x10($s2)
/* C5B9CC 8024128C C620003C */  lwc1      $f0, 0x3c($s1)
/* C5B9D0 80241290 4600018D */  trunc.w.s $f6, $f0
/* C5B9D4 80241294 44023000 */  mfc1      $v0, $f6
/* C5B9D8 80241298 00000000 */  nop
/* C5B9DC 8024129C A6420012 */  sh        $v0, 0x12($s2)
/* C5B9E0 802412A0 C6200040 */  lwc1      $f0, 0x40($s1)
/* C5B9E4 802412A4 A2430007 */  sb        $v1, 7($s2)
/* C5B9E8 802412A8 4600018D */  trunc.w.s $f6, $f0
/* C5B9EC 802412AC 44023000 */  mfc1      $v0, $f6
/* C5B9F0 802412B0 00000000 */  nop
/* C5B9F4 802412B4 A6420014 */  sh        $v0, 0x14($s2)
.L802412B8:
/* C5B9F8 802412B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* C5B9FC 802412BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* C5BA00 802412C0 8FB20018 */  lw        $s2, 0x18($sp)
/* C5BA04 802412C4 8FB10014 */  lw        $s1, 0x14($sp)
/* C5BA08 802412C8 8FB00010 */  lw        $s0, 0x10($sp)
/* C5BA0C 802412CC 03E00008 */  jr        $ra
/* C5BA10 802412D0 27BD0028 */   addiu    $sp, $sp, 0x28
