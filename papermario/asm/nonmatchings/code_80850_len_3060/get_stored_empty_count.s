.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_stored_empty_count
/* 080CF8 800E7848 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 080CFC 800E784C AFBF0010 */  sw    $ra, 0x10($sp)
/* 080D00 800E7850 0C039E05 */  jal   get_stored_count
/* 080D04 800E7854 00000000 */   nop   
/* 080D08 800E7858 24030020 */  addiu $v1, $zero, 0x20
/* 080D0C 800E785C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 080D10 800E7860 00621023 */  subu  $v0, $v1, $v0
/* 080D14 800E7864 03E00008 */  jr    $ra
/* 080D18 800E7868 27BD0018 */   addiu $sp, $sp, 0x18

