.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400DC
/* BA080C 802400DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA0810 802400E0 AFB10014 */  sw        $s1, 0x14($sp)
/* BA0814 802400E4 0080882D */  daddu     $s1, $a0, $zero
/* BA0818 802400E8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA081C 802400EC AFB00010 */  sw        $s0, 0x10($sp)
/* BA0820 802400F0 8E300148 */  lw        $s0, 0x148($s1)
/* BA0824 802400F4 0C00EABB */  jal       get_npc_unsafe
/* BA0828 802400F8 86040008 */   lh       $a0, 8($s0)
/* BA082C 802400FC 0040202D */  daddu     $a0, $v0, $zero
/* BA0830 80240100 9482008E */  lhu       $v0, 0x8e($a0)
/* BA0834 80240104 2442FFFF */  addiu     $v0, $v0, -1
/* BA0838 80240108 A482008E */  sh        $v0, 0x8e($a0)
/* BA083C 8024010C 00021400 */  sll       $v0, $v0, 0x10
/* BA0840 80240110 1C400009 */  bgtz      $v0, .L80240138
/* BA0844 80240114 24020003 */   addiu    $v0, $zero, 3
/* BA0848 80240118 96030076 */  lhu       $v1, 0x76($s0)
/* BA084C 8024011C AE02006C */  sw        $v0, 0x6c($s0)
/* BA0850 80240120 A483008E */  sh        $v1, 0x8e($a0)
/* BA0854 80240124 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA0858 80240128 8C420024 */  lw        $v0, 0x24($v0)
/* BA085C 8024012C AC820028 */  sw        $v0, 0x28($a0)
/* BA0860 80240130 24020020 */  addiu     $v0, $zero, 0x20
/* BA0864 80240134 AE220070 */  sw        $v0, 0x70($s1)
.L80240138:
/* BA0868 80240138 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA086C 8024013C 8FB10014 */  lw        $s1, 0x14($sp)
/* BA0870 80240140 8FB00010 */  lw        $s0, 0x10($sp)
/* BA0874 80240144 03E00008 */  jr        $ra
/* BA0878 80240148 27BD0020 */   addiu    $sp, $sp, 0x20
