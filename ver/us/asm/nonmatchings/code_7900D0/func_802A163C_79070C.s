.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A163C_79070C
/* 79070C 802A163C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 790710 802A1640 AFB20018 */  sw        $s2, 0x18($sp)
/* 790714 802A1644 0080902D */  daddu     $s2, $a0, $zero
/* 790718 802A1648 AFBF001C */  sw        $ra, 0x1c($sp)
/* 79071C 802A164C AFB10014 */  sw        $s1, 0x14($sp)
/* 790720 802A1650 AFB00010 */  sw        $s0, 0x10($sp)
/* 790724 802A1654 0C09A75B */  jal       get_actor
/* 790728 802A1658 8E440148 */   lw       $a0, 0x148($s2)
/* 79072C 802A165C 0040802D */  daddu     $s0, $v0, $zero
/* 790730 802A1660 0C09A75B */  jal       get_actor
/* 790734 802A1664 86040428 */   lh       $a0, 0x428($s0)
/* 790738 802A1668 0040882D */  daddu     $s1, $v0, $zero
/* 79073C 802A166C 82050426 */  lb        $a1, 0x426($s0)
/* 790740 802A1670 0C099117 */  jal       get_actor_part
/* 790744 802A1674 0220202D */   daddu    $a0, $s1, $zero
/* 790748 802A1678 AE400084 */  sw        $zero, 0x84($s2)
/* 79074C 802A167C 8E310000 */  lw        $s1, ($s1)
/* 790750 802A1680 0040182D */  daddu     $v1, $v0, $zero
/* 790754 802A1684 32224000 */  andi      $v0, $s1, 0x4000
/* 790758 802A1688 14400014 */  bnez      $v0, .L802A16DC
/* 79075C 802A168C 24020002 */   addiu    $v0, $zero, 2
/* 790760 802A1690 3C020040 */  lui       $v0, 0x40
/* 790764 802A1694 02221024 */  and       $v0, $s1, $v0
/* 790768 802A1698 14400010 */  bnez      $v0, .L802A16DC
/* 79076C 802A169C 24020002 */   addiu    $v0, $zero, 2
/* 790770 802A16A0 32222000 */  andi      $v0, $s1, 0x2000
/* 790774 802A16A4 1440000D */  bnez      $v0, .L802A16DC
/* 790778 802A16A8 24020002 */   addiu    $v0, $zero, 2
/* 79077C 802A16AC 8C63007C */  lw        $v1, 0x7c($v1)
/* 790780 802A16B0 3C020004 */  lui       $v0, 4
/* 790784 802A16B4 00621024 */  and       $v0, $v1, $v0
/* 790788 802A16B8 14400008 */  bnez      $v0, .L802A16DC
/* 79078C 802A16BC 24020002 */   addiu    $v0, $zero, 2
/* 790790 802A16C0 3C020008 */  lui       $v0, 8
/* 790794 802A16C4 00621024 */  and       $v0, $v1, $v0
/* 790798 802A16C8 14400004 */  bnez      $v0, .L802A16DC
/* 79079C 802A16CC 24020002 */   addiu    $v0, $zero, 2
/* 7907A0 802A16D0 24020001 */  addiu     $v0, $zero, 1
/* 7907A4 802A16D4 AE420084 */  sw        $v0, 0x84($s2)
/* 7907A8 802A16D8 24020002 */  addiu     $v0, $zero, 2
.L802A16DC:
/* 7907AC 802A16DC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7907B0 802A16E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 7907B4 802A16E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 7907B8 802A16E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7907BC 802A16EC 03E00008 */  jr        $ra
/* 7907C0 802A16F0 27BD0020 */   addiu    $sp, $sp, 0x20
