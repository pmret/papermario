.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel load_battle
/* 04E090 80072C90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 04E094 80072C94 3C01800E */  lui   $at, 0x800e
/* 04E098 80072C98 AC24C4E8 */  sw    $a0, -0x3b18($at)
/* 04E09C 80072C9C AFBF0010 */  sw    $ra, 0x10($sp)
/* 04E0A0 80072CA0 0C00CD3C */  jal   set_game_mode
/* 04E0A4 80072CA4 24040008 */   addiu $a0, $zero, 8
/* 04E0A8 80072CA8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 04E0AC 80072CAC 3C01800E */  lui   $at, 0x800e
/* 04E0B0 80072CB0 AC20C068 */  sw    $zero, -0x3f98($at)
/* 04E0B4 80072CB4 3C01800E */  lui   $at, 0x800e
/* 04E0B8 80072CB8 AC20C4D0 */  sw    $zero, -0x3b30($at)
/* 04E0BC 80072CBC 3C01800E */  lui   $at, 0x800e
/* 04E0C0 80072CC0 AC20C4DC */  sw    $zero, -0x3b24($at)
/* 04E0C4 80072CC4 03E00008 */  jr    $ra
/* 04E0C8 80072CC8 27BD0018 */   addiu $sp, $sp, 0x18

