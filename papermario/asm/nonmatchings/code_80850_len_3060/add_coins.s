.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_coins
/* 083570 800EA0C0 3C038011 */  lui   $v1, 0x8011
/* 083574 800EA0C4 2463F290 */  addiu $v1, $v1, -0xd70
/* 083578 800EA0C8 9462000C */  lhu   $v0, 0xc($v1)
/* 08357C 800EA0CC 00441021 */  addu  $v0, $v0, $a0
/* 083580 800EA0D0 A462000C */  sh    $v0, 0xc($v1)
/* 083584 800EA0D4 00021400 */  sll   $v0, $v0, 0x10
/* 083588 800EA0D8 00021403 */  sra   $v0, $v0, 0x10
/* 08358C 800EA0DC 284203E8 */  slti  $v0, $v0, 0x3e8
/* 083590 800EA0E0 14400002 */  bnez  $v0, .L800EA0EC
/* 083594 800EA0E4 240203E7 */   addiu $v0, $zero, 0x3e7
/* 083598 800EA0E8 A462000C */  sh    $v0, 0xc($v1)
.L800EA0EC:
/* 08359C 800EA0EC 8462000C */  lh    $v0, 0xc($v1)
/* 0835A0 800EA0F0 04420001 */  bltzl $v0, .L800EA0F8
/* 0835A4 800EA0F4 A460000C */   sh    $zero, 0xc($v1)
.L800EA0F8:
/* 0835A8 800EA0F8 18800008 */  blez  $a0, .L800EA11C
/* 0835AC 800EA0FC 3C050001 */   lui   $a1, 1
/* 0835B0 800EA100 8C6202B4 */  lw    $v0, 0x2b4($v1)
/* 0835B4 800EA104 34A5869F */  ori   $a1, $a1, 0x869f
/* 0835B8 800EA108 00441021 */  addu  $v0, $v0, $a0
/* 0835BC 800EA10C AC6202B4 */  sw    $v0, 0x2b4($v1)
/* 0835C0 800EA110 00A2102B */  sltu  $v0, $a1, $v0
/* 0835C4 800EA114 54400001 */  bnezl $v0, .L800EA11C
/* 0835C8 800EA118 AC6502B4 */   sw    $a1, 0x2b4($v1)
.L800EA11C:
/* 0835CC 800EA11C 8462000C */  lh    $v0, 0xc($v1)
/* 0835D0 800EA120 03E00008 */  jr    $ra
/* 0835D4 800EA124 00000000 */   nop   

