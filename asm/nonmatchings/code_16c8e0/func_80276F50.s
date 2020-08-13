.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80276F50
/* 1A5830 80276F50 8C8301F4 */  lw    $v1, 0x1f4($a0)
/* 1A5834 80276F54 1060000B */  beqz  $v1, .L80276F84
/* 1A5838 80276F58 0000202D */   daddu $a0, $zero, $zero
/* 1A583C 80276F5C 3C05000C */  lui   $a1, 0xc
.L80276F60:
/* 1A5840 80276F60 8C62007C */  lw    $v0, 0x7c($v1)
/* 1A5844 80276F64 00451024 */  and   $v0, $v0, $a1
/* 1A5848 80276F68 10400003 */  beqz  $v0, .L80276F78
/* 1A584C 80276F6C 00000000 */   nop   
/* 1A5850 80276F70 0809DBE1 */  j     .L80276F84
/* 1A5854 80276F74 24040001 */   addiu $a0, $zero, 1

.L80276F78:
/* 1A5858 80276F78 8C63000C */  lw    $v1, 0xc($v1)
/* 1A585C 80276F7C 1460FFF8 */  bnez  $v1, .L80276F60
/* 1A5860 80276F80 00000000 */   nop   
.L80276F84:
.L80276F84:
/* 1A5864 80276F84 03E00008 */  jr    $ra
/* 1A5868 80276F88 0080102D */   daddu $v0, $a0, $zero

