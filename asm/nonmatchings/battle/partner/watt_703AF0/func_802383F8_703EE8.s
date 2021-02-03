.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802383F8_703EE8
/* 703EE8 802383F8 3C018024 */  lui       $at, %hi(D_8023C1C4)
/* 703EEC 802383FC AC20C1C4 */  sw        $zero, %lo(D_8023C1C4)($at)
/* 703EF0 80238400 03E00008 */  jr        $ra
/* 703EF4 80238404 24020002 */   addiu    $v0, $zero, 2
