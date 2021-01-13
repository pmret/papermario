.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425D8_A95D18
/* A95D18 802425D8 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* A95D1C 802425DC AFB60048 */  sw        $s6, 0x48($sp)
/* A95D20 802425E0 0080B02D */  daddu     $s6, $a0, $zero
/* A95D24 802425E4 AFBF004C */  sw        $ra, 0x4c($sp)
/* A95D28 802425E8 AFB50044 */  sw        $s5, 0x44($sp)
/* A95D2C 802425EC AFB40040 */  sw        $s4, 0x40($sp)
/* A95D30 802425F0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A95D34 802425F4 AFB20038 */  sw        $s2, 0x38($sp)
/* A95D38 802425F8 AFB10034 */  sw        $s1, 0x34($sp)
/* A95D3C 802425FC AFB00030 */  sw        $s0, 0x30($sp)
/* A95D40 80242600 F7B60058 */  sdc1      $f22, 0x58($sp)
/* A95D44 80242604 F7B40050 */  sdc1      $f20, 0x50($sp)
/* A95D48 80242608 8ED50148 */  lw        $s5, 0x148($s6)
/* A95D4C 8024260C 86A40008 */  lh        $a0, 8($s5)
/* A95D50 80242610 0C00EABB */  jal       get_npc_unsafe
/* A95D54 80242614 0000982D */   daddu    $s3, $zero, $zero
/* A95D58 80242618 0040802D */  daddu     $s0, $v0, $zero
/* A95D5C 8024261C 9602008E */  lhu       $v0, 0x8e($s0)
/* A95D60 80242620 2442FFFF */  addiu     $v0, $v0, -1
/* A95D64 80242624 A602008E */  sh        $v0, 0x8e($s0)
/* A95D68 80242628 00021400 */  sll       $v0, $v0, 0x10
/* A95D6C 8024262C 1C4000DA */  bgtz      $v0, .L80242998
/* A95D70 80242630 0260A02D */   daddu    $s4, $s3, $zero
/* A95D74 80242634 0C00A67F */  jal       rand_int
/* A95D78 80242638 2404001E */   addiu    $a0, $zero, 0x1e
/* A95D7C 8024263C 0260902D */  daddu     $s2, $s3, $zero
/* A95D80 80242640 8EA400D0 */  lw        $a0, 0xd0($s5)
/* A95D84 80242644 C6000040 */  lwc1      $f0, 0x40($s0)
/* A95D88 80242648 3C018024 */  lui       $at, %hi(D_80245D78)
/* A95D8C 8024264C D4365D78 */  ldc1      $f22, %lo(D_80245D78)($at)
/* A95D90 80242650 C4820000 */  lwc1      $f2, ($a0)
/* A95D94 80242654 468010A0 */  cvt.s.w   $f2, $f2
/* A95D98 80242658 C4840008 */  lwc1      $f4, 8($a0)
/* A95D9C 8024265C 46802120 */  cvt.s.w   $f4, $f4
/* A95DA0 80242660 E7A00010 */  swc1      $f0, 0x10($sp)
/* A95DA4 80242664 8EA300D0 */  lw        $v1, 0xd0($s5)
/* A95DA8 80242668 44051000 */  mfc1      $a1, $f2
/* A95DAC 8024266C C460000C */  lwc1      $f0, 0xc($v1)
/* A95DB0 80242670 46800020 */  cvt.s.w   $f0, $f0
/* A95DB4 80242674 E7A00014 */  swc1      $f0, 0x14($sp)
/* A95DB8 80242678 8EA300D0 */  lw        $v1, 0xd0($s5)
/* A95DBC 8024267C 44062000 */  mfc1      $a2, $f4
/* A95DC0 80242680 C4600010 */  lwc1      $f0, 0x10($v1)
/* A95DC4 80242684 46800020 */  cvt.s.w   $f0, $f0
/* A95DC8 80242688 E7A00018 */  swc1      $f0, 0x18($sp)
/* A95DCC 8024268C 44820000 */  mtc1      $v0, $f0
/* A95DD0 80242690 00000000 */  nop
/* A95DD4 80242694 46800021 */  cvt.d.w   $f0, $f0
/* A95DD8 80242698 46360000 */  add.d     $f0, $f0, $f22
/* A95DDC 8024269C 8C840018 */  lw        $a0, 0x18($a0)
/* A95DE0 802426A0 8E070038 */  lw        $a3, 0x38($s0)
/* A95DE4 802426A4 0C0123F5 */  jal       is_point_within_region
/* A95DE8 802426A8 46200520 */   cvt.s.d  $f20, $f0
/* A95DEC 802426AC 10400023 */  beqz      $v0, .L8024273C
/* A95DF0 802426B0 00000000 */   nop
/* A95DF4 802426B4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A95DF8 802426B8 8EA200D0 */  lw        $v0, 0xd0($s5)
/* A95DFC 802426BC C60E0040 */  lwc1      $f14, 0x40($s0)
/* A95E00 802426C0 C44A0000 */  lwc1      $f10, ($v0)
/* A95E04 802426C4 468052A0 */  cvt.s.w   $f10, $f10
/* A95E08 802426C8 44065000 */  mfc1      $a2, $f10
/* A95E0C 802426CC C44A0008 */  lwc1      $f10, 8($v0)
/* A95E10 802426D0 468052A0 */  cvt.s.w   $f10, $f10
/* A95E14 802426D4 44075000 */  mfc1      $a3, $f10
/* A95E18 802426D8 0C00A720 */  jal       atan2
/* A95E1C 802426DC 00000000 */   nop
/* A95E20 802426E0 44931000 */  mtc1      $s3, $f2
/* A95E24 802426E4 00000000 */  nop
/* A95E28 802426E8 468010A0 */  cvt.s.w   $f2, $f2
/* A95E2C 802426EC 46020001 */  sub.s     $f0, $f0, $f2
/* A95E30 802426F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A95E34 802426F4 E600000C */  swc1      $f0, 0xc($s0)
/* A95E38 802426F8 8EA200D0 */  lw        $v0, 0xd0($s5)
/* A95E3C 802426FC C60E0040 */  lwc1      $f14, 0x40($s0)
/* A95E40 80242700 C44A0000 */  lwc1      $f10, ($v0)
/* A95E44 80242704 468052A0 */  cvt.s.w   $f10, $f10
/* A95E48 80242708 44065000 */  mfc1      $a2, $f10
/* A95E4C 8024270C C44A0008 */  lwc1      $f10, 8($v0)
/* A95E50 80242710 468052A0 */  cvt.s.w   $f10, $f10
/* A95E54 80242714 44075000 */  mfc1      $a3, $f10
/* A95E58 80242718 0C00A7B5 */  jal       dist2D
/* A95E5C 8024271C 00000000 */   nop
/* A95E60 80242720 46000106 */  mov.s     $f4, $f0
/* A95E64 80242724 4614003C */  c.lt.s    $f0, $f20
/* A95E68 80242728 00000000 */  nop
/* A95E6C 8024272C 4503006A */  bc1tl     .L802428D8
/* A95E70 80242730 46002506 */   mov.s    $f20, $f4
/* A95E74 80242734 08090A37 */  j         .L802428DC
/* A95E78 80242738 27A40020 */   addiu    $a0, $sp, 0x20
.L8024273C:
/* A95E7C 8024273C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A95E80 80242740 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A95E84 80242744 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A95E88 80242748 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A95E8C 8024274C 8C460028 */  lw        $a2, 0x28($v0)
/* A95E90 80242750 0C00A720 */  jal       atan2
/* A95E94 80242754 8C470030 */   lw       $a3, 0x30($v0)
/* A95E98 80242758 460000A1 */  cvt.d.s   $f2, $f0
/* A95E9C 8024275C 4636103C */  c.lt.d    $f2, $f22
/* A95EA0 80242760 00000000 */  nop
/* A95EA4 80242764 45000006 */  bc1f      .L80242780
/* A95EA8 80242768 E600000C */   swc1     $f0, 0xc($s0)
/* A95EAC 8024276C 0C00A67F */  jal       rand_int
/* A95EB0 80242770 2404000A */   addiu    $a0, $zero, 0xa
/* A95EB4 80242774 3C018024 */  lui       $at, %hi(D_80245D80)
/* A95EB8 80242778 080909E4 */  j         .L80242790
/* A95EBC 8024277C D4205D80 */   ldc1     $f0, %lo(D_80245D80)($at)
.L80242780:
/* A95EC0 80242780 0C00A67F */  jal       rand_int
/* A95EC4 80242784 2404000A */   addiu    $a0, $zero, 0xa
/* A95EC8 80242788 3C018024 */  lui       $at, %hi(D_80245D88)
/* A95ECC 8024278C D4205D88 */  ldc1      $f0, %lo(D_80245D88)($at)
.L80242790:
/* A95ED0 80242790 44821000 */  mtc1      $v0, $f2
/* A95ED4 80242794 00000000 */  nop
/* A95ED8 80242798 468010A1 */  cvt.d.w   $f2, $f2
/* A95EDC 8024279C 46201080 */  add.d     $f2, $f2, $f0
/* A95EE0 802427A0 3C014014 */  lui       $at, 0x4014
/* A95EE4 802427A4 44810800 */  mtc1      $at, $f1
/* A95EE8 802427A8 44800000 */  mtc1      $zero, $f0
/* A95EEC 802427AC 00000000 */  nop
/* A95EF0 802427B0 46201081 */  sub.d     $f2, $f2, $f0
/* A95EF4 802427B4 462015A0 */  cvt.s.d   $f22, $f2
/* A95EF8 802427B8 00141080 */  sll       $v0, $s4, 2
/* A95EFC 802427BC 00548821 */  addu      $s1, $v0, $s4
.L802427C0:
/* A95F00 802427C0 12400006 */  beqz      $s2, .L802427DC
/* A95F04 802427C4 00000000 */   nop
/* A95F08 802427C8 44910000 */  mtc1      $s1, $f0
/* A95F0C 802427CC 00000000 */  nop
/* A95F10 802427D0 46800020 */  cvt.s.w   $f0, $f0
/* A95F14 802427D4 080909FB */  j         .L802427EC
/* A95F18 802427D8 4600B000 */   add.s    $f0, $f22, $f0
.L802427DC:
/* A95F1C 802427DC 44910000 */  mtc1      $s1, $f0
/* A95F20 802427E0 00000000 */  nop
/* A95F24 802427E4 46800020 */  cvt.s.w   $f0, $f0
/* A95F28 802427E8 4600B001 */  sub.s     $f0, $f22, $f0
.L802427EC:
/* A95F2C 802427EC E600000C */  swc1      $f0, 0xc($s0)
/* A95F30 802427F0 C6000038 */  lwc1      $f0, 0x38($s0)
/* A95F34 802427F4 C602003C */  lwc1      $f2, 0x3c($s0)
/* A95F38 802427F8 C6040040 */  lwc1      $f4, 0x40($s0)
/* A95F3C 802427FC 0000202D */  daddu     $a0, $zero, $zero
/* A95F40 80242800 E7A00020 */  swc1      $f0, 0x20($sp)
/* A95F44 80242804 E7A20024 */  swc1      $f2, 0x24($sp)
/* A95F48 80242808 E7A40028 */  swc1      $f4, 0x28($sp)
/* A95F4C 8024280C E7B40010 */  swc1      $f20, 0x10($sp)
/* A95F50 80242810 C600000C */  lwc1      $f0, 0xc($s0)
/* A95F54 80242814 27A50020 */  addiu     $a1, $sp, 0x20
/* A95F58 80242818 E7A00014 */  swc1      $f0, 0x14($sp)
/* A95F5C 8024281C 860200A8 */  lh        $v0, 0xa8($s0)
/* A95F60 80242820 27A60024 */  addiu     $a2, $sp, 0x24
/* A95F64 80242824 44820000 */  mtc1      $v0, $f0
/* A95F68 80242828 00000000 */  nop
/* A95F6C 8024282C 46800020 */  cvt.s.w   $f0, $f0
/* A95F70 80242830 E7A00018 */  swc1      $f0, 0x18($sp)
/* A95F74 80242834 860200A6 */  lh        $v0, 0xa6($s0)
/* A95F78 80242838 27A70028 */  addiu     $a3, $sp, 0x28
/* A95F7C 8024283C 44820000 */  mtc1      $v0, $f0
/* A95F80 80242840 00000000 */  nop
/* A95F84 80242844 46800020 */  cvt.s.w   $f0, $f0
/* A95F88 80242848 0C0376B9 */  jal       func_800DDAE4
/* A95F8C 8024284C E7A0001C */   swc1     $f0, 0x1c($sp)
/* A95F90 80242850 50400014 */  beql      $v0, $zero, .L802428A4
/* A95F94 80242854 24130002 */   addiu    $s3, $zero, 2
/* A95F98 80242858 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A95F9C 8024285C C60E0040 */  lwc1      $f14, 0x40($s0)
/* A95FA0 80242860 8FA60020 */  lw        $a2, 0x20($sp)
/* A95FA4 80242864 0C00A7B5 */  jal       dist2D
/* A95FA8 80242868 8FA70028 */   lw       $a3, 0x28($sp)
/* A95FAC 8024286C 46000106 */  mov.s     $f4, $f0
/* A95FB0 80242870 3C014064 */  lui       $at, 0x4064
/* A95FB4 80242874 44811800 */  mtc1      $at, $f3
/* A95FB8 80242878 44801000 */  mtc1      $zero, $f2
/* A95FBC 8024287C 46002021 */  cvt.d.s   $f0, $f4
/* A95FC0 80242880 4620103C */  c.lt.d    $f2, $f0
/* A95FC4 80242884 00000000 */  nop
/* A95FC8 80242888 45000006 */  bc1f      .L802428A4
/* A95FCC 8024288C 00000000 */   nop
/* A95FD0 80242890 4614203C */  c.lt.s    $f4, $f20
/* A95FD4 80242894 00000000 */  nop
/* A95FD8 80242898 45030001 */  bc1tl     .L802428A0
/* A95FDC 8024289C 46002506 */   mov.s    $f20, $f4
.L802428A0:
/* A95FE0 802428A0 24130001 */  addiu     $s3, $zero, 1
.L802428A4:
/* A95FE4 802428A4 1660000D */  bnez      $s3, .L802428DC
/* A95FE8 802428A8 27A40020 */   addiu    $a0, $sp, 0x20
/* A95FEC 802428AC 56400003 */  bnel      $s2, $zero, .L802428BC
/* A95FF0 802428B0 26310005 */   addiu    $s1, $s1, 5
/* A95FF4 802428B4 08090A31 */  j         .L802428C4
/* A95FF8 802428B8 24120001 */   addiu    $s2, $zero, 1
.L802428BC:
/* A95FFC 802428BC 26940001 */  addiu     $s4, $s4, 1
/* A96000 802428C0 0000902D */  daddu     $s2, $zero, $zero
.L802428C4:
/* A96004 802428C4 2A820007 */  slti      $v0, $s4, 7
/* A96008 802428C8 5040FFBD */  beql      $v0, $zero, .L802427C0
/* A9600C 802428CC 24130003 */   addiu    $s3, $zero, 3
/* A96010 802428D0 080909F0 */  j         .L802427C0
/* A96014 802428D4 00000000 */   nop
.L802428D8:
/* A96018 802428D8 27A40020 */  addiu     $a0, $sp, 0x20
.L802428DC:
/* A9601C 802428DC 4406A000 */  mfc1      $a2, $f20
/* A96020 802428E0 8E07000C */  lw        $a3, 0xc($s0)
/* A96024 802428E4 C6000038 */  lwc1      $f0, 0x38($s0)
/* A96028 802428E8 C6020040 */  lwc1      $f2, 0x40($s0)
/* A9602C 802428EC 27A50028 */  addiu     $a1, $sp, 0x28
/* A96030 802428F0 E7A00020 */  swc1      $f0, 0x20($sp)
/* A96034 802428F4 0C00A7E7 */  jal       add_vec2D_polar
/* A96038 802428F8 E7A20028 */   swc1     $f2, 0x28($sp)
/* A9603C 802428FC C6000038 */  lwc1      $f0, 0x38($s0)
/* A96040 80242900 3C014059 */  lui       $at, 0x4059
/* A96044 80242904 44814800 */  mtc1      $at, $f9
/* A96048 80242908 44804000 */  mtc1      $zero, $f8
/* A9604C 8024290C 46000021 */  cvt.d.s   $f0, $f0
/* A96050 80242910 46280002 */  mul.d     $f0, $f0, $f8
/* A96054 80242914 00000000 */  nop
/* A96058 80242918 C7A20020 */  lwc1      $f2, 0x20($sp)
/* A9605C 8024291C C604003C */  lwc1      $f4, 0x3c($s0)
/* A96060 80242920 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A96064 80242924 E6020060 */  swc1      $f2, 0x60($s0)
/* A96068 80242928 E6040064 */  swc1      $f4, 0x64($s0)
/* A9606C 8024292C E6060068 */  swc1      $f6, 0x68($s0)
/* A96070 80242930 4620028D */  trunc.w.d $f10, $f0
/* A96074 80242934 E6AA007C */  swc1      $f10, 0x7c($s5)
/* A96078 80242938 C6000040 */  lwc1      $f0, 0x40($s0)
/* A9607C 8024293C 46000021 */  cvt.d.s   $f0, $f0
/* A96080 80242940 46280002 */  mul.d     $f0, $f0, $f8
/* A96084 80242944 00000000 */  nop
/* A96088 80242948 4620028D */  trunc.w.d $f10, $f0
/* A9608C 8024294C E6AA0084 */  swc1      $f10, 0x84($s5)
/* A96090 80242950 0C00A67F */  jal       rand_int
/* A96094 80242954 2404000A */   addiu    $a0, $zero, 0xa
/* A96098 80242958 3C014040 */  lui       $at, 0x4040
/* A9609C 8024295C 44810000 */  mtc1      $at, $f0
/* A960A0 80242960 3C013FB3 */  lui       $at, 0x3fb3
/* A960A4 80242964 34213333 */  ori       $at, $at, 0x3333
/* A960A8 80242968 44811000 */  mtc1      $at, $f2
/* A960AC 8024296C 3C013E4C */  lui       $at, 0x3e4c
/* A960B0 80242970 3421CCCD */  ori       $at, $at, 0xcccd
/* A960B4 80242974 44812000 */  mtc1      $at, $f4
/* A960B8 80242978 24420023 */  addiu     $v0, $v0, 0x23
/* A960BC 8024297C AEA20078 */  sw        $v0, 0x78($s5)
/* A960C0 80242980 24020010 */  addiu     $v0, $zero, 0x10
/* A960C4 80242984 A600008E */  sh        $zero, 0x8e($s0)
/* A960C8 80242988 E6000018 */  swc1      $f0, 0x18($s0)
/* A960CC 8024298C E602001C */  swc1      $f2, 0x1c($s0)
/* A960D0 80242990 E6040014 */  swc1      $f4, 0x14($s0)
/* A960D4 80242994 AEC20070 */  sw        $v0, 0x70($s6)
.L80242998:
/* A960D8 80242998 8FBF004C */  lw        $ra, 0x4c($sp)
/* A960DC 8024299C 8FB60048 */  lw        $s6, 0x48($sp)
/* A960E0 802429A0 8FB50044 */  lw        $s5, 0x44($sp)
/* A960E4 802429A4 8FB40040 */  lw        $s4, 0x40($sp)
/* A960E8 802429A8 8FB3003C */  lw        $s3, 0x3c($sp)
/* A960EC 802429AC 8FB20038 */  lw        $s2, 0x38($sp)
/* A960F0 802429B0 8FB10034 */  lw        $s1, 0x34($sp)
/* A960F4 802429B4 8FB00030 */  lw        $s0, 0x30($sp)
/* A960F8 802429B8 D7B60058 */  ldc1      $f22, 0x58($sp)
/* A960FC 802429BC D7B40050 */  ldc1      $f20, 0x50($sp)
/* A96100 802429C0 03E00008 */  jr        $ra
/* A96104 802429C4 27BD0060 */   addiu    $sp, $sp, 0x60
