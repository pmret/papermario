.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si
.L8006AD90:
/* 046190 8006AD90 32290002 */  andi  $t1, $s1, 2
/* 046194 8006AD94 11200008 */  beqz  $t1, .L8006ADB8
/* 046198 8006AD98 00000000 */   nop   
/* 04619C 8006AD9C 3231003D */  andi  $s1, $s1, 0x3d
/* 0461A0 8006ADA0 3C01A480 */  lui   $at, 0xa480
/* 0461A4 8006ADA4 AC200018 */  sw    $zero, 0x18($at)
/* 0461A8 8006ADA8 0C01ABDF */  jal   send_mesg
/* 0461AC 8006ADAC 24040028 */   addiu $a0, $zero, 0x28
/* 0461B0 8006ADB0 1220001F */  beqz  $s1, .L8006AE30
/* 0461B4 8006ADB4 00000000 */   nop   
