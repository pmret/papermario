.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80034940
/* 00FD40 80034940 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00FD44 80034944 AFBF0010 */  sw    $ra, 0x10($sp)
/* 00FD48 80034948 3C01800A */  lui   $at, 0x800a
/* 00FD4C 8003494C A0200921 */  sb    $zero, 0x921($at)
/* 00FD50 80034950 3C01800A */  lui   $at, 0x800a
/* 00FD54 80034954 A4200922 */  sh    $zero, 0x922($at)
/* 00FD58 80034958 0C03805E */  jal   func_800E0178
/* 00FD5C 8003495C 00000000 */   nop   
/* 00FD60 80034960 0C009C22 */  jal   func_80027088
/* 00FD64 80034964 24040003 */   addiu $a0, $zero, 3
/* 00FD68 80034968 0C051FB1 */  jal   func_80147EC4
/* 00FD6C 8003496C 24040002 */   addiu $a0, $zero, 2
/* 00FD70 80034970 8FBF0010 */  lw    $ra, 0x10($sp)
/* 00FD74 80034974 03E00008 */  jr    $ra
/* 00FD78 80034978 27BD0018 */   addiu $sp, $sp, 0x18

