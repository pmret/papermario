.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200450
/* 325F20 E0200450 3C01E020 */  lui       $at, 0xe020
/* 325F24 E0200454 8C2106A4 */  lw        $at, 0x6a4($at)
/* 325F28 E0200458 00200008 */  jr        $at
/* 325F2C E020045C 00000000 */   nop      
