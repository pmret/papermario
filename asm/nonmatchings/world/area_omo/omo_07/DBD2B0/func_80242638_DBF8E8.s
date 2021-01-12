.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242638_DBF8E8
/* DBF8E8 80242638 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DBF8EC 8024263C AFB3001C */  sw        $s3, 0x1c($sp)
/* DBF8F0 80242640 0080982D */  daddu     $s3, $a0, $zero
/* DBF8F4 80242644 AFBF0020 */  sw        $ra, 0x20($sp)
/* DBF8F8 80242648 AFB20018 */  sw        $s2, 0x18($sp)
/* DBF8FC 8024264C AFB10014 */  sw        $s1, 0x14($sp)
/* DBF900 80242650 AFB00010 */  sw        $s0, 0x10($sp)
/* DBF904 80242654 8E720148 */  lw        $s2, 0x148($s3)
/* DBF908 80242658 86440008 */  lh        $a0, 8($s2)
/* DBF90C 8024265C 0C00EABB */  jal       get_npc_unsafe
/* DBF910 80242660 00A0802D */   daddu    $s0, $a1, $zero
/* DBF914 80242664 0040882D */  daddu     $s1, $v0, $zero
/* DBF918 80242668 C6420080 */  lwc1      $f2, 0x80($s2)
/* DBF91C 8024266C 468010A0 */  cvt.s.w   $f2, $f2
/* DBF920 80242670 460010A1 */  cvt.d.s   $f2, $f2
/* DBF924 80242674 C6400084 */  lwc1      $f0, 0x84($s2)
/* DBF928 80242678 46800020 */  cvt.s.w   $f0, $f0
/* DBF92C 8024267C 46000021 */  cvt.d.s   $f0, $f0
/* DBF930 80242680 3C014059 */  lui       $at, 0x4059
/* DBF934 80242684 44812800 */  mtc1      $at, $f5
/* DBF938 80242688 44802000 */  mtc1      $zero, $f4
/* DBF93C 8024268C 8E4200CC */  lw        $v0, 0xcc($s2)
/* DBF940 80242690 C62C0038 */  lwc1      $f12, 0x38($s1)
/* DBF944 80242694 C62E0040 */  lwc1      $f14, 0x40($s1)
/* DBF948 80242698 46241083 */  div.d     $f2, $f2, $f4
/* DBF94C 8024269C 462010A0 */  cvt.s.d   $f2, $f2
/* DBF950 802426A0 46240003 */  div.d     $f0, $f0, $f4
/* DBF954 802426A4 8C420020 */  lw        $v0, 0x20($v0)
/* DBF958 802426A8 46200020 */  cvt.s.d   $f0, $f0
/* DBF95C 802426AC E622001C */  swc1      $f2, 0x1c($s1)
/* DBF960 802426B0 E6200014 */  swc1      $f0, 0x14($s1)
/* DBF964 802426B4 AE220028 */  sw        $v0, 0x28($s1)
/* DBF968 802426B8 C6000018 */  lwc1      $f0, 0x18($s0)
/* DBF96C 802426BC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBF970 802426C0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBF974 802426C4 E6200018 */  swc1      $f0, 0x18($s1)
/* DBF978 802426C8 8C460028 */  lw        $a2, 0x28($v0)
/* DBF97C 802426CC 0C00A720 */  jal       atan2
/* DBF980 802426D0 8C470030 */   lw       $a3, 0x30($v0)
/* DBF984 802426D4 E620000C */  swc1      $f0, 0xc($s1)
/* DBF988 802426D8 8E420018 */  lw        $v0, 0x18($s2)
/* DBF98C 802426DC AE400074 */  sw        $zero, 0x74($s2)
/* DBF990 802426E0 9442002A */  lhu       $v0, 0x2a($v0)
/* DBF994 802426E4 30420002 */  andi      $v0, $v0, 2
/* DBF998 802426E8 10400005 */  beqz      $v0, .L80242700
/* DBF99C 802426EC 24020003 */   addiu    $v0, $zero, 3
/* DBF9A0 802426F0 A622008E */  sh        $v0, 0x8e($s1)
/* DBF9A4 802426F4 2402000D */  addiu     $v0, $zero, 0xd
/* DBF9A8 802426F8 080909D4 */  j         .L80242750
/* DBF9AC 802426FC AE620070 */   sw       $v0, 0x70($s3)
.L80242700:
/* DBF9B0 80242700 24030001 */  addiu     $v1, $zero, 1
/* DBF9B4 80242704 2402000E */  addiu     $v0, $zero, 0xe
/* DBF9B8 80242708 A623008E */  sh        $v1, 0x8e($s1)
/* DBF9BC 8024270C AE620070 */  sw        $v0, 0x70($s3)
/* DBF9C0 80242710 C6200038 */  lwc1      $f0, 0x38($s1)
/* DBF9C4 80242714 4600018D */  trunc.w.s $f6, $f0
/* DBF9C8 80242718 44023000 */  mfc1      $v0, $f6
/* DBF9CC 8024271C 00000000 */  nop
/* DBF9D0 80242720 A6420010 */  sh        $v0, 0x10($s2)
/* DBF9D4 80242724 C620003C */  lwc1      $f0, 0x3c($s1)
/* DBF9D8 80242728 4600018D */  trunc.w.s $f6, $f0
/* DBF9DC 8024272C 44023000 */  mfc1      $v0, $f6
/* DBF9E0 80242730 00000000 */  nop
/* DBF9E4 80242734 A6420012 */  sh        $v0, 0x12($s2)
/* DBF9E8 80242738 C6200040 */  lwc1      $f0, 0x40($s1)
/* DBF9EC 8024273C A2430007 */  sb        $v1, 7($s2)
/* DBF9F0 80242740 4600018D */  trunc.w.s $f6, $f0
/* DBF9F4 80242744 44023000 */  mfc1      $v0, $f6
/* DBF9F8 80242748 00000000 */  nop
/* DBF9FC 8024274C A6420014 */  sh        $v0, 0x14($s2)
.L80242750:
/* DBFA00 80242750 8FBF0020 */  lw        $ra, 0x20($sp)
/* DBFA04 80242754 8FB3001C */  lw        $s3, 0x1c($sp)
/* DBFA08 80242758 8FB20018 */  lw        $s2, 0x18($sp)
/* DBFA0C 8024275C 8FB10014 */  lw        $s1, 0x14($sp)
/* DBFA10 80242760 8FB00010 */  lw        $s0, 0x10($sp)
/* DBFA14 80242764 03E00008 */  jr        $ra
/* DBFA18 80242768 27BD0028 */   addiu    $sp, $sp, 0x28
