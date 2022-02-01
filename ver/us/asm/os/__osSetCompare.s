.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel __osSetCompare
/* 47A80 8006C680 40845800 */  mtc0      $a0, $11
/* 47A84 8006C684 03E00008 */  jr        $ra
/* 47A88 8006C688 00000000 */   nop
