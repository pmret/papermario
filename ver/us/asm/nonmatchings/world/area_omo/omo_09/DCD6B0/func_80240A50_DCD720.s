.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8024A638_DD7308
.double 0.6

.section .text

glabel func_80240A50_DCD720
/* DCD720 80240A50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCD724 80240A54 AFB20028 */  sw        $s2, 0x28($sp)
/* DCD728 80240A58 0080902D */  daddu     $s2, $a0, $zero
/* DCD72C 80240A5C AFBF002C */  sw        $ra, 0x2c($sp)
/* DCD730 80240A60 AFB10024 */  sw        $s1, 0x24($sp)
/* DCD734 80240A64 AFB00020 */  sw        $s0, 0x20($sp)
/* DCD738 80240A68 8E510148 */  lw        $s1, 0x148($s2)
/* DCD73C 80240A6C 0C00EABB */  jal       get_npc_unsafe
/* DCD740 80240A70 86240008 */   lh       $a0, 8($s1)
/* DCD744 80240A74 0040802D */  daddu     $s0, $v0, $zero
/* DCD748 80240A78 0200202D */  daddu     $a0, $s0, $zero
/* DCD74C 80240A7C C600000C */  lwc1      $f0, 0xc($s0)
/* DCD750 80240A80 27A60018 */  addiu     $a2, $sp, 0x18
/* DCD754 80240A84 E7A00018 */  swc1      $f0, 0x18($sp)
/* DCD758 80240A88 AFA00010 */  sw        $zero, 0x10($sp)
/* DCD75C 80240A8C AFA00014 */  sw        $zero, 0x14($sp)
/* DCD760 80240A90 8E050018 */  lw        $a1, 0x18($s0)
/* DCD764 80240A94 0C0129E1 */  jal       func_8004A784
/* DCD768 80240A98 0000382D */   daddu    $a3, $zero, $zero
/* DCD76C 80240A9C 14400005 */  bnez      $v0, .L80240AB4
/* DCD770 80240AA0 00000000 */   nop
/* DCD774 80240AA4 8E050018 */  lw        $a1, 0x18($s0)
/* DCD778 80240AA8 8E06000C */  lw        $a2, 0xc($s0)
/* DCD77C 80240AAC 0C00EA95 */  jal       npc_move_heading
/* DCD780 80240AB0 0200202D */   daddu    $a0, $s0, $zero
.L80240AB4:
/* DCD784 80240AB4 9602008E */  lhu       $v0, 0x8e($s0)
/* DCD788 80240AB8 2442FFFF */  addiu     $v0, $v0, -1
/* DCD78C 80240ABC A602008E */  sh        $v0, 0x8e($s0)
/* DCD790 80240AC0 00021400 */  sll       $v0, $v0, 0x10
/* DCD794 80240AC4 14400010 */  bnez      $v0, .L80240B08
/* DCD798 80240AC8 00000000 */   nop
/* DCD79C 80240ACC C6000018 */  lwc1      $f0, 0x18($s0)
/* DCD7A0 80240AD0 3C018025 */  lui       $at, %hi(D_8024A638_DD7308)
/* DCD7A4 80240AD4 D422A638 */  ldc1      $f2, %lo(D_8024A638_DD7308)($at)
/* DCD7A8 80240AD8 46000021 */  cvt.d.s   $f0, $f0
/* DCD7AC 80240ADC 46220002 */  mul.d     $f0, $f0, $f2
/* DCD7B0 80240AE0 00000000 */  nop
/* DCD7B4 80240AE4 46200020 */  cvt.s.d   $f0, $f0
/* DCD7B8 80240AE8 E6000018 */  swc1      $f0, 0x18($s0)
/* DCD7BC 80240AEC 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCD7C0 80240AF0 8C43002C */  lw        $v1, 0x2c($v0)
/* DCD7C4 80240AF4 2402000A */  addiu     $v0, $zero, 0xa
/* DCD7C8 80240AF8 A602008E */  sh        $v0, 0x8e($s0)
/* DCD7CC 80240AFC 24020010 */  addiu     $v0, $zero, 0x10
/* DCD7D0 80240B00 AE030028 */  sw        $v1, 0x28($s0)
/* DCD7D4 80240B04 AE420070 */  sw        $v0, 0x70($s2)
.L80240B08:
/* DCD7D8 80240B08 8FBF002C */  lw        $ra, 0x2c($sp)
/* DCD7DC 80240B0C 8FB20028 */  lw        $s2, 0x28($sp)
/* DCD7E0 80240B10 8FB10024 */  lw        $s1, 0x24($sp)
/* DCD7E4 80240B14 8FB00020 */  lw        $s0, 0x20($sp)
/* DCD7E8 80240B18 03E00008 */  jr        $ra
/* DCD7EC 80240B1C 27BD0030 */   addiu    $sp, $sp, 0x30
