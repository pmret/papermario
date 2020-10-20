.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF4
/* 9404A4 80240EF4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9404A8 80240EF8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9404AC 80240EFC 0080882D */  daddu     $s1, $a0, $zero
/* 9404B0 80240F00 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9404B4 80240F04 AFB00010 */  sw        $s0, 0x10($sp)
/* 9404B8 80240F08 8E30000C */  lw        $s0, 0xc($s1)
/* 9404BC 80240F0C 8E050000 */  lw        $a1, ($s0)
/* 9404C0 80240F10 0C0B1EAF */  jal       get_variable
/* 9404C4 80240F14 26100004 */   addiu    $s0, $s0, 4
/* 9404C8 80240F18 0C00EAD2 */  jal       get_npc_safe
/* 9404CC 80240F1C 0040202D */   daddu    $a0, $v0, $zero
/* 9404D0 80240F20 10400005 */  beqz      $v0, .L80240F38
/* 9404D4 80240F24 00000000 */   nop      
/* 9404D8 80240F28 8E050000 */  lw        $a1, ($s0)
/* 9404DC 80240F2C 844600A8 */  lh        $a2, 0xa8($v0)
/* 9404E0 80240F30 0C0B2026 */  jal       set_variable
/* 9404E4 80240F34 0220202D */   daddu    $a0, $s1, $zero
.L80240F38:
/* 9404E8 80240F38 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9404EC 80240F3C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9404F0 80240F40 8FB00010 */  lw        $s0, 0x10($sp)
/* 9404F4 80240F44 24020002 */  addiu     $v0, $zero, 2
/* 9404F8 80240F48 03E00008 */  jr        $ra
/* 9404FC 80240F4C 27BD0020 */   addiu    $sp, $sp, 0x20
