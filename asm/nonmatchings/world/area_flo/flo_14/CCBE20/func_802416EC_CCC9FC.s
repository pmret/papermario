.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416EC_CCC9FC
/* CCC9FC 802416EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CCCA00 802416F0 AFB20018 */  sw        $s2, 0x18($sp)
/* CCCA04 802416F4 0080902D */  daddu     $s2, $a0, $zero
/* CCCA08 802416F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* CCCA0C 802416FC AFB10014 */  sw        $s1, 0x14($sp)
/* CCCA10 80241700 AFB00010 */  sw        $s0, 0x10($sp)
/* CCCA14 80241704 8E510148 */  lw        $s1, 0x148($s2)
/* CCCA18 80241708 0C00EABB */  jal       get_npc_unsafe
/* CCCA1C 8024170C 86240008 */   lh       $a0, 8($s1)
/* CCCA20 80241710 0040802D */  daddu     $s0, $v0, $zero
/* CCCA24 80241714 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CCCA28 80241718 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CCCA2C 8024171C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CCCA30 80241720 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CCCA34 80241724 A600008E */  sh        $zero, 0x8e($s0)
/* CCCA38 80241728 8C460028 */  lw        $a2, 0x28($v0)
/* CCCA3C 8024172C 0C00A720 */  jal       atan2
/* CCCA40 80241730 8C470030 */   lw       $a3, 0x30($v0)
/* CCCA44 80241734 E600000C */  swc1      $f0, 0xc($s0)
/* CCCA48 80241738 8E2200CC */  lw        $v0, 0xcc($s1)
/* CCCA4C 8024173C 8C420020 */  lw        $v0, 0x20($v0)
/* CCCA50 80241740 AE020028 */  sw        $v0, 0x28($s0)
/* CCCA54 80241744 2402000B */  addiu     $v0, $zero, 0xb
/* CCCA58 80241748 AE420070 */  sw        $v0, 0x70($s2)
/* CCCA5C 8024174C 8FBF001C */  lw        $ra, 0x1c($sp)
/* CCCA60 80241750 8FB20018 */  lw        $s2, 0x18($sp)
/* CCCA64 80241754 8FB10014 */  lw        $s1, 0x14($sp)
/* CCCA68 80241758 8FB00010 */  lw        $s0, 0x10($sp)
/* CCCA6C 8024175C 03E00008 */  jr        $ra
/* CCCA70 80241760 27BD0020 */   addiu    $sp, $sp, 0x20
