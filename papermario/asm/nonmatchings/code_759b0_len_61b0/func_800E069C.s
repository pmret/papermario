.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E069C
/* 079B4C 800E069C 3C02800F */  lui   $v0, 0x800f
/* 079B50 800E06A0 8C427B30 */  lw    $v0, 0x7b30($v0)
/* 079B54 800E06A4 8C430004 */  lw    $v1, 4($v0)
/* 079B58 800E06A8 2404FFDF */  addiu $a0, $zero, -0x21
/* 079B5C 800E06AC 3C018011 */  lui   $at, 0x8011
/* 079B60 800E06B0 AC20C940 */  sw    $zero, -0x36c0($at)
/* 079B64 800E06B4 00641824 */  and   $v1, $v1, $a0
/* 079B68 800E06B8 03E00008 */  jr    $ra
/* 079B6C 800E06BC AC430004 */   sw    $v1, 4($v0)

