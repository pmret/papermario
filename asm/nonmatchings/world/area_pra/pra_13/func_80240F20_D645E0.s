.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D65500
/* D65500 80240F20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D65504 80240F24 AFB10014 */  sw        $s1, 0x14($sp)
/* D65508 80240F28 0080882D */  daddu     $s1, $a0, $zero
/* D6550C 80240F2C AFBF0018 */  sw        $ra, 0x18($sp)
/* D65510 80240F30 AFB00010 */  sw        $s0, 0x10($sp)
/* D65514 80240F34 8E30000C */  lw        $s0, 0xc($s1)
/* D65518 80240F38 8E050000 */  lw        $a1, ($s0)
/* D6551C 80240F3C 0C0B1EAF */  jal       get_variable
/* D65520 80240F40 26100004 */   addiu    $s0, $s0, 4
/* D65524 80240F44 0C00EAD2 */  jal       get_npc_safe
/* D65528 80240F48 0040202D */   daddu    $a0, $v0, $zero
/* D6552C 80240F4C 10400005 */  beqz      $v0, .L80240F64
/* D65530 80240F50 00000000 */   nop      
/* D65534 80240F54 8E050000 */  lw        $a1, ($s0)
/* D65538 80240F58 844600A8 */  lh        $a2, 0xa8($v0)
/* D6553C 80240F5C 0C0B2026 */  jal       set_variable
/* D65540 80240F60 0220202D */   daddu    $a0, $s1, $zero
.L80240F64:
/* D65544 80240F64 8FBF0018 */  lw        $ra, 0x18($sp)
/* D65548 80240F68 8FB10014 */  lw        $s1, 0x14($sp)
/* D6554C 80240F6C 8FB00010 */  lw        $s0, 0x10($sp)
/* D65550 80240F70 24020002 */  addiu     $v0, $zero, 2
/* D65554 80240F74 03E00008 */  jr        $ra
/* D65558 80240F78 27BD0020 */   addiu    $sp, $sp, 0x20
