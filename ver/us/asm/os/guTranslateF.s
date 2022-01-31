.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guTranslateF
/* 42D00 80067900 3C083F80 */  lui       $t0, 0x3f80
/* 42D04 80067904 AC880000 */  sw        $t0, ($a0)
/* 42D08 80067908 AC800004 */  sw        $zero, 4($a0)
/* 42D0C 8006790C AC800008 */  sw        $zero, 8($a0)
/* 42D10 80067910 AC80000C */  sw        $zero, 0xc($a0)
/* 42D14 80067914 AC800010 */  sw        $zero, 0x10($a0)
/* 42D18 80067918 AC880014 */  sw        $t0, 0x14($a0)
/* 42D1C 8006791C AC800018 */  sw        $zero, 0x18($a0)
/* 42D20 80067920 AC80001C */  sw        $zero, 0x1c($a0)
/* 42D24 80067924 AC800020 */  sw        $zero, 0x20($a0)
/* 42D28 80067928 AC800024 */  sw        $zero, 0x24($a0)
/* 42D2C 8006792C AC880028 */  sw        $t0, 0x28($a0)
/* 42D30 80067930 AC80002C */  sw        $zero, 0x2c($a0)
/* 42D34 80067934 AC850030 */  sw        $a1, 0x30($a0)
/* 42D38 80067938 AC860034 */  sw        $a2, 0x34($a0)
/* 42D3C 8006793C AC870038 */  sw        $a3, 0x38($a0)
/* 42D40 80067940 03E00008 */  jr        $ra
/* 42D44 80067944 AC88003C */   sw       $t0, 0x3c($a0)
/* 42D48 80067948 00000000 */  nop
/* 42D4C 8006794C 00000000 */  nop
/* 42D50 80067950 00000000 */  nop
/* 42D54 80067954 00000000 */  nop
/* 42D58 80067958 00000000 */  nop
/* 42D5C 8006795C 00000000 */  nop
