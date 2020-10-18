.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200530
/* 326000 E0200530 3C01E020 */  lui       $at, 0xe020
/* 326004 E0200534 8C2106DC */  lw        $at, 0x6dc($at)
/* 326008 E0200538 00200008 */  jr        $at
/* 32600C E020053C 00000000 */   nop      
