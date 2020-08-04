.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A6D8
/* 13DA18 8024A6D8 24A5000C */  addiu $a1, $a1, 0xc
.L8024A6DC:
/* 13DA1C 8024A6DC 28820014 */  slti  $v0, $a0, 0x14
/* 13DA20 8024A6E0 5440FFFC */  bnezl $v0, .L8024A6D4
/* 13DA24 8024A6E4 A0A00000 */   sb    $zero, ($a1)
/* 13DA28 8024A6E8 0000202D */  daddu $a0, $zero, $zero
/* 13DA2C 8024A6EC 0C09260A */  jal   func_80249828
/* 13DA30 8024A6F0 0080282D */   daddu $a1, $a0, $zero
/* 13DA34 8024A6F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 13DA38 8024A6F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 13DA3C 8024A6FC 3C018027 */  lui   $at, 0x8027
/* 13DA40 8024A700 AC2205D4 */  sw    $v0, 0x5d4($at)
/* 13DA44 8024A704 3C018027 */  lui   $at, 0x8027
/* 13DA48 8024A708 AC2205D8 */  sw    $v0, 0x5d8($at)
/* 13DA4C 8024A70C 03E00008 */  jr    $ra
/* 13DA50 8024A710 27BD0018 */   addiu $sp, $sp, 0x18

/* 13DA54 8024A714 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 13DA58 8024A718 AFB3001C */  sw    $s3, 0x1c($sp)
/* 13DA5C 8024A71C 0080982D */  daddu $s3, $a0, $zero
/* 13DA60 8024A720 AFBF0020 */  sw    $ra, 0x20($sp)
/* 13DA64 8024A724 AFB20018 */  sw    $s2, 0x18($sp)
/* 13DA68 8024A728 AFB10014 */  sw    $s1, 0x14($sp)
/* 13DA6C 8024A72C AFB00010 */  sw    $s0, 0x10($sp)
/* 13DA70 8024A730 3C018027 */  lui   $at, 0x8027
/* 13DA74 8024A734 AC2005E0 */  sw    $zero, 0x5e0($at)
/* 13DA78 8024A738 3C018027 */  lui   $at, 0x8027
/* 13DA7C 8024A73C AC2005E4 */  sw    $zero, 0x5e4($at)
/* 13DA80 8024A740 0C092937 */  jal   func_8024A4DC
/* 13DA84 8024A744 0000202D */   daddu $a0, $zero, $zero
/* 13DA88 8024A748 0000802D */  daddu $s0, $zero, $zero
/* 13DA8C 8024A74C 3C128027 */  lui   $s2, 0x8027
/* 13DA90 8024A750 265205E8 */  addiu $s2, $s2, 0x5e8
/* 13DA94 8024A754 3C118025 */  lui   $s1, 0x8025
/* 13DA98 8024A758 2631F570 */  addiu $s1, $s1, -0xa90
.L8024A75C:
/* 13DA9C 8024A75C 8E240000 */  lw    $a0, ($s1)
/* 13DAA0 8024A760 26310004 */  addiu $s1, $s1, 4
/* 13DAA4 8024A764 0C050529 */  jal   create_icon
/* 13DAA8 8024A768 26100001 */   addiu $s0, $s0, 1
/* 13DAAC 8024A76C 0040202D */  daddu $a0, $v0, $zero
/* 13DAB0 8024A770 24050080 */  addiu $a1, $zero, 0x80
/* 13DAB4 8024A774 0C051280 */  jal   set_icon_flags
/* 13DAB8 8024A778 AE440000 */   sw    $a0, ($s2)
/* 13DABC 8024A77C 2A020014 */  slti  $v0, $s0, 0x14
/* 13DAC0 8024A780 1440FFF6 */  bnez  $v0, .L8024A75C
/* 13DAC4 8024A784 26520004 */   addiu $s2, $s2, 4
/* 13DAC8 8024A788 0000802D */  daddu $s0, $zero, $zero
/* 13DACC 8024A78C 3C028025 */  lui   $v0, 0x8025
/* 13DAD0 8024A790 2442F5C0 */  addiu $v0, $v0, -0xa40
.L8024A794:
/* 13DAD4 8024A794 AC530010 */  sw    $s3, 0x10($v0)
/* 13DAD8 8024A798 26100001 */  addiu $s0, $s0, 1
/* 13DADC 8024A79C 1A00FFFD */  blez  $s0, .L8024A794
