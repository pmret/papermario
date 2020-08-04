.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80137D88
/* 0CE488 80137D88 308400FF */  andi  $a0, $a0, 0xff
/* 0CE48C 80137D8C 3C018015 */  lui   $at, 0x8015
/* 0CE490 80137D90 AC246900 */  sw    $a0, 0x6900($at)
/* 0CE494 80137D94 3C018015 */  lui   $at, 0x8015
/* 0CE498 80137D98 AC256904 */  sw    $a1, 0x6904($at)
/* 0CE49C 80137D9C 03E00008 */  jr    $ra
/* 0CE4A0 80137DA0 00000000 */   nop   

