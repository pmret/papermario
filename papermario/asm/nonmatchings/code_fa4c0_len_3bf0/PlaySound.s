.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlaySound
/* 0FAB00 802D6150 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAB04 802D6154 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAB08 802D6158 8C82000C */  lw    $v0, 0xc($a0)
/* 0FAB0C 802D615C 0C0B1EAF */  jal   get_variable
/* 0FAB10 802D6160 8C450000 */   lw    $a1, ($v0)
/* 0FAB14 802D6164 0C05272D */  jal   play_sound
/* 0FAB18 802D6168 0040202D */   daddu $a0, $v0, $zero
/* 0FAB1C 802D616C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAB20 802D6170 24020002 */  addiu $v0, $zero, 2
/* 0FAB24 802D6174 03E00008 */  jr    $ra
/* 0FAB28 802D6178 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FAB2C 802D617C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FAB30 802D6180 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FAB34 802D6184 0080882D */  daddu $s1, $a0, $zero
/* 0FAB38 802D6188 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FAB3C 802D618C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FAB40 802D6190 8E30000C */  lw    $s0, 0xc($s1)
/* 0FAB44 802D6194 8E050000 */  lw    $a1, ($s0)
/* 0FAB48 802D6198 0C0B1EAF */  jal   get_variable
/* 0FAB4C 802D619C 26100004 */   addiu $s0, $s0, 4
/* 0FAB50 802D61A0 0220202D */  daddu $a0, $s1, $zero
/* 0FAB54 802D61A4 8E050000 */  lw    $a1, ($s0)
/* 0FAB58 802D61A8 0C0B1EAF */  jal   get_variable
/* 0FAB5C 802D61AC 0040802D */   daddu $s0, $v0, $zero
/* 0FAB60 802D61B0 0200202D */  daddu $a0, $s0, $zero
/* 0FAB64 802D61B4 304500FF */  andi  $a1, $v0, 0xff
/* 0FAB68 802D61B8 0000302D */  daddu $a2, $zero, $zero
/* 0FAB6C 802D61BC 0C0526AE */  jal   _play_sound
/* 0FAB70 802D61C0 00C0382D */   daddu $a3, $a2, $zero
/* 0FAB74 802D61C4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FAB78 802D61C8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FAB7C 802D61CC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FAB80 802D61D0 24020002 */  addiu $v0, $zero, 2
/* 0FAB84 802D61D4 03E00008 */  jr    $ra
/* 0FAB88 802D61D8 27BD0020 */   addiu $sp, $sp, 0x20

