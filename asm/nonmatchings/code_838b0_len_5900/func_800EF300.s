.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF300
/* 887B0 800EF300 24020028 */  addiu     $v0, $zero, 0x28
/* 887B4 800EF304 3C018011 */  lui       $at, 0x8011
/* 887B8 800EF308 A422CFC8 */  sh        $v0, -0x3038($at)
/* 887BC 800EF30C 03E00008 */  jr        $ra
/* 887C0 800EF310 00000000 */   nop      
