.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A3C
/* 9D8A5C 80241A3C 3C018015 */  lui       $at, %hi(D_80151310)
/* 9D8A60 80241A40 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 9D8A64 80241A44 03E00008 */  jr        $ra
/* 9D8A68 80241A48 24020002 */   addiu    $v0, $zero, 2
