.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242910_9C7CF0
/* 9C7CF0 80242910 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 9C7CF4 80242914 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 9C7CF8 80242918 8C6202BC */  lw        $v0, 0x2bc($v1)
/* 9C7CFC 8024291C AC620324 */  sw        $v0, 0x324($v1)
/* 9C7D00 80242920 03E00008 */  jr        $ra
/* 9C7D04 80242924 24020002 */   addiu    $v0, $zero, 2
/* 9C7D08 80242928 00000000 */  nop       
/* 9C7D0C 8024292C 00000000 */  nop       
