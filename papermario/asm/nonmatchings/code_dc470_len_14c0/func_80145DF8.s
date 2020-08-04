.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80145DF8
/* 0DC4F8 80145DF8 3C028007 */  lui   $v0, 0x8007
/* 0DC4FC 80145DFC 8C42419C */  lw    $v0, 0x419c($v0)
/* 0DC500 80145E00 94430148 */  lhu   $v1, 0x148($v0)
/* 0DC504 80145E04 240400B4 */  addiu $a0, $zero, 0xb4
/* 0DC508 80145E08 3C018016 */  lui   $at, 0x8016
/* 0DC50C 80145E0C AC2095A0 */  sw    $zero, -0x6a60($at)
/* 0DC510 80145E10 3C018015 */  lui   $at, 0x8015
/* 0DC514 80145E14 A020F12F */  sb    $zero, -0xed1($at)
/* 0DC518 80145E18 A444015C */  sh    $a0, 0x15c($v0)
/* 0DC51C 80145E1C 306300F0 */  andi  $v1, $v1, 0xf0
/* 0DC520 80145E20 03E00008 */  jr    $ra
/* 0DC524 80145E24 A4430148 */   sh    $v1, 0x148($v0)

