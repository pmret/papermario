.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240720_8239E0
/* 8239E0 80240720 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8239E4 80240724 AFB10054 */  sw        $s1, 0x54($sp)
/* 8239E8 80240728 0080882D */  daddu     $s1, $a0, $zero
/* 8239EC 8024072C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8239F0 80240730 AFB20058 */  sw        $s2, 0x58($sp)
/* 8239F4 80240734 AFB00050 */  sw        $s0, 0x50($sp)
/* 8239F8 80240738 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8239FC 8024073C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 823A00 80240740 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 823A04 80240744 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 823A08 80240748 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 823A0C 8024074C 8E30000C */  lw        $s0, 0xc($s1)
/* 823A10 80240750 8E050000 */  lw        $a1, ($s0)
/* 823A14 80240754 0C0B1EAF */  jal       get_variable
/* 823A18 80240758 26100004 */   addiu    $s0, $s0, 4
/* 823A1C 8024075C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 823A20 80240760 0040202D */   daddu    $a0, $v0, $zero
/* 823A24 80240764 8E050000 */  lw        $a1, ($s0)
/* 823A28 80240768 26100004 */  addiu     $s0, $s0, 4
/* 823A2C 8024076C 0220202D */  daddu     $a0, $s1, $zero
/* 823A30 80240770 0C0B210B */  jal       get_float_variable
/* 823A34 80240774 0040902D */   daddu    $s2, $v0, $zero
/* 823A38 80240778 8E050000 */  lw        $a1, ($s0)
/* 823A3C 8024077C 26100004 */  addiu     $s0, $s0, 4
/* 823A40 80240780 0220202D */  daddu     $a0, $s1, $zero
/* 823A44 80240784 0C0B210B */  jal       get_float_variable
/* 823A48 80240788 46000706 */   mov.s    $f28, $f0
/* 823A4C 8024078C 8E050000 */  lw        $a1, ($s0)
/* 823A50 80240790 26100004 */  addiu     $s0, $s0, 4
/* 823A54 80240794 0220202D */  daddu     $a0, $s1, $zero
/* 823A58 80240798 0C0B210B */  jal       get_float_variable
/* 823A5C 8024079C 46000686 */   mov.s    $f26, $f0
/* 823A60 802407A0 0220202D */  daddu     $a0, $s1, $zero
/* 823A64 802407A4 8E050000 */  lw        $a1, ($s0)
/* 823A68 802407A8 0C0B210B */  jal       get_float_variable
/* 823A6C 802407AC 46000586 */   mov.s    $f22, $f0
/* 823A70 802407B0 0240202D */  daddu     $a0, $s2, $zero
/* 823A74 802407B4 0C046B4C */  jal       get_model_from_list_index
/* 823A78 802407B8 46000606 */   mov.s    $f24, $f0
/* 823A7C 802407BC 0040882D */  daddu     $s1, $v0, $zero
/* 823A80 802407C0 96220000 */  lhu       $v0, ($s1)
/* 823A84 802407C4 30420400 */  andi      $v0, $v0, 0x400
/* 823A88 802407C8 1440001E */  bnez      $v0, .L80240844
/* 823A8C 802407CC 26300058 */   addiu    $s0, $s1, 0x58
/* 823A90 802407D0 4480A000 */  mtc1      $zero, $f20
/* 823A94 802407D4 4406B000 */  mfc1      $a2, $f22
/* 823A98 802407D8 4405A000 */  mfc1      $a1, $f20
/* 823A9C 802407DC 4407A000 */  mfc1      $a3, $f20
/* 823AA0 802407E0 0C019E40 */  jal       guTranslateF
/* 823AA4 802407E4 0200202D */   daddu    $a0, $s0, $zero
/* 823AA8 802407E8 4405E000 */  mfc1      $a1, $f28
/* 823AAC 802407EC 4406D000 */  mfc1      $a2, $f26
/* 823AB0 802407F0 4407C000 */  mfc1      $a3, $f24
/* 823AB4 802407F4 0C0901AC */  jal       func_802406B0_823970
/* 823AB8 802407F8 27A40010 */   addiu    $a0, $sp, 0x10
/* 823ABC 802407FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 823AC0 80240800 0200282D */  daddu     $a1, $s0, $zero
/* 823AC4 80240804 0C019D80 */  jal       guMtxCatF
/* 823AC8 80240808 0200302D */   daddu    $a2, $s0, $zero
/* 823ACC 8024080C 27A40010 */  addiu     $a0, $sp, 0x10
/* 823AD0 80240810 4600B587 */  neg.s     $f22, $f22
/* 823AD4 80240814 4405A000 */  mfc1      $a1, $f20
/* 823AD8 80240818 4406B000 */  mfc1      $a2, $f22
/* 823ADC 8024081C 0C019E40 */  jal       guTranslateF
/* 823AE0 80240820 00A0382D */   daddu    $a3, $a1, $zero
/* 823AE4 80240824 27A40010 */  addiu     $a0, $sp, 0x10
/* 823AE8 80240828 0200282D */  daddu     $a1, $s0, $zero
/* 823AEC 8024082C 0C019D80 */  jal       guMtxCatF
/* 823AF0 80240830 00A0302D */   daddu    $a2, $a1, $zero
/* 823AF4 80240834 96220000 */  lhu       $v0, ($s1)
/* 823AF8 80240838 34421400 */  ori       $v0, $v0, 0x1400
/* 823AFC 8024083C 0809022F */  j         .L802408BC
/* 823B00 80240840 A6220000 */   sh       $v0, ($s1)
.L80240844:
/* 823B04 80240844 4480A000 */  mtc1      $zero, $f20
/* 823B08 80240848 4406B000 */  mfc1      $a2, $f22
/* 823B0C 8024084C 4405A000 */  mfc1      $a1, $f20
/* 823B10 80240850 4407A000 */  mfc1      $a3, $f20
/* 823B14 80240854 0C019E40 */  jal       guTranslateF
/* 823B18 80240858 27A40010 */   addiu    $a0, $sp, 0x10
/* 823B1C 8024085C 27A40010 */  addiu     $a0, $sp, 0x10
/* 823B20 80240860 26300058 */  addiu     $s0, $s1, 0x58
/* 823B24 80240864 0200282D */  daddu     $a1, $s0, $zero
/* 823B28 80240868 0C019D80 */  jal       guMtxCatF
/* 823B2C 8024086C 0200302D */   daddu    $a2, $s0, $zero
/* 823B30 80240870 4405E000 */  mfc1      $a1, $f28
/* 823B34 80240874 4406D000 */  mfc1      $a2, $f26
/* 823B38 80240878 4407C000 */  mfc1      $a3, $f24
/* 823B3C 8024087C 0C0901AC */  jal       func_802406B0_823970
/* 823B40 80240880 27A40010 */   addiu    $a0, $sp, 0x10
/* 823B44 80240884 27A40010 */  addiu     $a0, $sp, 0x10
/* 823B48 80240888 0200282D */  daddu     $a1, $s0, $zero
/* 823B4C 8024088C 0C019D80 */  jal       guMtxCatF
/* 823B50 80240890 0200302D */   daddu    $a2, $s0, $zero
/* 823B54 80240894 27A40010 */  addiu     $a0, $sp, 0x10
/* 823B58 80240898 4600B587 */  neg.s     $f22, $f22
/* 823B5C 8024089C 4405A000 */  mfc1      $a1, $f20
/* 823B60 802408A0 4406B000 */  mfc1      $a2, $f22
/* 823B64 802408A4 0C019E40 */  jal       guTranslateF
/* 823B68 802408A8 00A0382D */   daddu    $a3, $a1, $zero
/* 823B6C 802408AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 823B70 802408B0 0200282D */  daddu     $a1, $s0, $zero
/* 823B74 802408B4 0C019D80 */  jal       guMtxCatF
/* 823B78 802408B8 00A0302D */   daddu    $a2, $a1, $zero
.L802408BC:
/* 823B7C 802408BC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 823B80 802408C0 8FB20058 */  lw        $s2, 0x58($sp)
/* 823B84 802408C4 8FB10054 */  lw        $s1, 0x54($sp)
/* 823B88 802408C8 8FB00050 */  lw        $s0, 0x50($sp)
/* 823B8C 802408CC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 823B90 802408D0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 823B94 802408D4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 823B98 802408D8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 823B9C 802408DC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 823BA0 802408E0 24020002 */  addiu     $v0, $zero, 2
/* 823BA4 802408E4 03E00008 */  jr        $ra
/* 823BA8 802408E8 27BD0088 */   addiu    $sp, $sp, 0x88
/* 823BAC 802408EC 00000000 */  nop       
