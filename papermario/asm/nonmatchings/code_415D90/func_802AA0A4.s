.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802AA0A4
/* 41EE34 802AA0A4 3C02800E */  lui   $v0, 0x800e
/* 41EE38 802AA0A8 8C42C074 */  lw    $v0, -0x3f8c($v0)
/* 41EE3C 802AA0AC 30420002 */  andi  $v0, $v0, 2
/* 41EE40 802AA0B0 03E00008 */  jr    $ra
/* 41EE44 802AA0B4 2C420001 */   sltiu $v0, $v0, 1

