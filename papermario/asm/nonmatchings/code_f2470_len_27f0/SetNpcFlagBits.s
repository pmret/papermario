.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetNpcFlagBits
/* 0F3A10 802CF060 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F3A14 802CF064 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3A18 802CF068 0080882D */  daddu $s1, $a0, $zero
/* 0F3A1C 802CF06C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F3A20 802CF070 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F3A24 802CF074 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3A28 802CF078 8E30000C */  lw    $s0, 0xc($s1)
/* 0F3A2C 802CF07C 8E050000 */  lw    $a1, ($s0)
/* 0F3A30 802CF080 0C0B1EAF */  jal   get_variable
/* 0F3A34 802CF084 26100004 */   addiu $s0, $s0, 4
/* 0F3A38 802CF088 0220202D */  daddu $a0, $s1, $zero
/* 0F3A3C 802CF08C 8E050004 */  lw    $a1, 4($s0)
/* 0F3A40 802CF090 8E100000 */  lw    $s0, ($s0)
/* 0F3A44 802CF094 0C0B1EAF */  jal   get_variable
/* 0F3A48 802CF098 0040902D */   daddu $s2, $v0, $zero
/* 0F3A4C 802CF09C 0220202D */  daddu $a0, $s1, $zero
/* 0F3A50 802CF0A0 0240282D */  daddu $a1, $s2, $zero
/* 0F3A54 802CF0A4 0C0B36B0 */  jal   func_802CDAC0
/* 0F3A58 802CF0A8 0040882D */   daddu $s1, $v0, $zero
/* 0F3A5C 802CF0AC 0040202D */  daddu $a0, $v0, $zero
/* 0F3A60 802CF0B0 5080000A */  beql  $a0, $zero, .L802CF0DC
/* 0F3A64 802CF0B4 24020002 */   addiu $v0, $zero, 2
/* 0F3A68 802CF0B8 12200004 */  beqz  $s1, .L802CF0CC
/* 0F3A6C 802CF0BC 00101827 */   nor   $v1, $zero, $s0
/* 0F3A70 802CF0C0 8C820000 */  lw    $v0, ($a0)
/* 0F3A74 802CF0C4 080B3C35 */  j     .L802CF0D4
/* 0F3A78 802CF0C8 00501025 */   or    $v0, $v0, $s0

.L802CF0CC:
/* 0F3A7C 802CF0CC 8C820000 */  lw    $v0, ($a0)
/* 0F3A80 802CF0D0 00431024 */  and   $v0, $v0, $v1
.L802CF0D4:
/* 0F3A84 802CF0D4 AC820000 */  sw    $v0, ($a0)
/* 0F3A88 802CF0D8 24020002 */  addiu $v0, $zero, 2
.L802CF0DC:
/* 0F3A8C 802CF0DC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F3A90 802CF0E0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F3A94 802CF0E4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3A98 802CF0E8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3A9C 802CF0EC 03E00008 */  jr    $ra
/* 0F3AA0 802CF0F0 27BD0020 */   addiu $sp, $sp, 0x20

