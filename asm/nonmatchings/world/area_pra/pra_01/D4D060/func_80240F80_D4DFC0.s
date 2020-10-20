.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F80_D4DFC0
/* D4DFC0 80240F80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D4DFC4 80240F84 AFB10014 */  sw        $s1, 0x14($sp)
/* D4DFC8 80240F88 0080882D */  daddu     $s1, $a0, $zero
/* D4DFCC 80240F8C AFBF0018 */  sw        $ra, 0x18($sp)
/* D4DFD0 80240F90 AFB00010 */  sw        $s0, 0x10($sp)
/* D4DFD4 80240F94 8E30000C */  lw        $s0, 0xc($s1)
/* D4DFD8 80240F98 8E050000 */  lw        $a1, ($s0)
/* D4DFDC 80240F9C 0C0B1EAF */  jal       get_variable
/* D4DFE0 80240FA0 26100004 */   addiu    $s0, $s0, 4
/* D4DFE4 80240FA4 0C00EAD2 */  jal       get_npc_safe
/* D4DFE8 80240FA8 0040202D */   daddu    $a0, $v0, $zero
/* D4DFEC 80240FAC 10400005 */  beqz      $v0, .L80240FC4
/* D4DFF0 80240FB0 00000000 */   nop      
/* D4DFF4 80240FB4 8E050000 */  lw        $a1, ($s0)
/* D4DFF8 80240FB8 844600A8 */  lh        $a2, 0xa8($v0)
/* D4DFFC 80240FBC 0C0B2026 */  jal       set_variable
/* D4E000 80240FC0 0220202D */   daddu    $a0, $s1, $zero
.L80240FC4:
/* D4E004 80240FC4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D4E008 80240FC8 8FB10014 */  lw        $s1, 0x14($sp)
/* D4E00C 80240FCC 8FB00010 */  lw        $s0, 0x10($sp)
/* D4E010 80240FD0 24020002 */  addiu     $v0, $zero, 2
/* D4E014 80240FD4 03E00008 */  jr        $ra
/* D4E018 80240FD8 27BD0020 */   addiu    $sp, $sp, 0x20
