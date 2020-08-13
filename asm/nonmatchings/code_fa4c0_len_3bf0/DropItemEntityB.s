.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel DropItemEntityB
/* 0FB870 802D6EC0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FB874 802D6EC4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FB878 802D6EC8 0080882D */  daddu $s1, $a0, $zero
/* 0FB87C 802D6ECC AFBF0030 */  sw    $ra, 0x30($sp)
/* 0FB880 802D6ED0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0FB884 802D6ED4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0FB888 802D6ED8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0FB88C 802D6EDC AFB20020 */  sw    $s2, 0x20($sp)
/* 0FB890 802D6EE0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FB894 802D6EE4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB898 802D6EE8 8E050000 */  lw    $a1, ($s0)
/* 0FB89C 802D6EEC 0C0B1EAF */  jal   get_variable
/* 0FB8A0 802D6EF0 26100004 */   addiu $s0, $s0, 4
/* 0FB8A4 802D6EF4 8E050000 */  lw    $a1, ($s0)
/* 0FB8A8 802D6EF8 26100004 */  addiu $s0, $s0, 4
/* 0FB8AC 802D6EFC 0220202D */  daddu $a0, $s1, $zero
/* 0FB8B0 802D6F00 0C0B1EAF */  jal   get_variable
/* 0FB8B4 802D6F04 0040A82D */   daddu $s5, $v0, $zero
/* 0FB8B8 802D6F08 8E050000 */  lw    $a1, ($s0)
/* 0FB8BC 802D6F0C 26100004 */  addiu $s0, $s0, 4
/* 0FB8C0 802D6F10 0220202D */  daddu $a0, $s1, $zero
/* 0FB8C4 802D6F14 0C0B1EAF */  jal   get_variable
/* 0FB8C8 802D6F18 0040A02D */   daddu $s4, $v0, $zero
/* 0FB8CC 802D6F1C 8E050000 */  lw    $a1, ($s0)
/* 0FB8D0 802D6F20 26100004 */  addiu $s0, $s0, 4
/* 0FB8D4 802D6F24 0220202D */  daddu $a0, $s1, $zero
/* 0FB8D8 802D6F28 0C0B1EAF */  jal   get_variable
/* 0FB8DC 802D6F2C 0040982D */   daddu $s3, $v0, $zero
/* 0FB8E0 802D6F30 8E050000 */  lw    $a1, ($s0)
/* 0FB8E4 802D6F34 26100004 */  addiu $s0, $s0, 4
/* 0FB8E8 802D6F38 0220202D */  daddu $a0, $s1, $zero
/* 0FB8EC 802D6F3C 0C0B1EAF */  jal   get_variable
/* 0FB8F0 802D6F40 0040902D */   daddu $s2, $v0, $zero
/* 0FB8F4 802D6F44 0220202D */  daddu $a0, $s1, $zero
/* 0FB8F8 802D6F48 8E050000 */  lw    $a1, ($s0)
/* 0FB8FC 802D6F4C 0C0B1F6A */  jal   get_variable_index
/* 0FB900 802D6F50 0040802D */   daddu $s0, $v0, $zero
/* 0FB904 802D6F54 44940000 */  mtc1  $s4, $f0
/* 0FB908 802D6F58 00000000 */  nop   
/* 0FB90C 802D6F5C 46800020 */  cvt.s.w $f0, $f0
/* 0FB910 802D6F60 44050000 */  mfc1  $a1, $f0
/* 0FB914 802D6F64 44930000 */  mtc1  $s3, $f0
/* 0FB918 802D6F68 00000000 */  nop   
/* 0FB91C 802D6F6C 46800020 */  cvt.s.w $f0, $f0
/* 0FB920 802D6F70 44060000 */  mfc1  $a2, $f0
/* 0FB924 802D6F74 44920000 */  mtc1  $s2, $f0
/* 0FB928 802D6F78 00000000 */  nop   
/* 0FB92C 802D6F7C 46800020 */  cvt.s.w $f0, $f0
/* 0FB930 802D6F80 44070000 */  mfc1  $a3, $f0
/* 0FB934 802D6F84 02A0202D */  daddu $a0, $s5, $zero
/* 0FB938 802D6F88 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB93C 802D6F8C 0C04C6A5 */  jal   make_item_entity_nodelay
/* 0FB940 802D6F90 AFA20014 */   sw    $v0, 0x14($sp)
/* 0FB944 802D6F94 0040202D */  daddu $a0, $v0, $zero
/* 0FB948 802D6F98 24054000 */  addiu $a1, $zero, 0x4000
/* 0FB94C 802D6F9C 0C04D052 */  jal   set_item_entity_flags
/* 0FB950 802D6FA0 AE240084 */   sw    $a0, 0x84($s1)
/* 0FB954 802D6FA4 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0FB958 802D6FA8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0FB95C 802D6FAC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FB960 802D6FB0 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FB964 802D6FB4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FB968 802D6FB8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FB96C 802D6FBC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FB970 802D6FC0 24020002 */  addiu $v0, $zero, 2
/* 0FB974 802D6FC4 03E00008 */  jr    $ra
/* 0FB978 802D6FC8 27BD0038 */   addiu $sp, $sp, 0x38

