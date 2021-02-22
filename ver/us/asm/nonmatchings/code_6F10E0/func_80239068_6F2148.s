.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80239068_6F2148
/* 6F2148 80239068 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 6F214C 8023906C 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 6F2150 80239070 3C034000 */  lui       $v1, 0x4000
/* 6F2154 80239074 8CC20000 */  lw        $v0, ($a2)
/* 6F2158 80239078 8CC500DC */  lw        $a1, 0xdc($a2)
/* 6F215C 8023907C 00431024 */  and       $v0, $v0, $v1
/* 6F2160 80239080 50400001 */  beql      $v0, $zero, .L80239088
/* 6F2164 80239084 A0A00220 */   sb       $zero, 0x220($a1)
.L80239088:
/* 6F2168 80239088 80A20220 */  lb        $v0, 0x220($a1)
/* 6F216C 8023908C 3C03BFFF */  lui       $v1, 0xbfff
/* 6F2170 80239090 AC820084 */  sw        $v0, 0x84($a0)
/* 6F2174 80239094 A0A00220 */  sb        $zero, 0x220($a1)
/* 6F2178 80239098 8CC20000 */  lw        $v0, ($a2)
/* 6F217C 8023909C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 6F2180 802390A0 00431024 */  and       $v0, $v0, $v1
/* 6F2184 802390A4 ACC20000 */  sw        $v0, ($a2)
/* 6F2188 802390A8 03E00008 */  jr        $ra
/* 6F218C 802390AC 24020002 */   addiu    $v0, $zero, 2
