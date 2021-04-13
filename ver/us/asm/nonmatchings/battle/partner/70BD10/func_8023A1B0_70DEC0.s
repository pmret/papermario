.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023A1B0_70DEC0
/* 70DEC0 8023A1B0 3C028024 */  lui       $v0, %hi(D_8023D334)
/* 70DEC4 8023A1B4 8C42D334 */  lw        $v0, %lo(D_8023D334)($v0)
/* 70DEC8 8023A1B8 AC820084 */  sw        $v0, 0x84($a0)
/* 70DECC 8023A1BC 03E00008 */  jr        $ra
