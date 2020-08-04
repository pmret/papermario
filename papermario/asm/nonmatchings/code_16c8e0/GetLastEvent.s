.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetLastEvent
/* 1AADC0 8027C4E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AADC4 8027C4E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AADC8 8027C4E8 0080882D */  daddu $s1, $a0, $zero
/* 1AADCC 8027C4EC AFBF0018 */  sw    $ra, 0x18($sp)
/* 1AADD0 8027C4F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AADD4 8027C4F4 8E30000C */  lw    $s0, 0xc($s1)
/* 1AADD8 8027C4F8 8E050000 */  lw    $a1, ($s0)
/* 1AADDC 8027C4FC 0C0B1EAF */  jal   get_variable
/* 1AADE0 8027C500 26100004 */   addiu $s0, $s0, 4
/* 1AADE4 8027C504 0040202D */  daddu $a0, $v0, $zero
/* 1AADE8 8027C508 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AADEC 8027C50C 14820002 */  bne   $a0, $v0, .L8027C518
/* 1AADF0 8027C510 00000000 */   nop   
/* 1AADF4 8027C514 8E240148 */  lw    $a0, 0x148($s1)
.L8027C518:
/* 1AADF8 8027C518 0C09A75B */  jal   get_actor
/* 1AADFC 8027C51C 8E100000 */   lw    $s0, ($s0)
/* 1AAE00 8027C520 0220202D */  daddu $a0, $s1, $zero
/* 1AAE04 8027C524 804601F0 */  lb    $a2, 0x1f0($v0)
/* 1AAE08 8027C528 0C0B2026 */  jal   set_variable
/* 1AAE0C 8027C52C 0200282D */   daddu $a1, $s0, $zero
/* 1AAE10 8027C530 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1AAE14 8027C534 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AAE18 8027C538 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AAE1C 8027C53C 24020002 */  addiu $v0, $zero, 2
/* 1AAE20 8027C540 03E00008 */  jr    $ra
/* 1AAE24 8027C544 27BD0020 */   addiu $sp, $sp, 0x20

