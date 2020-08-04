.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel StartBattle
/* 01FC40 80044840 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01FC44 80044844 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01FC48 80044848 0C0111AD */  jal   start_battle
/* 01FC4C 8004484C 2405FFFF */   addiu $a1, $zero, -1
/* 01FC50 80044850 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01FC54 80044854 24020001 */  addiu $v0, $zero, 1
/* 01FC58 80044858 03E00008 */  jr    $ra
/* 01FC5C 8004485C 27BD0018 */   addiu $sp, $sp, 0x18

