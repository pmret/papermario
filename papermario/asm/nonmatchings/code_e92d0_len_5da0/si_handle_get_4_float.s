.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_4_float
/* 0EAA0C 802C605C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAA10 802C6060 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAA14 802C6064 0080802D */  daddu $s0, $a0, $zero
/* 0EAA18 802C6068 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAA1C 802C606C AFB20018 */  sw    $s2, 0x18($sp)
/* 0EAA20 802C6070 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EAA24 802C6074 8E11000C */  lw    $s1, 0xc($s0)
/* 0EAA28 802C6078 8E020138 */  lw    $v0, 0x138($s0)
/* 0EAA2C 802C607C 8E320000 */  lw    $s2, ($s1)
/* 0EAA30 802C6080 26310004 */  addiu $s1, $s1, 4
/* 0EAA34 802C6084 8C450000 */  lw    $a1, ($v0)
/* 0EAA38 802C6088 24420004 */  addiu $v0, $v0, 4
/* 0EAA3C 802C608C 0C0B210B */  jal   get_float_variable
/* 0EAA40 802C6090 AE020138 */   sw    $v0, 0x138($s0)
/* 0EAA44 802C6094 0200202D */  daddu $a0, $s0, $zero
/* 0EAA48 802C6098 44060000 */  mfc1  $a2, $f0
/* 0EAA4C 802C609C 0C0B2190 */  jal   set_float_variable
/* 0EAA50 802C60A0 0240282D */   daddu $a1, $s2, $zero
/* 0EAA54 802C60A4 8E320000 */  lw    $s2, ($s1)
/* 0EAA58 802C60A8 26310004 */  addiu $s1, $s1, 4
/* 0EAA5C 802C60AC 8E020138 */  lw    $v0, 0x138($s0)
/* 0EAA60 802C60B0 0200202D */  daddu $a0, $s0, $zero
/* 0EAA64 802C60B4 8C450000 */  lw    $a1, ($v0)
/* 0EAA68 802C60B8 24420004 */  addiu $v0, $v0, 4
/* 0EAA6C 802C60BC 0C0B210B */  jal   get_float_variable
/* 0EAA70 802C60C0 AE020138 */   sw    $v0, 0x138($s0)
/* 0EAA74 802C60C4 0200202D */  daddu $a0, $s0, $zero
/* 0EAA78 802C60C8 44060000 */  mfc1  $a2, $f0
/* 0EAA7C 802C60CC 0C0B2190 */  jal   set_float_variable
/* 0EAA80 802C60D0 0240282D */   daddu $a1, $s2, $zero
/* 0EAA84 802C60D4 8E320000 */  lw    $s2, ($s1)
/* 0EAA88 802C60D8 26310004 */  addiu $s1, $s1, 4
/* 0EAA8C 802C60DC 8E020138 */  lw    $v0, 0x138($s0)
/* 0EAA90 802C60E0 0200202D */  daddu $a0, $s0, $zero
/* 0EAA94 802C60E4 8C450000 */  lw    $a1, ($v0)
/* 0EAA98 802C60E8 24420004 */  addiu $v0, $v0, 4
/* 0EAA9C 802C60EC 0C0B210B */  jal   get_float_variable
/* 0EAAA0 802C60F0 AE020138 */   sw    $v0, 0x138($s0)
/* 0EAAA4 802C60F4 0200202D */  daddu $a0, $s0, $zero
/* 0EAAA8 802C60F8 44060000 */  mfc1  $a2, $f0
/* 0EAAAC 802C60FC 0C0B2190 */  jal   set_float_variable
/* 0EAAB0 802C6100 0240282D */   daddu $a1, $s2, $zero
/* 0EAAB4 802C6104 0200202D */  daddu $a0, $s0, $zero
/* 0EAAB8 802C6108 8E020138 */  lw    $v0, 0x138($s0)
/* 0EAABC 802C610C 8E310000 */  lw    $s1, ($s1)
/* 0EAAC0 802C6110 8C450000 */  lw    $a1, ($v0)
/* 0EAAC4 802C6114 24420004 */  addiu $v0, $v0, 4
/* 0EAAC8 802C6118 0C0B210B */  jal   get_float_variable
/* 0EAACC 802C611C AE020138 */   sw    $v0, 0x138($s0)
/* 0EAAD0 802C6120 0200202D */  daddu $a0, $s0, $zero
/* 0EAAD4 802C6124 44060000 */  mfc1  $a2, $f0
/* 0EAAD8 802C6128 0C0B2190 */  jal   set_float_variable
/* 0EAADC 802C612C 0220282D */   daddu $a1, $s1, $zero
/* 0EAAE0 802C6130 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EAAE4 802C6134 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EAAE8 802C6138 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAAEC 802C613C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAAF0 802C6140 24020002 */  addiu $v0, $zero, 2
/* 0EAAF4 802C6144 03E00008 */  jr    $ra
/* 0EAAF8 802C6148 27BD0020 */   addiu $sp, $sp, 0x20

