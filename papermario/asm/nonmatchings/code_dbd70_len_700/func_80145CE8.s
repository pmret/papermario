.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80145CE8
/* 0DC3E8 80145CE8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DC3EC 80145CEC AFB00010 */  sw    $s0, 0x10($sp)
/* 0DC3F0 80145CF0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DC3F4 80145CF4 0C0394BE */  jal   func_800E52F8
/* 0DC3F8 80145CF8 0080802D */   daddu $s0, $a0, $zero
/* 0DC3FC 80145CFC 14400003 */  bnez  $v0, .L80145D0C
/* 0DC400 80145D00 0000282D */   daddu $a1, $zero, $zero
/* 0DC404 80145D04 08051756 */  j     .L80145D58
/* 0DC408 80145D08 0000102D */   daddu $v0, $zero, $zero

.L80145D0C:
/* 0DC40C 80145D0C 3C048016 */  lui   $a0, 0x8016
/* 0DC410 80145D10 8C849390 */  lw    $a0, -0x6c70($a0)
.L80145D14:
/* 0DC414 80145D14 8C830000 */  lw    $v1, ($a0)
/* 0DC418 80145D18 5060000B */  beql  $v1, $zero, .L80145D48
/* 0DC41C 80145D1C 24A50001 */   addiu $a1, $a1, 1
/* 0DC420 80145D20 90620030 */  lbu   $v0, 0x30($v1)
/* 0DC424 80145D24 10400008 */  beqz  $v0, .L80145D48
/* 0DC428 80145D28 24A50001 */   addiu $a1, $a1, 1
/* 0DC42C 80145D2C 8C620008 */  lw    $v0, 8($v1)
/* 0DC430 80145D30 14500005 */  bne   $v0, $s0, .L80145D48
/* 0DC434 80145D34 00000000 */   nop   
/* 0DC438 80145D38 8C620000 */  lw    $v0, ($v1)
/* 0DC43C 80145D3C 30420100 */  andi  $v0, $v0, 0x100
/* 0DC440 80145D40 14400005 */  bnez  $v0, .L80145D58
/* 0DC444 80145D44 24020001 */   addiu $v0, $zero, 1
.L80145D48:
/* 0DC448 80145D48 28A20040 */  slti  $v0, $a1, 0x40
/* 0DC44C 80145D4C 1440FFF1 */  bnez  $v0, .L80145D14
/* 0DC450 80145D50 24840004 */   addiu $a0, $a0, 4
/* 0DC454 80145D54 0000102D */  daddu $v0, $zero, $zero
.L80145D58:
/* 0DC458 80145D58 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DC45C 80145D5C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DC460 80145D60 03E00008 */  jr    $ra
/* 0DC464 80145D64 27BD0018 */   addiu $sp, $sp, 0x18

/* 0DC468 80145D68 00000000 */  nop   
/* 0DC46C 80145D6C 00000000 */  nop   

.set reorder
