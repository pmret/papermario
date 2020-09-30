.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF43C
/* 888EC 800EF43C 3C018011 */  lui       $at, 0x8011
/* 888F0 800EF440 A420CFC8 */  sh        $zero, -0x3038($at)
/* 888F4 800EF444 3C018011 */  lui       $at, 0x8011
/* 888F8 800EF448 A420CFCA */  sh        $zero, -0x3036($at)
/* 888FC 800EF44C 3C018011 */  lui       $at, 0x8011
/* 88900 800EF450 A420CFCE */  sh        $zero, -0x3032($at)
/* 88904 800EF454 03E00008 */  jr        $ra
/* 88908 800EF458 00000000 */   nop      
