.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sqrtf
/* 03D2F0 80061EF0 03E00008 */  jr    $ra
/* 03D2F4 80061EF4 46006004 */   sqrt.s $f0, $f12

/* 03D2F8 80061EF8 00000000 */  nop   
/* 03D2FC 80061EFC 00000000 */  nop   


