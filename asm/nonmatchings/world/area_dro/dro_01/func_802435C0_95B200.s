.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435C0_95E7C0
/* 95E7C0 802435C0 3C028016 */  lui       $v0, 0x8016
/* 95E7C4 802435C4 8442A552 */  lh        $v0, -0x5aae($v0)
/* 95E7C8 802435C8 AC820084 */  sw        $v0, 0x84($a0)
/* 95E7CC 802435CC 03E00008 */  jr        $ra
/* 95E7D0 802435D0 24020002 */   addiu    $v0, $zero, 2
