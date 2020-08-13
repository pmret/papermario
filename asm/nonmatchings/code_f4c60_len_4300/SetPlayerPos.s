.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetPlayerPos
/* 0F58A0 802D0EF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F58A4 802D0EF4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F58A8 802D0EF8 0080882D */  daddu $s1, $a0, $zero
/* 0F58AC 802D0EFC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F58B0 802D0F00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F58B4 802D0F04 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F58B8 802D0F08 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F58BC 802D0F0C 8E30000C */  lw    $s0, 0xc($s1)
/* 0F58C0 802D0F10 8E050000 */  lw    $a1, ($s0)
/* 0F58C4 802D0F14 0C0B1EAF */  jal   get_variable
/* 0F58C8 802D0F18 26100004 */   addiu $s0, $s0, 4
/* 0F58CC 802D0F1C 8E050000 */  lw    $a1, ($s0)
/* 0F58D0 802D0F20 26100004 */  addiu $s0, $s0, 4
/* 0F58D4 802D0F24 4482B000 */  mtc1  $v0, $f22
/* 0F58D8 802D0F28 00000000 */  nop   
/* 0F58DC 802D0F2C 4680B5A0 */  cvt.s.w $f22, $f22
/* 0F58E0 802D0F30 0C0B1EAF */  jal   get_variable
/* 0F58E4 802D0F34 0220202D */   daddu $a0, $s1, $zero
/* 0F58E8 802D0F38 8E050000 */  lw    $a1, ($s0)
/* 0F58EC 802D0F3C 4482A000 */  mtc1  $v0, $f20
/* 0F58F0 802D0F40 00000000 */  nop   
/* 0F58F4 802D0F44 4680A520 */  cvt.s.w $f20, $f20
/* 0F58F8 802D0F48 0C0B1EAF */  jal   get_variable
/* 0F58FC 802D0F4C 0220202D */   daddu $a0, $s1, $zero
/* 0F5900 802D0F50 44820000 */  mtc1  $v0, $f0
/* 0F5904 802D0F54 00000000 */  nop   
/* 0F5908 802D0F58 46800020 */  cvt.s.w $f0, $f0
/* 0F590C 802D0F5C 3C03802E */  lui   $v1, 0x802e
/* 0F5910 802D0F60 8C639D20 */  lw    $v1, -0x62e0($v1)
/* 0F5914 802D0F64 3C048011 */  lui   $a0, 0x8011
/* 0F5918 802D0F68 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 0F591C 802D0F6C E4760038 */  swc1  $f22, 0x38($v1)
/* 0F5920 802D0F70 E4600040 */  swc1  $f0, 0x40($v1)
/* 0F5924 802D0F74 4600B006 */  mov.s $f0, $f22
/* 0F5928 802D0F78 E474003C */  swc1  $f20, 0x3c($v1)
/* 0F592C 802D0F7C E4800028 */  swc1  $f0, 0x28($a0)
/* 0F5930 802D0F80 C460003C */  lwc1  $f0, 0x3c($v1)
/* 0F5934 802D0F84 E480002C */  swc1  $f0, 0x2c($a0)
/* 0F5938 802D0F88 C4600040 */  lwc1  $f0, 0x40($v1)
/* 0F593C 802D0F8C E4800030 */  swc1  $f0, 0x30($a0)
/* 0F5940 802D0F90 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F5944 802D0F94 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F5948 802D0F98 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F594C 802D0F9C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F5950 802D0FA0 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F5954 802D0FA4 24020002 */  addiu $v0, $zero, 2
/* 0F5958 802D0FA8 03E00008 */  jr    $ra
/* 0F595C 802D0FAC 27BD0030 */   addiu $sp, $sp, 0x30

