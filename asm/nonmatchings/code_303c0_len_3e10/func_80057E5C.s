.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80057E5C
/* 03325C 80057E5C 0000302D */  daddu $a2, $zero, $zero
/* 033260 80057E60 3C05800A */  lui   $a1, 0x800a
/* 033264 80057E64 8CA53FE0 */  lw    $a1, 0x3fe0($a1)
/* 033268 80057E68 3C03800A */  lui   $v1, 0x800a
/* 03326C 80057E6C 8C633FE4 */  lw    $v1, 0x3fe4($v1)
.L80057E70:
/* 033270 80057E70 ACA00000 */  sw    $zero, ($a1)
/* 033274 80057E74 24A50004 */  addiu $a1, $a1, 4
/* 033278 80057E78 AC600000 */  sw    $zero, ($v1)
/* 03327C 80057E7C 24C60001 */  addiu $a2, $a2, 1
/* 033280 80057E80 28C20170 */  slti  $v0, $a2, 0x170
/* 033284 80057E84 1440FFFA */  bnez  $v0, .L80057E70
/* 033288 80057E88 24630004 */   addiu $v1, $v1, 4
/* 03328C 80057E8C 24020002 */  addiu $v0, $zero, 2
/* 033290 80057E90 3C01800A */  lui   $at, 0x800a
/* 033294 80057E94 A0243FEC */  sb    $a0, 0x3fec($at)
/* 033298 80057E98 3C01800A */  lui   $at, 0x800a
/* 03329C 80057E9C A4223FEE */  sh    $v0, 0x3fee($at)
/* 0332A0 80057EA0 3C01800A */  lui   $at, 0x800a
/* 0332A4 80057EA4 AC203FE8 */  sw    $zero, 0x3fe8($at)
/* 0332A8 80057EA8 03E00008 */  jr    $ra
/* 0332AC 80057EAC 00000000 */   nop   

