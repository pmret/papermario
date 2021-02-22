.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802390B0_6F2190
/* 6F2190 802390B0 3C02800E */  lui       $v0, %hi(gBattleStatus+0xDC)
/* 6F2194 802390B4 8C42C14C */  lw        $v0, %lo(gBattleStatus+0xDC)($v0)
/* 6F2198 802390B8 80420220 */  lb        $v0, 0x220($v0)
/* 6F219C 802390BC AC820084 */  sw        $v0, 0x84($a0)
/* 6F21A0 802390C0 03E00008 */  jr        $ra
/* 6F21A4 802390C4 24020002 */   addiu    $v0, $zero, 2
