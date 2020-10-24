.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241588_95C788
/* 95C788 80241588 24020001 */  addiu     $v0, $zero, 1
/* 95C78C 8024158C 3C018015 */  lui       $at, %hi(D_80151310)
/* 95C790 80241590 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 95C794 80241594 03E00008 */  jr        $ra
/* 95C798 80241598 24020002 */   addiu    $v0, $zero, 2
