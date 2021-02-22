.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BED4
/* 72D4 8002BED4 3C01800A */  lui       $at, %hi(D_8009BA7C)
/* 72D8 8002BED8 E42CBA7C */  swc1      $f12, %lo(D_8009BA7C)($at)
/* 72DC 8002BEDC 03E00008 */  jr        $ra
/* 72E0 8002BEE0 00000000 */   nop
