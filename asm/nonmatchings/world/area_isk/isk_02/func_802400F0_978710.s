.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_978800
/* 978800 802400F0 8C830148 */  lw        $v1, 0x148($a0)
/* 978804 802400F4 24020003 */  addiu     $v0, $zero, 3
/* 978808 802400F8 A06200B5 */  sb        $v0, 0xb5($v1)
/* 97880C 802400FC 03E00008 */  jr        $ra
/* 978810 80240100 24020002 */   addiu    $v0, $zero, 2
/* 978814 80240104 00000000 */  nop       
/* 978818 80240108 00000000 */  nop       
/* 97881C 8024010C 00000000 */  nop       
