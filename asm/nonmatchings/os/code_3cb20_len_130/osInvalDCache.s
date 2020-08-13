.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osInvalDCache
/* 03CB20 80061720 18A00020 */  blez  $a1, .L800617A4
/* 03CB24 80061724 00000000 */   nop   
/* 03CB28 80061728 240B2000 */  addiu $t3, $zero, 0x2000
/* 03CB2C 8006172C 00AB082B */  sltu  $at, $a1, $t3
/* 03CB30 80061730 1020001E */  beqz  $at, .L800617AC
/* 03CB34 80061734 00000000 */   nop   
/* 03CB38 80061738 00804021 */  addu  $t0, $a0, $zero
/* 03CB3C 8006173C 00854821 */  addu  $t1, $a0, $a1
/* 03CB40 80061740 0109082B */  sltu  $at, $t0, $t1
/* 03CB44 80061744 10200017 */  beqz  $at, .L800617A4
/* 03CB48 80061748 00000000 */   nop   
/* 03CB4C 8006174C 2529FFF0 */  addiu $t1, $t1, -0x10
/* 03CB50 80061750 310A000F */  andi  $t2, $t0, 0xf
/* 03CB54 80061754 11400007 */  beqz  $t2, .L80061774
/* 03CB58 80061758 00000000 */   nop   
/* 03CB5C 8006175C 010A4023 */  subu  $t0, $t0, $t2
/* 03CB60 80061760 BD150000 */  cache 0x15, ($t0)
/* 03CB64 80061764 0109082B */  sltu  $at, $t0, $t1
/* 03CB68 80061768 1020000E */  beqz  $at, .L800617A4
/* 03CB6C 8006176C 00000000 */   nop   
/* 03CB70 80061770 25080010 */  addiu $t0, $t0, 0x10
.L80061774:
/* 03CB74 80061774 312A000F */  andi  $t2, $t1, 0xf
/* 03CB78 80061778 11400006 */  beqz  $t2, .L80061794
/* 03CB7C 8006177C 00000000 */   nop   
/* 03CB80 80061780 012A4823 */  subu  $t1, $t1, $t2
/* 03CB84 80061784 BD350010 */  cache 0x15, 0x10($t1)
/* 03CB88 80061788 0128082B */  sltu  $at, $t1, $t0
/* 03CB8C 8006178C 14200005 */  bnez  $at, .L800617A4
/* 03CB90 80061790 00000000 */   nop   
.L80061794:
/* 03CB94 80061794 BD110000 */  cache 0x11, ($t0)
/* 03CB98 80061798 0109082B */  sltu  $at, $t0, $t1
/* 03CB9C 8006179C 1420FFFD */  bnez  $at, .L80061794
/* 03CBA0 800617A0 25080010 */   addiu $t0, $t0, 0x10
.L800617A4:
/* 03CBA4 800617A4 03E00008 */  jr    $ra
/* 03CBA8 800617A8 00000000 */   nop   

.L800617AC:
/* 03CBAC 800617AC 3C088000 */  lui   $t0, 0x8000
/* 03CBB0 800617B0 010B4821 */  addu  $t1, $t0, $t3
/* 03CBB4 800617B4 2529FFF0 */  addiu $t1, $t1, -0x10
.L800617B8:
/* 03CBB8 800617B8 BD010000 */  cache 1, ($t0)
/* 03CBBC 800617BC 0109082B */  sltu  $at, $t0, $t1
/* 03CBC0 800617C0 1420FFFD */  bnez  $at, .L800617B8
/* 03CBC4 800617C4 25080010 */   addiu $t0, $t0, 0x10
/* 03CBC8 800617C8 03E00008 */  jr    $ra
/* 03CBCC 800617CC 00000000 */   nop   

