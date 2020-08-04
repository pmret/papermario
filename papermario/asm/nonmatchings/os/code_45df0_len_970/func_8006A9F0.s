.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8006A9F0
/* 045DF0 8006A9F0 3C1A8007 */  lui   $k0, 0x8007
/* 045DF4 8006A9F4 275AAA00 */  addiu $k0, $k0, -0x5600
/* 045DF8 8006A9F8 03400008 */  jr    $k0
/* 045DFC 8006A9FC 00000000 */   nop  
