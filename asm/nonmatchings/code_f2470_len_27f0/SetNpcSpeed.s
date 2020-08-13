.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetNpcSpeed
/* 0F29CC 802CE01C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F29D0 802CE020 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F29D4 802CE024 0080882D */  daddu $s1, $a0, $zero
/* 0F29D8 802CE028 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F29DC 802CE02C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F29E0 802CE030 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F29E4 802CE034 8E30000C */  lw    $s0, 0xc($s1)
/* 0F29E8 802CE038 8E050000 */  lw    $a1, ($s0)
/* 0F29EC 802CE03C 0C0B1EAF */  jal   get_variable
/* 0F29F0 802CE040 26100004 */   addiu $s0, $s0, 4
/* 0F29F4 802CE044 0220202D */  daddu $a0, $s1, $zero
/* 0F29F8 802CE048 8E050000 */  lw    $a1, ($s0)
/* 0F29FC 802CE04C 0C0B210B */  jal   get_float_variable
/* 0F2A00 802CE050 0040802D */   daddu $s0, $v0, $zero
/* 0F2A04 802CE054 0220202D */  daddu $a0, $s1, $zero
/* 0F2A08 802CE058 0200282D */  daddu $a1, $s0, $zero
/* 0F2A0C 802CE05C 0C0B36B0 */  jal   func_802CDAC0
/* 0F2A10 802CE060 46000506 */   mov.s $f20, $f0
/* 0F2A14 802CE064 54400001 */  bnel  $v0, $zero, .L802CE06C
/* 0F2A18 802CE068 E4540018 */   swc1  $f20, 0x18($v0)
.L802CE06C:
/* 0F2A1C 802CE06C 24020002 */  addiu $v0, $zero, 2
/* 0F2A20 802CE070 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2A24 802CE074 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2A28 802CE078 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2A2C 802CE07C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2A30 802CE080 03E00008 */  jr    $ra
/* 0F2A34 802CE084 27BD0028 */   addiu $sp, $sp, 0x28

