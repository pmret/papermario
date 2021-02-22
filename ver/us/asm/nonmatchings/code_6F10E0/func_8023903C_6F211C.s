.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023903C_6F211C
/* 6F211C 8023903C 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 6F2120 80239040 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 6F2124 80239044 8C6200DC */  lw        $v0, 0xdc($v1)
/* 6F2128 80239048 3C04BFFF */  lui       $a0, 0xbfff
/* 6F212C 8023904C A0400220 */  sb        $zero, 0x220($v0)
/* 6F2130 80239050 8C620000 */  lw        $v0, ($v1)
/* 6F2134 80239054 3484FFFF */  ori       $a0, $a0, 0xffff
/* 6F2138 80239058 00441024 */  and       $v0, $v0, $a0
/* 6F213C 8023905C AC620000 */  sw        $v0, ($v1)
/* 6F2140 80239060 03E00008 */  jr        $ra
/* 6F2144 80239064 24020002 */   addiu    $v0, $zero, 2
