.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel osInvalDCache
/* 3CB20 80061720 18A00020 */  blez      $a1, .L800617A4
/* 3CB24 80061724 00000000 */   nop
/* 3CB28 80061728 240B2000 */  addiu     $t3, $zero, 0x2000
/* 3CB2C 8006172C 00AB082B */  sltu      $at, $a1, $t3
/* 3CB30 80061730 1020001E */  beqz      $at, .L800617AC
/* 3CB34 80061734 00000000 */   nop
/* 3CB38 80061738 00804021 */  addu      $t0, $a0, $zero
/* 3CB3C 8006173C 00854821 */  addu      $t1, $a0, $a1
/* 3CB40 80061740 0109082B */  sltu      $at, $t0, $t1
/* 3CB44 80061744 10200017 */  beqz      $at, .L800617A4
/* 3CB48 80061748 00000000 */   nop
/* 3CB4C 8006174C 2529FFF0 */  addiu     $t1, $t1, -0x10
/* 3CB50 80061750 310A000F */  andi      $t2, $t0, 0xf
/* 3CB54 80061754 11400007 */  beqz      $t2, .L80061774
/* 3CB58 80061758 00000000 */   nop
/* 3CB5C 8006175C 010A4023 */  subu      $t0, $t0, $t2
/* 3CB60 80061760 BD150000 */  cache     0x15, ($t0)
/* 3CB64 80061764 0109082B */  sltu      $at, $t0, $t1
/* 3CB68 80061768 1020000E */  beqz      $at, .L800617A4
/* 3CB6C 8006176C 00000000 */   nop
/* 3CB70 80061770 25080010 */  addiu     $t0, $t0, 0x10
.L80061774:
/* 3CB74 80061774 312A000F */  andi      $t2, $t1, 0xf
/* 3CB78 80061778 11400006 */  beqz      $t2, .L80061794
/* 3CB7C 8006177C 00000000 */   nop
/* 3CB80 80061780 012A4823 */  subu      $t1, $t1, $t2
/* 3CB84 80061784 BD350010 */  cache     0x15, 0x10($t1)
/* 3CB88 80061788 0128082B */  sltu      $at, $t1, $t0
/* 3CB8C 8006178C 14200005 */  bnez      $at, .L800617A4
/* 3CB90 80061790 00000000 */   nop
.L80061794:
/* 3CB94 80061794 BD110000 */  cache     0x11, ($t0)
/* 3CB98 80061798 0109082B */  sltu      $at, $t0, $t1
/* 3CB9C 8006179C 1420FFFD */  bnez      $at, .L80061794
/* 3CBA0 800617A0 25080010 */   addiu    $t0, $t0, 0x10
.L800617A4:
/* 3CBA4 800617A4 03E00008 */  jr        $ra
/* 3CBA8 800617A8 00000000 */   nop
.L800617AC:
/* 3CBAC 800617AC 3C088000 */  lui       $t0, 0x8000
/* 3CBB0 800617B0 010B4821 */  addu      $t1, $t0, $t3
/* 3CBB4 800617B4 2529FFF0 */  addiu     $t1, $t1, -0x10
.L800617B8:
/* 3CBB8 800617B8 BD010000 */  cache     1, ($t0)
/* 3CBBC 800617BC 0109082B */  sltu      $at, $t0, $t1
/* 3CBC0 800617C0 1420FFFD */  bnez      $at, .L800617B8
/* 3CBC4 800617C4 25080010 */   addiu    $t0, $t0, 0x10
/* 3CBC8 800617C8 03E00008 */  jr        $ra
/* 3CBCC 800617CC 00000000 */   nop
