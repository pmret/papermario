.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200550
/* 326020 E0200550 3C01E020 */  lui       $at, 0xe020
/* 326024 E0200554 8C2106E4 */  lw        $at, 0x6e4($at)
/* 326028 E0200558 00200008 */  jr        $at
/* 32602C E020055C 00000000 */   nop      
