.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BEC4
/* 72C4 8002BEC4 3C01800A */  lui       $at, %hi(D_8009BA80)
/* 72C8 8002BEC8 AC24BA80 */  sw        $a0, %lo(D_8009BA80)($at)
/* 72CC 8002BECC 03E00008 */  jr        $ra
/* 72D0 8002BED0 00000000 */   nop
