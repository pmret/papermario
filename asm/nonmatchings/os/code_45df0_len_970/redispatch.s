.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel redispatch
.L8006AF00:
/* 046300 8006AF00 8F490004 */  lw    $t1, 4($k0)
/* 046304 8006AF04 3C0A8009 */  lui   $t2, 0x8009
/* 046308 8006AF08 8D4A4658 */  lw    $t2, 0x4658($t2)
/* 04630C 8006AF0C 8D4B0004 */  lw    $t3, 4($t2)
/* 046310 8006AF10 012B082A */  slt   $at, $t1, $t3
/* 046314 8006AF14 10200007 */  beqz  $at, .L8006AF34
/* 046318 8006AF18 00000000 */   nop   
/* 04631C 8006AF1C 03402821 */  addu  $a1, $k0, $zero
/* 046320 8006AF20 3C048009 */  lui   $a0, 0x8009
/* 046324 8006AF24 0C01AC5D */  jal   osEnqueueThread
/* 046328 8006AF28 24844658 */   addiu $a0, $a0, 0x4658
/* 04632C 8006AF2C 0801AC75 */  j     osDispatchThread
/* 046330 8006AF30 00000000 */   nop   

