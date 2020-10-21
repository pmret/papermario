.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418D8_824B98
/* 824B98 802418D8 24020001 */  addiu     $v0, $zero, 1
/* 824B9C 802418DC 3C018015 */  lui       $at, %hi(D_80151310)
/* 824BA0 802418E0 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 824BA4 802418E4 03E00008 */  jr        $ra
/* 824BA8 802418E8 24020002 */   addiu    $v0, $zero, 2
