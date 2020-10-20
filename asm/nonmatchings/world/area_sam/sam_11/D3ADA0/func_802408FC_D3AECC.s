.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408FC_D3AECC
/* D3AECC 802408FC 3C018015 */  lui       $at, %hi(D_80151310)
/* D3AED0 80240900 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* D3AED4 80240904 03E00008 */  jr        $ra
/* D3AED8 80240908 24020002 */   addiu    $v0, $zero, 2
