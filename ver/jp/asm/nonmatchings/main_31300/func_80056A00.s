.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056A00
/* 31E00 80056A00 3C028008 */  lui       $v0, %hi(D_80078E2A)
/* 31E04 80056A04 03E00008 */  jr        $ra
/* 31E08 80056A08 84428E2A */   lh       $v0, %lo(D_80078E2A)($v0)
