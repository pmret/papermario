.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200580
/* 326050 E0200580 3C01E020 */  lui       $at, %hi(D_E02006F0)
/* 326054 E0200584 8C2106F0 */  lw        $at, %lo(D_E02006F0)($at)
/* 326058 E0200588 00200008 */  jr        $at
/* 32605C E020058C 00000000 */   nop      
