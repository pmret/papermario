.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetBlockResult
/* 197E5C 8026957C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197E60 80269580 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197E64 80269584 8C82000C */  lw    $v0, 0xc($a0)
/* 197E68 80269588 3C06800E */  lui   $a2, 0x800e
/* 197E6C 8026958C 80C6C0F7 */  lb    $a2, -0x3f09($a2)
/* 197E70 80269590 0C0B2026 */  jal   set_variable
/* 197E74 80269594 8C450000 */   lw    $a1, ($v0)
/* 197E78 80269598 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197E7C 8026959C 24020002 */  addiu $v0, $zero, 2
/* 197E80 802695A0 03E00008 */  jr    $ra
/* 197E84 802695A4 27BD0018 */   addiu $sp, $sp, 0x18

/* 197E88 802695A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197E8C 802695AC AFBF0010 */  sw    $ra, 0x10($sp)
/* 197E90 802695B0 8C82000C */  lw    $v0, 0xc($a0)
/* 197E94 802695B4 3C06800E */  lui   $a2, 0x800e
/* 197E98 802695B8 80C6C0F4 */  lb    $a2, -0x3f0c($a2)
/* 197E9C 802695BC 0C0B2026 */  jal   set_variable
/* 197EA0 802695C0 8C450000 */   lw    $a1, ($v0)
/* 197EA4 802695C4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197EA8 802695C8 24020002 */  addiu $v0, $zero, 2
/* 197EAC 802695CC 03E00008 */  jr    $ra
/* 197EB0 802695D0 27BD0018 */   addiu $sp, $sp, 0x18

/* 197EB4 802695D4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197EB8 802695D8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197EBC 802695DC 8C82000C */  lw    $v0, 0xc($a0)
/* 197EC0 802695E0 0C0B1EAF */  jal   get_variable
/* 197EC4 802695E4 8C450000 */   lw    $a1, ($v0)
/* 197EC8 802695E8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197ECC 802695EC 3C01800E */  lui   $at, 0x800e
/* 197ED0 802695F0 A022C0F4 */  sb    $v0, -0x3f0c($at)
/* 197ED4 802695F4 24020002 */  addiu $v0, $zero, 2
/* 197ED8 802695F8 03E00008 */  jr    $ra
/* 197EDC 802695FC 27BD0018 */   addiu $sp, $sp, 0x18

/* 197EE0 80269600 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197EE4 80269604 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197EE8 80269608 8C82000C */  lw    $v0, 0xc($a0)
/* 197EEC 8026960C 3C06800E */  lui   $a2, 0x800e
/* 197EF0 80269610 80C6C0F5 */  lb    $a2, -0x3f0b($a2)
/* 197EF4 80269614 0C0B2026 */  jal   set_variable
/* 197EF8 80269618 8C450000 */   lw    $a1, ($v0)
/* 197EFC 8026961C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197F00 80269620 24020002 */  addiu $v0, $zero, 2
/* 197F04 80269624 03E00008 */  jr    $ra
/* 197F08 80269628 27BD0018 */   addiu $sp, $sp, 0x18

/* 197F0C 8026962C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197F10 80269630 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197F14 80269634 8C82000C */  lw    $v0, 0xc($a0)
/* 197F18 80269638 0C0B1EAF */  jal   get_variable
/* 197F1C 8026963C 8C450000 */   lw    $a1, ($v0)
/* 197F20 80269640 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197F24 80269644 3C01800E */  lui   $at, 0x800e
/* 197F28 80269648 A022C0F5 */  sb    $v0, -0x3f0b($at)
/* 197F2C 8026964C 24020002 */  addiu $v0, $zero, 2
/* 197F30 80269650 03E00008 */  jr    $ra
/* 197F34 80269654 27BD0018 */   addiu $sp, $sp, 0x18

/* 197F38 80269658 00000000 */  nop   
/* 197F3C 8026965C 00000000 */  nop   
