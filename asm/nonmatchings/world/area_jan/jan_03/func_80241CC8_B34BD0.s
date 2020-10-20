.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CC8_B36898
/* B36898 80241CC8 3C018015 */  lui       $at, %hi(D_80151310)
/* B3689C 80241CCC AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* B368A0 80241CD0 03E00008 */  jr        $ra
/* B368A4 80241CD4 24020002 */   addiu    $v0, $zero, 2
