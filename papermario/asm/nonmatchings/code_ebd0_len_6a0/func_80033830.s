.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80033830
/* 00EC30 80033830 3C058007 */  lui   $a1, 0x8007
/* 00EC34 80033834 8CA5419C */  lw    $a1, 0x419c($a1)
/* 00EC38 80033838 240600FF */  addiu $a2, $zero, 0xff
/* 00EC3C 8003383C 84A200B6 */  lh    $v0, 0xb6($a1)
/* 00EC40 80033840 94A300B6 */  lhu   $v1, 0xb6($a1)
/* 00EC44 80033844 14460003 */  bne   $v0, $a2, .L80033854
/* 00EC48 80033848 00641021 */   addu  $v0, $v1, $a0
/* 00EC4C 8003384C 03E00008 */  jr    $ra
/* 00EC50 80033850 24020001 */   addiu $v0, $zero, 1

.L80033854:
/* 00EC54 80033854 A4A200B6 */  sh    $v0, 0xb6($a1)
/* 00EC58 80033858 00021400 */  sll   $v0, $v0, 0x10
/* 00EC5C 8003385C 00021403 */  sra   $v0, $v0, 0x10
/* 00EC60 80033860 28420100 */  slti  $v0, $v0, 0x100
/* 00EC64 80033864 50400001 */  beql  $v0, $zero, .L8003386C
/* 00EC68 80033868 A4A600B6 */   sh    $a2, 0xb6($a1)
.L8003386C:
/* 00EC6C 8003386C 03E00008 */  jr    $ra
/* 00EC70 80033870 0000102D */   daddu $v0, $zero, $zero

