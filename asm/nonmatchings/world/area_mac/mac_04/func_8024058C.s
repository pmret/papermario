.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024058C
/* 84315C 8024058C 3C018015 */  lui       $at, %hi(D_80151310)
/* 843160 80240590 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 843164 80240594 03E00008 */  jr        $ra
/* 843168 80240598 24020002 */   addiu    $v0, $zero, 2
