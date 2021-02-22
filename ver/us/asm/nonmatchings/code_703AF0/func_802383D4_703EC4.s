.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802383D4_703EC4
/* 703EC4 802383D4 3C018024 */  lui       $at, %hi(D_8023C1BC)
/* 703EC8 802383D8 AC20C1BC */  sw        $zero, %lo(D_8023C1BC)($at)
/* 703ECC 802383DC 03E00008 */  jr        $ra
/* 703ED0 802383E0 24020002 */   addiu    $v0, $zero, 2
