.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417D0_CCCAE0
/* CCCAE0 802417D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CCCAE4 802417D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* CCCAE8 802417D8 0080982D */  daddu     $s3, $a0, $zero
/* CCCAEC 802417DC AFBF0020 */  sw        $ra, 0x20($sp)
/* CCCAF0 802417E0 AFB20018 */  sw        $s2, 0x18($sp)
/* CCCAF4 802417E4 AFB10014 */  sw        $s1, 0x14($sp)
/* CCCAF8 802417E8 AFB00010 */  sw        $s0, 0x10($sp)
/* CCCAFC 802417EC 8E720148 */  lw        $s2, 0x148($s3)
/* CCCB00 802417F0 86440008 */  lh        $a0, 8($s2)
/* CCCB04 802417F4 0C00EABB */  jal       get_npc_unsafe
/* CCCB08 802417F8 00A0802D */   daddu    $s0, $a1, $zero
/* CCCB0C 802417FC 0040882D */  daddu     $s1, $v0, $zero
/* CCCB10 80241800 C6420080 */  lwc1      $f2, 0x80($s2)
/* CCCB14 80241804 468010A0 */  cvt.s.w   $f2, $f2
/* CCCB18 80241808 460010A1 */  cvt.d.s   $f2, $f2
/* CCCB1C 8024180C C6400084 */  lwc1      $f0, 0x84($s2)
/* CCCB20 80241810 46800020 */  cvt.s.w   $f0, $f0
/* CCCB24 80241814 46000021 */  cvt.d.s   $f0, $f0
/* CCCB28 80241818 3C014059 */  lui       $at, 0x4059
/* CCCB2C 8024181C 44812800 */  mtc1      $at, $f5
/* CCCB30 80241820 44802000 */  mtc1      $zero, $f4
/* CCCB34 80241824 8E4200CC */  lw        $v0, 0xcc($s2)
/* CCCB38 80241828 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CCCB3C 8024182C C62E0040 */  lwc1      $f14, 0x40($s1)
/* CCCB40 80241830 46241083 */  div.d     $f2, $f2, $f4
/* CCCB44 80241834 462010A0 */  cvt.s.d   $f2, $f2
/* CCCB48 80241838 46240003 */  div.d     $f0, $f0, $f4
/* CCCB4C 8024183C 8C420020 */  lw        $v0, 0x20($v0)
/* CCCB50 80241840 46200020 */  cvt.s.d   $f0, $f0
/* CCCB54 80241844 E622001C */  swc1      $f2, 0x1c($s1)
/* CCCB58 80241848 E6200014 */  swc1      $f0, 0x14($s1)
/* CCCB5C 8024184C AE220028 */  sw        $v0, 0x28($s1)
/* CCCB60 80241850 C6000018 */  lwc1      $f0, 0x18($s0)
/* CCCB64 80241854 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CCCB68 80241858 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CCCB6C 8024185C E6200018 */  swc1      $f0, 0x18($s1)
/* CCCB70 80241860 8C460028 */  lw        $a2, 0x28($v0)
/* CCCB74 80241864 0C00A720 */  jal       atan2
/* CCCB78 80241868 8C470030 */   lw       $a3, 0x30($v0)
/* CCCB7C 8024186C E620000C */  swc1      $f0, 0xc($s1)
/* CCCB80 80241870 8E420018 */  lw        $v0, 0x18($s2)
/* CCCB84 80241874 AE400074 */  sw        $zero, 0x74($s2)
/* CCCB88 80241878 9442002A */  lhu       $v0, 0x2a($v0)
/* CCCB8C 8024187C 30420002 */  andi      $v0, $v0, 2
/* CCCB90 80241880 10400005 */  beqz      $v0, .L80241898
/* CCCB94 80241884 24020003 */   addiu    $v0, $zero, 3
/* CCCB98 80241888 A622008E */  sh        $v0, 0x8e($s1)
/* CCCB9C 8024188C 2402000D */  addiu     $v0, $zero, 0xd
/* CCCBA0 80241890 0809063A */  j         .L802418E8
/* CCCBA4 80241894 AE620070 */   sw       $v0, 0x70($s3)
.L80241898:
/* CCCBA8 80241898 24030001 */  addiu     $v1, $zero, 1
/* CCCBAC 8024189C 2402000E */  addiu     $v0, $zero, 0xe
/* CCCBB0 802418A0 A623008E */  sh        $v1, 0x8e($s1)
/* CCCBB4 802418A4 AE620070 */  sw        $v0, 0x70($s3)
/* CCCBB8 802418A8 C6200038 */  lwc1      $f0, 0x38($s1)
/* CCCBBC 802418AC 4600018D */  trunc.w.s $f6, $f0
/* CCCBC0 802418B0 44023000 */  mfc1      $v0, $f6
/* CCCBC4 802418B4 00000000 */  nop
/* CCCBC8 802418B8 A6420010 */  sh        $v0, 0x10($s2)
/* CCCBCC 802418BC C620003C */  lwc1      $f0, 0x3c($s1)
/* CCCBD0 802418C0 4600018D */  trunc.w.s $f6, $f0
/* CCCBD4 802418C4 44023000 */  mfc1      $v0, $f6
/* CCCBD8 802418C8 00000000 */  nop
/* CCCBDC 802418CC A6420012 */  sh        $v0, 0x12($s2)
/* CCCBE0 802418D0 C6200040 */  lwc1      $f0, 0x40($s1)
/* CCCBE4 802418D4 A2430007 */  sb        $v1, 7($s2)
/* CCCBE8 802418D8 4600018D */  trunc.w.s $f6, $f0
/* CCCBEC 802418DC 44023000 */  mfc1      $v0, $f6
/* CCCBF0 802418E0 00000000 */  nop
/* CCCBF4 802418E4 A6420014 */  sh        $v0, 0x14($s2)
.L802418E8:
/* CCCBF8 802418E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* CCCBFC 802418EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* CCCC00 802418F0 8FB20018 */  lw        $s2, 0x18($sp)
/* CCCC04 802418F4 8FB10014 */  lw        $s1, 0x14($sp)
/* CCCC08 802418F8 8FB00010 */  lw        $s0, 0x10($sp)
/* CCCC0C 802418FC 03E00008 */  jr        $ra
/* CCCC10 80241900 27BD0028 */   addiu    $sp, $sp, 0x28
