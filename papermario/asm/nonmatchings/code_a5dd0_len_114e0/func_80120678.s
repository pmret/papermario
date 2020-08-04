.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80120678
/* 0B6D78 80120678 27BDFE00 */  addiu $sp, $sp, -0x200
/* 0B6D7C 8012067C AFB001F8 */  sw    $s0, 0x1f8($sp)
/* 0B6D80 80120680 AFBF01FC */  sw    $ra, 0x1fc($sp)
/* 0B6D84 80120684 0C047900 */  jal   func_8011E400
/* 0B6D88 80120688 0080802D */   daddu $s0, $a0, $zero
/* 0B6D8C 8012068C 24040079 */  addiu $a0, $zero, 0x79
/* 0B6D90 80120690 8E0202C8 */  lw    $v0, 0x2c8($s0)
/* 0B6D94 80120694 27A301F4 */  addiu $v1, $sp, 0x1f4
/* 0B6D98 80120698 3C018015 */  lui   $at, 0x8015
/* 0B6D9C 8012069C AC223B68 */  sw    $v0, 0x3b68($at)
.L801206A0:
/* 0B6DA0 801206A0 AC600000 */  sw    $zero, ($v1)
/* 0B6DA4 801206A4 2484FFFF */  addiu $a0, $a0, -1
/* 0B6DA8 801206A8 0481FFFD */  bgez  $a0, .L801206A0
/* 0B6DAC 801206AC 2463FFFC */   addiu $v1, $v1, -4
/* 0B6DB0 801206B0 0200282D */  daddu $a1, $s0, $zero
/* 0B6DB4 801206B4 8E0202CC */  lw    $v0, 0x2cc($s0)
/* 0B6DB8 801206B8 0000302D */  daddu $a2, $zero, $zero
/* 0B6DBC 801206BC 00021080 */  sll   $v0, $v0, 2
/* 0B6DC0 801206C0 02021021 */  addu  $v0, $s0, $v0
/* 0B6DC4 801206C4 8C4400E0 */  lw    $a0, 0xe0($v0)
/* 0B6DC8 801206C8 0C04814C */  jal   func_80120530
/* 0B6DCC 801206CC 27A70010 */   addiu $a3, $sp, 0x10
/* 0B6DD0 801206D0 0200202D */  daddu $a0, $s0, $zero
/* 0B6DD4 801206D4 27A50010 */  addiu $a1, $sp, 0x10
/* 0B6DD8 801206D8 2406007A */  addiu $a2, $zero, 0x7a
/* 0B6DDC 801206DC 2402FFFF */  addiu $v0, $zero, -1
/* 0B6DE0 801206E0 0C047FED */  jal   func_8011FFB4
/* 0B6DE4 801206E4 AFA20010 */   sw    $v0, 0x10($sp)
/* 0B6DE8 801206E8 8FBF01FC */  lw    $ra, 0x1fc($sp)
/* 0B6DEC 801206EC 8FB001F8 */  lw    $s0, 0x1f8($sp)
/* 0B6DF0 801206F0 03E00008 */  jr    $ra
/* 0B6DF4 801206F4 27BD0200 */   addiu $sp, $sp, 0x200

