.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_8EC4DC
/* 8EC4DC 802406BC AC80007C */  sw        $zero, 0x7c($a0)
/* 8EC4E0 802406C0 03E00008 */  jr        $ra
/* 8EC4E4 802406C4 24020002 */   addiu    $v0, $zero, 2
