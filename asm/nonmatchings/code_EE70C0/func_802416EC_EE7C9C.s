.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416EC_EE7C9C
/* EE7C9C 802416EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE7CA0 802416F0 AFB20018 */  sw        $s2, 0x18($sp)
/* EE7CA4 802416F4 0080902D */  daddu     $s2, $a0, $zero
/* EE7CA8 802416F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* EE7CAC 802416FC AFB10014 */  sw        $s1, 0x14($sp)
/* EE7CB0 80241700 AFB00010 */  sw        $s0, 0x10($sp)
/* EE7CB4 80241704 8E510148 */  lw        $s1, 0x148($s2)
/* EE7CB8 80241708 0C00F92F */  jal       func_8003E4BC
/* EE7CBC 8024170C 86240008 */   lh       $a0, 8($s1)
/* EE7CC0 80241710 0040802D */  daddu     $s0, $v0, $zero
/* EE7CC4 80241714 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EE7CC8 80241718 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EE7CCC 8024171C C60C0038 */  lwc1      $f12, 0x38($s0)
/* EE7CD0 80241720 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EE7CD4 80241724 A600008E */  sh        $zero, 0x8e($s0)
/* EE7CD8 80241728 8C460028 */  lw        $a2, 0x28($v0)
/* EE7CDC 8024172C 0C00ABDC */  jal       fio_validate_header_checksums
/* EE7CE0 80241730 8C470030 */   lw       $a3, 0x30($v0)
/* EE7CE4 80241734 E600000C */  swc1      $f0, 0xc($s0)
/* EE7CE8 80241738 8E2200CC */  lw        $v0, 0xcc($s1)
/* EE7CEC 8024173C 8C420020 */  lw        $v0, 0x20($v0)
/* EE7CF0 80241740 AE020028 */  sw        $v0, 0x28($s0)
/* EE7CF4 80241744 2402000B */  addiu     $v0, $zero, 0xb
/* EE7CF8 80241748 AE420070 */  sw        $v0, 0x70($s2)
/* EE7CFC 8024174C 8FBF001C */  lw        $ra, 0x1c($sp)
/* EE7D00 80241750 8FB20018 */  lw        $s2, 0x18($sp)
/* EE7D04 80241754 8FB10014 */  lw        $s1, 0x14($sp)
/* EE7D08 80241758 8FB00010 */  lw        $s0, 0x10($sp)
/* EE7D0C 8024175C 03E00008 */  jr        $ra
/* EE7D10 80241760 27BD0020 */   addiu    $sp, $sp, 0x20
