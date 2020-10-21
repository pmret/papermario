.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405DC_831DDC
/* 831DDC 802405DC 3C018015 */  lui       $at, %hi(D_80151310)
/* 831DE0 802405E0 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 831DE4 802405E4 03E00008 */  jr        $ra
/* 831DE8 802405E8 24020002 */   addiu    $v0, $zero, 2
