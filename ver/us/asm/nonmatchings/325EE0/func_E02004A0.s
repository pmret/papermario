.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004A0
/* 325F70 E02004A0 3C01E020 */  lui       $at, %hi(D_E02006B8)
/* 325F74 E02004A4 8C2106B8 */  lw        $at, %lo(D_E02006B8)($at)
/* 325F78 E02004A8 00200008 */  jr        $at
/* 325F7C E02004AC 00000000 */   nop
