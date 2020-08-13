.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802AA014
/* 41EDA4 802AA014 00000000 */   nop   
/* 41EDA8 802AA018 14400007 */  bnez  $v0, .L802AA038
/* 41EDAC 802AA01C 24020001 */   addiu $v0, $zero, 1
/* 41EDB0 802AA020 3C01802B */  lui   $at, 0x802b
/* 41EDB4 802AA024 A020D607 */  sb    $zero, -0x29f9($at)
/* 41EDB8 802AA028 3C01802B */  lui   $at, 0x802b
/* 41EDBC 802AA02C AC20CC60 */  sw    $zero, -0x33a0($at)
.L802AA030:
/* 41EDC0 802AA030 3C01800E */  lui   $at, 0x800e
/* 41EDC4 802AA034 AC22C4DC */  sw    $v0, -0x3b24($at)
.L802AA038:
/* 41EDC8 802AA038 8FBF001C */  lw    $ra, 0x1c($sp)
/* 41EDCC 802AA03C 8FB20018 */  lw    $s2, 0x18($sp)
/* 41EDD0 802AA040 8FB10014 */  lw    $s1, 0x14($sp)
/* 41EDD4 802AA044 8FB00010 */  lw    $s0, 0x10($sp)
/* 41EDD8 802AA048 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 41EDDC 802AA04C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 41EDE0 802AA050 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 41EDE4 802AA054 03E00008 */  jr    $ra
/* 41EDE8 802AA058 27BD0038 */   addiu $sp, $sp, 0x38

