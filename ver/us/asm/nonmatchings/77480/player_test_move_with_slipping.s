.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel player_test_move_with_slipping
/* 78910 800DF460 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 78914 800DF464 AFB40078 */  sw        $s4, 0x78($sp)
/* 78918 800DF468 0080A02D */  daddu     $s4, $a0, $zero
/* 7891C 800DF46C AFB1006C */  sw        $s1, 0x6c($sp)
/* 78920 800DF470 00A0882D */  daddu     $s1, $a1, $zero
/* 78924 800DF474 AFB5007C */  sw        $s5, 0x7c($sp)
/* 78928 800DF478 00C0A82D */  daddu     $s5, $a2, $zero
/* 7892C 800DF47C AFB20070 */  sw        $s2, 0x70($sp)
/* 78930 800DF480 00E0902D */  daddu     $s2, $a3, $zero
/* 78934 800DF484 AFB30074 */  sw        $s3, 0x74($sp)
/* 78938 800DF488 AFBF0080 */  sw        $ra, 0x80($sp)
/* 7893C 800DF48C AFB00068 */  sw        $s0, 0x68($sp)
/* 78940 800DF490 F7BE00B0 */  sdc1      $f30, 0xb0($sp)
/* 78944 800DF494 F7BC00A8 */  sdc1      $f28, 0xa8($sp)
/* 78948 800DF498 F7BA00A0 */  sdc1      $f26, 0xa0($sp)
/* 7894C 800DF49C F7B80098 */  sdc1      $f24, 0x98($sp)
/* 78950 800DF4A0 F7B60090 */  sdc1      $f22, 0x90($sp)
/* 78954 800DF4A4 F7B40088 */  sdc1      $f20, 0x88($sp)
/* 78958 800DF4A8 8E820000 */  lw        $v0, ($s4)
/* 7895C 800DF4AC 4480A000 */  mtc1      $zero, $f20
/* 78960 800DF4B0 C7BC00C8 */  lwc1      $f28, 0xc8($sp)
/* 78964 800DF4B4 30420006 */  andi      $v0, $v0, 6
/* 78968 800DF4B8 14400004 */  bnez      $v0, .L800DF4CC
/* 7896C 800DF4BC 2413FFFF */   addiu    $s3, $zero, -1
/* 78970 800DF4C0 3C014120 */  lui       $at, 0x4120
/* 78974 800DF4C4 342128F6 */  ori       $at, $at, 0x28f6
/* 78978 800DF4C8 4481A000 */  mtc1      $at, $f20
.L800DF4CC:
/* 7897C 800DF4CC 27A50038 */  addiu     $a1, $sp, 0x38
/* 78980 800DF4D0 3C0140C9 */  lui       $at, 0x40c9
/* 78984 800DF4D4 34210FD0 */  ori       $at, $at, 0xfd0
/* 78988 800DF4D8 44810000 */  mtc1      $at, $f0
/* 7898C 800DF4DC C7A400CC */  lwc1      $f4, 0xcc($sp)
/* 78990 800DF4E0 27A6003C */  addiu     $a2, $sp, 0x3c
/* 78994 800DF4E4 46002102 */  mul.s     $f4, $f4, $f0
/* 78998 800DF4E8 00000000 */  nop
/* 7899C 800DF4EC 868200B2 */  lh        $v0, 0xb2($s4)
/* 789A0 800DF4F0 3C013F00 */  lui       $at, 0x3f00
/* 789A4 800DF4F4 44811000 */  mtc1      $at, $f2
/* 789A8 800DF4F8 3C0143B4 */  lui       $at, 0x43b4
/* 789AC 800DF4FC 44816000 */  mtc1      $at, $f12
/* 789B0 800DF500 44820000 */  mtc1      $v0, $f0
/* 789B4 800DF504 00000000 */  nop
/* 789B8 800DF508 46800020 */  cvt.s.w   $f0, $f0
/* 789BC 800DF50C 46020782 */  mul.s     $f30, $f0, $f2
/* 789C0 800DF510 00000000 */  nop
/* 789C4 800DF514 0C00A82D */  jal       sin_cos_rad
/* 789C8 800DF518 460C2303 */   div.s    $f12, $f4, $f12
/* 789CC 800DF51C 27A20040 */  addiu     $v0, $sp, 0x40
/* 789D0 800DF520 461EE580 */  add.s     $f22, $f28, $f30
/* 789D4 800DF524 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 789D8 800DF528 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 789DC 800DF52C 46000007 */  neg.s     $f0, $f0
/* 789E0 800DF530 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 789E4 800DF534 E7B6004C */  swc1      $f22, 0x4c($sp)
/* 789E8 800DF538 C6A40000 */  lwc1      $f4, ($s5)
/* 789EC 800DF53C 4602E682 */  mul.s     $f26, $f28, $f2
/* 789F0 800DF540 00000000 */  nop
/* 789F4 800DF544 AFA2001C */  sw        $v0, 0x1c($sp)
/* 789F8 800DF548 27A20044 */  addiu     $v0, $sp, 0x44
/* 789FC 800DF54C AFA20020 */  sw        $v0, 0x20($sp)
/* 78A00 800DF550 27A20048 */  addiu     $v0, $sp, 0x48
/* 78A04 800DF554 AFA20024 */  sw        $v0, 0x24($sp)
/* 78A08 800DF558 27A2004C */  addiu     $v0, $sp, 0x4c
/* 78A0C 800DF55C AFA20028 */  sw        $v0, 0x28($sp)
/* 78A10 800DF560 27A20050 */  addiu     $v0, $sp, 0x50
/* 78A14 800DF564 AFA2002C */  sw        $v0, 0x2c($sp)
/* 78A18 800DF568 27A20054 */  addiu     $v0, $sp, 0x54
/* 78A1C 800DF56C AFA20030 */  sw        $v0, 0x30($sp)
/* 78A20 800DF570 27A20058 */  addiu     $v0, $sp, 0x58
/* 78A24 800DF574 E7A20010 */  swc1      $f2, 0x10($sp)
/* 78A28 800DF578 AFA00014 */  sw        $zero, 0x14($sp)
/* 78A2C 800DF57C E7A00018 */  swc1      $f0, 0x18($sp)
/* 78A30 800DF580 AFA20034 */  sw        $v0, 0x34($sp)
/* 78A34 800DF584 46142100 */  add.s     $f4, $f4, $f20
/* 78A38 800DF588 8E250000 */  lw        $a1, ($s1)
/* 78A3C 800DF58C 8E470000 */  lw        $a3, ($s2)
/* 78A40 800DF590 44062000 */  mfc1      $a2, $f4
/* 78A44 800DF594 4600E602 */  mul.s     $f24, $f28, $f0
/* 78A48 800DF598 00000000 */  nop
/* 78A4C 800DF59C 0C037B97 */  jal       player_raycast_general
/* 78A50 800DF5A0 0000202D */   daddu    $a0, $zero, $zero
/* 78A54 800DF5A4 0040802D */  daddu     $s0, $v0, $zero
/* 78A58 800DF5A8 06000008 */  bltz      $s0, .L800DF5CC
/* 78A5C 800DF5AC 00000000 */   nop
/* 78A60 800DF5B0 C7A4004C */  lwc1      $f4, 0x4c($sp)
/* 78A64 800DF5B4 4616203E */  c.le.s    $f4, $f22
/* 78A68 800DF5B8 00000000 */  nop
/* 78A6C 800DF5BC 45000003 */  bc1f      .L800DF5CC
/* 78A70 800DF5C0 27A4005C */   addiu    $a0, $sp, 0x5c
/* 78A74 800DF5C4 08037DA1 */  j         .L800DF684
/* 78A78 800DF5C8 46162101 */   sub.s    $f4, $f4, $f22
.L800DF5CC:
/* 78A7C 800DF5CC 868300B0 */  lh        $v1, 0xb0($s4)
/* 78A80 800DF5D0 C6A60000 */  lwc1      $f6, ($s5)
/* 78A84 800DF5D4 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 78A88 800DF5D8 AFA00014 */  sw        $zero, 0x14($sp)
/* 78A8C 800DF5DC E7A00010 */  swc1      $f0, 0x10($sp)
/* 78A90 800DF5E0 C7A4003C */  lwc1      $f4, 0x3c($sp)
/* 78A94 800DF5E4 27A20040 */  addiu     $v0, $sp, 0x40
/* 78A98 800DF5E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 78A9C 800DF5EC 27A20044 */  addiu     $v0, $sp, 0x44
/* 78AA0 800DF5F0 AFA20020 */  sw        $v0, 0x20($sp)
/* 78AA4 800DF5F4 27A20048 */  addiu     $v0, $sp, 0x48
/* 78AA8 800DF5F8 AFA20024 */  sw        $v0, 0x24($sp)
/* 78AAC 800DF5FC 27A2004C */  addiu     $v0, $sp, 0x4c
/* 78AB0 800DF600 3C013FE8 */  lui       $at, 0x3fe8
/* 78AB4 800DF604 44810800 */  mtc1      $at, $f1
/* 78AB8 800DF608 44800000 */  mtc1      $zero, $f0
/* 78ABC 800DF60C 44831000 */  mtc1      $v1, $f2
/* 78AC0 800DF610 00000000 */  nop
/* 78AC4 800DF614 468010A1 */  cvt.d.w   $f2, $f2
/* 78AC8 800DF618 AFA20028 */  sw        $v0, 0x28($sp)
/* 78ACC 800DF61C 46201082 */  mul.d     $f2, $f2, $f0
/* 78AD0 800DF620 00000000 */  nop
/* 78AD4 800DF624 27A20050 */  addiu     $v0, $sp, 0x50
/* 78AD8 800DF628 AFA2002C */  sw        $v0, 0x2c($sp)
/* 78ADC 800DF62C 27A20054 */  addiu     $v0, $sp, 0x54
/* 78AE0 800DF630 AFA20030 */  sw        $v0, 0x30($sp)
/* 78AE4 800DF634 27A20058 */  addiu     $v0, $sp, 0x58
/* 78AE8 800DF638 AFA20034 */  sw        $v0, 0x34($sp)
/* 78AEC 800DF63C E7A40018 */  swc1      $f4, 0x18($sp)
/* 78AF0 800DF640 46201520 */  cvt.s.d   $f20, $f2
/* 78AF4 800DF644 46143180 */  add.s     $f6, $f6, $f20
/* 78AF8 800DF648 8E250000 */  lw        $a1, ($s1)
/* 78AFC 800DF64C 8E470000 */  lw        $a3, ($s2)
/* 78B00 800DF650 44063000 */  mfc1      $a2, $f6
/* 78B04 800DF654 0C037B97 */  jal       player_raycast_general
/* 78B08 800DF658 0000202D */   daddu    $a0, $zero, $zero
/* 78B0C 800DF65C 0040802D */  daddu     $s0, $v0, $zero
/* 78B10 800DF660 06000021 */  bltz      $s0, .L800DF6E8
/* 78B14 800DF664 00000000 */   nop
/* 78B18 800DF668 461EE000 */  add.s     $f0, $f28, $f30
/* 78B1C 800DF66C C7A4004C */  lwc1      $f4, 0x4c($sp)
/* 78B20 800DF670 4600203E */  c.le.s    $f4, $f0
/* 78B24 800DF674 00000000 */  nop
/* 78B28 800DF678 4500001B */  bc1f      .L800DF6E8
/* 78B2C 800DF67C 27A4005C */   addiu    $a0, $sp, 0x5c
/* 78B30 800DF680 46002101 */  sub.s     $f4, $f4, $f0
.L800DF684:
/* 78B34 800DF684 4406D000 */  mfc1      $a2, $f26
/* 78B38 800DF688 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 78B3C 800DF68C 4407C000 */  mfc1      $a3, $f24
/* 78B40 800DF690 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 78B44 800DF694 46002582 */  mul.s     $f22, $f4, $f0
/* 78B48 800DF698 00000000 */  nop
/* 78B4C 800DF69C C7A00050 */  lwc1      $f0, 0x50($sp)
/* 78B50 800DF6A0 27A50060 */  addiu     $a1, $sp, 0x60
/* 78B54 800DF6A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 78B58 800DF6A8 C7A00058 */  lwc1      $f0, 0x58($sp)
/* 78B5C 800DF6AC 46022502 */  mul.s     $f20, $f4, $f2
/* 78B60 800DF6B0 00000000 */  nop
/* 78B64 800DF6B4 0C037CFF */  jal       player_get_slip_vector
/* 78B68 800DF6B8 E7A00014 */   swc1     $f0, 0x14($sp)
/* 78B6C 800DF6BC C7A2005C */  lwc1      $f2, 0x5c($sp)
/* 78B70 800DF6C0 4602B080 */  add.s     $f2, $f22, $f2
/* 78B74 800DF6C4 C6200000 */  lwc1      $f0, ($s1)
/* 78B78 800DF6C8 46020000 */  add.s     $f0, $f0, $f2
/* 78B7C 800DF6CC E6200000 */  swc1      $f0, ($s1)
/* 78B80 800DF6D0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 78B84 800DF6D4 4600A000 */  add.s     $f0, $f20, $f0
/* 78B88 800DF6D8 C6420000 */  lwc1      $f2, ($s2)
/* 78B8C 800DF6DC 46001080 */  add.s     $f2, $f2, $f0
/* 78B90 800DF6E0 0200982D */  daddu     $s3, $s0, $zero
/* 78B94 800DF6E4 E6420000 */  swc1      $f2, ($s2)
.L800DF6E8:
/* 78B98 800DF6E8 C6200000 */  lwc1      $f0, ($s1)
/* 78B9C 800DF6EC 461A0000 */  add.s     $f0, $f0, $f26
/* 78BA0 800DF6F0 E6200000 */  swc1      $f0, ($s1)
/* 78BA4 800DF6F4 C6400000 */  lwc1      $f0, ($s2)
/* 78BA8 800DF6F8 46180000 */  add.s     $f0, $f0, $f24
/* 78BAC 800DF6FC 0260102D */  daddu     $v0, $s3, $zero
/* 78BB0 800DF700 E6400000 */  swc1      $f0, ($s2)
/* 78BB4 800DF704 8FBF0080 */  lw        $ra, 0x80($sp)
/* 78BB8 800DF708 8FB5007C */  lw        $s5, 0x7c($sp)
/* 78BBC 800DF70C 8FB40078 */  lw        $s4, 0x78($sp)
/* 78BC0 800DF710 8FB30074 */  lw        $s3, 0x74($sp)
/* 78BC4 800DF714 8FB20070 */  lw        $s2, 0x70($sp)
/* 78BC8 800DF718 8FB1006C */  lw        $s1, 0x6c($sp)
/* 78BCC 800DF71C 8FB00068 */  lw        $s0, 0x68($sp)
/* 78BD0 800DF720 D7BE00B0 */  ldc1      $f30, 0xb0($sp)
/* 78BD4 800DF724 D7BC00A8 */  ldc1      $f28, 0xa8($sp)
/* 78BD8 800DF728 D7BA00A0 */  ldc1      $f26, 0xa0($sp)
/* 78BDC 800DF72C D7B80098 */  ldc1      $f24, 0x98($sp)
/* 78BE0 800DF730 D7B60090 */  ldc1      $f22, 0x90($sp)
/* 78BE4 800DF734 D7B40088 */  ldc1      $f20, 0x88($sp)
/* 78BE8 800DF738 03E00008 */  jr        $ra
/* 78BEC 800DF73C 27BD00B8 */   addiu    $sp, $sp, 0xb8
