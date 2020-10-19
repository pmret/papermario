.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_D138E0
/* D138E0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D138E4 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* D138E8 80240318 0080882D */  daddu     $s1, $a0, $zero
/* D138EC 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* D138F0 80240320 AFB00010 */  sw        $s0, 0x10($sp)
/* D138F4 80240324 8E30000C */  lw        $s0, 0xc($s1)
/* D138F8 80240328 8E050000 */  lw        $a1, ($s0)
/* D138FC 8024032C 0C0B1EAF */  jal       get_variable
/* D13900 80240330 26100004 */   addiu    $s0, $s0, 4
/* D13904 80240334 0C00EAD2 */  jal       get_npc_safe
/* D13908 80240338 0040202D */   daddu    $a0, $v0, $zero
/* D1390C 8024033C 10400005 */  beqz      $v0, .L80240354
/* D13910 80240340 00000000 */   nop      
/* D13914 80240344 8E050000 */  lw        $a1, ($s0)
/* D13918 80240348 844600A8 */  lh        $a2, 0xa8($v0)
/* D1391C 8024034C 0C0B2026 */  jal       set_variable
/* D13920 80240350 0220202D */   daddu    $a0, $s1, $zero
.L80240354:
/* D13924 80240354 8FBF0018 */  lw        $ra, 0x18($sp)
/* D13928 80240358 8FB10014 */  lw        $s1, 0x14($sp)
/* D1392C 8024035C 8FB00010 */  lw        $s0, 0x10($sp)
/* D13930 80240360 24020002 */  addiu     $v0, $zero, 2
/* D13934 80240364 03E00008 */  jr        $ra
/* D13938 80240368 27BD0020 */   addiu    $sp, $sp, 0x20
