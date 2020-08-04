.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E9900
/* 082DB0 800E9900 3C018011 */  lui   $at, 0x8011
/* 082DB4 800E9904 A020EF9E */  sb    $zero, -0x1062($at)
/* 082DB8 800E9908 03E00008 */  jr    $ra
/* 082DBC 800E990C 00000000 */   nop   

