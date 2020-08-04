.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_else
/* 0E98F0 802C4F40 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E98F4 802C4F44 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E98F8 802C4F48 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E98FC 802C4F4C 0C0B225E */  jal   si_skip_else
/* 0E9900 802C4F50 0080802D */   daddu $s0, $a0, $zero
/* 0E9904 802C4F54 AE020008 */  sw    $v0, 8($s0)
/* 0E9908 802C4F58 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E990C 802C4F5C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9910 802C4F60 24020002 */  addiu $v0, $zero, 2
/* 0E9914 802C4F64 03E00008 */  jr    $ra
/* 0E9918 802C4F68 27BD0018 */   addiu $sp, $sp, 0x18

