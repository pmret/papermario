.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004C0
/* 325F90 E02004C0 3C01E020 */  lui       $at, %hi(D_E02006C0)
/* 325F94 E02004C4 8C2106C0 */  lw        $at, %lo(D_E02006C0)($at)
/* 325F98 E02004C8 00200008 */  jr        $at
/* 325F9C E02004CC 00000000 */   nop
