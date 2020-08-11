.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel StopSound
/* 0FAC68 802D62B8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAC6C 802D62BC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAC70 802D62C0 8C82000C */  lw    $v0, 0xc($a0)
/* 0FAC74 802D62C4 0C0B1EAF */  jal   get_variable
/* 0FAC78 802D62C8 8C450000 */   lw    $a1, ($v0)
/* 0FAC7C 802D62CC 0C05271B */  jal   stop_sound
/* 0FAC80 802D62D0 0040202D */   daddu $a0, $v0, $zero
/* 0FAC84 802D62D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAC88 802D62D8 24020002 */  addiu $v0, $zero, 2
/* 0FAC8C 802D62DC 03E00008 */  jr    $ra
/* 0FAC90 802D62E0 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D62E4
/* 0FAC94 802D62E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAC98 802D62E8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAC9C 802D62EC 8C82000C */  lw    $v0, 0xc($a0)
/* 0FACA0 802D62F0 0C0B1EAF */  jal   get_variable
/* 0FACA4 802D62F4 8C450000 */   lw    $a1, ($v0)
/* 0FACA8 802D62F8 0040202D */  daddu $a0, $v0, $zero
/* 0FACAC 802D62FC 0C05269B */  jal   func_80149A6C
/* 0FACB0 802D6300 24050001 */   addiu $a1, $zero, 1
/* 0FACB4 802D6304 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FACB8 802D6308 24020002 */  addiu $v0, $zero, 2
/* 0FACBC 802D630C 03E00008 */  jr    $ra
/* 0FACC0 802D6310 27BD0018 */   addiu $sp, $sp, 0x18

