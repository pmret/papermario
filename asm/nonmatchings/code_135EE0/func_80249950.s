.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249950
.L80249950:
/* 13CC90 80249950 03E00008 */  jr    $ra
