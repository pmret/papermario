.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055448
/* 030848 80055448 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03084C 8005544C AFBF0010 */  sw    $ra, 0x10($sp)
/* 030850 80055450 0C014FE0 */  jal   func_80053F80
/* 030854 80055454 00000000 */   nop   
/* 030858 80055458 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03085C 8005545C 03E00008 */  jr    $ra
/* 030860 80055460 27BD0018 */   addiu $sp, $sp, 0x18

