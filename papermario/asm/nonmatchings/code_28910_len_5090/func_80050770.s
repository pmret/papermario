.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80050770
/* 02BB70 80050770 44852000 */  mtc1  $a1, $f4
/* 02BB74 80050774 3C014000 */  lui   $at, 0x4000
/* 02BB78 80050778 44810800 */  mtc1  $at, $f1
/* 02BB7C 8005077C 44800000 */  mtc1  $zero, $f0
/* 02BB80 80050780 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02BB84 80050784 AFB00010 */  sw    $s0, 0x10($sp)
/* 02BB88 80050788 0080802D */  daddu $s0, $a0, $zero
/* 02BB8C 8005078C 460020A1 */  cvt.d.s $f2, $f4
/* 02BB90 80050790 4622003C */  c.lt.d $f0, $f2
/* 02BB94 80050794 00000000 */  nop   
/* 02BB98 80050798 45000005 */  bc1f  .L800507B0
/* 02BB9C 8005079C AFBF0014 */   sw    $ra, 0x14($sp)
/* 02BBA0 800507A0 3C014000 */  lui   $at, 0x4000
/* 02BBA4 800507A4 44812000 */  mtc1  $at, $f4
/* 02BBA8 800507A8 080141F6 */  j     .L800507D8
/* 02BBAC 800507AC 00000000 */   nop   

.L800507B0:
/* 02BBB0 800507B0 3C013FD0 */  lui   $at, 0x3fd0
/* 02BBB4 800507B4 44810800 */  mtc1  $at, $f1
/* 02BBB8 800507B8 44800000 */  mtc1  $zero, $f0
/* 02BBBC 800507BC 00000000 */  nop   
/* 02BBC0 800507C0 4620103C */  c.lt.d $f2, $f0
/* 02BBC4 800507C4 00000000 */  nop   
/* 02BBC8 800507C8 45000003 */  bc1f  .L800507D8
/* 02BBCC 800507CC 00000000 */   nop   
/* 02BBD0 800507D0 3C013E80 */  lui   $at, 0x3e80
/* 02BBD4 800507D4 44812000 */  mtc1  $at, $f4
.L800507D8:
/* 02BBD8 800507D8 96050208 */  lhu   $a1, 0x208($s0)
/* 02BBDC 800507DC 0200202D */  daddu $a0, $s0, $zero
/* 02BBE0 800507E0 0C013F02 */  jal   func_8004FC08
/* 02BBE4 800507E4 E60400D0 */   swc1  $f4, 0xd0($s0)
/* 02BBE8 800507E8 00021880 */  sll   $v1, $v0, 2
/* 02BBEC 800507EC 00621821 */  addu  $v1, $v1, $v0
/* 02BBF0 800507F0 00031840 */  sll   $v1, $v1, 1
/* 02BBF4 800507F4 AE0200B0 */  sw    $v0, 0xb0($s0)
/* 02BBF8 800507F8 AE030008 */  sw    $v1, 8($s0)
/* 02BBFC 800507FC AE0000BC */  sw    $zero, 0xbc($s0)
/* 02BC00 80050800 AE0000B8 */  sw    $zero, 0xb8($s0)
/* 02BC04 80050804 AE0000B4 */  sw    $zero, 0xb4($s0)
/* 02BC08 80050808 8FBF0014 */  lw    $ra, 0x14($sp)
/* 02BC0C 8005080C 8FB00010 */  lw    $s0, 0x10($sp)
/* 02BC10 80050810 03E00008 */  jr    $ra
/* 02BC14 80050814 27BD0018 */   addiu $sp, $sp, 0x18

