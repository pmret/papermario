.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1740_71ED90
/* 71ED90 802A1740 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 71ED94 802A1744 AFB3001C */  sw        $s3, 0x1c($sp)
/* 71ED98 802A1748 3C13800E */  lui       $s3, %hi(gBattleStatus+0xD8)
/* 71ED9C 802A174C 8E73C148 */  lw        $s3, %lo(gBattleStatus+0xD8)($s3)
/* 71EDA0 802A1750 AFB40020 */  sw        $s4, 0x20($sp)
/* 71EDA4 802A1754 AFBF0024 */  sw        $ra, 0x24($sp)
/* 71EDA8 802A1758 AFB20018 */  sw        $s2, 0x18($sp)
/* 71EDAC 802A175C AFB10014 */  sw        $s1, 0x14($sp)
/* 71EDB0 802A1760 AFB00010 */  sw        $s0, 0x10($sp)
/* 71EDB4 802A1764 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 71EDB8 802A1768 10A00004 */  beqz      $a1, .L802A177C
/* 71EDBC 802A176C 0080A02D */   daddu    $s4, $a0, $zero
/* 71EDC0 802A1770 2402005A */  addiu     $v0, $zero, 0x5a
/* 71EDC4 802A1774 AE800070 */  sw        $zero, 0x70($s4)
/* 71EDC8 802A1778 AE820074 */  sw        $v0, 0x74($s4)
.L802A177C:
/* 71EDCC 802A177C 8262040C */  lb        $v0, 0x40c($s3)
/* 71EDD0 802A1780 18400021 */  blez      $v0, .L802A1808
/* 71EDD4 802A1784 0000902D */   daddu    $s2, $zero, $zero
/* 71EDD8 802A1788 3C014204 */  lui       $at, 0x4204
/* 71EDDC 802A178C 4481A000 */  mtc1      $at, $f20
/* 71EDE0 802A1790 02721021 */  addu      $v0, $s3, $s2
.L802A1794:
/* 71EDE4 802A1794 8042040D */  lb        $v0, 0x40d($v0)
/* 71EDE8 802A1798 00028080 */  sll       $s0, $v0, 2
/* 71EDEC 802A179C 02028021 */  addu      $s0, $s0, $v0
/* 71EDF0 802A17A0 00108080 */  sll       $s0, $s0, 2
/* 71EDF4 802A17A4 2610022C */  addiu     $s0, $s0, 0x22c
/* 71EDF8 802A17A8 02708021 */  addu      $s0, $s3, $s0
/* 71EDFC 802A17AC 0C09A75B */  jal       get_actor
/* 71EE00 802A17B0 86040000 */   lh       $a0, ($s0)
/* 71EE04 802A17B4 0040882D */  daddu     $s1, $v0, $zero
/* 71EE08 802A17B8 86050002 */  lh        $a1, 2($s0)
/* 71EE0C 802A17BC 0C099117 */  jal       get_actor_part
/* 71EE10 802A17C0 0220202D */   daddu    $a0, $s1, $zero
/* 71EE14 802A17C4 82230218 */  lb        $v1, 0x218($s1)
/* 71EE18 802A17C8 1460000A */  bnez      $v1, .L802A17F4
/* 71EE1C 802A17CC 00000000 */   nop      
/* 71EE20 802A17D0 8C42007C */  lw        $v0, 0x7c($v0)
/* 71EE24 802A17D4 30420020 */  andi      $v0, $v0, 0x20
/* 71EE28 802A17D8 14400006 */  bnez      $v0, .L802A17F4
/* 71EE2C 802A17DC 00000000 */   nop      
/* 71EE30 802A17E0 C62C018C */  lwc1      $f12, 0x18c($s1)
/* 71EE34 802A17E4 46146300 */  add.s     $f12, $f12, $f20
/* 71EE38 802A17E8 0C00A6C9 */  jal       clamp_angle
/* 71EE3C 802A17EC E62C018C */   swc1     $f12, 0x18c($s1)
/* 71EE40 802A17F0 E620018C */  swc1      $f0, 0x18c($s1)
.L802A17F4:
/* 71EE44 802A17F4 8262040C */  lb        $v0, 0x40c($s3)
/* 71EE48 802A17F8 26520001 */  addiu     $s2, $s2, 1
/* 71EE4C 802A17FC 0242102A */  slt       $v0, $s2, $v0
/* 71EE50 802A1800 1440FFE4 */  bnez      $v0, .L802A1794
/* 71EE54 802A1804 02721021 */   addu     $v0, $s3, $s2
.L802A1808:
/* 71EE58 802A1808 8E820074 */  lw        $v0, 0x74($s4)
/* 71EE5C 802A180C 14400003 */  bnez      $v0, .L802A181C
/* 71EE60 802A1810 2442FFFF */   addiu    $v0, $v0, -1
/* 71EE64 802A1814 080A8609 */  j         .L802A1824
/* 71EE68 802A1818 24020002 */   addiu    $v0, $zero, 2
.L802A181C:
/* 71EE6C 802A181C AE820074 */  sw        $v0, 0x74($s4)
/* 71EE70 802A1820 0000102D */  daddu     $v0, $zero, $zero
.L802A1824:
/* 71EE74 802A1824 8FBF0024 */  lw        $ra, 0x24($sp)
/* 71EE78 802A1828 8FB40020 */  lw        $s4, 0x20($sp)
/* 71EE7C 802A182C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 71EE80 802A1830 8FB20018 */  lw        $s2, 0x18($sp)
/* 71EE84 802A1834 8FB10014 */  lw        $s1, 0x14($sp)
/* 71EE88 802A1838 8FB00010 */  lw        $s0, 0x10($sp)
/* 71EE8C 802A183C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 71EE90 802A1840 03E00008 */  jr        $ra
/* 71EE94 802A1844 27BD0030 */   addiu    $sp, $sp, 0x30
