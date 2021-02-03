.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_785C04
/* 785C04 802A10E4 24020003 */  addiu     $v0, $zero, 3
/* 785C08 802A10E8 AC820084 */  sw        $v0, 0x84($a0)
/* 785C0C 802A10EC 03E00008 */  jr        $ra
