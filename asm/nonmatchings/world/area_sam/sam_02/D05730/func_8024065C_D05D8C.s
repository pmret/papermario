.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024065C_D05D8C
/* D05D8C 8024065C 27BDFF78 */  addiu     $sp, $sp, -0x88
/* D05D90 80240660 AFB10054 */  sw        $s1, 0x54($sp)
/* D05D94 80240664 0080882D */  daddu     $s1, $a0, $zero
/* D05D98 80240668 AFBF005C */  sw        $ra, 0x5c($sp)
/* D05D9C 8024066C AFB20058 */  sw        $s2, 0x58($sp)
/* D05DA0 80240670 AFB00050 */  sw        $s0, 0x50($sp)
/* D05DA4 80240674 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* D05DA8 80240678 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* D05DAC 8024067C F7B80070 */  sdc1      $f24, 0x70($sp)
/* D05DB0 80240680 F7B60068 */  sdc1      $f22, 0x68($sp)
/* D05DB4 80240684 F7B40060 */  sdc1      $f20, 0x60($sp)
/* D05DB8 80240688 8E30000C */  lw        $s0, 0xc($s1)
/* D05DBC 8024068C 8E050000 */  lw        $a1, ($s0)
/* D05DC0 80240690 0C0B1EAF */  jal       get_variable
/* D05DC4 80240694 26100004 */   addiu    $s0, $s0, 4
/* D05DC8 80240698 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D05DCC 8024069C 0040202D */   daddu    $a0, $v0, $zero
/* D05DD0 802406A0 8E050000 */  lw        $a1, ($s0)
/* D05DD4 802406A4 26100004 */  addiu     $s0, $s0, 4
/* D05DD8 802406A8 0220202D */  daddu     $a0, $s1, $zero
/* D05DDC 802406AC 0C0B210B */  jal       get_float_variable
/* D05DE0 802406B0 0040902D */   daddu    $s2, $v0, $zero
/* D05DE4 802406B4 8E050000 */  lw        $a1, ($s0)
/* D05DE8 802406B8 26100004 */  addiu     $s0, $s0, 4
/* D05DEC 802406BC 0220202D */  daddu     $a0, $s1, $zero
/* D05DF0 802406C0 0C0B210B */  jal       get_float_variable
/* D05DF4 802406C4 46000706 */   mov.s    $f28, $f0
/* D05DF8 802406C8 8E050000 */  lw        $a1, ($s0)
/* D05DFC 802406CC 26100004 */  addiu     $s0, $s0, 4
/* D05E00 802406D0 0220202D */  daddu     $a0, $s1, $zero
/* D05E04 802406D4 0C0B210B */  jal       get_float_variable
/* D05E08 802406D8 46000686 */   mov.s    $f26, $f0
/* D05E0C 802406DC 0220202D */  daddu     $a0, $s1, $zero
/* D05E10 802406E0 8E050000 */  lw        $a1, ($s0)
/* D05E14 802406E4 0C0B210B */  jal       get_float_variable
/* D05E18 802406E8 46000586 */   mov.s    $f22, $f0
/* D05E1C 802406EC 0240202D */  daddu     $a0, $s2, $zero
/* D05E20 802406F0 0C046B4C */  jal       get_model_from_list_index
/* D05E24 802406F4 46000606 */   mov.s    $f24, $f0
/* D05E28 802406F8 0040882D */  daddu     $s1, $v0, $zero
/* D05E2C 802406FC 96220000 */  lhu       $v0, ($s1)
/* D05E30 80240700 30420400 */  andi      $v0, $v0, 0x400
/* D05E34 80240704 1440001E */  bnez      $v0, .L80240780
/* D05E38 80240708 26300058 */   addiu    $s0, $s1, 0x58
/* D05E3C 8024070C 4480A000 */  mtc1      $zero, $f20
/* D05E40 80240710 4406B000 */  mfc1      $a2, $f22
/* D05E44 80240714 4405A000 */  mfc1      $a1, $f20
/* D05E48 80240718 4407A000 */  mfc1      $a3, $f20
/* D05E4C 8024071C 0C019E40 */  jal       guTranslateF
/* D05E50 80240720 0200202D */   daddu    $a0, $s0, $zero
/* D05E54 80240724 4405E000 */  mfc1      $a1, $f28
/* D05E58 80240728 4406D000 */  mfc1      $a2, $f26
/* D05E5C 8024072C 4407C000 */  mfc1      $a3, $f24
/* D05E60 80240730 0C09017B */  jal       func_802405EC_D05D1C
/* D05E64 80240734 27A40010 */   addiu    $a0, $sp, 0x10
/* D05E68 80240738 27A40010 */  addiu     $a0, $sp, 0x10
/* D05E6C 8024073C 0200282D */  daddu     $a1, $s0, $zero
/* D05E70 80240740 0C019D80 */  jal       guMtxCatF
/* D05E74 80240744 0200302D */   daddu    $a2, $s0, $zero
/* D05E78 80240748 27A40010 */  addiu     $a0, $sp, 0x10
/* D05E7C 8024074C 4600B587 */  neg.s     $f22, $f22
/* D05E80 80240750 4405A000 */  mfc1      $a1, $f20
/* D05E84 80240754 4406B000 */  mfc1      $a2, $f22
/* D05E88 80240758 0C019E40 */  jal       guTranslateF
/* D05E8C 8024075C 00A0382D */   daddu    $a3, $a1, $zero
/* D05E90 80240760 27A40010 */  addiu     $a0, $sp, 0x10
/* D05E94 80240764 0200282D */  daddu     $a1, $s0, $zero
/* D05E98 80240768 0C019D80 */  jal       guMtxCatF
/* D05E9C 8024076C 00A0302D */   daddu    $a2, $a1, $zero
/* D05EA0 80240770 96220000 */  lhu       $v0, ($s1)
/* D05EA4 80240774 34421400 */  ori       $v0, $v0, 0x1400
/* D05EA8 80240778 080901FE */  j         .L802407F8
/* D05EAC 8024077C A6220000 */   sh       $v0, ($s1)
.L80240780:
/* D05EB0 80240780 4480A000 */  mtc1      $zero, $f20
/* D05EB4 80240784 4406B000 */  mfc1      $a2, $f22
/* D05EB8 80240788 4405A000 */  mfc1      $a1, $f20
/* D05EBC 8024078C 4407A000 */  mfc1      $a3, $f20
/* D05EC0 80240790 0C019E40 */  jal       guTranslateF
/* D05EC4 80240794 27A40010 */   addiu    $a0, $sp, 0x10
/* D05EC8 80240798 27A40010 */  addiu     $a0, $sp, 0x10
/* D05ECC 8024079C 26300058 */  addiu     $s0, $s1, 0x58
/* D05ED0 802407A0 0200282D */  daddu     $a1, $s0, $zero
/* D05ED4 802407A4 0C019D80 */  jal       guMtxCatF
/* D05ED8 802407A8 0200302D */   daddu    $a2, $s0, $zero
/* D05EDC 802407AC 4405E000 */  mfc1      $a1, $f28
/* D05EE0 802407B0 4406D000 */  mfc1      $a2, $f26
/* D05EE4 802407B4 4407C000 */  mfc1      $a3, $f24
/* D05EE8 802407B8 0C09017B */  jal       func_802405EC_D05D1C
/* D05EEC 802407BC 27A40010 */   addiu    $a0, $sp, 0x10
/* D05EF0 802407C0 27A40010 */  addiu     $a0, $sp, 0x10
/* D05EF4 802407C4 0200282D */  daddu     $a1, $s0, $zero
/* D05EF8 802407C8 0C019D80 */  jal       guMtxCatF
/* D05EFC 802407CC 0200302D */   daddu    $a2, $s0, $zero
/* D05F00 802407D0 27A40010 */  addiu     $a0, $sp, 0x10
/* D05F04 802407D4 4600B587 */  neg.s     $f22, $f22
/* D05F08 802407D8 4405A000 */  mfc1      $a1, $f20
/* D05F0C 802407DC 4406B000 */  mfc1      $a2, $f22
/* D05F10 802407E0 0C019E40 */  jal       guTranslateF
/* D05F14 802407E4 00A0382D */   daddu    $a3, $a1, $zero
/* D05F18 802407E8 27A40010 */  addiu     $a0, $sp, 0x10
/* D05F1C 802407EC 0200282D */  daddu     $a1, $s0, $zero
/* D05F20 802407F0 0C019D80 */  jal       guMtxCatF
/* D05F24 802407F4 00A0302D */   daddu    $a2, $a1, $zero
.L802407F8:
/* D05F28 802407F8 8FBF005C */  lw        $ra, 0x5c($sp)
/* D05F2C 802407FC 8FB20058 */  lw        $s2, 0x58($sp)
/* D05F30 80240800 8FB10054 */  lw        $s1, 0x54($sp)
/* D05F34 80240804 8FB00050 */  lw        $s0, 0x50($sp)
/* D05F38 80240808 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* D05F3C 8024080C D7BA0078 */  ldc1      $f26, 0x78($sp)
/* D05F40 80240810 D7B80070 */  ldc1      $f24, 0x70($sp)
/* D05F44 80240814 D7B60068 */  ldc1      $f22, 0x68($sp)
/* D05F48 80240818 D7B40060 */  ldc1      $f20, 0x60($sp)
/* D05F4C 8024081C 24020002 */  addiu     $v0, $zero, 2
/* D05F50 80240820 03E00008 */  jr        $ra
/* D05F54 80240824 27BD0088 */   addiu    $sp, $sp, 0x88
/* D05F58 80240828 00000000 */  nop       
/* D05F5C 8024082C 00000000 */  nop       
