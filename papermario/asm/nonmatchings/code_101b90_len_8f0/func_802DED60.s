.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DED60
/* 101E50 802DED60 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 101E54 802DED64 AFB10014 */  sw    $s1, 0x14($sp)
/* 101E58 802DED68 0080882D */  daddu $s1, $a0, $zero
/* 101E5C 802DED6C AFB20018 */  sw    $s2, 0x18($sp)
/* 101E60 802DED70 00A0902D */  daddu $s2, $a1, $zero
/* 101E64 802DED74 3C040194 */  lui   $a0, 0x194
/* 101E68 802DED78 34843010 */  ori   $a0, $a0, 0x3010
/* 101E6C 802DED7C AFB00010 */  sw    $s0, 0x10($sp)
/* 101E70 802DED80 3C10802E */  lui   $s0, 0x802e
/* 101E74 802DED84 26100C60 */  addiu $s0, $s0, 0xc60
/* 101E78 802DED88 0200282D */  daddu $a1, $s0, $zero
/* 101E7C 802DED8C AFBF001C */  sw    $ra, 0x1c($sp)
/* 101E80 802DED90 0C017D24 */  jal   nuPiReadRom
/* 101E84 802DED94 2406000C */   addiu $a2, $zero, 0xc
/* 101E88 802DED98 3C060194 */  lui   $a2, 0x194
/* 101E8C 802DED9C 34C63010 */  ori   $a2, $a2, 0x3010
/* 101E90 802DEDA0 3C048035 */  lui   $a0, 0x8035
/* 101E94 802DEDA4 2484F800 */  addiu $a0, $a0, -0x800
/* 101E98 802DEDA8 8E020000 */  lw    $v0, ($s0)
/* 101E9C 802DEDAC 02510018 */  mult  $s2, $s1
/* 101EA0 802DEDB0 3C01802E */  lui   $at, 0x802e
/* 101EA4 802DEDB4 AC310C58 */  sw    $s1, 0xc58($at)
/* 101EA8 802DEDB8 3C11802E */  lui   $s1, 0x802e
/* 101EAC 802DEDBC 26310C5C */  addiu $s1, $s1, 0xc5c
/* 101EB0 802DEDC0 AE320000 */  sw    $s2, ($s1)
/* 101EB4 802DEDC4 8E030008 */  lw    $v1, 8($s0)
/* 101EB8 802DEDC8 00461021 */  addu  $v0, $v0, $a2
/* 101EBC 802DEDCC AE020000 */  sw    $v0, ($s0)
/* 101EC0 802DEDD0 8E020004 */  lw    $v0, 4($s0)
/* 101EC4 802DEDD4 00661821 */  addu  $v1, $v1, $a2
/* 101EC8 802DEDD8 AE030008 */  sw    $v1, 8($s0)
/* 101ECC 802DEDDC 00461021 */  addu  $v0, $v0, $a2
/* 101ED0 802DEDE0 00002812 */  mflo  $a1
/* 101ED4 802DEDE4 0C00A41B */  jal   _heap_malloc
/* 101ED8 802DEDE8 AE020004 */   sw    $v0, 4($s0)
/* 101EDC 802DEDEC 0040282D */  daddu $a1, $v0, $zero
/* 101EE0 802DEDF0 0000202D */  daddu $a0, $zero, $zero
/* 101EE4 802DEDF4 240600FF */  addiu $a2, $zero, 0xff
/* 101EE8 802DEDF8 3C03802E */  lui   $v1, 0x802e
/* 101EEC 802DEDFC 24630C70 */  addiu $v1, $v1, 0xc70
/* 101EF0 802DEE00 8E310000 */  lw    $s1, ($s1)
.L802DEE04:
/* 101EF4 802DEE04 AC65000C */  sw    $a1, 0xc($v1)
/* 101EF8 802DEE08 00B12821 */  addu  $a1, $a1, $s1
/* 101EFC 802DEE0C AC600000 */  sw    $zero, ($v1)
/* 101F00 802DEE10 AC600004 */  sw    $zero, 4($v1)
/* 101F04 802DEE14 AC660008 */  sw    $a2, 8($v1)
/* 101F08 802DEE18 24840001 */  addiu $a0, $a0, 1
/* 101F0C 802DEE1C 28820012 */  slti  $v0, $a0, 0x12
/* 101F10 802DEE20 1440FFF8 */  bnez  $v0, .L802DEE04
/* 101F14 802DEE24 24630010 */   addiu $v1, $v1, 0x10
/* 101F18 802DEE28 2404000C */  addiu $a0, $zero, 0xc
/* 101F1C 802DEE2C 3C02802E */  lui   $v0, 0x802e
/* 101F20 802DEE30 24420080 */  addiu $v0, $v0, 0x80
.L802DEE34:
/* 101F24 802DEE34 AC400000 */  sw    $zero, ($v0)
/* 101F28 802DEE38 2484FFFF */  addiu $a0, $a0, -1
/* 101F2C 802DEE3C 0481FFFD */  bgez  $a0, .L802DEE34
/* 101F30 802DEE40 2442FFFC */   addiu $v0, $v0, -4
/* 101F34 802DEE44 3C11802E */  lui   $s1, 0x802e
/* 101F38 802DEE48 26310C10 */  addiu $s1, $s1, 0xc10
/* 101F3C 802DEE4C 0220282D */  daddu $a1, $s1, $zero
/* 101F40 802DEE50 3C10802E */  lui   $s0, 0x802e
/* 101F44 802DEE54 26100C60 */  addiu $s0, $s0, 0xc60
/* 101F48 802DEE58 8E040000 */  lw    $a0, ($s0)
/* 101F4C 802DEE5C 3C01802E */  lui   $at, 0x802e
/* 101F50 802DEE60 AC20004C */  sw    $zero, 0x4c($at)
/* 101F54 802DEE64 0C017D24 */  jal   nuPiReadRom
/* 101F58 802DEE68 2406000C */   addiu $a2, $zero, 0xc
/* 101F5C 802DEE6C 3C05802E */  lui   $a1, 0x802e
/* 101F60 802DEE70 24A50C20 */  addiu $a1, $a1, 0xc20
/* 101F64 802DEE74 8E020000 */  lw    $v0, ($s0)
/* 101F68 802DEE78 8E240000 */  lw    $a0, ($s1)
/* 101F6C 802DEE7C 24060038 */  addiu $a2, $zero, 0x38
/* 101F70 802DEE80 0C017D24 */  jal   nuPiReadRom
/* 101F74 802DEE84 00442021 */   addu  $a0, $v0, $a0
/* 101F78 802DEE88 8FBF001C */  lw    $ra, 0x1c($sp)
/* 101F7C 802DEE8C 8FB20018 */  lw    $s2, 0x18($sp)
/* 101F80 802DEE90 8FB10014 */  lw    $s1, 0x14($sp)
/* 101F84 802DEE94 8FB00010 */  lw    $s0, 0x10($sp)
/* 101F88 802DEE98 03E00008 */  jr    $ra
/* 101F8C 802DEE9C 27BD0020 */   addiu $sp, $sp, 0x20

