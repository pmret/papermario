.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200500
/* 325FD0 E0200500 3C01E020 */  lui       $at, %hi(D_E02006D0)
/* 325FD4 E0200504 8C2106D0 */  lw        $at, %lo(D_E02006D0)($at)
/* 325FD8 E0200508 00200008 */  jr        $at
/* 325FDC E020050C 00000000 */   nop      
