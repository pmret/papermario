.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_badge
/* 080BEC 800E773C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 080BF0 800E7740 00041140 */  sll   $v0, $a0, 5
/* 080BF4 800E7744 AFBF0010 */  sw    $ra, 0x10($sp)
/* 080BF8 800E7748 3C018008 */  lui   $at, 0x8008
/* 080BFC 800E774C 00220821 */  addu  $at, $at, $v0
/* 080C00 800E7750 942278F8 */  lhu   $v0, 0x78f8($at)
/* 080C04 800E7754 3C068011 */  lui   $a2, 0x8011
/* 080C08 800E7758 24C6F290 */  addiu $a2, $a2, -0xd70
/* 080C0C 800E775C 30420040 */  andi  $v0, $v0, 0x40
/* 080C10 800E7760 14400005 */  bnez  $v0, .L800E7778
/* 080C14 800E7764 0000182D */   daddu $v1, $zero, $zero
/* 080C18 800E7768 0C039D5D */  jal   add_item
/* 080C1C 800E776C 00000000 */   nop   
/* 080C20 800E7770 08039DEE */  j     .L800E77B8
/* 080C24 800E7774 00000000 */   nop   

.L800E7778:
/* 080C28 800E7778 00C0282D */  daddu $a1, $a2, $zero
.L800E777C:
/* 080C2C 800E777C 84A200B4 */  lh    $v0, 0xb4($a1)
/* 080C30 800E7780 10400006 */  beqz  $v0, .L800E779C
/* 080C34 800E7784 28620080 */   slti  $v0, $v1, 0x80
/* 080C38 800E7788 24630001 */  addiu $v1, $v1, 1
/* 080C3C 800E778C 28620080 */  slti  $v0, $v1, 0x80
/* 080C40 800E7790 1440FFFA */  bnez  $v0, .L800E777C
/* 080C44 800E7794 24A50002 */   addiu $a1, $a1, 2
/* 080C48 800E7798 28620080 */  slti  $v0, $v1, 0x80
.L800E779C:
/* 080C4C 800E779C 10400005 */  beqz  $v0, .L800E77B4
/* 080C50 800E77A0 00031040 */   sll   $v0, $v1, 1
/* 080C54 800E77A4 00C21021 */  addu  $v0, $a2, $v0
/* 080C58 800E77A8 A44400B4 */  sh    $a0, 0xb4($v0)
/* 080C5C 800E77AC 08039DEE */  j     .L800E77B8
/* 080C60 800E77B0 0060102D */   daddu $v0, $v1, $zero

.L800E77B4:
/* 080C64 800E77B4 0000102D */  daddu $v0, $zero, $zero
.L800E77B8:
/* 080C68 800E77B8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 080C6C 800E77BC 03E00008 */  jr    $ra
/* 080C70 800E77C0 27BD0018 */   addiu $sp, $sp, 0x18

