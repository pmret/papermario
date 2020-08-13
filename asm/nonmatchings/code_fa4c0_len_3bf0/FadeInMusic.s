.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FadeInMusic
/* 0FA7A4 802D5DF4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FA7A8 802D5DF8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FA7AC 802D5DFC 0080882D */  daddu $s1, $a0, $zero
/* 0FA7B0 802D5E00 AFBF0030 */  sw    $ra, 0x30($sp)
/* 0FA7B4 802D5E04 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0FA7B8 802D5E08 AFB40028 */  sw    $s4, 0x28($sp)
/* 0FA7BC 802D5E0C AFB30024 */  sw    $s3, 0x24($sp)
/* 0FA7C0 802D5E10 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FA7C4 802D5E14 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FA7C8 802D5E18 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA7CC 802D5E1C 8E050000 */  lw    $a1, ($s0)
/* 0FA7D0 802D5E20 0C0B1EAF */  jal   get_variable
/* 0FA7D4 802D5E24 26100004 */   addiu $s0, $s0, 4
/* 0FA7D8 802D5E28 8E050000 */  lw    $a1, ($s0)
/* 0FA7DC 802D5E2C 26100004 */  addiu $s0, $s0, 4
/* 0FA7E0 802D5E30 0220202D */  daddu $a0, $s1, $zero
/* 0FA7E4 802D5E34 0C0B1EAF */  jal   get_variable
/* 0FA7E8 802D5E38 0040A82D */   daddu $s5, $v0, $zero
/* 0FA7EC 802D5E3C 8E050000 */  lw    $a1, ($s0)
/* 0FA7F0 802D5E40 26100004 */  addiu $s0, $s0, 4
/* 0FA7F4 802D5E44 0220202D */  daddu $a0, $s1, $zero
/* 0FA7F8 802D5E48 0C0B1EAF */  jal   get_variable
/* 0FA7FC 802D5E4C 0040982D */   daddu $s3, $v0, $zero
/* 0FA800 802D5E50 8E050000 */  lw    $a1, ($s0)
/* 0FA804 802D5E54 26100004 */  addiu $s0, $s0, 4
/* 0FA808 802D5E58 0220202D */  daddu $a0, $s1, $zero
/* 0FA80C 802D5E5C 0C0B1EAF */  jal   get_variable
/* 0FA810 802D5E60 0040A02D */   daddu $s4, $v0, $zero
/* 0FA814 802D5E64 8E050000 */  lw    $a1, ($s0)
/* 0FA818 802D5E68 26100004 */  addiu $s0, $s0, 4
/* 0FA81C 802D5E6C 0220202D */  daddu $a0, $s1, $zero
/* 0FA820 802D5E70 0C0B1EAF */  jal   get_variable
/* 0FA824 802D5E74 0040902D */   daddu $s2, $v0, $zero
/* 0FA828 802D5E78 0220202D */  daddu $a0, $s1, $zero
/* 0FA82C 802D5E7C 8E050000 */  lw    $a1, ($s0)
/* 0FA830 802D5E80 0C0B1EAF */  jal   get_variable
/* 0FA834 802D5E84 0040802D */   daddu $s0, $v0, $zero
/* 0FA838 802D5E88 02A0202D */  daddu $a0, $s5, $zero
/* 0FA83C 802D5E8C 0260282D */  daddu $a1, $s3, $zero
/* 0FA840 802D5E90 00108400 */  sll   $s0, $s0, 0x10
/* 0FA844 802D5E94 00108403 */  sra   $s0, $s0, 0x10
/* 0FA848 802D5E98 00021400 */  sll   $v0, $v0, 0x10
/* 0FA84C 802D5E9C 00021403 */  sra   $v0, $v0, 0x10
/* 0FA850 802D5EA0 0280302D */  daddu $a2, $s4, $zero
/* 0FA854 802D5EA4 0240382D */  daddu $a3, $s2, $zero
/* 0FA858 802D5EA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA85C 802D5EAC 0C052A59 */  jal   func_8014A964
/* 0FA860 802D5EB0 AFA20014 */   sw    $v0, 0x14($sp)
/* 0FA864 802D5EB4 0002102B */  sltu  $v0, $zero, $v0
/* 0FA868 802D5EB8 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0FA86C 802D5EBC 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0FA870 802D5EC0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FA874 802D5EC4 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FA878 802D5EC8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FA87C 802D5ECC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FA880 802D5ED0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FA884 802D5ED4 00021040 */  sll   $v0, $v0, 1
/* 0FA888 802D5ED8 03E00008 */  jr    $ra
/* 0FA88C 802D5EDC 27BD0038 */   addiu $sp, $sp, 0x38

