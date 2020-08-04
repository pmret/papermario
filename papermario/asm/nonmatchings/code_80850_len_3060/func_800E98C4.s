.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E98C4
/* 082D74 800E98C4 3C018011 */  lui   $at, 0x8011
/* 082D78 800E98C8 A020EF9C */  sb    $zero, -0x1064($at)
/* 082D7C 800E98CC 03E00008 */  jr    $ra
/* 082D80 800E98D0 00000000 */   nop   

