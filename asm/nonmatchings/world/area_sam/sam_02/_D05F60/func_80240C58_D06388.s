.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C58_D06388
/* D06388 80240C58 3C018015 */  lui       $at, %hi(D_80151310)
/* D0638C 80240C5C AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* D06390 80240C60 03E00008 */  jr        $ra
/* D06394 80240C64 24020002 */   addiu    $v0, $zero, 2
