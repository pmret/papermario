.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A2468_79AC18
/* 79AC18 802A2468 3C02802A */  lui       $v0, %hi(D_802A3838)
/* 79AC1C 802A246C 8C423838 */  lw        $v0, %lo(D_802A3838)($v0)
/* 79AC20 802A2470 AC820084 */  sw        $v0, 0x84($a0)
/* 79AC24 802A2474 03E00008 */  jr        $ra
/* 79AC28 802A2478 24020002 */   addiu    $v0, $zero, 2
