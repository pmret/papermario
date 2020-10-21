.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241640_940BF0
/* 940BF0 80241640 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 940BF4 80241644 AFB10054 */  sw        $s1, 0x54($sp)
/* 940BF8 80241648 0080882D */  daddu     $s1, $a0, $zero
/* 940BFC 8024164C AFBF005C */  sw        $ra, 0x5c($sp)
/* 940C00 80241650 AFB20058 */  sw        $s2, 0x58($sp)
/* 940C04 80241654 AFB00050 */  sw        $s0, 0x50($sp)
/* 940C08 80241658 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 940C0C 8024165C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 940C10 80241660 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 940C14 80241664 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 940C18 80241668 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 940C1C 8024166C 8E30000C */  lw        $s0, 0xc($s1)
/* 940C20 80241670 8E050000 */  lw        $a1, ($s0)
/* 940C24 80241674 0C0B1EAF */  jal       get_variable
/* 940C28 80241678 26100004 */   addiu    $s0, $s0, 4
/* 940C2C 8024167C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 940C30 80241680 0040202D */   daddu    $a0, $v0, $zero
/* 940C34 80241684 8E050000 */  lw        $a1, ($s0)
/* 940C38 80241688 26100004 */  addiu     $s0, $s0, 4
/* 940C3C 8024168C 0220202D */  daddu     $a0, $s1, $zero
/* 940C40 80241690 0C0B210B */  jal       get_float_variable
/* 940C44 80241694 0040902D */   daddu    $s2, $v0, $zero
/* 940C48 80241698 8E050000 */  lw        $a1, ($s0)
/* 940C4C 8024169C 26100004 */  addiu     $s0, $s0, 4
/* 940C50 802416A0 0220202D */  daddu     $a0, $s1, $zero
/* 940C54 802416A4 0C0B210B */  jal       get_float_variable
/* 940C58 802416A8 46000706 */   mov.s    $f28, $f0
/* 940C5C 802416AC 8E050000 */  lw        $a1, ($s0)
/* 940C60 802416B0 26100004 */  addiu     $s0, $s0, 4
/* 940C64 802416B4 0220202D */  daddu     $a0, $s1, $zero
/* 940C68 802416B8 0C0B210B */  jal       get_float_variable
/* 940C6C 802416BC 46000686 */   mov.s    $f26, $f0
/* 940C70 802416C0 0220202D */  daddu     $a0, $s1, $zero
/* 940C74 802416C4 8E050000 */  lw        $a1, ($s0)
/* 940C78 802416C8 0C0B210B */  jal       get_float_variable
/* 940C7C 802416CC 46000586 */   mov.s    $f22, $f0
/* 940C80 802416D0 0240202D */  daddu     $a0, $s2, $zero
/* 940C84 802416D4 0C046B4C */  jal       get_model_from_list_index
/* 940C88 802416D8 46000606 */   mov.s    $f24, $f0
/* 940C8C 802416DC 0040882D */  daddu     $s1, $v0, $zero
/* 940C90 802416E0 96220000 */  lhu       $v0, ($s1)
/* 940C94 802416E4 30420400 */  andi      $v0, $v0, 0x400
/* 940C98 802416E8 1440001E */  bnez      $v0, .L80241764
/* 940C9C 802416EC 26300058 */   addiu    $s0, $s1, 0x58
/* 940CA0 802416F0 4480A000 */  mtc1      $zero, $f20
/* 940CA4 802416F4 4406B000 */  mfc1      $a2, $f22
/* 940CA8 802416F8 4405A000 */  mfc1      $a1, $f20
/* 940CAC 802416FC 4407A000 */  mfc1      $a3, $f20
/* 940CB0 80241700 0C019E40 */  jal       guTranslateF
/* 940CB4 80241704 0200202D */   daddu    $a0, $s0, $zero
/* 940CB8 80241708 4405E000 */  mfc1      $a1, $f28
/* 940CBC 8024170C 4406D000 */  mfc1      $a2, $f26
/* 940CC0 80241710 4407C000 */  mfc1      $a3, $f24
/* 940CC4 80241714 0C090574 */  jal       func_802415D0_940B80
/* 940CC8 80241718 27A40010 */   addiu    $a0, $sp, 0x10
/* 940CCC 8024171C 27A40010 */  addiu     $a0, $sp, 0x10
/* 940CD0 80241720 0200282D */  daddu     $a1, $s0, $zero
/* 940CD4 80241724 0C019D80 */  jal       guMtxCatF
/* 940CD8 80241728 0200302D */   daddu    $a2, $s0, $zero
/* 940CDC 8024172C 27A40010 */  addiu     $a0, $sp, 0x10
/* 940CE0 80241730 4600B587 */  neg.s     $f22, $f22
/* 940CE4 80241734 4405A000 */  mfc1      $a1, $f20
/* 940CE8 80241738 4406B000 */  mfc1      $a2, $f22
/* 940CEC 8024173C 0C019E40 */  jal       guTranslateF
/* 940CF0 80241740 00A0382D */   daddu    $a3, $a1, $zero
/* 940CF4 80241744 27A40010 */  addiu     $a0, $sp, 0x10
/* 940CF8 80241748 0200282D */  daddu     $a1, $s0, $zero
/* 940CFC 8024174C 0C019D80 */  jal       guMtxCatF
/* 940D00 80241750 00A0302D */   daddu    $a2, $a1, $zero
/* 940D04 80241754 96220000 */  lhu       $v0, ($s1)
/* 940D08 80241758 34421400 */  ori       $v0, $v0, 0x1400
/* 940D0C 8024175C 080905F7 */  j         .L802417DC
/* 940D10 80241760 A6220000 */   sh       $v0, ($s1)
.L80241764:
/* 940D14 80241764 4480A000 */  mtc1      $zero, $f20
/* 940D18 80241768 4406B000 */  mfc1      $a2, $f22
/* 940D1C 8024176C 4405A000 */  mfc1      $a1, $f20
/* 940D20 80241770 4407A000 */  mfc1      $a3, $f20
/* 940D24 80241774 0C019E40 */  jal       guTranslateF
/* 940D28 80241778 27A40010 */   addiu    $a0, $sp, 0x10
/* 940D2C 8024177C 27A40010 */  addiu     $a0, $sp, 0x10
/* 940D30 80241780 26300058 */  addiu     $s0, $s1, 0x58
/* 940D34 80241784 0200282D */  daddu     $a1, $s0, $zero
/* 940D38 80241788 0C019D80 */  jal       guMtxCatF
/* 940D3C 8024178C 0200302D */   daddu    $a2, $s0, $zero
/* 940D40 80241790 4405E000 */  mfc1      $a1, $f28
/* 940D44 80241794 4406D000 */  mfc1      $a2, $f26
/* 940D48 80241798 4407C000 */  mfc1      $a3, $f24
/* 940D4C 8024179C 0C090574 */  jal       func_802415D0_940B80
/* 940D50 802417A0 27A40010 */   addiu    $a0, $sp, 0x10
/* 940D54 802417A4 27A40010 */  addiu     $a0, $sp, 0x10
/* 940D58 802417A8 0200282D */  daddu     $a1, $s0, $zero
/* 940D5C 802417AC 0C019D80 */  jal       guMtxCatF
/* 940D60 802417B0 0200302D */   daddu    $a2, $s0, $zero
/* 940D64 802417B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 940D68 802417B8 4600B587 */  neg.s     $f22, $f22
/* 940D6C 802417BC 4405A000 */  mfc1      $a1, $f20
/* 940D70 802417C0 4406B000 */  mfc1      $a2, $f22
/* 940D74 802417C4 0C019E40 */  jal       guTranslateF
/* 940D78 802417C8 00A0382D */   daddu    $a3, $a1, $zero
/* 940D7C 802417CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 940D80 802417D0 0200282D */  daddu     $a1, $s0, $zero
/* 940D84 802417D4 0C019D80 */  jal       guMtxCatF
/* 940D88 802417D8 00A0302D */   daddu    $a2, $a1, $zero
.L802417DC:
/* 940D8C 802417DC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 940D90 802417E0 8FB20058 */  lw        $s2, 0x58($sp)
/* 940D94 802417E4 8FB10054 */  lw        $s1, 0x54($sp)
/* 940D98 802417E8 8FB00050 */  lw        $s0, 0x50($sp)
/* 940D9C 802417EC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 940DA0 802417F0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 940DA4 802417F4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 940DA8 802417F8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 940DAC 802417FC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 940DB0 80241800 24020002 */  addiu     $v0, $zero, 2
/* 940DB4 80241804 03E00008 */  jr        $ra
/* 940DB8 80241808 27BD0088 */   addiu    $sp, $sp, 0x88
/* 940DBC 8024180C 00000000 */  nop       
