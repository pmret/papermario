.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel panic
.L8006AF4C:
/* 04634C 8006AF4C 3C018009 */  lui   $at, 0x8009
/* 046350 8006AF50 AC3A4664 */  sw    $k0, 0x4664($at)
/* 046354 8006AF54 24090001 */  addiu $t1, $zero, 1
/* 046358 8006AF58 A7490010 */  sh    $t1, 0x10($k0)
/* 04635C 8006AF5C 24090002 */  addiu $t1, $zero, 2
/* 046360 8006AF60 A7490012 */  sh    $t1, 0x12($k0)
/* 046364 8006AF64 400A4000 */  mfc0  $t2, $8
/* 046368 8006AF68 AF4A0124 */  sw    $t2, 0x124($k0)
/* 04636C 8006AF6C 0C01ABDF */  jal   send_mesg
/* 046370 8006AF70 24040060 */   addiu $a0, $zero, 0x60
/* 046374 8006AF74 0801AC75 */  j     osDispatchThread
/* 046378 8006AF78 00000000 */   nop   

