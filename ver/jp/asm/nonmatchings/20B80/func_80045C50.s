.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045C50
/* 21050 80045C50 3C02800A */  lui       $v0, %hi(D_8009ED50)
/* 21054 80045C54 8C42ED50 */  lw        $v0, %lo(D_8009ED50)($v0)
/* 21058 80045C58 03E00008 */  jr        $ra
/* 2105C 80045C5C 00000000 */   nop
