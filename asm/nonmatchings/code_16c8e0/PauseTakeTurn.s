.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PauseTakeTurn
/* 1A7284 802789A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A7288 802789A8 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A728C 802789AC 0080902D */  daddu $s2, $a0, $zero
/* 1A7290 802789B0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A7294 802789B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A7298 802789B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A729C 802789BC 8E51000C */  lw    $s1, 0xc($s2)
/* 1A72A0 802789C0 8E250000 */  lw    $a1, ($s1)
/* 1A72A4 802789C4 0C0B1EAF */  jal   get_variable
/* 1A72A8 802789C8 26310004 */   addiu $s1, $s1, 4
/* 1A72AC 802789CC 0040802D */  daddu $s0, $v0, $zero
/* 1A72B0 802789D0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A72B4 802789D4 16020002 */  bne   $s0, $v0, .L802789E0
/* 1A72B8 802789D8 00000000 */   nop   
/* 1A72BC 802789DC 8E500148 */  lw    $s0, 0x148($s2)
.L802789E0:
/* 1A72C0 802789E0 8E250000 */  lw    $a1, ($s1)
/* 1A72C4 802789E4 0C0B1EAF */  jal   get_variable
/* 1A72C8 802789E8 0240202D */   daddu $a0, $s2, $zero
/* 1A72CC 802789EC 0C09A75B */  jal   get_actor
/* 1A72D0 802789F0 0200202D */   daddu $a0, $s0, $zero
/* 1A72D4 802789F4 8C4401E4 */  lw    $a0, 0x1e4($v0)
/* 1A72D8 802789F8 0C0B1108 */  jal   suspend_all_script
/* 1A72DC 802789FC 00000000 */   nop   
/* 1A72E0 80278A00 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A72E4 80278A04 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A72E8 80278A08 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A72EC 80278A0C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A72F0 80278A10 24020002 */  addiu $v0, $zero, 2
/* 1A72F4 80278A14 03E00008 */  jr    $ra
/* 1A72F8 80278A18 27BD0020 */   addiu $sp, $sp, 0x20

