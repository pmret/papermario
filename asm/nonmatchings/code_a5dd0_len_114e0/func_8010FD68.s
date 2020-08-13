.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8010FD68
/* 0A6468 8010FD68 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A646C 8010FD6C AFB00010 */  sw    $s0, 0x10($sp)
/* 0A6470 8010FD70 0080802D */  daddu $s0, $a0, $zero
/* 0A6474 8010FD74 AFBF0014 */  sw    $ra, 0x14($sp)
.L8010FD78:
/* 0A6478 8010FD78 0C043EF6 */  jal   func_8010FBD8
/* 0A647C 8010FD7C 0200202D */   daddu $a0, $s0, $zero
/* 0A6480 8010FD80 1440FFFD */  bnez  $v0, .L8010FD78
/* 0A6484 8010FD84 00000000 */   nop   
/* 0A6488 8010FD88 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A648C 8010FD8C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A6490 8010FD90 03E00008 */  jr    $ra
/* 0A6494 8010FD94 27BD0018 */   addiu $sp, $sp, 0x18

