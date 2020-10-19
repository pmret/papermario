.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429A4
/* 9D99C4 802429A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D99C8 802429A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D99CC 802429AC 0080882D */  daddu     $s1, $a0, $zero
/* 9D99D0 802429B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D99D4 802429B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D99D8 802429B8 8E30000C */  lw        $s0, 0xc($s1)
/* 9D99DC 802429BC 8E050000 */  lw        $a1, ($s0)
/* 9D99E0 802429C0 0C0B1EAF */  jal       get_variable
/* 9D99E4 802429C4 26100004 */   addiu    $s0, $s0, 4
/* 9D99E8 802429C8 0C00EAD2 */  jal       get_npc_safe
/* 9D99EC 802429CC 0040202D */   daddu    $a0, $v0, $zero
/* 9D99F0 802429D0 10400005 */  beqz      $v0, .L802429E8
/* 9D99F4 802429D4 00000000 */   nop      
/* 9D99F8 802429D8 8E050000 */  lw        $a1, ($s0)
/* 9D99FC 802429DC 844600A8 */  lh        $a2, 0xa8($v0)
/* 9D9A00 802429E0 0C0B2026 */  jal       set_variable
/* 9D9A04 802429E4 0220202D */   daddu    $a0, $s1, $zero
.L802429E8:
/* 9D9A08 802429E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D9A0C 802429EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9A10 802429F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9A14 802429F4 24020002 */  addiu     $v0, $zero, 2
/* 9D9A18 802429F8 03E00008 */  jr        $ra
/* 9D9A1C 802429FC 27BD0020 */   addiu    $sp, $sp, 0x20
