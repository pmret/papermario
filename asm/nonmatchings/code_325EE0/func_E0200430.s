.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200430
/* 325F00 E0200430 3C01E020 */  lui       $at, 0xe020
/* 325F04 E0200434 8C21069C */  lw        $at, 0x69c($at)
/* 325F08 E0200438 00200008 */  jr        $at
/* 325F0C E020043C 00000000 */   nop      
