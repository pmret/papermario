.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetAnimation
/* 199A90 8026B1B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199A94 8026B1B4 AFB20018 */  sw    $s2, 0x18($sp)
/* 199A98 8026B1B8 0080902D */  daddu $s2, $a0, $zero
/* 199A9C 8026B1BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 199AA0 8026B1C0 AFB10014 */  sw    $s1, 0x14($sp)
/* 199AA4 8026B1C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 199AA8 8026B1C8 8E50000C */  lw    $s0, 0xc($s2)
/* 199AAC 8026B1CC 8E050000 */  lw    $a1, ($s0)
/* 199AB0 8026B1D0 0C0B1EAF */  jal   get_variable
/* 199AB4 8026B1D4 26100004 */   addiu $s0, $s0, 4
/* 199AB8 8026B1D8 0040882D */  daddu $s1, $v0, $zero
/* 199ABC 8026B1DC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199AC0 8026B1E0 16220002 */  bne   $s1, $v0, .L8026B1EC
/* 199AC4 8026B1E4 00000000 */   nop   
/* 199AC8 8026B1E8 8E510148 */  lw    $s1, 0x148($s2)
.L8026B1EC:
/* 199ACC 8026B1EC 8E050000 */  lw    $a1, ($s0)
/* 199AD0 8026B1F0 26100004 */  addiu $s0, $s0, 4
/* 199AD4 8026B1F4 0C0B1EAF */  jal   get_variable
/* 199AD8 8026B1F8 0240202D */   daddu $a0, $s2, $zero
/* 199ADC 8026B1FC 0240202D */  daddu $a0, $s2, $zero
/* 199AE0 8026B200 8E050000 */  lw    $a1, ($s0)
/* 199AE4 8026B204 0C0B1EAF */  jal   get_variable
/* 199AE8 8026B208 0040802D */   daddu $s0, $v0, $zero
/* 199AEC 8026B20C 0220202D */  daddu $a0, $s1, $zero
/* 199AF0 8026B210 0200282D */  daddu $a1, $s0, $zero
/* 199AF4 8026B214 0C098F3F */  jal   set_animation
/* 199AF8 8026B218 0040302D */   daddu $a2, $v0, $zero
/* 199AFC 8026B21C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199B00 8026B220 8FB20018 */  lw    $s2, 0x18($sp)
/* 199B04 8026B224 8FB10014 */  lw    $s1, 0x14($sp)
/* 199B08 8026B228 8FB00010 */  lw    $s0, 0x10($sp)
/* 199B0C 8026B22C 24020002 */  addiu $v0, $zero, 2
/* 199B10 8026B230 03E00008 */  jr    $ra
/* 199B14 8026B234 27BD0020 */   addiu $sp, $sp, 0x20

