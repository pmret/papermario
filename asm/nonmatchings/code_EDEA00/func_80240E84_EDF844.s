.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E84_EDF844
/* EDF844 80240E84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EDF848 80240E88 AFB3001C */  sw        $s3, 0x1c($sp)
/* EDF84C 80240E8C 0080982D */  daddu     $s3, $a0, $zero
/* EDF850 80240E90 AFBF0020 */  sw        $ra, 0x20($sp)
/* EDF854 80240E94 AFB20018 */  sw        $s2, 0x18($sp)
/* EDF858 80240E98 AFB10014 */  sw        $s1, 0x14($sp)
/* EDF85C 80240E9C AFB00010 */  sw        $s0, 0x10($sp)
/* EDF860 80240EA0 8E720148 */  lw        $s2, 0x148($s3)
/* EDF864 80240EA4 86440008 */  lh        $a0, 8($s2)
/* EDF868 80240EA8 0C00F92F */  jal       func_8003E4BC
/* EDF86C 80240EAC 00A0802D */   daddu    $s0, $a1, $zero
/* EDF870 80240EB0 0040882D */  daddu     $s1, $v0, $zero
/* EDF874 80240EB4 C6420080 */  lwc1      $f2, 0x80($s2)
/* EDF878 80240EB8 468010A0 */  cvt.s.w   $f2, $f2
/* EDF87C 80240EBC 460010A1 */  cvt.d.s   $f2, $f2
/* EDF880 80240EC0 C6400084 */  lwc1      $f0, 0x84($s2)
/* EDF884 80240EC4 46800020 */  cvt.s.w   $f0, $f0
/* EDF888 80240EC8 46000021 */  cvt.d.s   $f0, $f0
/* EDF88C 80240ECC 3C014059 */  lui       $at, 0x4059
/* EDF890 80240ED0 44812800 */  mtc1      $at, $f5
/* EDF894 80240ED4 44802000 */  mtc1      $zero, $f4
/* EDF898 80240ED8 8E4200CC */  lw        $v0, 0xcc($s2)
/* EDF89C 80240EDC C62C0038 */  lwc1      $f12, 0x38($s1)
/* EDF8A0 80240EE0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* EDF8A4 80240EE4 46241083 */  div.d     $f2, $f2, $f4
/* EDF8A8 80240EE8 462010A0 */  cvt.s.d   $f2, $f2
/* EDF8AC 80240EEC 46240003 */  div.d     $f0, $f0, $f4
/* EDF8B0 80240EF0 8C420020 */  lw        $v0, 0x20($v0)
/* EDF8B4 80240EF4 46200020 */  cvt.s.d   $f0, $f0
/* EDF8B8 80240EF8 E622001C */  swc1      $f2, 0x1c($s1)
/* EDF8BC 80240EFC E6200014 */  swc1      $f0, 0x14($s1)
/* EDF8C0 80240F00 AE220028 */  sw        $v0, 0x28($s1)
/* EDF8C4 80240F04 C6000018 */  lwc1      $f0, 0x18($s0)
/* EDF8C8 80240F08 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EDF8CC 80240F0C 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EDF8D0 80240F10 E6200018 */  swc1      $f0, 0x18($s1)
/* EDF8D4 80240F14 8C460028 */  lw        $a2, 0x28($v0)
/* EDF8D8 80240F18 0C00ABDC */  jal       fio_validate_header_checksums
/* EDF8DC 80240F1C 8C470030 */   lw       $a3, 0x30($v0)
/* EDF8E0 80240F20 E620000C */  swc1      $f0, 0xc($s1)
/* EDF8E4 80240F24 8E420018 */  lw        $v0, 0x18($s2)
/* EDF8E8 80240F28 AE400074 */  sw        $zero, 0x74($s2)
/* EDF8EC 80240F2C 9442002A */  lhu       $v0, 0x2a($v0)
/* EDF8F0 80240F30 30420002 */  andi      $v0, $v0, 2
/* EDF8F4 80240F34 10400005 */  beqz      $v0, .L80240F4C
/* EDF8F8 80240F38 24020003 */   addiu    $v0, $zero, 3
/* EDF8FC 80240F3C A622008E */  sh        $v0, 0x8e($s1)
/* EDF900 80240F40 2402000D */  addiu     $v0, $zero, 0xd
/* EDF904 80240F44 080903E7 */  j         .L80240F9C
/* EDF908 80240F48 AE620070 */   sw       $v0, 0x70($s3)
.L80240F4C:
/* EDF90C 80240F4C 24030001 */  addiu     $v1, $zero, 1
/* EDF910 80240F50 2402000E */  addiu     $v0, $zero, 0xe
/* EDF914 80240F54 A623008E */  sh        $v1, 0x8e($s1)
/* EDF918 80240F58 AE620070 */  sw        $v0, 0x70($s3)
/* EDF91C 80240F5C C6200038 */  lwc1      $f0, 0x38($s1)
/* EDF920 80240F60 4600018D */  trunc.w.s $f6, $f0
/* EDF924 80240F64 44023000 */  mfc1      $v0, $f6
/* EDF928 80240F68 00000000 */  nop       
/* EDF92C 80240F6C A6420010 */  sh        $v0, 0x10($s2)
/* EDF930 80240F70 C620003C */  lwc1      $f0, 0x3c($s1)
/* EDF934 80240F74 4600018D */  trunc.w.s $f6, $f0
/* EDF938 80240F78 44023000 */  mfc1      $v0, $f6
/* EDF93C 80240F7C 00000000 */  nop       
/* EDF940 80240F80 A6420012 */  sh        $v0, 0x12($s2)
/* EDF944 80240F84 C6200040 */  lwc1      $f0, 0x40($s1)
/* EDF948 80240F88 A2430007 */  sb        $v1, 7($s2)
/* EDF94C 80240F8C 4600018D */  trunc.w.s $f6, $f0
/* EDF950 80240F90 44023000 */  mfc1      $v0, $f6
/* EDF954 80240F94 00000000 */  nop       
/* EDF958 80240F98 A6420014 */  sh        $v0, 0x14($s2)
.L80240F9C:
/* EDF95C 80240F9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* EDF960 80240FA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* EDF964 80240FA4 8FB20018 */  lw        $s2, 0x18($sp)
/* EDF968 80240FA8 8FB10014 */  lw        $s1, 0x14($sp)
/* EDF96C 80240FAC 8FB00010 */  lw        $s0, 0x10($sp)
/* EDF970 80240FB0 03E00008 */  jr        $ra
/* EDF974 80240FB4 27BD0028 */   addiu    $sp, $sp, 0x28
