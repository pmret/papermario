.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80038844
/* 013C44 80038844 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 013C48 80038848 0000282D */  daddu $a1, $zero, $zero
/* 013C4C 8003884C AFBF0010 */  sw    $ra, 0x10($sp)
/* 013C50 80038850 0C00E166 */  jal   func_80038598
/* 013C54 80038854 00A0302D */   daddu $a2, $a1, $zero
/* 013C58 80038858 8FBF0010 */  lw    $ra, 0x10($sp)
/* 013C5C 8003885C 03E00008 */  jr    $ra
/* 013C60 80038860 27BD0018 */   addiu $sp, $sp, 0x18

