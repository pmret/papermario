.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241588_DAE988
/* DAE988 80241588 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DAE98C 8024158C AFB00028 */  sw        $s0, 0x28($sp)
/* DAE990 80241590 00A0802D */  daddu     $s0, $a1, $zero
/* DAE994 80241594 AFB1002C */  sw        $s1, 0x2c($sp)
/* DAE998 80241598 00C0882D */  daddu     $s1, $a2, $zero
/* DAE99C 8024159C AFBF0034 */  sw        $ra, 0x34($sp)
/* DAE9A0 802415A0 AFB20030 */  sw        $s2, 0x30($sp)
/* DAE9A4 802415A4 AE200070 */  sw        $zero, 0x70($s1)
/* DAE9A8 802415A8 8C830000 */  lw        $v1, ($a0)
/* DAE9AC 802415AC 2402FDFF */  addiu     $v0, $zero, -0x201
/* DAE9B0 802415B0 A480008E */  sh        $zero, 0x8e($a0)
/* DAE9B4 802415B4 00621824 */  and       $v1, $v1, $v0
/* DAE9B8 802415B8 34650800 */  ori       $a1, $v1, 0x800
/* DAE9BC 802415BC AC850000 */  sw        $a1, ($a0)
/* DAE9C0 802415C0 8E0200D0 */  lw        $v0, 0xd0($s0)
/* DAE9C4 802415C4 8C420034 */  lw        $v0, 0x34($v0)
/* DAE9C8 802415C8 10400003 */  beqz      $v0, .L802415D8
/* DAE9CC 802415CC 00E0902D */   daddu    $s2, $a3, $zero
/* DAE9D0 802415D0 08090578 */  j         .L802415E0
/* DAE9D4 802415D4 34620808 */   ori      $v0, $v1, 0x808
.L802415D8:
/* DAE9D8 802415D8 2402FFF7 */  addiu     $v0, $zero, -9
/* DAE9DC 802415DC 00A21024 */  and       $v0, $a1, $v0
.L802415E0:
/* DAE9E0 802415E0 AC820000 */  sw        $v0, ($a0)
/* DAE9E4 802415E4 27A20024 */  addiu     $v0, $sp, 0x24
/* DAE9E8 802415E8 27A50018 */  addiu     $a1, $sp, 0x18
/* DAE9EC 802415EC C4800038 */  lwc1      $f0, 0x38($a0)
/* DAE9F0 802415F0 C482003C */  lwc1      $f2, 0x3c($a0)
/* DAE9F4 802415F4 C4840040 */  lwc1      $f4, 0x40($a0)
/* DAE9F8 802415F8 3C01447A */  lui       $at, 0x447a
/* DAE9FC 802415FC 44813000 */  mtc1      $at, $f6
/* DAEA00 80241600 27A6001C */  addiu     $a2, $sp, 0x1c
/* DAEA04 80241604 E7A00018 */  swc1      $f0, 0x18($sp)
/* DAEA08 80241608 E7A2001C */  swc1      $f2, 0x1c($sp)
/* DAEA0C 8024160C E7A40020 */  swc1      $f4, 0x20($sp)
/* DAEA10 80241610 E7A60024 */  swc1      $f6, 0x24($sp)
/* DAEA14 80241614 AFA20010 */  sw        $v0, 0x10($sp)
/* DAEA18 80241618 8C840080 */  lw        $a0, 0x80($a0)
/* DAEA1C 8024161C 0C0372DF */  jal       func_800DCB7C
/* DAEA20 80241620 27A70020 */   addiu    $a3, $sp, 0x20
/* DAEA24 80241624 C7A20024 */  lwc1      $f2, 0x24($sp)
/* DAEA28 80241628 3C014059 */  lui       $at, 0x4059
/* DAEA2C 8024162C 44812800 */  mtc1      $at, $f5
/* DAEA30 80241630 44802000 */  mtc1      $zero, $f4
/* DAEA34 80241634 460010A1 */  cvt.d.s   $f2, $f2
/* DAEA38 80241638 46241082 */  mul.d     $f2, $f2, $f4
/* DAEA3C 8024163C 00000000 */  nop       
/* DAEA40 80241640 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DAEA44 80241644 46000021 */  cvt.d.s   $f0, $f0
/* DAEA48 80241648 46240002 */  mul.d     $f0, $f0, $f4
/* DAEA4C 8024164C 00000000 */  nop       
/* DAEA50 80241650 3C013FE0 */  lui       $at, 0x3fe0
/* DAEA54 80241654 44812800 */  mtc1      $at, $f5
/* DAEA58 80241658 44802000 */  mtc1      $zero, $f4
/* DAEA5C 8024165C 00000000 */  nop       
/* DAEA60 80241660 46241080 */  add.d     $f2, $f2, $f4
/* DAEA64 80241664 AE000074 */  sw        $zero, 0x74($s0)
/* DAEA68 80241668 46240000 */  add.d     $f0, $f0, $f4
/* DAEA6C 8024166C AE000090 */  sw        $zero, 0x90($s0)
/* DAEA70 80241670 4620120D */  trunc.w.d $f8, $f2
/* DAEA74 80241674 E6080078 */  swc1      $f8, 0x78($s0)
/* DAEA78 80241678 4620020D */  trunc.w.d $f8, $f0
/* DAEA7C 8024167C E6080088 */  swc1      $f8, 0x88($s0)
/* DAEA80 80241680 8E420014 */  lw        $v0, 0x14($s2)
/* DAEA84 80241684 AE220074 */  sw        $v0, 0x74($s1)
/* DAEA88 80241688 8E0200B0 */  lw        $v0, 0xb0($s0)
/* DAEA8C 8024168C 34420010 */  ori       $v0, $v0, 0x10
/* DAEA90 80241690 AE0200B0 */  sw        $v0, 0xb0($s0)
/* DAEA94 80241694 8FBF0034 */  lw        $ra, 0x34($sp)
/* DAEA98 80241698 8FB20030 */  lw        $s2, 0x30($sp)
/* DAEA9C 8024169C 8FB1002C */  lw        $s1, 0x2c($sp)
/* DAEAA0 802416A0 8FB00028 */  lw        $s0, 0x28($sp)
/* DAEAA4 802416A4 03E00008 */  jr        $ra
/* DAEAA8 802416A8 27BD0038 */   addiu    $sp, $sp, 0x38
