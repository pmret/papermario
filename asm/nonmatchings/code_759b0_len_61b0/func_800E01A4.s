.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E01A4
/* 079654 800E01A4 3C048011 */  lui   $a0, 0x8011
/* 079658 800E01A8 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 07965C 800E01AC 90820015 */  lbu   $v0, 0x15($a0)
/* 079660 800E01B0 2442FFFF */  addiu $v0, $v0, -1
/* 079664 800E01B4 A0820015 */  sb    $v0, 0x15($a0)
/* 079668 800E01B8 00021600 */  sll   $v0, $v0, 0x18
/* 07966C 800E01BC 00022E03 */  sra   $a1, $v0, 0x18
/* 079670 800E01C0 14A00004 */  bnez  $a1, .L800E01D4
/* 079674 800E01C4 2403DFFF */   addiu $v1, $zero, -0x2001
/* 079678 800E01C8 8C820000 */  lw    $v0, ($a0)
/* 07967C 800E01CC 00431024 */  and   $v0, $v0, $v1
/* 079680 800E01D0 AC820000 */  sw    $v0, ($a0)
.L800E01D4:
/* 079684 800E01D4 03E00008 */  jr    $ra
/* 079688 800E01D8 00A0102D */   daddu $v0, $a1, $zero

