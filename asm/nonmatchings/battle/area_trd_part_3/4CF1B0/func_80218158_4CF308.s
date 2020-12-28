.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218158_4CF308
/* 4CF308 80218158 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 4CF30C 8021815C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 4CF310 80218160 A040004C */  sb        $zero, 0x4c($v0)
/* 4CF314 80218164 A040005C */  sb        $zero, 0x5c($v0)
/* 4CF318 80218168 03E00008 */  jr        $ra
/* 4CF31C 8021816C 24020002 */   addiu    $v0, $zero, 2
