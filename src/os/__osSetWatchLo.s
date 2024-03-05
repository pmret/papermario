.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel __osSetWatchLo
/* 47AB0 8006C6B0 40849000 */  mtc0      $a0, $18
/* 47AB4 8006C6B4 00000000 */  nop
/* 47AB8 8006C6B8 03E00008 */  jr        $ra
/* 47ABC 8006C6BC 00000000 */   nop
