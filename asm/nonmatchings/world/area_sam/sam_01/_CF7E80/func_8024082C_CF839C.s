.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024082C_CF839C
/* CF839C 8024082C 3C018015 */  lui       $at, %hi(D_80151310)
/* CF83A0 80240830 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* CF83A4 80240834 03E00008 */  jr        $ra
/* CF83A8 80240838 24020002 */   addiu    $v0, $zero, 2
