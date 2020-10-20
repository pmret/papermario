.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024181C_B5FACC
/* B5FACC 8024181C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5FAD0 80241820 AFB10014 */  sw        $s1, 0x14($sp)
/* B5FAD4 80241824 0080882D */  daddu     $s1, $a0, $zero
/* B5FAD8 80241828 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5FADC 8024182C AFB00010 */  sw        $s0, 0x10($sp)
/* B5FAE0 80241830 8E300148 */  lw        $s0, 0x148($s1)
/* B5FAE4 80241834 0C00EABB */  jal       get_npc_unsafe
/* B5FAE8 80241838 86040008 */   lh       $a0, 8($s0)
/* B5FAEC 8024183C 9443008E */  lhu       $v1, 0x8e($v0)
/* B5FAF0 80241840 2463FFFF */  addiu     $v1, $v1, -1
/* B5FAF4 80241844 A443008E */  sh        $v1, 0x8e($v0)
/* B5FAF8 80241848 00031C00 */  sll       $v1, $v1, 0x10
/* B5FAFC 8024184C 1C600003 */  bgtz      $v1, .L8024185C
/* B5FB00 80241850 2402000C */   addiu    $v0, $zero, 0xc
/* B5FB04 80241854 AE00006C */  sw        $zero, 0x6c($s0)
/* B5FB08 80241858 AE220070 */  sw        $v0, 0x70($s1)
.L8024185C:
/* B5FB0C 8024185C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5FB10 80241860 8FB10014 */  lw        $s1, 0x14($sp)
/* B5FB14 80241864 8FB00010 */  lw        $s0, 0x10($sp)
/* B5FB18 80241868 03E00008 */  jr        $ra
/* B5FB1C 8024186C 27BD0020 */   addiu    $sp, $sp, 0x20
