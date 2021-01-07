.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004B0
/* 325F80 E02004B0 3C01E020 */  lui       $at, %hi(D_E02006BC)
/* 325F84 E02004B4 8C2106BC */  lw        $at, %lo(D_E02006BC)($at)
/* 325F88 E02004B8 00200008 */  jr        $at
/* 325F8C E02004BC 00000000 */   nop      
