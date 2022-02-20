.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel __osSetSR
/* 47AA0 8006C6A0 40846000 */  mtc0      $a0, $12
/* 47AA4 8006C6A4 00000000 */  nop
/* 47AA8 8006C6A8 03E00008 */  jr        $ra
/* 47AAC 8006C6AC 00000000 */   nop
