.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.5 */

# Handwritten function
glabel osInvalICache
/* 3DA40 80062640 18A00011 */  blez      $a1, .LPAL_80062688
/* 3DA44 80062644 00000000 */   nop
/* 3DA48 80062648 240B4000 */  addiu     $t3, $zero, 0x4000
/* 3DA4C 8006264C 00AB082B */  sltu      $at, $a1, $t3
/* 3DA50 80062650 1020000F */  beqz      $at, .LPAL_80062690
/* 3DA54 80062654 00000000 */   nop
/* 3DA58 80062658 00804021 */  addu      $t0, $a0, $zero
/* 3DA5C 8006265C 00854821 */  addu      $t1, $a0, $a1
/* 3DA60 80062660 0109082B */  sltu      $at, $t0, $t1
/* 3DA64 80062664 10200008 */  beqz      $at, .LPAL_80062688
/* 3DA68 80062668 00000000 */   nop
/* 3DA6C 8006266C 2529FFE0 */  addiu     $t1, $t1, -0x20
/* 3DA70 80062670 310A001F */  andi      $t2, $t0, 0x1F
/* 3DA74 80062674 010A4023 */  subu      $t0, $t0, $t2
.LPAL_80062678:
/* 3DA78 80062678 BD100000 */  cache     0x10, 0x0($t0) # handwritten instruction
/* 3DA7C 8006267C 0109082B */  sltu      $at, $t0, $t1
/* 3DA80 80062680 1420FFFD */  bnez      $at, .LPAL_80062678
/* 3DA84 80062684 25080020 */   addiu    $t0, $t0, 0x20
.LPAL_80062688:
/* 3DA88 80062688 03E00008 */  jr        $ra
/* 3DA8C 8006268C 00000000 */   nop
.LPAL_80062690:
/* 3DA90 80062690 3C088000 */  lui       $t0, 0x8000
/* 3DA94 80062694 010B4821 */  addu      $t1, $t0, $t3
/* 3DA98 80062698 2529FFE0 */  addiu     $t1, $t1, -0x20
.LPAL_8006269C:
/* 3DA9C 8006269C BD000000 */  cache     0x00, 0x0($t0) # handwritten instruction
/* 3DAA0 800626A0 0109082B */  sltu      $at, $t0, $t1
/* 3DAA4 800626A4 1420FFFD */  bnez      $at, .LPAL_8006269C
/* 3DAA8 800626A8 25080020 */   addiu    $t0, $t0, (0x80000020 & 0xFFFF)
/* 3DAAC 800626AC 03E00008 */  jr        $ra
/* 3DAB0 800626B0 00000000 */   nop
/* 3DAB4 800626B4 00000000 */  nop
/* 3DAB8 800626B8 00000000 */  nop
/* 3DABC 800626BC 00000000 */  nop