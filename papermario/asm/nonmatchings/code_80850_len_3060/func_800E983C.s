.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E983C
/* 082CEC 800E983C 3C018011 */  lui   $at, 0x8011
/* 082CF0 800E9840 A020EF9D */  sb    $zero, -0x1063($at)
/* 082CF4 800E9844 03E00008 */  jr    $ra
/* 082CF8 800E9848 00000000 */   nop   

