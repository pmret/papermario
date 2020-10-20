.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802420E4_C5C824
/* C5C824 802420E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5C828 802420E8 AFB10014 */  sw        $s1, 0x14($sp)
/* C5C82C 802420EC 0080882D */  daddu     $s1, $a0, $zero
/* C5C830 802420F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C5C834 802420F4 AFB00010 */  sw        $s0, 0x10($sp)
/* C5C838 802420F8 8E30000C */  lw        $s0, 0xc($s1)
/* C5C83C 802420FC 8E050000 */  lw        $a1, ($s0)
/* C5C840 80242100 0C0B1EAF */  jal       get_variable
/* C5C844 80242104 26100004 */   addiu    $s0, $s0, 4
/* C5C848 80242108 0C00EAD2 */  jal       get_npc_safe
/* C5C84C 8024210C 0040202D */   daddu    $a0, $v0, $zero
/* C5C850 80242110 10400005 */  beqz      $v0, .L80242128
/* C5C854 80242114 00000000 */   nop      
/* C5C858 80242118 8E050000 */  lw        $a1, ($s0)
/* C5C85C 8024211C 844600A8 */  lh        $a2, 0xa8($v0)
/* C5C860 80242120 0C0B2026 */  jal       set_variable
/* C5C864 80242124 0220202D */   daddu    $a0, $s1, $zero
.L80242128:
/* C5C868 80242128 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5C86C 8024212C 8FB10014 */  lw        $s1, 0x14($sp)
/* C5C870 80242130 8FB00010 */  lw        $s0, 0x10($sp)
/* C5C874 80242134 24020002 */  addiu     $v0, $zero, 2
/* C5C878 80242138 03E00008 */  jr        $ra
/* C5C87C 8024213C 27BD0020 */   addiu    $sp, $sp, 0x20
