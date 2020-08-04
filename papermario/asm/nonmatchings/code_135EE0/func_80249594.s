.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249594
/* 13C8D4 80249594 AC2000CC */  sw    $zero, 0xcc($at)
