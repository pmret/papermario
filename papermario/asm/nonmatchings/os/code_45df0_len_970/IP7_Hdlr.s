.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel IP7_Hdlr
/* 046050 8006AC50 2401BFFF */  addiu $at, $zero, -0x4001
/* 046054 8006AC54 1000FFED */  b     .L8006AC0C
/* 046058 8006AC58 02018024 */   and   $s0, $s0, $at
