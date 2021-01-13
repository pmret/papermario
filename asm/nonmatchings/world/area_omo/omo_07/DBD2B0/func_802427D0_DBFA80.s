.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427D0_DBFA80
/* DBFA80 802427D0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DBFA84 802427D4 AFB20030 */  sw        $s2, 0x30($sp)
/* DBFA88 802427D8 0080902D */  daddu     $s2, $a0, $zero
/* DBFA8C 802427DC AFBF0038 */  sw        $ra, 0x38($sp)
/* DBFA90 802427E0 AFB30034 */  sw        $s3, 0x34($sp)
/* DBFA94 802427E4 AFB1002C */  sw        $s1, 0x2c($sp)
/* DBFA98 802427E8 AFB00028 */  sw        $s0, 0x28($sp)
/* DBFA9C 802427EC F7B60048 */  sdc1      $f22, 0x48($sp)
/* DBFAA0 802427F0 F7B40040 */  sdc1      $f20, 0x40($sp)
/* DBFAA4 802427F4 8E510148 */  lw        $s1, 0x148($s2)
/* DBFAA8 802427F8 86240008 */  lh        $a0, 8($s1)
/* DBFAAC 802427FC 0C00EABB */  jal       get_npc_unsafe
/* DBFAB0 80242800 00A0982D */   daddu    $s3, $a1, $zero
/* DBFAB4 80242804 0040802D */  daddu     $s0, $v0, $zero
/* DBFAB8 80242808 0200202D */  daddu     $a0, $s0, $zero
/* DBFABC 8024280C C6220088 */  lwc1      $f2, 0x88($s1)
/* DBFAC0 80242810 468010A0 */  cvt.s.w   $f2, $f2
/* DBFAC4 80242814 460010A1 */  cvt.d.s   $f2, $f2
/* DBFAC8 80242818 C604001C */  lwc1      $f4, 0x1c($s0)
/* DBFACC 8024281C C6000014 */  lwc1      $f0, 0x14($s0)
/* DBFAD0 80242820 8E050018 */  lw        $a1, 0x18($s0)
/* DBFAD4 80242824 46002100 */  add.s     $f4, $f4, $f0
/* DBFAD8 80242828 8E06000C */  lw        $a2, 0xc($s0)
/* DBFADC 8024282C C6200078 */  lwc1      $f0, 0x78($s1)
/* DBFAE0 80242830 46800020 */  cvt.s.w   $f0, $f0
/* DBFAE4 80242834 E604001C */  swc1      $f4, 0x1c($s0)
/* DBFAE8 80242838 3C014059 */  lui       $at, 0x4059
/* DBFAEC 8024283C 44812800 */  mtc1      $at, $f5
/* DBFAF0 80242840 44802000 */  mtc1      $zero, $f4
/* DBFAF4 80242844 46000021 */  cvt.d.s   $f0, $f0
/* DBFAF8 80242848 46240003 */  div.d     $f0, $f0, $f4
/* DBFAFC 8024284C 46200520 */  cvt.s.d   $f20, $f0
/* DBFB00 80242850 46241083 */  div.d     $f2, $f2, $f4
/* DBFB04 80242854 0C00EA95 */  jal       npc_move_heading
/* DBFB08 80242858 462015A0 */   cvt.s.d  $f22, $f2
/* DBFB0C 8024285C C604001C */  lwc1      $f4, 0x1c($s0)
/* DBFB10 80242860 44801000 */  mtc1      $zero, $f2
/* DBFB14 80242864 44801800 */  mtc1      $zero, $f3
/* DBFB18 80242868 46002021 */  cvt.d.s   $f0, $f4
/* DBFB1C 8024286C 4620103E */  c.le.d    $f2, $f0
/* DBFB20 80242870 00000000 */  nop
/* DBFB24 80242874 45000030 */  bc1f      .L80242938
/* DBFB28 80242878 00000000 */   nop
/* DBFB2C 8024287C C600003C */  lwc1      $f0, 0x3c($s0)
/* DBFB30 80242880 46040000 */  add.s     $f0, $f0, $f4
/* DBFB34 80242884 E600003C */  swc1      $f0, 0x3c($s0)
/* DBFB38 80242888 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBFB3C 8024288C 8C420024 */  lw        $v0, 0x24($v0)
/* DBFB40 80242890 AE020028 */  sw        $v0, 0x28($s0)
/* DBFB44 80242894 A2200007 */  sb        $zero, 7($s1)
/* DBFB48 80242898 8E020000 */  lw        $v0, ($s0)
/* DBFB4C 8024289C 30420008 */  andi      $v0, $v0, 8
/* DBFB50 802428A0 14400011 */  bnez      $v0, .L802428E8
/* DBFB54 802428A4 0000102D */   daddu    $v0, $zero, $zero
/* DBFB58 802428A8 27A50018 */  addiu     $a1, $sp, 0x18
/* DBFB5C 802428AC 27A6001C */  addiu     $a2, $sp, 0x1c
/* DBFB60 802428B0 C6000038 */  lwc1      $f0, 0x38($s0)
/* DBFB64 802428B4 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBFB68 802428B8 C6040040 */  lwc1      $f4, 0x40($s0)
/* DBFB6C 802428BC 3C01447A */  lui       $at, 0x447a
/* DBFB70 802428C0 44813000 */  mtc1      $at, $f6
/* DBFB74 802428C4 27A20024 */  addiu     $v0, $sp, 0x24
/* DBFB78 802428C8 E7A00018 */  swc1      $f0, 0x18($sp)
/* DBFB7C 802428CC E7A2001C */  swc1      $f2, 0x1c($sp)
/* DBFB80 802428D0 E7A40020 */  swc1      $f4, 0x20($sp)
/* DBFB84 802428D4 E7A60024 */  swc1      $f6, 0x24($sp)
/* DBFB88 802428D8 AFA20010 */  sw        $v0, 0x10($sp)
/* DBFB8C 802428DC 8E040080 */  lw        $a0, 0x80($s0)
/* DBFB90 802428E0 0C0372DF */  jal       func_800DCB7C
/* DBFB94 802428E4 27A70020 */   addiu    $a3, $sp, 0x20
.L802428E8:
/* DBFB98 802428E8 1040000B */  beqz      $v0, .L80242918
/* DBFB9C 802428EC 00000000 */   nop
/* DBFBA0 802428F0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DBFBA4 802428F4 46140080 */  add.s     $f2, $f0, $f20
/* DBFBA8 802428F8 C600003C */  lwc1      $f0, 0x3c($s0)
/* DBFBAC 802428FC 4600103E */  c.le.s    $f2, $f0
/* DBFBB0 80242900 00000000 */  nop
/* DBFBB4 80242904 4500008D */  bc1f      .L80242B3C
/* DBFBB8 80242908 00000000 */   nop
/* DBFBBC 8024290C E602003C */  swc1      $f2, 0x3c($s0)
/* DBFBC0 80242910 08090ACF */  j         .L80242B3C
/* DBFBC4 80242914 AE400070 */   sw       $zero, 0x70($s2)
.L80242918:
/* DBFBC8 80242918 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBFBCC 8024291C C6000064 */  lwc1      $f0, 0x64($s0)
/* DBFBD0 80242920 4602003E */  c.le.s    $f0, $f2
/* DBFBD4 80242924 00000000 */  nop
/* DBFBD8 80242928 45030084 */  bc1tl     .L80242B3C
/* DBFBDC 8024292C AE400070 */   sw       $zero, 0x70($s2)
/* DBFBE0 80242930 08090ACF */  j         .L80242B3C
/* DBFBE4 80242934 00000000 */   nop
.L80242938:
/* DBFBE8 80242938 4622003C */  c.lt.d    $f0, $f2
/* DBFBEC 8024293C 00000000 */  nop
/* DBFBF0 80242940 4500007E */  bc1f      .L80242B3C
/* DBFBF4 80242944 00000000 */   nop
/* DBFBF8 80242948 9602008E */  lhu       $v0, 0x8e($s0)
/* DBFBFC 8024294C 24420001 */  addiu     $v0, $v0, 1
/* DBFC00 80242950 A602008E */  sh        $v0, 0x8e($s0)
/* DBFC04 80242954 00021400 */  sll       $v0, $v0, 0x10
/* DBFC08 80242958 8E630020 */  lw        $v1, 0x20($s3)
/* DBFC0C 8024295C 00021403 */  sra       $v0, $v0, 0x10
/* DBFC10 80242960 0043102A */  slt       $v0, $v0, $v1
/* DBFC14 80242964 14400026 */  bnez      $v0, .L80242A00
/* DBFC18 80242968 00000000 */   nop
/* DBFC1C 8024296C C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBFC20 80242970 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBFC24 80242974 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBFC28 80242978 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBFC2C 8024297C A600008E */  sh        $zero, 0x8e($s0)
/* DBFC30 80242980 8C460028 */  lw        $a2, 0x28($v0)
/* DBFC34 80242984 0C00A720 */  jal       atan2
/* DBFC38 80242988 8C470030 */   lw       $a3, 0x30($v0)
/* DBFC3C 8024298C 46000506 */  mov.s     $f20, $f0
/* DBFC40 80242990 C60C000C */  lwc1      $f12, 0xc($s0)
/* DBFC44 80242994 0C00A70A */  jal       get_clamped_angle_diff
/* DBFC48 80242998 4600A386 */   mov.s    $f14, $f20
/* DBFC4C 8024299C 46000086 */  mov.s     $f2, $f0
/* DBFC50 802429A0 8E62001C */  lw        $v0, 0x1c($s3)
/* DBFC54 802429A4 46001005 */  abs.s     $f0, $f2
/* DBFC58 802429A8 44822000 */  mtc1      $v0, $f4
/* DBFC5C 802429AC 00000000 */  nop
/* DBFC60 802429B0 46802120 */  cvt.s.w   $f4, $f4
/* DBFC64 802429B4 4600203C */  c.lt.s    $f4, $f0
/* DBFC68 802429B8 00000000 */  nop
/* DBFC6C 802429BC 4500000D */  bc1f      .L802429F4
/* DBFC70 802429C0 00000000 */   nop
/* DBFC74 802429C4 44800000 */  mtc1      $zero, $f0
/* DBFC78 802429C8 C614000C */  lwc1      $f20, 0xc($s0)
/* DBFC7C 802429CC 4600103C */  c.lt.s    $f2, $f0
/* DBFC80 802429D0 00000000 */  nop
/* DBFC84 802429D4 45000006 */  bc1f      .L802429F0
/* DBFC88 802429D8 00021023 */   negu     $v0, $v0
/* DBFC8C 802429DC 44820000 */  mtc1      $v0, $f0
/* DBFC90 802429E0 00000000 */  nop
/* DBFC94 802429E4 46800020 */  cvt.s.w   $f0, $f0
/* DBFC98 802429E8 08090A7D */  j         .L802429F4
/* DBFC9C 802429EC 4600A500 */   add.s    $f20, $f20, $f0
.L802429F0:
/* DBFCA0 802429F0 4604A500 */  add.s     $f20, $f20, $f4
.L802429F4:
/* DBFCA4 802429F4 0C00A6C9 */  jal       clamp_angle
/* DBFCA8 802429F8 4600A306 */   mov.s    $f12, $f20
/* DBFCAC 802429FC E600000C */  swc1      $f0, 0xc($s0)
.L80242A00:
/* DBFCB0 80242A00 8E020000 */  lw        $v0, ($s0)
/* DBFCB4 80242A04 30420008 */  andi      $v0, $v0, 8
/* DBFCB8 80242A08 1040000A */  beqz      $v0, .L80242A34
/* DBFCBC 80242A0C 27A50018 */   addiu    $a1, $sp, 0x18
/* DBFCC0 80242A10 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBFCC4 80242A14 C600001C */  lwc1      $f0, 0x1c($s0)
/* DBFCC8 80242A18 46001080 */  add.s     $f2, $f2, $f0
/* DBFCCC 80242A1C 4616103C */  c.lt.s    $f2, $f22
/* DBFCD0 80242A20 00000000 */  nop
/* DBFCD4 80242A24 45020045 */  bc1fl     .L80242B3C
/* DBFCD8 80242A28 E602003C */   swc1     $f2, 0x3c($s0)
/* DBFCDC 80242A2C 08090ACE */  j         .L80242B38
/* DBFCE0 80242A30 E616003C */   swc1     $f22, 0x3c($s0)
.L80242A34:
/* DBFCE4 80242A34 C6000038 */  lwc1      $f0, 0x38($s0)
/* DBFCE8 80242A38 27A6001C */  addiu     $a2, $sp, 0x1c
/* DBFCEC 80242A3C E7A00018 */  swc1      $f0, 0x18($sp)
/* DBFCF0 80242A40 860200A8 */  lh        $v0, 0xa8($s0)
/* DBFCF4 80242A44 C600001C */  lwc1      $f0, 0x1c($s0)
/* DBFCF8 80242A48 C604003C */  lwc1      $f4, 0x3c($s0)
/* DBFCFC 80242A4C 44821000 */  mtc1      $v0, $f2
/* DBFD00 80242A50 00000000 */  nop
/* DBFD04 80242A54 468010A0 */  cvt.s.w   $f2, $f2
/* DBFD08 80242A58 46000005 */  abs.s     $f0, $f0
/* DBFD0C 80242A5C 46020000 */  add.s     $f0, $f0, $f2
/* DBFD10 80242A60 C6060040 */  lwc1      $f6, 0x40($s0)
/* DBFD14 80242A64 27A20024 */  addiu     $v0, $sp, 0x24
/* DBFD18 80242A68 46022100 */  add.s     $f4, $f4, $f2
/* DBFD1C 80242A6C 3C014024 */  lui       $at, 0x4024
/* DBFD20 80242A70 44811800 */  mtc1      $at, $f3
/* DBFD24 80242A74 44801000 */  mtc1      $zero, $f2
/* DBFD28 80242A78 46000021 */  cvt.d.s   $f0, $f0
/* DBFD2C 80242A7C 46220000 */  add.d     $f0, $f0, $f2
/* DBFD30 80242A80 E7A60020 */  swc1      $f6, 0x20($sp)
/* DBFD34 80242A84 E7A4001C */  swc1      $f4, 0x1c($sp)
/* DBFD38 80242A88 46200020 */  cvt.s.d   $f0, $f0
/* DBFD3C 80242A8C E7A00024 */  swc1      $f0, 0x24($sp)
/* DBFD40 80242A90 AFA20010 */  sw        $v0, 0x10($sp)
/* DBFD44 80242A94 8E040080 */  lw        $a0, 0x80($s0)
/* DBFD48 80242A98 0C0372DF */  jal       func_800DCB7C
/* DBFD4C 80242A9C 27A70020 */   addiu    $a3, $sp, 0x20
/* DBFD50 80242AA0 10400015 */  beqz      $v0, .L80242AF8
/* DBFD54 80242AA4 00000000 */   nop
/* DBFD58 80242AA8 860200A8 */  lh        $v0, 0xa8($s0)
/* DBFD5C 80242AAC C604001C */  lwc1      $f4, 0x1c($s0)
/* DBFD60 80242AB0 44820000 */  mtc1      $v0, $f0
/* DBFD64 80242AB4 00000000 */  nop
/* DBFD68 80242AB8 46800020 */  cvt.s.w   $f0, $f0
/* DBFD6C 80242ABC 46002085 */  abs.s     $f2, $f4
/* DBFD70 80242AC0 46020000 */  add.s     $f0, $f0, $f2
/* DBFD74 80242AC4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* DBFD78 80242AC8 4600103E */  c.le.s    $f2, $f0
/* DBFD7C 80242ACC 00000000 */  nop
/* DBFD80 80242AD0 45000005 */  bc1f      .L80242AE8
/* DBFD84 80242AD4 00000000 */   nop
/* DBFD88 80242AD8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DBFD8C 80242ADC AE00001C */  sw        $zero, 0x1c($s0)
/* DBFD90 80242AE0 08090ACF */  j         .L80242B3C
/* DBFD94 80242AE4 E600003C */   swc1     $f0, 0x3c($s0)
.L80242AE8:
/* DBFD98 80242AE8 C600003C */  lwc1      $f0, 0x3c($s0)
/* DBFD9C 80242AEC 46040000 */  add.s     $f0, $f0, $f4
/* DBFDA0 80242AF0 08090ACF */  j         .L80242B3C
/* DBFDA4 80242AF4 E600003C */   swc1     $f0, 0x3c($s0)
.L80242AF8:
/* DBFDA8 80242AF8 C606003C */  lwc1      $f6, 0x3c($s0)
/* DBFDAC 80242AFC 860200A8 */  lh        $v0, 0xa8($s0)
/* DBFDB0 80242B00 46163081 */  sub.s     $f2, $f6, $f22
/* DBFDB4 80242B04 44820000 */  mtc1      $v0, $f0
/* DBFDB8 80242B08 00000000 */  nop
/* DBFDBC 80242B0C 46800020 */  cvt.s.w   $f0, $f0
/* DBFDC0 80242B10 46001080 */  add.s     $f2, $f2, $f0
/* DBFDC4 80242B14 C604001C */  lwc1      $f4, 0x1c($s0)
/* DBFDC8 80242B18 46002005 */  abs.s     $f0, $f4
/* DBFDCC 80242B1C 4602003C */  c.lt.s    $f0, $f2
/* DBFDD0 80242B20 00000000 */  nop
/* DBFDD4 80242B24 45020005 */  bc1fl     .L80242B3C
/* DBFDD8 80242B28 AE00001C */   sw       $zero, 0x1c($s0)
/* DBFDDC 80242B2C 46043000 */  add.s     $f0, $f6, $f4
/* DBFDE0 80242B30 08090ACF */  j         .L80242B3C
/* DBFDE4 80242B34 E600003C */   swc1     $f0, 0x3c($s0)
.L80242B38:
/* DBFDE8 80242B38 AE00001C */  sw        $zero, 0x1c($s0)
.L80242B3C:
/* DBFDEC 80242B3C 8FBF0038 */  lw        $ra, 0x38($sp)
/* DBFDF0 80242B40 8FB30034 */  lw        $s3, 0x34($sp)
/* DBFDF4 80242B44 8FB20030 */  lw        $s2, 0x30($sp)
/* DBFDF8 80242B48 8FB1002C */  lw        $s1, 0x2c($sp)
/* DBFDFC 80242B4C 8FB00028 */  lw        $s0, 0x28($sp)
/* DBFE00 80242B50 D7B60048 */  ldc1      $f22, 0x48($sp)
/* DBFE04 80242B54 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DBFE08 80242B58 03E00008 */  jr        $ra
/* DBFE0C 80242B5C 27BD0050 */   addiu    $sp, $sp, 0x50
