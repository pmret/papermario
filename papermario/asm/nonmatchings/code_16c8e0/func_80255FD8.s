.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80255FD8
/* 1848B8 80255FD8 03E00008 */  jr    $ra
/* 1848BC 80255FDC 00000000 */   nop   

