.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802383E4_703ED4
/* 703ED4 802383E4 24020001 */  addiu     $v0, $zero, 1
/* 703ED8 802383E8 3C018024 */  lui       $at, %hi(D_8023C1C4)
/* 703EDC 802383EC AC22C1C4 */  sw        $v0, %lo(D_8023C1C4)($at)
/* 703EE0 802383F0 03E00008 */  jr        $ra
/* 703EE4 802383F4 24020002 */   addiu    $v0, $zero, 2
