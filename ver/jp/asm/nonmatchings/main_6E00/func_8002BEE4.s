.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BEE4
/* 72E4 8002BEE4 3C01800A */  lui       $at, %hi(D_8009BA7C)
/* 72E8 8002BEE8 E42CBA7C */  swc1      $f12, %lo(D_8009BA7C)($at)
/* 72EC 8002BEEC 3C01800A */  lui       $at, %hi(D_8009BA78)
/* 72F0 8002BEF0 E42CBA78 */  swc1      $f12, %lo(D_8009BA78)($at)
/* 72F4 8002BEF4 03E00008 */  jr        $ra
/* 72F8 8002BEF8 00000000 */   nop
/* 72FC 8002BEFC 00000000 */  nop
