.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel IsMessageBoxDisplayed
/* 17FC64 80251384 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17FC68 80251388 AFB00010 */  sw    $s0, 0x10($sp)
/* 17FC6C 8025138C 0080802D */  daddu $s0, $a0, $zero
/* 17FC70 80251390 AFBF0018 */  sw    $ra, 0x18($sp)
/* 17FC74 80251394 AFB10014 */  sw    $s1, 0x14($sp)
/* 17FC78 80251398 8E02000C */  lw    $v0, 0xc($s0)
/* 17FC7C 8025139C 0C093EAD */  jal   is_popup_displayed
/* 17FC80 802513A0 8C510000 */   lw    $s1, ($v0)
/* 17FC84 802513A4 0200202D */  daddu $a0, $s0, $zero
/* 17FC88 802513A8 0040302D */  daddu $a2, $v0, $zero
/* 17FC8C 802513AC 0C0B2026 */  jal   set_variable
/* 17FC90 802513B0 0220282D */   daddu $a1, $s1, $zero
/* 17FC94 802513B4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 17FC98 802513B8 8FB10014 */  lw    $s1, 0x14($sp)
/* 17FC9C 802513BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 17FCA0 802513C0 24020002 */  addiu $v0, $zero, 2
/* 17FCA4 802513C4 03E00008 */  jr    $ra
/* 17FCA8 802513C8 27BD0020 */   addiu $sp, $sp, 0x20

