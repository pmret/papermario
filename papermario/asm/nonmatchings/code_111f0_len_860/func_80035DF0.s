.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80035DF0
/* 0111F0 80035DF0 3C01800A */  lui   $at, 0x800a
/* 0111F4 80035DF4 A4240942 */  sh    $a0, 0x942($at)
/* 0111F8 80035DF8 03E00008 */  jr    $ra
/* 0111FC 80035DFC 00000000 */   nop   

