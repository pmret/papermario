.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004B62C
/* 026A2C 8004B62C 24080008 */  addiu $t0, $zero, 8
/* 026A30 8004B630 8C820000 */  lw    $v0, ($a0)
/* 026A34 8004B634 0000382D */  daddu $a3, $zero, $zero
/* 026A38 8004B638 8C4500A0 */  lw    $a1, 0xa0($v0)
/* 026A3C 8004B63C 0080302D */  daddu $a2, $a0, $zero
/* 026A40 8004B640 00A0182D */  daddu $v1, $a1, $zero
/* 026A44 8004B644 AC850008 */  sw    $a1, 8($a0)
.L8004B648:
/* 026A48 8004B648 94620010 */  lhu   $v0, 0x10($v1)
/* 026A4C 8004B64C 50400004 */  beql  $v0, $zero, .L8004B660
/* 026A50 8004B650 24C60004 */   addiu $a2, $a2, 4
/* 026A54 8004B654 00451021 */  addu  $v0, $v0, $a1
/* 026A58 8004B658 ACC2000C */  sw    $v0, 0xc($a2)
/* 026A5C 8004B65C 24C60004 */  addiu $a2, $a2, 4
.L8004B660:
/* 026A60 8004B660 24E70001 */  addiu $a3, $a3, 1
/* 026A64 8004B664 00E8102B */  sltu  $v0, $a3, $t0
/* 026A68 8004B668 1440FFF7 */  bnez  $v0, .L8004B648
/* 026A6C 8004B66C 24630002 */   addiu $v1, $v1, 2
/* 026A70 8004B670 90A3000E */  lbu   $v1, 0xe($a1)
/* 026A74 8004B674 24020001 */  addiu $v0, $zero, 1
/* 026A78 8004B678 14620005 */  bne   $v1, $v0, .L8004B690
/* 026A7C 8004B67C 00000000 */   nop   
/* 026A80 8004B680 94A20020 */  lhu   $v0, 0x20($a1)
/* 026A84 8004B684 10400002 */  beqz  $v0, .L8004B690
/* 026A88 8004B688 00451021 */   addu  $v0, $v0, $a1
/* 026A8C 8004B68C AC82002C */  sw    $v0, 0x2c($a0)
.L8004B690:
/* 026A90 8004B690 03E00008 */  jr    $ra
/* 026A94 8004B694 00000000 */   nop   

