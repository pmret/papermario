.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D60_BAE6A0
/* BAE6A0 80240D60 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BAE6A4 80240D64 AFB3001C */  sw        $s3, 0x1c($sp)
/* BAE6A8 80240D68 0080982D */  daddu     $s3, $a0, $zero
/* BAE6AC 80240D6C AFBF0020 */  sw        $ra, 0x20($sp)
/* BAE6B0 80240D70 AFB20018 */  sw        $s2, 0x18($sp)
/* BAE6B4 80240D74 AFB10014 */  sw        $s1, 0x14($sp)
/* BAE6B8 80240D78 AFB00010 */  sw        $s0, 0x10($sp)
/* BAE6BC 80240D7C 8E720148 */  lw        $s2, 0x148($s3)
/* BAE6C0 80240D80 86440008 */  lh        $a0, 8($s2)
/* BAE6C4 80240D84 0C00EABB */  jal       get_npc_unsafe
/* BAE6C8 80240D88 00A0802D */   daddu    $s0, $a1, $zero
/* BAE6CC 80240D8C 0040882D */  daddu     $s1, $v0, $zero
/* BAE6D0 80240D90 C6420080 */  lwc1      $f2, 0x80($s2)
/* BAE6D4 80240D94 468010A0 */  cvt.s.w   $f2, $f2
/* BAE6D8 80240D98 460010A1 */  cvt.d.s   $f2, $f2
/* BAE6DC 80240D9C C6400084 */  lwc1      $f0, 0x84($s2)
/* BAE6E0 80240DA0 46800020 */  cvt.s.w   $f0, $f0
/* BAE6E4 80240DA4 46000021 */  cvt.d.s   $f0, $f0
/* BAE6E8 80240DA8 3C014059 */  lui       $at, 0x4059
/* BAE6EC 80240DAC 44812800 */  mtc1      $at, $f5
/* BAE6F0 80240DB0 44802000 */  mtc1      $zero, $f4
/* BAE6F4 80240DB4 8E4200CC */  lw        $v0, 0xcc($s2)
/* BAE6F8 80240DB8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BAE6FC 80240DBC C62E0040 */  lwc1      $f14, 0x40($s1)
/* BAE700 80240DC0 46241083 */  div.d     $f2, $f2, $f4
/* BAE704 80240DC4 462010A0 */  cvt.s.d   $f2, $f2
/* BAE708 80240DC8 46240003 */  div.d     $f0, $f0, $f4
/* BAE70C 80240DCC 8C420020 */  lw        $v0, 0x20($v0)
/* BAE710 80240DD0 46200020 */  cvt.s.d   $f0, $f0
/* BAE714 80240DD4 E622001C */  swc1      $f2, 0x1c($s1)
/* BAE718 80240DD8 E6200014 */  swc1      $f0, 0x14($s1)
/* BAE71C 80240DDC AE220028 */  sw        $v0, 0x28($s1)
/* BAE720 80240DE0 C6000018 */  lwc1      $f0, 0x18($s0)
/* BAE724 80240DE4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAE728 80240DE8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAE72C 80240DEC E6200018 */  swc1      $f0, 0x18($s1)
/* BAE730 80240DF0 8C460028 */  lw        $a2, 0x28($v0)
/* BAE734 80240DF4 0C00A720 */  jal       atan2
/* BAE738 80240DF8 8C470030 */   lw       $a3, 0x30($v0)
/* BAE73C 80240DFC E620000C */  swc1      $f0, 0xc($s1)
/* BAE740 80240E00 8E420018 */  lw        $v0, 0x18($s2)
/* BAE744 80240E04 AE400074 */  sw        $zero, 0x74($s2)
/* BAE748 80240E08 9442002A */  lhu       $v0, 0x2a($v0)
/* BAE74C 80240E0C 30420002 */  andi      $v0, $v0, 2
/* BAE750 80240E10 10400005 */  beqz      $v0, .L80240E28
/* BAE754 80240E14 24020003 */   addiu    $v0, $zero, 3
/* BAE758 80240E18 A622008E */  sh        $v0, 0x8e($s1)
/* BAE75C 80240E1C 2402000D */  addiu     $v0, $zero, 0xd
/* BAE760 80240E20 0809039E */  j         .L80240E78
/* BAE764 80240E24 AE620070 */   sw       $v0, 0x70($s3)
.L80240E28:
/* BAE768 80240E28 24030001 */  addiu     $v1, $zero, 1
/* BAE76C 80240E2C 2402000E */  addiu     $v0, $zero, 0xe
/* BAE770 80240E30 A623008E */  sh        $v1, 0x8e($s1)
/* BAE774 80240E34 AE620070 */  sw        $v0, 0x70($s3)
/* BAE778 80240E38 C6200038 */  lwc1      $f0, 0x38($s1)
/* BAE77C 80240E3C 4600018D */  trunc.w.s $f6, $f0
/* BAE780 80240E40 44023000 */  mfc1      $v0, $f6
/* BAE784 80240E44 00000000 */  nop
/* BAE788 80240E48 A6420010 */  sh        $v0, 0x10($s2)
/* BAE78C 80240E4C C620003C */  lwc1      $f0, 0x3c($s1)
/* BAE790 80240E50 4600018D */  trunc.w.s $f6, $f0
/* BAE794 80240E54 44023000 */  mfc1      $v0, $f6
/* BAE798 80240E58 00000000 */  nop
/* BAE79C 80240E5C A6420012 */  sh        $v0, 0x12($s2)
/* BAE7A0 80240E60 C6200040 */  lwc1      $f0, 0x40($s1)
/* BAE7A4 80240E64 A2430007 */  sb        $v1, 7($s2)
/* BAE7A8 80240E68 4600018D */  trunc.w.s $f6, $f0
/* BAE7AC 80240E6C 44023000 */  mfc1      $v0, $f6
/* BAE7B0 80240E70 00000000 */  nop
/* BAE7B4 80240E74 A6420014 */  sh        $v0, 0x14($s2)
.L80240E78:
/* BAE7B8 80240E78 8FBF0020 */  lw        $ra, 0x20($sp)
/* BAE7BC 80240E7C 8FB3001C */  lw        $s3, 0x1c($sp)
/* BAE7C0 80240E80 8FB20018 */  lw        $s2, 0x18($sp)
/* BAE7C4 80240E84 8FB10014 */  lw        $s1, 0x14($sp)
/* BAE7C8 80240E88 8FB00010 */  lw        $s0, 0x10($sp)
/* BAE7CC 80240E8C 03E00008 */  jr        $ra
/* BAE7D0 80240E90 27BD0028 */   addiu    $sp, $sp, 0x28
