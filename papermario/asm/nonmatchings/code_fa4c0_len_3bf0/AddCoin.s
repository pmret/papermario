.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddCoin
/* 0FBC28 802D7278 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FBC2C 802D727C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBC30 802D7280 0080802D */  daddu $s0, $a0, $zero
/* 0FBC34 802D7284 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0FBC38 802D7288 8E02000C */  lw    $v0, 0xc($s0)
/* 0FBC3C 802D728C 0C0B1EAF */  jal   get_variable
/* 0FBC40 802D7290 8C450000 */   lw    $a1, ($v0)
/* 0FBC44 802D7294 0C03A830 */  jal   add_coins
/* 0FBC48 802D7298 0040202D */   daddu $a0, $v0, $zero
/* 0FBC4C 802D729C AE020084 */  sw    $v0, 0x84($s0)
/* 0FBC50 802D72A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0FBC54 802D72A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBC58 802D72A8 24020002 */  addiu $v0, $zero, 2
/* 0FBC5C 802D72AC 03E00008 */  jr    $ra
/* 0FBC60 802D72B0 27BD0018 */   addiu $sp, $sp, 0x18

