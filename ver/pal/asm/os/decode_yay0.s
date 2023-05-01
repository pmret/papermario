.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.5 */

# Handwritten function
glabel decode_yay0
/* 4B190 8006FD90 8C980004 */  lw        $t8, 0x4($a0)
/* 4B194 8006FD94 8C870008 */  lw        $a3, 0x8($a0)
/* 4B198 8006FD98 8C99000C */  lw        $t9, 0xC($a0)
/* 4B19C 8006FD9C 0000302D */  daddu     $a2, $zero, $zero
/* 4B1A0 8006FDA0 0305C020 */  add       $t8, $t8, $a1 # handwritten instruction
/* 4B1A4 8006FDA4 00E43820 */  add       $a3, $a3, $a0 # handwritten instruction
/* 4B1A8 8006FDA8 0324C820 */  add       $t9, $t9, $a0 # handwritten instruction
/* 4B1AC 8006FDAC 20840010 */  addi      $a0, $a0, 0x10 # handwritten instruction
.LPAL_8006FDB0:
/* 4B1B0 8006FDB0 14C00004 */  bnez      $a2, .LPAL_8006FDC4
/* 4B1B4 8006FDB4 00000000 */   nop
/* 4B1B8 8006FDB8 8C880000 */  lw        $t0, 0x0($a0)
/* 4B1BC 8006FDBC 24060020 */  addiu     $a2, $zero, 0x20
/* 4B1C0 8006FDC0 20840004 */  addi      $a0, $a0, 0x4 # handwritten instruction
.LPAL_8006FDC4:
/* 4B1C4 8006FDC4 0100482A */  slt       $t1, $t0, $zero
/* 4B1C8 8006FDC8 11200006 */  beqz      $t1, .LPAL_8006FDE4
/* 4B1CC 8006FDCC 00000000 */   nop
/* 4B1D0 8006FDD0 832A0000 */  lb        $t2, 0x0($t9)
/* 4B1D4 8006FDD4 23390001 */  addi      $t9, $t9, 0x1 # handwritten instruction
/* 4B1D8 8006FDD8 A0AA0000 */  sb        $t2, 0x0($a1)
/* 4B1DC 8006FDDC 1000000E */  b         .LPAL_8006FE18
/* 4B1E0 8006FDE0 20A50001 */   addi     $a1, $a1, 0x1 # handwritten instruction
.LPAL_8006FDE4:
/* 4B1E4 8006FDE4 94EA0000 */  lhu       $t2, 0x0($a3)
/* 4B1E8 8006FDE8 20E70002 */  addi      $a3, $a3, 0x2 # handwritten instruction
/* 4B1EC 8006FDEC 000A5B02 */  srl       $t3, $t2, 12
/* 4B1F0 8006FDF0 314A0FFF */  andi      $t2, $t2, 0xFFF
/* 4B1F4 8006FDF4 1160000D */  beqz      $t3, .LPAL_8006FE2C
/* 4B1F8 8006FDF8 00AA4822 */   sub      $t1, $a1, $t2 # handwritten instruction
/* 4B1FC 8006FDFC 216B0002 */  addi      $t3, $t3, 0x2 # handwritten instruction
.LPAL_8006FE00:
/* 4B200 8006FE00 812AFFFF */  lb        $t2, -0x1($t1)
/* 4B204 8006FE04 216BFFFF */  addi      $t3, $t3, -0x1 # handwritten instruction
/* 4B208 8006FE08 21290001 */  addi      $t1, $t1, 0x1 # handwritten instruction
/* 4B20C 8006FE0C A0AA0000 */  sb        $t2, 0x0($a1)
/* 4B210 8006FE10 1560FFFB */  bnez      $t3, .LPAL_8006FE00
/* 4B214 8006FE14 20A50001 */   addi     $a1, $a1, 0x1 # handwritten instruction
.LPAL_8006FE18:
/* 4B218 8006FE18 00084040 */  sll       $t0, $t0, 1
/* 4B21C 8006FE1C 14B8FFE4 */  bne       $a1, $t8, .LPAL_8006FDB0
/* 4B220 8006FE20 20C6FFFF */   addi     $a2, $a2, -0x1 # handwritten instruction
/* 4B224 8006FE24 03E00008 */  jr        $ra
/* 4B228 8006FE28 00000000 */   nop
.LPAL_8006FE2C:
/* 4B22C 8006FE2C 932B0000 */  lbu       $t3, 0x0($t9)
/* 4B230 8006FE30 23390001 */  addi      $t9, $t9, 0x1 # handwritten instruction
/* 4B234 8006FE34 1000FFF2 */  b         .LPAL_8006FE00
/* 4B238 8006FE38 216B0012 */   addi     $t3, $t3, 0x12 # handwritten instruction
/* 4B23C 8006FE3C 00000000 */  nop