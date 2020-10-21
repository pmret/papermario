.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CB4_B36884
/* B36884 80241CB4 24020001 */  addiu     $v0, $zero, 1
/* B36888 80241CB8 3C018015 */  lui       $at, %hi(D_80151310)
/* B3688C 80241CBC AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* B36890 80241CC0 03E00008 */  jr        $ra
/* B36894 80241CC4 24020002 */   addiu    $v0, $zero, 2
