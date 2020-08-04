.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80034FF0
/* 0103F0 80034FF0 03E00008 */  jr    $ra
/* 0103F4 80034FF4 00000000 */   nop   

/* 0103F8 80034FF8 00000000 */  nop   
/* 0103FC 80034FFC 00000000 */  nop   
