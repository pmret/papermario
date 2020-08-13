.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8005610C
/* 03150C 8005610C 3C05800A */  lui   $a1, 0x800a
/* 031510 80056110 8CA5A5C0 */  lw    $a1, -0x5a40($a1)
/* 031514 80056114 2404000F */  addiu $a0, $zero, 0xf
/* 031518 80056118 8CA30094 */  lw    $v1, 0x94($a1)
.L8005611C:
/* 03151C 8005611C AC600000 */  sw    $zero, ($v1)
/* 031520 80056120 24630004 */  addiu $v1, $v1, 4
/* 031524 80056124 0080102D */  daddu $v0, $a0, $zero
/* 031528 80056128 1440FFFC */  bnez  $v0, .L8005611C
/* 03152C 8005612C 2484FFFF */   addiu $a0, $a0, -1
/* 031530 80056130 8CA20094 */  lw    $v0, 0x94($a1)
/* 031534 80056134 ACA00098 */  sw    $zero, 0x98($a1)
/* 031538 80056138 ACA0009C */  sw    $zero, 0x9c($a1)
/* 03153C 8005613C 03E00008 */  jr    $ra
/* 031540 80056140 ACA20090 */   sw    $v0, 0x90($a1)

/* 031544 80056144 3C02800A */  lui   $v0, 0x800a
/* 031548 80056148 8C42A5C0 */  lw    $v0, -0x5a40($v0)
/* 03154C 8005614C 00052880 */  sll   $a1, $a1, 2
/* 031550 80056150 00451021 */  addu  $v0, $v0, $a1
/* 031554 80056154 03E00008 */  jr    $ra
/* 031558 80056158 AC4400A4 */   sw    $a0, 0xa4($v0)

