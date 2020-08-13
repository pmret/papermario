.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetBattleVar
/* 19DF74 8026F694 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19DF78 8026F698 AFB10014 */  sw    $s1, 0x14($sp)
/* 19DF7C 8026F69C 0080882D */  daddu $s1, $a0, $zero
/* 19DF80 8026F6A0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 19DF84 8026F6A4 AFB00010 */  sw    $s0, 0x10($sp)
/* 19DF88 8026F6A8 8E30000C */  lw    $s0, 0xc($s1)
/* 19DF8C 8026F6AC 8E050000 */  lw    $a1, ($s0)
/* 19DF90 8026F6B0 0C0B1EAF */  jal   get_variable
/* 19DF94 8026F6B4 26100004 */   addiu $s0, $s0, 4
/* 19DF98 8026F6B8 00021080 */  sll   $v0, $v0, 2
/* 19DF9C 8026F6BC 8E050000 */  lw    $a1, ($s0)
/* 19DFA0 8026F6C0 3C06800E */  lui   $a2, 0x800e
/* 19DFA4 8026F6C4 00C23021 */  addu  $a2, $a2, $v0
/* 19DFA8 8026F6C8 8CC6C078 */  lw    $a2, -0x3f88($a2)
/* 19DFAC 8026F6CC 0C0B2026 */  jal   set_variable
/* 19DFB0 8026F6D0 0220202D */   daddu $a0, $s1, $zero
/* 19DFB4 8026F6D4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19DFB8 8026F6D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 19DFBC 8026F6DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19DFC0 8026F6E0 24020002 */  addiu $v0, $zero, 2
/* 19DFC4 8026F6E4 03E00008 */  jr    $ra
/* 19DFC8 8026F6E8 27BD0020 */   addiu $sp, $sp, 0x20

