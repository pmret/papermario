.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FadeOutMusic
/* 0FA690 802D5CE0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FA694 802D5CE4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FA698 802D5CE8 0080882D */  daddu $s1, $a0, $zero
/* 0FA69C 802D5CEC AFBF0020 */  sw    $ra, 0x20($sp)
/* 0FA6A0 802D5CF0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FA6A4 802D5CF4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA6A8 802D5CF8 8E050000 */  lw    $a1, ($s0)
/* 0FA6AC 802D5CFC 0C0B1EAF */  jal   get_variable
/* 0FA6B0 802D5D00 26100004 */   addiu $s0, $s0, 4
/* 0FA6B4 802D5D04 0220202D */  daddu $a0, $s1, $zero
/* 0FA6B8 802D5D08 8E050000 */  lw    $a1, ($s0)
/* 0FA6BC 802D5D0C 0C0B1EAF */  jal   get_variable
/* 0FA6C0 802D5D10 0040802D */   daddu $s0, $v0, $zero
/* 0FA6C4 802D5D14 0200202D */  daddu $a0, $s0, $zero
/* 0FA6C8 802D5D18 2405FFFF */  addiu $a1, $zero, -1
/* 0FA6CC 802D5D1C 24030008 */  addiu $v1, $zero, 8
/* 0FA6D0 802D5D20 0000302D */  daddu $a2, $zero, $zero
/* 0FA6D4 802D5D24 0040382D */  daddu $a3, $v0, $zero
/* 0FA6D8 802D5D28 0C052A46 */  jal   set_music_track
/* 0FA6DC 802D5D2C AFA30010 */   sw    $v1, 0x10($sp)
/* 0FA6E0 802D5D30 0002102B */  sltu  $v0, $zero, $v0
/* 0FA6E4 802D5D34 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0FA6E8 802D5D38 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FA6EC 802D5D3C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FA6F0 802D5D40 00021040 */  sll   $v0, $v0, 1
/* 0FA6F4 802D5D44 03E00008 */  jr    $ra
/* 0FA6F8 802D5D48 27BD0028 */   addiu $sp, $sp, 0x28

