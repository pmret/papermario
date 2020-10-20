.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C44_D06374
/* D06374 80240C44 24020001 */  addiu     $v0, $zero, 1
/* D06378 80240C48 3C018015 */  lui       $at, %hi(D_80151310)
/* D0637C 80240C4C AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* D06380 80240C50 03E00008 */  jr        $ra
/* D06384 80240C54 24020002 */   addiu    $v0, $zero, 2
