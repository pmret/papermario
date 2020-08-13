.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPlayerAnimation
/* 0F5A34 802D1084 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5A38 802D1088 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5A3C 802D108C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F5A40 802D1090 0C0B1EAF */  jal   get_variable
/* 0F5A44 802D1094 8C450000 */   lw    $a1, ($v0)
/* 0F5A48 802D1098 3C040008 */  lui   $a0, 8
/* 0F5A4C 802D109C 3C03802E */  lui   $v1, 0x802e
/* 0F5A50 802D10A0 8C639D20 */  lw    $v1, -0x62e0($v1)
/* 0F5A54 802D10A4 34840003 */  ori   $a0, $a0, 3
/* 0F5A58 802D10A8 AC620028 */  sw    $v0, 0x28($v1)
/* 0F5A5C 802D10AC 3C018011 */  lui   $at, 0x8011
/* 0F5A60 802D10B0 AC22F080 */  sw    $v0, -0xf80($at)
/* 0F5A64 802D10B4 14440004 */  bne   $v0, $a0, .L802D10C8
/* 0F5A68 802D10B8 0000202D */   daddu $a0, $zero, $zero
/* 0F5A6C 802D10BC 0080282D */  daddu $a1, $a0, $zero
/* 0F5A70 802D10C0 0C0B2D5B */  jal   exec_ShakeCam1
/* 0F5A74 802D10C4 24060002 */   addiu $a2, $zero, 2
.L802D10C8:
/* 0F5A78 802D10C8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5A7C 802D10CC 24020002 */  addiu $v0, $zero, 2
/* 0F5A80 802D10D0 03E00008 */  jr    $ra
/* 0F5A84 802D10D4 27BD0018 */   addiu $sp, $sp, 0x18

