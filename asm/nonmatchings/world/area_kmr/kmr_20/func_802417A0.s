.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A0
/* 8ED5C0 802417A0 3C028016 */  lui       $v0, 0x8016
/* 8ED5C4 802417A4 8442A552 */  lh        $v0, -0x5aae($v0)
/* 8ED5C8 802417A8 AC820084 */  sw        $v0, 0x84($a0)
/* 8ED5CC 802417AC 03E00008 */  jr        $ra
/* 8ED5D0 802417B0 24020002 */   addiu    $v0, $zero, 2
