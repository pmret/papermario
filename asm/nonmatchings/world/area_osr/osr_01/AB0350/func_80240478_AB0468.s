.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240478_AB0468
/* AB0468 80240478 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB046C 8024047C AFB10014 */  sw        $s1, 0x14($sp)
/* AB0470 80240480 0080882D */  daddu     $s1, $a0, $zero
/* AB0474 80240484 AFBF0018 */  sw        $ra, 0x18($sp)
/* AB0478 80240488 AFB00010 */  sw        $s0, 0x10($sp)
/* AB047C 8024048C 8E30000C */  lw        $s0, 0xc($s1)
/* AB0480 80240490 8E050000 */  lw        $a1, ($s0)
/* AB0484 80240494 0C0B1EAF */  jal       get_variable
/* AB0488 80240498 26100004 */   addiu    $s0, $s0, 4
/* AB048C 8024049C 0C00EAD2 */  jal       get_npc_safe
/* AB0490 802404A0 0040202D */   daddu    $a0, $v0, $zero
/* AB0494 802404A4 10400005 */  beqz      $v0, .L802404BC
/* AB0498 802404A8 00000000 */   nop      
/* AB049C 802404AC 8E050000 */  lw        $a1, ($s0)
/* AB04A0 802404B0 844600A8 */  lh        $a2, 0xa8($v0)
/* AB04A4 802404B4 0C0B2026 */  jal       set_variable
/* AB04A8 802404B8 0220202D */   daddu    $a0, $s1, $zero
.L802404BC:
/* AB04AC 802404BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB04B0 802404C0 8FB10014 */  lw        $s1, 0x14($sp)
/* AB04B4 802404C4 8FB00010 */  lw        $s0, 0x10($sp)
/* AB04B8 802404C8 24020002 */  addiu     $v0, $zero, 2
/* AB04BC 802404CC 03E00008 */  jr        $ra
/* AB04C0 802404D0 27BD0020 */   addiu    $sp, $sp, 0x20
