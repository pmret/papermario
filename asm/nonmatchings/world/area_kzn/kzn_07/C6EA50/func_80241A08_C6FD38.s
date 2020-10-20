.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A08_C6FD38
/* C6FD38 80241A08 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C6FD3C 80241A0C AFB00028 */  sw        $s0, 0x28($sp)
/* C6FD40 80241A10 00A0802D */  daddu     $s0, $a1, $zero
/* C6FD44 80241A14 AFB1002C */  sw        $s1, 0x2c($sp)
/* C6FD48 80241A18 00C0882D */  daddu     $s1, $a2, $zero
/* C6FD4C 80241A1C AFBF0034 */  sw        $ra, 0x34($sp)
/* C6FD50 80241A20 AFB20030 */  sw        $s2, 0x30($sp)
/* C6FD54 80241A24 AE200070 */  sw        $zero, 0x70($s1)
/* C6FD58 80241A28 8C830000 */  lw        $v1, ($a0)
/* C6FD5C 80241A2C 2402FDFF */  addiu     $v0, $zero, -0x201
/* C6FD60 80241A30 A480008E */  sh        $zero, 0x8e($a0)
/* C6FD64 80241A34 00621824 */  and       $v1, $v1, $v0
/* C6FD68 80241A38 34650800 */  ori       $a1, $v1, 0x800
/* C6FD6C 80241A3C AC850000 */  sw        $a1, ($a0)
/* C6FD70 80241A40 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C6FD74 80241A44 8C420034 */  lw        $v0, 0x34($v0)
/* C6FD78 80241A48 10400003 */  beqz      $v0, .L80241A58
/* C6FD7C 80241A4C 00E0902D */   daddu    $s2, $a3, $zero
/* C6FD80 80241A50 08090698 */  j         .L80241A60
/* C6FD84 80241A54 34620808 */   ori      $v0, $v1, 0x808
.L80241A58:
/* C6FD88 80241A58 2402FFF7 */  addiu     $v0, $zero, -9
/* C6FD8C 80241A5C 00A21024 */  and       $v0, $a1, $v0
.L80241A60:
/* C6FD90 80241A60 AC820000 */  sw        $v0, ($a0)
/* C6FD94 80241A64 27A20024 */  addiu     $v0, $sp, 0x24
/* C6FD98 80241A68 27A50018 */  addiu     $a1, $sp, 0x18
/* C6FD9C 80241A6C C4800038 */  lwc1      $f0, 0x38($a0)
/* C6FDA0 80241A70 C482003C */  lwc1      $f2, 0x3c($a0)
/* C6FDA4 80241A74 C4840040 */  lwc1      $f4, 0x40($a0)
/* C6FDA8 80241A78 3C01447A */  lui       $at, 0x447a
/* C6FDAC 80241A7C 44813000 */  mtc1      $at, $f6
/* C6FDB0 80241A80 27A6001C */  addiu     $a2, $sp, 0x1c
/* C6FDB4 80241A84 E7A00018 */  swc1      $f0, 0x18($sp)
/* C6FDB8 80241A88 E7A2001C */  swc1      $f2, 0x1c($sp)
/* C6FDBC 80241A8C E7A40020 */  swc1      $f4, 0x20($sp)
/* C6FDC0 80241A90 E7A60024 */  swc1      $f6, 0x24($sp)
/* C6FDC4 80241A94 AFA20010 */  sw        $v0, 0x10($sp)
/* C6FDC8 80241A98 8C840080 */  lw        $a0, 0x80($a0)
/* C6FDCC 80241A9C 0C0372DF */  jal       func_800DCB7C
/* C6FDD0 80241AA0 27A70020 */   addiu    $a3, $sp, 0x20
/* C6FDD4 80241AA4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* C6FDD8 80241AA8 3C014059 */  lui       $at, 0x4059
/* C6FDDC 80241AAC 44812800 */  mtc1      $at, $f5
/* C6FDE0 80241AB0 44802000 */  mtc1      $zero, $f4
/* C6FDE4 80241AB4 460010A1 */  cvt.d.s   $f2, $f2
/* C6FDE8 80241AB8 46241082 */  mul.d     $f2, $f2, $f4
/* C6FDEC 80241ABC 00000000 */  nop       
/* C6FDF0 80241AC0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C6FDF4 80241AC4 46000021 */  cvt.d.s   $f0, $f0
/* C6FDF8 80241AC8 46240002 */  mul.d     $f0, $f0, $f4
/* C6FDFC 80241ACC 00000000 */  nop       
/* C6FE00 80241AD0 3C013FE0 */  lui       $at, 0x3fe0
/* C6FE04 80241AD4 44812800 */  mtc1      $at, $f5
/* C6FE08 80241AD8 44802000 */  mtc1      $zero, $f4
/* C6FE0C 80241ADC 00000000 */  nop       
/* C6FE10 80241AE0 46241080 */  add.d     $f2, $f2, $f4
/* C6FE14 80241AE4 AE000074 */  sw        $zero, 0x74($s0)
/* C6FE18 80241AE8 46240000 */  add.d     $f0, $f0, $f4
/* C6FE1C 80241AEC AE000090 */  sw        $zero, 0x90($s0)
/* C6FE20 80241AF0 4620120D */  trunc.w.d $f8, $f2
/* C6FE24 80241AF4 E6080078 */  swc1      $f8, 0x78($s0)
/* C6FE28 80241AF8 4620020D */  trunc.w.d $f8, $f0
/* C6FE2C 80241AFC E6080088 */  swc1      $f8, 0x88($s0)
/* C6FE30 80241B00 8E420014 */  lw        $v0, 0x14($s2)
/* C6FE34 80241B04 AE220074 */  sw        $v0, 0x74($s1)
/* C6FE38 80241B08 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C6FE3C 80241B0C 34420010 */  ori       $v0, $v0, 0x10
/* C6FE40 80241B10 AE0200B0 */  sw        $v0, 0xb0($s0)
/* C6FE44 80241B14 8FBF0034 */  lw        $ra, 0x34($sp)
/* C6FE48 80241B18 8FB20030 */  lw        $s2, 0x30($sp)
/* C6FE4C 80241B1C 8FB1002C */  lw        $s1, 0x2c($sp)
/* C6FE50 80241B20 8FB00028 */  lw        $s0, 0x28($sp)
/* C6FE54 80241B24 03E00008 */  jr        $ra
/* C6FE58 80241B28 27BD0038 */   addiu    $sp, $sp, 0x38
