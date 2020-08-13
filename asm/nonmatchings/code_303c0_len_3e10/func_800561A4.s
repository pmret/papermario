.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800561A4
/* 0315A4 800561A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0315A8 800561A8 0080282D */  daddu $a1, $a0, $zero
/* 0315AC 800561AC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0315B0 800561B0 0C015338 */  jal   func_80054CE0
/* 0315B4 800561B4 24040001 */   addiu $a0, $zero, 1
/* 0315B8 800561B8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0315BC 800561BC 03E00008 */  jr    $ra
/* 0315C0 800561C0 27BD0018 */   addiu $sp, $sp, 0x18

/* 0315C4 800561C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0315C8 800561C8 0080282D */  daddu $a1, $a0, $zero
/* 0315CC 800561CC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0315D0 800561D0 0C015338 */  jal   func_80054CE0
/* 0315D4 800561D4 24040010 */   addiu $a0, $zero, 0x10
/* 0315D8 800561D8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0315DC 800561DC 03E00008 */  jr    $ra
/* 0315E0 800561E0 27BD0018 */   addiu $sp, $sp, 0x18

