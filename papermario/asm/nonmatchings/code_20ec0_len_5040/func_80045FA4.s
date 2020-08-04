.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80045FA4
/* 0213A4 80045FA4 3C02800A */  lui   $v0, 0x800a
/* 0213A8 80045FA8 8C420F40 */  lw    $v0, 0xf40($v0)
/* 0213AC 80045FAC 03E00008 */  jr    $ra
/* 0213B0 80045FB0 00000000 */   nop   

