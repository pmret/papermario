.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024EDA4
/* 17D684 8024EDA4 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17D688 8024EDA8 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17D68C 8024EDAC 03E00008 */  jr        $ra
/* 17D690 8024EDB0 24020002 */   addiu    $v0, $zero, 2
/* 17D694 8024EDB4 00000000 */  nop
/* 17D698 8024EDB8 00000000 */  nop
/* 17D69C 8024EDBC 00000000 */  nop
