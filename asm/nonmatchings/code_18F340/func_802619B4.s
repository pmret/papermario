.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802619B4
/* 190294 802619B4 24020001 */  addiu     $v0, $zero, 1
/* 190298 802619B8 3C01802A */  lui       $at, %hi(D_8029FBA4)
/* 19029C 802619BC A422FBA4 */  sh        $v0, %lo(D_8029FBA4)($at)
/* 1902A0 802619C0 03E00008 */  jr        $ra
/* 1902A4 802619C4 24020002 */   addiu    $v0, $zero, 2
