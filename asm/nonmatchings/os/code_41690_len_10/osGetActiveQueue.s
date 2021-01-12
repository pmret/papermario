.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osGetActiveQueue
/* 41690 80066290 3C028009 */  lui       $v0, %hi(D_8009465C)
/* 41694 80066294 03E00008 */  jr        $ra
/* 41698 80066298 8C42465C */   lw       $v0, %lo(D_8009465C)($v0)
/* 4169C 8006629C 00000000 */  nop
