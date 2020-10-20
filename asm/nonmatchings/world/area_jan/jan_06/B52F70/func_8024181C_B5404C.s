.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024181C_B5404C
/* B5404C 8024181C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B54050 80241820 AFB10014 */  sw        $s1, 0x14($sp)
/* B54054 80241824 0080882D */  daddu     $s1, $a0, $zero
/* B54058 80241828 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5405C 8024182C AFB00010 */  sw        $s0, 0x10($sp)
/* B54060 80241830 8E300148 */  lw        $s0, 0x148($s1)
/* B54064 80241834 0C00EABB */  jal       get_npc_unsafe
/* B54068 80241838 86040008 */   lh       $a0, 8($s0)
/* B5406C 8024183C 24030001 */  addiu     $v1, $zero, 1
/* B54070 80241840 0040202D */  daddu     $a0, $v0, $zero
/* B54074 80241844 AE03006C */  sw        $v1, 0x6c($s0)
/* B54078 80241848 8482008C */  lh        $v0, 0x8c($a0)
/* B5407C 8024184C 14400009 */  bnez      $v0, .L80241874
/* B54080 80241850 24020002 */   addiu    $v0, $zero, 2
/* B54084 80241854 96030072 */  lhu       $v1, 0x72($s0)
/* B54088 80241858 AE02006C */  sw        $v0, 0x6c($s0)
/* B5408C 8024185C A483008E */  sh        $v1, 0x8e($a0)
/* B54090 80241860 8E0200CC */  lw        $v0, 0xcc($s0)
/* B54094 80241864 8C420020 */  lw        $v0, 0x20($v0)
/* B54098 80241868 AC820028 */  sw        $v0, 0x28($a0)
/* B5409C 8024186C 2402001F */  addiu     $v0, $zero, 0x1f
/* B540A0 80241870 AE220070 */  sw        $v0, 0x70($s1)
.L80241874:
/* B540A4 80241874 8FBF0018 */  lw        $ra, 0x18($sp)
/* B540A8 80241878 8FB10014 */  lw        $s1, 0x14($sp)
/* B540AC 8024187C 8FB00010 */  lw        $s0, 0x10($sp)
/* B540B0 80241880 03E00008 */  jr        $ra
/* B540B4 80241884 27BD0020 */   addiu    $sp, $sp, 0x20
