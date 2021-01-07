.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200420
/* 325EF0 E0200420 3C01E020 */  lui       $at, %hi(D_E0200698)
/* 325EF4 E0200424 8C210698 */  lw        $at, %lo(D_E0200698)($at)
/* 325EF8 E0200428 00200008 */  jr        $at
/* 325EFC E020042C 00000000 */   nop      
