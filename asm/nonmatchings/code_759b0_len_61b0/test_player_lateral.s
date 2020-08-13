.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel test_player_lateral
/* 078910 800DF460 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 078914 800DF464 AFB40078 */  sw    $s4, 0x78($sp)
/* 078918 800DF468 0080A02D */  daddu $s4, $a0, $zero
/* 07891C 800DF46C AFB1006C */  sw    $s1, 0x6c($sp)
/* 078920 800DF470 00A0882D */  daddu $s1, $a1, $zero
/* 078924 800DF474 AFB5007C */  sw    $s5, 0x7c($sp)
/* 078928 800DF478 00C0A82D */  daddu $s5, $a2, $zero
/* 07892C 800DF47C AFB20070 */  sw    $s2, 0x70($sp)
/* 078930 800DF480 00E0902D */  daddu $s2, $a3, $zero
/* 078934 800DF484 AFB30074 */  sw    $s3, 0x74($sp)
/* 078938 800DF488 AFBF0080 */  sw    $ra, 0x80($sp)
/* 07893C 800DF48C AFB00068 */  sw    $s0, 0x68($sp)
/* 078940 800DF490 F7BE00B0 */  sdc1  $f30, 0xb0($sp)
/* 078944 800DF494 F7BC00A8 */  sdc1  $f28, 0xa8($sp)
/* 078948 800DF498 F7BA00A0 */  sdc1  $f26, 0xa0($sp)
/* 07894C 800DF49C F7B80098 */  sdc1  $f24, 0x98($sp)
/* 078950 800DF4A0 F7B60090 */  sdc1  $f22, 0x90($sp)
/* 078954 800DF4A4 F7B40088 */  sdc1  $f20, 0x88($sp)
/* 078958 800DF4A8 8E820000 */  lw    $v0, ($s4)
/* 07895C 800DF4AC 4480A000 */  mtc1  $zero, $f20
/* 078960 800DF4B0 C7BC00C8 */  lwc1  $f28, 0xc8($sp)
/* 078964 800DF4B4 30420006 */  andi  $v0, $v0, 6
/* 078968 800DF4B8 14400004 */  bnez  $v0, .L800DF4CC
/* 07896C 800DF4BC 2413FFFF */   addiu $s3, $zero, -1
/* 078970 800DF4C0 3C014120 */  lui   $at, 0x4120
/* 078974 800DF4C4 342128F6 */  ori   $at, $at, 0x28f6
/* 078978 800DF4C8 4481A000 */  mtc1  $at, $f20
.L800DF4CC:
/* 07897C 800DF4CC 27A50038 */  addiu $a1, $sp, 0x38
/* 078980 800DF4D0 3C0140C9 */  lui   $at, 0x40c9
/* 078984 800DF4D4 34210FD0 */  ori   $at, $at, 0xfd0
/* 078988 800DF4D8 44810000 */  mtc1  $at, $f0
/* 07898C 800DF4DC C7A400CC */  lwc1  $f4, 0xcc($sp)
/* 078990 800DF4E0 27A6003C */  addiu $a2, $sp, 0x3c
/* 078994 800DF4E4 46002102 */  mul.s $f4, $f4, $f0
/* 078998 800DF4E8 00000000 */  nop   
/* 07899C 800DF4EC 868200B2 */  lh    $v0, 0xb2($s4)
/* 0789A0 800DF4F0 3C013F00 */  lui   $at, 0x3f00
/* 0789A4 800DF4F4 44811000 */  mtc1  $at, $f2
/* 0789A8 800DF4F8 3C0143B4 */  lui   $at, 0x43b4
/* 0789AC 800DF4FC 44816000 */  mtc1  $at, $f12
/* 0789B0 800DF500 44820000 */  mtc1  $v0, $f0
/* 0789B4 800DF504 00000000 */  nop   
/* 0789B8 800DF508 46800020 */  cvt.s.w $f0, $f0
/* 0789BC 800DF50C 46020782 */  mul.s $f30, $f0, $f2
/* 0789C0 800DF510 00000000 */  nop   
/* 0789C4 800DF514 0C00A82D */  jal   sin_cos_rad
/* 0789C8 800DF518 460C2303 */   div.s $f12, $f4, $f12
/* 0789CC 800DF51C 27A20040 */  addiu $v0, $sp, 0x40
/* 0789D0 800DF520 461EE580 */  add.s $f22, $f28, $f30
/* 0789D4 800DF524 C7A0003C */  lwc1  $f0, 0x3c($sp)
/* 0789D8 800DF528 C7A20038 */  lwc1  $f2, 0x38($sp)
/* 0789DC 800DF52C 46000007 */  neg.s $f0, $f0
/* 0789E0 800DF530 E7A0003C */  swc1  $f0, 0x3c($sp)
/* 0789E4 800DF534 E7B6004C */  swc1  $f22, 0x4c($sp)
/* 0789E8 800DF538 C6A40000 */  lwc1  $f4, ($s5)
/* 0789EC 800DF53C 4602E682 */  mul.s $f26, $f28, $f2
/* 0789F0 800DF540 00000000 */  nop   
/* 0789F4 800DF544 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0789F8 800DF548 27A20044 */  addiu $v0, $sp, 0x44
/* 0789FC 800DF54C AFA20020 */  sw    $v0, 0x20($sp)
/* 078A00 800DF550 27A20048 */  addiu $v0, $sp, 0x48
/* 078A04 800DF554 AFA20024 */  sw    $v0, 0x24($sp)
/* 078A08 800DF558 27A2004C */  addiu $v0, $sp, 0x4c
/* 078A0C 800DF55C AFA20028 */  sw    $v0, 0x28($sp)
/* 078A10 800DF560 27A20050 */  addiu $v0, $sp, 0x50
/* 078A14 800DF564 AFA2002C */  sw    $v0, 0x2c($sp)
/* 078A18 800DF568 27A20054 */  addiu $v0, $sp, 0x54
/* 078A1C 800DF56C AFA20030 */  sw    $v0, 0x30($sp)
/* 078A20 800DF570 27A20058 */  addiu $v0, $sp, 0x58
/* 078A24 800DF574 E7A20010 */  swc1  $f2, 0x10($sp)
/* 078A28 800DF578 AFA00014 */  sw    $zero, 0x14($sp)
/* 078A2C 800DF57C E7A00018 */  swc1  $f0, 0x18($sp)
/* 078A30 800DF580 AFA20034 */  sw    $v0, 0x34($sp)
/* 078A34 800DF584 46142100 */  add.s $f4, $f4, $f20
/* 078A38 800DF588 8E250000 */  lw    $a1, ($s1)
/* 078A3C 800DF58C 8E470000 */  lw    $a3, ($s2)
/* 078A40 800DF590 44062000 */  mfc1  $a2, $f4
/* 078A44 800DF594 4600E602 */  mul.s $f24, $f28, $f0
/* 078A48 800DF598 00000000 */  nop   
/* 078A4C 800DF59C 0C037B97 */  jal   func_800DEE5C
/* 078A50 800DF5A0 0000202D */   daddu $a0, $zero, $zero
/* 078A54 800DF5A4 0040802D */  daddu $s0, $v0, $zero
/* 078A58 800DF5A8 06000008 */  bltz  $s0, .L800DF5CC
/* 078A5C 800DF5AC 00000000 */   nop   
/* 078A60 800DF5B0 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 078A64 800DF5B4 4616203E */  c.le.s $f4, $f22
/* 078A68 800DF5B8 00000000 */  nop   
/* 078A6C 800DF5BC 45000003 */  bc1f  .L800DF5CC
/* 078A70 800DF5C0 27A4005C */   addiu $a0, $sp, 0x5c
/* 078A74 800DF5C4 08037DA1 */  j     .L800DF684
/* 078A78 800DF5C8 46162101 */   sub.s $f4, $f4, $f22

