.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414CC_DF7ECC
/* DF7ECC 802414CC 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* DF7ED0 802414D0 AFB100CC */  sw        $s1, 0xcc($sp)
/* DF7ED4 802414D4 0080882D */  daddu     $s1, $a0, $zero
/* DF7ED8 802414D8 AFB000C8 */  sw        $s0, 0xc8($sp)
/* DF7EDC 802414DC 00A0802D */  daddu     $s0, $a1, $zero
/* DF7EE0 802414E0 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* DF7EE4 802414E4 AFB500DC */  sw        $s5, 0xdc($sp)
/* DF7EE8 802414E8 AFB400D8 */  sw        $s4, 0xd8($sp)
/* DF7EEC 802414EC AFB300D4 */  sw        $s3, 0xd4($sp)
/* DF7EF0 802414F0 AFB200D0 */  sw        $s2, 0xd0($sp)
/* DF7EF4 802414F4 F7BE0110 */  sdc1      $f30, 0x110($sp)
/* DF7EF8 802414F8 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* DF7EFC 802414FC F7BA0100 */  sdc1      $f26, 0x100($sp)
/* DF7F00 80241500 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* DF7F04 80241504 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* DF7F08 80241508 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* DF7F0C 8024150C C6140010 */  lwc1      $f20, 0x10($s0)
/* DF7F10 80241510 4680A520 */  cvt.s.w   $f20, $f20
/* DF7F14 80241514 4480E000 */  mtc1      $zero, $f28
/* DF7F18 80241518 3C05437F */  lui       $a1, 0x437f
/* DF7F1C 8024151C 8E220050 */  lw        $v0, 0x50($s1)
/* DF7F20 80241520 4406E000 */  mfc1      $a2, $f28
/* DF7F24 80241524 C61E0014 */  lwc1      $f30, 0x14($s0)
/* DF7F28 80241528 4680F7A0 */  cvt.s.w   $f30, $f30
/* DF7F2C 8024152C AFA20010 */  sw        $v0, 0x10($sp)
/* DF7F30 80241530 8E070018 */  lw        $a3, 0x18($s0)
/* DF7F34 80241534 0C00A8ED */  jal       update_lerp
/* DF7F38 80241538 2404000B */   addiu    $a0, $zero, 0xb
/* DF7F3C 8024153C 4600008D */  trunc.w.s $f2, $f0
/* DF7F40 80241540 E7A20014 */  swc1      $f2, 0x14($sp)
/* DF7F44 80241544 0000202D */  daddu     $a0, $zero, $zero
/* DF7F48 80241548 24050007 */  addiu     $a1, $zero, 7
/* DF7F4C 8024154C 240600FF */  addiu     $a2, $zero, 0xff
/* DF7F50 80241550 00C0382D */  daddu     $a3, $a2, $zero
/* DF7F54 80241554 00C0A82D */  daddu     $s5, $a2, $zero
/* DF7F58 80241558 AFB50010 */  sw        $s5, 0x10($sp)
/* DF7F5C 8024155C 0C04EAA7 */  jal       func_8013AA9C
/* DF7F60 80241560 AFA00018 */   sw       $zero, 0x18($sp)
/* DF7F64 80241564 3C013F80 */  lui       $at, 0x3f80
/* DF7F68 80241568 4481D000 */  mtc1      $at, $f26
/* DF7F6C 8024156C 8E220050 */  lw        $v0, 0x50($s1)
/* DF7F70 80241570 3C063E4C */  lui       $a2, 0x3e4c
/* DF7F74 80241574 34C6CCCD */  ori       $a2, $a2, 0xcccd
/* DF7F78 80241578 4405D000 */  mfc1      $a1, $f26
/* DF7F7C 8024157C AFA20010 */  sw        $v0, 0x10($sp)
/* DF7F80 80241580 8E070018 */  lw        $a3, 0x18($s0)
/* DF7F84 80241584 0C00A8ED */  jal       update_lerp
/* DF7F88 80241588 0000202D */   daddu    $a0, $zero, $zero
/* DF7F8C 8024158C 27A20038 */  addiu     $v0, $sp, 0x38
/* DF7F90 80241590 AFA20010 */  sw        $v0, 0x10($sp)
/* DF7F94 80241594 8E040004 */  lw        $a0, 4($s0)
/* DF7F98 80241598 8E050008 */  lw        $a1, 8($s0)
/* DF7F9C 8024159C 8E060000 */  lw        $a2, ($s0)
/* DF7FA0 802415A0 8E07000C */  lw        $a3, 0xc($s0)
/* DF7FA4 802415A4 0C04BA38 */  jal       func_8012E8E0
/* DF7FA8 802415A8 46000586 */   mov.s    $f22, $f0
/* DF7FAC 802415AC 93A20042 */  lbu       $v0, 0x42($sp)
/* DF7FB0 802415B0 3C013FE0 */  lui       $at, 0x3fe0
/* DF7FB4 802415B4 4481C800 */  mtc1      $at, $f25
/* DF7FB8 802415B8 4480C000 */  mtc1      $zero, $f24
/* DF7FBC 802415BC 44820000 */  mtc1      $v0, $f0
/* DF7FC0 802415C0 00000000 */  nop       
/* DF7FC4 802415C4 46800021 */  cvt.d.w   $f0, $f0
/* DF7FC8 802415C8 46380002 */  mul.d     $f0, $f0, $f24
/* DF7FCC 802415CC 00000000 */  nop       
/* DF7FD0 802415D0 3C140001 */  lui       $s4, 1
/* DF7FD4 802415D4 36941630 */  ori       $s4, $s4, 0x1630
/* DF7FD8 802415D8 4600A521 */  cvt.d.s   $f20, $f20
/* DF7FDC 802415DC 27B10048 */  addiu     $s1, $sp, 0x48
/* DF7FE0 802415E0 4600F787 */  neg.s     $f30, $f30
/* DF7FE4 802415E4 4620A500 */  add.d     $f20, $f20, $f0
/* DF7FE8 802415E8 4406F000 */  mfc1      $a2, $f30
/* DF7FEC 802415EC 4407E000 */  mfc1      $a3, $f28
/* DF7FF0 802415F0 4620A520 */  cvt.s.d   $f20, $f20
/* DF7FF4 802415F4 4405A000 */  mfc1      $a1, $f20
/* DF7FF8 802415F8 0C019E40 */  jal       guTranslateF
/* DF7FFC 802415FC 0220202D */   daddu    $a0, $s1, $zero
/* DF8000 80241600 27B00088 */  addiu     $s0, $sp, 0x88
/* DF8004 80241604 0200202D */  daddu     $a0, $s0, $zero
/* DF8008 80241608 4405B000 */  mfc1      $a1, $f22
/* DF800C 8024160C 4407D000 */  mfc1      $a3, $f26
/* DF8010 80241610 0C019DF0 */  jal       guScaleF
/* DF8014 80241614 00A0302D */   daddu    $a2, $a1, $zero
/* DF8018 80241618 0200202D */  daddu     $a0, $s0, $zero
/* DF801C 8024161C 0220282D */  daddu     $a1, $s1, $zero
/* DF8020 80241620 0C019D80 */  jal       guMtxCatF
/* DF8024 80241624 0220302D */   daddu    $a2, $s1, $zero
/* DF8028 80241628 0220202D */  daddu     $a0, $s1, $zero
/* DF802C 8024162C 3C128007 */  lui       $s2, 0x8007
/* DF8030 80241630 265241F0 */  addiu     $s2, $s2, 0x41f0
/* DF8034 80241634 3C13800A */  lui       $s3, 0x800a
/* DF8038 80241638 2673A674 */  addiu     $s3, $s3, -0x598c
/* DF803C 8024163C 96450000 */  lhu       $a1, ($s2)
/* DF8040 80241640 8E620000 */  lw        $v0, ($s3)
/* DF8044 80241644 00052980 */  sll       $a1, $a1, 6
/* DF8048 80241648 00B42821 */  addu      $a1, $a1, $s4
/* DF804C 8024164C 0C019D40 */  jal       guMtxF2L
/* DF8050 80241650 00452821 */   addu     $a1, $v0, $a1
/* DF8054 80241654 3C03DA38 */  lui       $v1, 0xda38
/* DF8058 80241658 34630002 */  ori       $v1, $v1, 2
/* DF805C 8024165C 0000202D */  daddu     $a0, $zero, $zero
/* DF8060 80241660 27A50020 */  addiu     $a1, $sp, 0x20
/* DF8064 80241664 24060040 */  addiu     $a2, $zero, 0x40
/* DF8068 80241668 3C10800A */  lui       $s0, 0x800a
/* DF806C 8024166C 2610A66C */  addiu     $s0, $s0, -0x5994
/* DF8070 80241670 0220382D */  daddu     $a3, $s1, $zero
/* DF8074 80241674 8E020000 */  lw        $v0, ($s0)
/* DF8078 80241678 96480000 */  lhu       $t0, ($s2)
/* DF807C 8024167C 0040482D */  daddu     $t1, $v0, $zero
/* DF8080 80241680 24420008 */  addiu     $v0, $v0, 8
/* DF8084 80241684 AE020000 */  sw        $v0, ($s0)
/* DF8088 80241688 3102FFFF */  andi      $v0, $t0, 0xffff
/* DF808C 8024168C 00021180 */  sll       $v0, $v0, 6
/* DF8090 80241690 00541021 */  addu      $v0, $v0, $s4
/* DF8094 80241694 AD230000 */  sw        $v1, ($t1)
/* DF8098 80241698 8E630000 */  lw        $v1, ($s3)
/* DF809C 8024169C 25080001 */  addiu     $t0, $t0, 1
/* DF80A0 802416A0 00621821 */  addu      $v1, $v1, $v0
/* DF80A4 802416A4 3C028000 */  lui       $v0, 0x8000
/* DF80A8 802416A8 00621821 */  addu      $v1, $v1, $v0
/* DF80AC 802416AC AD230004 */  sw        $v1, 4($t1)
/* DF80B0 802416B0 93A20042 */  lbu       $v0, 0x42($sp)
/* DF80B4 802416B4 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF80B8 802416B8 93A90040 */  lbu       $t1, 0x40($sp)
/* DF80BC 802416BC 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF80C0 802416C0 44820000 */  mtc1      $v0, $f0
/* DF80C4 802416C4 00000000 */  nop       
/* DF80C8 802416C8 46800021 */  cvt.d.w   $f0, $f0
/* DF80CC 802416CC 8FA20038 */  lw        $v0, 0x38($sp)
/* DF80D0 802416D0 46380002 */  mul.d     $f0, $f0, $f24
/* DF80D4 802416D4 00000000 */  nop       
/* DF80D8 802416D8 A6480000 */  sh        $t0, ($s2)
/* DF80DC 802416DC A7A0002E */  sh        $zero, 0x2e($sp)
/* DF80E0 802416E0 A3B50030 */  sb        $s5, 0x30($sp)
/* DF80E4 802416E4 AFA30024 */  sw        $v1, 0x24($sp)
/* DF80E8 802416E8 A7A90028 */  sh        $t1, 0x28($sp)
/* DF80EC 802416EC A7AA002A */  sh        $t2, 0x2a($sp)
/* DF80F0 802416F0 AFA20020 */  sw        $v0, 0x20($sp)
/* DF80F4 802416F4 46200007 */  neg.d     $f0, $f0
/* DF80F8 802416F8 4620008D */  trunc.w.d $f2, $f0
/* DF80FC 802416FC 44021000 */  mfc1      $v0, $f2
/* DF8100 80241700 0C04EBDC */  jal       func_8013AF70
/* DF8104 80241704 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF8108 80241708 3C04D838 */  lui       $a0, 0xd838
/* DF810C 8024170C 8E020000 */  lw        $v0, ($s0)
/* DF8110 80241710 34840002 */  ori       $a0, $a0, 2
/* DF8114 80241714 0040182D */  daddu     $v1, $v0, $zero
/* DF8118 80241718 24420008 */  addiu     $v0, $v0, 8
/* DF811C 8024171C AE020000 */  sw        $v0, ($s0)
/* DF8120 80241720 24020040 */  addiu     $v0, $zero, 0x40
/* DF8124 80241724 AC640000 */  sw        $a0, ($v1)
/* DF8128 80241728 AC620004 */  sw        $v0, 4($v1)
/* DF812C 8024172C 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* DF8130 80241730 8FB500DC */  lw        $s5, 0xdc($sp)
/* DF8134 80241734 8FB400D8 */  lw        $s4, 0xd8($sp)
/* DF8138 80241738 8FB300D4 */  lw        $s3, 0xd4($sp)
/* DF813C 8024173C 8FB200D0 */  lw        $s2, 0xd0($sp)
/* DF8140 80241740 8FB100CC */  lw        $s1, 0xcc($sp)
/* DF8144 80241744 8FB000C8 */  lw        $s0, 0xc8($sp)
/* DF8148 80241748 D7BE0110 */  ldc1      $f30, 0x110($sp)
/* DF814C 8024174C D7BC0108 */  ldc1      $f28, 0x108($sp)
/* DF8150 80241750 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* DF8154 80241754 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* DF8158 80241758 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* DF815C 8024175C D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* DF8160 80241760 03E00008 */  jr        $ra
/* DF8164 80241764 27BD0118 */   addiu    $sp, $sp, 0x118
