.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802461C0
/* 139500 802461C0 25100089 */  addiu $s0, $t0, 0x89
/* 139504 802461C4 0C093BA5 */  jal   func_8024EE94
/* 139508 802461C8 0200282D */   daddu $a1, $s0, $zero
/* 13950C 802461CC 24040004 */  addiu $a0, $zero, 4
/* 139510 802461D0 0200282D */  daddu $a1, $s0, $zero
/* 139514 802461D4 0C093BA5 */  jal   func_8024EE94
/* 139518 802461D8 27C60023 */   addiu $a2, $fp, 0x23
/* 13951C 802461DC 00128400 */  sll   $s0, $s2, 0x10
/* 139520 802461E0 00108383 */  sra   $s0, $s0, 0xe
