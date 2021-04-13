.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006CB80
/* 47F80 8006CB80 3C028009 */  lui       $v0, %hi(D_80095960)
/* 47F84 8006CB84 03E00008 */  jr        $ra
/* 47F88 8006CB88 8C425960 */   lw       $v0, %lo(D_80095960)($v0)
/* 47F8C 8006CB8C 00000000 */  nop
/* 47F90 8006CB90 00000000 */  nop
/* 47F94 8006CB94 00000000 */  nop
/* 47F98 8006CB98 00000000 */  nop
/* 47F9C 8006CB9C 00000000 */  nop
