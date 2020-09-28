.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FFFC
/* 2B3FC 8004FFFC 03E00008 */  jr        $ra
/* 2B400 80050000 A0A00056 */   sb       $zero, 0x56($a1)
