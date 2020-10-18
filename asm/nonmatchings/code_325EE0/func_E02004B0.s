.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004B0
/* 325F80 E02004B0 3C01E020 */  lui       $at, 0xe020
/* 325F84 E02004B4 8C2106BC */  lw        $at, 0x6bc($at)
/* 325F88 E02004B8 00200008 */  jr        $at
/* 325F8C E02004BC 00000000 */   nop      
