.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241744_CB0484
/* CB0484 80241744 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CB0488 80241748 AFB10014 */  sw        $s1, 0x14($sp)
/* CB048C 8024174C 0080882D */  daddu     $s1, $a0, $zero
/* CB0490 80241750 AFBF0018 */  sw        $ra, 0x18($sp)
/* CB0494 80241754 AFB00010 */  sw        $s0, 0x10($sp)
/* CB0498 80241758 8E30000C */  lw        $s0, 0xc($s1)
/* CB049C 8024175C 8E050000 */  lw        $a1, ($s0)
/* CB04A0 80241760 0C0B1EAF */  jal       get_variable
/* CB04A4 80241764 26100004 */   addiu    $s0, $s0, 4
/* CB04A8 80241768 0C00EAD2 */  jal       get_npc_safe
/* CB04AC 8024176C 0040202D */   daddu    $a0, $v0, $zero
/* CB04B0 80241770 10400005 */  beqz      $v0, .L80241788
/* CB04B4 80241774 00000000 */   nop      
/* CB04B8 80241778 8E050000 */  lw        $a1, ($s0)
/* CB04BC 8024177C 844600A8 */  lh        $a2, 0xa8($v0)
/* CB04C0 80241780 0C0B2026 */  jal       set_variable
/* CB04C4 80241784 0220202D */   daddu    $a0, $s1, $zero
.L80241788:
/* CB04C8 80241788 8FBF0018 */  lw        $ra, 0x18($sp)
/* CB04CC 8024178C 8FB10014 */  lw        $s1, 0x14($sp)
/* CB04D0 80241790 8FB00010 */  lw        $s0, 0x10($sp)
/* CB04D4 80241794 24020002 */  addiu     $v0, $zero, 2
/* CB04D8 80241798 03E00008 */  jr        $ra
/* CB04DC 8024179C 27BD0020 */   addiu    $sp, $sp, 0x20
