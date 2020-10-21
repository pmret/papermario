.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802436C0_DF2560
/* DF2560 802436C0 8C830148 */  lw        $v1, 0x148($a0)
/* DF2564 802436C4 24020003 */  addiu     $v0, $zero, 3
/* DF2568 802436C8 A06200B5 */  sb        $v0, 0xb5($v1)
/* DF256C 802436CC 03E00008 */  jr        $ra
/* DF2570 802436D0 24020002 */   addiu    $v0, $zero, 2
