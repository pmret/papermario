.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80067800
/* 42C00 80067800 3C014780 */  lui       $at, 0x4780
/* 42C04 80067804 44812000 */  mtc1      $at, $f4
/* 42C08 80067808 44853000 */  mtc1      $a1, $f6
/* 42C0C 8006780C 00000000 */  nop
/* 42C10 80067810 46043202 */  mul.s     $f8, $f6, $f4
/* 42C14 80067814 4600428D */  trunc.w.s $f10, $f8
/* 42C18 80067818 44095000 */  mfc1      $t1, $f10
/* 42C1C 8006781C 44863000 */  mtc1      $a2, $f6
/* 42C20 80067820 00000000 */  nop
/* 42C24 80067824 46043202 */  mul.s     $f8, $f6, $f4
/* 42C28 80067828 4600428D */  trunc.w.s $f10, $f8
/* 42C2C 8006782C 440B5000 */  mfc1      $t3, $f10
/* 42C30 80067830 00095402 */  srl       $t2, $t1, 0x10
/* 42C34 80067834 000A4400 */  sll       $t0, $t2, 0x10
/* 42C38 80067838 000B5402 */  srl       $t2, $t3, 0x10
/* 42C3C 8006783C 010A4025 */  or        $t0, $t0, $t2
/* 42C40 80067840 AC880018 */  sw        $t0, 0x18($a0)
/* 42C44 80067844 00094400 */  sll       $t0, $t1, 0x10
/* 42C48 80067848 000B5400 */  sll       $t2, $t3, 0x10
/* 42C4C 8006784C 000A5402 */  srl       $t2, $t2, 0x10
/* 42C50 80067850 010A4025 */  or        $t0, $t0, $t2
/* 42C54 80067854 AC880038 */  sw        $t0, 0x38($a0)
/* 42C58 80067858 44873000 */  mtc1      $a3, $f6
/* 42C5C 8006785C 00000000 */  nop
/* 42C60 80067860 46043202 */  mul.s     $f8, $f6, $f4
/* 42C64 80067864 4600428D */  trunc.w.s $f10, $f8
/* 42C68 80067868 44095000 */  mfc1      $t1, $f10
/* 42C6C 8006786C 00000000 */  nop
/* 42C70 80067870 00095402 */  srl       $t2, $t1, 0x10
/* 42C74 80067874 000A4400 */  sll       $t0, $t2, 0x10
/* 42C78 80067878 25080001 */  addiu     $t0, $t0, 1
/* 42C7C 8006787C AC88001C */  sw        $t0, 0x1c($a0)
/* 42C80 80067880 00095400 */  sll       $t2, $t1, 0x10
/* 42C84 80067884 AC8A003C */  sw        $t2, 0x3c($a0)
/* 42C88 80067888 AC800000 */  sw        $zero, ($a0)
/* 42C8C 8006788C AC800004 */  sw        $zero, 4($a0)
/* 42C90 80067890 AC800008 */  sw        $zero, 8($a0)
/* 42C94 80067894 AC80000C */  sw        $zero, 0xc($a0)
/* 42C98 80067898 AC800010 */  sw        $zero, 0x10($a0)
/* 42C9C 8006789C AC800014 */  sw        $zero, 0x14($a0)
/* 42CA0 800678A0 AC800020 */  sw        $zero, 0x20($a0)
/* 42CA4 800678A4 AC800024 */  sw        $zero, 0x24($a0)
/* 42CA8 800678A8 AC800028 */  sw        $zero, 0x28($a0)
/* 42CAC 800678AC AC80002C */  sw        $zero, 0x2c($a0)
/* 42CB0 800678B0 AC800030 */  sw        $zero, 0x30($a0)
/* 42CB4 800678B4 AC800034 */  sw        $zero, 0x34($a0)
/* 42CB8 800678B8 3C080001 */  lui       $t0, 1
/* 42CBC 800678BC 35080000 */  ori       $t0, $t0, 0
/* 42CC0 800678C0 AC880000 */  sw        $t0, ($a0)
/* 42CC4 800678C4 AC880014 */  sw        $t0, 0x14($a0)
/* 42CC8 800678C8 3C080000 */  lui       $t0, 0
/* 42CCC 800678CC 35080001 */  ori       $t0, $t0, 1
/* 42CD0 800678D0 03E00008 */  jr        $ra
/* 42CD4 800678D4 AC880008 */   sw       $t0, 8($a0)
/* 42CD8 800678D8 00000000 */  nop
/* 42CDC 800678DC 00000000 */  nop
