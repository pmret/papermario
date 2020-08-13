.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osNop
/* 0465CC 8006B1CC 03E00008 */  jr    $ra
/* 0465D0 8006B1D0 00000000 */   nop   

