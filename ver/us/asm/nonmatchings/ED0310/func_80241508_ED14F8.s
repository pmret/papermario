.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241508_ED14F8
/* ED14F8 80241508 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* ED14FC 8024150C AFB00028 */  sw        $s0, 0x28($sp)
/* ED1500 80241510 00A0802D */  daddu     $s0, $a1, $zero
/* ED1504 80241514 AFB1002C */  sw        $s1, 0x2c($sp)
/* ED1508 80241518 00C0882D */  daddu     $s1, $a2, $zero
/* ED150C 8024151C AFBF0034 */  sw        $ra, 0x34($sp)
/* ED1510 80241520 AFB20030 */  sw        $s2, 0x30($sp)
/* ED1514 80241524 AE200070 */  sw        $zero, 0x70($s1)
/* ED1518 80241528 8C830000 */  lw        $v1, ($a0)
/* ED151C 8024152C 2402FDFF */  addiu     $v0, $zero, -0x201
/* ED1520 80241530 A480008E */  sh        $zero, 0x8e($a0)
/* ED1524 80241534 00621824 */  and       $v1, $v1, $v0
/* ED1528 80241538 34650800 */  ori       $a1, $v1, 0x800
/* ED152C 8024153C AC850000 */  sw        $a1, ($a0)
/* ED1530 80241540 8E0200D0 */  lw        $v0, 0xd0($s0)
/* ED1534 80241544 8C420034 */  lw        $v0, 0x34($v0)
/* ED1538 80241548 10400003 */  beqz      $v0, .L80241558
/* ED153C 8024154C 00E0902D */   daddu    $s2, $a3, $zero
/* ED1540 80241550 08090558 */  j         .L80241560
/* ED1544 80241554 34620808 */   ori      $v0, $v1, 0x808
.L80241558:
/* ED1548 80241558 2402FFF7 */  addiu     $v0, $zero, -9
/* ED154C 8024155C 00A21024 */  and       $v0, $a1, $v0
.L80241560:
/* ED1550 80241560 AC820000 */  sw        $v0, ($a0)
/* ED1554 80241564 27A20024 */  addiu     $v0, $sp, 0x24
/* ED1558 80241568 27A50018 */  addiu     $a1, $sp, 0x18
/* ED155C 8024156C C4800038 */  lwc1      $f0, 0x38($a0)
/* ED1560 80241570 C482003C */  lwc1      $f2, 0x3c($a0)
/* ED1564 80241574 C4840040 */  lwc1      $f4, 0x40($a0)
/* ED1568 80241578 3C01447A */  lui       $at, 0x447a
/* ED156C 8024157C 44813000 */  mtc1      $at, $f6
/* ED1570 80241580 27A6001C */  addiu     $a2, $sp, 0x1c
/* ED1574 80241584 E7A00018 */  swc1      $f0, 0x18($sp)
/* ED1578 80241588 E7A2001C */  swc1      $f2, 0x1c($sp)
/* ED157C 8024158C E7A40020 */  swc1      $f4, 0x20($sp)
/* ED1580 80241590 E7A60024 */  swc1      $f6, 0x24($sp)
/* ED1584 80241594 AFA20010 */  sw        $v0, 0x10($sp)
/* ED1588 80241598 8C840080 */  lw        $a0, 0x80($a0)
/* ED158C 8024159C 0C03908F */  jal       dead_npc_raycast_down_sides
/* ED1590 802415A0 27A70020 */   addiu    $a3, $sp, 0x20
/* ED1594 802415A4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* ED1598 802415A8 3C014059 */  lui       $at, 0x4059
/* ED159C 802415AC 44812800 */  mtc1      $at, $f5
/* ED15A0 802415B0 44802000 */  mtc1      $zero, $f4
/* ED15A4 802415B4 460010A1 */  cvt.d.s   $f2, $f2
/* ED15A8 802415B8 46241082 */  mul.d     $f2, $f2, $f4
/* ED15AC 802415BC 00000000 */  nop
/* ED15B0 802415C0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* ED15B4 802415C4 46000021 */  cvt.d.s   $f0, $f0
/* ED15B8 802415C8 46240002 */  mul.d     $f0, $f0, $f4
/* ED15BC 802415CC 00000000 */  nop
/* ED15C0 802415D0 3C013FE0 */  lui       $at, 0x3fe0
/* ED15C4 802415D4 44812800 */  mtc1      $at, $f5
/* ED15C8 802415D8 44802000 */  mtc1      $zero, $f4
/* ED15CC 802415DC 00000000 */  nop
/* ED15D0 802415E0 46241080 */  add.d     $f2, $f2, $f4
/* ED15D4 802415E4 AE000074 */  sw        $zero, 0x74($s0)
/* ED15D8 802415E8 46240000 */  add.d     $f0, $f0, $f4
/* ED15DC 802415EC AE000090 */  sw        $zero, 0x90($s0)
/* ED15E0 802415F0 4620120D */  trunc.w.d $f8, $f2
/* ED15E4 802415F4 E6080078 */  swc1      $f8, 0x78($s0)
/* ED15E8 802415F8 4620020D */  trunc.w.d $f8, $f0
/* ED15EC 802415FC E6080088 */  swc1      $f8, 0x88($s0)
/* ED15F0 80241600 8E420014 */  lw        $v0, 0x14($s2)
/* ED15F4 80241604 AE220074 */  sw        $v0, 0x74($s1)
/* ED15F8 80241608 8E0200B0 */  lw        $v0, 0xb0($s0)
/* ED15FC 8024160C 34420010 */  ori       $v0, $v0, 0x10
/* ED1600 80241610 AE0200B0 */  sw        $v0, 0xb0($s0)
/* ED1604 80241614 8FBF0034 */  lw        $ra, 0x34($sp)
/* ED1608 80241618 8FB20030 */  lw        $s2, 0x30($sp)
/* ED160C 8024161C 8FB1002C */  lw        $s1, 0x2c($sp)
/* ED1610 80241620 8FB00028 */  lw        $s0, 0x28($sp)
/* ED1614 80241624 03E00008 */  jr        $ra
/* ED1618 80241628 27BD0038 */   addiu    $sp, $sp, 0x38
