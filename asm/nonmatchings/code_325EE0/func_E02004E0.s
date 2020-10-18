.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004E0
/* 325FB0 E02004E0 3C01E020 */  lui       $at, 0xe020
/* 325FB4 E02004E4 8C2106C8 */  lw        $at, 0x6c8($at)
/* 325FB8 E02004E8 00200008 */  jr        $at
/* 325FBC E02004EC 00000000 */   nop      
