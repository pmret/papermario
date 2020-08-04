.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80050C54
/* 02C054 80050C54 3C02800A */  lui   $v0, 0x800a
/* 02C058 80050C58 8C42A628 */  lw    $v0, -0x59d8($v0)
/* 02C05C 80050C5C 03E00008 */  jr    $ra
/* 02C060 80050C60 A0450021 */   sb    $a1, 0x21($v0)

