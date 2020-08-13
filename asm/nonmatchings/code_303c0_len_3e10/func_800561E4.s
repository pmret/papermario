.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800561E4
/* 0315E4 800561E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0315E8 800561E8 0080282D */  daddu $a1, $a0, $zero
/* 0315EC 800561EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0315F0 800561F0 0C01535D */  jal   func_80054D74
/* 0315F4 800561F4 24040010 */   addiu $a0, $zero, 0x10
/* 0315F8 800561F8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0315FC 800561FC 03E00008 */  jr    $ra
/* 031600 80056200 27BD0018 */   addiu $sp, $sp, 0x18

