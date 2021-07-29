.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005052C
/* 2B92C 8005052C AC850204 */  sw        $a1, 0x204($a0)
/* 2B930 80050530 03E00008 */  jr        $ra
/* 2B934 80050534 A0860232 */   sb       $a2, 0x232($a0)
