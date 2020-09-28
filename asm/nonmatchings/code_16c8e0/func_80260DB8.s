.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260DB8
/* 18F698 80260DB8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 18F69C 80260DBC 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 18F6A0 80260DC0 8C430000 */  lw        $v1, ($v0)
/* 18F6A4 80260DC4 3C040004 */  lui       $a0, 4
/* 18F6A8 80260DC8 00641825 */  or        $v1, $v1, $a0
/* 18F6AC 80260DCC AC430000 */  sw        $v1, ($v0)
/* 18F6B0 80260DD0 03E00008 */  jr        $ra
/* 18F6B4 80260DD4 24020002 */   addiu    $v0, $zero, 2
