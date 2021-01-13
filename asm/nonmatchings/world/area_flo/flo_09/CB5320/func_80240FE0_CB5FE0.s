.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_CB5FE0
/* CB5FE0 80240FE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CB5FE4 80240FE4 AFB3001C */  sw        $s3, 0x1c($sp)
/* CB5FE8 80240FE8 0080982D */  daddu     $s3, $a0, $zero
/* CB5FEC 80240FEC AFBF0020 */  sw        $ra, 0x20($sp)
/* CB5FF0 80240FF0 AFB20018 */  sw        $s2, 0x18($sp)
/* CB5FF4 80240FF4 AFB10014 */  sw        $s1, 0x14($sp)
/* CB5FF8 80240FF8 AFB00010 */  sw        $s0, 0x10($sp)
/* CB5FFC 80240FFC 8E720148 */  lw        $s2, 0x148($s3)
/* CB6000 80241000 86440008 */  lh        $a0, 8($s2)
/* CB6004 80241004 0C00EABB */  jal       get_npc_unsafe
/* CB6008 80241008 00A0802D */   daddu    $s0, $a1, $zero
/* CB600C 8024100C 0040882D */  daddu     $s1, $v0, $zero
/* CB6010 80241010 C6420080 */  lwc1      $f2, 0x80($s2)
/* CB6014 80241014 468010A0 */  cvt.s.w   $f2, $f2
/* CB6018 80241018 460010A1 */  cvt.d.s   $f2, $f2
/* CB601C 8024101C C6400084 */  lwc1      $f0, 0x84($s2)
/* CB6020 80241020 46800020 */  cvt.s.w   $f0, $f0
/* CB6024 80241024 46000021 */  cvt.d.s   $f0, $f0
/* CB6028 80241028 3C014059 */  lui       $at, 0x4059
/* CB602C 8024102C 44812800 */  mtc1      $at, $f5
/* CB6030 80241030 44802000 */  mtc1      $zero, $f4
/* CB6034 80241034 8E4200CC */  lw        $v0, 0xcc($s2)
/* CB6038 80241038 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CB603C 8024103C C62E0040 */  lwc1      $f14, 0x40($s1)
/* CB6040 80241040 46241083 */  div.d     $f2, $f2, $f4
/* CB6044 80241044 462010A0 */  cvt.s.d   $f2, $f2
/* CB6048 80241048 46240003 */  div.d     $f0, $f0, $f4
/* CB604C 8024104C 8C420020 */  lw        $v0, 0x20($v0)
/* CB6050 80241050 46200020 */  cvt.s.d   $f0, $f0
/* CB6054 80241054 E622001C */  swc1      $f2, 0x1c($s1)
/* CB6058 80241058 E6200014 */  swc1      $f0, 0x14($s1)
/* CB605C 8024105C AE220028 */  sw        $v0, 0x28($s1)
/* CB6060 80241060 C6000018 */  lwc1      $f0, 0x18($s0)
/* CB6064 80241064 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CB6068 80241068 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CB606C 8024106C E6200018 */  swc1      $f0, 0x18($s1)
/* CB6070 80241070 8C460028 */  lw        $a2, 0x28($v0)
/* CB6074 80241074 0C00A720 */  jal       atan2
/* CB6078 80241078 8C470030 */   lw       $a3, 0x30($v0)
/* CB607C 8024107C E620000C */  swc1      $f0, 0xc($s1)
/* CB6080 80241080 8E420018 */  lw        $v0, 0x18($s2)
/* CB6084 80241084 AE400074 */  sw        $zero, 0x74($s2)
/* CB6088 80241088 9442002A */  lhu       $v0, 0x2a($v0)
/* CB608C 8024108C 30420002 */  andi      $v0, $v0, 2
/* CB6090 80241090 10400005 */  beqz      $v0, .L802410A8
/* CB6094 80241094 24020003 */   addiu    $v0, $zero, 3
/* CB6098 80241098 A622008E */  sh        $v0, 0x8e($s1)
/* CB609C 8024109C 2402000D */  addiu     $v0, $zero, 0xd
/* CB60A0 802410A0 0809043E */  j         .L802410F8
/* CB60A4 802410A4 AE620070 */   sw       $v0, 0x70($s3)
.L802410A8:
/* CB60A8 802410A8 24030001 */  addiu     $v1, $zero, 1
/* CB60AC 802410AC 2402000E */  addiu     $v0, $zero, 0xe
/* CB60B0 802410B0 A623008E */  sh        $v1, 0x8e($s1)
/* CB60B4 802410B4 AE620070 */  sw        $v0, 0x70($s3)
/* CB60B8 802410B8 C6200038 */  lwc1      $f0, 0x38($s1)
/* CB60BC 802410BC 4600018D */  trunc.w.s $f6, $f0
/* CB60C0 802410C0 44023000 */  mfc1      $v0, $f6
/* CB60C4 802410C4 00000000 */  nop
/* CB60C8 802410C8 A6420010 */  sh        $v0, 0x10($s2)
/* CB60CC 802410CC C620003C */  lwc1      $f0, 0x3c($s1)
/* CB60D0 802410D0 4600018D */  trunc.w.s $f6, $f0
/* CB60D4 802410D4 44023000 */  mfc1      $v0, $f6
/* CB60D8 802410D8 00000000 */  nop
/* CB60DC 802410DC A6420012 */  sh        $v0, 0x12($s2)
/* CB60E0 802410E0 C6200040 */  lwc1      $f0, 0x40($s1)
/* CB60E4 802410E4 A2430007 */  sb        $v1, 7($s2)
/* CB60E8 802410E8 4600018D */  trunc.w.s $f6, $f0
/* CB60EC 802410EC 44023000 */  mfc1      $v0, $f6
/* CB60F0 802410F0 00000000 */  nop
/* CB60F4 802410F4 A6420014 */  sh        $v0, 0x14($s2)
.L802410F8:
/* CB60F8 802410F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* CB60FC 802410FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* CB6100 80241100 8FB20018 */  lw        $s2, 0x18($sp)
/* CB6104 80241104 8FB10014 */  lw        $s1, 0x14($sp)
/* CB6108 80241108 8FB00010 */  lw        $s0, 0x10($sp)
/* CB610C 8024110C 03E00008 */  jr        $ra
/* CB6110 80241110 27BD0028 */   addiu    $sp, $sp, 0x28
