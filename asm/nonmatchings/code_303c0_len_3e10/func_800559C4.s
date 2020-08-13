.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800559C4
/* 030DC4 800559C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 030DC8 800559C8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 030DCC 800559CC 0C013683 */  jal   func_8004DA0C
/* 030DD0 800559D0 00000000 */   nop   
/* 030DD4 800559D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 030DD8 800559D8 03E00008 */  jr    $ra
/* 030DDC 800559DC 27BD0018 */   addiu $sp, $sp, 0x18

/* 030DE0 800559E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 030DE4 800559E4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 030DE8 800559E8 0C01369D */  jal   func_8004DA74
/* 030DEC 800559EC 00000000 */   nop   
/* 030DF0 800559F0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 030DF4 800559F4 03E00008 */  jr    $ra
/* 030DF8 800559F8 27BD0018 */   addiu $sp, $sp, 0x18

