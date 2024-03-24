.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel osUnmapTLBAll
/* 41D60 80066960 40085000 */  mfc0      $t0, $10
/* 41D64 80066964 2409001E */  addiu     $t1, $zero, 0x1e
/* 41D68 80066968 3C0A8000 */  lui       $t2, 0x8000
/* 41D6C 8006696C 408A5000 */  mtc0      $t2, $10
/* 41D70 80066970 40801000 */  mtc0      $zero, $2
/* 41D74 80066974 40801800 */  mtc0      $zero, $3
.L80066978:
/* 41D78 80066978 40890000 */  mtc0      $t1, $0
/* 41D7C 8006697C 00000000 */  nop
/* 41D80 80066980 42000002 */  tlbwi
/* 41D84 80066984 00000000 */  nop
/* 41D88 80066988 00000000 */  nop
/* 41D8C 8006698C 2129FFFF */  addi      $t1, $t1, -1
/* 41D90 80066990 0521FFF9 */  bgez      $t1, .L80066978
/* 41D94 80066994 00000000 */   nop
/* 41D98 80066998 40885000 */  mtc0      $t0, $10
/* 41D9C 8006699C 03E00008 */  jr        $ra
/* 41DA0 800669A0 00000000 */   nop
