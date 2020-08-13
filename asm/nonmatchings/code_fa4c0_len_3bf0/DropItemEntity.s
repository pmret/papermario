.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel DropItemEntity
/* 0FB770 802D6DC0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FB774 802D6DC4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FB778 802D6DC8 0080882D */  daddu $s1, $a0, $zero
/* 0FB77C 802D6DCC AFBF0030 */  sw    $ra, 0x30($sp)
/* 0FB780 802D6DD0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0FB784 802D6DD4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0FB788 802D6DD8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0FB78C 802D6DDC AFB20020 */  sw    $s2, 0x20($sp)
/* 0FB790 802D6DE0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FB794 802D6DE4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB798 802D6DE8 8E050000 */  lw    $a1, ($s0)
/* 0FB79C 802D6DEC 0C0B1EAF */  jal   get_variable
/* 0FB7A0 802D6DF0 26100004 */   addiu $s0, $s0, 4
/* 0FB7A4 802D6DF4 8E050000 */  lw    $a1, ($s0)
/* 0FB7A8 802D6DF8 26100004 */  addiu $s0, $s0, 4
/* 0FB7AC 802D6DFC 0220202D */  daddu $a0, $s1, $zero
/* 0FB7B0 802D6E00 0C0B1EAF */  jal   get_variable
/* 0FB7B4 802D6E04 0040A82D */   daddu $s5, $v0, $zero
/* 0FB7B8 802D6E08 8E050000 */  lw    $a1, ($s0)
/* 0FB7BC 802D6E0C 26100004 */  addiu $s0, $s0, 4
/* 0FB7C0 802D6E10 0220202D */  daddu $a0, $s1, $zero
/* 0FB7C4 802D6E14 0C0B1EAF */  jal   get_variable
/* 0FB7C8 802D6E18 0040A02D */   daddu $s4, $v0, $zero
/* 0FB7CC 802D6E1C 8E050000 */  lw    $a1, ($s0)
/* 0FB7D0 802D6E20 26100004 */  addiu $s0, $s0, 4
/* 0FB7D4 802D6E24 0220202D */  daddu $a0, $s1, $zero
/* 0FB7D8 802D6E28 0C0B1EAF */  jal   get_variable
/* 0FB7DC 802D6E2C 0040982D */   daddu $s3, $v0, $zero
/* 0FB7E0 802D6E30 8E050000 */  lw    $a1, ($s0)
/* 0FB7E4 802D6E34 26100004 */  addiu $s0, $s0, 4
/* 0FB7E8 802D6E38 0220202D */  daddu $a0, $s1, $zero
/* 0FB7EC 802D6E3C 0C0B1EAF */  jal   get_variable
/* 0FB7F0 802D6E40 0040902D */   daddu $s2, $v0, $zero
/* 0FB7F4 802D6E44 0220202D */  daddu $a0, $s1, $zero
/* 0FB7F8 802D6E48 8E050000 */  lw    $a1, ($s0)
/* 0FB7FC 802D6E4C 0C0B1EAF */  jal   get_variable
/* 0FB800 802D6E50 0040802D */   daddu $s0, $v0, $zero
/* 0FB804 802D6E54 44940000 */  mtc1  $s4, $f0
/* 0FB808 802D6E58 00000000 */  nop   
/* 0FB80C 802D6E5C 46800020 */  cvt.s.w $f0, $f0
/* 0FB810 802D6E60 44050000 */  mfc1  $a1, $f0
/* 0FB814 802D6E64 44930000 */  mtc1  $s3, $f0
/* 0FB818 802D6E68 00000000 */  nop   
/* 0FB81C 802D6E6C 46800020 */  cvt.s.w $f0, $f0
/* 0FB820 802D6E70 44060000 */  mfc1  $a2, $f0
/* 0FB824 802D6E74 44920000 */  mtc1  $s2, $f0
/* 0FB828 802D6E78 00000000 */  nop   
/* 0FB82C 802D6E7C 46800020 */  cvt.s.w $f0, $f0
/* 0FB830 802D6E80 44070000 */  mfc1  $a3, $f0
/* 0FB834 802D6E84 02A0202D */  daddu $a0, $s5, $zero
/* 0FB838 802D6E88 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB83C 802D6E8C 0C04C6A5 */  jal   make_item_entity_nodelay
/* 0FB840 802D6E90 AFA20014 */   sw    $v0, 0x14($sp)
/* 0FB844 802D6E94 AE220084 */  sw    $v0, 0x84($s1)
/* 0FB848 802D6E98 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0FB84C 802D6E9C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0FB850 802D6EA0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FB854 802D6EA4 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FB858 802D6EA8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FB85C 802D6EAC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FB860 802D6EB0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FB864 802D6EB4 24020002 */  addiu $v0, $zero, 2
/* 0FB868 802D6EB8 03E00008 */  jr    $ra
/* 0FB86C 802D6EBC 27BD0038 */   addiu $sp, $sp, 0x38

