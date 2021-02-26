.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80069590
/* 44990 80069590 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 44994 80069594 3C03800E */  lui       $v1, %hi(D_800DA01C)
/* 44998 80069598 2463A01C */  addiu     $v1, $v1, %lo(D_800DA01C)
/* 4499C 8006959C 2466FFC4 */  addiu     $a2, $v1, -0x3c
/* 449A0 800695A0 00003821 */  addu      $a3, $zero, $zero
/* 449A4 800695A4 240200FE */  addiu     $v0, $zero, 0xfe
/* 449A8 800695A8 3C01800A */  lui       $at, %hi(D_8009A5FC)
/* 449AC 800695AC A022A5FC */  sb        $v0, %lo(D_8009A5FC)($at)
/* 449B0 800695B0 24020001 */  addiu     $v0, $zero, 1
/* 449B4 800695B4 AC620000 */  sw        $v0, ($v1)
/* 449B8 800695B8 24020001 */  addiu     $v0, $zero, 1
/* 449BC 800695BC A3A20000 */  sb        $v0, ($sp)
/* 449C0 800695C0 24020003 */  addiu     $v0, $zero, 3
/* 449C4 800695C4 A3A20001 */  sb        $v0, 1($sp)
/* 449C8 800695C8 240200FF */  addiu     $v0, $zero, 0xff
/* 449CC 800695CC A3A50002 */  sb        $a1, 2($sp)
/* 449D0 800695D0 A3A20003 */  sb        $v0, 3($sp)
/* 449D4 800695D4 A3A20004 */  sb        $v0, 4($sp)
/* 449D8 800695D8 18800006 */  blez      $a0, .L800695F4
/* 449DC 800695DC A3A20005 */   sb       $v0, 5($sp)
.L800695E0:
/* 449E0 800695E0 A0C00000 */  sb        $zero, ($a2)
/* 449E4 800695E4 24E70001 */  addiu     $a3, $a3, 1
/* 449E8 800695E8 00E4102A */  slt       $v0, $a3, $a0
/* 449EC 800695EC 1440FFFC */  bnez      $v0, .L800695E0
/* 449F0 800695F0 24C60001 */   addiu    $a2, $a2, 1
.L800695F4:
/* 449F4 800695F4 8BA20000 */  lwl       $v0, ($sp)
/* 449F8 800695F8 9BA20003 */  lwr       $v0, 3($sp)
/* 449FC 800695FC 83A30004 */  lb        $v1, 4($sp)
/* 44A00 80069600 83A40005 */  lb        $a0, 5($sp)
/* 44A04 80069604 A8C20000 */  swl       $v0, ($a2)
/* 44A08 80069608 B8C20003 */  swr       $v0, 3($a2)
/* 44A0C 8006960C A0C30004 */  sb        $v1, 4($a2)
/* 44A10 80069610 A0C40005 */  sb        $a0, 5($a2)
/* 44A14 80069614 240200FE */  addiu     $v0, $zero, 0xfe
/* 44A18 80069618 A0C20006 */  sb        $v0, 6($a2)
/* 44A1C 8006961C 03E00008 */  jr        $ra
/* 44A20 80069620 27BD0010 */   addiu    $sp, $sp, 0x10
