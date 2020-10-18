.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200560
/* 326030 E0200560 3C01E020 */  lui       $at, 0xe020
/* 326034 E0200564 8C2106E8 */  lw        $at, 0x6e8($at)
/* 326038 E0200568 00200008 */  jr        $at
/* 32603C E020056C 00000000 */   nop      
