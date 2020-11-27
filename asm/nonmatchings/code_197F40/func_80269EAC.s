.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269EAC
/* 19878C 80269EAC 8C82000C */  lw        $v0, 0xc($a0)
/* 198790 80269EB0 8C420000 */  lw        $v0, ($v0)
/* 198794 80269EB4 3C01800E */  lui       $at, %hi(gBattleStatus+0x19A)
/* 198798 80269EB8 A022C20A */  sb        $v0, %lo(gBattleStatus+0x19A)($at)
/* 19879C 80269EBC 03E00008 */  jr        $ra
/* 1987A0 80269EC0 24020002 */   addiu    $v0, $zero, 2
