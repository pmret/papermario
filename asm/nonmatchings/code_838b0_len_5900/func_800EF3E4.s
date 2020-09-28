.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF3E4
/* 88894 800EF3E4 2402000F */  addiu     $v0, $zero, 0xf
/* 88898 800EF3E8 3C018011 */  lui       $at, 0x8011
/* 8889C 800EF3EC A422CFC8 */  sh        $v0, -0x3038($at)
/* 888A0 800EF3F0 2402000A */  addiu     $v0, $zero, 0xa
/* 888A4 800EF3F4 3C018011 */  lui       $at, 0x8011
/* 888A8 800EF3F8 A420CFCA */  sh        $zero, -0x3036($at)
/* 888AC 800EF3FC 3C018010 */  lui       $at, 0x8010
/* 888B0 800EF400 AC22802C */  sw        $v0, -0x7fd4($at)
/* 888B4 800EF404 3C018011 */  lui       $at, 0x8011
/* 888B8 800EF408 A420CFCE */  sh        $zero, -0x3032($at)
/* 888BC 800EF40C 03E00008 */  jr        $ra
/* 888C0 800EF410 00000000 */   nop      
