.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408E8_D3AEB8
/* D3AEB8 802408E8 24020001 */  addiu     $v0, $zero, 1
/* D3AEBC 802408EC 3C018015 */  lui       $at, %hi(D_80151310)
/* D3AEC0 802408F0 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* D3AEC4 802408F4 03E00008 */  jr        $ra
/* D3AEC8 802408F8 24020002 */   addiu    $v0, $zero, 2
