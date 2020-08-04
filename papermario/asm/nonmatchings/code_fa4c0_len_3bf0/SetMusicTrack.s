.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetMusicTrack
/* 0FA6FC 802D5D4C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0FA700 802D5D50 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FA704 802D5D54 0080882D */  daddu $s1, $a0, $zero
/* 0FA708 802D5D58 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0FA70C 802D5D5C AFB30024 */  sw    $s3, 0x24($sp)
/* 0FA710 802D5D60 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FA714 802D5D64 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FA718 802D5D68 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA71C 802D5D6C 8E050000 */  lw    $a1, ($s0)
/* 0FA720 802D5D70 0C0B1EAF */  jal   get_variable
/* 0FA724 802D5D74 26100004 */   addiu $s0, $s0, 4
/* 0FA728 802D5D78 8E050000 */  lw    $a1, ($s0)
/* 0FA72C 802D5D7C 26100004 */  addiu $s0, $s0, 4
/* 0FA730 802D5D80 0220202D */  daddu $a0, $s1, $zero
/* 0FA734 802D5D84 0C0B1EAF */  jal   get_variable
/* 0FA738 802D5D88 0040982D */   daddu $s3, $v0, $zero
/* 0FA73C 802D5D8C 8E050000 */  lw    $a1, ($s0)
/* 0FA740 802D5D90 26100004 */  addiu $s0, $s0, 4
/* 0FA744 802D5D94 0220202D */  daddu $a0, $s1, $zero
/* 0FA748 802D5D98 0C0B1EAF */  jal   get_variable
/* 0FA74C 802D5D9C 0040902D */   daddu $s2, $v0, $zero
/* 0FA750 802D5DA0 0220202D */  daddu $a0, $s1, $zero
/* 0FA754 802D5DA4 8E050000 */  lw    $a1, ($s0)
/* 0FA758 802D5DA8 0C0B1EAF */  jal   get_variable
/* 0FA75C 802D5DAC 0040802D */   daddu $s0, $v0, $zero
/* 0FA760 802D5DB0 0260202D */  daddu $a0, $s3, $zero
/* 0FA764 802D5DB4 0240282D */  daddu $a1, $s2, $zero
/* 0FA768 802D5DB8 00021400 */  sll   $v0, $v0, 0x10
/* 0FA76C 802D5DBC 00021403 */  sra   $v0, $v0, 0x10
/* 0FA770 802D5DC0 0200302D */  daddu $a2, $s0, $zero
/* 0FA774 802D5DC4 240701F4 */  addiu $a3, $zero, 0x1f4
/* 0FA778 802D5DC8 0C052A46 */  jal   set_music_track
/* 0FA77C 802D5DCC AFA20010 */   sw    $v0, 0x10($sp)
/* 0FA780 802D5DD0 0002102B */  sltu  $v0, $zero, $v0
/* 0FA784 802D5DD4 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0FA788 802D5DD8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FA78C 802D5DDC 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FA790 802D5DE0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FA794 802D5DE4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FA798 802D5DE8 00021040 */  sll   $v0, $v0, 1
/* 0FA79C 802D5DEC 03E00008 */  jr    $ra
/* 0FA7A0 802D5DF0 27BD0030 */   addiu $sp, $sp, 0x30

