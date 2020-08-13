.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247BB0
/* 13AEF0 80247BB0 8FAA00C4 */  lw    $t2, 0xc4($sp)
/* 13AEF4 80247BB4 245000EB */  addiu $s0, $v0, 0xeb