.L800DF5CC:
/* 078A7C 800DF5CC 868300B0 */  lh    $v1, 0xb0($s4)
/* 078A80 800DF5D0 C6A60000 */  lwc1  $f6, ($s5)
/* 078A84 800DF5D4 C7A00038 */  lwc1  $f0, 0x38($sp)
/* 078A88 800DF5D8 AFA00014 */  sw    $zero, 0x14($sp)
/* 078A8C 800DF5DC E7A00010 */  swc1  $f0, 0x10($sp)
/* 078A90 800DF5E0 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 078A94 800DF5E4 27A20040 */  addiu $v0, $sp, 0x40
/* 078A98 800DF5E8 AFA2001C */  sw    $v0, 0x1c($sp)
/* 078A9C 800DF5EC 27A20044 */  addiu $v0, $sp, 0x44
/* 078AA0 800DF5F0 AFA20020 */  sw    $v0, 0x20($sp)
/* 078AA4 800DF5F4 27A20048 */  addiu $v0, $sp, 0x48
/* 078AA8 800DF5F8 AFA20024 */  sw    $v0, 0x24($sp)
/* 078AAC 800DF5FC 27A2004C */  addiu $v0, $sp, 0x4c
/* 078AB0 800DF600 3C013FE8 */  lui   $at, 0x3fe8
/* 078AB4 800DF604 44810800 */  mtc1  $at, $f1
/* 078AB8 800DF608 44800000 */  mtc1  $zero, $f0
/* 078ABC 800DF60C 44831000 */  mtc1  $v1, $f2
/* 078AC0 800DF610 00000000 */  nop   
/* 078AC4 800DF614 468010A1 */  cvt.d.w $f2, $f2
/* 078AC8 800DF618 AFA20028 */  sw    $v0, 0x28($sp)
/* 078ACC 800DF61C 46201082 */  mul.d $f2, $f2, $f0
/* 078AD0 800DF620 00000000 */  nop   
/* 078AD4 800DF624 27A20050 */  addiu $v0, $sp, 0x50
/* 078AD8 800DF628 AFA2002C */  sw    $v0, 0x2c($sp)
/* 078ADC 800DF62C 27A20054 */  addiu $v0, $sp, 0x54
/* 078AE0 800DF630 AFA20030 */  sw    $v0, 0x30($sp)
/* 078AE4 800DF634 27A20058 */  addiu $v0, $sp, 0x58
/* 078AE8 800DF638 AFA20034 */  sw    $v0, 0x34($sp)
/* 078AEC 800DF63C E7A40018 */  swc1  $f4, 0x18($sp)
/* 078AF0 800DF640 46201520 */  cvt.s.d $f20, $f2
/* 078AF4 800DF644 46143180 */  add.s $f6, $f6, $f20
/* 078AF8 800DF648 8E250000 */  lw    $a1, ($s1)
/* 078AFC 800DF64C 8E470000 */  lw    $a3, ($s2)
/* 078B00 800DF650 44063000 */  mfc1  $a2, $f6
/* 078B04 800DF654 0C037B97 */  jal   func_800DEE5C
/* 078B08 800DF658 0000202D */   daddu $a0, $zero, $zero
/* 078B0C 800DF65C 0040802D */  daddu $s0, $v0, $zero
/* 078B10 800DF660 06000021 */  bltz  $s0, .L800DF6E8
/* 078B14 800DF664 00000000 */   nop   
/* 078B18 800DF668 461EE000 */  add.s $f0, $f28, $f30
/* 078B1C 800DF66C C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 078B20 800DF670 4600203E */  c.le.s $f4, $f0
/* 078B24 800DF674 00000000 */  nop   
/* 078B28 800DF678 4500001B */  bc1f  .L800DF6E8
/* 078B2C 800DF67C 27A4005C */   addiu $a0, $sp, 0x5c
/* 078B30 800DF680 46002101 */  sub.s $f4, $f4, $f0
.L800DF684:
/* 078B34 800DF684 4406D000 */  mfc1  $a2, $f26
/* 078B38 800DF688 C7A00038 */  lwc1  $f0, 0x38($sp)
/* 078B3C 800DF68C 4407C000 */  mfc1  $a3, $f24
/* 078B40 800DF690 C7A2003C */  lwc1  $f2, 0x3c($sp)
/* 078B44 800DF694 46002582 */  mul.s $f22, $f4, $f0
/* 078B48 800DF698 00000000 */  nop   
/* 078B4C 800DF69C C7A00050 */  lwc1  $f0, 0x50($sp)
/* 078B50 800DF6A0 27A50060 */  addiu $a1, $sp, 0x60
/* 078B54 800DF6A4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 078B58 800DF6A8 C7A00058 */  lwc1  $f0, 0x58($sp)
/* 078B5C 800DF6AC 46022502 */  mul.s $f20, $f4, $f2
/* 078B60 800DF6B0 00000000 */  nop   
/* 078B64 800DF6B4 0C037CFF */  jal   func_800DF3FC
/* 078B68 800DF6B8 E7A00014 */   swc1  $f0, 0x14($sp)
/* 078B6C 800DF6BC C7A2005C */  lwc1  $f2, 0x5c($sp)
/* 078B70 800DF6C0 4602B080 */  add.s $f2, $f22, $f2
/* 078B74 800DF6C4 C6200000 */  lwc1  $f0, ($s1)
/* 078B78 800DF6C8 46020000 */  add.s $f0, $f0, $f2
/* 078B7C 800DF6CC E6200000 */  swc1  $f0, ($s1)
/* 078B80 800DF6D0 C7A00060 */  lwc1  $f0, 0x60($sp)
/* 078B84 800DF6D4 4600A000 */  add.s $f0, $f20, $f0
/* 078B88 800DF6D8 C6420000 */  lwc1  $f2, ($s2)
/* 078B8C 800DF6DC 46001080 */  add.s $f2, $f2, $f0
/* 078B90 800DF6E0 0200982D */  daddu $s3, $s0, $zero
/* 078B94 800DF6E4 E6420000 */  swc1  $f2, ($s2)
.L800DF6E8:
/* 078B98 800DF6E8 C6200000 */  lwc1  $f0, ($s1)
/* 078B9C 800DF6EC 461A0000 */  add.s $f0, $f0, $f26
/* 078BA0 800DF6F0 E6200000 */  swc1  $f0, ($s1)
/* 078BA4 800DF6F4 C6400000 */  lwc1  $f0, ($s2)
/* 078BA8 800DF6F8 46180000 */  add.s $f0, $f0, $f24
/* 078BAC 800DF6FC 0260102D */  daddu $v0, $s3, $zero
/* 078BB0 800DF700 E6400000 */  swc1  $f0, ($s2)
/* 078BB4 800DF704 8FBF0080 */  lw    $ra, 0x80($sp)
/* 078BB8 800DF708 8FB5007C */  lw    $s5, 0x7c($sp)
/* 078BBC 800DF70C 8FB40078 */  lw    $s4, 0x78($sp)
/* 078BC0 800DF710 8FB30074 */  lw    $s3, 0x74($sp)
/* 078BC4 800DF714 8FB20070 */  lw    $s2, 0x70($sp)
/* 078BC8 800DF718 8FB1006C */  lw    $s1, 0x6c($sp)
/* 078BCC 800DF71C 8FB00068 */  lw    $s0, 0x68($sp)
/* 078BD0 800DF720 D7BE00B0 */  ldc1  $f30, 0xb0($sp)
/* 078BD4 800DF724 D7BC00A8 */  ldc1  $f28, 0xa8($sp)
/* 078BD8 800DF728 D7BA00A0 */  ldc1  $f26, 0xa0($sp)
/* 078BDC 800DF72C D7B80098 */  ldc1  $f24, 0x98($sp)
/* 078BE0 800DF730 D7B60090 */  ldc1  $f22, 0x90($sp)
/* 078BE4 800DF734 D7B40088 */  ldc1  $f20, 0x88($sp)
/* 078BE8 800DF738 03E00008 */  jr    $ra
/* 078BEC 800DF73C 27BD00B8 */   addiu $sp, $sp, 0xb8

