.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C0_BF4860
/* BF4860 802400C0 24020001 */  addiu     $v0, $zero, 1
/* BF4864 802400C4 3C018011 */  lui       $at, %hi(gPlayerData)
/* BF4868 802400C8 A022F290 */  sb        $v0, %lo(gPlayerData)($at)
/* BF486C 802400CC 03E00008 */  jr        $ra
/* BF4870 802400D0 24020002 */   addiu    $v0, $zero, 2
