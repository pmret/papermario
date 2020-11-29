.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF3E4
/* 88894 800EF3E4 2402000F */  addiu     $v0, $zero, 0xf
/* 88898 800EF3E8 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 8889C 800EF3EC A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 888A0 800EF3F0 2402000A */  addiu     $v0, $zero, 0xa
/* 888A4 800EF3F4 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 888A8 800EF3F8 A420CFCA */  sh        $zero, %lo(D_8010CFCA)($at)
/* 888AC 800EF3FC 3C018010 */  lui       $at, %hi(D_800F802C)
/* 888B0 800EF400 AC22802C */  sw        $v0, %lo(D_800F802C)($at)
/* 888B4 800EF404 3C018011 */  lui       $at, %hi(D_8010CFCE)
/* 888B8 800EF408 A420CFCE */  sh        $zero, %lo(D_8010CFCE)($at)
/* 888BC 800EF40C 03E00008 */  jr        $ra
/* 888C0 800EF410 00000000 */   nop      
