.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel copy_matrix
/* 004B20 80029720 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 004B24 80029724 AFBF0010 */  sw    $ra, 0x10($sp)
/* 004B28 80029728 0C019194 */  jal   bcopy
/* 004B2C 8002972C 24060040 */   addiu $a2, $zero, 0x40
/* 004B30 80029730 8FBF0010 */  lw    $ra, 0x10($sp)
/* 004B34 80029734 03E00008 */  jr    $ra
/* 004B38 80029738 27BD0018 */   addiu $sp, $sp, 0x18

