.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_map_transition_effect
/* 0CE9A0 801382A0 3C018015 */  lui   $at, 0x8015
/* 0CE9A4 801382A4 03E00008 */  jr    $ra
/* 0CE9A8 801382A8 AC24C6F0 */   sw    $a0, -0x3910($at)

