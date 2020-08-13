.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EF43C
/* 0888EC 800EF43C 3C018011 */  lui   $at, 0x8011
/* 0888F0 800EF440 A420CFC8 */  sh    $zero, -0x3038($at)
/* 0888F4 800EF444 3C018011 */  lui   $at, 0x8011
/* 0888F8 800EF448 A420CFCA */  sh    $zero, -0x3036($at)
/* 0888FC 800EF44C 3C018011 */  lui   $at, 0x8011
/* 088900 800EF450 A420CFCE */  sh    $zero, -0x3032($at)
/* 088904 800EF454 03E00008 */  jr    $ra
/* 088908 800EF458 00000000 */   nop   