glabel func_802D5EE0
/* 0FA890 802D5EE0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA894 802D5EE4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA898 802D5EE8 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA89C 802D5EEC 0C0B1EAF */  jal   get_variable
/* 0FA8A0 802D5EF0 8C450000 */   lw    $a1, ($v0)
/* 0FA8A4 802D5EF4 3C048016 */  lui   $a0, 0x8016
/* 0FA8A8 802D5EF8 24849AF0 */  addiu $a0, $a0, -0x6510
/* 0FA8AC 802D5EFC 00021840 */  sll   $v1, $v0, 1
/* 0FA8B0 802D5F00 00621821 */  addu  $v1, $v1, $v0
/* 0FA8B4 802D5F04 00031900 */  sll   $v1, $v1, 4
/* 0FA8B8 802D5F08 00641821 */  addu  $v1, $v1, $a0
/* 0FA8BC 802D5F0C 94640000 */  lhu   $a0, ($v1)
/* 0FA8C0 802D5F10 24020002 */  addiu $v0, $zero, 2
/* 0FA8C4 802D5F14 00822025 */  or    $a0, $a0, $v0
/* 0FA8C8 802D5F18 A4640000 */  sh    $a0, ($v1)
/* 0FA8CC 802D5F1C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA8D0 802D5F20 03E00008 */  jr    $ra
/* 0FA8D4 802D5F24 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D5F28
/* 0FA8D8 802D5F28 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA8DC 802D5F2C AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA8E0 802D5F30 0080882D */  daddu $s1, $a0, $zero
/* 0FA8E4 802D5F34 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FA8E8 802D5F38 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FA8EC 802D5F3C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA8F0 802D5F40 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA8F4 802D5F44 8E050000 */  lw    $a1, ($s0)
/* 0FA8F8 802D5F48 0C0B1EAF */  jal   get_variable
/* 0FA8FC 802D5F4C 26100004 */   addiu $s0, $s0, 4
/* 0FA900 802D5F50 8E050000 */  lw    $a1, ($s0)
/* 0FA904 802D5F54 26100004 */  addiu $s0, $s0, 4
/* 0FA908 802D5F58 0220202D */  daddu $a0, $s1, $zero
/* 0FA90C 802D5F5C 0C0B1EAF */  jal   get_variable
/* 0FA910 802D5F60 0040902D */   daddu $s2, $v0, $zero
/* 0FA914 802D5F64 0220202D */  daddu $a0, $s1, $zero
/* 0FA918 802D5F68 8E050000 */  lw    $a1, ($s0)
/* 0FA91C 802D5F6C 0C0B1EAF */  jal   get_variable
/* 0FA920 802D5F70 0040802D */   daddu $s0, $v0, $zero
/* 0FA924 802D5F74 0240202D */  daddu $a0, $s2, $zero
/* 0FA928 802D5F78 0200282D */  daddu $a1, $s0, $zero
/* 0FA92C 802D5F7C 00021400 */  sll   $v0, $v0, 0x10
/* 0FA930 802D5F80 0C052A95 */  jal   func_8014AA54
/* 0FA934 802D5F84 00023403 */   sra   $a2, $v0, 0x10
/* 0FA938 802D5F88 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FA93C 802D5F8C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FA940 802D5F90 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA944 802D5F94 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA948 802D5F98 24020002 */  addiu $v0, $zero, 2
/* 0FA94C 802D5F9C 03E00008 */  jr    $ra
/* 0FA950 802D5FA0 27BD0020 */   addiu $sp, $sp, 0x20

