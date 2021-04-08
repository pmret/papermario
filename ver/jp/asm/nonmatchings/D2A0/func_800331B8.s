.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800331B8
/* E5B8 800331B8 3C02800A */  lui       $v0, %hi(D_8009E700)
/* E5BC 800331BC 8442E700 */  lh        $v0, %lo(D_8009E700)($v0)
/* E5C0 800331C0 03E00008 */  jr        $ra
/* E5C4 800331C4 00000000 */   nop
/* E5C8 800331C8 00000000 */  nop
/* E5CC 800331CC 00000000 */  nop
