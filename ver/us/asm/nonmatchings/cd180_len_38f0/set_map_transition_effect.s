.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_map_transition_effect
/* CE9A0 801382A0 3C018015 */  lui       $at, %hi(D_8014C6F0)
/* CE9A4 801382A4 03E00008 */  jr        $ra
/* CE9A8 801382A8 AC24C6F0 */   sw       $a0, %lo(D_8014C6F0)($at)
