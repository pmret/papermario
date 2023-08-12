.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.16.0 */

# Handwritten function
glabel osWritebackDCache
/* 3BA00 80060600 18A00011 */  blez      $a1, .LIQUE_80060648
/* 3BA04 80060604 00000000 */   nop
/* 3BA08 80060608 240B2000 */  addiu     $t3, $zero, 0x2000
/* 3BA0C 8006060C 00AB082B */  sltu      $at, $a1, $t3
/* 3BA10 80060610 1020000F */  beqz      $at, .LIQUE_80060650
/* 3BA14 80060614 00000000 */   nop
/* 3BA18 80060618 0080402D */  daddu     $t0, $a0, $zero
/* 3BA1C 8006061C 00854821 */  addu      $t1, $a0, $a1
/* 3BA20 80060620 0109082B */  sltu      $at, $t0, $t1
/* 3BA24 80060624 10200008 */  beqz      $at, .LIQUE_80060648
/* 3BA28 80060628 00000000 */   nop
/* 3BA2C 8006062C 2529FFF0 */  addiu     $t1, $t1, -0x10
/* 3BA30 80060630 310A000F */  andi      $t2, $t0, 0xF
/* 3BA34 80060634 010A4023 */  subu      $t0, $t0, $t2
.LIQUE_80060638:
/* 3BA38 80060638 BD190000 */  cache     0x19, 0x0($t0) # handwritten instruction
/* 3BA3C 8006063C 0109082B */  sltu      $at, $t0, $t1
/* 3BA40 80060640 1420FFFD */  bnez      $at, .LIQUE_80060638
/* 3BA44 80060644 25080010 */   addiu    $t0, $t0, 0x10
.LIQUE_80060648:
/* 3BA48 80060648 03E00008 */  jr        $ra
/* 3BA4C 8006064C 00000000 */   nop
.LIQUE_80060650:
/* 3BA50 80060650 3C088000 */  lui       $t0, 0x8000
/* 3BA54 80060654 010B4821 */  addu      $t1, $t0, $t3
/* 3BA58 80060658 2529FFF0 */  addiu     $t1, $t1, -0x10
.LIQUE_8006065C:
/* 3BA5C 8006065C BD010000 */  cache     0x01, 0x0($t0) # handwritten instruction
/* 3BA60 80060660 0109082B */  sltu      $at, $t0, $t1
/* 3BA64 80060664 1420FFFD */  bnez      $at, .LIQUE_8006065C
/* 3BA68 80060668 25080010 */   addiu    $t0, $t0, (0x80000010 & 0xFFFF)
/* 3BA6C 8006066C 03E00008 */  jr        $ra
/* 3BA70 80060670 00000000 */   nop
/* 3BA74 80060674 00000000 */  nop
/* 3BA78 80060678 00000000 */  nop
/* 3BA7C 8006067C 00000000 */  nop
.size osWritebackDCache, . - osWritebackDCache