glabel func_802D5FA4
/* 0FA954 802D5FA4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA958 802D5FA8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA95C 802D5FAC 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA960 802D5FB0 0C0B1EAF */  jal   get_variable
/* 0FA964 802D5FB4 8C450000 */   lw    $a1, ($v0)
/* 0FA968 802D5FB8 0000202D */  daddu $a0, $zero, $zero
/* 0FA96C 802D5FBC 00021400 */  sll   $v0, $v0, 0x10
/* 0FA970 802D5FC0 0C052AC3 */  jal   func_8014AB0C
/* 0FA974 802D5FC4 00022C03 */   sra   $a1, $v0, 0x10
/* 0FA978 802D5FC8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA97C 802D5FCC 24020002 */  addiu $v0, $zero, 2
/* 0FA980 802D5FD0 03E00008 */  jr    $ra
/* 0FA984 802D5FD4 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D5FD8
/* 0FA988 802D5FD8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA98C 802D5FDC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA990 802D5FE0 0C052B69 */  jal   func_8014ADA4
/* 0FA994 802D5FE4 00000000 */   nop   
/* 0FA998 802D5FE8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA99C 802D5FEC 24020002 */  addiu $v0, $zero, 2
/* 0FA9A0 802D5FF0 03E00008 */  jr    $ra
/* 0FA9A4 802D5FF4 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D5FF8
/* 0FA9A8 802D5FF8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA9AC 802D5FFC AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA9B0 802D6000 0080882D */  daddu $s1, $a0, $zero
/* 0FA9B4 802D6004 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA9B8 802D6008 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA9BC 802D600C 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA9C0 802D6010 8E050000 */  lw    $a1, ($s0)
/* 0FA9C4 802D6014 0C0B1EAF */  jal   get_variable
/* 0FA9C8 802D6018 26100004 */   addiu $s0, $s0, 4
/* 0FA9CC 802D601C 0220202D */  daddu $a0, $s1, $zero
/* 0FA9D0 802D6020 8E050000 */  lw    $a1, ($s0)
/* 0FA9D4 802D6024 0C0B1EAF */  jal   get_variable
/* 0FA9D8 802D6028 0040802D */   daddu $s0, $v0, $zero
/* 0FA9DC 802D602C 0200202D */  daddu $a0, $s0, $zero
/* 0FA9E0 802D6030 0C052B7E */  jal   func_8014ADF8
/* 0FA9E4 802D6034 0040282D */   daddu $a1, $v0, $zero
/* 0FA9E8 802D6038 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA9EC 802D603C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA9F0 802D6040 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA9F4 802D6044 24020002 */  addiu $v0, $zero, 2
/* 0FA9F8 802D6048 03E00008 */  jr    $ra
/* 0FA9FC 802D604C 27BD0020 */   addiu $sp, $sp, 0x20

glabel func_802D6050
/* 0FAA00 802D6050 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAA04 802D6054 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAA08 802D6058 0C052B9B */  jal   func_8014AE6C
/* 0FAA0C 802D605C 00000000 */   nop   
/* 0FAA10 802D6060 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAA14 802D6064 24020002 */  addiu $v0, $zero, 2
/* 0FAA18 802D6068 03E00008 */  jr    $ra
/* 0FAA1C 802D606C 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D6070
/* 0FAA20 802D6070 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAA24 802D6074 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAA28 802D6078 0C052BBE */  jal   func_8014AEF8
/* 0FAA2C 802D607C 00000000 */   nop   
/* 0FAA30 802D6080 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAA34 802D6084 24020002 */  addiu $v0, $zero, 2
/* 0FAA38 802D6088 03E00008 */  jr    $ra
/* 0FAA3C 802D608C 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D6090
/* 0FAA40 802D6090 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FAA44 802D6094 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FAA48 802D6098 0080882D */  daddu $s1, $a0, $zero
/* 0FAA4C 802D609C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FAA50 802D60A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FAA54 802D60A4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FAA58 802D60A8 8E050000 */  lw    $a1, ($s0)
/* 0FAA5C 802D60AC 0C0B1EAF */  jal   get_variable
/* 0FAA60 802D60B0 26100004 */   addiu $s0, $s0, 4
/* 0FAA64 802D60B4 0220202D */  daddu $a0, $s1, $zero
/* 0FAA68 802D60B8 8E050000 */  lw    $a1, ($s0)
/* 0FAA6C 802D60BC 0C0B1EAF */  jal   get_variable
/* 0FAA70 802D60C0 0040802D */   daddu $s0, $v0, $zero
/* 0FAA74 802D60C4 0200202D */  daddu $a0, $s0, $zero
/* 0FAA78 802D60C8 0C052BE3 */  jal   func_8014AF8C
/* 0FAA7C 802D60CC 0040282D */   daddu $a1, $v0, $zero
/* 0FAA80 802D60D0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FAA84 802D60D4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FAA88 802D60D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FAA8C 802D60DC 24020002 */  addiu $v0, $zero, 2
/* 0FAA90 802D60E0 03E00008 */  jr    $ra
/* 0FAA94 802D60E4 27BD0020 */   addiu $sp, $sp, 0x20

glabel func_802D60E8
/* 0FAA98 802D60E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAA9C 802D60EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAAA0 802D60F0 8C82000C */  lw    $v0, 0xc($a0)
/* 0FAAA4 802D60F4 0C0B1EAF */  jal   get_variable
/* 0FAAA8 802D60F8 8C450000 */   lw    $a1, ($v0)
/* 0FAAAC 802D60FC 2404FFFF */  addiu $a0, $zero, -1
/* 0FAAB0 802D6100 0C051CDA */  jal   play_ambient_sounds
/* 0FAAB4 802D6104 0040282D */   daddu $a1, $v0, $zero
/* 0FAAB8 802D6108 0002102B */  sltu  $v0, $zero, $v0
/* 0FAABC 802D610C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAAC0 802D6110 00021040 */  sll   $v0, $v0, 1
/* 0FAAC4 802D6114 03E00008 */  jr    $ra
/* 0FAAC8 802D6118 27BD0018 */   addiu $sp, $sp, 0x18

