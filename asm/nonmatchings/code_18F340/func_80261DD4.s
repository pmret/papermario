.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261DD4
/* 1906B4 80261DD4 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 1906B8 80261DD8 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 1906BC 80261DDC 80620000 */  lb        $v0, ($v1)
/* 1906C0 80261DE0 AC8200B0 */  sw        $v0, 0xb0($a0)
/* 1906C4 80261DE4 80620001 */  lb        $v0, 1($v1)
/* 1906C8 80261DE8 AC8200B4 */  sw        $v0, 0xb4($a0)
/* 1906CC 80261DEC 03E00008 */  jr        $ra
/* 1906D0 80261DF0 24020002 */   addiu    $v0, $zero, 2
