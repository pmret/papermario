.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200460
/* 325F30 E0200460 3C01E020 */  lui       $at, %hi(D_E02006A8)
/* 325F34 E0200464 8C2106A8 */  lw        $at, %lo(D_E02006A8)($at)
/* 325F38 E0200468 00200008 */  jr        $at
/* 325F3C E020046C 00000000 */   nop
