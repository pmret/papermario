.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248D40
/* 13C080 80248D40 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13C084 80248D44 240700FF */  addiu $a3, $zero, 0xff
/* 13C088 80248D48 AFA00010 */  sw    $zero, 0x10($sp)
/* 13C08C 80248D4C AFB00014 */  sw    $s0, 0x14($sp)
/* 13C090 80248D50 2565005A */  addiu $a1, $t3, 0x5a
