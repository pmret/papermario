.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guScale
/* 42B00 80067700 3C014780 */  lui       $at, 0x4780
/* 42B04 80067704 44812000 */  mtc1      $at, $f4
/* 42B08 80067708 44853000 */  mtc1      $a1, $f6
#ifndef BBPLAYER
/* 42B0C 8006770C 00000000 */  nop
#endif
/* 42B10 80067710 46043202 */  mul.s     $f8, $f6, $f4
/* 42B14 80067714 4600428D */  trunc.w.s $f10, $f8
/* 42B18 80067718 44095000 */  mfc1      $t1, $f10
#ifndef BBPLAYER
/* 42B1C 8006771C 00000000 */  nop
#endif
/* 42B20 80067720 00095402 */  srl       $t2, $t1, 0x10
/* 42B24 80067724 000A4400 */  sll       $t0, $t2, 0x10
/* 42B28 80067728 AC880000 */  sw        $t0, ($a0)
/* 42B2C 8006772C 00095400 */  sll       $t2, $t1, 0x10
/* 42B30 80067730 AC8A0020 */  sw        $t2, 0x20($a0)
/* 42B34 80067734 44863000 */  mtc1      $a2, $f6
#ifndef BBPLAYER
/* 42B38 80067738 00000000 */  nop
#endif
/* 42B3C 8006773C 46043202 */  mul.s     $f8, $f6, $f4
/* 42B40 80067740 4600428D */  trunc.w.s $f10, $f8
/* 42B44 80067744 44095000 */  mfc1      $t1, $f10
#ifndef BBPLAYER
/* 42B48 80067748 00000000 */  nop
#endif
/* 42B4C 8006774C 00094402 */  srl       $t0, $t1, 0x10
/* 42B50 80067750 AC880008 */  sw        $t0, 8($a0)
/* 42B54 80067754 312AFFFF */  andi      $t2, $t1, 0xffff
/* 42B58 80067758 AC8A0028 */  sw        $t2, 0x28($a0)
/* 42B5C 8006775C 44873000 */  mtc1      $a3, $f6
#ifndef BBPLAYER
/* 42B60 80067760 00000000 */  nop
#endif
/* 42B64 80067764 46043202 */  mul.s     $f8, $f6, $f4
/* 42B68 80067768 4600428D */  trunc.w.s $f10, $f8
/* 42B6C 8006776C 44095000 */  mfc1      $t1, $f10
#ifndef BBPLAYER
/* 42B70 80067770 00000000 */  nop
#endif
/* 42B74 80067774 00095402 */  srl       $t2, $t1, 0x10
/* 42B78 80067778 000A4400 */  sll       $t0, $t2, 0x10
/* 42B7C 8006777C AC880014 */  sw        $t0, 0x14($a0)
/* 42B80 80067780 00095400 */  sll       $t2, $t1, 0x10
/* 42B84 80067784 AC8A0034 */  sw        $t2, 0x34($a0)
/* 42B88 80067788 24080001 */  addiu     $t0, $zero, 1
/* 42B8C 8006778C AC88001C */  sw        $t0, 0x1c($a0)
/* 42B90 80067790 AC800004 */  sw        $zero, 4($a0)
/* 42B94 80067794 AC80000C */  sw        $zero, 0xc($a0)
/* 42B98 80067798 AC800010 */  sw        $zero, 0x10($a0)
/* 42B9C 8006779C AC800018 */  sw        $zero, 0x18($a0)
/* 42BA0 800677A0 AC800024 */  sw        $zero, 0x24($a0)
/* 42BA4 800677A4 AC80002C */  sw        $zero, 0x2c($a0)
/* 42BA8 800677A8 AC800030 */  sw        $zero, 0x30($a0)
/* 42BAC 800677AC AC800038 */  sw        $zero, 0x38($a0)
/* 42BB0 800677B0 03E00008 */  jr        $ra
/* 42BB4 800677B4 AC80003C */   sw       $zero, 0x3c($a0)
