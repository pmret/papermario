.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guMtxIdent
/* 42840 80067440 20080001 */  addi      $t0, $zero, 1
/* 42844 80067444 00084C00 */  sll       $t1, $t0, 0x10
/* 42848 80067448 AC890000 */  sw        $t1, ($a0)
/* 4284C 8006744C AC800004 */  sw        $zero, 4($a0)
/* 42850 80067450 AC880008 */  sw        $t0, 8($a0)
/* 42854 80067454 AC80000C */  sw        $zero, 0xc($a0)
/* 42858 80067458 AC800010 */  sw        $zero, 0x10($a0)
/* 4285C 8006745C AC890014 */  sw        $t1, 0x14($a0)
/* 42860 80067460 AC800018 */  sw        $zero, 0x18($a0)
/* 42864 80067464 AC88001C */  sw        $t0, 0x1c($a0)
/* 42868 80067468 AC800020 */  sw        $zero, 0x20($a0)
/* 4286C 8006746C AC800024 */  sw        $zero, 0x24($a0)
/* 42870 80067470 AC800028 */  sw        $zero, 0x28($a0)
/* 42874 80067474 AC80002C */  sw        $zero, 0x2c($a0)
/* 42878 80067478 AC800030 */  sw        $zero, 0x30($a0)
/* 4287C 8006747C AC800034 */  sw        $zero, 0x34($a0)
/* 42880 80067480 AC800038 */  sw        $zero, 0x38($a0)
/* 42884 80067484 03E00008 */  jr        $ra
/* 42888 80067488 AC80003C */   sw       $zero, 0x3c($a0)
/* 4288C 8006748C 00000000 */  nop
/* 42890 80067490 00000000 */  nop
/* 42894 80067494 00000000 */  nop
/* 42898 80067498 00000000 */  nop
/* 4289C 8006749C 00000000 */  nop
