.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200600
/* 3260D0 E0200600 3C01E020 */  lui       $at, 0xe020
/* 3260D4 E0200604 8C210710 */  lw        $at, 0x710($at)
/* 3260D8 E0200608 00200008 */  jr        $at
/* 3260DC E020060C 00000000 */   nop      
