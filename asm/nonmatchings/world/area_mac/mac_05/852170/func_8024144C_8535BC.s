.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024144C_8535BC
/* 8535BC 8024144C 3C018015 */  lui       $at, %hi(D_80151310)
/* 8535C0 80241450 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 8535C4 80241454 03E00008 */  jr        $ra
/* 8535C8 80241458 24020002 */   addiu    $v0, $zero, 2
