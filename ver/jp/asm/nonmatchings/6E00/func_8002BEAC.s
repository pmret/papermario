.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BEAC
/* 72AC 8002BEAC 3C01800A */  lui       $at, %hi(D_8009BA74)
/* 72B0 8002BEB0 E42CBA74 */  swc1      $f12, %lo(D_8009BA74)($at)
/* 72B4 8002BEB4 3C01800A */  lui       $at, %hi(D_8009BA70)
/* 72B8 8002BEB8 E42CBA70 */  swc1      $f12, %lo(D_8009BA70)($at)
/* 72BC 8002BEBC 03E00008 */  jr        $ra
/* 72C0 8002BEC0 00000000 */   nop
