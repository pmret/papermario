.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200590
/* 326060 E0200590 3C01E020 */  lui       $at, %hi(D_E02006F4)
/* 326064 E0200594 8C2106F4 */  lw        $at, %lo(D_E02006F4)($at)
/* 326068 E0200598 00200008 */  jr        $at
/* 32606C E020059C 00000000 */   nop
