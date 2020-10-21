.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A8_8B0518
/* 8B0518 802404A8 24020001 */  addiu     $v0, $zero, 1
/* 8B051C 802404AC 3C018015 */  lui       $at, %hi(D_80151310)
/* 8B0520 802404B0 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 8B0524 802404B4 03E00008 */  jr        $ra
/* 8B0528 802404B8 24020002 */   addiu    $v0, $zero, 2
