.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osContGetInitData
/* 03D11C 80061D1C 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 03D120 80061D20 00805821 */  addu  $t3, $a0, $zero
/* 03D124 80061D24 00A04821 */  addu  $t1, $a1, $zero
/* 03D128 80061D28 00005021 */  addu  $t2, $zero, $zero
/* 03D12C 80061D2C 3C02800A */  lui   $v0, 0x800a
/* 03D130 80061D30 9042A606 */  lbu   $v0, -0x59fa($v0)
/* 03D134 80061D34 3C08800B */  lui   $t0, 0x800b
/* 03D138 80061D38 25080ED0 */  addiu $t0, $t0, 0xed0
/* 03D13C 80061D3C 18400021 */  blez  $v0, .L80061DC4
/* 03D140 80061D40 00003821 */   addu  $a3, $zero, $zero
/* 03D144 80061D44 240C0001 */  addiu $t4, $zero, 1
/* 03D148 80061D48 24A60002 */  addiu $a2, $a1, 2
.L80061D4C:
/* 03D14C 80061D4C 89020000 */  lwl   $v0, ($t0)
/* 03D150 80061D50 99020003 */  lwr   $v0, 3($t0)
/* 03D154 80061D54 89030004 */  lwl   $v1, 4($t0)
/* 03D158 80061D58 99030007 */  lwr   $v1, 7($t0)
/* 03D15C 80061D5C ABA20000 */  swl   $v0, ($sp)
/* 03D160 80061D60 BBA20003 */  swr   $v0, 3($sp)
/* 03D164 80061D64 ABA30004 */  swl   $v1, 4($sp)
/* 03D168 80061D68 BBA30007 */  swr   $v1, 7($sp)
/* 03D16C 80061D6C 93A20002 */  lbu   $v0, 2($sp)
/* 03D170 80061D70 304200C0 */  andi  $v0, $v0, 0xc0
/* 03D174 80061D74 00021102 */  srl   $v0, $v0, 4
/* 03D178 80061D78 1440000A */  bnez  $v0, .L80061DA4
/* 03D17C 80061D7C A0C20001 */   sb    $v0, 1($a2)
/* 03D180 80061D80 93A20005 */  lbu   $v0, 5($sp)
/* 03D184 80061D84 93A30004 */  lbu   $v1, 4($sp)
/* 03D188 80061D88 00021200 */  sll   $v0, $v0, 8
/* 03D18C 80061D8C 00621825 */  or    $v1, $v1, $v0
/* 03D190 80061D90 A5230000 */  sh    $v1, ($t1)
/* 03D194 80061D94 93A30006 */  lbu   $v1, 6($sp)
/* 03D198 80061D98 00EC1004 */  sllv  $v0, $t4, $a3
/* 03D19C 80061D9C 01425025 */  or    $t2, $t2, $v0
/* 03D1A0 80061DA0 A0C30000 */  sb    $v1, ($a2)
.L80061DA4:
/* 03D1A4 80061DA4 24E70001 */  addiu $a3, $a3, 1
/* 03D1A8 80061DA8 25080008 */  addiu $t0, $t0, 8
/* 03D1AC 80061DAC 3C02800A */  lui   $v0, 0x800a
/* 03D1B0 80061DB0 9042A606 */  lbu   $v0, -0x59fa($v0)
/* 03D1B4 80061DB4 24C60004 */  addiu $a2, $a2, 4
/* 03D1B8 80061DB8 00E2102A */  slt   $v0, $a3, $v0
/* 03D1BC 80061DBC 1440FFE3 */  bnez  $v0, .L80061D4C
/* 03D1C0 80061DC0 25290004 */   addiu $t1, $t1, 4
.L80061DC4:
/* 03D1C4 80061DC4 A16A0000 */  sb    $t2, ($t3)
/* 03D1C8 80061DC8 03E00008 */  jr    $ra
/* 03D1CC 80061DCC 27BD0010 */   addiu $sp, $sp, 0x10

