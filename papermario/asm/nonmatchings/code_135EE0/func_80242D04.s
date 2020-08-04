.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80242D04
/* 136044 80242D04 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 136048 80242D08 AFB20018 */  sw    $s2, 0x18($sp)
/* 13604C 80242D0C 00A0902D */  daddu $s2, $a1, $zero
/* 136050 80242D10 AFB3001C */  sw    $s3, 0x1c($sp)
/* 136054 80242D14 00C0982D */  daddu $s3, $a2, $zero
/* 136058 80242D18 AFB40020 */  sw    $s4, 0x20($sp)
/* 13605C 80242D1C 3C148016 */  lui   $s4, 0x8016
