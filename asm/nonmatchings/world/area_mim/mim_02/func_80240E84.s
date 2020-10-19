.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E84
/* B98A84 80240E84 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B98A88 80240E88 AFB10014 */  sw        $s1, 0x14($sp)
/* B98A8C 80240E8C 0080882D */  daddu     $s1, $a0, $zero
/* B98A90 80240E90 AFBF0018 */  sw        $ra, 0x18($sp)
/* B98A94 80240E94 AFB00010 */  sw        $s0, 0x10($sp)
/* B98A98 80240E98 8E30000C */  lw        $s0, 0xc($s1)
/* B98A9C 80240E9C 8E050000 */  lw        $a1, ($s0)
/* B98AA0 80240EA0 0C0B1EAF */  jal       get_variable
/* B98AA4 80240EA4 26100004 */   addiu    $s0, $s0, 4
/* B98AA8 80240EA8 0C00EAD2 */  jal       get_npc_safe
/* B98AAC 80240EAC 0040202D */   daddu    $a0, $v0, $zero
/* B98AB0 80240EB0 10400005 */  beqz      $v0, .L80240EC8
/* B98AB4 80240EB4 00000000 */   nop      
/* B98AB8 80240EB8 8E050000 */  lw        $a1, ($s0)
/* B98ABC 80240EBC 844600A8 */  lh        $a2, 0xa8($v0)
/* B98AC0 80240EC0 0C0B2026 */  jal       set_variable
/* B98AC4 80240EC4 0220202D */   daddu    $a0, $s1, $zero
.L80240EC8:
/* B98AC8 80240EC8 8FBF0018 */  lw        $ra, 0x18($sp)
/* B98ACC 80240ECC 8FB10014 */  lw        $s1, 0x14($sp)
/* B98AD0 80240ED0 8FB00010 */  lw        $s0, 0x10($sp)
/* B98AD4 80240ED4 24020002 */  addiu     $v0, $zero, 2
/* B98AD8 80240ED8 03E00008 */  jr        $ra
/* B98ADC 80240EDC 27BD0020 */   addiu    $sp, $sp, 0x20
