.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407E4_C9E704
/* C9E704 802407E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9E708 802407E8 AFB00010 */  sw        $s0, 0x10($sp)
/* C9E70C 802407EC 0080802D */  daddu     $s0, $a0, $zero
/* C9E710 802407F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C9E714 802407F4 8E020148 */  lw        $v0, 0x148($s0)
/* C9E718 802407F8 0C00EABB */  jal       get_npc_unsafe
/* C9E71C 802407FC 84440008 */   lh       $a0, 8($v0)
/* C9E720 80240800 0040202D */  daddu     $a0, $v0, $zero
/* C9E724 80240804 C482003C */  lwc1      $f2, 0x3c($a0)
/* C9E728 80240808 C480001C */  lwc1      $f0, 0x1c($a0)
/* C9E72C 8024080C 46001080 */  add.s     $f2, $f2, $f0
/* C9E730 80240810 C4840014 */  lwc1      $f4, 0x14($a0)
/* C9E734 80240814 46040001 */  sub.s     $f0, $f0, $f4
/* C9E738 80240818 C4840064 */  lwc1      $f4, 0x64($a0)
/* C9E73C 8024081C 4602203C */  c.lt.s    $f4, $f2
/* C9E740 80240820 E482003C */  swc1      $f2, 0x3c($a0)
/* C9E744 80240824 45010009 */  bc1t      .L8024084C
/* C9E748 80240828 E480001C */   swc1     $f0, 0x1c($a0)
/* C9E74C 8024082C 8C820000 */  lw        $v0, ($a0)
/* C9E750 80240830 2403F7FF */  addiu     $v1, $zero, -0x801
/* C9E754 80240834 E484003C */  swc1      $f4, 0x3c($a0)
/* C9E758 80240838 AC80001C */  sw        $zero, 0x1c($a0)
/* C9E75C 8024083C 00431024 */  and       $v0, $v0, $v1
/* C9E760 80240840 AC820000 */  sw        $v0, ($a0)
/* C9E764 80240844 2402000C */  addiu     $v0, $zero, 0xc
/* C9E768 80240848 AE020070 */  sw        $v0, 0x70($s0)
.L8024084C:
/* C9E76C 8024084C 8FBF0014 */  lw        $ra, 0x14($sp)
/* C9E770 80240850 8FB00010 */  lw        $s0, 0x10($sp)
/* C9E774 80240854 03E00008 */  jr        $ra
/* C9E778 80240858 27BD0018 */   addiu    $sp, $sp, 0x18
