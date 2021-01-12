.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C8_C5BE08
/* C5BE08 802416C8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C5BE0C 802416CC AFB00028 */  sw        $s0, 0x28($sp)
/* C5BE10 802416D0 00A0802D */  daddu     $s0, $a1, $zero
/* C5BE14 802416D4 AFB1002C */  sw        $s1, 0x2c($sp)
/* C5BE18 802416D8 00C0882D */  daddu     $s1, $a2, $zero
/* C5BE1C 802416DC AFBF0034 */  sw        $ra, 0x34($sp)
/* C5BE20 802416E0 AFB20030 */  sw        $s2, 0x30($sp)
/* C5BE24 802416E4 AE200070 */  sw        $zero, 0x70($s1)
/* C5BE28 802416E8 8C830000 */  lw        $v1, ($a0)
/* C5BE2C 802416EC 2402FDFF */  addiu     $v0, $zero, -0x201
/* C5BE30 802416F0 A480008E */  sh        $zero, 0x8e($a0)
/* C5BE34 802416F4 00621824 */  and       $v1, $v1, $v0
/* C5BE38 802416F8 34650800 */  ori       $a1, $v1, 0x800
/* C5BE3C 802416FC AC850000 */  sw        $a1, ($a0)
/* C5BE40 80241700 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C5BE44 80241704 8C420034 */  lw        $v0, 0x34($v0)
/* C5BE48 80241708 10400003 */  beqz      $v0, .L80241718
/* C5BE4C 8024170C 00E0902D */   daddu    $s2, $a3, $zero
/* C5BE50 80241710 080905C8 */  j         .L80241720
/* C5BE54 80241714 34620808 */   ori      $v0, $v1, 0x808
.L80241718:
/* C5BE58 80241718 2402FFF7 */  addiu     $v0, $zero, -9
/* C5BE5C 8024171C 00A21024 */  and       $v0, $a1, $v0
.L80241720:
/* C5BE60 80241720 AC820000 */  sw        $v0, ($a0)
/* C5BE64 80241724 27A20024 */  addiu     $v0, $sp, 0x24
/* C5BE68 80241728 27A50018 */  addiu     $a1, $sp, 0x18
/* C5BE6C 8024172C C4800038 */  lwc1      $f0, 0x38($a0)
/* C5BE70 80241730 C482003C */  lwc1      $f2, 0x3c($a0)
/* C5BE74 80241734 C4840040 */  lwc1      $f4, 0x40($a0)
/* C5BE78 80241738 3C01447A */  lui       $at, 0x447a
/* C5BE7C 8024173C 44813000 */  mtc1      $at, $f6
/* C5BE80 80241740 27A6001C */  addiu     $a2, $sp, 0x1c
/* C5BE84 80241744 E7A00018 */  swc1      $f0, 0x18($sp)
/* C5BE88 80241748 E7A2001C */  swc1      $f2, 0x1c($sp)
/* C5BE8C 8024174C E7A40020 */  swc1      $f4, 0x20($sp)
/* C5BE90 80241750 E7A60024 */  swc1      $f6, 0x24($sp)
/* C5BE94 80241754 AFA20010 */  sw        $v0, 0x10($sp)
/* C5BE98 80241758 8C840080 */  lw        $a0, 0x80($a0)
/* C5BE9C 8024175C 0C0372DF */  jal       func_800DCB7C
/* C5BEA0 80241760 27A70020 */   addiu    $a3, $sp, 0x20
/* C5BEA4 80241764 C7A20024 */  lwc1      $f2, 0x24($sp)
/* C5BEA8 80241768 3C014059 */  lui       $at, 0x4059
/* C5BEAC 8024176C 44812800 */  mtc1      $at, $f5
/* C5BEB0 80241770 44802000 */  mtc1      $zero, $f4
/* C5BEB4 80241774 460010A1 */  cvt.d.s   $f2, $f2
/* C5BEB8 80241778 46241082 */  mul.d     $f2, $f2, $f4
/* C5BEBC 8024177C 00000000 */  nop
/* C5BEC0 80241780 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C5BEC4 80241784 46000021 */  cvt.d.s   $f0, $f0
/* C5BEC8 80241788 46240002 */  mul.d     $f0, $f0, $f4
/* C5BECC 8024178C 00000000 */  nop
/* C5BED0 80241790 3C013FE0 */  lui       $at, 0x3fe0
/* C5BED4 80241794 44812800 */  mtc1      $at, $f5
/* C5BED8 80241798 44802000 */  mtc1      $zero, $f4
/* C5BEDC 8024179C 00000000 */  nop
/* C5BEE0 802417A0 46241080 */  add.d     $f2, $f2, $f4
/* C5BEE4 802417A4 AE000074 */  sw        $zero, 0x74($s0)
/* C5BEE8 802417A8 46240000 */  add.d     $f0, $f0, $f4
/* C5BEEC 802417AC AE000090 */  sw        $zero, 0x90($s0)
/* C5BEF0 802417B0 4620120D */  trunc.w.d $f8, $f2
/* C5BEF4 802417B4 E6080078 */  swc1      $f8, 0x78($s0)
/* C5BEF8 802417B8 4620020D */  trunc.w.d $f8, $f0
/* C5BEFC 802417BC E6080088 */  swc1      $f8, 0x88($s0)
/* C5BF00 802417C0 8E420014 */  lw        $v0, 0x14($s2)
/* C5BF04 802417C4 AE220074 */  sw        $v0, 0x74($s1)
/* C5BF08 802417C8 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C5BF0C 802417CC 34420010 */  ori       $v0, $v0, 0x10
/* C5BF10 802417D0 AE0200B0 */  sw        $v0, 0xb0($s0)
/* C5BF14 802417D4 8FBF0034 */  lw        $ra, 0x34($sp)
/* C5BF18 802417D8 8FB20030 */  lw        $s2, 0x30($sp)
/* C5BF1C 802417DC 8FB1002C */  lw        $s1, 0x2c($sp)
/* C5BF20 802417E0 8FB00028 */  lw        $s0, 0x28($sp)
/* C5BF24 802417E4 03E00008 */  jr        $ra
/* C5BF28 802417E8 27BD0038 */   addiu    $sp, $sp, 0x38
