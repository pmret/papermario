.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200510
/* 325FE0 E0200510 3C01E020 */  lui       $at, 0xe020
/* 325FE4 E0200514 8C2106D4 */  lw        $at, 0x6d4($at)
/* 325FE8 E0200518 00200008 */  jr        $at
/* 325FEC E020051C 00000000 */   nop      
