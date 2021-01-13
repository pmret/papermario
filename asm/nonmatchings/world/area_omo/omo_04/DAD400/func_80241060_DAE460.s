.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241060_DAE460
/* DAE460 80241060 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DAE464 80241064 AFB3001C */  sw        $s3, 0x1c($sp)
/* DAE468 80241068 0080982D */  daddu     $s3, $a0, $zero
/* DAE46C 8024106C AFBF0020 */  sw        $ra, 0x20($sp)
/* DAE470 80241070 AFB20018 */  sw        $s2, 0x18($sp)
/* DAE474 80241074 AFB10014 */  sw        $s1, 0x14($sp)
/* DAE478 80241078 AFB00010 */  sw        $s0, 0x10($sp)
/* DAE47C 8024107C 8E720148 */  lw        $s2, 0x148($s3)
/* DAE480 80241080 86440008 */  lh        $a0, 8($s2)
/* DAE484 80241084 0C00EABB */  jal       get_npc_unsafe
/* DAE488 80241088 00A0802D */   daddu    $s0, $a1, $zero
/* DAE48C 8024108C 0040882D */  daddu     $s1, $v0, $zero
/* DAE490 80241090 C6420080 */  lwc1      $f2, 0x80($s2)
/* DAE494 80241094 468010A0 */  cvt.s.w   $f2, $f2
/* DAE498 80241098 460010A1 */  cvt.d.s   $f2, $f2
/* DAE49C 8024109C C6400084 */  lwc1      $f0, 0x84($s2)
/* DAE4A0 802410A0 46800020 */  cvt.s.w   $f0, $f0
/* DAE4A4 802410A4 46000021 */  cvt.d.s   $f0, $f0
/* DAE4A8 802410A8 3C014059 */  lui       $at, 0x4059
/* DAE4AC 802410AC 44812800 */  mtc1      $at, $f5
/* DAE4B0 802410B0 44802000 */  mtc1      $zero, $f4
/* DAE4B4 802410B4 8E4200CC */  lw        $v0, 0xcc($s2)
/* DAE4B8 802410B8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* DAE4BC 802410BC C62E0040 */  lwc1      $f14, 0x40($s1)
/* DAE4C0 802410C0 46241083 */  div.d     $f2, $f2, $f4
/* DAE4C4 802410C4 462010A0 */  cvt.s.d   $f2, $f2
/* DAE4C8 802410C8 46240003 */  div.d     $f0, $f0, $f4
/* DAE4CC 802410CC 8C420020 */  lw        $v0, 0x20($v0)
/* DAE4D0 802410D0 46200020 */  cvt.s.d   $f0, $f0
/* DAE4D4 802410D4 E622001C */  swc1      $f2, 0x1c($s1)
/* DAE4D8 802410D8 E6200014 */  swc1      $f0, 0x14($s1)
/* DAE4DC 802410DC AE220028 */  sw        $v0, 0x28($s1)
/* DAE4E0 802410E0 C6000018 */  lwc1      $f0, 0x18($s0)
/* DAE4E4 802410E4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DAE4E8 802410E8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DAE4EC 802410EC E6200018 */  swc1      $f0, 0x18($s1)
/* DAE4F0 802410F0 8C460028 */  lw        $a2, 0x28($v0)
/* DAE4F4 802410F4 0C00A720 */  jal       atan2
/* DAE4F8 802410F8 8C470030 */   lw       $a3, 0x30($v0)
/* DAE4FC 802410FC E620000C */  swc1      $f0, 0xc($s1)
/* DAE500 80241100 8E420018 */  lw        $v0, 0x18($s2)
/* DAE504 80241104 AE400074 */  sw        $zero, 0x74($s2)
/* DAE508 80241108 9442002A */  lhu       $v0, 0x2a($v0)
/* DAE50C 8024110C 30420002 */  andi      $v0, $v0, 2
/* DAE510 80241110 10400005 */  beqz      $v0, .L80241128
/* DAE514 80241114 24020003 */   addiu    $v0, $zero, 3
/* DAE518 80241118 A622008E */  sh        $v0, 0x8e($s1)
/* DAE51C 8024111C 2402000D */  addiu     $v0, $zero, 0xd
/* DAE520 80241120 0809045E */  j         .L80241178
/* DAE524 80241124 AE620070 */   sw       $v0, 0x70($s3)
.L80241128:
/* DAE528 80241128 24030001 */  addiu     $v1, $zero, 1
/* DAE52C 8024112C 2402000E */  addiu     $v0, $zero, 0xe
/* DAE530 80241130 A623008E */  sh        $v1, 0x8e($s1)
/* DAE534 80241134 AE620070 */  sw        $v0, 0x70($s3)
/* DAE538 80241138 C6200038 */  lwc1      $f0, 0x38($s1)
/* DAE53C 8024113C 4600018D */  trunc.w.s $f6, $f0
/* DAE540 80241140 44023000 */  mfc1      $v0, $f6
/* DAE544 80241144 00000000 */  nop
/* DAE548 80241148 A6420010 */  sh        $v0, 0x10($s2)
/* DAE54C 8024114C C620003C */  lwc1      $f0, 0x3c($s1)
/* DAE550 80241150 4600018D */  trunc.w.s $f6, $f0
/* DAE554 80241154 44023000 */  mfc1      $v0, $f6
/* DAE558 80241158 00000000 */  nop
/* DAE55C 8024115C A6420012 */  sh        $v0, 0x12($s2)
/* DAE560 80241160 C6200040 */  lwc1      $f0, 0x40($s1)
/* DAE564 80241164 A2430007 */  sb        $v1, 7($s2)
/* DAE568 80241168 4600018D */  trunc.w.s $f6, $f0
/* DAE56C 8024116C 44023000 */  mfc1      $v0, $f6
/* DAE570 80241170 00000000 */  nop
/* DAE574 80241174 A6420014 */  sh        $v0, 0x14($s2)
.L80241178:
/* DAE578 80241178 8FBF0020 */  lw        $ra, 0x20($sp)
/* DAE57C 8024117C 8FB3001C */  lw        $s3, 0x1c($sp)
/* DAE580 80241180 8FB20018 */  lw        $s2, 0x18($sp)
/* DAE584 80241184 8FB10014 */  lw        $s1, 0x14($sp)
/* DAE588 80241188 8FB00010 */  lw        $s0, 0x10($sp)
/* DAE58C 8024118C 03E00008 */  jr        $ra
/* DAE590 80241190 27BD0028 */   addiu    $sp, $sp, 0x28
