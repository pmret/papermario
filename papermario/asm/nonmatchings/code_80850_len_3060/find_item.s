.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel find_item
/* 080AF4 800E7644 00041140 */  sll   $v0, $a0, 5
/* 080AF8 800E7648 3C018008 */  lui   $at, 0x8008
/* 080AFC 800E764C 00220821 */  addu  $at, $at, $v0
/* 080B00 800E7650 942278F8 */  lhu   $v0, 0x78f8($at)
/* 080B04 800E7654 3C038011 */  lui   $v1, 0x8011
/* 080B08 800E7658 2463F290 */  addiu $v1, $v1, -0xd70
/* 080B0C 800E765C 30420008 */  andi  $v0, $v0, 8
/* 080B10 800E7660 1040000D */  beqz  $v0, .L800E7698
/* 080B14 800E7664 0000282D */   daddu $a1, $zero, $zero
.L800E7668:
/* 080B18 800E7668 84620074 */  lh    $v0, 0x74($v1)
/* 080B1C 800E766C 50440006 */  beql  $v0, $a0, .L800E7688
/* 080B20 800E7670 28A30020 */   slti  $v1, $a1, 0x20
/* 080B24 800E7674 24A50001 */  addiu $a1, $a1, 1
/* 080B28 800E7678 28A20020 */  slti  $v0, $a1, 0x20
/* 080B2C 800E767C 1440FFFA */  bnez  $v0, .L800E7668
/* 080B30 800E7680 24630002 */   addiu $v1, $v1, 2
/* 080B34 800E7684 28A30020 */  slti  $v1, $a1, 0x20
.L800E7688:
/* 080B38 800E7688 1060000E */  beqz  $v1, .L800E76C4
/* 080B3C 800E768C 2402FFFF */   addiu $v0, $zero, -1
/* 080B40 800E7690 03E00008 */  jr    $ra
/* 080B44 800E7694 00A0102D */   daddu $v0, $a1, $zero

.L800E7698:
/* 080B48 800E7698 846201B4 */  lh    $v0, 0x1b4($v1)
/* 080B4C 800E769C 50440006 */  beql  $v0, $a0, .L800E76B8
/* 080B50 800E76A0 2403000A */   addiu $v1, $zero, 0xa
/* 080B54 800E76A4 24A50001 */  addiu $a1, $a1, 1
/* 080B58 800E76A8 28A2000A */  slti  $v0, $a1, 0xa
/* 080B5C 800E76AC 1440FFFA */  bnez  $v0, .L800E7698
/* 080B60 800E76B0 24630002 */   addiu $v1, $v1, 2
/* 080B64 800E76B4 2403000A */  addiu $v1, $zero, 0xa
.L800E76B8:
/* 080B68 800E76B8 10A30002 */  beq   $a1, $v1, .L800E76C4
/* 080B6C 800E76BC 2402FFFF */   addiu $v0, $zero, -1
/* 080B70 800E76C0 00A0102D */  daddu $v0, $a1, $zero
.L800E76C4:
/* 080B74 800E76C4 03E00008 */  jr    $ra
/* 080B78 800E76C8 00000000 */   nop   

