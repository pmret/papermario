.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066260
/* 41660 80066260 3C028009 */  lui       $v0, %hi(D_8009463C)
/* 41664 80066264 03E00008 */  jr        $ra
/* 41668 80066268 8C42463C */   lw       $v0, %lo(D_8009463C)($v0)
/* 4166C 8006626C 00000000 */  nop
