.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241740_B2DBB0
/* B2DBB0 80241740 3C018015 */  lui       $at, %hi(D_80151310)
/* B2DBB4 80241744 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* B2DBB8 80241748 03E00008 */  jr        $ra
/* B2DBBC 8024174C 24020002 */   addiu    $v0, $zero, 2
