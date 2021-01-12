.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1194_743F84
/* 743F84 802A1194 3C01802A */  lui       $at, %hi(D_802A4020)
/* 743F88 802A1198 AC204020 */  sw        $zero, %lo(D_802A4020)($at)
/* 743F8C 802A119C 03E00008 */  jr        $ra
/* 743F90 802A11A0 24020002 */   addiu    $v0, $zero, 2
