.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetMessageString
/* 0F569C 802D0CEC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F56A0 802D0CF0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F56A4 802D0CF4 0080882D */  daddu $s1, $a0, $zero
/* 0F56A8 802D0CF8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F56AC 802D0CFC AFB00010 */  sw    $s0, 0x10($sp)
/* 0F56B0 802D0D00 8E30000C */  lw    $s0, 0xc($s1)
/* 0F56B4 802D0D04 8E050000 */  lw    $a1, ($s0)
/* 0F56B8 802D0D08 0C0B1EAF */  jal   get_variable
/* 0F56BC 802D0D0C 26100004 */   addiu $s0, $s0, 4
/* 0F56C0 802D0D10 0220202D */  daddu $a0, $s1, $zero
/* 0F56C4 802D0D14 8E050000 */  lw    $a1, ($s0)
/* 0F56C8 802D0D18 0C0B1EAF */  jal   get_variable
/* 0F56CC 802D0D1C 0040802D */   daddu $s0, $v0, $zero
/* 0F56D0 802D0D20 0200202D */  daddu $a0, $s0, $zero
/* 0F56D4 802D0D24 0C0496CF */  jal   set_message_string
/* 0F56D8 802D0D28 0040282D */   daddu $a1, $v0, $zero
/* 0F56DC 802D0D2C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F56E0 802D0D30 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F56E4 802D0D34 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F56E8 802D0D38 24020002 */  addiu $v0, $zero, 2
/* 0F56EC 802D0D3C 03E00008 */  jr    $ra
/* 0F56F0 802D0D40 27BD0020 */   addiu $sp, $sp, 0x20

