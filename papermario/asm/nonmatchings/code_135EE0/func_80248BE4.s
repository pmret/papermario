.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248BE4
/* 13BF24 80248BE4 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13BF28 80248BE8 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13BF2C 80248BEC 01652821 */  addu  $a1, $t3, $a1
/* 13BF30 80248BF0 01463021 */  addu  $a2, $t2, $a2
