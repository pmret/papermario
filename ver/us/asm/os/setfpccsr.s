.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel __osSetFpcCsr
/* 47A90 8006C690 4442F800 */  cfc1      $v0, $31
/* 47A94 8006C694 44C4F800 */  ctc1      $a0, $31
/* 47A98 8006C698 03E00008 */  jr        $ra
/* 47A9C 8006C69C 00000000 */   nop
