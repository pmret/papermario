.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel osUnmapTLB
/* 41D20 80066920 40085000 */  mfc0      $t0, $10
/* 41D24 80066924 40840000 */  mtc0      $a0, $0
/* 41D28 80066928 3C098000 */  lui       $t1, 0x8000
/* 41D2C 8006692C 40895000 */  mtc0      $t1, $10
/* 41D30 80066930 40801000 */  mtc0      $zero, $2
/* 41D34 80066934 40801800 */  mtc0      $zero, $3
/* 41D38 80066938 00000000 */  nop
/* 41D3C 8006693C 42000002 */  tlbwi
/* 41D40 80066940 00000000 */  nop
/* 41D44 80066944 00000000 */  nop
/* 41D48 80066948 00000000 */  nop
/* 41D4C 8006694C 00000000 */  nop
/* 41D50 80066950 40885000 */  mtc0      $t0, $10
/* 41D54 80066954 03E00008 */  jr        $ra
/* 41D58 80066958 00000000 */   nop
