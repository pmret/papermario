.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242028
/* 8028A8 80242028 24020001 */  addiu     $v0, $zero, 1
/* 8028AC 8024202C 3C018015 */  lui       $at, %hi(D_80151310)
/* 8028B0 80242030 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 8028B4 80242034 03E00008 */  jr        $ra
/* 8028B8 80242038 24020002 */   addiu    $v0, $zero, 2
