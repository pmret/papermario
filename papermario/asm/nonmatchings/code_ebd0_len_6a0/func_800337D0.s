.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800337D0
/* 00EBD0 800337D0 3C028007 */  lui   $v0, 0x8007
/* 00EBD4 800337D4 8C42419C */  lw    $v0, 0x419c($v0)
/* 00EBD8 800337D8 03E00008 */  jr    $ra
/* 00EBDC 800337DC A44400B6 */   sh    $a0, 0xb6($v0)

