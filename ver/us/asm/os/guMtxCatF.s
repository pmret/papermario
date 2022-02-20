.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guMtxCatF
/* 42A00 80067600 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 42A04 80067604 24820040 */  addiu     $v0, $a0, 0x40
/* 42A08 80067608 24A30010 */  addiu     $v1, $a1, 0x10
/* 42A0C 8006760C 03A05021 */  addu      $t2, $sp, $zero
.L80067610:
/* 42A10 80067610 00A03821 */  addu      $a3, $a1, $zero
.L80067614:
/* 42A14 80067614 C4840000 */  lwc1      $f4, ($a0)
/* 42A18 80067618 C4E60000 */  lwc1      $f6, ($a3)
/* 42A1C 8006761C 46062202 */  mul.s     $f8, $f4, $f6
/* 42A20 80067620 C48A0004 */  lwc1      $f10, 4($a0)
/* 42A24 80067624 C4F00010 */  lwc1      $f16, 0x10($a3)
/* 42A28 80067628 46105482 */  mul.s     $f18, $f10, $f16
/* 42A2C 8006762C 46124200 */  add.s     $f8, $f8, $f18
/* 42A30 80067630 C4840008 */  lwc1      $f4, 8($a0)
/* 42A34 80067634 C4E60020 */  lwc1      $f6, 0x20($a3)
/* 42A38 80067638 46062482 */  mul.s     $f18, $f4, $f6
/* 42A3C 8006763C 46124200 */  add.s     $f8, $f8, $f18
/* 42A40 80067640 C48A000C */  lwc1      $f10, 0xc($a0)
/* 42A44 80067644 C4F00030 */  lwc1      $f16, 0x30($a3)
/* 42A48 80067648 46105482 */  mul.s     $f18, $f10, $f16
/* 42A4C 8006764C 46124200 */  add.s     $f8, $f8, $f18
/* 42A50 80067650 E5480000 */  swc1      $f8, ($t2)
/* 42A54 80067654 24E70004 */  addiu     $a3, $a3, 4
/* 42A58 80067658 14E3FFEE */  bne       $a3, $v1, .L80067614
/* 42A5C 8006765C 254A0004 */   addiu    $t2, $t2, 4
/* 42A60 80067660 24840010 */  addiu     $a0, $a0, 0x10
/* 42A64 80067664 1482FFEA */  bne       $a0, $v0, .L80067610
/* 42A68 80067668 00000000 */   nop
/* 42A6C 8006766C E4C8003C */  swc1      $f8, 0x3c($a2)
/* 42A70 80067670 8FA80000 */  lw        $t0, ($sp)
/* 42A74 80067674 8FA90004 */  lw        $t1, 4($sp)
/* 42A78 80067678 8FAA0008 */  lw        $t2, 8($sp)
/* 42A7C 8006767C 8FAB000C */  lw        $t3, 0xc($sp)
/* 42A80 80067680 8FAC0010 */  lw        $t4, 0x10($sp)
/* 42A84 80067684 8FAD0014 */  lw        $t5, 0x14($sp)
/* 42A88 80067688 8FAE0018 */  lw        $t6, 0x18($sp)
/* 42A8C 8006768C 8FAF001C */  lw        $t7, 0x1c($sp)
/* 42A90 80067690 8FB80020 */  lw        $t8, 0x20($sp)
/* 42A94 80067694 8FB90024 */  lw        $t9, 0x24($sp)
/* 42A98 80067698 8FA20028 */  lw        $v0, 0x28($sp)
/* 42A9C 8006769C 8FA3002C */  lw        $v1, 0x2c($sp)
/* 42AA0 800676A0 8FA40030 */  lw        $a0, 0x30($sp)
/* 42AA4 800676A4 8FA50034 */  lw        $a1, 0x34($sp)
/* 42AA8 800676A8 8FA70038 */  lw        $a3, 0x38($sp)
/* 42AAC 800676AC ACC80000 */  sw        $t0, ($a2)
/* 42AB0 800676B0 ACC90004 */  sw        $t1, 4($a2)
/* 42AB4 800676B4 ACCA0008 */  sw        $t2, 8($a2)
/* 42AB8 800676B8 ACCB000C */  sw        $t3, 0xc($a2)
/* 42ABC 800676BC ACCC0010 */  sw        $t4, 0x10($a2)
/* 42AC0 800676C0 ACCD0014 */  sw        $t5, 0x14($a2)
/* 42AC4 800676C4 ACCE0018 */  sw        $t6, 0x18($a2)
/* 42AC8 800676C8 ACCF001C */  sw        $t7, 0x1c($a2)
/* 42ACC 800676CC ACD80020 */  sw        $t8, 0x20($a2)
/* 42AD0 800676D0 ACD90024 */  sw        $t9, 0x24($a2)
/* 42AD4 800676D4 ACC20028 */  sw        $v0, 0x28($a2)
/* 42AD8 800676D8 ACC3002C */  sw        $v1, 0x2c($a2)
/* 42ADC 800676DC ACC40030 */  sw        $a0, 0x30($a2)
/* 42AE0 800676E0 ACC50034 */  sw        $a1, 0x34($a2)
/* 42AE4 800676E4 ACC70038 */  sw        $a3, 0x38($a2)
/* 42AE8 800676E8 03E00008 */  jr        $ra
/* 42AEC 800676EC 27BD0040 */   addiu    $sp, $sp, 0x40
/* 42AF0 800676F0 00000000 */  nop
/* 42AF4 800676F4 00000000 */  nop
/* 42AF8 800676F8 00000000 */  nop
/* 42AFC 800676FC 00000000 */  nop
