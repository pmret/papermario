.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80137E10
/* 0CE510 80137E10 28820002 */  slti  $v0, $a0, 2
/* 0CE514 80137E14 1040000B */  beqz  $v0, .L80137E44
/* 0CE518 80137E18 00000000 */   nop   
/* 0CE51C 80137E1C 04800009 */  bltz  $a0, .L80137E44
/* 0CE520 80137E20 00041040 */   sll   $v0, $a0, 1
/* 0CE524 80137E24 3C038016 */  lui   $v1, 0x8016
/* 0CE528 80137E28 2463C790 */  addiu $v1, $v1, -0x3870
/* 0CE52C 80137E2C 00441021 */  addu  $v0, $v0, $a0
/* 0CE530 80137E30 000210C0 */  sll   $v0, $v0, 3
/* 0CE534 80137E34 00431021 */  addu  $v0, $v0, $v1
/* 0CE538 80137E38 A0450000 */  sb    $a1, ($v0)
/* 0CE53C 80137E3C A0460001 */  sb    $a2, 1($v0)
/* 0CE540 80137E40 A0470002 */  sb    $a3, 2($v0)
.L80137E44:
/* 0CE544 80137E44 03E00008 */  jr    $ra
/* 0CE548 80137E48 00000000 */   nop   

