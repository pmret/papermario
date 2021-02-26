.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FCAC
/* 2B0AC 8004FCAC 03E00008 */  jr        $ra
/* 2B0B0 8004FCB0 A0A00056 */   sb       $zero, 0x56($a1)
