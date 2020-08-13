.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80035E24
/* 011224 80035E24 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 011228 80035E28 24020001 */  addiu $v0, $zero, 1
/* 01122C 80035E2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 011230 80035E30 3C01800A */  lui   $at, 0x800a
/* 011234 80035E34 A4220948 */  sh    $v0, 0x948($at)
/* 011238 80035E38 0C04E0A8 */  jal   set_map_transition_effect
/* 01123C 80035E3C 24040008 */   addiu $a0, $zero, 8
/* 011240 80035E40 0C00D795 */  jal   func_80035E54
/* 011244 80035E44 00000000 */   nop   
/* 011248 80035E48 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01124C 80035E4C 03E00008 */  jr    $ra
/* 011250 80035E50 27BD0018 */   addiu $sp, $sp, 0x18

