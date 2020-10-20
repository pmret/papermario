.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240418_9695D8
/* 9695D8 80240418 24020001 */  addiu     $v0, $zero, 1
/* 9695DC 8024041C 3C018015 */  lui       $at, %hi(D_80151310)
/* 9695E0 80240420 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 9695E4 80240424 03E00008 */  jr        $ra
/* 9695E8 80240428 24020002 */   addiu    $v0, $zero, 2
