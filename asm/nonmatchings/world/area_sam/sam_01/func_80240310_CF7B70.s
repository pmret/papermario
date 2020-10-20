.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_CF7E80
/* CF7E80 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF7E84 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* CF7E88 80240318 0080882D */  daddu     $s1, $a0, $zero
/* CF7E8C 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* CF7E90 80240320 AFB00010 */  sw        $s0, 0x10($sp)
/* CF7E94 80240324 8E30000C */  lw        $s0, 0xc($s1)
/* CF7E98 80240328 8E050000 */  lw        $a1, ($s0)
/* CF7E9C 8024032C 0C0B1EAF */  jal       get_variable
/* CF7EA0 80240330 26100004 */   addiu    $s0, $s0, 4
/* CF7EA4 80240334 0C00EAD2 */  jal       get_npc_safe
/* CF7EA8 80240338 0040202D */   daddu    $a0, $v0, $zero
/* CF7EAC 8024033C 10400005 */  beqz      $v0, .L80240354
/* CF7EB0 80240340 00000000 */   nop      
/* CF7EB4 80240344 8E050000 */  lw        $a1, ($s0)
/* CF7EB8 80240348 844600A8 */  lh        $a2, 0xa8($v0)
/* CF7EBC 8024034C 0C0B2026 */  jal       set_variable
/* CF7EC0 80240350 0220202D */   daddu    $a0, $s1, $zero
.L80240354:
/* CF7EC4 80240354 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF7EC8 80240358 8FB10014 */  lw        $s1, 0x14($sp)
/* CF7ECC 8024035C 8FB00010 */  lw        $s0, 0x10($sp)
/* CF7ED0 80240360 24020002 */  addiu     $v0, $zero, 2
/* CF7ED4 80240364 03E00008 */  jr        $ra
/* CF7ED8 80240368 27BD0020 */   addiu    $sp, $sp, 0x20
