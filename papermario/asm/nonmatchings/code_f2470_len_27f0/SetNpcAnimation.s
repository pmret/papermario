.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetNpcAnimation
/* 0F2AA4 802CE0F4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F2AA8 802CE0F8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2AAC 802CE0FC 0080882D */  daddu $s1, $a0, $zero
/* 0F2AB0 802CE100 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F2AB4 802CE104 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2AB8 802CE108 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2ABC 802CE10C 8E050000 */  lw    $a1, ($s0)
/* 0F2AC0 802CE110 0C0B1EAF */  jal   get_variable
/* 0F2AC4 802CE114 26100004 */   addiu $s0, $s0, 4
/* 0F2AC8 802CE118 0220202D */  daddu $a0, $s1, $zero
/* 0F2ACC 802CE11C 8E050000 */  lw    $a1, ($s0)
/* 0F2AD0 802CE120 0C0B1EAF */  jal   get_variable
/* 0F2AD4 802CE124 0040802D */   daddu $s0, $v0, $zero
/* 0F2AD8 802CE128 0220202D */  daddu $a0, $s1, $zero
/* 0F2ADC 802CE12C 0200282D */  daddu $a1, $s0, $zero
/* 0F2AE0 802CE130 0C0B36B0 */  jal   func_802CDAC0
/* 0F2AE4 802CE134 0040802D */   daddu $s0, $v0, $zero
/* 0F2AE8 802CE138 10400003 */  beqz  $v0, .L802CE148
/* 0F2AEC 802CE13C 0040202D */   daddu $a0, $v0, $zero
/* 0F2AF0 802CE140 0C0B36C3 */  jal   set_npc_animation
/* 0F2AF4 802CE144 0200282D */   daddu $a1, $s0, $zero
.L802CE148:
/* 0F2AF8 802CE148 24020002 */  addiu $v0, $zero, 2
/* 0F2AFC 802CE14C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2B00 802CE150 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2B04 802CE154 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2B08 802CE158 03E00008 */  jr    $ra
/* 0F2B0C 802CE15C 27BD0020 */   addiu $sp, $sp, 0x20

