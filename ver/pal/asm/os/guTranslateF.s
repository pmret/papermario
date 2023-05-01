.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.5 */

glabel guTranslateF
/* 43B80 80068780 3C083F80 */  lui       $t0, (0x3F800000 >> 16)
/* 43B84 80068784 AC880000 */  sw        $t0, 0x0($a0)
/* 43B88 80068788 AC800004 */  sw        $zero, 0x4($a0)
/* 43B8C 8006878C AC800008 */  sw        $zero, 0x8($a0)
/* 43B90 80068790 AC80000C */  sw        $zero, 0xC($a0)
/* 43B94 80068794 AC800010 */  sw        $zero, 0x10($a0)
/* 43B98 80068798 AC880014 */  sw        $t0, 0x14($a0)
/* 43B9C 8006879C AC800018 */  sw        $zero, 0x18($a0)
/* 43BA0 800687A0 AC80001C */  sw        $zero, 0x1C($a0)
/* 43BA4 800687A4 AC800020 */  sw        $zero, 0x20($a0)
/* 43BA8 800687A8 AC800024 */  sw        $zero, 0x24($a0)
/* 43BAC 800687AC AC880028 */  sw        $t0, 0x28($a0)
/* 43BB0 800687B0 AC80002C */  sw        $zero, 0x2C($a0)
/* 43BB4 800687B4 AC850030 */  sw        $a1, 0x30($a0)
/* 43BB8 800687B8 AC860034 */  sw        $a2, 0x34($a0)
/* 43BBC 800687BC AC870038 */  sw        $a3, 0x38($a0)
/* 43BC0 800687C0 03E00008 */  jr        $ra
/* 43BC4 800687C4 AC88003C */   sw       $t0, 0x3C($a0)
/* 43BC8 800687C8 00000000 */  nop
/* 43BCC 800687CC 00000000 */  nop
/* 43BD0 800687D0 00000000 */  nop
/* 43BD4 800687D4 00000000 */  nop
/* 43BD8 800687D8 00000000 */  nop
/* 43BDC 800687DC 00000000 */  nop