.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_global_flag
/* 0DBBBC 801454BC 0080282D */  daddu $a1, $a0, $zero
/* 0DBBC0 801454C0 3C02F8D8 */  lui   $v0, 0xf8d8
/* 0DBBC4 801454C4 3442F200 */  ori   $v0, $v0, 0xf200
/* 0DBBC8 801454C8 0045102A */  slt   $v0, $v0, $a1
/* 0DBBCC 801454CC 14400003 */  bnez  $v0, .L801454DC
/* 0DBBD0 801454D0 3C0207BF */   lui   $v0, 0x7bf
/* 0DBBD4 801454D4 3442A480 */  ori   $v0, $v0, 0xa480
/* 0DBBD8 801454D8 00A22821 */  addu  $a1, $a1, $v0
.L801454DC:
/* 0DBBDC 801454DC 04A10002 */  bgez  $a1, .L801454E8
/* 0DBBE0 801454E0 00A0182D */   daddu $v1, $a1, $zero
/* 0DBBE4 801454E4 24A3001F */  addiu $v1, $a1, 0x1f
.L801454E8:
/* 0DBBE8 801454E8 00031943 */  sra   $v1, $v1, 5
/* 0DBBEC 801454EC 00032140 */  sll   $a0, $v1, 5
/* 0DBBF0 801454F0 00A42023 */  subu  $a0, $a1, $a0
/* 0DBBF4 801454F4 00031880 */  sll   $v1, $v1, 2
/* 0DBBF8 801454F8 24020001 */  addiu $v0, $zero, 1
/* 0DBBFC 801454FC 3C01800E */  lui   $at, 0x800e
/* 0DBC00 80145500 00230821 */  addu  $at, $at, $v1
/* 0DBC04 80145504 8C23BC70 */  lw    $v1, -0x4390($at)
/* 0DBC08 80145508 00821004 */  sllv  $v0, $v0, $a0
/* 0DBC0C 8014550C 00621024 */  and   $v0, $v1, $v0
/* 0DBC10 80145510 54400001 */  bnel  $v0, $zero, .L80145518
/* 0DBC14 80145514 24020001 */   addiu $v0, $zero, 1
.L80145518:
/* 0DBC18 80145518 03E00008 */  jr    $ra
/* 0DBC1C 8014551C 00000000 */   nop   

