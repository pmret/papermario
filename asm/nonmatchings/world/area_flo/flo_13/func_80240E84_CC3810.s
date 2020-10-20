.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E84_CC4694
/* CC4694 80240E84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CC4698 80240E88 AFB3001C */  sw        $s3, 0x1c($sp)
/* CC469C 80240E8C 0080982D */  daddu     $s3, $a0, $zero
/* CC46A0 80240E90 AFBF0020 */  sw        $ra, 0x20($sp)
/* CC46A4 80240E94 AFB20018 */  sw        $s2, 0x18($sp)
/* CC46A8 80240E98 AFB10014 */  sw        $s1, 0x14($sp)
/* CC46AC 80240E9C AFB00010 */  sw        $s0, 0x10($sp)
/* CC46B0 80240EA0 8E720148 */  lw        $s2, 0x148($s3)
/* CC46B4 80240EA4 86440008 */  lh        $a0, 8($s2)
/* CC46B8 80240EA8 0C00EABB */  jal       get_npc_unsafe
/* CC46BC 80240EAC 00A0802D */   daddu    $s0, $a1, $zero
/* CC46C0 80240EB0 0040882D */  daddu     $s1, $v0, $zero
/* CC46C4 80240EB4 C6420080 */  lwc1      $f2, 0x80($s2)
/* CC46C8 80240EB8 468010A0 */  cvt.s.w   $f2, $f2
/* CC46CC 80240EBC 460010A1 */  cvt.d.s   $f2, $f2
/* CC46D0 80240EC0 C6400084 */  lwc1      $f0, 0x84($s2)
/* CC46D4 80240EC4 46800020 */  cvt.s.w   $f0, $f0
/* CC46D8 80240EC8 46000021 */  cvt.d.s   $f0, $f0
/* CC46DC 80240ECC 3C014059 */  lui       $at, 0x4059
/* CC46E0 80240ED0 44812800 */  mtc1      $at, $f5
/* CC46E4 80240ED4 44802000 */  mtc1      $zero, $f4
/* CC46E8 80240ED8 8E4200CC */  lw        $v0, 0xcc($s2)
/* CC46EC 80240EDC C62C0038 */  lwc1      $f12, 0x38($s1)
/* CC46F0 80240EE0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* CC46F4 80240EE4 46241083 */  div.d     $f2, $f2, $f4
/* CC46F8 80240EE8 462010A0 */  cvt.s.d   $f2, $f2
/* CC46FC 80240EEC 46240003 */  div.d     $f0, $f0, $f4
/* CC4700 80240EF0 8C420020 */  lw        $v0, 0x20($v0)
/* CC4704 80240EF4 46200020 */  cvt.s.d   $f0, $f0
/* CC4708 80240EF8 E622001C */  swc1      $f2, 0x1c($s1)
/* CC470C 80240EFC E6200014 */  swc1      $f0, 0x14($s1)
/* CC4710 80240F00 AE220028 */  sw        $v0, 0x28($s1)
/* CC4714 80240F04 C6000018 */  lwc1      $f0, 0x18($s0)
/* CC4718 80240F08 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC471C 80240F0C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC4720 80240F10 E6200018 */  swc1      $f0, 0x18($s1)
/* CC4724 80240F14 8C460028 */  lw        $a2, 0x28($v0)
/* CC4728 80240F18 0C00A720 */  jal       atan2
/* CC472C 80240F1C 8C470030 */   lw       $a3, 0x30($v0)
/* CC4730 80240F20 E620000C */  swc1      $f0, 0xc($s1)
/* CC4734 80240F24 8E420018 */  lw        $v0, 0x18($s2)
/* CC4738 80240F28 AE400074 */  sw        $zero, 0x74($s2)
/* CC473C 80240F2C 9442002A */  lhu       $v0, 0x2a($v0)
/* CC4740 80240F30 30420002 */  andi      $v0, $v0, 2
/* CC4744 80240F34 10400005 */  beqz      $v0, .L80240F4C
/* CC4748 80240F38 24020003 */   addiu    $v0, $zero, 3
/* CC474C 80240F3C A622008E */  sh        $v0, 0x8e($s1)
/* CC4750 80240F40 2402000D */  addiu     $v0, $zero, 0xd
/* CC4754 80240F44 080903E7 */  j         .L80240F9C
/* CC4758 80240F48 AE620070 */   sw       $v0, 0x70($s3)
.L80240F4C:
/* CC475C 80240F4C 24030001 */  addiu     $v1, $zero, 1
/* CC4760 80240F50 2402000E */  addiu     $v0, $zero, 0xe
/* CC4764 80240F54 A623008E */  sh        $v1, 0x8e($s1)
/* CC4768 80240F58 AE620070 */  sw        $v0, 0x70($s3)
/* CC476C 80240F5C C6200038 */  lwc1      $f0, 0x38($s1)
/* CC4770 80240F60 4600018D */  trunc.w.s $f6, $f0
/* CC4774 80240F64 44023000 */  mfc1      $v0, $f6
/* CC4778 80240F68 00000000 */  nop       
/* CC477C 80240F6C A6420010 */  sh        $v0, 0x10($s2)
/* CC4780 80240F70 C620003C */  lwc1      $f0, 0x3c($s1)
/* CC4784 80240F74 4600018D */  trunc.w.s $f6, $f0
/* CC4788 80240F78 44023000 */  mfc1      $v0, $f6
/* CC478C 80240F7C 00000000 */  nop       
/* CC4790 80240F80 A6420012 */  sh        $v0, 0x12($s2)
/* CC4794 80240F84 C6200040 */  lwc1      $f0, 0x40($s1)
/* CC4798 80240F88 A2430007 */  sb        $v1, 7($s2)
/* CC479C 80240F8C 4600018D */  trunc.w.s $f6, $f0
/* CC47A0 80240F90 44023000 */  mfc1      $v0, $f6
/* CC47A4 80240F94 00000000 */  nop       
/* CC47A8 80240F98 A6420014 */  sh        $v0, 0x14($s2)
.L80240F9C:
/* CC47AC 80240F9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CC47B0 80240FA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* CC47B4 80240FA4 8FB20018 */  lw        $s2, 0x18($sp)
/* CC47B8 80240FA8 8FB10014 */  lw        $s1, 0x14($sp)
/* CC47BC 80240FAC 8FB00010 */  lw        $s0, 0x10($sp)
/* CC47C0 80240FB0 03E00008 */  jr        $ra
/* CC47C4 80240FB4 27BD0028 */   addiu    $sp, $sp, 0x28
