.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80242C2C
/* 135F6C 80242C2C 10400025 */  beqz  $v0, .L80242CC4
/* 135F70 80242C30 00000000 */   nop   
