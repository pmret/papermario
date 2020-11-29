.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200680
/* 326150 E0200680 3C01E020 */  lui       $at, %hi(D_E0200730)
/* 326154 E0200684 8C210730 */  lw        $at, %lo(D_E0200730)($at)
/* 326158 E0200688 00200008 */  jr        $at
/* 32615C E020068C 00000000 */   nop      
