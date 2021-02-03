.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1528_7905F8
/* 7905F8 802A1528 3C02802A */  lui       $v0, %hi(D_802A2CC0)
/* 7905FC 802A152C 8C422CC0 */  lw        $v0, %lo(D_802A2CC0)($v0)
/* 790600 802A1530 AC820084 */  sw        $v0, 0x84($a0)
/* 790604 802A1534 03E00008 */  jr        $ra
/* 790608 802A1538 24020002 */   addiu    $v0, $zero, 2
