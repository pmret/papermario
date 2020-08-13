.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E0514
/* 0799C4 800E0514 3C02800F */  lui   $v0, 0x800f
/* 0799C8 800E0518 8C427B30 */  lw    $v0, 0x7b30($v0)
/* 0799CC 800E051C 8C430004 */  lw    $v1, 4($v0)
/* 0799D0 800E0520 2404FFBF */  addiu $a0, $zero, -0x41
/* 0799D4 800E0524 3C018011 */  lui   $at, 0x8011
/* 0799D8 800E0528 AC20C920 */  sw    $zero, -0x36e0($at)
/* 0799DC 800E052C 00641824 */  and   $v1, $v1, $a0
/* 0799E0 800E0530 03E00008 */  jr    $ra
/* 0799E4 800E0534 AC430004 */   sw    $v1, 4($v0)

