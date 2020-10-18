.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004F0
/* 325FC0 E02004F0 3C01E020 */  lui       $at, 0xe020
/* 325FC4 E02004F4 8C2106CC */  lw        $at, 0x6cc($at)
/* 325FC8 E02004F8 00200008 */  jr        $at
/* 325FCC E02004FC 00000000 */   nop      
