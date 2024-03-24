.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guScaleF
/* 42BC0 800677C0 AC850000 */  sw        $a1, ($a0)
/* 42BC4 800677C4 AC800004 */  sw        $zero, 4($a0)
/* 42BC8 800677C8 AC800008 */  sw        $zero, 8($a0)
/* 42BCC 800677CC AC80000C */  sw        $zero, 0xc($a0)
/* 42BD0 800677D0 AC800010 */  sw        $zero, 0x10($a0)
/* 42BD4 800677D4 AC860014 */  sw        $a2, 0x14($a0)
/* 42BD8 800677D8 AC800018 */  sw        $zero, 0x18($a0)
/* 42BDC 800677DC AC80001C */  sw        $zero, 0x1c($a0)
/* 42BE0 800677E0 AC800020 */  sw        $zero, 0x20($a0)
/* 42BE4 800677E4 AC800024 */  sw        $zero, 0x24($a0)
/* 42BE8 800677E8 AC870028 */  sw        $a3, 0x28($a0)
/* 42BEC 800677EC AC80002C */  sw        $zero, 0x2c($a0)
/* 42BF0 800677F0 3C083F80 */  lui       $t0, 0x3f80
/* 42BF4 800677F4 AC800030 */  sw        $zero, 0x30($a0)
/* 42BF8 800677F8 AC800034 */  sw        $zero, 0x34($a0)
/* 42BFC 800677FC AC800038 */  sw        $zero, 0x38($a0)
/* 42C00 80067800 03E00008 */  jr        $ra
/* 42C04 80067804 AC88003C */   sw       $t0, 0x3c($a0)
/* 42C08 80067808 00000000 */  nop
/* 42C0C 8006780C 00000000 */  nop
/* 42C10 80067810 00000000 */  nop
/* 42C14 80067814 00000000 */  nop
/* 42C18 80067818 00000000 */  nop
/* 42C1C 8006781C 00000000 */  nop
