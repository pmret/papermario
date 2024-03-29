.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guTranslate
/* 42C20 80067820 3C014780 */  lui       $at, 0x4780
/* 42C24 80067824 44812000 */  mtc1      $at, $f4
/* 42C28 80067828 44853000 */  mtc1      $a1, $f6
#ifndef BBPLAYER
/* 42C2C 8006782C 00000000 */  nop
#endif
/* 42C30 80067830 46043202 */  mul.s     $f8, $f6, $f4
/* 42C34 80067834 4600428D */  trunc.w.s $f10, $f8
/* 42C38 80067838 44095000 */  mfc1      $t1, $f10
/* 42C3C 8006783C 44863000 */  mtc1      $a2, $f6
#ifndef BBPLAYER
/* 42C40 80067840 00000000 */  nop
#endif
/* 42C44 80067844 46043202 */  mul.s     $f8, $f6, $f4
/* 42C48 80067848 4600428D */  trunc.w.s $f10, $f8
/* 42C4C 8006784C 440B5000 */  mfc1      $t3, $f10
/* 42C50 80067850 00095402 */  srl       $t2, $t1, 0x10
/* 42C54 80067854 000A4400 */  sll       $t0, $t2, 0x10
/* 42C58 80067858 000B5402 */  srl       $t2, $t3, 0x10
/* 42C5C 8006785C 010A4025 */  or        $t0, $t0, $t2
/* 42C60 80067860 AC880018 */  sw        $t0, 0x18($a0)
/* 42C64 80067864 00094400 */  sll       $t0, $t1, 0x10
/* 42C68 80067868 000B5400 */  sll       $t2, $t3, 0x10
/* 42C6C 8006786C 000A5402 */  srl       $t2, $t2, 0x10
/* 42C70 80067870 010A4025 */  or        $t0, $t0, $t2
/* 42C74 80067874 AC880038 */  sw        $t0, 0x38($a0)
/* 42C78 80067878 44873000 */  mtc1      $a3, $f6
#ifndef BBPLAYER
/* 42C7C 8006787C 00000000 */  nop
#endif
/* 42C80 80067880 46043202 */  mul.s     $f8, $f6, $f4
/* 42C84 80067884 4600428D */  trunc.w.s $f10, $f8
/* 42C88 80067888 44095000 */  mfc1      $t1, $f10
#ifndef BBPLAYER
/* 42C8C 8006788C 00000000 */  nop
#endif
/* 42C90 80067890 00095402 */  srl       $t2, $t1, 0x10
/* 42C94 80067894 000A4400 */  sll       $t0, $t2, 0x10
/* 42C98 80067898 25080001 */  addiu     $t0, $t0, 1
/* 42C9C 8006789C AC88001C */  sw        $t0, 0x1c($a0)
/* 42CA0 800678A0 00095400 */  sll       $t2, $t1, 0x10
/* 42CA4 800678A4 AC8A003C */  sw        $t2, 0x3c($a0)
/* 42CA8 800678A8 AC800000 */  sw        $zero, ($a0)
/* 42CAC 800678AC AC800004 */  sw        $zero, 4($a0)
/* 42CB0 800678B0 AC800008 */  sw        $zero, 8($a0)
/* 42CB4 800678B4 AC80000C */  sw        $zero, 0xc($a0)
/* 42CB8 800678B8 AC800010 */  sw        $zero, 0x10($a0)
/* 42CBC 800678BC AC800014 */  sw        $zero, 0x14($a0)
/* 42CC0 800678C0 AC800020 */  sw        $zero, 0x20($a0)
/* 42CC4 800678C4 AC800024 */  sw        $zero, 0x24($a0)
/* 42CC8 800678C8 AC800028 */  sw        $zero, 0x28($a0)
/* 42CCC 800678CC AC80002C */  sw        $zero, 0x2c($a0)
/* 42CD0 800678D0 AC800030 */  sw        $zero, 0x30($a0)
/* 42CD4 800678D4 AC800034 */  sw        $zero, 0x34($a0)
/* 42CD8 800678D8 3C080001 */  lui       $t0, 1
/* 42CDC 800678DC 35080000 */  ori       $t0, $t0, 0
/* 42CE0 800678E0 AC880000 */  sw        $t0, ($a0)
/* 42CE4 800678E4 AC880014 */  sw        $t0, 0x14($a0)
/* 42CE8 800678E8 3C080000 */  lui       $t0, 0
/* 42CEC 800678EC 35080001 */  ori       $t0, $t0, 1
/* 42CF0 800678F0 03E00008 */  jr        $ra
/* 42CF4 800678F4 AC880008 */   sw       $t0, 8($a0)
/* 42CF8 800678F8 00000000 */  nop
/* 42CFC 800678FC 00000000 */  nop
#ifdef BBPLAYER // spontaneous padding??
/* 41290 80065E90 00000000 */  nop
/* 41294 80065E94 00000000 */  nop
/* 41298 80065E98 00000000 */  nop
/* 4129C 80065E9C 00000000 */  nop
#endif
