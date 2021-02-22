.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407A0_BCD800
/* BCD800 802407A0 AC800074 */  sw        $zero, 0x74($a0)
/* BCD804 802407A4 03E00008 */  jr        $ra
/* BCD808 802407A8 24020002 */   addiu    $v0, $zero, 2
