.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200520
/* 325FF0 E0200520 3C01E020 */  lui       $at, %hi(D_E02006D8)
/* 325FF4 E0200524 8C2106D8 */  lw        $at, %lo(D_E02006D8)($at)
/* 325FF8 E0200528 00200008 */  jr        $at
/* 325FFC E020052C 00000000 */   nop
