.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435B8_DD0288
/* DD0288 802435B8 8C830148 */  lw        $v1, 0x148($a0)
/* DD028C 802435BC 24020003 */  addiu     $v0, $zero, 3
/* DD0290 802435C0 A06200B5 */  sb        $v0, 0xb5($v1)
/* DD0294 802435C4 03E00008 */  jr        $ra
/* DD0298 802435C8 24020002 */   addiu    $v0, $zero, 2
