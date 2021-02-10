.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF314
/* 887C4 800EF314 24020032 */  addiu     $v0, $zero, 0x32
/* 887C8 800EF318 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 887CC 800EF31C A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 887D0 800EF320 03E00008 */  jr        $ra
/* 887D4 800EF324 00000000 */   nop
