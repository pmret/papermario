.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240578
/* 843148 80240578 24020001 */  addiu     $v0, $zero, 1
/* 84314C 8024057C 3C018015 */  lui       $at, %hi(D_80151310)
/* 843150 80240580 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 843154 80240584 03E00008 */  jr        $ra
/* 843158 80240588 24020002 */   addiu    $v0, $zero, 2
