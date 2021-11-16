.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240550_E058B0
/* E058B0 80240550 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* E058B4 80240554 AFB200D0 */  sw        $s2, 0xd0($sp)
/* E058B8 80240558 0080902D */  daddu     $s2, $a0, $zero
/* E058BC 8024055C AFB000C8 */  sw        $s0, 0xc8($sp)
/* E058C0 80240560 00A0802D */  daddu     $s0, $a1, $zero
/* E058C4 80240564 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* E058C8 80240568 AFB500DC */  sw        $s5, 0xdc($sp)
/* E058CC 8024056C AFB400D8 */  sw        $s4, 0xd8($sp)
/* E058D0 80240570 AFB300D4 */  sw        $s3, 0xd4($sp)
/* E058D4 80240574 AFB100CC */  sw        $s1, 0xcc($sp)
/* E058D8 80240578 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* E058DC 8024057C F7BA0100 */  sdc1      $f26, 0x100($sp)
/* E058E0 80240580 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* E058E4 80240584 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* E058E8 80240588 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* E058EC 8024058C C6160010 */  lwc1      $f22, 0x10($s0)
/* E058F0 80240590 4680B5A0 */  cvt.s.w   $f22, $f22
/* E058F4 80240594 3C054180 */  lui       $a1, 0x4180
/* E058F8 80240598 3C064396 */  lui       $a2, 0x4396
/* E058FC 8024059C 8E42001C */  lw        $v0, 0x1c($s2)
/* E05900 802405A0 C61C0014 */  lwc1      $f28, 0x14($s0)
/* E05904 802405A4 4680E720 */  cvt.s.w   $f28, $f28
/* E05908 802405A8 AFA20010 */  sw        $v0, 0x10($sp)
/* E0590C 802405AC 8E070018 */  lw        $a3, 0x18($s0)
/* E05910 802405B0 0C00A8ED */  jal       update_lerp
/* E05914 802405B4 2404000C */   addiu    $a0, $zero, 0xc
/* E05918 802405B8 3C01437F */  lui       $at, 0x437f
/* E0591C 802405BC 44811000 */  mtc1      $at, $f2
/* E05920 802405C0 00000000 */  nop
/* E05924 802405C4 4600103C */  c.lt.s    $f2, $f0
/* E05928 802405C8 00000000 */  nop
/* E0592C 802405CC 45000002 */  bc1f      .L802405D8
/* E05930 802405D0 27B10038 */   addiu    $s1, $sp, 0x38
/* E05934 802405D4 46001006 */  mov.s     $f0, $f2
.L802405D8:
/* E05938 802405D8 4600010D */  trunc.w.s $f4, $f0
/* E0593C 802405DC E7A40014 */  swc1      $f4, 0x14($sp)
/* E05940 802405E0 0000202D */  daddu     $a0, $zero, $zero
/* E05944 802405E4 24050007 */  addiu     $a1, $zero, 7
/* E05948 802405E8 240600FF */  addiu     $a2, $zero, 0xff
/* E0594C 802405EC 00C0382D */  daddu     $a3, $a2, $zero
/* E05950 802405F0 00C0A82D */  daddu     $s5, $a2, $zero
/* E05954 802405F4 AFB50010 */  sw        $s5, 0x10($sp)
/* E05958 802405F8 0C04EAA7 */  jal       fold_update
/* E0595C 802405FC AFA00018 */   sw       $zero, 0x18($sp)
/* E05960 80240600 8E42001C */  lw        $v0, 0x1c($s2)
/* E05964 80240604 3C053E4C */  lui       $a1, 0x3e4c
/* E05968 80240608 34A5CCCD */  ori       $a1, $a1, 0xcccd
/* E0596C 8024060C 3C064000 */  lui       $a2, 0x4000
/* E05970 80240610 AFA20010 */  sw        $v0, 0x10($sp)
/* E05974 80240614 8E070018 */  lw        $a3, 0x18($s0)
/* E05978 80240618 0C00A8ED */  jal       update_lerp
/* E0597C 8024061C 0000202D */   daddu    $a0, $zero, $zero
/* E05980 80240620 46000506 */  mov.s     $f20, $f0
/* E05984 80240624 3C013FF0 */  lui       $at, 0x3ff0
/* E05988 80240628 4481C800 */  mtc1      $at, $f25
/* E0598C 8024062C 4480C000 */  mtc1      $zero, $f24
/* E05990 80240630 4600A021 */  cvt.d.s   $f0, $f20
/* E05994 80240634 4620C03C */  c.lt.d    $f24, $f0
/* E05998 80240638 00000000 */  nop
/* E0599C 8024063C 45000003 */  bc1f      .L8024064C
/* E059A0 80240640 AFB10010 */   sw       $s1, 0x10($sp)
/* E059A4 80240644 3C013F80 */  lui       $at, 0x3f80
/* E059A8 80240648 4481A000 */  mtc1      $at, $f20
.L8024064C:
/* E059AC 8024064C 8E040004 */  lw        $a0, 4($s0)
/* E059B0 80240650 8E050008 */  lw        $a1, 8($s0)
/* E059B4 80240654 8E060000 */  lw        $a2, ($s0)
/* E059B8 80240658 0C04BA38 */  jal       msg_get_glyph
/* E059BC 8024065C 8E07000C */   lw       $a3, 0xc($s0)
/* E059C0 80240660 93A20042 */  lbu       $v0, 0x42($sp)
/* E059C4 80240664 3C013FE0 */  lui       $at, 0x3fe0
/* E059C8 80240668 4481D800 */  mtc1      $at, $f27
/* E059CC 8024066C 4480D000 */  mtc1      $zero, $f26
/* E059D0 80240670 44820000 */  mtc1      $v0, $f0
/* E059D4 80240674 00000000 */  nop
/* E059D8 80240678 46800021 */  cvt.d.w   $f0, $f0
/* E059DC 8024067C 463A0002 */  mul.d     $f0, $f0, $f26
/* E059E0 80240680 00000000 */  nop
/* E059E4 80240684 4600B0A1 */  cvt.d.s   $f2, $f22
/* E059E8 80240688 46201080 */  add.d     $f2, $f2, $f0
/* E059EC 8024068C 27B40048 */  addiu     $s4, $sp, 0x48
/* E059F0 80240690 0280202D */  daddu     $a0, $s4, $zero
/* E059F4 80240694 4600E707 */  neg.s     $f28, $f28
/* E059F8 80240698 4406E000 */  mfc1      $a2, $f28
/* E059FC 8024069C 462010A0 */  cvt.s.d   $f2, $f2
/* E05A00 802406A0 44051000 */  mfc1      $a1, $f2
/* E05A04 802406A4 0C019E40 */  jal       guTranslateF
/* E05A08 802406A8 0000382D */   daddu    $a3, $zero, $zero
/* E05A0C 802406AC 4600A021 */  cvt.d.s   $f0, $f20
/* E05A10 802406B0 46380032 */  c.eq.d    $f0, $f24
/* E05A14 802406B4 00000000 */  nop
/* E05A18 802406B8 4501000C */  bc1t      .L802406EC
/* E05A1C 802406BC 3C130001 */   lui      $s3, 1
/* E05A20 802406C0 27B00088 */  addiu     $s0, $sp, 0x88
/* E05A24 802406C4 0200202D */  daddu     $a0, $s0, $zero
/* E05A28 802406C8 4405A000 */  mfc1      $a1, $f20
/* E05A2C 802406CC 3C073F80 */  lui       $a3, 0x3f80
/* E05A30 802406D0 0C019DF0 */  jal       guScaleF
/* E05A34 802406D4 00A0302D */   daddu    $a2, $a1, $zero
/* E05A38 802406D8 0200202D */  daddu     $a0, $s0, $zero
/* E05A3C 802406DC 0280282D */  daddu     $a1, $s4, $zero
/* E05A40 802406E0 0C019D80 */  jal       guMtxCatF
/* E05A44 802406E4 0280302D */   daddu    $a2, $s4, $zero
/* E05A48 802406E8 3C130001 */  lui       $s3, 1
.L802406EC:
/* E05A4C 802406EC 36731630 */  ori       $s3, $s3, 0x1630
/* E05A50 802406F0 0280202D */  daddu     $a0, $s4, $zero
/* E05A54 802406F4 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* E05A58 802406F8 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* E05A5C 802406FC 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* E05A60 80240700 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* E05A64 80240704 96250000 */  lhu       $a1, ($s1)
/* E05A68 80240708 8E420000 */  lw        $v0, ($s2)
/* E05A6C 8024070C 00052980 */  sll       $a1, $a1, 6
/* E05A70 80240710 00B32821 */  addu      $a1, $a1, $s3
/* E05A74 80240714 0C019D40 */  jal       guMtxF2L
/* E05A78 80240718 00452821 */   addu     $a1, $v0, $a1
/* E05A7C 8024071C 3C03DA38 */  lui       $v1, 0xda38
/* E05A80 80240720 34630002 */  ori       $v1, $v1, 2
/* E05A84 80240724 0000202D */  daddu     $a0, $zero, $zero
/* E05A88 80240728 27A50020 */  addiu     $a1, $sp, 0x20
/* E05A8C 8024072C 24060040 */  addiu     $a2, $zero, 0x40
/* E05A90 80240730 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* E05A94 80240734 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* E05A98 80240738 0280382D */  daddu     $a3, $s4, $zero
/* E05A9C 8024073C 8E020000 */  lw        $v0, ($s0)
/* E05AA0 80240740 96280000 */  lhu       $t0, ($s1)
/* E05AA4 80240744 0040482D */  daddu     $t1, $v0, $zero
/* E05AA8 80240748 24420008 */  addiu     $v0, $v0, 8
/* E05AAC 8024074C AE020000 */  sw        $v0, ($s0)
/* E05AB0 80240750 3102FFFF */  andi      $v0, $t0, 0xffff
/* E05AB4 80240754 00021180 */  sll       $v0, $v0, 6
/* E05AB8 80240758 00531021 */  addu      $v0, $v0, $s3
/* E05ABC 8024075C AD230000 */  sw        $v1, ($t1)
/* E05AC0 80240760 8E430000 */  lw        $v1, ($s2)
/* E05AC4 80240764 25080001 */  addiu     $t0, $t0, 1
/* E05AC8 80240768 00621821 */  addu      $v1, $v1, $v0
/* E05ACC 8024076C 3C028000 */  lui       $v0, 0x8000
/* E05AD0 80240770 00621821 */  addu      $v1, $v1, $v0
/* E05AD4 80240774 AD230004 */  sw        $v1, 4($t1)
/* E05AD8 80240778 93A20042 */  lbu       $v0, 0x42($sp)
/* E05ADC 8024077C 8FA3003C */  lw        $v1, 0x3c($sp)
/* E05AE0 80240780 93A90040 */  lbu       $t1, 0x40($sp)
/* E05AE4 80240784 93AA0041 */  lbu       $t2, 0x41($sp)
/* E05AE8 80240788 44820000 */  mtc1      $v0, $f0
/* E05AEC 8024078C 00000000 */  nop
/* E05AF0 80240790 46800021 */  cvt.d.w   $f0, $f0
/* E05AF4 80240794 8FA20038 */  lw        $v0, 0x38($sp)
/* E05AF8 80240798 463A0002 */  mul.d     $f0, $f0, $f26
/* E05AFC 8024079C 00000000 */  nop
/* E05B00 802407A0 A6280000 */  sh        $t0, ($s1)
/* E05B04 802407A4 A7A0002E */  sh        $zero, 0x2e($sp)
/* E05B08 802407A8 A3B50030 */  sb        $s5, 0x30($sp)
/* E05B0C 802407AC AFA30024 */  sw        $v1, 0x24($sp)
/* E05B10 802407B0 A7A90028 */  sh        $t1, 0x28($sp)
/* E05B14 802407B4 A7AA002A */  sh        $t2, 0x2a($sp)
/* E05B18 802407B8 AFA20020 */  sw        $v0, 0x20($sp)
/* E05B1C 802407BC 46200007 */  neg.d     $f0, $f0
/* E05B20 802407C0 4620010D */  trunc.w.d $f4, $f0
/* E05B24 802407C4 44022000 */  mfc1      $v0, $f4
/* E05B28 802407C8 0C04EBDC */  jal       fold_appendGfx_component
/* E05B2C 802407CC A7A2002C */   sh       $v0, 0x2c($sp)
/* E05B30 802407D0 3C04D838 */  lui       $a0, 0xd838
/* E05B34 802407D4 8E020000 */  lw        $v0, ($s0)
/* E05B38 802407D8 34840002 */  ori       $a0, $a0, 2
/* E05B3C 802407DC 0040182D */  daddu     $v1, $v0, $zero
/* E05B40 802407E0 24420008 */  addiu     $v0, $v0, 8
/* E05B44 802407E4 AE020000 */  sw        $v0, ($s0)
/* E05B48 802407E8 24020040 */  addiu     $v0, $zero, 0x40
/* E05B4C 802407EC AC640000 */  sw        $a0, ($v1)
/* E05B50 802407F0 AC620004 */  sw        $v0, 4($v1)
/* E05B54 802407F4 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* E05B58 802407F8 8FB500DC */  lw        $s5, 0xdc($sp)
/* E05B5C 802407FC 8FB400D8 */  lw        $s4, 0xd8($sp)
/* E05B60 80240800 8FB300D4 */  lw        $s3, 0xd4($sp)
/* E05B64 80240804 8FB200D0 */  lw        $s2, 0xd0($sp)
/* E05B68 80240808 8FB100CC */  lw        $s1, 0xcc($sp)
/* E05B6C 8024080C 8FB000C8 */  lw        $s0, 0xc8($sp)
/* E05B70 80240810 D7BC0108 */  ldc1      $f28, 0x108($sp)
/* E05B74 80240814 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* E05B78 80240818 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* E05B7C 8024081C D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* E05B80 80240820 D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* E05B84 80240824 03E00008 */  jr        $ra
/* E05B88 80240828 27BD0110 */   addiu    $sp, $sp, 0x110
