.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E984C
/* 082CFC 800E984C 24020001 */  addiu $v0, $zero, 1
/* 082D00 800E9850 3C018011 */  lui   $at, 0x8011
/* 082D04 800E9854 A022EF9D */  sb    $v0, -0x1063($at)
/* 082D08 800E9858 03E00008 */  jr    $ra
/* 082D0C 800E985C 00000000 */   nop   

