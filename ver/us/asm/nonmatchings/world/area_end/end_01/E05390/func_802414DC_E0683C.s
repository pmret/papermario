.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414DC_E0683C
/* E0683C 802414DC 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* E06840 802414E0 AFB100CC */  sw        $s1, 0xcc($sp)
/* E06844 802414E4 0080882D */  daddu     $s1, $a0, $zero
/* E06848 802414E8 AFB000C8 */  sw        $s0, 0xc8($sp)
/* E0684C 802414EC 00A0802D */  daddu     $s0, $a1, $zero
/* E06850 802414F0 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* E06854 802414F4 AFB500DC */  sw        $s5, 0xdc($sp)
/* E06858 802414F8 AFB400D8 */  sw        $s4, 0xd8($sp)
/* E0685C 802414FC AFB300D4 */  sw        $s3, 0xd4($sp)
/* E06860 80241500 AFB200D0 */  sw        $s2, 0xd0($sp)
/* E06864 80241504 F7BE0110 */  sdc1      $f30, 0x110($sp)
/* E06868 80241508 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* E0686C 8024150C F7BA0100 */  sdc1      $f26, 0x100($sp)
/* E06870 80241510 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* E06874 80241514 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* E06878 80241518 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* E0687C 8024151C C6140010 */  lwc1      $f20, 0x10($s0)
/* E06880 80241520 4680A520 */  cvt.s.w   $f20, $f20
/* E06884 80241524 4480E000 */  mtc1      $zero, $f28
/* E06888 80241528 3C05437F */  lui       $a1, 0x437f
/* E0688C 8024152C 8E220050 */  lw        $v0, 0x50($s1)
/* E06890 80241530 4406E000 */  mfc1      $a2, $f28
/* E06894 80241534 C61E0014 */  lwc1      $f30, 0x14($s0)
/* E06898 80241538 4680F7A0 */  cvt.s.w   $f30, $f30
/* E0689C 8024153C AFA20010 */  sw        $v0, 0x10($sp)
/* E068A0 80241540 8E070018 */  lw        $a3, 0x18($s0)
/* E068A4 80241544 0C00A8ED */  jal       update_lerp
/* E068A8 80241548 2404000B */   addiu    $a0, $zero, 0xb
/* E068AC 8024154C 4600008D */  trunc.w.s $f2, $f0
/* E068B0 80241550 E7A20014 */  swc1      $f2, 0x14($sp)
/* E068B4 80241554 0000202D */  daddu     $a0, $zero, $zero
/* E068B8 80241558 24050007 */  addiu     $a1, $zero, 7
/* E068BC 8024155C 240600FF */  addiu     $a2, $zero, 0xff
/* E068C0 80241560 00C0382D */  daddu     $a3, $a2, $zero
/* E068C4 80241564 00C0A82D */  daddu     $s5, $a2, $zero
/* E068C8 80241568 AFB50010 */  sw        $s5, 0x10($sp)
/* E068CC 8024156C 0C04EAA7 */  jal       func_8013AA9C
/* E068D0 80241570 AFA00018 */   sw       $zero, 0x18($sp)
/* E068D4 80241574 3C013F80 */  lui       $at, 0x3f80
/* E068D8 80241578 4481D000 */  mtc1      $at, $f26
/* E068DC 8024157C 8E220050 */  lw        $v0, 0x50($s1)
/* E068E0 80241580 3C063E4C */  lui       $a2, 0x3e4c
/* E068E4 80241584 34C6CCCD */  ori       $a2, $a2, 0xcccd
/* E068E8 80241588 4405D000 */  mfc1      $a1, $f26
/* E068EC 8024158C AFA20010 */  sw        $v0, 0x10($sp)
/* E068F0 80241590 8E070018 */  lw        $a3, 0x18($s0)
/* E068F4 80241594 0C00A8ED */  jal       update_lerp
/* E068F8 80241598 0000202D */   daddu    $a0, $zero, $zero
/* E068FC 8024159C 27A20038 */  addiu     $v0, $sp, 0x38
/* E06900 802415A0 AFA20010 */  sw        $v0, 0x10($sp)
/* E06904 802415A4 8E040004 */  lw        $a0, 4($s0)
/* E06908 802415A8 8E050008 */  lw        $a1, 8($s0)
/* E0690C 802415AC 8E060000 */  lw        $a2, ($s0)
/* E06910 802415B0 8E07000C */  lw        $a3, 0xc($s0)
/* E06914 802415B4 0C04BA38 */  jal       msg_get_glyph
/* E06918 802415B8 46000586 */   mov.s    $f22, $f0
/* E0691C 802415BC 93A20042 */  lbu       $v0, 0x42($sp)
/* E06920 802415C0 3C013FE0 */  lui       $at, 0x3fe0
/* E06924 802415C4 4481C800 */  mtc1      $at, $f25
/* E06928 802415C8 4480C000 */  mtc1      $zero, $f24
/* E0692C 802415CC 44820000 */  mtc1      $v0, $f0
/* E06930 802415D0 00000000 */  nop
/* E06934 802415D4 46800021 */  cvt.d.w   $f0, $f0
/* E06938 802415D8 46380002 */  mul.d     $f0, $f0, $f24
/* E0693C 802415DC 00000000 */  nop
/* E06940 802415E0 3C140001 */  lui       $s4, 1
/* E06944 802415E4 36941630 */  ori       $s4, $s4, 0x1630
/* E06948 802415E8 4600A521 */  cvt.d.s   $f20, $f20
/* E0694C 802415EC 27B10048 */  addiu     $s1, $sp, 0x48
/* E06950 802415F0 4600F787 */  neg.s     $f30, $f30
/* E06954 802415F4 4620A500 */  add.d     $f20, $f20, $f0
/* E06958 802415F8 4406F000 */  mfc1      $a2, $f30
/* E0695C 802415FC 4407E000 */  mfc1      $a3, $f28
/* E06960 80241600 4620A520 */  cvt.s.d   $f20, $f20
/* E06964 80241604 4405A000 */  mfc1      $a1, $f20
/* E06968 80241608 0C019E40 */  jal       guTranslateF
/* E0696C 8024160C 0220202D */   daddu    $a0, $s1, $zero
/* E06970 80241610 27B00088 */  addiu     $s0, $sp, 0x88
/* E06974 80241614 0200202D */  daddu     $a0, $s0, $zero
/* E06978 80241618 4405B000 */  mfc1      $a1, $f22
/* E0697C 8024161C 4407D000 */  mfc1      $a3, $f26
/* E06980 80241620 0C019DF0 */  jal       guScaleF
/* E06984 80241624 00A0302D */   daddu    $a2, $a1, $zero
/* E06988 80241628 0200202D */  daddu     $a0, $s0, $zero
/* E0698C 8024162C 0220282D */  daddu     $a1, $s1, $zero
/* E06990 80241630 0C019D80 */  jal       guMtxCatF
/* E06994 80241634 0220302D */   daddu    $a2, $s1, $zero
/* E06998 80241638 0220202D */  daddu     $a0, $s1, $zero
/* E0699C 8024163C 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* E069A0 80241640 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* E069A4 80241644 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E069A8 80241648 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E069AC 8024164C 96450000 */  lhu       $a1, ($s2)
/* E069B0 80241650 8E620000 */  lw        $v0, ($s3)
/* E069B4 80241654 00052980 */  sll       $a1, $a1, 6
/* E069B8 80241658 00B42821 */  addu      $a1, $a1, $s4
/* E069BC 8024165C 0C019D40 */  jal       guMtxF2L
/* E069C0 80241660 00452821 */   addu     $a1, $v0, $a1
/* E069C4 80241664 3C03DA38 */  lui       $v1, 0xda38
/* E069C8 80241668 34630002 */  ori       $v1, $v1, 2
/* E069CC 8024166C 0000202D */  daddu     $a0, $zero, $zero
/* E069D0 80241670 27A50020 */  addiu     $a1, $sp, 0x20
/* E069D4 80241674 24060040 */  addiu     $a2, $zero, 0x40
/* E069D8 80241678 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* E069DC 8024167C 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* E069E0 80241680 0220382D */  daddu     $a3, $s1, $zero
/* E069E4 80241684 8E020000 */  lw        $v0, ($s0)
/* E069E8 80241688 96480000 */  lhu       $t0, ($s2)
/* E069EC 8024168C 0040482D */  daddu     $t1, $v0, $zero
/* E069F0 80241690 24420008 */  addiu     $v0, $v0, 8
/* E069F4 80241694 AE020000 */  sw        $v0, ($s0)
/* E069F8 80241698 3102FFFF */  andi      $v0, $t0, 0xffff
/* E069FC 8024169C 00021180 */  sll       $v0, $v0, 6
/* E06A00 802416A0 00541021 */  addu      $v0, $v0, $s4
/* E06A04 802416A4 AD230000 */  sw        $v1, ($t1)
/* E06A08 802416A8 8E630000 */  lw        $v1, ($s3)
/* E06A0C 802416AC 25080001 */  addiu     $t0, $t0, 1
/* E06A10 802416B0 00621821 */  addu      $v1, $v1, $v0
/* E06A14 802416B4 3C028000 */  lui       $v0, 0x8000
/* E06A18 802416B8 00621821 */  addu      $v1, $v1, $v0
/* E06A1C 802416BC AD230004 */  sw        $v1, 4($t1)
/* E06A20 802416C0 93A20042 */  lbu       $v0, 0x42($sp)
/* E06A24 802416C4 8FA3003C */  lw        $v1, 0x3c($sp)
/* E06A28 802416C8 93A90040 */  lbu       $t1, 0x40($sp)
/* E06A2C 802416CC 93AA0041 */  lbu       $t2, 0x41($sp)
/* E06A30 802416D0 44820000 */  mtc1      $v0, $f0
/* E06A34 802416D4 00000000 */  nop
/* E06A38 802416D8 46800021 */  cvt.d.w   $f0, $f0
/* E06A3C 802416DC 8FA20038 */  lw        $v0, 0x38($sp)
/* E06A40 802416E0 46380002 */  mul.d     $f0, $f0, $f24
/* E06A44 802416E4 00000000 */  nop
/* E06A48 802416E8 A6480000 */  sh        $t0, ($s2)
/* E06A4C 802416EC A7A0002E */  sh        $zero, 0x2e($sp)
/* E06A50 802416F0 A3B50030 */  sb        $s5, 0x30($sp)
/* E06A54 802416F4 AFA30024 */  sw        $v1, 0x24($sp)
/* E06A58 802416F8 A7A90028 */  sh        $t1, 0x28($sp)
/* E06A5C 802416FC A7AA002A */  sh        $t2, 0x2a($sp)
/* E06A60 80241700 AFA20020 */  sw        $v0, 0x20($sp)
/* E06A64 80241704 46200007 */  neg.d     $f0, $f0
/* E06A68 80241708 4620008D */  trunc.w.d $f2, $f0
/* E06A6C 8024170C 44021000 */  mfc1      $v0, $f2
/* E06A70 80241710 0C04EBDC */  jal       func_8013AF70
/* E06A74 80241714 A7A2002C */   sh       $v0, 0x2c($sp)
/* E06A78 80241718 3C04D838 */  lui       $a0, 0xd838
/* E06A7C 8024171C 8E020000 */  lw        $v0, ($s0)
/* E06A80 80241720 34840002 */  ori       $a0, $a0, 2
/* E06A84 80241724 0040182D */  daddu     $v1, $v0, $zero
/* E06A88 80241728 24420008 */  addiu     $v0, $v0, 8
/* E06A8C 8024172C AE020000 */  sw        $v0, ($s0)
/* E06A90 80241730 24020040 */  addiu     $v0, $zero, 0x40
/* E06A94 80241734 AC640000 */  sw        $a0, ($v1)
/* E06A98 80241738 AC620004 */  sw        $v0, 4($v1)
/* E06A9C 8024173C 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* E06AA0 80241740 8FB500DC */  lw        $s5, 0xdc($sp)
/* E06AA4 80241744 8FB400D8 */  lw        $s4, 0xd8($sp)
/* E06AA8 80241748 8FB300D4 */  lw        $s3, 0xd4($sp)
/* E06AAC 8024174C 8FB200D0 */  lw        $s2, 0xd0($sp)
/* E06AB0 80241750 8FB100CC */  lw        $s1, 0xcc($sp)
/* E06AB4 80241754 8FB000C8 */  lw        $s0, 0xc8($sp)
/* E06AB8 80241758 D7BE0110 */  ldc1      $f30, 0x110($sp)
/* E06ABC 8024175C D7BC0108 */  ldc1      $f28, 0x108($sp)
/* E06AC0 80241760 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* E06AC4 80241764 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* E06AC8 80241768 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* E06ACC 8024176C D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* E06AD0 80241770 03E00008 */  jr        $ra
/* E06AD4 80241774 27BD0118 */   addiu    $sp, $sp, 0x118
