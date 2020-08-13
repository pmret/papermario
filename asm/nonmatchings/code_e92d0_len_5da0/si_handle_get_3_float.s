.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_3_float
/* 0EA94C 802C5F9C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA950 802C5FA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA954 802C5FA4 0080802D */  daddu $s0, $a0, $zero
/* 0EA958 802C5FA8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA95C 802C5FAC AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA960 802C5FB0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA964 802C5FB4 8E11000C */  lw    $s1, 0xc($s0)
/* 0EA968 802C5FB8 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA96C 802C5FBC 8E320000 */  lw    $s2, ($s1)
/* 0EA970 802C5FC0 26310004 */  addiu $s1, $s1, 4
/* 0EA974 802C5FC4 8C450000 */  lw    $a1, ($v0)
/* 0EA978 802C5FC8 24420004 */  addiu $v0, $v0, 4
/* 0EA97C 802C5FCC 0C0B210B */  jal   get_float_variable
/* 0EA980 802C5FD0 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA984 802C5FD4 0200202D */  daddu $a0, $s0, $zero
/* 0EA988 802C5FD8 44060000 */  mfc1  $a2, $f0
/* 0EA98C 802C5FDC 0C0B2190 */  jal   set_float_variable
/* 0EA990 802C5FE0 0240282D */   daddu $a1, $s2, $zero
/* 0EA994 802C5FE4 8E320000 */  lw    $s2, ($s1)
/* 0EA998 802C5FE8 26310004 */  addiu $s1, $s1, 4
/* 0EA99C 802C5FEC 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA9A0 802C5FF0 0200202D */  daddu $a0, $s0, $zero
/* 0EA9A4 802C5FF4 8C450000 */  lw    $a1, ($v0)
/* 0EA9A8 802C5FF8 24420004 */  addiu $v0, $v0, 4
/* 0EA9AC 802C5FFC 0C0B210B */  jal   get_float_variable
/* 0EA9B0 802C6000 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA9B4 802C6004 0200202D */  daddu $a0, $s0, $zero
/* 0EA9B8 802C6008 44060000 */  mfc1  $a2, $f0
/* 0EA9BC 802C600C 0C0B2190 */  jal   set_float_variable
/* 0EA9C0 802C6010 0240282D */   daddu $a1, $s2, $zero
/* 0EA9C4 802C6014 0200202D */  daddu $a0, $s0, $zero
/* 0EA9C8 802C6018 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA9CC 802C601C 8E310000 */  lw    $s1, ($s1)
/* 0EA9D0 802C6020 8C450000 */  lw    $a1, ($v0)
/* 0EA9D4 802C6024 24420004 */  addiu $v0, $v0, 4
/* 0EA9D8 802C6028 0C0B210B */  jal   get_float_variable
/* 0EA9DC 802C602C AE020138 */   sw    $v0, 0x138($s0)
/* 0EA9E0 802C6030 0200202D */  daddu $a0, $s0, $zero
/* 0EA9E4 802C6034 44060000 */  mfc1  $a2, $f0
/* 0EA9E8 802C6038 0C0B2190 */  jal   set_float_variable
/* 0EA9EC 802C603C 0220282D */   daddu $a1, $s1, $zero
/* 0EA9F0 802C6040 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA9F4 802C6044 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA9F8 802C6048 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA9FC 802C604C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAA00 802C6050 24020002 */  addiu $v0, $zero, 2
/* 0EAA04 802C6054 03E00008 */  jr    $ra
/* 0EAA08 802C6058 27BD0020 */   addiu $sp, $sp, 0x20

