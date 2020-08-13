.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80242CE8
/* 136028 80242CE8 8FB40020 */  lw    $s4, 0x20($sp)
/* 13602C 80242CEC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 136030 80242CF0 8FB20018 */  lw    $s2, 0x18($sp)
/* 136034 80242CF4 8FB10014 */  lw    $s1, 0x14($sp)
