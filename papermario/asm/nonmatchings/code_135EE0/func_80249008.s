.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249008
/* 13C348 80249008 24027FFE */  addiu $v0, $zero, 0x7ffe
/* 13C34C 8024900C 14620003 */  bne   $v1, $v0, .L8024901C
/* 13C350 80249010 0000802D */   daddu $s0, $zero, $zero
/* 13C354 80249014 08092423 */  j     func_8024908C
/* 13C358 80249018 A2600000 */   sb    $zero, ($s3)

.L8024901C:
/* 13C35C 8024901C 3C128027 */  lui   $s2, 0x8027
/* 13C360 80249020 265203A8 */  addiu $s2, $s2, 0x3a8
/* 13C364 80249024 3C118025 */  lui   $s1, 0x8025
/* 13C368 80249028 2631F4D0 */  addiu $s1, $s1, -0xb30
.L8024902C:
/* 13C36C 8024902C 8E240000 */  lw    $a0, ($s1)
/* 13C370 80249030 26310004 */  addiu $s1, $s1, 4
