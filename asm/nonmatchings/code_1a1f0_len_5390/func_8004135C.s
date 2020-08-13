.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004135C
/* 01C75C 8004135C 03E00008 */  jr    $ra
/* 01C760 80041360 00000000 */   nop   

