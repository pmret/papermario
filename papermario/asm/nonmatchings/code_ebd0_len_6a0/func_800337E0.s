.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800337E0
/* 00EBE0 800337E0 3C028007 */  lui   $v0, 0x8007
/* 00EBE4 800337E4 8C42419C */  lw    $v0, 0x419c($v0)
/* 00EBE8 800337E8 A44400BC */  sh    $a0, 0xbc($v0)
/* 00EBEC 800337EC A44400BA */  sh    $a0, 0xba($v0)
/* 00EBF0 800337F0 03E00008 */  jr    $ra
/* 00EBF4 800337F4 A44400B8 */   sh    $a0, 0xb8($v0)

