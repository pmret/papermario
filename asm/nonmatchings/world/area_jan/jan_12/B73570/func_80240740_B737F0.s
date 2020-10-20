.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240740_B737F0
/* B737F0 80240740 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B737F4 80240744 AFB10014 */  sw        $s1, 0x14($sp)
/* B737F8 80240748 0080882D */  daddu     $s1, $a0, $zero
/* B737FC 8024074C AFBF0018 */  sw        $ra, 0x18($sp)
/* B73800 80240750 AFB00010 */  sw        $s0, 0x10($sp)
/* B73804 80240754 8E300148 */  lw        $s0, 0x148($s1)
/* B73808 80240758 0C00EABB */  jal       get_npc_unsafe
/* B7380C 8024075C 86040008 */   lh       $a0, 8($s0)
/* B73810 80240760 0040202D */  daddu     $a0, $v0, $zero
/* B73814 80240764 9482008E */  lhu       $v0, 0x8e($a0)
/* B73818 80240768 2442FFFF */  addiu     $v0, $v0, -1
/* B7381C 8024076C A482008E */  sh        $v0, 0x8e($a0)
/* B73820 80240770 00021400 */  sll       $v0, $v0, 0x10
/* B73824 80240774 1C400009 */  bgtz      $v0, .L8024079C
/* B73828 80240778 24020003 */   addiu    $v0, $zero, 3
/* B7382C 8024077C 96030076 */  lhu       $v1, 0x76($s0)
/* B73830 80240780 AE02006C */  sw        $v0, 0x6c($s0)
/* B73834 80240784 A483008E */  sh        $v1, 0x8e($a0)
/* B73838 80240788 8E0200CC */  lw        $v0, 0xcc($s0)
/* B7383C 8024078C 8C420024 */  lw        $v0, 0x24($v0)
/* B73840 80240790 AC820028 */  sw        $v0, 0x28($a0)
/* B73844 80240794 24020020 */  addiu     $v0, $zero, 0x20
/* B73848 80240798 AE220070 */  sw        $v0, 0x70($s1)
.L8024079C:
/* B7384C 8024079C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B73850 802407A0 8FB10014 */  lw        $s1, 0x14($sp)
/* B73854 802407A4 8FB00010 */  lw        $s0, 0x10($sp)
/* B73858 802407A8 03E00008 */  jr        $ra
/* B7385C 802407AC 27BD0020 */   addiu    $sp, $sp, 0x20
