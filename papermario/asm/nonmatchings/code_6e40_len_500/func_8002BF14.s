.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8002BF14
/* 007314 8002BF14 3C01800A */  lui   $at, 0x800a
/* 007318 8002BF18 E42CBA9C */  swc1  $f12, -0x4564($at)
/* 00731C 8002BF1C 03E00008 */  jr    $ra
/* 007320 8002BF20 00000000 */   nop   

