.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9B30
/* 41E8C0 802A9B30 3C02800E */  lui       $v0, 0x800e
/* 41E8C4 802A9B34 8C42C074 */  lw        $v0, -0x3f8c($v0)
/* 41E8C8 802A9B38 30420004 */  andi      $v0, $v0, 4
/* 41E8CC 802A9B3C 03E00008 */  jr        $ra
/* 41E8D0 802A9B40 2C420001 */   sltiu    $v0, $v0, 1
