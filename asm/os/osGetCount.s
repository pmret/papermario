.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel osGetCount
/* 40E00 80065A00 40024800 */  mfc0      $v0, $9
/* 40E04 80065A04 03E00008 */  jr        $ra
/* 40E08 80065A08 00000000 */   nop
/* 40E0C 80065A0C 00000000 */  nop
