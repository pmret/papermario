.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025CEC8
/* 18B7A8 8025CEC8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 18B7AC 8025CECC AFB10014 */  sw    $s1, 0x14($sp)
/* 18B7B0 8025CED0 0080882D */  daddu $s1, $a0, $zero
/* 18B7B4 8025CED4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 18B7B8 8025CED8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 18B7BC 8025CEDC AFB20018 */  sw    $s2, 0x18($sp)
/* 18B7C0 8025CEE0 AFB00010 */  sw    $s0, 0x10($sp)
/* 18B7C4 8025CEE4 8E220000 */  lw    $v0, ($s1)
/* 18B7C8 8025CEE8 30420002 */  andi  $v0, $v0, 2
/* 18B7CC 8025CEEC 1440004C */  bnez  $v0, .L8025D020
/* 18B7D0 8025CEF0 0000802D */   daddu $s0, $zero, $zero
/* 18B7D4 8025CEF4 8E3200C0 */  lw    $s2, 0xc0($s1)
/* 18B7D8 8025CEF8 3C13802A */  lui   $s3, 0x802a
/* 18B7DC 8025CEFC 2673D488 */  addiu $s3, $s3, -0x2b78
/* 18B7E0 8025CF00 02501021 */  addu  $v0, $s2, $s0
.L8025CF04:
/* 18B7E4 8025CF04 804308B8 */  lb    $v1, 0x8b8($v0)
/* 18B7E8 8025CF08 2C62000C */  sltiu $v0, $v1, 0xc
/* 18B7EC 8025CF0C 50400041 */  beql  $v0, $zero, .L8025D014
/* 18B7F0 8025CF10 26100001 */   addiu $s0, $s0, 1
/* 18B7F4 8025CF14 00031080 */  sll   $v0, $v1, 2
/* 18B7F8 8025CF18 00531021 */  addu  $v0, $v0, $s3
/* 18B7FC 8025CF1C 8C420000 */  lw    $v0, ($v0)
/* 18B800 8025CF20 00400008 */  jr    $v0
/* 18B804 8025CF24 00000000 */   nop   
/* 18B808 8025CF28 0220202D */  daddu $a0, $s1, $zero
/* 18B80C 8025CF2C 0C097454 */  jal   func_8025D150
/* 18B810 8025CF30 0200282D */   daddu $a1, $s0, $zero
/* 18B814 8025CF34 08097405 */  j     .L8025D014
/* 18B818 8025CF38 26100001 */   addiu $s0, $s0, 1

/* 18B81C 8025CF3C 0220202D */  daddu $a0, $s1, $zero
/* 18B820 8025CF40 0C097458 */  jal   func_8025D160
/* 18B824 8025CF44 0200282D */   daddu $a1, $s0, $zero
/* 18B828 8025CF48 08097405 */  j     .L8025D014
/* 18B82C 8025CF4C 26100001 */   addiu $s0, $s0, 1

/* 18B830 8025CF50 0220202D */  daddu $a0, $s1, $zero
/* 18B834 8025CF54 0C0974AC */  jal   func_8025D2B0
/* 18B838 8025CF58 0200282D */   daddu $a1, $s0, $zero
/* 18B83C 8025CF5C 08097405 */  j     .L8025D014
/* 18B840 8025CF60 26100001 */   addiu $s0, $s0, 1

/* 18B844 8025CF64 0220202D */  daddu $a0, $s1, $zero
/* 18B848 8025CF68 0C0974F3 */  jal   func_8025D3CC
/* 18B84C 8025CF6C 0200282D */   daddu $a1, $s0, $zero
/* 18B850 8025CF70 08097405 */  j     .L8025D014
/* 18B854 8025CF74 26100001 */   addiu $s0, $s0, 1

/* 18B858 8025CF78 0220202D */  daddu $a0, $s1, $zero
/* 18B85C 8025CF7C 0C097532 */  jal   func_8025D4C8
/* 18B860 8025CF80 0200282D */   daddu $a1, $s0, $zero
/* 18B864 8025CF84 08097405 */  j     .L8025D014
/* 18B868 8025CF88 26100001 */   addiu $s0, $s0, 1

