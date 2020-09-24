.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D286C
/* F721C 802D286C 8C82000C */  lw        $v0, 0xc($a0)
/* F7220 802D2870 8C420000 */  lw        $v0, ($v0)
/* F7224 802D2874 3C01802E */  lui       $at, 0x802e
/* F7228 802D2878 A422B5B0 */  sh        $v0, -0x4a50($at)
/* F722C 802D287C 03E00008 */  jr        $ra
/* F7230 802D2880 24020002 */   addiu    $v0, $zero, 2
