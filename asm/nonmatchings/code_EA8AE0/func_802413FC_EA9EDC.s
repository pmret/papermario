.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413FC_EA9EDC
/* EA9EDC 802413FC 3C018025 */  lui       $at, %hi(D_80248380)
/* EA9EE0 80241400 AC208380 */  sw        $zero, %lo(D_80248380)($at)
/* EA9EE4 80241404 03E00008 */  jr        $ra
/* EA9EE8 80241408 24020002 */   addiu    $v0, $zero, 2
