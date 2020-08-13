.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel EnableNpcShadow
/* 0F3C18 802CF268 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F3C1C 802CF26C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3C20 802CF270 0080882D */  daddu $s1, $a0, $zero
/* 0F3C24 802CF274 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F3C28 802CF278 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3C2C 802CF27C 8E30000C */  lw    $s0, 0xc($s1)
/* 0F3C30 802CF280 8E050000 */  lw    $a1, ($s0)
/* 0F3C34 802CF284 0C0B1EAF */  jal   get_variable
/* 0F3C38 802CF288 26100004 */   addiu $s0, $s0, 4
/* 0F3C3C 802CF28C 0220202D */  daddu $a0, $s1, $zero
/* 0F3C40 802CF290 8E050000 */  lw    $a1, ($s0)
/* 0F3C44 802CF294 0C0B1EAF */  jal   get_variable
/* 0F3C48 802CF298 0040802D */   daddu $s0, $v0, $zero
/* 0F3C4C 802CF29C 0220202D */  daddu $a0, $s1, $zero
/* 0F3C50 802CF2A0 0200282D */  daddu $a1, $s0, $zero
/* 0F3C54 802CF2A4 0C0B36B0 */  jal   func_802CDAC0
/* 0F3C58 802CF2A8 0040802D */   daddu $s0, $v0, $zero
/* 0F3C5C 802CF2AC 5040000A */  beql  $v0, $zero, .L802CF2D8
/* 0F3C60 802CF2B0 24020002 */   addiu $v0, $zero, 2
/* 0F3C64 802CF2B4 12000005 */  beqz  $s0, .L802CF2CC
/* 0F3C68 802CF2B8 00000000 */   nop   
/* 0F3C6C 802CF2BC 0C00EAE8 */  jal   enable_npc_shadow
/* 0F3C70 802CF2C0 0040202D */   daddu $a0, $v0, $zero
/* 0F3C74 802CF2C4 080B3CB6 */  j     .L802CF2D8
/* 0F3C78 802CF2C8 24020002 */   addiu $v0, $zero, 2

.L802CF2CC:
/* 0F3C7C 802CF2CC 0C00EAFF */  jal   disable_npc_shadow
/* 0F3C80 802CF2D0 0040202D */   daddu $a0, $v0, $zero
/* 0F3C84 802CF2D4 24020002 */  addiu $v0, $zero, 2
.L802CF2D8:
/* 0F3C88 802CF2D8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F3C8C 802CF2DC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3C90 802CF2E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3C94 802CF2E4 03E00008 */  jr    $ra
/* 0F3C98 802CF2E8 27BD0020 */   addiu $sp, $sp, 0x20

