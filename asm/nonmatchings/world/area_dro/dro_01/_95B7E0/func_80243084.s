.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243084
/* 95E284 80243084 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 95E288 80243088 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 95E28C 8024308C 8C6202BC */  lw        $v0, 0x2bc($v1)
/* 95E290 80243090 AC620328 */  sw        $v0, 0x328($v1)
/* 95E294 80243094 03E00008 */  jr        $ra
/* 95E298 80243098 24020002 */   addiu    $v0, $zero, 2
