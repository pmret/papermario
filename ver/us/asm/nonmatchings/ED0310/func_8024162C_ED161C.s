.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802441E8_ED41D8
.word L80241764_ED1754, L80241774_ED1764, L8024178C_ED177C, L8024179C_ED178C, L8024181C_ED180C, L8024181C_ED180C, L8024181C_ED180C, L8024181C_ED180C, L8024181C_ED180C, L8024181C_ED180C, L802417B4_ED17A4, L802417C4_ED17B4, L802417DC_ED17CC, L802417F4_ED17E4, L8024180C_ED17FC, 0, 0, 0

.section .text

glabel func_8024162C_ED161C
/* ED161C 8024162C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* ED1620 80241630 AFB50044 */  sw        $s5, 0x44($sp)
/* ED1624 80241634 0080A82D */  daddu     $s5, $a0, $zero
/* ED1628 80241638 AFBF0048 */  sw        $ra, 0x48($sp)
/* ED162C 8024163C AFB40040 */  sw        $s4, 0x40($sp)
/* ED1630 80241640 AFB3003C */  sw        $s3, 0x3c($sp)
/* ED1634 80241644 AFB20038 */  sw        $s2, 0x38($sp)
/* ED1638 80241648 AFB10034 */  sw        $s1, 0x34($sp)
/* ED163C 8024164C AFB00030 */  sw        $s0, 0x30($sp)
/* ED1640 80241650 8EB20148 */  lw        $s2, 0x148($s5)
/* ED1644 80241654 86440008 */  lh        $a0, 8($s2)
/* ED1648 80241658 8EB0000C */  lw        $s0, 0xc($s5)
/* ED164C 8024165C 0C00F92F */  jal       dead_get_npc_unsafe
/* ED1650 80241660 00A0882D */   daddu    $s1, $a1, $zero
/* ED1654 80241664 02A0202D */  daddu     $a0, $s5, $zero
/* ED1658 80241668 8E050000 */  lw        $a1, ($s0)
/* ED165C 8024166C 0C0B53A3 */  jal       dead_evt_get_variable
/* ED1660 80241670 0040A02D */   daddu    $s4, $v0, $zero
/* ED1664 80241674 AFA00010 */  sw        $zero, 0x10($sp)
/* ED1668 80241678 8E4300D0 */  lw        $v1, 0xd0($s2)
/* ED166C 8024167C 8C630030 */  lw        $v1, 0x30($v1)
/* ED1670 80241680 AFA30014 */  sw        $v1, 0x14($sp)
/* ED1674 80241684 8E4300D0 */  lw        $v1, 0xd0($s2)
/* ED1678 80241688 8C63001C */  lw        $v1, 0x1c($v1)
/* ED167C 8024168C AFA30018 */  sw        $v1, 0x18($sp)
/* ED1680 80241690 8E4300D0 */  lw        $v1, 0xd0($s2)
/* ED1684 80241694 8C630024 */  lw        $v1, 0x24($v1)
/* ED1688 80241698 AFA3001C */  sw        $v1, 0x1c($sp)
/* ED168C 8024169C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* ED1690 802416A0 8C630028 */  lw        $v1, 0x28($v1)
/* ED1694 802416A4 AFA30020 */  sw        $v1, 0x20($sp)
/* ED1698 802416A8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* ED169C 802416AC 3C0142F0 */  lui       $at, 0x42f0
/* ED16A0 802416B0 44810000 */  mtc1      $at, $f0
/* ED16A4 802416B4 8C63002C */  lw        $v1, 0x2c($v1)
/* ED16A8 802416B8 E7A00028 */  swc1      $f0, 0x28($sp)
/* ED16AC 802416BC A7A0002C */  sh        $zero, 0x2c($sp)
/* ED16B0 802416C0 AFA30024 */  sw        $v1, 0x24($sp)
/* ED16B4 802416C4 C6800038 */  lwc1      $f0, 0x38($s4)
/* ED16B8 802416C8 E6400108 */  swc1      $f0, 0x108($s2)
/* ED16BC 802416CC C680003C */  lwc1      $f0, 0x3c($s4)
/* ED16C0 802416D0 27B30010 */  addiu     $s3, $sp, 0x10
/* ED16C4 802416D4 E640010C */  swc1      $f0, 0x10c($s2)
/* ED16C8 802416D8 3C0138D1 */  lui       $at, 0x38d1
/* ED16CC 802416DC 3421B717 */  ori       $at, $at, 0xb717
/* ED16D0 802416E0 44810000 */  mtc1      $at, $f0
/* ED16D4 802416E4 C6820040 */  lwc1      $f2, 0x40($s4)
/* ED16D8 802416E8 0040802D */  daddu     $s0, $v0, $zero
/* ED16DC 802416EC E6400114 */  swc1      $f0, 0x114($s2)
/* ED16E0 802416F0 E6400118 */  swc1      $f0, 0x118($s2)
/* ED16E4 802416F4 12200006 */  beqz      $s1, .L80241710
/* ED16E8 802416F8 E6420110 */   swc1     $f2, 0x110($s2)
/* ED16EC 802416FC 0280202D */  daddu     $a0, $s4, $zero
/* ED16F0 80241700 0240282D */  daddu     $a1, $s2, $zero
/* ED16F4 80241704 02A0302D */  daddu     $a2, $s5, $zero
/* ED16F8 80241708 0C090542 */  jal       ED0310_UnkFunc5
/* ED16FC 8024170C 0200382D */   daddu    $a3, $s0, $zero
.L80241710:
/* ED1700 80241710 2402FFFE */  addiu     $v0, $zero, -2
/* ED1704 80241714 A28200AB */  sb        $v0, 0xab($s4)
/* ED1708 80241718 8E4300B0 */  lw        $v1, 0xb0($s2)
/* ED170C 8024171C 30620004 */  andi      $v0, $v1, 4
/* ED1710 80241720 10400007 */  beqz      $v0, .L80241740
/* ED1714 80241724 00000000 */   nop
/* ED1718 80241728 824200B4 */  lb        $v0, 0xb4($s2)
/* ED171C 8024172C 1440003C */  bnez      $v0, .L80241820
/* ED1720 80241730 0000102D */   daddu    $v0, $zero, $zero
/* ED1724 80241734 2402FFFB */  addiu     $v0, $zero, -5
/* ED1728 80241738 00621024 */  and       $v0, $v1, $v0
/* ED172C 8024173C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241740:
/* ED1730 80241740 8EA30070 */  lw        $v1, 0x70($s5)
/* ED1734 80241744 2C62000F */  sltiu     $v0, $v1, 0xf
/* ED1738 80241748 10400034 */  beqz      $v0, L8024181C_ED180C
/* ED173C 8024174C 00031080 */   sll      $v0, $v1, 2
/* ED1740 80241750 3C018024 */  lui       $at, %hi(jtbl_802441E8_ED41D8)
/* ED1744 80241754 00220821 */  addu      $at, $at, $v0
/* ED1748 80241758 8C2241E8 */  lw        $v0, %lo(jtbl_802441E8_ED41D8)($at)
/* ED174C 8024175C 00400008 */  jr        $v0
/* ED1750 80241760 00000000 */   nop
glabel L80241764_ED1754
/* ED1754 80241764 02A0202D */  daddu     $a0, $s5, $zero
/* ED1758 80241768 0200282D */  daddu     $a1, $s0, $zero
/* ED175C 8024176C 0C0900C8 */  jal       ED0310_UnkNpcAIFunc23
/* ED1760 80241770 0260302D */   daddu    $a2, $s3, $zero
glabel L80241774_ED1764
/* ED1764 80241774 02A0202D */  daddu     $a0, $s5, $zero
/* ED1768 80241778 0200282D */  daddu     $a1, $s0, $zero
/* ED176C 8024177C 0C090134 */  jal       func_802404D0_ED04C0
/* ED1770 80241780 0260302D */   daddu    $a2, $s3, $zero
/* ED1774 80241784 08090608 */  j         .L80241820
/* ED1778 80241788 0000102D */   daddu    $v0, $zero, $zero
glabel L8024178C_ED177C
/* ED177C 8024178C 02A0202D */  daddu     $a0, $s5, $zero
/* ED1780 80241790 0200282D */  daddu     $a1, $s0, $zero
/* ED1784 80241794 0C0902BE */  jal       ED0310_UnkNpcAIFunc1
/* ED1788 80241798 0260302D */   daddu    $a2, $s3, $zero
glabel L8024179C_ED178C
/* ED178C 8024179C 02A0202D */  daddu     $a0, $s5, $zero
/* ED1790 802417A0 0200282D */  daddu     $a1, $s0, $zero
/* ED1794 802417A4 0C0902EE */  jal       ED0310_UnkFunc4
/* ED1798 802417A8 0260302D */   daddu    $a2, $s3, $zero
/* ED179C 802417AC 08090608 */  j         .L80241820
/* ED17A0 802417B0 0000102D */   daddu    $v0, $zero, $zero
glabel L802417B4_ED17A4
/* ED17A4 802417B4 02A0202D */  daddu     $a0, $s5, $zero
/* ED17A8 802417B8 0200282D */  daddu     $a1, $s0, $zero
/* ED17AC 802417BC 0C0903BF */  jal       ED0310_UnkNpcAIFunc2
/* ED17B0 802417C0 0260302D */   daddu    $a2, $s3, $zero
glabel L802417C4_ED17B4
/* ED17B4 802417C4 02A0202D */  daddu     $a0, $s5, $zero
/* ED17B8 802417C8 0200282D */  daddu     $a1, $s0, $zero
/* ED17BC 802417CC 0C0903DD */  jal       func_80240F74_ED0F64
/* ED17C0 802417D0 0260302D */   daddu    $a2, $s3, $zero
/* ED17C4 802417D4 08090608 */  j         .L80241820
/* ED17C8 802417D8 0000102D */   daddu    $v0, $zero, $zero
glabel L802417DC_ED17CC
/* ED17CC 802417DC 02A0202D */  daddu     $a0, $s5, $zero
/* ED17D0 802417E0 0200282D */  daddu     $a1, $s0, $zero
/* ED17D4 802417E4 0C0903F8 */  jal       ED0310_UnkNpcAIFunc14
/* ED17D8 802417E8 0260302D */   daddu    $a2, $s3, $zero
/* ED17DC 802417EC 08090608 */  j         .L80241820
/* ED17E0 802417F0 0000102D */   daddu    $v0, $zero, $zero
glabel L802417F4_ED17E4
/* ED17E4 802417F4 02A0202D */  daddu     $a0, $s5, $zero
/* ED17E8 802417F8 0200282D */  daddu     $a1, $s0, $zero
/* ED17EC 802417FC 0C090445 */  jal       ED0310_UnkNpcAIFunc3
/* ED17F0 80241800 0260302D */   daddu    $a2, $s3, $zero
/* ED17F4 80241804 08090608 */  j         .L80241820
/* ED17F8 80241808 0000102D */   daddu    $v0, $zero, $zero
glabel L8024180C_ED17FC
/* ED17FC 8024180C 02A0202D */  daddu     $a0, $s5, $zero
/* ED1800 80241810 0200282D */  daddu     $a1, $s0, $zero
/* ED1804 80241814 0C09045E */  jal       ED0310_UnkFunc6
/* ED1808 80241818 0260302D */   daddu    $a2, $s3, $zero
glabel L8024181C_ED180C
/* ED180C 8024181C 0000102D */  daddu     $v0, $zero, $zero
.L80241820:
/* ED1810 80241820 8FBF0048 */  lw        $ra, 0x48($sp)
/* ED1814 80241824 8FB50044 */  lw        $s5, 0x44($sp)
/* ED1818 80241828 8FB40040 */  lw        $s4, 0x40($sp)
/* ED181C 8024182C 8FB3003C */  lw        $s3, 0x3c($sp)
/* ED1820 80241830 8FB20038 */  lw        $s2, 0x38($sp)
/* ED1824 80241834 8FB10034 */  lw        $s1, 0x34($sp)
/* ED1828 80241838 8FB00030 */  lw        $s0, 0x30($sp)
/* ED182C 8024183C 03E00008 */  jr        $ra
/* ED1830 80241840 27BD0050 */   addiu    $sp, $sp, 0x50
/* ED1834 80241844 00000000 */  nop
/* ED1838 80241848 00000000 */  nop
/* ED183C 8024184C 00000000 */  nop
