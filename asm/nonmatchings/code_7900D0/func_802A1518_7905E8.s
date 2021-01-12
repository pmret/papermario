.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_7905E8
/* 7905E8 802A1518 3C01802A */  lui       $at, %hi(D_802A2CC0)
/* 7905EC 802A151C AC202CC0 */  sw        $zero, %lo(D_802A2CC0)($at)
/* 7905F0 802A1520 03E00008 */  jr        $ra
/* 7905F4 802A1524 24020002 */   addiu    $v0, $zero, 2
