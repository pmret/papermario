.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E1D4
/* 195D4 8003E1D4 3C01800B */  lui       $at, %hi(D_800B0EF8)
/* 195D8 8003E1D8 A0240EF8 */  sb        $a0, %lo(D_800B0EF8)($at)
/* 195DC 8003E1DC 03E00008 */  jr        $ra
/* 195E0 8003E1E0 00000000 */   nop
