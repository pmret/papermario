.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200440
/* 325F10 E0200440 3C01E020 */  lui       $at, 0xe020
/* 325F14 E0200444 8C2106A0 */  lw        $at, 0x6a0($at)
/* 325F18 E0200448 00200008 */  jr        $at
/* 325F1C E020044C 00000000 */   nop      
