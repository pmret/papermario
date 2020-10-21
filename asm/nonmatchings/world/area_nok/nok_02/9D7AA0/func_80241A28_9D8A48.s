.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A28_9D8A48
/* 9D8A48 80241A28 24020001 */  addiu     $v0, $zero, 1
/* 9D8A4C 80241A2C 3C018015 */  lui       $at, %hi(D_80151310)
/* 9D8A50 80241A30 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 9D8A54 80241A34 03E00008 */  jr        $ra
/* 9D8A58 80241A38 24020002 */   addiu    $v0, $zero, 2
