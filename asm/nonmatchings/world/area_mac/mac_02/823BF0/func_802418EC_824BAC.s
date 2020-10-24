.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418EC_824BAC
/* 824BAC 802418EC 3C018015 */  lui       $at, %hi(D_80151310)
/* 824BB0 802418F0 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 824BB4 802418F4 03E00008 */  jr        $ra
/* 824BB8 802418F8 24020002 */   addiu    $v0, $zero, 2
