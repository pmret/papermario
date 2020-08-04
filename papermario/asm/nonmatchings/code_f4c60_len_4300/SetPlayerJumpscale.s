.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetPlayerJumpscale
/* 0F5A04 802D1054 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5A08 802D1058 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5A0C 802D105C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F5A10 802D1060 0C0B210B */  jal   get_float_variable
/* 0F5A14 802D1064 8C450000 */   lw    $a1, ($v0)
/* 0F5A18 802D1068 3C02802E */  lui   $v0, 0x802e
/* 0F5A1C 802D106C 8C429D20 */  lw    $v0, -0x62e0($v0)
/* 0F5A20 802D1070 E4400014 */  swc1  $f0, 0x14($v0)
/* 0F5A24 802D1074 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5A28 802D1078 24020002 */  addiu $v0, $zero, 2
/* 0F5A2C 802D107C 03E00008 */  jr    $ra
/* 0F5A30 802D1080 27BD0018 */   addiu $sp, $sp, 0x18

