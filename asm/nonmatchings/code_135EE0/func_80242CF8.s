.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80242CF8
/* 136038 80242CF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 13603C 80242CFC 03E00008 */  jr    $ra
/* 136040 80242D00 27BD0028 */   addiu $sp, $sp, 0x28

