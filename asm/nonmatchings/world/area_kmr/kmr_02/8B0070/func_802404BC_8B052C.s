.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404BC_8B052C
/* 8B052C 802404BC 3C018015 */  lui       $at, %hi(D_80151310)
/* 8B0530 802404C0 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 8B0534 802404C4 03E00008 */  jr        $ra
/* 8B0538 802404C8 24020002 */   addiu    $v0, $zero, 2
