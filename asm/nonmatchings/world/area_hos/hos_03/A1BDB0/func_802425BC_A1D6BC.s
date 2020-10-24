.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425BC_A1D6BC
/* A1D6BC 802425BC 24020001 */  addiu     $v0, $zero, 1
/* A1D6C0 802425C0 3C018015 */  lui       $at, %hi(D_80151310)
/* A1D6C4 802425C4 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* A1D6C8 802425C8 03E00008 */  jr        $ra
/* A1D6CC 802425CC 24020002 */   addiu    $v0, $zero, 2
