.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ClearPartnerMoveHistory
/* 0F3D20 802CF370 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3D24 802CF374 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3D28 802CF378 0080802D */  daddu $s0, $a0, $zero
/* 0F3D2C 802CF37C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F3D30 802CF380 8E02000C */  lw    $v0, 0xc($s0)
/* 0F3D34 802CF384 0C0B1EAF */  jal   get_variable
/* 0F3D38 802CF388 8C450000 */   lw    $a1, ($v0)
/* 0F3D3C 802CF38C 0200202D */  daddu $a0, $s0, $zero
/* 0F3D40 802CF390 0C0B36B0 */  jal   func_802CDAC0
/* 0F3D44 802CF394 0040282D */   daddu $a1, $v0, $zero
/* 0F3D48 802CF398 50400004 */  beql  $v0, $zero, .L802CF3AC
/* 0F3D4C 802CF39C 24020002 */   addiu $v0, $zero, 2
/* 0F3D50 802CF3A0 0C03BD17 */  jal   clear_partner_move_history
/* 0F3D54 802CF3A4 0040202D */   daddu $a0, $v0, $zero
/* 0F3D58 802CF3A8 24020002 */  addiu $v0, $zero, 2
.L802CF3AC:
/* 0F3D5C 802CF3AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F3D60 802CF3B0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3D64 802CF3B4 03E00008 */  jr    $ra
/* 0F3D68 802CF3B8 27BD0018 */   addiu $sp, $sp, 0x18

