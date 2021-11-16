.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80246E20_9F4A10
.double 0.2

dlabel D_80246E28_9F4A18
.double 0.92

dlabel D_80246E30_9F4A20
.double 0.92, 0.0

.section .text

glabel func_80240814_9EE404
/* 9EE404 80240814 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 9EE408 80240818 3C028024 */  lui       $v0, %hi(D_802413F8_9EEFE8)
/* 9EE40C 8024081C 244213F8 */  addiu     $v0, $v0, %lo(D_802413F8_9EEFE8)
/* 9EE410 80240820 AFBF0048 */  sw        $ra, 0x48($sp)
/* 9EE414 80240824 AFB70044 */  sw        $s7, 0x44($sp)
/* 9EE418 80240828 AFB60040 */  sw        $s6, 0x40($sp)
/* 9EE41C 8024082C AFB5003C */  sw        $s5, 0x3c($sp)
/* 9EE420 80240830 AFB40038 */  sw        $s4, 0x38($sp)
/* 9EE424 80240834 AFB30034 */  sw        $s3, 0x34($sp)
/* 9EE428 80240838 AFB20030 */  sw        $s2, 0x30($sp)
/* 9EE42C 8024083C AFB1002C */  sw        $s1, 0x2c($sp)
/* 9EE430 80240840 AFB00028 */  sw        $s0, 0x28($sp)
/* 9EE434 80240844 F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 9EE438 80240848 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 9EE43C 8024084C F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 9EE440 80240850 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 9EE444 80240854 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 9EE448 80240858 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 9EE44C 8024085C C44E0000 */  lwc1      $f14, ($v0)
/* 9EE450 80240860 3C018024 */  lui       $at, %hi(D_80246E20_9F4A10)
/* 9EE454 80240864 D4226E20 */  ldc1      $f2, %lo(D_80246E20_9F4A10)($at)
/* 9EE458 80240868 44805000 */  mtc1      $zero, $f10
/* 9EE45C 8024086C E7AE0020 */  swc1      $f14, 0x20($sp)
/* 9EE460 80240870 C4400014 */  lwc1      $f0, 0x14($v0)
/* 9EE464 80240874 C4480030 */  lwc1      $f8, 0x30($v0)
/* 9EE468 80240878 46000021 */  cvt.d.s   $f0, $f0
/* 9EE46C 8024087C 46220000 */  add.d     $f0, $f0, $f2
/* 9EE470 80240880 C45E0004 */  lwc1      $f30, 4($v0)
/* 9EE474 80240884 C44E0008 */  lwc1      $f14, 8($v0)
/* 9EE478 80240888 460A4032 */  c.eq.s    $f8, $f10
/* 9EE47C 8024088C 46200120 */  cvt.s.d   $f4, $f0
/* 9EE480 80240890 E4440014 */  swc1      $f4, 0x14($v0)
/* 9EE484 80240894 4501002D */  bc1t      .L8024094C
/* 9EE488 80240898 E7AE0024 */   swc1     $f14, 0x24($sp)
/* 9EE48C 8024089C C4420010 */  lwc1      $f2, 0x10($v0)
/* 9EE490 802408A0 C4400038 */  lwc1      $f0, 0x38($v0)
/* 9EE494 802408A4 46001080 */  add.s     $f2, $f2, $f0
/* 9EE498 802408A8 C440000C */  lwc1      $f0, 0xc($v0)
/* 9EE49C 802408AC 4602003C */  c.lt.s    $f0, $f2
/* 9EE4A0 802408B0 00000000 */  nop
/* 9EE4A4 802408B4 45000009 */  bc1f      .L802408DC
/* 9EE4A8 802408B8 E4420010 */   swc1     $f2, 0x10($v0)
/* 9EE4AC 802408BC 46020001 */  sub.s     $f0, $f0, $f2
/* 9EE4B0 802408C0 3C013F00 */  lui       $at, 0x3f00
/* 9EE4B4 802408C4 44811000 */  mtc1      $at, $f2
/* 9EE4B8 802408C8 00000000 */  nop
/* 9EE4BC 802408CC 46020002 */  mul.s     $f0, $f0, $f2
/* 9EE4C0 802408D0 00000000 */  nop
/* 9EE4C4 802408D4 46002000 */  add.s     $f0, $f4, $f0
/* 9EE4C8 802408D8 E4400014 */  swc1      $f0, 0x14($v0)
.L802408DC:
/* 9EE4CC 802408DC C4420018 */  lwc1      $f2, 0x18($v0)
/* 9EE4D0 802408E0 C4460020 */  lwc1      $f6, 0x20($v0)
/* 9EE4D4 802408E4 46061081 */  sub.s     $f2, $f2, $f6
/* 9EE4D8 802408E8 3C014120 */  lui       $at, 0x4120
/* 9EE4DC 802408EC 44812000 */  mtc1      $at, $f4
/* 9EE4E0 802408F0 C440001C */  lwc1      $f0, 0x1c($v0)
/* 9EE4E4 802408F4 46041083 */  div.s     $f2, $f2, $f4
/* 9EE4E8 802408F8 46020000 */  add.s     $f0, $f0, $f2
/* 9EE4EC 802408FC 3C018024 */  lui       $at, %hi(D_80246E28_9F4A18)
/* 9EE4F0 80240900 D4226E28 */  ldc1      $f2, %lo(D_80246E28_9F4A18)($at)
/* 9EE4F4 80240904 46000021 */  cvt.d.s   $f0, $f0
/* 9EE4F8 80240908 46220002 */  mul.d     $f0, $f0, $f2
/* 9EE4FC 8024090C 00000000 */  nop
/* 9EE500 80240910 C4440034 */  lwc1      $f4, 0x34($v0)
/* 9EE504 80240914 3C013F80 */  lui       $at, 0x3f80
/* 9EE508 80240918 44811000 */  mtc1      $at, $f2
/* 9EE50C 8024091C 00000000 */  nop
/* 9EE510 80240920 46022100 */  add.s     $f4, $f4, $f2
/* 9EE514 80240924 C442003C */  lwc1      $f2, 0x3c($v0)
/* 9EE518 80240928 46023180 */  add.s     $f6, $f6, $f2
/* 9EE51C 8024092C 4604403E */  c.le.s    $f8, $f4
/* 9EE520 80240930 E4440034 */  swc1      $f4, 0x34($v0)
/* 9EE524 80240934 E4460020 */  swc1      $f6, 0x20($v0)
/* 9EE528 80240938 46200020 */  cvt.s.d   $f0, $f0
/* 9EE52C 8024093C 45000023 */  bc1f      .L802409CC
/* 9EE530 80240940 E440001C */   swc1     $f0, 0x1c($v0)
/* 9EE534 80240944 08090273 */  j         .L802409CC
/* 9EE538 80240948 E44A0030 */   swc1     $f10, 0x30($v0)
.L8024094C:
/* 9EE53C 8024094C C4400010 */  lwc1      $f0, 0x10($v0)
/* 9EE540 80240950 46040000 */  add.s     $f0, $f0, $f4
/* 9EE544 80240954 C442000C */  lwc1      $f2, 0xc($v0)
/* 9EE548 80240958 4600103C */  c.lt.s    $f2, $f0
/* 9EE54C 8024095C 00000000 */  nop
/* 9EE550 80240960 45000009 */  bc1f      .L80240988
/* 9EE554 80240964 E4400010 */   swc1     $f0, 0x10($v0)
/* 9EE558 80240968 46001001 */  sub.s     $f0, $f2, $f0
/* 9EE55C 8024096C 3C013F00 */  lui       $at, 0x3f00
/* 9EE560 80240970 44811000 */  mtc1      $at, $f2
/* 9EE564 80240974 00000000 */  nop
/* 9EE568 80240978 46020002 */  mul.s     $f0, $f0, $f2
/* 9EE56C 8024097C 00000000 */  nop
/* 9EE570 80240980 46002000 */  add.s     $f0, $f4, $f0
/* 9EE574 80240984 E4400014 */  swc1      $f0, 0x14($v0)
.L80240988:
/* 9EE578 80240988 C4420018 */  lwc1      $f2, 0x18($v0)
/* 9EE57C 8024098C C4460020 */  lwc1      $f6, 0x20($v0)
/* 9EE580 80240990 46061081 */  sub.s     $f2, $f2, $f6
/* 9EE584 80240994 3C014120 */  lui       $at, 0x4120
/* 9EE588 80240998 44812000 */  mtc1      $at, $f4
/* 9EE58C 8024099C C440001C */  lwc1      $f0, 0x1c($v0)
/* 9EE590 802409A0 46041083 */  div.s     $f2, $f2, $f4
/* 9EE594 802409A4 46020000 */  add.s     $f0, $f0, $f2
/* 9EE598 802409A8 3C018024 */  lui       $at, %hi(D_80246E30_9F4A20)
/* 9EE59C 802409AC D4226E30 */  ldc1      $f2, %lo(D_80246E30_9F4A20)($at)
/* 9EE5A0 802409B0 46000021 */  cvt.d.s   $f0, $f0
/* 9EE5A4 802409B4 46220002 */  mul.d     $f0, $f0, $f2
/* 9EE5A8 802409B8 00000000 */  nop
/* 9EE5AC 802409BC 46200020 */  cvt.s.d   $f0, $f0
/* 9EE5B0 802409C0 46003180 */  add.s     $f6, $f6, $f0
/* 9EE5B4 802409C4 E440001C */  swc1      $f0, 0x1c($v0)
/* 9EE5B8 802409C8 E4460020 */  swc1      $f6, 0x20($v0)
.L802409CC:
/* 9EE5BC 802409CC 3C108024 */  lui       $s0, %hi(D_802413F8_9EEFE8)
/* 9EE5C0 802409D0 261013F8 */  addiu     $s0, $s0, %lo(D_802413F8_9EEFE8)
/* 9EE5C4 802409D4 3C140001 */  lui       $s4, 1
/* 9EE5C8 802409D8 C6000014 */  lwc1      $f0, 0x14($s0)
/* 9EE5CC 802409DC 3C013FE0 */  lui       $at, 0x3fe0
/* 9EE5D0 802409E0 44811800 */  mtc1      $at, $f3
/* 9EE5D4 802409E4 44801000 */  mtc1      $zero, $f2
/* 9EE5D8 802409E8 46000021 */  cvt.d.s   $f0, $f0
/* 9EE5DC 802409EC 46220002 */  mul.d     $f0, $f0, $f2
/* 9EE5E0 802409F0 00000000 */  nop
/* 9EE5E4 802409F4 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 9EE5E8 802409F8 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 9EE5EC 802409FC 36941630 */  ori       $s4, $s4, 0x1630
/* 9EE5F0 80240A00 3C02DE00 */  lui       $v0, 0xde00
/* 9EE5F4 80240A04 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 9EE5F8 80240A08 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 9EE5FC 80240A0C 8E430000 */  lw        $v1, ($s2)
/* 9EE600 80240A10 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 9EE604 80240A14 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 9EE608 80240A18 0060202D */  daddu     $a0, $v1, $zero
/* 9EE60C 80240A1C 46200020 */  cvt.s.d   $f0, $f0
/* 9EE610 80240A20 E6000014 */  swc1      $f0, 0x14($s0)
/* 9EE614 80240A24 AC820000 */  sw        $v0, ($a0)
/* 9EE618 80240A28 3C028024 */  lui       $v0, %hi(D_80241768_9EF358)
/* 9EE61C 80240A2C 24421768 */  addiu     $v0, $v0, %lo(D_80241768_9EF358)
/* 9EE620 80240A30 AC820004 */  sw        $v0, 4($a0)
/* 9EE624 80240A34 8E050000 */  lw        $a1, ($s0)
/* 9EE628 80240A38 8E060004 */  lw        $a2, 4($s0)
/* 9EE62C 80240A3C 8E070008 */  lw        $a3, 8($s0)
/* 9EE630 80240A40 96240000 */  lhu       $a0, ($s1)
/* 9EE634 80240A44 8E620000 */  lw        $v0, ($s3)
/* 9EE638 80240A48 24630008 */  addiu     $v1, $v1, 8
/* 9EE63C 80240A4C AE430000 */  sw        $v1, ($s2)
/* 9EE640 80240A50 00042180 */  sll       $a0, $a0, 6
/* 9EE644 80240A54 00942021 */  addu      $a0, $a0, $s4
/* 9EE648 80240A58 0C019E08 */  jal       guTranslate
/* 9EE64C 80240A5C 00442021 */   addu     $a0, $v0, $a0
/* 9EE650 80240A60 3C02DA38 */  lui       $v0, 0xda38
/* 9EE654 80240A64 34420002 */  ori       $v0, $v0, 2
/* 9EE658 80240A68 8E440000 */  lw        $a0, ($s2)
/* 9EE65C 80240A6C 96250000 */  lhu       $a1, ($s1)
/* 9EE660 80240A70 4480C000 */  mtc1      $zero, $f24
/* 9EE664 80240A74 0080302D */  daddu     $a2, $a0, $zero
/* 9EE668 80240A78 ACC20000 */  sw        $v0, ($a2)
/* 9EE66C 80240A7C 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 9EE670 80240A80 00021180 */  sll       $v0, $v0, 6
/* 9EE674 80240A84 8E630000 */  lw        $v1, ($s3)
/* 9EE678 80240A88 00541021 */  addu      $v0, $v0, $s4
/* 9EE67C 80240A8C 00621821 */  addu      $v1, $v1, $v0
/* 9EE680 80240A90 ACC30004 */  sw        $v1, 4($a2)
/* 9EE684 80240A94 C61C0020 */  lwc1      $f28, 0x20($s0)
/* 9EE688 80240A98 4618E302 */  mul.s     $f12, $f28, $f24
/* 9EE68C 80240A9C 00000000 */  nop
/* 9EE690 80240AA0 3C014334 */  lui       $at, 0x4334
/* 9EE694 80240AA4 4481A000 */  mtc1      $at, $f20
/* 9EE698 80240AA8 3C014049 */  lui       $at, 0x4049
/* 9EE69C 80240AAC 34210FD8 */  ori       $at, $at, 0xfd8
/* 9EE6A0 80240AB0 4481B000 */  mtc1      $at, $f22
/* 9EE6A4 80240AB4 24840008 */  addiu     $a0, $a0, 8
/* 9EE6A8 80240AB8 46146303 */  div.s     $f12, $f12, $f20
/* 9EE6AC 80240ABC 46166302 */  mul.s     $f12, $f12, $f22
/* 9EE6B0 80240AC0 00000000 */  nop
/* 9EE6B4 80240AC4 24A50001 */  addiu     $a1, $a1, 1
/* 9EE6B8 80240AC8 AE440000 */  sw        $a0, ($s2)
/* 9EE6BC 80240ACC A6250000 */  sh        $a1, ($s1)
/* 9EE6C0 80240AD0 C61A0010 */  lwc1      $f26, 0x10($s0)
/* 9EE6C4 80240AD4 0C00A85B */  jal       sin_rad
/* 9EE6C8 80240AD8 24150001 */   addiu    $s5, $zero, 1
/* 9EE6CC 80240ADC C60C0020 */  lwc1      $f12, 0x20($s0)
/* 9EE6D0 80240AE0 46186302 */  mul.s     $f12, $f12, $f24
/* 9EE6D4 80240AE4 00000000 */  nop
/* 9EE6D8 80240AE8 4600D002 */  mul.s     $f0, $f26, $f0
/* 9EE6DC 80240AEC 00000000 */  nop
/* 9EE6E0 80240AF0 46146303 */  div.s     $f12, $f12, $f20
/* 9EE6E4 80240AF4 46166302 */  mul.s     $f12, $f12, $f22
/* 9EE6E8 80240AF8 00000000 */  nop
/* 9EE6EC 80240AFC 0200B02D */  daddu     $s6, $s0, $zero
/* 9EE6F0 80240B00 C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 9EE6F4 80240B04 3C178024 */  lui       $s7, %hi(D_80241748_9EF338)
/* 9EE6F8 80240B08 26F71748 */  addiu     $s7, $s7, %lo(D_80241748_9EF338)
/* 9EE6FC 80240B0C 46007380 */  add.s     $f14, $f14, $f0
/* 9EE700 80240B10 3C100001 */  lui       $s0, 1
/* 9EE704 80240B14 36101630 */  ori       $s0, $s0, 0x1630
/* 9EE708 80240B18 0C00A874 */  jal       cos_rad
/* 9EE70C 80240B1C E7AE0020 */   swc1     $f14, 0x20($sp)
/* 9EE710 80240B20 4600D587 */  neg.s     $f22, $f26
/* 9EE714 80240B24 4405C000 */  mfc1      $a1, $f24
/* 9EE718 80240B28 4406C000 */  mfc1      $a2, $f24
/* 9EE71C 80240B2C 4407E000 */  mfc1      $a3, $f28
/* 9EE720 80240B30 96240000 */  lhu       $a0, ($s1)
/* 9EE724 80240B34 4600B002 */  mul.s     $f0, $f22, $f0
/* 9EE728 80240B38 00000000 */  nop
/* 9EE72C 80240B3C E7B80014 */  swc1      $f24, 0x14($sp)
/* 9EE730 80240B40 E7B60018 */  swc1      $f22, 0x18($sp)
/* 9EE734 80240B44 E7B8001C */  swc1      $f24, 0x1c($sp)
/* 9EE738 80240B48 8E620000 */  lw        $v0, ($s3)
/* 9EE73C 80240B4C 3C013F80 */  lui       $at, 0x3f80
/* 9EE740 80240B50 44811000 */  mtc1      $at, $f2
/* 9EE744 80240B54 00042180 */  sll       $a0, $a0, 6
/* 9EE748 80240B58 00942021 */  addu      $a0, $a0, $s4
/* 9EE74C 80240B5C 00442021 */  addu      $a0, $v0, $a0
/* 9EE750 80240B60 E7A20010 */  swc1      $f2, 0x10($sp)
/* 9EE754 80240B64 0C01903A */  jal       guPosition
/* 9EE758 80240B68 4600F780 */   add.s    $f30, $f30, $f0
/* 9EE75C 80240B6C 3C04DA38 */  lui       $a0, 0xda38
/* 9EE760 80240B70 00952025 */  or        $a0, $a0, $s5
/* 9EE764 80240B74 8E430000 */  lw        $v1, ($s2)
/* 9EE768 80240B78 96220000 */  lhu       $v0, ($s1)
/* 9EE76C 80240B7C 0060282D */  daddu     $a1, $v1, $zero
/* 9EE770 80240B80 24630008 */  addiu     $v1, $v1, 8
/* 9EE774 80240B84 AE430000 */  sw        $v1, ($s2)
/* 9EE778 80240B88 00551821 */  addu      $v1, $v0, $s5
/* 9EE77C 80240B8C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 9EE780 80240B90 00021180 */  sll       $v0, $v0, 6
/* 9EE784 80240B94 ACA40000 */  sw        $a0, ($a1)
/* 9EE788 80240B98 A6230000 */  sh        $v1, ($s1)
/* 9EE78C 80240B9C 8E630000 */  lw        $v1, ($s3)
/* 9EE790 80240BA0 00541021 */  addu      $v0, $v0, $s4
/* 9EE794 80240BA4 00621821 */  addu      $v1, $v1, $v0
/* 9EE798 80240BA8 ACA30004 */  sw        $v1, 4($a1)
.L80240BAC:
/* 9EE79C 80240BAC C6DC0020 */  lwc1      $f28, 0x20($s6)
/* 9EE7A0 80240BB0 4495A000 */  mtc1      $s5, $f20
/* 9EE7A4 80240BB4 00000000 */  nop
/* 9EE7A8 80240BB8 4680A520 */  cvt.s.w   $f20, $f20
/* 9EE7AC 80240BBC 4614E302 */  mul.s     $f12, $f28, $f20
/* 9EE7B0 80240BC0 00000000 */  nop
/* 9EE7B4 80240BC4 3C014334 */  lui       $at, 0x4334
/* 9EE7B8 80240BC8 44817000 */  mtc1      $at, $f14
/* 9EE7BC 80240BCC 00000000 */  nop
/* 9EE7C0 80240BD0 460E6303 */  div.s     $f12, $f12, $f14
/* 9EE7C4 80240BD4 3C014049 */  lui       $at, 0x4049
/* 9EE7C8 80240BD8 34210FD8 */  ori       $at, $at, 0xfd8
/* 9EE7CC 80240BDC 44817000 */  mtc1      $at, $f14
/* 9EE7D0 80240BE0 00000000 */  nop
/* 9EE7D4 80240BE4 460E6302 */  mul.s     $f12, $f12, $f14
/* 9EE7D8 80240BE8 00000000 */  nop
/* 9EE7DC 80240BEC C6D60010 */  lwc1      $f22, 0x10($s6)
/* 9EE7E0 80240BF0 0C00A85B */  jal       sin_rad
/* 9EE7E4 80240BF4 26B50001 */   addiu    $s5, $s5, 1
/* 9EE7E8 80240BF8 C6CC0020 */  lwc1      $f12, 0x20($s6)
/* 9EE7EC 80240BFC 46146302 */  mul.s     $f12, $f12, $f20
/* 9EE7F0 80240C00 00000000 */  nop
/* 9EE7F4 80240C04 4600B002 */  mul.s     $f0, $f22, $f0
/* 9EE7F8 80240C08 00000000 */  nop
/* 9EE7FC 80240C0C 3C014334 */  lui       $at, 0x4334
/* 9EE800 80240C10 44817000 */  mtc1      $at, $f14
/* 9EE804 80240C14 00000000 */  nop
/* 9EE808 80240C18 460E6303 */  div.s     $f12, $f12, $f14
/* 9EE80C 80240C1C 3C014049 */  lui       $at, 0x4049
/* 9EE810 80240C20 34210FD8 */  ori       $at, $at, 0xfd8
/* 9EE814 80240C24 44817000 */  mtc1      $at, $f14
/* 9EE818 80240C28 00000000 */  nop
/* 9EE81C 80240C2C 460E6302 */  mul.s     $f12, $f12, $f14
/* 9EE820 80240C30 00000000 */  nop
/* 9EE824 80240C34 C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 9EE828 80240C38 46007380 */  add.s     $f14, $f14, $f0
/* 9EE82C 80240C3C 4600B587 */  neg.s     $f22, $f22
/* 9EE830 80240C40 0C00A874 */  jal       cos_rad
/* 9EE834 80240C44 E7AE0020 */   swc1     $f14, 0x20($sp)
/* 9EE838 80240C48 3C090100 */  lui       $t1, 0x100
/* 9EE83C 80240C4C 35292004 */  ori       $t1, $t1, 0x2004
/* 9EE840 80240C50 4600B002 */  mul.s     $f0, $f22, $f0
/* 9EE844 80240C54 00000000 */  nop
/* 9EE848 80240C58 8E430000 */  lw        $v1, ($s2)
/* 9EE84C 80240C5C 4405C000 */  mfc1      $a1, $f24
/* 9EE850 80240C60 4406C000 */  mfc1      $a2, $f24
/* 9EE854 80240C64 4407E000 */  mfc1      $a3, $f28
/* 9EE858 80240C68 96240000 */  lhu       $a0, ($s1)
/* 9EE85C 80240C6C 8E620000 */  lw        $v0, ($s3)
/* 9EE860 80240C70 3C013F80 */  lui       $at, 0x3f80
/* 9EE864 80240C74 44811000 */  mtc1      $at, $f2
/* 9EE868 80240C78 0060402D */  daddu     $t0, $v1, $zero
/* 9EE86C 80240C7C 24630008 */  addiu     $v1, $v1, 8
/* 9EE870 80240C80 00042180 */  sll       $a0, $a0, 6
/* 9EE874 80240C84 00902021 */  addu      $a0, $a0, $s0
/* 9EE878 80240C88 00442021 */  addu      $a0, $v0, $a0
/* 9EE87C 80240C8C AE430000 */  sw        $v1, ($s2)
/* 9EE880 80240C90 AD090000 */  sw        $t1, ($t0)
/* 9EE884 80240C94 AD170004 */  sw        $s7, 4($t0)
/* 9EE888 80240C98 E7A20010 */  swc1      $f2, 0x10($sp)
/* 9EE88C 80240C9C E7B80014 */  swc1      $f24, 0x14($sp)
/* 9EE890 80240CA0 E7B60018 */  swc1      $f22, 0x18($sp)
/* 9EE894 80240CA4 E7B8001C */  swc1      $f24, 0x1c($sp)
/* 9EE898 80240CA8 0C01903A */  jal       guPosition
/* 9EE89C 80240CAC 4600F780 */   add.s    $f30, $f30, $f0
/* 9EE8A0 80240CB0 3C02DA38 */  lui       $v0, 0xda38
/* 9EE8A4 80240CB4 34420001 */  ori       $v0, $v0, 1
/* 9EE8A8 80240CB8 3C060100 */  lui       $a2, 0x100
/* 9EE8AC 80240CBC 34C62008 */  ori       $a2, $a2, 0x2008
/* 9EE8B0 80240CC0 3C080600 */  lui       $t0, 0x600
/* 9EE8B4 80240CC4 35080402 */  ori       $t0, $t0, 0x402
/* 9EE8B8 80240CC8 3C070004 */  lui       $a3, 4
/* 9EE8BC 80240CCC 34E70602 */  ori       $a3, $a3, 0x602
/* 9EE8C0 80240CD0 8E440000 */  lw        $a0, ($s2)
/* 9EE8C4 80240CD4 96230000 */  lhu       $v1, ($s1)
/* 9EE8C8 80240CD8 0080282D */  daddu     $a1, $a0, $zero
/* 9EE8CC 80240CDC 24840008 */  addiu     $a0, $a0, 8
/* 9EE8D0 80240CE0 AE440000 */  sw        $a0, ($s2)
/* 9EE8D4 80240CE4 ACA20000 */  sw        $v0, ($a1)
/* 9EE8D8 80240CE8 24620001 */  addiu     $v0, $v1, 1
/* 9EE8DC 80240CEC 3063FFFF */  andi      $v1, $v1, 0xffff
/* 9EE8E0 80240CF0 00031980 */  sll       $v1, $v1, 6
/* 9EE8E4 80240CF4 A6220000 */  sh        $v0, ($s1)
/* 9EE8E8 80240CF8 8E620000 */  lw        $v0, ($s3)
/* 9EE8EC 80240CFC 00701821 */  addu      $v1, $v1, $s0
/* 9EE8F0 80240D00 00431021 */  addu      $v0, $v0, $v1
/* 9EE8F4 80240D04 ACA20004 */  sw        $v0, 4($a1)
/* 9EE8F8 80240D08 24820008 */  addiu     $v0, $a0, 8
/* 9EE8FC 80240D0C AE420000 */  sw        $v0, ($s2)
/* 9EE900 80240D10 24820010 */  addiu     $v0, $a0, 0x10
/* 9EE904 80240D14 AC860000 */  sw        $a2, ($a0)
/* 9EE908 80240D18 AC970004 */  sw        $s7, 4($a0)
/* 9EE90C 80240D1C AE420000 */  sw        $v0, ($s2)
/* 9EE910 80240D20 2AA20010 */  slti      $v0, $s5, 0x10
/* 9EE914 80240D24 AC880008 */  sw        $t0, 8($a0)
/* 9EE918 80240D28 1440FFA0 */  bnez      $v0, .L80240BAC
/* 9EE91C 80240D2C AC87000C */   sw       $a3, 0xc($a0)
/* 9EE920 80240D30 3C03D838 */  lui       $v1, 0xd838
/* 9EE924 80240D34 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 9EE928 80240D38 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 9EE92C 80240D3C 8CA20000 */  lw        $v0, ($a1)
/* 9EE930 80240D40 34630002 */  ori       $v1, $v1, 2
/* 9EE934 80240D44 0040202D */  daddu     $a0, $v0, $zero
/* 9EE938 80240D48 24420008 */  addiu     $v0, $v0, 8
/* 9EE93C 80240D4C ACA20000 */  sw        $v0, ($a1)
/* 9EE940 80240D50 AC830000 */  sw        $v1, ($a0)
/* 9EE944 80240D54 24030040 */  addiu     $v1, $zero, 0x40
/* 9EE948 80240D58 AC830004 */  sw        $v1, 4($a0)
/* 9EE94C 80240D5C 3C03E700 */  lui       $v1, 0xe700
/* 9EE950 80240D60 AC430000 */  sw        $v1, ($v0)
/* 9EE954 80240D64 3C038024 */  lui       $v1, %hi(D_802413F8_9EEFE8)
/* 9EE958 80240D68 246313F8 */  addiu     $v1, $v1, %lo(D_802413F8_9EEFE8)
/* 9EE95C 80240D6C AC400004 */  sw        $zero, 4($v0)
/* 9EE960 80240D70 8C640040 */  lw        $a0, 0x40($v1)
/* 9EE964 80240D74 24420008 */  addiu     $v0, $v0, 8
/* 9EE968 80240D78 ACA20000 */  sw        $v0, ($a1)
/* 9EE96C 80240D7C C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 9EE970 80240D80 E47E0028 */  swc1      $f30, 0x28($v1)
/* 9EE974 80240D84 E46E0024 */  swc1      $f14, 0x24($v1)
/* 9EE978 80240D88 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 9EE97C 80240D8C 1080000E */  beqz      $a0, .L80240DC8
/* 9EE980 80240D90 E46E002C */   swc1     $f14, 0x2c($v1)
/* 9EE984 80240D94 3C014080 */  lui       $at, 0x4080
/* 9EE988 80240D98 44811000 */  mtc1      $at, $f2
/* 9EE98C 80240D9C C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 9EE990 80240DA0 3C0140C0 */  lui       $at, 0x40c0
/* 9EE994 80240DA4 44810000 */  mtc1      $at, $f0
/* 9EE998 80240DA8 4602F081 */  sub.s     $f2, $f30, $f2
/* 9EE99C 80240DAC E48E0038 */  swc1      $f14, 0x38($a0)
/* 9EE9A0 80240DB0 8C620040 */  lw        $v0, 0x40($v1)
/* 9EE9A4 80240DB4 E442003C */  swc1      $f2, 0x3c($v0)
/* 9EE9A8 80240DB8 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 9EE9AC 80240DBC 46007000 */  add.s     $f0, $f14, $f0
/* 9EE9B0 80240DC0 8C620040 */  lw        $v0, 0x40($v1)
/* 9EE9B4 80240DC4 E4400040 */  swc1      $f0, 0x40($v0)
.L80240DC8:
/* 9EE9B8 80240DC8 8C620044 */  lw        $v0, 0x44($v1)
/* 9EE9BC 80240DCC 1040000E */  beqz      $v0, .L80240E08
/* 9EE9C0 80240DD0 00000000 */   nop
/* 9EE9C4 80240DD4 3C014080 */  lui       $at, 0x4080
/* 9EE9C8 80240DD8 44811000 */  mtc1      $at, $f2
/* 9EE9CC 80240DDC C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 9EE9D0 80240DE0 3C014040 */  lui       $at, 0x4040
/* 9EE9D4 80240DE4 44810000 */  mtc1      $at, $f0
/* 9EE9D8 80240DE8 4602F081 */  sub.s     $f2, $f30, $f2
/* 9EE9DC 80240DEC E44E0038 */  swc1      $f14, 0x38($v0)
/* 9EE9E0 80240DF0 8C620044 */  lw        $v0, 0x44($v1)
/* 9EE9E4 80240DF4 E442003C */  swc1      $f2, 0x3c($v0)
/* 9EE9E8 80240DF8 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 9EE9EC 80240DFC 46007000 */  add.s     $f0, $f14, $f0
/* 9EE9F0 80240E00 8C620044 */  lw        $v0, 0x44($v1)
/* 9EE9F4 80240E04 E4400040 */  swc1      $f0, 0x40($v0)
.L80240E08:
/* 9EE9F8 80240E08 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9EE9FC 80240E0C 8FB70044 */  lw        $s7, 0x44($sp)
/* 9EEA00 80240E10 8FB60040 */  lw        $s6, 0x40($sp)
/* 9EEA04 80240E14 8FB5003C */  lw        $s5, 0x3c($sp)
/* 9EEA08 80240E18 8FB40038 */  lw        $s4, 0x38($sp)
/* 9EEA0C 80240E1C 8FB30034 */  lw        $s3, 0x34($sp)
/* 9EEA10 80240E20 8FB20030 */  lw        $s2, 0x30($sp)
/* 9EEA14 80240E24 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9EEA18 80240E28 8FB00028 */  lw        $s0, 0x28($sp)
/* 9EEA1C 80240E2C D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 9EEA20 80240E30 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 9EEA24 80240E34 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 9EEA28 80240E38 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 9EEA2C 80240E3C D7B60058 */  ldc1      $f22, 0x58($sp)
/* 9EEA30 80240E40 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 9EEA34 80240E44 03E00008 */  jr        $ra
/* 9EEA38 80240E48 27BD0080 */   addiu    $sp, $sp, 0x80
