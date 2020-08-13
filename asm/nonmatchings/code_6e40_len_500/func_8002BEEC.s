.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8002BEEC
/* 0072EC 8002BEEC 3C01800A */  lui   $at, 0x800a
/* 0072F0 8002BEF0 E42CBA94 */  swc1  $f12, -0x456c($at)
/* 0072F4 8002BEF4 3C01800A */  lui   $at, 0x800a
/* 0072F8 8002BEF8 E42CBA90 */  swc1  $f12, -0x4570($at)
/* 0072FC 8002BEFC 03E00008 */  jr    $ra
/* 007300 8002BF00 00000000 */   nop   

