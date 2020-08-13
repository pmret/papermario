.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel handle_break
.L8006AEE8:
/* 0462E8 8006AEE8 24090001 */  addiu $t1, $zero, 1
/* 0462EC 8006AEEC A7490012 */  sh    $t1, 0x12($k0)
/* 0462F0 8006AEF0 0C01ABDF */  jal   send_mesg
/* 0462F4 8006AEF4 24040050 */   addiu $a0, $zero, 0x50
/* 0462F8 8006AEF8 10000001 */  b     .L8006AF00
/* 0462FC 8006AEFC 00000000 */   nop   
