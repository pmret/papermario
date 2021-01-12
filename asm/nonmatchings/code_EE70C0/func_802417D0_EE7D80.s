.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417D0_EE7D80
/* EE7D80 802417D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EE7D84 802417D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* EE7D88 802417D8 0080982D */  daddu     $s3, $a0, $zero
/* EE7D8C 802417DC AFBF0020 */  sw        $ra, 0x20($sp)
/* EE7D90 802417E0 AFB20018 */  sw        $s2, 0x18($sp)
/* EE7D94 802417E4 AFB10014 */  sw        $s1, 0x14($sp)
/* EE7D98 802417E8 AFB00010 */  sw        $s0, 0x10($sp)
/* EE7D9C 802417EC 8E720148 */  lw        $s2, 0x148($s3)
/* EE7DA0 802417F0 86440008 */  lh        $a0, 8($s2)
/* EE7DA4 802417F4 0C00F92F */  jal       func_8003E4BC
/* EE7DA8 802417F8 00A0802D */   daddu    $s0, $a1, $zero
/* EE7DAC 802417FC 0040882D */  daddu     $s1, $v0, $zero
/* EE7DB0 80241800 C6420080 */  lwc1      $f2, 0x80($s2)
/* EE7DB4 80241804 468010A0 */  cvt.s.w   $f2, $f2
/* EE7DB8 80241808 460010A1 */  cvt.d.s   $f2, $f2
/* EE7DBC 8024180C C6400084 */  lwc1      $f0, 0x84($s2)
/* EE7DC0 80241810 46800020 */  cvt.s.w   $f0, $f0
/* EE7DC4 80241814 46000021 */  cvt.d.s   $f0, $f0
/* EE7DC8 80241818 3C014059 */  lui       $at, 0x4059
/* EE7DCC 8024181C 44812800 */  mtc1      $at, $f5
/* EE7DD0 80241820 44802000 */  mtc1      $zero, $f4
/* EE7DD4 80241824 8E4200CC */  lw        $v0, 0xcc($s2)
/* EE7DD8 80241828 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EE7DDC 8024182C C62E0040 */  lwc1      $f14, 0x40($s1)
/* EE7DE0 80241830 46241083 */  div.d     $f2, $f2, $f4
/* EE7DE4 80241834 462010A0 */  cvt.s.d   $f2, $f2
/* EE7DE8 80241838 46240003 */  div.d     $f0, $f0, $f4
/* EE7DEC 8024183C 8C420020 */  lw        $v0, 0x20($v0)
/* EE7DF0 80241840 46200020 */  cvt.s.d   $f0, $f0
/* EE7DF4 80241844 E622001C */  swc1      $f2, 0x1c($s1)
/* EE7DF8 80241848 E6200014 */  swc1      $f0, 0x14($s1)
/* EE7DFC 8024184C AE220028 */  sw        $v0, 0x28($s1)
/* EE7E00 80241850 C6000018 */  lwc1      $f0, 0x18($s0)
/* EE7E04 80241854 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EE7E08 80241858 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EE7E0C 8024185C E6200018 */  swc1      $f0, 0x18($s1)
/* EE7E10 80241860 8C460028 */  lw        $a2, 0x28($v0)
/* EE7E14 80241864 0C00ABDC */  jal       fio_validate_header_checksums
/* EE7E18 80241868 8C470030 */   lw       $a3, 0x30($v0)
/* EE7E1C 8024186C E620000C */  swc1      $f0, 0xc($s1)
/* EE7E20 80241870 8E420018 */  lw        $v0, 0x18($s2)
/* EE7E24 80241874 AE400074 */  sw        $zero, 0x74($s2)
/* EE7E28 80241878 9442002A */  lhu       $v0, 0x2a($v0)
/* EE7E2C 8024187C 30420002 */  andi      $v0, $v0, 2
/* EE7E30 80241880 10400005 */  beqz      $v0, .L80241898
/* EE7E34 80241884 24020003 */   addiu    $v0, $zero, 3
/* EE7E38 80241888 A622008E */  sh        $v0, 0x8e($s1)
/* EE7E3C 8024188C 2402000D */  addiu     $v0, $zero, 0xd
/* EE7E40 80241890 0809063A */  j         .L802418E8
/* EE7E44 80241894 AE620070 */   sw       $v0, 0x70($s3)
.L80241898:
/* EE7E48 80241898 24030001 */  addiu     $v1, $zero, 1
/* EE7E4C 8024189C 2402000E */  addiu     $v0, $zero, 0xe
/* EE7E50 802418A0 A623008E */  sh        $v1, 0x8e($s1)
/* EE7E54 802418A4 AE620070 */  sw        $v0, 0x70($s3)
/* EE7E58 802418A8 C6200038 */  lwc1      $f0, 0x38($s1)
/* EE7E5C 802418AC 4600018D */  trunc.w.s $f6, $f0
/* EE7E60 802418B0 44023000 */  mfc1      $v0, $f6
/* EE7E64 802418B4 00000000 */  nop       
/* EE7E68 802418B8 A6420010 */  sh        $v0, 0x10($s2)
/* EE7E6C 802418BC C620003C */  lwc1      $f0, 0x3c($s1)
/* EE7E70 802418C0 4600018D */  trunc.w.s $f6, $f0
/* EE7E74 802418C4 44023000 */  mfc1      $v0, $f6
/* EE7E78 802418C8 00000000 */  nop       
/* EE7E7C 802418CC A6420012 */  sh        $v0, 0x12($s2)
/* EE7E80 802418D0 C6200040 */  lwc1      $f0, 0x40($s1)
/* EE7E84 802418D4 A2430007 */  sb        $v1, 7($s2)
/* EE7E88 802418D8 4600018D */  trunc.w.s $f6, $f0
/* EE7E8C 802418DC 44023000 */  mfc1      $v0, $f6
/* EE7E90 802418E0 00000000 */  nop       
/* EE7E94 802418E4 A6420014 */  sh        $v0, 0x14($s2)
.L802418E8:
/* EE7E98 802418E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* EE7E9C 802418EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* EE7EA0 802418F0 8FB20018 */  lw        $s2, 0x18($sp)
/* EE7EA4 802418F4 8FB10014 */  lw        $s1, 0x14($sp)
/* EE7EA8 802418F8 8FB00010 */  lw        $s0, 0x10($sp)
/* EE7EAC 802418FC 03E00008 */  jr        $ra
/* EE7EB0 80241900 27BD0028 */   addiu    $sp, $sp, 0x28
