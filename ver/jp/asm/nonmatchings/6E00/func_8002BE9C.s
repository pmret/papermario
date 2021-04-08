.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BE9C
/* 729C 8002BE9C 3C01800A */  lui       $at, %hi(D_8009BA74)
/* 72A0 8002BEA0 E42CBA74 */  swc1      $f12, %lo(D_8009BA74)($at)
/* 72A4 8002BEA4 03E00008 */  jr        $ra
/* 72A8 8002BEA8 00000000 */   nop
