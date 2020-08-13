.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSiCreateAccessQueue
/* 041170 80065D70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 041174 80065D74 24020001 */  addiu $v0, $zero, 1
/* 041178 80065D78 AFB00010 */  sw    $s0, 0x10($sp)
/* 04117C 80065D7C 3C10800E */  lui   $s0, 0x800e
/* 041180 80065D80 2610ACA8 */  addiu $s0, $s0, -0x5358
/* 041184 80065D84 02002021 */  addu  $a0, $s0, $zero
/* 041188 80065D88 3C05800B */  lui   $a1, 0x800b
/* 04118C 80065D8C 24A5F900 */  addiu $a1, $a1, -0x700
/* 041190 80065D90 AFBF0014 */  sw    $ra, 0x14($sp)
/* 041194 80065D94 3C018009 */  lui   $at, 0x8009
/* 041198 80065D98 AC224640 */  sw    $v0, 0x4640($at)
/* 04119C 80065D9C 0C019560 */  jal   osCreateMesgQueue
/* 0411A0 80065DA0 24060001 */   addiu $a2, $zero, 1
/* 0411A4 80065DA4 02002021 */  addu  $a0, $s0, $zero
/* 0411A8 80065DA8 00002821 */  addu  $a1, $zero, $zero
/* 0411AC 80065DAC 0C019608 */  jal   osSendMesg
/* 0411B0 80065DB0 00003021 */   addu  $a2, $zero, $zero
/* 0411B4 80065DB4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0411B8 80065DB8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0411BC 80065DBC 03E00008 */  jr    $ra
/* 0411C0 80065DC0 27BD0018 */   addiu $sp, $sp, 0x18

