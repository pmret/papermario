.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238000_710EF0
/* 710EF0 80238000 3C02800E */  lui       $v0, %hi(gBattleStatus+0x9A)
/* 710EF4 80238004 8042C10A */  lb        $v0, %lo(gBattleStatus+0x9A)($v0)
/* 710EF8 80238008 AC820084 */  sw        $v0, 0x84($a0)
/* 710EFC 8023800C 03E00008 */  jr        $ra
/* 710F00 80238010 24020002 */   addiu    $v0, $zero, 2
