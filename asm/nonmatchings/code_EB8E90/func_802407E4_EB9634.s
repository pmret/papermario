.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407E4_EB9634
/* EB9634 802407E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB9638 802407E8 AFB00010 */  sw        $s0, 0x10($sp)
/* EB963C 802407EC 0080802D */  daddu     $s0, $a0, $zero
/* EB9640 802407F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* EB9644 802407F4 8E020148 */  lw        $v0, 0x148($s0)
/* EB9648 802407F8 0C00F92F */  jal       func_8003E4BC
/* EB964C 802407FC 84440008 */   lh       $a0, 8($v0)
/* EB9650 80240800 0040202D */  daddu     $a0, $v0, $zero
/* EB9654 80240804 C482003C */  lwc1      $f2, 0x3c($a0)
/* EB9658 80240808 C480001C */  lwc1      $f0, 0x1c($a0)
/* EB965C 8024080C 46001080 */  add.s     $f2, $f2, $f0
/* EB9660 80240810 C4840014 */  lwc1      $f4, 0x14($a0)
/* EB9664 80240814 46040001 */  sub.s     $f0, $f0, $f4
/* EB9668 80240818 C4840064 */  lwc1      $f4, 0x64($a0)
/* EB966C 8024081C 4602203C */  c.lt.s    $f4, $f2
/* EB9670 80240820 E482003C */  swc1      $f2, 0x3c($a0)
/* EB9674 80240824 45010009 */  bc1t      .L8024084C
/* EB9678 80240828 E480001C */   swc1     $f0, 0x1c($a0)
/* EB967C 8024082C 8C820000 */  lw        $v0, ($a0)
/* EB9680 80240830 2403F7FF */  addiu     $v1, $zero, -0x801
/* EB9684 80240834 E484003C */  swc1      $f4, 0x3c($a0)
/* EB9688 80240838 AC80001C */  sw        $zero, 0x1c($a0)
/* EB968C 8024083C 00431024 */  and       $v0, $v0, $v1
/* EB9690 80240840 AC820000 */  sw        $v0, ($a0)
/* EB9694 80240844 2402000C */  addiu     $v0, $zero, 0xc
/* EB9698 80240848 AE020070 */  sw        $v0, 0x70($s0)
.L8024084C:
/* EB969C 8024084C 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB96A0 80240850 8FB00010 */  lw        $s0, 0x10($sp)
/* EB96A4 80240854 03E00008 */  jr        $ra
/* EB96A8 80240858 27BD0018 */   addiu    $sp, $sp, 0x18
