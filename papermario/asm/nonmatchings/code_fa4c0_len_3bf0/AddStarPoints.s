.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddStarPoints
/* 0FBC64 802D72B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FBC68 802D72B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBC6C 802D72BC 0080802D */  daddu $s0, $a0, $zero
/* 0FBC70 802D72C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0FBC74 802D72C4 8E02000C */  lw    $v0, 0xc($s0)
/* 0FBC78 802D72C8 0C0B1EAF */  jal   get_variable
/* 0FBC7C 802D72CC 8C450000 */   lw    $a1, ($v0)
/* 0FBC80 802D72D0 0C03A84A */  jal   add_star_points
/* 0FBC84 802D72D4 0040202D */   daddu $a0, $v0, $zero
/* 0FBC88 802D72D8 AE020084 */  sw    $v0, 0x84($s0)
/* 0FBC8C 802D72DC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0FBC90 802D72E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBC94 802D72E4 24020002 */  addiu $v0, $zero, 2
/* 0FBC98 802D72E8 03E00008 */  jr    $ra
/* 0FBC9C 802D72EC 27BD0018 */   addiu $sp, $sp, 0x18

