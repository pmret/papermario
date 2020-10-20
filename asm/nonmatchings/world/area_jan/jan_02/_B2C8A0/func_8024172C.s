.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024172C
/* B2DB9C 8024172C 24020001 */  addiu     $v0, $zero, 1
/* B2DBA0 80241730 3C018015 */  lui       $at, %hi(D_80151310)
/* B2DBA4 80241734 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* B2DBA8 80241738 03E00008 */  jr        $ra
/* B2DBAC 8024173C 24020002 */   addiu    $v0, $zero, 2
