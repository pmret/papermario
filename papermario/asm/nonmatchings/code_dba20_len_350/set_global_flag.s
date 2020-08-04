.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_global_flag
/* 0DBB50 80145450 3C02F8D8 */  lui   $v0, 0xf8d8
/* 0DBB54 80145454 3442F200 */  ori   $v0, $v0, 0xf200
/* 0DBB58 80145458 0044102A */  slt   $v0, $v0, $a0
/* 0DBB5C 8014545C 14400003 */  bnez  $v0, .L8014546C
/* 0DBB60 80145460 3C0207BF */   lui   $v0, 0x7bf
/* 0DBB64 80145464 3442A480 */  ori   $v0, $v0, 0xa480
/* 0DBB68 80145468 00822021 */  addu  $a0, $a0, $v0
.L8014546C:
/* 0DBB6C 8014546C 04810002 */  bgez  $a0, .L80145478
/* 0DBB70 80145470 0080102D */   daddu $v0, $a0, $zero
/* 0DBB74 80145474 2482001F */  addiu $v0, $a0, 0x1f
.L80145478:
/* 0DBB78 80145478 00021143 */  sra   $v0, $v0, 5
/* 0DBB7C 8014547C 00021940 */  sll   $v1, $v0, 5
/* 0DBB80 80145480 00831823 */  subu  $v1, $a0, $v1
/* 0DBB84 80145484 3C04800E */  lui   $a0, 0x800e
/* 0DBB88 80145488 2484ACC0 */  addiu $a0, $a0, -0x5340
/* 0DBB8C 8014548C 00021080 */  sll   $v0, $v0, 2
/* 0DBB90 80145490 00442821 */  addu  $a1, $v0, $a0
/* 0DBB94 80145494 24020001 */  addiu $v0, $zero, 1
/* 0DBB98 80145498 8CA40FB0 */  lw    $a0, 0xfb0($a1)
/* 0DBB9C 8014549C 00621004 */  sllv  $v0, $v0, $v1
/* 0DBBA0 801454A0 00821824 */  and   $v1, $a0, $v0
/* 0DBBA4 801454A4 54600001 */  bnel  $v1, $zero, .L801454AC
/* 0DBBA8 801454A8 24030001 */   addiu $v1, $zero, 1
.L801454AC:
/* 0DBBAC 801454AC 00821025 */  or    $v0, $a0, $v0
/* 0DBBB0 801454B0 ACA20FB0 */  sw    $v0, 0xfb0($a1)
/* 0DBBB4 801454B4 03E00008 */  jr    $ra
/* 0DBBB8 801454B8 0060102D */   daddu $v0, $v1, $zero

