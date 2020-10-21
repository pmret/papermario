.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425D0_A1D6D0
/* A1D6D0 802425D0 3C018015 */  lui       $at, %hi(D_80151310)
/* A1D6D4 802425D4 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* A1D6D8 802425D8 03E00008 */  jr        $ra
/* A1D6DC 802425DC 24020002 */   addiu    $v0, $zero, 2
