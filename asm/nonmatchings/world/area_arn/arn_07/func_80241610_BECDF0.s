.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241610_BEE400
/* BEE400 80241610 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BEE404 80241614 AFB3001C */  sw        $s3, 0x1c($sp)
/* BEE408 80241618 0080982D */  daddu     $s3, $a0, $zero
/* BEE40C 8024161C AFBF0020 */  sw        $ra, 0x20($sp)
/* BEE410 80241620 AFB20018 */  sw        $s2, 0x18($sp)
/* BEE414 80241624 AFB10014 */  sw        $s1, 0x14($sp)
/* BEE418 80241628 AFB00010 */  sw        $s0, 0x10($sp)
/* BEE41C 8024162C 8E720148 */  lw        $s2, 0x148($s3)
/* BEE420 80241630 86440008 */  lh        $a0, 8($s2)
/* BEE424 80241634 0C00EABB */  jal       get_npc_unsafe
/* BEE428 80241638 00A0802D */   daddu    $s0, $a1, $zero
/* BEE42C 8024163C 0040882D */  daddu     $s1, $v0, $zero
/* BEE430 80241640 C6420080 */  lwc1      $f2, 0x80($s2)
/* BEE434 80241644 468010A0 */  cvt.s.w   $f2, $f2
/* BEE438 80241648 460010A1 */  cvt.d.s   $f2, $f2
/* BEE43C 8024164C C6400084 */  lwc1      $f0, 0x84($s2)
/* BEE440 80241650 46800020 */  cvt.s.w   $f0, $f0
/* BEE444 80241654 46000021 */  cvt.d.s   $f0, $f0
/* BEE448 80241658 3C014059 */  lui       $at, 0x4059
/* BEE44C 8024165C 44812800 */  mtc1      $at, $f5
/* BEE450 80241660 44802000 */  mtc1      $zero, $f4
/* BEE454 80241664 8E4200CC */  lw        $v0, 0xcc($s2)
/* BEE458 80241668 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BEE45C 8024166C C62E0040 */  lwc1      $f14, 0x40($s1)
/* BEE460 80241670 46241083 */  div.d     $f2, $f2, $f4
/* BEE464 80241674 462010A0 */  cvt.s.d   $f2, $f2
/* BEE468 80241678 46240003 */  div.d     $f0, $f0, $f4
/* BEE46C 8024167C 8C420020 */  lw        $v0, 0x20($v0)
/* BEE470 80241680 46200020 */  cvt.s.d   $f0, $f0
/* BEE474 80241684 E622001C */  swc1      $f2, 0x1c($s1)
/* BEE478 80241688 E6200014 */  swc1      $f0, 0x14($s1)
/* BEE47C 8024168C AE220028 */  sw        $v0, 0x28($s1)
/* BEE480 80241690 C6000018 */  lwc1      $f0, 0x18($s0)
/* BEE484 80241694 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BEE488 80241698 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BEE48C 8024169C E6200018 */  swc1      $f0, 0x18($s1)
/* BEE490 802416A0 8C460028 */  lw        $a2, 0x28($v0)
/* BEE494 802416A4 0C00A720 */  jal       atan2
/* BEE498 802416A8 8C470030 */   lw       $a3, 0x30($v0)
/* BEE49C 802416AC E620000C */  swc1      $f0, 0xc($s1)
/* BEE4A0 802416B0 8E420018 */  lw        $v0, 0x18($s2)
/* BEE4A4 802416B4 AE400074 */  sw        $zero, 0x74($s2)
/* BEE4A8 802416B8 9442002A */  lhu       $v0, 0x2a($v0)
/* BEE4AC 802416BC 30420002 */  andi      $v0, $v0, 2
/* BEE4B0 802416C0 10400005 */  beqz      $v0, .L802416D8
/* BEE4B4 802416C4 24020003 */   addiu    $v0, $zero, 3
/* BEE4B8 802416C8 A622008E */  sh        $v0, 0x8e($s1)
/* BEE4BC 802416CC 2402000D */  addiu     $v0, $zero, 0xd
/* BEE4C0 802416D0 080905CA */  j         .L80241728
/* BEE4C4 802416D4 AE620070 */   sw       $v0, 0x70($s3)
.L802416D8:
/* BEE4C8 802416D8 24030001 */  addiu     $v1, $zero, 1
/* BEE4CC 802416DC 2402000E */  addiu     $v0, $zero, 0xe
/* BEE4D0 802416E0 A623008E */  sh        $v1, 0x8e($s1)
/* BEE4D4 802416E4 AE620070 */  sw        $v0, 0x70($s3)
/* BEE4D8 802416E8 C6200038 */  lwc1      $f0, 0x38($s1)
/* BEE4DC 802416EC 4600018D */  trunc.w.s $f6, $f0
/* BEE4E0 802416F0 44023000 */  mfc1      $v0, $f6
/* BEE4E4 802416F4 00000000 */  nop       
/* BEE4E8 802416F8 A6420010 */  sh        $v0, 0x10($s2)
/* BEE4EC 802416FC C620003C */  lwc1      $f0, 0x3c($s1)
/* BEE4F0 80241700 4600018D */  trunc.w.s $f6, $f0
/* BEE4F4 80241704 44023000 */  mfc1      $v0, $f6
/* BEE4F8 80241708 00000000 */  nop       
/* BEE4FC 8024170C A6420012 */  sh        $v0, 0x12($s2)
/* BEE500 80241710 C6200040 */  lwc1      $f0, 0x40($s1)
/* BEE504 80241714 A2430007 */  sb        $v1, 7($s2)
/* BEE508 80241718 4600018D */  trunc.w.s $f6, $f0
/* BEE50C 8024171C 44023000 */  mfc1      $v0, $f6
/* BEE510 80241720 00000000 */  nop       
/* BEE514 80241724 A6420014 */  sh        $v0, 0x14($s2)
.L80241728:
/* BEE518 80241728 8FBF0020 */  lw        $ra, 0x20($sp)
/* BEE51C 8024172C 8FB3001C */  lw        $s3, 0x1c($sp)
/* BEE520 80241730 8FB20018 */  lw        $s2, 0x18($sp)
/* BEE524 80241734 8FB10014 */  lw        $s1, 0x14($sp)
/* BEE528 80241738 8FB00010 */  lw        $s0, 0x10($sp)
/* BEE52C 8024173C 03E00008 */  jr        $ra
/* BEE530 80241740 27BD0028 */   addiu    $sp, $sp, 0x28
