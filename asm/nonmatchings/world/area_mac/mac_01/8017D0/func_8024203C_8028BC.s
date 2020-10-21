.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024203C_8028BC
/* 8028BC 8024203C 3C018015 */  lui       $at, %hi(D_80151310)
/* 8028C0 80242040 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 8028C4 80242044 03E00008 */  jr        $ra
/* 8028C8 80242048 24020002 */   addiu    $v0, $zero, 2
