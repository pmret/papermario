.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249034
/* 13C374 80249034 0C050529 */  jal   create_icon
/* 13C378 80249038 26100001 */   addiu $s0, $s0, 1
/* 13C37C 8024903C 0040202D */  daddu $a0, $v0, $zero
/* 13C380 80249040 24050080 */  addiu $a1, $zero, 0x80
/* 13C384 80249044 0C051280 */  jal   set_icon_flags
/* 13C388 80249048 AE440000 */   sw    $a0, ($s2)
/* 13C38C 8024904C 2A020016 */  slti  $v0, $s0, 0x16
/* 13C390 80249050 1440FFF6 */  bnez  $v0, .L8024902C
/* 13C394 80249054 26520004 */   addiu $s2, $s2, 4
/* 13C398 80249058 0000802D */  daddu $s0, $zero, $zero
/* 13C39C 8024905C 3C028025 */  lui   $v0, 0x8025
/* 13C3A0 80249060 2442F528 */  addiu $v0, $v0, -0xad8
.L80249064:
/* 13C3A4 80249064 AC530010 */  sw    $s3, 0x10($v0)
/* 13C3A8 80249068 26100001 */  addiu $s0, $s0, 1
/* 13C3AC 8024906C 1A00FFFD */  blez  $s0, .L80249064
/* 13C3B0 80249070 24420024 */   addiu $v0, $v0, 0x24
/* 13C3B4 80249074 3C048025 */  lui   $a0, 0x8025
/* 13C3B8 80249078 2484F528 */  addiu $a0, $a0, -0xad8
/* 13C3BC 8024907C 0C051FCC */  jal   func_80147F30
/* 13C3C0 80249080 24050001 */   addiu $a1, $zero, 1
/* 13C3C4 80249084 24020001 */  addiu $v0, $zero, 1
/* 13C3C8 80249088 A2620000 */  sb    $v0, ($s3)
