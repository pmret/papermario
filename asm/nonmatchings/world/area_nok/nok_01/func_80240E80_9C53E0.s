.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E80_9C6260
/* 9C6260 80240E80 24020001 */  addiu     $v0, $zero, 1
/* 9C6264 80240E84 3C018015 */  lui       $at, %hi(D_80151310)
/* 9C6268 80240E88 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 9C626C 80240E8C 03E00008 */  jr        $ra
/* 9C6270 80240E90 24020002 */   addiu    $v0, $zero, 2
