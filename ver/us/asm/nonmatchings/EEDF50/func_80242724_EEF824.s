.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242724_EEF824
/* EEF824 80242724 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEF828 80242728 AFB10014 */  sw        $s1, 0x14($sp)
/* EEF82C 8024272C 0080882D */  daddu     $s1, $a0, $zero
/* EEF830 80242730 AFBF0018 */  sw        $ra, 0x18($sp)
/* EEF834 80242734 AFB00010 */  sw        $s0, 0x10($sp)
/* EEF838 80242738 8E300148 */  lw        $s0, 0x148($s1)
/* EEF83C 8024273C 0C00F92F */  jal       dead_get_npc_unsafe
/* EEF840 80242740 86040008 */   lh       $a0, 8($s0)
/* EEF844 80242744 0040182D */  daddu     $v1, $v0, $zero
/* EEF848 80242748 9462008E */  lhu       $v0, 0x8e($v1)
/* EEF84C 8024274C 2442FFFF */  addiu     $v0, $v0, -1
/* EEF850 80242750 A462008E */  sh        $v0, 0x8e($v1)
/* EEF854 80242754 00021400 */  sll       $v0, $v0, 0x10
/* EEF858 80242758 1C400004 */  bgtz      $v0, .L8024276C
/* EEF85C 8024275C 00000000 */   nop
/* EEF860 80242760 AE000074 */  sw        $zero, 0x74($s0)
/* EEF864 80242764 A460008E */  sh        $zero, 0x8e($v1)
/* EEF868 80242768 AE200070 */  sw        $zero, 0x70($s1)
.L8024276C:
/* EEF86C 8024276C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EEF870 80242770 8FB10014 */  lw        $s1, 0x14($sp)
/* EEF874 80242774 8FB00010 */  lw        $s0, 0x10($sp)
/* EEF878 80242778 03E00008 */  jr        $ra
/* EEF87C 8024277C 27BD0020 */   addiu    $sp, $sp, 0x20
