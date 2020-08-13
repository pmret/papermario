.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel sw1
/* 0462C4 8006AEC4 2401FEFF */  addiu $at, $zero, -0x101
/* 0462C8 8006AEC8 01014024 */  and   $t0, $t0, $at
/* 0462CC 8006AECC 40886800 */  mtc0  $t0, $13
/* 0462D0 8006AED0 24040000 */  addiu $a0, $zero, 0
/* 0462D4 8006AED4 0C01ABDF */  jal   send_mesg
/* 0462D8 8006AED8 00000000 */   nop   
/* 0462DC 8006AEDC 2401FEFF */  addiu $at, $zero, -0x101
/* 0462E0 8006AEE0 1000FF4A */  b     .L8006AC0C
/* 0462E4 8006AEE4 02018024 */   and   $s0, $s0, $at
