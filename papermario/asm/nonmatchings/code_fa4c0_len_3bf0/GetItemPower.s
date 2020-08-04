.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetItemPower
/* 0FBCDC 802D732C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FBCE0 802D7330 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FBCE4 802D7334 0080902D */  daddu $s2, $a0, $zero
/* 0FBCE8 802D7338 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FBCEC 802D733C AFB10014 */  sw    $s1, 0x14($sp)
/* 0FBCF0 802D7340 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBCF4 802D7344 8E50000C */  lw    $s0, 0xc($s2)
/* 0FBCF8 802D7348 8E050000 */  lw    $a1, ($s0)
/* 0FBCFC 802D734C 0C0B1EAF */  jal   get_variable
/* 0FBD00 802D7350 26100004 */   addiu $s0, $s0, 4
/* 0FBD04 802D7354 3C038008 */  lui   $v1, 0x8008
/* 0FBD08 802D7358 246378E0 */  addiu $v1, $v1, 0x78e0
/* 0FBD0C 802D735C 00028940 */  sll   $s1, $v0, 5
/* 0FBD10 802D7360 02238821 */  addu  $s1, $s1, $v1
/* 0FBD14 802D7364 8E050000 */  lw    $a1, ($s0)
/* 0FBD18 802D7368 8226001B */  lb    $a2, 0x1b($s1)
/* 0FBD1C 802D736C 8E100004 */  lw    $s0, 4($s0)
/* 0FBD20 802D7370 0C0B2026 */  jal   set_variable
/* 0FBD24 802D7374 0240202D */   daddu $a0, $s2, $zero
/* 0FBD28 802D7378 0240202D */  daddu $a0, $s2, $zero
/* 0FBD2C 802D737C 8226001C */  lb    $a2, 0x1c($s1)
/* 0FBD30 802D7380 0C0B2026 */  jal   set_variable
/* 0FBD34 802D7384 0200282D */   daddu $a1, $s0, $zero
/* 0FBD38 802D7388 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FBD3C 802D738C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FBD40 802D7390 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FBD44 802D7394 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBD48 802D7398 24020002 */  addiu $v0, $zero, 2
/* 0FBD4C 802D739C 03E00008 */  jr    $ra
/* 0FBD50 802D73A0 27BD0020 */   addiu $sp, $sp, 0x20

