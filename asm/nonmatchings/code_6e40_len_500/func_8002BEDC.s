.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8002BEDC
/* 0072DC 8002BEDC 3C01800A */  lui   $at, 0x800a
/* 0072E0 8002BEE0 E42CBA94 */  swc1  $f12, -0x456c($at)
/* 0072E4 8002BEE4 03E00008 */  jr    $ra
/* 0072E8 8002BEE8 00000000 */   nop   

