.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_78BB18
/* 78BB18 802A1518 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 78BB1C 802A151C AFB1001C */  sw        $s1, 0x1c($sp)
/* 78BB20 802A1520 0080882D */  daddu     $s1, $a0, $zero
/* 78BB24 802A1524 AFBF0024 */  sw        $ra, 0x24($sp)
/* 78BB28 802A1528 AFB20020 */  sw        $s2, 0x20($sp)
/* 78BB2C 802A152C AFB00018 */  sw        $s0, 0x18($sp)
/* 78BB30 802A1530 8E24000C */  lw        $a0, 0xc($s1)
/* 78BB34 802A1534 54A00001 */  bnel      $a1, $zero, .L802A153C
/* 78BB38 802A1538 AE200070 */   sw       $zero, 0x70($s1)
.L802A153C:
/* 78BB3C 802A153C 24120001 */  addiu     $s2, $zero, 1
/* 78BB40 802A1540 8E230070 */  lw        $v1, 0x70($s1)
/* 78BB44 802A1544 8E300074 */  lw        $s0, 0x74($s1)
/* 78BB48 802A1548 10720027 */  beq       $v1, $s2, .L802A15E8
/* 78BB4C 802A154C 28620002 */   slti     $v0, $v1, 2
/* 78BB50 802A1550 10400005 */  beqz      $v0, .L802A1568
/* 78BB54 802A1554 24020002 */   addiu    $v0, $zero, 2
/* 78BB58 802A1558 10600007 */  beqz      $v1, .L802A1578
/* 78BB5C 802A155C 0000102D */   daddu    $v0, $zero, $zero
/* 78BB60 802A1560 080A85EF */  j         .L802A17BC
/* 78BB64 802A1564 00000000 */   nop
.L802A1568:
/* 78BB68 802A1568 10620091 */  beq       $v1, $v0, .L802A17B0
/* 78BB6C 802A156C 0000102D */   daddu    $v0, $zero, $zero
/* 78BB70 802A1570 080A85EF */  j         .L802A17BC
/* 78BB74 802A1574 00000000 */   nop
.L802A1578:
/* 78BB78 802A1578 8C850000 */  lw        $a1, ($a0)
/* 78BB7C 802A157C 0C0B1EAF */  jal       get_variable
/* 78BB80 802A1580 0220202D */   daddu    $a0, $s1, $zero
/* 78BB84 802A1584 0C00EABB */  jal       get_npc_unsafe
/* 78BB88 802A1588 0040202D */   daddu    $a0, $v0, $zero
/* 78BB8C 802A158C 3C01BFC0 */  lui       $at, 0xbfc0
/* 78BB90 802A1590 44810000 */  mtc1      $at, $f0
/* 78BB94 802A1594 3C013CA3 */  lui       $at, 0x3ca3
/* 78BB98 802A1598 3421D70A */  ori       $at, $at, 0xd70a
/* 78BB9C 802A159C 44811000 */  mtc1      $at, $f2
/* 78BBA0 802A15A0 3C013F80 */  lui       $at, 0x3f80
/* 78BBA4 802A15A4 44812000 */  mtc1      $at, $f4
/* 78BBA8 802A15A8 0040802D */  daddu     $s0, $v0, $zero
/* 78BBAC 802A15AC AE300074 */  sw        $s0, 0x74($s1)
/* 78BBB0 802A15B0 C6060038 */  lwc1      $f6, 0x38($s0)
/* 78BBB4 802A15B4 C608003C */  lwc1      $f8, 0x3c($s0)
/* 78BBB8 802A15B8 C60A0040 */  lwc1      $f10, 0x40($s0)
/* 78BBBC 802A15BC AE000010 */  sw        $zero, 0x10($s0)
/* 78BBC0 802A15C0 AE00000C */  sw        $zero, 0xc($s0)
/* 78BBC4 802A15C4 A600008E */  sh        $zero, 0x8e($s0)
/* 78BBC8 802A15C8 E600001C */  swc1      $f0, 0x1c($s0)
/* 78BBCC 802A15CC E6020014 */  swc1      $f2, 0x14($s0)
/* 78BBD0 802A15D0 E6040018 */  swc1      $f4, 0x18($s0)
/* 78BBD4 802A15D4 E6060060 */  swc1      $f6, 0x60($s0)
/* 78BBD8 802A15D8 E6080064 */  swc1      $f8, 0x64($s0)
/* 78BBDC 802A15DC E60A0068 */  swc1      $f10, 0x68($s0)
/* 78BBE0 802A15E0 080A85EE */  j         .L802A17B8
/* 78BBE4 802A15E4 AE320070 */   sw       $s2, 0x70($s1)
.L802A15E8:
/* 78BBE8 802A15E8 C602001C */  lwc1      $f2, 0x1c($s0)
/* 78BBEC 802A15EC 44800000 */  mtc1      $zero, $f0
/* 78BBF0 802A15F0 00000000 */  nop
/* 78BBF4 802A15F4 4600103C */  c.lt.s    $f2, $f0
/* 78BBF8 802A15F8 00000000 */  nop
/* 78BBFC 802A15FC 4500000D */  bc1f      .L802A1634
/* 78BC00 802A1600 00000000 */   nop
/* 78BC04 802A1604 C6000010 */  lwc1      $f0, 0x10($s0)
/* 78BC08 802A1608 3C014008 */  lui       $at, 0x4008
/* 78BC0C 802A160C 44811800 */  mtc1      $at, $f3
/* 78BC10 802A1610 44801000 */  mtc1      $zero, $f2
/* 78BC14 802A1614 46000021 */  cvt.d.s   $f0, $f0
/* 78BC18 802A1618 46220000 */  add.d     $f0, $f0, $f2
/* 78BC1C 802A161C 3C014220 */  lui       $at, 0x4220
/* 78BC20 802A1620 44811000 */  mtc1      $at, $f2
/* 78BC24 802A1624 46200020 */  cvt.s.d   $f0, $f0
/* 78BC28 802A1628 4600103C */  c.lt.s    $f2, $f0
/* 78BC2C 802A162C 080A8598 */  j         .L802A1660
/* 78BC30 802A1630 E6000010 */   swc1     $f0, 0x10($s0)
.L802A1634:
/* 78BC34 802A1634 C6000010 */  lwc1      $f0, 0x10($s0)
/* 78BC38 802A1638 3C014000 */  lui       $at, 0x4000
/* 78BC3C 802A163C 44811800 */  mtc1      $at, $f3
/* 78BC40 802A1640 44801000 */  mtc1      $zero, $f2
/* 78BC44 802A1644 46000021 */  cvt.d.s   $f0, $f0
/* 78BC48 802A1648 46220001 */  sub.d     $f0, $f0, $f2
/* 78BC4C 802A164C 3C0141A0 */  lui       $at, 0x41a0
/* 78BC50 802A1650 44811000 */  mtc1      $at, $f2
/* 78BC54 802A1654 46200020 */  cvt.s.d   $f0, $f0
/* 78BC58 802A1658 4602003C */  c.lt.s    $f0, $f2
/* 78BC5C 802A165C E6000010 */  swc1      $f0, 0x10($s0)
.L802A1660:
/* 78BC60 802A1660 45030001 */  bc1tl     .L802A1668
/* 78BC64 802A1664 E6020010 */   swc1     $f2, 0x10($s0)
.L802A1668:
/* 78BC68 802A1668 C6000018 */  lwc1      $f0, 0x18($s0)
/* 78BC6C 802A166C 3C013FE8 */  lui       $at, 0x3fe8
/* 78BC70 802A1670 44811800 */  mtc1      $at, $f3
/* 78BC74 802A1674 44801000 */  mtc1      $zero, $f2
/* 78BC78 802A1678 C604001C */  lwc1      $f4, 0x1c($s0)
/* 78BC7C 802A167C 46000021 */  cvt.d.s   $f0, $f0
/* 78BC80 802A1680 46220000 */  add.d     $f0, $f0, $f2
/* 78BC84 802A1684 C6020014 */  lwc1      $f2, 0x14($s0)
/* 78BC88 802A1688 3C014204 */  lui       $at, 0x4204
/* 78BC8C 802A168C 44813000 */  mtc1      $at, $f6
/* 78BC90 802A1690 46022100 */  add.s     $f4, $f4, $f2
/* 78BC94 802A1694 C602003C */  lwc1      $f2, 0x3c($s0)
/* 78BC98 802A1698 46200020 */  cvt.s.d   $f0, $f0
/* 78BC9C 802A169C 4600303C */  c.lt.s    $f6, $f0
/* 78BCA0 802A16A0 46041080 */  add.s     $f2, $f2, $f4
/* 78BCA4 802A16A4 E6000018 */  swc1      $f0, 0x18($s0)
/* 78BCA8 802A16A8 E604001C */  swc1      $f4, 0x1c($s0)
/* 78BCAC 802A16AC 45000002 */  bc1f      .L802A16B8
/* 78BCB0 802A16B0 E602003C */   swc1     $f2, 0x3c($s0)
/* 78BCB4 802A16B4 E6060018 */  swc1      $f6, 0x18($s0)
.L802A16B8:
/* 78BCB8 802A16B8 C602000C */  lwc1      $f2, 0xc($s0)
/* 78BCBC 802A16BC C6000018 */  lwc1      $f0, 0x18($s0)
/* 78BCC0 802A16C0 8E060010 */  lw        $a2, 0x10($s0)
/* 78BCC4 802A16C4 46001080 */  add.s     $f2, $f2, $f0
/* 78BCC8 802A16C8 C6000060 */  lwc1      $f0, 0x60($s0)
/* 78BCCC 802A16CC 26040038 */  addiu     $a0, $s0, 0x38
/* 78BCD0 802A16D0 E602000C */  swc1      $f2, 0xc($s0)
/* 78BCD4 802A16D4 44071000 */  mfc1      $a3, $f2
/* 78BCD8 802A16D8 C6020068 */  lwc1      $f2, 0x68($s0)
/* 78BCDC 802A16DC 26050040 */  addiu     $a1, $s0, 0x40
/* 78BCE0 802A16E0 E6000038 */  swc1      $f0, 0x38($s0)
/* 78BCE4 802A16E4 0C00A7E7 */  jal       add_vec2D_polar
/* 78BCE8 802A16E8 E6020040 */   swc1     $f2, 0x40($s0)
/* 78BCEC 802A16EC 3C039249 */  lui       $v1, 0x9249
/* 78BCF0 802A16F0 9602008E */  lhu       $v0, 0x8e($s0)
/* 78BCF4 802A16F4 34632493 */  ori       $v1, $v1, 0x2493
/* 78BCF8 802A16F8 00021400 */  sll       $v0, $v0, 0x10
/* 78BCFC 802A16FC 00022403 */  sra       $a0, $v0, 0x10
/* 78BD00 802A1700 00830018 */  mult      $a0, $v1
/* 78BD04 802A1704 000217C3 */  sra       $v0, $v0, 0x1f
/* 78BD08 802A1708 00004010 */  mfhi      $t0
/* 78BD0C 802A170C 01041821 */  addu      $v1, $t0, $a0
/* 78BD10 802A1710 000318C3 */  sra       $v1, $v1, 3
/* 78BD14 802A1714 00621823 */  subu      $v1, $v1, $v0
/* 78BD18 802A1718 000310C0 */  sll       $v0, $v1, 3
/* 78BD1C 802A171C 00431023 */  subu      $v0, $v0, $v1
/* 78BD20 802A1720 00021040 */  sll       $v0, $v0, 1
/* 78BD24 802A1724 00822023 */  subu      $a0, $a0, $v0
/* 78BD28 802A1728 00042400 */  sll       $a0, $a0, 0x10
/* 78BD2C 802A172C 1480000A */  bnez      $a0, .L802A1758
/* 78BD30 802A1730 00000000 */   nop
/* 78BD34 802A1734 3C0141F0 */  lui       $at, 0x41f0
/* 78BD38 802A1738 44810000 */  mtc1      $at, $f0
/* 78BD3C 802A173C 00000000 */  nop
/* 78BD40 802A1740 E7A00010 */  swc1      $f0, 0x10($sp)
/* 78BD44 802A1744 8E050038 */  lw        $a1, 0x38($s0)
/* 78BD48 802A1748 8E06003C */  lw        $a2, 0x3c($s0)
/* 78BD4C 802A174C 8E070040 */  lw        $a3, 0x40($s0)
/* 78BD50 802A1750 0C01BFBC */  jal       func_8006FEF0
/* 78BD54 802A1754 0000202D */   daddu    $a0, $zero, $zero
.L802A1758:
/* 78BD58 802A1758 9602008E */  lhu       $v0, 0x8e($s0)
/* 78BD5C 802A175C 24420001 */  addiu     $v0, $v0, 1
/* 78BD60 802A1760 A602008E */  sh        $v0, 0x8e($s0)
/* 78BD64 802A1764 00021400 */  sll       $v0, $v0, 0x10
/* 78BD68 802A1768 00021403 */  sra       $v0, $v0, 0x10
/* 78BD6C 802A176C 28420029 */  slti      $v0, $v0, 0x29
/* 78BD70 802A1770 14400005 */  bnez      $v0, .L802A1788
/* 78BD74 802A1774 00000000 */   nop
/* 78BD78 802A1778 3C013F00 */  lui       $at, 0x3f00
/* 78BD7C 802A177C 44810000 */  mtc1      $at, $f0
/* 78BD80 802A1780 00000000 */  nop
/* 78BD84 802A1784 E6000014 */  swc1      $f0, 0x14($s0)
.L802A1788:
/* 78BD88 802A1788 C602003C */  lwc1      $f2, 0x3c($s0)
/* 78BD8C 802A178C 3C014348 */  lui       $at, 0x4348
/* 78BD90 802A1790 44810000 */  mtc1      $at, $f0
/* 78BD94 802A1794 00000000 */  nop
/* 78BD98 802A1798 4602003C */  c.lt.s    $f0, $f2
/* 78BD9C 802A179C 00000000 */  nop
/* 78BDA0 802A17A0 45000005 */  bc1f      .L802A17B8
/* 78BDA4 802A17A4 24020002 */   addiu    $v0, $zero, 2
/* 78BDA8 802A17A8 080A85EE */  j         .L802A17B8
/* 78BDAC 802A17AC AE220070 */   sw       $v0, 0x70($s1)
.L802A17B0:
/* 78BDB0 802A17B0 080A85EF */  j         .L802A17BC
/* 78BDB4 802A17B4 24020002 */   addiu    $v0, $zero, 2
.L802A17B8:
/* 78BDB8 802A17B8 0000102D */  daddu     $v0, $zero, $zero
.L802A17BC:
/* 78BDBC 802A17BC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 78BDC0 802A17C0 8FB20020 */  lw        $s2, 0x20($sp)
/* 78BDC4 802A17C4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 78BDC8 802A17C8 8FB00018 */  lw        $s0, 0x18($sp)
/* 78BDCC 802A17CC 03E00008 */  jr        $ra
/* 78BDD0 802A17D0 27BD0028 */   addiu    $sp, $sp, 0x28
