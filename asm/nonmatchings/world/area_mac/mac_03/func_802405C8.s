.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C8
/* 831DC8 802405C8 24020001 */  addiu     $v0, $zero, 1
/* 831DCC 802405CC 3C018015 */  lui       $at, %hi(D_80151310)
/* 831DD0 802405D0 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 831DD4 802405D4 03E00008 */  jr        $ra
/* 831DD8 802405D8 24020002 */   addiu    $v0, $zero, 2
