.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200480
/* 325F50 E0200480 3C01E020 */  lui       $at, %hi(D_E02006B0)
/* 325F54 E0200484 8C2106B0 */  lw        $at, %lo(D_E02006B0)($at)
/* 325F58 E0200488 00200008 */  jr        $at
/* 325F5C E020048C 00000000 */   nop
