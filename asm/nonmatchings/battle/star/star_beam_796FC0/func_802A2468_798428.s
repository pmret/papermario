.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A2468_798428
/* 798428 802A2468 3C02802A */  lui       $v0, %hi(D_802A3838)
/* 79842C 802A246C 8C423838 */  lw        $v0, %lo(D_802A3838)($v0)
/* 798430 802A2470 AC820084 */  sw        $v0, 0x84($a0)
/* 798434 802A2474 03E00008 */  jr        $ra
/* 798438 802A2478 24020002 */   addiu    $v0, $zero, 2
