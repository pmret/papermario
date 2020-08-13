.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80057ED0
/* 0332D0 80057ED0 0000302D */  daddu $a2, $zero, $zero
/* 0332D4 80057ED4 3C05800A */  lui   $a1, 0x800a
/* 0332D8 80057ED8 8CA53FE0 */  lw    $a1, 0x3fe0($a1)
/* 0332DC 80057EDC 3C03800A */  lui   $v1, 0x800a
/* 0332E0 80057EE0 8C633FE4 */  lw    $v1, 0x3fe4($v1)
.L80057EE4:
/* 0332E4 80057EE4 ACA00000 */  sw    $zero, ($a1)
/* 0332E8 80057EE8 24A50004 */  addiu $a1, $a1, 4
/* 0332EC 80057EEC AC600000 */  sw    $zero, ($v1)
/* 0332F0 80057EF0 24C60001 */  addiu $a2, $a2, 1
/* 0332F4 80057EF4 28C20170 */  slti  $v0, $a2, 0x170
/* 0332F8 80057EF8 1440FFFA */  bnez  $v0, .L80057EE4
/* 0332FC 80057EFC 24630004 */   addiu $v1, $v1, 4
/* 033300 80057F00 3C01800A */  lui   $at, 0x800a
/* 033304 80057F04 A0203FEC */  sb    $zero, 0x3fec($at)
/* 033308 80057F08 3C01800A */  lui   $at, 0x800a
/* 03330C 80057F0C A4243FEE */  sh    $a0, 0x3fee($at)
/* 033310 80057F10 3C01800A */  lui   $at, 0x800a
/* 033314 80057F14 AC203FE8 */  sw    $zero, 0x3fe8($at)
/* 033318 80057F18 03E00008 */  jr    $ra
/* 03331C 80057F1C 00000000 */   nop   

