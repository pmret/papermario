.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8013EE48
/* 0D5548 8013EE48 3C014248 */  lui   $at, 0x4248
/* 0D554C 8013EE4C 44810000 */  mtc1  $at, $f0
/* 0D5550 8013EE50 3C0141F0 */  lui   $at, 0x41f0
/* 0D5554 8013EE54 44811000 */  mtc1  $at, $f2
/* 0D5558 8013EE58 AC80003C */  sw    $zero, 0x3c($a0)
/* 0D555C 8013EE5C E4800040 */  swc1  $f0, 0x40($a0)
/* 0D5560 8013EE60 03E00008 */  jr    $ra
/* 0D5564 8013EE64 E4820044 */   swc1  $f2, 0x44($a0)

