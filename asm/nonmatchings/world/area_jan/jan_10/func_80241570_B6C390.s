.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241570_B6D900
/* B6D900 80241570 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B6D904 80241574 AFB10054 */  sw        $s1, 0x54($sp)
/* B6D908 80241578 0080882D */  daddu     $s1, $a0, $zero
/* B6D90C 8024157C AFBF005C */  sw        $ra, 0x5c($sp)
/* B6D910 80241580 AFB20058 */  sw        $s2, 0x58($sp)
/* B6D914 80241584 AFB00050 */  sw        $s0, 0x50($sp)
/* B6D918 80241588 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B6D91C 8024158C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B6D920 80241590 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B6D924 80241594 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B6D928 80241598 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B6D92C 8024159C 8E30000C */  lw        $s0, 0xc($s1)
/* B6D930 802415A0 8E050000 */  lw        $a1, ($s0)
/* B6D934 802415A4 0C0B1EAF */  jal       get_variable
/* B6D938 802415A8 26100004 */   addiu    $s0, $s0, 4
/* B6D93C 802415AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B6D940 802415B0 0040202D */   daddu    $a0, $v0, $zero
/* B6D944 802415B4 8E050000 */  lw        $a1, ($s0)
/* B6D948 802415B8 26100004 */  addiu     $s0, $s0, 4
/* B6D94C 802415BC 0220202D */  daddu     $a0, $s1, $zero
/* B6D950 802415C0 0C0B210B */  jal       get_float_variable
/* B6D954 802415C4 0040902D */   daddu    $s2, $v0, $zero
/* B6D958 802415C8 8E050000 */  lw        $a1, ($s0)
/* B6D95C 802415CC 26100004 */  addiu     $s0, $s0, 4
/* B6D960 802415D0 0220202D */  daddu     $a0, $s1, $zero
/* B6D964 802415D4 0C0B210B */  jal       get_float_variable
/* B6D968 802415D8 46000706 */   mov.s    $f28, $f0
/* B6D96C 802415DC 8E050000 */  lw        $a1, ($s0)
/* B6D970 802415E0 26100004 */  addiu     $s0, $s0, 4
/* B6D974 802415E4 0220202D */  daddu     $a0, $s1, $zero
/* B6D978 802415E8 0C0B210B */  jal       get_float_variable
/* B6D97C 802415EC 46000686 */   mov.s    $f26, $f0
/* B6D980 802415F0 0220202D */  daddu     $a0, $s1, $zero
/* B6D984 802415F4 8E050000 */  lw        $a1, ($s0)
/* B6D988 802415F8 0C0B210B */  jal       get_float_variable
/* B6D98C 802415FC 46000586 */   mov.s    $f22, $f0
/* B6D990 80241600 0240202D */  daddu     $a0, $s2, $zero
/* B6D994 80241604 0C046B4C */  jal       get_model_from_list_index
/* B6D998 80241608 46000606 */   mov.s    $f24, $f0
/* B6D99C 8024160C 0040882D */  daddu     $s1, $v0, $zero
/* B6D9A0 80241610 96220000 */  lhu       $v0, ($s1)
/* B6D9A4 80241614 30420400 */  andi      $v0, $v0, 0x400
/* B6D9A8 80241618 1440001E */  bnez      $v0, .L80241694
/* B6D9AC 8024161C 26300058 */   addiu    $s0, $s1, 0x58
/* B6D9B0 80241620 4480A000 */  mtc1      $zero, $f20
/* B6D9B4 80241624 4406B000 */  mfc1      $a2, $f22
/* B6D9B8 80241628 4405A000 */  mfc1      $a1, $f20
/* B6D9BC 8024162C 4407A000 */  mfc1      $a3, $f20
/* B6D9C0 80241630 0C019E40 */  jal       guTranslateF
/* B6D9C4 80241634 0200202D */   daddu    $a0, $s0, $zero
/* B6D9C8 80241638 4405E000 */  mfc1      $a1, $f28
/* B6D9CC 8024163C 4406D000 */  mfc1      $a2, $f26
/* B6D9D0 80241640 4407C000 */  mfc1      $a3, $f24
/* B6D9D4 80241644 0C090540 */  jal       func_80241500
/* B6D9D8 80241648 27A40010 */   addiu    $a0, $sp, 0x10
/* B6D9DC 8024164C 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D9E0 80241650 0200282D */  daddu     $a1, $s0, $zero
/* B6D9E4 80241654 0C019D80 */  jal       guMtxCatF
/* B6D9E8 80241658 0200302D */   daddu    $a2, $s0, $zero
/* B6D9EC 8024165C 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D9F0 80241660 4600B587 */  neg.s     $f22, $f22
/* B6D9F4 80241664 4405A000 */  mfc1      $a1, $f20
/* B6D9F8 80241668 4406B000 */  mfc1      $a2, $f22
/* B6D9FC 8024166C 0C019E40 */  jal       guTranslateF
/* B6DA00 80241670 00A0382D */   daddu    $a3, $a1, $zero
/* B6DA04 80241674 27A40010 */  addiu     $a0, $sp, 0x10
/* B6DA08 80241678 0200282D */  daddu     $a1, $s0, $zero
/* B6DA0C 8024167C 0C019D80 */  jal       guMtxCatF
/* B6DA10 80241680 00A0302D */   daddu    $a2, $a1, $zero
/* B6DA14 80241684 96220000 */  lhu       $v0, ($s1)
/* B6DA18 80241688 34421400 */  ori       $v0, $v0, 0x1400
/* B6DA1C 8024168C 080905C3 */  j         .L8024170C
/* B6DA20 80241690 A6220000 */   sh       $v0, ($s1)
.L80241694:
/* B6DA24 80241694 4480A000 */  mtc1      $zero, $f20
/* B6DA28 80241698 4406B000 */  mfc1      $a2, $f22
/* B6DA2C 8024169C 4405A000 */  mfc1      $a1, $f20
/* B6DA30 802416A0 4407A000 */  mfc1      $a3, $f20
/* B6DA34 802416A4 0C019E40 */  jal       guTranslateF
/* B6DA38 802416A8 27A40010 */   addiu    $a0, $sp, 0x10
/* B6DA3C 802416AC 27A40010 */  addiu     $a0, $sp, 0x10
/* B6DA40 802416B0 26300058 */  addiu     $s0, $s1, 0x58
/* B6DA44 802416B4 0200282D */  daddu     $a1, $s0, $zero
/* B6DA48 802416B8 0C019D80 */  jal       guMtxCatF
/* B6DA4C 802416BC 0200302D */   daddu    $a2, $s0, $zero
/* B6DA50 802416C0 4405E000 */  mfc1      $a1, $f28
/* B6DA54 802416C4 4406D000 */  mfc1      $a2, $f26
/* B6DA58 802416C8 4407C000 */  mfc1      $a3, $f24
/* B6DA5C 802416CC 0C090540 */  jal       func_80241500
/* B6DA60 802416D0 27A40010 */   addiu    $a0, $sp, 0x10
/* B6DA64 802416D4 27A40010 */  addiu     $a0, $sp, 0x10
/* B6DA68 802416D8 0200282D */  daddu     $a1, $s0, $zero
/* B6DA6C 802416DC 0C019D80 */  jal       guMtxCatF
/* B6DA70 802416E0 0200302D */   daddu    $a2, $s0, $zero
/* B6DA74 802416E4 27A40010 */  addiu     $a0, $sp, 0x10
/* B6DA78 802416E8 4600B587 */  neg.s     $f22, $f22
/* B6DA7C 802416EC 4405A000 */  mfc1      $a1, $f20
/* B6DA80 802416F0 4406B000 */  mfc1      $a2, $f22
/* B6DA84 802416F4 0C019E40 */  jal       guTranslateF
/* B6DA88 802416F8 00A0382D */   daddu    $a3, $a1, $zero
/* B6DA8C 802416FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B6DA90 80241700 0200282D */  daddu     $a1, $s0, $zero
/* B6DA94 80241704 0C019D80 */  jal       guMtxCatF
/* B6DA98 80241708 00A0302D */   daddu    $a2, $a1, $zero
.L8024170C:
/* B6DA9C 8024170C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B6DAA0 80241710 8FB20058 */  lw        $s2, 0x58($sp)
/* B6DAA4 80241714 8FB10054 */  lw        $s1, 0x54($sp)
/* B6DAA8 80241718 8FB00050 */  lw        $s0, 0x50($sp)
/* B6DAAC 8024171C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B6DAB0 80241720 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B6DAB4 80241724 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B6DAB8 80241728 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B6DABC 8024172C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B6DAC0 80241730 24020002 */  addiu     $v0, $zero, 2
/* B6DAC4 80241734 03E00008 */  jr        $ra
/* B6DAC8 80241738 27BD0088 */   addiu    $sp, $sp, 0x88
/* B6DACC 8024173C 00000000 */  nop       
