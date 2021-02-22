.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D00_BC8B60
/* BC8B60 80240D00 24020001 */  addiu     $v0, $zero, 1
/* BC8B64 80240D04 3C018011 */  lui       $at, %hi(gPlayerData)
/* BC8B68 80240D08 A022F290 */  sb        $v0, %lo(gPlayerData)($at)
/* BC8B6C 80240D0C 03E00008 */  jr        $ra
/* BC8B70 80240D10 24020002 */   addiu    $v0, $zero, 2
