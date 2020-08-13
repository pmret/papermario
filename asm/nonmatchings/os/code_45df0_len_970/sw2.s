.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sw2
/* 0462A0 8006AEA0 2401FDFF */  addiu $at, $zero, -0x201
/* 0462A4 8006AEA4 01014024 */  and   $t0, $t0, $at
/* 0462A8 8006AEA8 40886800 */  mtc0  $t0, $13
/* 0462AC 8006AEAC 24040008 */  addiu $a0, $zero, 8
/* 0462B0 8006AEB0 0C01ABDF */  jal   send_mesg
/* 0462B4 8006AEB4 00000000 */   nop   
/* 0462B8 8006AEB8 2401FDFF */  addiu $at, $zero, -0x201
/* 0462BC 8006AEBC 1000FF53 */  b     .L8006AC0C
/* 0462C0 8006AEC0 02018024 */   and   $s0, $s0, $at
