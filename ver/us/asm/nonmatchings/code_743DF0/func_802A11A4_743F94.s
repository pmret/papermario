.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11A4_743F94
/* 743F94 802A11A4 3C03802A */  lui       $v1, %hi(D_802A4020)
/* 743F98 802A11A8 24634020 */  addiu     $v1, $v1, %lo(D_802A4020)
/* 743F9C 802A11AC 8C620000 */  lw        $v0, ($v1)
/* 743FA0 802A11B0 24420001 */  addiu     $v0, $v0, 1
/* 743FA4 802A11B4 AC620000 */  sw        $v0, ($v1)
/* 743FA8 802A11B8 03E00008 */  jr        $ra
/* 743FAC 802A11BC 24020002 */   addiu    $v0, $zero, 2
