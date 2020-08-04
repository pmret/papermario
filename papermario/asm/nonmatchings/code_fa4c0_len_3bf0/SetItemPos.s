.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetItemPos
/* 0FBA80 802D70D0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FBA84 802D70D4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FBA88 802D70D8 0080882D */  daddu $s1, $a0, $zero
/* 0FBA8C 802D70DC AFBF0020 */  sw    $ra, 0x20($sp)
/* 0FBA90 802D70E0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0FBA94 802D70E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FBA98 802D70E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBA9C 802D70EC 8E30000C */  lw    $s0, 0xc($s1)
/* 0FBAA0 802D70F0 8E050000 */  lw    $a1, ($s0)
/* 0FBAA4 802D70F4 0C0B1EAF */  jal   get_variable
/* 0FBAA8 802D70F8 26100004 */   addiu $s0, $s0, 4
/* 0FBAAC 802D70FC 8E050000 */  lw    $a1, ($s0)
/* 0FBAB0 802D7100 26100004 */  addiu $s0, $s0, 4
/* 0FBAB4 802D7104 0220202D */  daddu $a0, $s1, $zero
/* 0FBAB8 802D7108 0C0B1EAF */  jal   get_variable
/* 0FBABC 802D710C 0040982D */   daddu $s3, $v0, $zero
/* 0FBAC0 802D7110 8E050000 */  lw    $a1, ($s0)
/* 0FBAC4 802D7114 26100004 */  addiu $s0, $s0, 4
/* 0FBAC8 802D7118 0220202D */  daddu $a0, $s1, $zero
/* 0FBACC 802D711C 0C0B1EAF */  jal   get_variable
/* 0FBAD0 802D7120 0040902D */   daddu $s2, $v0, $zero
/* 0FBAD4 802D7124 0220202D */  daddu $a0, $s1, $zero
/* 0FBAD8 802D7128 8E050000 */  lw    $a1, ($s0)
/* 0FBADC 802D712C 0C0B1EAF */  jal   get_variable
/* 0FBAE0 802D7130 0040882D */   daddu $s1, $v0, $zero
/* 0FBAE4 802D7134 0260202D */  daddu $a0, $s3, $zero
/* 0FBAE8 802D7138 0C04C3D6 */  jal   get_item_entity
/* 0FBAEC 802D713C 0040802D */   daddu $s0, $v0, $zero
/* 0FBAF0 802D7140 0040182D */  daddu $v1, $v0, $zero
/* 0FBAF4 802D7144 44920000 */  mtc1  $s2, $f0
/* 0FBAF8 802D7148 00000000 */  nop   
/* 0FBAFC 802D714C 46800020 */  cvt.s.w $f0, $f0
/* 0FBB00 802D7150 E4600008 */  swc1  $f0, 8($v1)
/* 0FBB04 802D7154 44910000 */  mtc1  $s1, $f0
/* 0FBB08 802D7158 00000000 */  nop   
/* 0FBB0C 802D715C 46800020 */  cvt.s.w $f0, $f0
/* 0FBB10 802D7160 E460000C */  swc1  $f0, 0xc($v1)
/* 0FBB14 802D7164 44900000 */  mtc1  $s0, $f0
/* 0FBB18 802D7168 00000000 */  nop   
/* 0FBB1C 802D716C 46800020 */  cvt.s.w $f0, $f0
/* 0FBB20 802D7170 E4600010 */  swc1  $f0, 0x10($v1)
/* 0FBB24 802D7174 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0FBB28 802D7178 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0FBB2C 802D717C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FBB30 802D7180 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FBB34 802D7184 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBB38 802D7188 24020002 */  addiu $v0, $zero, 2
/* 0FBB3C 802D718C 03E00008 */  jr    $ra
/* 0FBB40 802D7190 27BD0028 */   addiu $sp, $sp, 0x28

