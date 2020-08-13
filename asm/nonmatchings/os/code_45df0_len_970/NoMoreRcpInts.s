.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel NoMoreRcpInts
.L8006AE30:
/* 046230 8006AE30 2401FBFF */  addiu $at, $zero, -0x401
/* 046234 8006AE34 1000FF75 */  b     .L8006AC0C
/* 046238 8006AE38 02018024 */   and   $s0, $s0, $at
