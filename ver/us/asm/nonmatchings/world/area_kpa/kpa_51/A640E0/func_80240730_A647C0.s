.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_A647C0
/* A647C0 80240730 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A647C4 80240734 AFB10014 */  sw        $s1, 0x14($sp)
/* A647C8 80240738 0080882D */  daddu     $s1, $a0, $zero
/* A647CC 8024073C AFBF0018 */  sw        $ra, 0x18($sp)
/* A647D0 80240740 AFB00010 */  sw        $s0, 0x10($sp)
/* A647D4 80240744 8E300148 */  lw        $s0, 0x148($s1)
/* A647D8 80240748 0C00EABB */  jal       get_npc_unsafe
/* A647DC 8024074C 86040008 */   lh       $a0, 8($s0)
/* A647E0 80240750 0040282D */  daddu     $a1, $v0, $zero
/* A647E4 80240754 94A2008E */  lhu       $v0, 0x8e($a1)
/* A647E8 80240758 2442FFFF */  addiu     $v0, $v0, -1
/* A647EC 8024075C A4A2008E */  sh        $v0, 0x8e($a1)
/* A647F0 80240760 00021400 */  sll       $v0, $v0, 0x10
/* A647F4 80240764 1C40000A */  bgtz      $v0, .L80240790
/* A647F8 80240768 2404FFFD */   addiu    $a0, $zero, -3
/* A647FC 8024076C 8E0300CC */  lw        $v1, 0xcc($s0)
/* A64800 80240770 8CA20000 */  lw        $v0, ($a1)
/* A64804 80240774 8C630000 */  lw        $v1, ($v1)
/* A64808 80240778 00441024 */  and       $v0, $v0, $a0
/* A6480C 8024077C ACA20000 */  sw        $v0, ($a1)
/* A64810 80240780 24020001 */  addiu     $v0, $zero, 1
/* A64814 80240784 A4A0008E */  sh        $zero, 0x8e($a1)
/* A64818 80240788 ACA30028 */  sw        $v1, 0x28($a1)
/* A6481C 8024078C AE220070 */  sw        $v0, 0x70($s1)
.L80240790:
/* A64820 80240790 8FBF0018 */  lw        $ra, 0x18($sp)
/* A64824 80240794 8FB10014 */  lw        $s1, 0x14($sp)
/* A64828 80240798 8FB00010 */  lw        $s0, 0x10($sp)
/* A6482C 8024079C 03E00008 */  jr        $ra
/* A64830 802407A0 27BD0020 */   addiu    $sp, $sp, 0x20
