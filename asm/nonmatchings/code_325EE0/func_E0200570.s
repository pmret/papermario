.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200570
/* 326040 E0200570 3C01E020 */  lui       $at, %hi(D_E02006EC)
/* 326044 E0200574 8C2106EC */  lw        $at, %lo(D_E02006EC)($at)
/* 326048 E0200578 00200008 */  jr        $at
/* 32604C E020057C 00000000 */   nop      
