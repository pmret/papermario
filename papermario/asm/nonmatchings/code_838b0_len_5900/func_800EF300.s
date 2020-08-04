.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EF300
/* 0887B0 800EF300 24020028 */  addiu $v0, $zero, 0x28
/* 0887B4 800EF304 3C018011 */  lui   $at, 0x8011
/* 0887B8 800EF308 A422CFC8 */  sh    $v0, -0x3038($at)
/* 0887BC 800EF30C 03E00008 */  jr    $ra
/* 0887C0 800EF310 00000000 */   nop   

