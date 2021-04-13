.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002715C
/* 255C 8002715C 3C02800A */  lui       $v0, %hi(D_8009A5B8)
/* 2560 80027160 8C42A5B8 */  lw        $v0, %lo(D_8009A5B8)($v0)
/* 2564 80027164 03E00008 */  jr        $ra
/* 2568 80027168 00000000 */   nop
/* 256C 8002716C 00000000 */  nop
