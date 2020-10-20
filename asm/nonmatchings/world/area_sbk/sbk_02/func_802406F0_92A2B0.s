.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406F0_92A9A0
/* 92A9A0 802406F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 92A9A4 802406F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 92A9A8 802406F8 0080882D */  daddu     $s1, $a0, $zero
/* 92A9AC 802406FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 92A9B0 80240700 AFB00010 */  sw        $s0, 0x10($sp)
/* 92A9B4 80240704 8E30000C */  lw        $s0, 0xc($s1)
/* 92A9B8 80240708 8E050000 */  lw        $a1, ($s0)
/* 92A9BC 8024070C 0C0B1EAF */  jal       get_variable
/* 92A9C0 80240710 26100004 */   addiu    $s0, $s0, 4
/* 92A9C4 80240714 0C00EAD2 */  jal       get_npc_safe
/* 92A9C8 80240718 0040202D */   daddu    $a0, $v0, $zero
/* 92A9CC 8024071C 10400005 */  beqz      $v0, .L80240734
/* 92A9D0 80240720 00000000 */   nop      
/* 92A9D4 80240724 8E050000 */  lw        $a1, ($s0)
/* 92A9D8 80240728 844600A8 */  lh        $a2, 0xa8($v0)
/* 92A9DC 8024072C 0C0B2026 */  jal       set_variable
/* 92A9E0 80240730 0220202D */   daddu    $a0, $s1, $zero
.L80240734:
/* 92A9E4 80240734 8FBF0018 */  lw        $ra, 0x18($sp)
/* 92A9E8 80240738 8FB10014 */  lw        $s1, 0x14($sp)
/* 92A9EC 8024073C 8FB00010 */  lw        $s0, 0x10($sp)
/* 92A9F0 80240740 24020002 */  addiu     $v0, $zero, 2
/* 92A9F4 80240744 03E00008 */  jr        $ra
/* 92A9F8 80240748 27BD0020 */   addiu    $sp, $sp, 0x20
