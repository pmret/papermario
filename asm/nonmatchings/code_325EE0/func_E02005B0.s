.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02005B0
/* 326080 E02005B0 3C01E020 */  lui       $at, %hi(D_E02006FC)
/* 326084 E02005B4 8C2106FC */  lw        $at, %lo(D_E02006FC)($at)
/* 326088 E02005B8 00200008 */  jr        $at
/* 32608C E02005BC 00000000 */   nop
