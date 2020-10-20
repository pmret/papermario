.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417AC_B3637C
/* B3637C 802417AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B36380 802417B0 AFB10014 */  sw        $s1, 0x14($sp)
/* B36384 802417B4 0080882D */  daddu     $s1, $a0, $zero
/* B36388 802417B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* B3638C 802417BC AFB00010 */  sw        $s0, 0x10($sp)
/* B36390 802417C0 8E30000C */  lw        $s0, 0xc($s1)
/* B36394 802417C4 8E050000 */  lw        $a1, ($s0)
/* B36398 802417C8 0C0B1EAF */  jal       get_variable
/* B3639C 802417CC 26100004 */   addiu    $s0, $s0, 4
/* B363A0 802417D0 0C00EAD2 */  jal       get_npc_safe
/* B363A4 802417D4 0040202D */   daddu    $a0, $v0, $zero
/* B363A8 802417D8 10400005 */  beqz      $v0, .L802417F0
/* B363AC 802417DC 00000000 */   nop      
/* B363B0 802417E0 8E050000 */  lw        $a1, ($s0)
/* B363B4 802417E4 844600A8 */  lh        $a2, 0xa8($v0)
/* B363B8 802417E8 0C0B2026 */  jal       set_variable
/* B363BC 802417EC 0220202D */   daddu    $a0, $s1, $zero
.L802417F0:
/* B363C0 802417F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B363C4 802417F4 8FB10014 */  lw        $s1, 0x14($sp)
/* B363C8 802417F8 8FB00010 */  lw        $s0, 0x10($sp)
/* B363CC 802417FC 24020002 */  addiu     $v0, $zero, 2
/* B363D0 80241800 03E00008 */  jr        $ra
/* B363D4 80241804 27BD0020 */   addiu    $sp, $sp, 0x20
