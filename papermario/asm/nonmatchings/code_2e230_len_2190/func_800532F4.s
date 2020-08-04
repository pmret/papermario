.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800532F4
/* 02E6F4 800532F4 3C013F00 */  lui   $at, 0x3f00
/* 02E6F8 800532F8 44810000 */  mtc1  $at, $f0
/* 02E6FC 800532FC 3C028008 */  lui   $v0, 0x8008
/* 02E700 80053300 244281D0 */  addiu $v0, $v0, -0x7e30
/* 02E704 80053304 AC820000 */  sw    $v0, ($a0)
/* 02E708 80053308 240200BE */  addiu $v0, $zero, 0xbe
/* 02E70C 8005330C AC820004 */  sw    $v0, 4($a0)
/* 02E710 80053310 3C028008 */  lui   $v0, 0x8008
/* 02E714 80053314 24428190 */  addiu $v0, $v0, -0x7e70
/* 02E718 80053318 AC820018 */  sw    $v0, 0x18($a0)
/* 02E71C 8005331C 24020040 */  addiu $v0, $zero, 0x40
/* 02E720 80053320 A482001C */  sh    $v0, 0x1c($a0)
/* 02E724 80053324 240212C0 */  addiu $v0, $zero, 0x12c0
/* 02E728 80053328 A482001E */  sh    $v0, 0x1e($a0)
/* 02E72C 8005332C 3C028008 */  lui   $v0, 0x8008
/* 02E730 80053330 24428544 */  addiu $v0, $v0, -0x7abc
/* 02E734 80053334 AC800008 */  sw    $zero, 8($a0)
/* 02E738 80053338 AC80000C */  sw    $zero, 0xc($a0)
/* 02E73C 8005333C AC800010 */  sw    $zero, 0x10($a0)
/* 02E740 80053340 AC800014 */  sw    $zero, 0x14($a0)
/* 02E744 80053344 A0800024 */  sb    $zero, 0x24($a0)
/* 02E748 80053348 A0800025 */  sb    $zero, 0x25($a0)
/* 02E74C 8005334C AC82002C */  sw    $v0, 0x2c($a0)
/* 02E750 80053350 A0800026 */  sb    $zero, 0x26($a0)
/* 02E754 80053354 A0800027 */  sb    $zero, 0x27($a0)
/* 02E758 80053358 A0800028 */  sb    $zero, 0x28($a0)
/* 02E75C 8005335C A0800029 */  sb    $zero, 0x29($a0)
/* 02E760 80053360 A080002A */  sb    $zero, 0x2a($a0)
/* 02E764 80053364 A080002B */  sb    $zero, 0x2b($a0)
/* 02E768 80053368 03E00008 */  jr    $ra
/* 02E76C 8005336C E4800020 */   swc1  $f0, 0x20($a0)