/* 18B86C 8025CF8C 0220202D */  daddu $a0, $s1, $zero
/* 18B870 8025CF90 0C097590 */  jal   func_8025D640
/* 18B874 8025CF94 0200282D */   daddu $a1, $s0, $zero
/* 18B878 8025CF98 08097405 */  j     .L8025D014
/* 18B87C 8025CF9C 26100001 */   addiu $s0, $s0, 1

/* 18B880 8025CFA0 0220202D */  daddu $a0, $s1, $zero
/* 18B884 8025CFA4 0C0975C7 */  jal   func_8025D71C
/* 18B888 8025CFA8 0200282D */   daddu $a1, $s0, $zero
/* 18B88C 8025CFAC 08097405 */  j     .L8025D014
/* 18B890 8025CFB0 26100001 */   addiu $s0, $s0, 1

/* 18B894 8025CFB4 0220202D */  daddu $a0, $s1, $zero
/* 18B898 8025CFB8 0C09760C */  jal   func_8025D830
/* 18B89C 8025CFBC 0200282D */   daddu $a1, $s0, $zero
/* 18B8A0 8025CFC0 08097405 */  j     .L8025D014
/* 18B8A4 8025CFC4 26100001 */   addiu $s0, $s0, 1

/* 18B8A8 8025CFC8 0220202D */  daddu $a0, $s1, $zero
/* 18B8AC 8025CFCC 0C097643 */  jal   func_8025D90C
/* 18B8B0 8025CFD0 0200282D */   daddu $a1, $s0, $zero
/* 18B8B4 8025CFD4 08097405 */  j     .L8025D014
/* 18B8B8 8025CFD8 26100001 */   addiu $s0, $s0, 1

/* 18B8BC 8025CFDC 0220202D */  daddu $a0, $s1, $zero
/* 18B8C0 8025CFE0 0C09769A */  jal   func_8025DA68
/* 18B8C4 8025CFE4 0200282D */   daddu $a1, $s0, $zero
/* 18B8C8 8025CFE8 08097405 */  j     .L8025D014
/* 18B8CC 8025CFEC 26100001 */   addiu $s0, $s0, 1

/* 18B8D0 8025CFF0 0220202D */  daddu $a0, $s1, $zero
/* 18B8D4 8025CFF4 0C0976F4 */  jal   func_8025DBD0
/* 18B8D8 8025CFF8 0200282D */   daddu $a1, $s0, $zero
/* 18B8DC 8025CFFC 08097405 */  j     .L8025D014
/* 18B8E0 8025D000 26100001 */   addiu $s0, $s0, 1

/* 18B8E4 8025D004 0220202D */  daddu $a0, $s1, $zero
/* 18B8E8 8025D008 0C097758 */  jal   func_8025DD60
/* 18B8EC 8025D00C 0200282D */   daddu $a1, $s0, $zero
/* 18B8F0 8025D010 26100001 */  addiu $s0, $s0, 1
.L8025D014:
.L8025D014:
/* 18B8F4 8025D014 2A020002 */  slti  $v0, $s0, 2
/* 18B8F8 8025D018 1440FFBA */  bnez  $v0, .L8025CF04
/* 18B8FC 8025D01C 02501021 */   addu  $v0, $s2, $s0
.L8025D020:
/* 18B900 8025D020 8FBF0020 */  lw    $ra, 0x20($sp)
/* 18B904 8025D024 8FB3001C */  lw    $s3, 0x1c($sp)
/* 18B908 8025D028 8FB20018 */  lw    $s2, 0x18($sp)
/* 18B90C 8025D02C 8FB10014 */  lw    $s1, 0x14($sp)
/* 18B910 8025D030 8FB00010 */  lw    $s0, 0x10($sp)
/* 18B914 8025D034 03E00008 */  jr    $ra
/* 18B918 8025D038 27BD0028 */   addiu $sp, $sp, 0x28

