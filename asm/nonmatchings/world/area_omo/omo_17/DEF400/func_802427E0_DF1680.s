.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427E0_DF1680
/* DF1680 802427E0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DF1684 802427E4 AFB20038 */  sw        $s2, 0x38($sp)
/* DF1688 802427E8 0080902D */  daddu     $s2, $a0, $zero
/* DF168C 802427EC AFBF003C */  sw        $ra, 0x3c($sp)
/* DF1690 802427F0 AFB10034 */  sw        $s1, 0x34($sp)
/* DF1694 802427F4 AFB00030 */  sw        $s0, 0x30($sp)
/* DF1698 802427F8 8E510148 */  lw        $s1, 0x148($s2)
/* DF169C 802427FC 0C00EABB */  jal       get_npc_unsafe
/* DF16A0 80242800 86240008 */   lh       $a0, 8($s1)
/* DF16A4 80242804 0040802D */  daddu     $s0, $v0, $zero
/* DF16A8 80242808 9602008E */  lhu       $v0, 0x8e($s0)
/* DF16AC 8024280C 2442FFFF */  addiu     $v0, $v0, -1
/* DF16B0 80242810 A602008E */  sh        $v0, 0x8e($s0)
/* DF16B4 80242814 00021400 */  sll       $v0, $v0, 0x10
/* DF16B8 80242818 1C40002B */  bgtz      $v0, .L802428C8
/* DF16BC 8024281C 00000000 */   nop
/* DF16C0 80242820 0C09092B */  jal       func_802424AC_DF134C
/* DF16C4 80242824 0240202D */   daddu    $a0, $s2, $zero
/* DF16C8 80242828 0040202D */  daddu     $a0, $v0, $zero
/* DF16CC 8024282C 0481001A */  bgez      $a0, .L80242898
/* DF16D0 80242830 2402000F */   addiu    $v0, $zero, 0xf
/* DF16D4 80242834 24040002 */  addiu     $a0, $zero, 2
/* DF16D8 80242838 860300A8 */  lh        $v1, 0xa8($s0)
/* DF16DC 8024283C AFA2001C */  sw        $v0, 0x1c($sp)
/* DF16E0 80242840 27A20028 */  addiu     $v0, $sp, 0x28
/* DF16E4 80242844 0200282D */  daddu     $a1, $s0, $zero
/* DF16E8 80242848 3C013F80 */  lui       $at, 0x3f80
/* DF16EC 8024284C 44810000 */  mtc1      $at, $f0
/* DF16F0 80242850 3C014000 */  lui       $at, 0x4000
/* DF16F4 80242854 44811000 */  mtc1      $at, $f2
/* DF16F8 80242858 3C01C1A0 */  lui       $at, 0xc1a0
/* DF16FC 8024285C 44812000 */  mtc1      $at, $f4
/* DF1700 80242860 44833000 */  mtc1      $v1, $f6
/* DF1704 80242864 00000000 */  nop
/* DF1708 80242868 468031A0 */  cvt.s.w   $f6, $f6
/* DF170C 8024286C 44073000 */  mfc1      $a3, $f6
/* DF1710 80242870 0000302D */  daddu     $a2, $zero, $zero
/* DF1714 80242874 AFA20020 */  sw        $v0, 0x20($sp)
/* DF1718 80242878 E7A00010 */  swc1      $f0, 0x10($sp)
/* DF171C 8024287C E7A20014 */  swc1      $f2, 0x14($sp)
/* DF1720 80242880 0C01BFA4 */  jal       fx_emote
/* DF1724 80242884 E7A40018 */   swc1     $f4, 0x18($sp)
/* DF1728 80242888 8E2200CC */  lw        $v0, 0xcc($s1)
/* DF172C 8024288C 8C420000 */  lw        $v0, ($v0)
/* DF1730 80242890 08090A2E */  j         .L802428B8
/* DF1734 80242894 AE020028 */   sw       $v0, 0x28($s0)
.L80242898:
/* DF1738 80242898 8E2200CC */  lw        $v0, 0xcc($s1)
/* DF173C 8024289C 8C420024 */  lw        $v0, 0x24($v0)
/* DF1740 802428A0 0C00FB3A */  jal       get_enemy
/* DF1744 802428A4 AE020028 */   sw       $v0, 0x28($s0)
/* DF1748 802428A8 86240008 */  lh        $a0, 8($s1)
/* DF174C 802428AC 24030001 */  addiu     $v1, $zero, 1
/* DF1750 802428B0 AC43006C */  sw        $v1, 0x6c($v0)
/* DF1754 802428B4 AC44007C */  sw        $a0, 0x7c($v0)
.L802428B8:
/* DF1758 802428B8 96220076 */  lhu       $v0, 0x76($s1)
/* DF175C 802428BC A602008E */  sh        $v0, 0x8e($s0)
/* DF1760 802428C0 24020021 */  addiu     $v0, $zero, 0x21
/* DF1764 802428C4 AE420070 */  sw        $v0, 0x70($s2)
.L802428C8:
/* DF1768 802428C8 8FBF003C */  lw        $ra, 0x3c($sp)
/* DF176C 802428CC 8FB20038 */  lw        $s2, 0x38($sp)
/* DF1770 802428D0 8FB10034 */  lw        $s1, 0x34($sp)
/* DF1774 802428D4 8FB00030 */  lw        $s0, 0x30($sp)
/* DF1778 802428D8 03E00008 */  jr        $ra
/* DF177C 802428DC 27BD0040 */   addiu    $sp, $sp, 0x40
