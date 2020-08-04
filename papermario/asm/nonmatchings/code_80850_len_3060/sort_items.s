.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sort_items
/* 080B7C 800E76CC 24060008 */  addiu $a2, $zero, 8
/* 080B80 800E76D0 3C088011 */  lui   $t0, 0x8011
/* 080B84 800E76D4 2508F290 */  addiu $t0, $t0, -0xd70
/* 080B88 800E76D8 25070010 */  addiu $a3, $t0, 0x10
.L800E76DC:
/* 080B8C 800E76DC 84E201B4 */  lh    $v0, 0x1b4($a3)
/* 080B90 800E76E0 50400012 */  beql  $v0, $zero, .L800E772C
/* 080B94 800E76E4 24C6FFFF */   addiu $a2, $a2, -1
/* 080B98 800E76E8 24040009 */  addiu $a0, $zero, 9
/* 080B9C 800E76EC 00C4102A */  slt   $v0, $a2, $a0
/* 080BA0 800E76F0 5040000E */  beql  $v0, $zero, .L800E772C
/* 080BA4 800E76F4 24C6FFFF */   addiu $a2, $a2, -1
/* 080BA8 800E76F8 00E0282D */  daddu $a1, $a3, $zero
/* 080BAC 800E76FC 25030012 */  addiu $v1, $t0, 0x12
.L800E7700:
/* 080BB0 800E7700 846201B4 */  lh    $v0, 0x1b4($v1)
/* 080BB4 800E7704 54400005 */  bnezl $v0, .L800E771C
/* 080BB8 800E7708 2484FFFF */   addiu $a0, $a0, -1
/* 080BBC 800E770C 94A201B4 */  lhu   $v0, 0x1b4($a1)
/* 080BC0 800E7710 A46201B4 */  sh    $v0, 0x1b4($v1)
/* 080BC4 800E7714 08039DCA */  j     .L800E7728
/* 080BC8 800E7718 A4A001B4 */   sh    $zero, 0x1b4($a1)

.L800E771C:
/* 080BCC 800E771C 00C4102A */  slt   $v0, $a2, $a0
/* 080BD0 800E7720 1440FFF7 */  bnez  $v0, .L800E7700
/* 080BD4 800E7724 2463FFFE */   addiu $v1, $v1, -2
.L800E7728:
/* 080BD8 800E7728 24C6FFFF */  addiu $a2, $a2, -1
.L800E772C:
/* 080BDC 800E772C 04C1FFEB */  bgez  $a2, .L800E76DC
/* 080BE0 800E7730 24E7FFFE */   addiu $a3, $a3, -2
/* 080BE4 800E7734 03E00008 */  jr    $ra
/* 080BE8 800E7738 00000000 */   nop   

