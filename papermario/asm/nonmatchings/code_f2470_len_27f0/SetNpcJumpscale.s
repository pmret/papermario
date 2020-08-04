.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetNpcJumpscale
/* 0F2A38 802CE088 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F2A3C 802CE08C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2A40 802CE090 0080882D */  daddu $s1, $a0, $zero
/* 0F2A44 802CE094 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F2A48 802CE098 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2A4C 802CE09C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F2A50 802CE0A0 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2A54 802CE0A4 8E050000 */  lw    $a1, ($s0)
/* 0F2A58 802CE0A8 0C0B1EAF */  jal   get_variable
/* 0F2A5C 802CE0AC 26100004 */   addiu $s0, $s0, 4
/* 0F2A60 802CE0B0 0220202D */  daddu $a0, $s1, $zero
/* 0F2A64 802CE0B4 8E050000 */  lw    $a1, ($s0)
/* 0F2A68 802CE0B8 0C0B210B */  jal   get_float_variable
/* 0F2A6C 802CE0BC 0040802D */   daddu $s0, $v0, $zero
/* 0F2A70 802CE0C0 0220202D */  daddu $a0, $s1, $zero
/* 0F2A74 802CE0C4 0200282D */  daddu $a1, $s0, $zero
/* 0F2A78 802CE0C8 0C0B36B0 */  jal   func_802CDAC0
/* 0F2A7C 802CE0CC 46000506 */   mov.s $f20, $f0
/* 0F2A80 802CE0D0 54400001 */  bnel  $v0, $zero, .L802CE0D8
/* 0F2A84 802CE0D4 E4540014 */   swc1  $f20, 0x14($v0)
.L802CE0D8:
/* 0F2A88 802CE0D8 24020002 */  addiu $v0, $zero, 2
/* 0F2A8C 802CE0DC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2A90 802CE0E0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2A94 802CE0E4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2A98 802CE0E8 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2A9C 802CE0EC 03E00008 */  jr    $ra
/* 0F2AA0 802CE0F0 27BD0028 */   addiu $sp, $sp, 0x28

