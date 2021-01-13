.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_ED0FD0
/* ED0FD0 80240FE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ED0FD4 80240FE4 AFB3001C */  sw        $s3, 0x1c($sp)
/* ED0FD8 80240FE8 0080982D */  daddu     $s3, $a0, $zero
/* ED0FDC 80240FEC AFBF0020 */  sw        $ra, 0x20($sp)
/* ED0FE0 80240FF0 AFB20018 */  sw        $s2, 0x18($sp)
/* ED0FE4 80240FF4 AFB10014 */  sw        $s1, 0x14($sp)
/* ED0FE8 80240FF8 AFB00010 */  sw        $s0, 0x10($sp)
/* ED0FEC 80240FFC 8E720148 */  lw        $s2, 0x148($s3)
/* ED0FF0 80241000 86440008 */  lh        $a0, 8($s2)
/* ED0FF4 80241004 0C00F92F */  jal       func_8003E4BC
/* ED0FF8 80241008 00A0802D */   daddu    $s0, $a1, $zero
/* ED0FFC 8024100C 0040882D */  daddu     $s1, $v0, $zero
/* ED1000 80241010 C6420080 */  lwc1      $f2, 0x80($s2)
/* ED1004 80241014 468010A0 */  cvt.s.w   $f2, $f2
/* ED1008 80241018 460010A1 */  cvt.d.s   $f2, $f2
/* ED100C 8024101C C6400084 */  lwc1      $f0, 0x84($s2)
/* ED1010 80241020 46800020 */  cvt.s.w   $f0, $f0
/* ED1014 80241024 46000021 */  cvt.d.s   $f0, $f0
/* ED1018 80241028 3C014059 */  lui       $at, 0x4059
/* ED101C 8024102C 44812800 */  mtc1      $at, $f5
/* ED1020 80241030 44802000 */  mtc1      $zero, $f4
/* ED1024 80241034 8E4200CC */  lw        $v0, 0xcc($s2)
/* ED1028 80241038 C62C0038 */  lwc1      $f12, 0x38($s1)
/* ED102C 8024103C C62E0040 */  lwc1      $f14, 0x40($s1)
/* ED1030 80241040 46241083 */  div.d     $f2, $f2, $f4
/* ED1034 80241044 462010A0 */  cvt.s.d   $f2, $f2
/* ED1038 80241048 46240003 */  div.d     $f0, $f0, $f4
/* ED103C 8024104C 8C420020 */  lw        $v0, 0x20($v0)
/* ED1040 80241050 46200020 */  cvt.s.d   $f0, $f0
/* ED1044 80241054 E622001C */  swc1      $f2, 0x1c($s1)
/* ED1048 80241058 E6200014 */  swc1      $f0, 0x14($s1)
/* ED104C 8024105C AE220028 */  sw        $v0, 0x28($s1)
/* ED1050 80241060 C6000018 */  lwc1      $f0, 0x18($s0)
/* ED1054 80241064 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* ED1058 80241068 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* ED105C 8024106C E6200018 */  swc1      $f0, 0x18($s1)
/* ED1060 80241070 8C460028 */  lw        $a2, 0x28($v0)
/* ED1064 80241074 0C00ABDC */  jal       fio_validate_header_checksums
/* ED1068 80241078 8C470030 */   lw       $a3, 0x30($v0)
/* ED106C 8024107C E620000C */  swc1      $f0, 0xc($s1)
/* ED1070 80241080 8E420018 */  lw        $v0, 0x18($s2)
/* ED1074 80241084 AE400074 */  sw        $zero, 0x74($s2)
/* ED1078 80241088 9442002A */  lhu       $v0, 0x2a($v0)
/* ED107C 8024108C 30420002 */  andi      $v0, $v0, 2
/* ED1080 80241090 10400005 */  beqz      $v0, .L802410A8
/* ED1084 80241094 24020003 */   addiu    $v0, $zero, 3
/* ED1088 80241098 A622008E */  sh        $v0, 0x8e($s1)
/* ED108C 8024109C 2402000D */  addiu     $v0, $zero, 0xd
/* ED1090 802410A0 0809043E */  j         .L802410F8
/* ED1094 802410A4 AE620070 */   sw       $v0, 0x70($s3)
.L802410A8:
/* ED1098 802410A8 24030001 */  addiu     $v1, $zero, 1
/* ED109C 802410AC 2402000E */  addiu     $v0, $zero, 0xe
/* ED10A0 802410B0 A623008E */  sh        $v1, 0x8e($s1)
/* ED10A4 802410B4 AE620070 */  sw        $v0, 0x70($s3)
/* ED10A8 802410B8 C6200038 */  lwc1      $f0, 0x38($s1)
/* ED10AC 802410BC 4600018D */  trunc.w.s $f6, $f0
/* ED10B0 802410C0 44023000 */  mfc1      $v0, $f6
/* ED10B4 802410C4 00000000 */  nop
/* ED10B8 802410C8 A6420010 */  sh        $v0, 0x10($s2)
/* ED10BC 802410CC C620003C */  lwc1      $f0, 0x3c($s1)
/* ED10C0 802410D0 4600018D */  trunc.w.s $f6, $f0
/* ED10C4 802410D4 44023000 */  mfc1      $v0, $f6
/* ED10C8 802410D8 00000000 */  nop
/* ED10CC 802410DC A6420012 */  sh        $v0, 0x12($s2)
/* ED10D0 802410E0 C6200040 */  lwc1      $f0, 0x40($s1)
/* ED10D4 802410E4 A2430007 */  sb        $v1, 7($s2)
/* ED10D8 802410E8 4600018D */  trunc.w.s $f6, $f0
/* ED10DC 802410EC 44023000 */  mfc1      $v0, $f6
/* ED10E0 802410F0 00000000 */  nop
/* ED10E4 802410F4 A6420014 */  sh        $v0, 0x14($s2)
.L802410F8:
/* ED10E8 802410F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* ED10EC 802410FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* ED10F0 80241100 8FB20018 */  lw        $s2, 0x18($sp)
/* ED10F4 80241104 8FB10014 */  lw        $s1, 0x14($sp)
/* ED10F8 80241108 8FB00010 */  lw        $s0, 0x10($sp)
/* ED10FC 8024110C 03E00008 */  jr        $ra
/* ED1100 80241110 27BD0028 */   addiu    $sp, $sp, 0x28
