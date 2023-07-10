.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

# Handwritten function
glabel func_800004F0
/* 10F0 800004F0 00851020 */  add        $v0, $a0, $a1 # handwritten instruction
/* 10F4 800004F4 03E00008 */  jr         $ra
/* 10F8 800004F8 00000000 */   nop
/* 10FC 800004FC 00000000 */  nop
