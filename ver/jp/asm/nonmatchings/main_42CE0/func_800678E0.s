.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800678E0
/* 42CE0 800678E0 3C083F80 */  lui       $t0, 0x3f80
/* 42CE4 800678E4 AC880000 */  sw        $t0, ($a0)
/* 42CE8 800678E8 AC800004 */  sw        $zero, 4($a0)
/* 42CEC 800678EC AC800008 */  sw        $zero, 8($a0)
/* 42CF0 800678F0 AC80000C */  sw        $zero, 0xc($a0)
/* 42CF4 800678F4 AC800010 */  sw        $zero, 0x10($a0)
/* 42CF8 800678F8 AC880014 */  sw        $t0, 0x14($a0)
/* 42CFC 800678FC AC800018 */  sw        $zero, 0x18($a0)
/* 42D00 80067900 AC80001C */  sw        $zero, 0x1c($a0)
/* 42D04 80067904 AC800020 */  sw        $zero, 0x20($a0)
/* 42D08 80067908 AC800024 */  sw        $zero, 0x24($a0)
/* 42D0C 8006790C AC880028 */  sw        $t0, 0x28($a0)
/* 42D10 80067910 AC80002C */  sw        $zero, 0x2c($a0)
/* 42D14 80067914 AC850030 */  sw        $a1, 0x30($a0)
/* 42D18 80067918 AC860034 */  sw        $a2, 0x34($a0)
/* 42D1C 8006791C AC870038 */  sw        $a3, 0x38($a0)
/* 42D20 80067920 03E00008 */  jr        $ra
/* 42D24 80067924 AC88003C */   sw       $t0, 0x3c($a0)
/* 42D28 80067928 00000000 */  nop
/* 42D2C 8006792C 00000000 */  nop
/* 42D30 80067930 00000000 */  nop
/* 42D34 80067934 00000000 */  nop
/* 42D38 80067938 00000000 */  nop
/* 42D3C 8006793C 00000000 */  nop
