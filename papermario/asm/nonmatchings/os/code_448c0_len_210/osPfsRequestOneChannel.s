.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osPfsRequestOneChannel
/* 0449B0 800695B0 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0449B4 800695B4 3C03800E */  lui   $v1, 0x800e
/* 0449B8 800695B8 2463A03C */  addiu $v1, $v1, -0x5fc4
/* 0449BC 800695BC 2466FFC4 */  addiu $a2, $v1, -0x3c
/* 0449C0 800695C0 00003821 */  addu  $a3, $zero, $zero
/* 0449C4 800695C4 240200FE */  addiu $v0, $zero, 0xfe
/* 0449C8 800695C8 3C01800A */  lui   $at, 0x800a
/* 0449CC 800695CC A022A61C */  sb    $v0, -0x59e4($at)
/* 0449D0 800695D0 24020001 */  addiu $v0, $zero, 1
/* 0449D4 800695D4 AC620000 */  sw    $v0, ($v1)
/* 0449D8 800695D8 24020001 */  addiu $v0, $zero, 1
/* 0449DC 800695DC A3A20000 */  sb    $v0, ($sp)
/* 0449E0 800695E0 24020003 */  addiu $v0, $zero, 3
/* 0449E4 800695E4 A3A20001 */  sb    $v0, 1($sp)
/* 0449E8 800695E8 240200FF */  addiu $v0, $zero, 0xff
/* 0449EC 800695EC A3A50002 */  sb    $a1, 2($sp)
/* 0449F0 800695F0 A3A20003 */  sb    $v0, 3($sp)
/* 0449F4 800695F4 A3A20004 */  sb    $v0, 4($sp)
/* 0449F8 800695F8 18800006 */  blez  $a0, .L80069614
/* 0449FC 800695FC A3A20005 */   sb    $v0, 5($sp)
.L80069600:
/* 044A00 80069600 A0C00000 */  sb    $zero, ($a2)
/* 044A04 80069604 24E70001 */  addiu $a3, $a3, 1
/* 044A08 80069608 00E4102A */  slt   $v0, $a3, $a0
/* 044A0C 8006960C 1440FFFC */  bnez  $v0, .L80069600
/* 044A10 80069610 24C60001 */   addiu $a2, $a2, 1
.L80069614:
/* 044A14 80069614 8BA20000 */  lwl   $v0, ($sp)
/* 044A18 80069618 9BA20003 */  lwr   $v0, 3($sp)
/* 044A1C 8006961C 83A30004 */  lb    $v1, 4($sp)
/* 044A20 80069620 83A40005 */  lb    $a0, 5($sp)
/* 044A24 80069624 A8C20000 */  swl   $v0, ($a2)
/* 044A28 80069628 B8C20003 */  swr   $v0, 3($a2)
/* 044A2C 8006962C A0C30004 */  sb    $v1, 4($a2)
/* 044A30 80069630 A0C40005 */  sb    $a0, 5($a2)
/* 044A34 80069634 240200FE */  addiu $v0, $zero, 0xfe
/* 044A38 80069638 A0C20006 */  sb    $v0, 6($a2)
/* 044A3C 8006963C 03E00008 */  jr    $ra
/* 044A40 80069640 27BD0010 */   addiu $sp, $sp, 0x10

