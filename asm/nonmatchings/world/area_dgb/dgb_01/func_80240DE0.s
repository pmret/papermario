.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE0
/* BFE660 80240DE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BFE664 80240DE4 AFB3001C */  sw        $s3, 0x1c($sp)
/* BFE668 80240DE8 0080982D */  daddu     $s3, $a0, $zero
/* BFE66C 80240DEC AFBF0020 */  sw        $ra, 0x20($sp)
/* BFE670 80240DF0 AFB20018 */  sw        $s2, 0x18($sp)
/* BFE674 80240DF4 AFB10014 */  sw        $s1, 0x14($sp)
/* BFE678 80240DF8 AFB00010 */  sw        $s0, 0x10($sp)
/* BFE67C 80240DFC 8E720148 */  lw        $s2, 0x148($s3)
/* BFE680 80240E00 86440008 */  lh        $a0, 8($s2)
/* BFE684 80240E04 0C00EABB */  jal       get_npc_unsafe
/* BFE688 80240E08 00A0802D */   daddu    $s0, $a1, $zero
/* BFE68C 80240E0C 0040882D */  daddu     $s1, $v0, $zero
/* BFE690 80240E10 C6420080 */  lwc1      $f2, 0x80($s2)
/* BFE694 80240E14 468010A0 */  cvt.s.w   $f2, $f2
/* BFE698 80240E18 460010A1 */  cvt.d.s   $f2, $f2
/* BFE69C 80240E1C C6400084 */  lwc1      $f0, 0x84($s2)
/* BFE6A0 80240E20 46800020 */  cvt.s.w   $f0, $f0
/* BFE6A4 80240E24 46000021 */  cvt.d.s   $f0, $f0
/* BFE6A8 80240E28 3C014059 */  lui       $at, 0x4059
/* BFE6AC 80240E2C 44812800 */  mtc1      $at, $f5
/* BFE6B0 80240E30 44802000 */  mtc1      $zero, $f4
/* BFE6B4 80240E34 8E4200CC */  lw        $v0, 0xcc($s2)
/* BFE6B8 80240E38 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BFE6BC 80240E3C C62E0040 */  lwc1      $f14, 0x40($s1)
/* BFE6C0 80240E40 46241083 */  div.d     $f2, $f2, $f4
/* BFE6C4 80240E44 462010A0 */  cvt.s.d   $f2, $f2
/* BFE6C8 80240E48 46240003 */  div.d     $f0, $f0, $f4
/* BFE6CC 80240E4C 8C420020 */  lw        $v0, 0x20($v0)
/* BFE6D0 80240E50 46200020 */  cvt.s.d   $f0, $f0
/* BFE6D4 80240E54 E622001C */  swc1      $f2, 0x1c($s1)
/* BFE6D8 80240E58 E6200014 */  swc1      $f0, 0x14($s1)
/* BFE6DC 80240E5C AE220028 */  sw        $v0, 0x28($s1)
/* BFE6E0 80240E60 C6000018 */  lwc1      $f0, 0x18($s0)
/* BFE6E4 80240E64 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFE6E8 80240E68 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFE6EC 80240E6C E6200018 */  swc1      $f0, 0x18($s1)
/* BFE6F0 80240E70 8C460028 */  lw        $a2, 0x28($v0)
/* BFE6F4 80240E74 0C00A720 */  jal       atan2
/* BFE6F8 80240E78 8C470030 */   lw       $a3, 0x30($v0)
/* BFE6FC 80240E7C E620000C */  swc1      $f0, 0xc($s1)
/* BFE700 80240E80 8E420018 */  lw        $v0, 0x18($s2)
/* BFE704 80240E84 AE400074 */  sw        $zero, 0x74($s2)
/* BFE708 80240E88 9442002A */  lhu       $v0, 0x2a($v0)
/* BFE70C 80240E8C 30420002 */  andi      $v0, $v0, 2
/* BFE710 80240E90 10400005 */  beqz      $v0, .L80240EA8
/* BFE714 80240E94 24020003 */   addiu    $v0, $zero, 3
/* BFE718 80240E98 A622008E */  sh        $v0, 0x8e($s1)
/* BFE71C 80240E9C 2402000D */  addiu     $v0, $zero, 0xd
/* BFE720 80240EA0 080903BE */  j         .L80240EF8
/* BFE724 80240EA4 AE620070 */   sw       $v0, 0x70($s3)
.L80240EA8:
/* BFE728 80240EA8 24030001 */  addiu     $v1, $zero, 1
/* BFE72C 80240EAC 2402000E */  addiu     $v0, $zero, 0xe
/* BFE730 80240EB0 A623008E */  sh        $v1, 0x8e($s1)
/* BFE734 80240EB4 AE620070 */  sw        $v0, 0x70($s3)
/* BFE738 80240EB8 C6200038 */  lwc1      $f0, 0x38($s1)
/* BFE73C 80240EBC 4600018D */  trunc.w.s $f6, $f0
/* BFE740 80240EC0 44023000 */  mfc1      $v0, $f6
/* BFE744 80240EC4 00000000 */  nop       
/* BFE748 80240EC8 A6420010 */  sh        $v0, 0x10($s2)
/* BFE74C 80240ECC C620003C */  lwc1      $f0, 0x3c($s1)
/* BFE750 80240ED0 4600018D */  trunc.w.s $f6, $f0
/* BFE754 80240ED4 44023000 */  mfc1      $v0, $f6
/* BFE758 80240ED8 00000000 */  nop       
/* BFE75C 80240EDC A6420012 */  sh        $v0, 0x12($s2)
/* BFE760 80240EE0 C6200040 */  lwc1      $f0, 0x40($s1)
/* BFE764 80240EE4 A2430007 */  sb        $v1, 7($s2)
/* BFE768 80240EE8 4600018D */  trunc.w.s $f6, $f0
/* BFE76C 80240EEC 44023000 */  mfc1      $v0, $f6
/* BFE770 80240EF0 00000000 */  nop       
/* BFE774 80240EF4 A6420014 */  sh        $v0, 0x14($s2)
.L80240EF8:
/* BFE778 80240EF8 8FBF0020 */  lw        $ra, 0x20($sp)
/* BFE77C 80240EFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* BFE780 80240F00 8FB20018 */  lw        $s2, 0x18($sp)
/* BFE784 80240F04 8FB10014 */  lw        $s1, 0x14($sp)
/* BFE788 80240F08 8FB00010 */  lw        $s0, 0x10($sp)
/* BFE78C 80240F0C 03E00008 */  jr        $ra
/* BFE790 80240F10 27BD0028 */   addiu    $sp, $sp, 0x28
