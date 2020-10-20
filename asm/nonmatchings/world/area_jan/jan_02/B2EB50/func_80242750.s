.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242750
/* B2EBC0 80242750 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B2EBC4 80242754 AFB10054 */  sw        $s1, 0x54($sp)
/* B2EBC8 80242758 0080882D */  daddu     $s1, $a0, $zero
/* B2EBCC 8024275C AFBF005C */  sw        $ra, 0x5c($sp)
/* B2EBD0 80242760 AFB20058 */  sw        $s2, 0x58($sp)
/* B2EBD4 80242764 AFB00050 */  sw        $s0, 0x50($sp)
/* B2EBD8 80242768 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B2EBDC 8024276C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B2EBE0 80242770 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B2EBE4 80242774 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B2EBE8 80242778 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B2EBEC 8024277C 8E30000C */  lw        $s0, 0xc($s1)
/* B2EBF0 80242780 8E050000 */  lw        $a1, ($s0)
/* B2EBF4 80242784 0C0B1EAF */  jal       get_variable
/* B2EBF8 80242788 26100004 */   addiu    $s0, $s0, 4
/* B2EBFC 8024278C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B2EC00 80242790 0040202D */   daddu    $a0, $v0, $zero
/* B2EC04 80242794 8E050000 */  lw        $a1, ($s0)
/* B2EC08 80242798 26100004 */  addiu     $s0, $s0, 4
/* B2EC0C 8024279C 0220202D */  daddu     $a0, $s1, $zero
/* B2EC10 802427A0 0C0B210B */  jal       get_float_variable
/* B2EC14 802427A4 0040902D */   daddu    $s2, $v0, $zero
/* B2EC18 802427A8 8E050000 */  lw        $a1, ($s0)
/* B2EC1C 802427AC 26100004 */  addiu     $s0, $s0, 4
/* B2EC20 802427B0 0220202D */  daddu     $a0, $s1, $zero
/* B2EC24 802427B4 0C0B210B */  jal       get_float_variable
/* B2EC28 802427B8 46000706 */   mov.s    $f28, $f0
/* B2EC2C 802427BC 8E050000 */  lw        $a1, ($s0)
/* B2EC30 802427C0 26100004 */  addiu     $s0, $s0, 4
/* B2EC34 802427C4 0220202D */  daddu     $a0, $s1, $zero
/* B2EC38 802427C8 0C0B210B */  jal       get_float_variable
/* B2EC3C 802427CC 46000686 */   mov.s    $f26, $f0
/* B2EC40 802427D0 0220202D */  daddu     $a0, $s1, $zero
/* B2EC44 802427D4 8E050000 */  lw        $a1, ($s0)
/* B2EC48 802427D8 0C0B210B */  jal       get_float_variable
/* B2EC4C 802427DC 46000586 */   mov.s    $f22, $f0
/* B2EC50 802427E0 0240202D */  daddu     $a0, $s2, $zero
/* B2EC54 802427E4 0C046B4C */  jal       get_model_from_list_index
/* B2EC58 802427E8 46000606 */   mov.s    $f24, $f0
/* B2EC5C 802427EC 0040882D */  daddu     $s1, $v0, $zero
/* B2EC60 802427F0 96220000 */  lhu       $v0, ($s1)
/* B2EC64 802427F4 30420400 */  andi      $v0, $v0, 0x400
/* B2EC68 802427F8 1440001E */  bnez      $v0, .L80242874
/* B2EC6C 802427FC 26300058 */   addiu    $s0, $s1, 0x58
/* B2EC70 80242800 4480A000 */  mtc1      $zero, $f20
/* B2EC74 80242804 4406B000 */  mfc1      $a2, $f22
/* B2EC78 80242808 4405A000 */  mfc1      $a1, $f20
/* B2EC7C 8024280C 4407A000 */  mfc1      $a3, $f20
/* B2EC80 80242810 0C019E40 */  jal       guTranslateF
/* B2EC84 80242814 0200202D */   daddu    $a0, $s0, $zero
/* B2EC88 80242818 4405E000 */  mfc1      $a1, $f28
/* B2EC8C 8024281C 4406D000 */  mfc1      $a2, $f26
/* B2EC90 80242820 4407C000 */  mfc1      $a3, $f24
/* B2EC94 80242824 0C0909B8 */  jal       func_802426E0
/* B2EC98 80242828 27A40010 */   addiu    $a0, $sp, 0x10
/* B2EC9C 8024282C 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ECA0 80242830 0200282D */  daddu     $a1, $s0, $zero
/* B2ECA4 80242834 0C019D80 */  jal       guMtxCatF
/* B2ECA8 80242838 0200302D */   daddu    $a2, $s0, $zero
/* B2ECAC 8024283C 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ECB0 80242840 4600B587 */  neg.s     $f22, $f22
/* B2ECB4 80242844 4405A000 */  mfc1      $a1, $f20
/* B2ECB8 80242848 4406B000 */  mfc1      $a2, $f22
/* B2ECBC 8024284C 0C019E40 */  jal       guTranslateF
/* B2ECC0 80242850 00A0382D */   daddu    $a3, $a1, $zero
/* B2ECC4 80242854 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ECC8 80242858 0200282D */  daddu     $a1, $s0, $zero
/* B2ECCC 8024285C 0C019D80 */  jal       guMtxCatF
/* B2ECD0 80242860 00A0302D */   daddu    $a2, $a1, $zero
/* B2ECD4 80242864 96220000 */  lhu       $v0, ($s1)
/* B2ECD8 80242868 34421400 */  ori       $v0, $v0, 0x1400
/* B2ECDC 8024286C 08090A3B */  j         .L802428EC
/* B2ECE0 80242870 A6220000 */   sh       $v0, ($s1)
.L80242874:
/* B2ECE4 80242874 4480A000 */  mtc1      $zero, $f20
/* B2ECE8 80242878 4406B000 */  mfc1      $a2, $f22
/* B2ECEC 8024287C 4405A000 */  mfc1      $a1, $f20
/* B2ECF0 80242880 4407A000 */  mfc1      $a3, $f20
/* B2ECF4 80242884 0C019E40 */  jal       guTranslateF
/* B2ECF8 80242888 27A40010 */   addiu    $a0, $sp, 0x10
/* B2ECFC 8024288C 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ED00 80242890 26300058 */  addiu     $s0, $s1, 0x58
/* B2ED04 80242894 0200282D */  daddu     $a1, $s0, $zero
/* B2ED08 80242898 0C019D80 */  jal       guMtxCatF
/* B2ED0C 8024289C 0200302D */   daddu    $a2, $s0, $zero
/* B2ED10 802428A0 4405E000 */  mfc1      $a1, $f28
/* B2ED14 802428A4 4406D000 */  mfc1      $a2, $f26
/* B2ED18 802428A8 4407C000 */  mfc1      $a3, $f24
/* B2ED1C 802428AC 0C0909B8 */  jal       func_802426E0
/* B2ED20 802428B0 27A40010 */   addiu    $a0, $sp, 0x10
/* B2ED24 802428B4 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ED28 802428B8 0200282D */  daddu     $a1, $s0, $zero
/* B2ED2C 802428BC 0C019D80 */  jal       guMtxCatF
/* B2ED30 802428C0 0200302D */   daddu    $a2, $s0, $zero
/* B2ED34 802428C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ED38 802428C8 4600B587 */  neg.s     $f22, $f22
/* B2ED3C 802428CC 4405A000 */  mfc1      $a1, $f20
/* B2ED40 802428D0 4406B000 */  mfc1      $a2, $f22
/* B2ED44 802428D4 0C019E40 */  jal       guTranslateF
/* B2ED48 802428D8 00A0382D */   daddu    $a3, $a1, $zero
/* B2ED4C 802428DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B2ED50 802428E0 0200282D */  daddu     $a1, $s0, $zero
/* B2ED54 802428E4 0C019D80 */  jal       guMtxCatF
/* B2ED58 802428E8 00A0302D */   daddu    $a2, $a1, $zero
.L802428EC:
/* B2ED5C 802428EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B2ED60 802428F0 8FB20058 */  lw        $s2, 0x58($sp)
/* B2ED64 802428F4 8FB10054 */  lw        $s1, 0x54($sp)
/* B2ED68 802428F8 8FB00050 */  lw        $s0, 0x50($sp)
/* B2ED6C 802428FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B2ED70 80242900 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B2ED74 80242904 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B2ED78 80242908 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B2ED7C 8024290C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B2ED80 80242910 24020002 */  addiu     $v0, $zero, 2
/* B2ED84 80242914 03E00008 */  jr        $ra
/* B2ED88 80242918 27BD0088 */   addiu    $sp, $sp, 0x88
/* B2ED8C 8024291C 00000000 */  nop       
