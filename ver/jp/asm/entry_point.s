.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_80025C00
/* 1000 80025C00 3C08800A */  lui       $t0, %hi(D_8009A590)
/* 1004 80025C04 2508A590 */  addiu     $t0, $t0, %lo(D_8009A590)
/* 1008 80025C08 3C090004 */  lui       $t1, 4
/* 100C 80025C0C 25291F50 */  addiu     $t1, $t1, 0x1f50
.L80025C10:
/* 1010 80025C10 AD000000 */  sw        $zero, ($t0)
/* 1014 80025C14 AD000004 */  sw        $zero, 4($t0)
/* 1018 80025C18 21080008 */  addi      $t0, $t0, 8
/* 101C 80025C1C 2129FFF8 */  addi      $t1, $t1, -8
/* 1020 80025C20 1520FFFB */  bnez      $t1, .L80025C10
/* 1024 80025C24 00000000 */   nop
/* 1028 80025C28 3C1D800B */  lui       $sp, %hi(D_800B6570)
/* 102C 80025C2C 27BD6570 */  addiu     $sp, $sp, %lo(D_800B6570)
/* 1030 80025C30 3C0A8006 */  lui       $t2, %hi(D_8005E560)
/* 1034 80025C34 254AE560 */  addiu     $t2, $t2, %lo(D_8005E560)
/* 1038 80025C38 01400008 */  jr        $t2
/* 103C 80025C3C 00000000 */   nop
/* 1040 80025C40 00000000 */  nop
/* 1044 80025C44 00000000 */  nop
/* 1048 80025C48 00000000 */  nop
/* 104C 80025C4C 00000000 */  nop
/* 1050 80025C50 00000000 */  nop
/* 1054 80025C54 00000000 */  nop
/* 1058 80025C58 00000000 */  nop
/* 105C 80025C5C 00000000 */  nop
