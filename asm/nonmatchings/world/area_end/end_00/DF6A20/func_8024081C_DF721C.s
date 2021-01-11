.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024081C_DF721C
/* DF721C 8024081C 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* DF7220 80240820 AFB200D0 */  sw        $s2, 0xd0($sp)
/* DF7224 80240824 0080902D */  daddu     $s2, $a0, $zero
/* DF7228 80240828 AFB000C8 */  sw        $s0, 0xc8($sp)
/* DF722C 8024082C 00A0802D */  daddu     $s0, $a1, $zero
/* DF7230 80240830 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* DF7234 80240834 AFB500DC */  sw        $s5, 0xdc($sp)
/* DF7238 80240838 AFB400D8 */  sw        $s4, 0xd8($sp)
/* DF723C 8024083C AFB300D4 */  sw        $s3, 0xd4($sp)
/* DF7240 80240840 AFB100CC */  sw        $s1, 0xcc($sp)
/* DF7244 80240844 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* DF7248 80240848 F7BA0100 */  sdc1      $f26, 0x100($sp)
/* DF724C 8024084C F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* DF7250 80240850 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* DF7254 80240854 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* DF7258 80240858 C6180010 */  lwc1      $f24, 0x10($s0)
/* DF725C 8024085C 4680C620 */  cvt.s.w   $f24, $f24
/* DF7260 80240860 3C054200 */  lui       $a1, 0x4200
/* DF7264 80240864 3C064396 */  lui       $a2, 0x4396
/* DF7268 80240868 8E42001C */  lw        $v0, 0x1c($s2)
/* DF726C 8024086C C61C0014 */  lwc1      $f28, 0x14($s0)
/* DF7270 80240870 4680E720 */  cvt.s.w   $f28, $f28
/* DF7274 80240874 AFA20010 */  sw        $v0, 0x10($sp)
/* DF7278 80240878 8E070018 */  lw        $a3, 0x18($s0)
/* DF727C 8024087C 0C00A8ED */  jal       update_lerp
/* DF7280 80240880 2404000C */   addiu    $a0, $zero, 0xc
/* DF7284 80240884 3C01437F */  lui       $at, 0x437f
/* DF7288 80240888 44811000 */  mtc1      $at, $f2
/* DF728C 8024088C 00000000 */  nop
/* DF7290 80240890 4600103C */  c.lt.s    $f2, $f0
/* DF7294 80240894 00000000 */  nop
/* DF7298 80240898 45000002 */  bc1f      .L802408A4
/* DF729C 8024089C 27B10038 */   addiu    $s1, $sp, 0x38
/* DF72A0 802408A0 46001006 */  mov.s     $f0, $f2
.L802408A4:
/* DF72A4 802408A4 4600010D */  trunc.w.s $f4, $f0
/* DF72A8 802408A8 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF72AC 802408AC 0000202D */  daddu     $a0, $zero, $zero
/* DF72B0 802408B0 24050007 */  addiu     $a1, $zero, 7
/* DF72B4 802408B4 240600FF */  addiu     $a2, $zero, 0xff
/* DF72B8 802408B8 00C0382D */  daddu     $a3, $a2, $zero
/* DF72BC 802408BC 00C0A82D */  daddu     $s5, $a2, $zero
/* DF72C0 802408C0 AFB50010 */  sw        $s5, 0x10($sp)
/* DF72C4 802408C4 0C04EAA7 */  jal       func_8013AA9C
/* DF72C8 802408C8 AFA00018 */   sw       $zero, 0x18($sp)
/* DF72CC 802408CC 8E42001C */  lw        $v0, 0x1c($s2)
/* DF72D0 802408D0 3C05C296 */  lui       $a1, 0xc296
/* DF72D4 802408D4 3C0641F0 */  lui       $a2, 0x41f0
/* DF72D8 802408D8 AFA20010 */  sw        $v0, 0x10($sp)
/* DF72DC 802408DC 8E070018 */  lw        $a3, 0x18($s0)
/* DF72E0 802408E0 0C00A8ED */  jal       update_lerp
/* DF72E4 802408E4 0000202D */   daddu    $a0, $zero, $zero
/* DF72E8 802408E8 4480B000 */  mtc1      $zero, $f22
/* DF72EC 802408EC 46000506 */  mov.s     $f20, $f0
/* DF72F0 802408F0 4614B03E */  c.le.s    $f22, $f20
/* DF72F4 802408F4 00000000 */  nop
/* DF72F8 802408F8 45030001 */  bc1tl     .L80240900
/* DF72FC 802408FC 4600B506 */   mov.s    $f20, $f22
.L80240900:
/* DF7300 80240900 AFB10010 */  sw        $s1, 0x10($sp)
/* DF7304 80240904 8E040004 */  lw        $a0, 4($s0)
/* DF7308 80240908 8E050008 */  lw        $a1, 8($s0)
/* DF730C 8024090C 8E060000 */  lw        $a2, ($s0)
/* DF7310 80240910 0C04BA38 */  jal       func_8012E8E0
/* DF7314 80240914 8E07000C */   lw       $a3, 0xc($s0)
/* DF7318 80240918 93A20042 */  lbu       $v0, 0x42($sp)
/* DF731C 8024091C 3C013FE0 */  lui       $at, 0x3fe0
/* DF7320 80240920 4481D800 */  mtc1      $at, $f27
/* DF7324 80240924 4480D000 */  mtc1      $zero, $f26
/* DF7328 80240928 44820000 */  mtc1      $v0, $f0
/* DF732C 8024092C 00000000 */  nop
/* DF7330 80240930 46800021 */  cvt.d.w   $f0, $f0
/* DF7334 80240934 463A0002 */  mul.d     $f0, $f0, $f26
/* DF7338 80240938 00000000 */  nop
/* DF733C 8024093C 4600C0A1 */  cvt.d.s   $f2, $f24
/* DF7340 80240940 27B40048 */  addiu     $s4, $sp, 0x48
/* DF7344 80240944 4600E707 */  neg.s     $f28, $f28
/* DF7348 80240948 46201080 */  add.d     $f2, $f2, $f0
/* DF734C 8024094C 4406E000 */  mfc1      $a2, $f28
/* DF7350 80240950 4407B000 */  mfc1      $a3, $f22
/* DF7354 80240954 462010A0 */  cvt.s.d   $f2, $f2
/* DF7358 80240958 44051000 */  mfc1      $a1, $f2
/* DF735C 8024095C 0C019E40 */  jal       guTranslateF
/* DF7360 80240960 0280202D */   daddu    $a0, $s4, $zero
/* DF7364 80240964 4616A032 */  c.eq.s    $f20, $f22
/* DF7368 80240968 00000000 */  nop
/* DF736C 8024096C 4501000D */  bc1t      .L802409A4
/* DF7370 80240970 3C130001 */   lui      $s3, 1
/* DF7374 80240974 27B00088 */  addiu     $s0, $sp, 0x88
/* DF7378 80240978 4405A000 */  mfc1      $a1, $f20
/* DF737C 8024097C 4406B000 */  mfc1      $a2, $f22
/* DF7380 80240980 3C073F80 */  lui       $a3, 0x3f80
/* DF7384 80240984 0200202D */  daddu     $a0, $s0, $zero
/* DF7388 80240988 0C019EC8 */  jal       guRotateF
/* DF738C 8024098C AFA60010 */   sw       $a2, 0x10($sp)
/* DF7390 80240990 0200202D */  daddu     $a0, $s0, $zero
/* DF7394 80240994 0280282D */  daddu     $a1, $s4, $zero
/* DF7398 80240998 0C019D80 */  jal       guMtxCatF
/* DF739C 8024099C 0280302D */   daddu    $a2, $s4, $zero
/* DF73A0 802409A0 3C130001 */  lui       $s3, 1
.L802409A4:
/* DF73A4 802409A4 36731630 */  ori       $s3, $s3, 0x1630
/* DF73A8 802409A8 0280202D */  daddu     $a0, $s4, $zero
/* DF73AC 802409AC 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* DF73B0 802409B0 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* DF73B4 802409B4 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* DF73B8 802409B8 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* DF73BC 802409BC 96250000 */  lhu       $a1, ($s1)
/* DF73C0 802409C0 8E420000 */  lw        $v0, ($s2)
/* DF73C4 802409C4 00052980 */  sll       $a1, $a1, 6
/* DF73C8 802409C8 00B32821 */  addu      $a1, $a1, $s3
/* DF73CC 802409CC 0C019D40 */  jal       guMtxF2L
/* DF73D0 802409D0 00452821 */   addu     $a1, $v0, $a1
/* DF73D4 802409D4 3C03DA38 */  lui       $v1, 0xda38
/* DF73D8 802409D8 34630002 */  ori       $v1, $v1, 2
/* DF73DC 802409DC 0000202D */  daddu     $a0, $zero, $zero
/* DF73E0 802409E0 27A50020 */  addiu     $a1, $sp, 0x20
/* DF73E4 802409E4 3C060001 */  lui       $a2, 1
/* DF73E8 802409E8 34C60040 */  ori       $a2, $a2, 0x40
/* DF73EC 802409EC 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* DF73F0 802409F0 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* DF73F4 802409F4 0280382D */  daddu     $a3, $s4, $zero
/* DF73F8 802409F8 8E020000 */  lw        $v0, ($s0)
/* DF73FC 802409FC 96280000 */  lhu       $t0, ($s1)
/* DF7400 80240A00 0040482D */  daddu     $t1, $v0, $zero
/* DF7404 80240A04 24420008 */  addiu     $v0, $v0, 8
/* DF7408 80240A08 AE020000 */  sw        $v0, ($s0)
/* DF740C 80240A0C 3102FFFF */  andi      $v0, $t0, 0xffff
/* DF7410 80240A10 00021180 */  sll       $v0, $v0, 6
/* DF7414 80240A14 00531021 */  addu      $v0, $v0, $s3
/* DF7418 80240A18 AD230000 */  sw        $v1, ($t1)
/* DF741C 80240A1C 8E430000 */  lw        $v1, ($s2)
/* DF7420 80240A20 25080001 */  addiu     $t0, $t0, 1
/* DF7424 80240A24 00621821 */  addu      $v1, $v1, $v0
/* DF7428 80240A28 3C028000 */  lui       $v0, 0x8000
/* DF742C 80240A2C 00621821 */  addu      $v1, $v1, $v0
/* DF7430 80240A30 AD230004 */  sw        $v1, 4($t1)
/* DF7434 80240A34 93A20042 */  lbu       $v0, 0x42($sp)
/* DF7438 80240A38 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF743C 80240A3C 93A90040 */  lbu       $t1, 0x40($sp)
/* DF7440 80240A40 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF7444 80240A44 44820000 */  mtc1      $v0, $f0
/* DF7448 80240A48 00000000 */  nop
/* DF744C 80240A4C 46800021 */  cvt.d.w   $f0, $f0
/* DF7450 80240A50 8FA20038 */  lw        $v0, 0x38($sp)
/* DF7454 80240A54 463A0002 */  mul.d     $f0, $f0, $f26
/* DF7458 80240A58 00000000 */  nop
/* DF745C 80240A5C A6280000 */  sh        $t0, ($s1)
/* DF7460 80240A60 A7A0002E */  sh        $zero, 0x2e($sp)
/* DF7464 80240A64 A3B50030 */  sb        $s5, 0x30($sp)
/* DF7468 80240A68 AFA30024 */  sw        $v1, 0x24($sp)
/* DF746C 80240A6C A7A90028 */  sh        $t1, 0x28($sp)
/* DF7470 80240A70 A7AA002A */  sh        $t2, 0x2a($sp)
/* DF7474 80240A74 AFA20020 */  sw        $v0, 0x20($sp)
/* DF7478 80240A78 46200007 */  neg.d     $f0, $f0
/* DF747C 80240A7C 4620010D */  trunc.w.d $f4, $f0
/* DF7480 80240A80 44022000 */  mfc1      $v0, $f4
/* DF7484 80240A84 0C04EBDC */  jal       func_8013AF70
/* DF7488 80240A88 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF748C 80240A8C 3C04D838 */  lui       $a0, 0xd838
/* DF7490 80240A90 8E020000 */  lw        $v0, ($s0)
/* DF7494 80240A94 34840002 */  ori       $a0, $a0, 2
/* DF7498 80240A98 0040182D */  daddu     $v1, $v0, $zero
/* DF749C 80240A9C 24420008 */  addiu     $v0, $v0, 8
/* DF74A0 80240AA0 AE020000 */  sw        $v0, ($s0)
/* DF74A4 80240AA4 24020040 */  addiu     $v0, $zero, 0x40
/* DF74A8 80240AA8 AC640000 */  sw        $a0, ($v1)
/* DF74AC 80240AAC AC620004 */  sw        $v0, 4($v1)
/* DF74B0 80240AB0 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* DF74B4 80240AB4 8FB500DC */  lw        $s5, 0xdc($sp)
/* DF74B8 80240AB8 8FB400D8 */  lw        $s4, 0xd8($sp)
/* DF74BC 80240ABC 8FB300D4 */  lw        $s3, 0xd4($sp)
/* DF74C0 80240AC0 8FB200D0 */  lw        $s2, 0xd0($sp)
/* DF74C4 80240AC4 8FB100CC */  lw        $s1, 0xcc($sp)
/* DF74C8 80240AC8 8FB000C8 */  lw        $s0, 0xc8($sp)
/* DF74CC 80240ACC D7BC0108 */  ldc1      $f28, 0x108($sp)
/* DF74D0 80240AD0 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* DF74D4 80240AD4 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* DF74D8 80240AD8 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* DF74DC 80240ADC D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* DF74E0 80240AE0 03E00008 */  jr        $ra
/* DF74E4 80240AE4 27BD0110 */   addiu    $sp, $sp, 0x110
