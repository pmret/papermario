.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ai
.L8006AD64:
/* 046164 8006AD64 32290004 */  andi  $t1, $s1, 4
/* 046168 8006AD68 11200009 */  beqz  $t1, .L8006AD90
/* 04616C 8006AD6C 00000000 */   nop   
/* 046170 8006AD70 3231003B */  andi  $s1, $s1, 0x3b
/* 046174 8006AD74 24090001 */  addiu $t1, $zero, 1
/* 046178 8006AD78 3C01A450 */  lui   $at, 0xa450
/* 04617C 8006AD7C AC29000C */  sw    $t1, 0xc($at)
/* 046180 8006AD80 0C01ABDF */  jal   send_mesg
/* 046184 8006AD84 24040030 */   addiu $a0, $zero, 0x30
/* 046188 8006AD88 12200029 */  beqz  $s1, .L8006AE30
/* 04618C 8006AD8C 00000000 */   nop   
