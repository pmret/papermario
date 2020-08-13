.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247444
.L80247444:
/* 13A784 80247444 8FBF0018 */  lw    $ra, 0x18($sp)
/* 13A788 80247448 8FB10014 */  lw    $s1, 0x14($sp)
/* 13A78C 8024744C 8FB00010 */  lw    $s0, 0x10($sp)
/* 13A790 80247450 03E00008 */  jr    $ra
/* 13A794 80247454 27BD0020 */   addiu $sp, $sp, 0x20

