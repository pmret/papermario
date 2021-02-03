.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802383C0_703EB0
/* 703EB0 802383C0 24020001 */  addiu     $v0, $zero, 1
/* 703EB4 802383C4 3C018024 */  lui       $at, %hi(D_8023C1BC)
/* 703EB8 802383C8 AC22C1BC */  sw        $v0, %lo(D_8023C1BC)($at)
/* 703EBC 802383CC 03E00008 */  jr        $ra
/* 703EC0 802383D0 24020002 */   addiu    $v0, $zero, 2
