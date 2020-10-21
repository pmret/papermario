.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240660_B66110
/* B66110 80240660 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B66114 80240664 AFB10054 */  sw        $s1, 0x54($sp)
/* B66118 80240668 0080882D */  daddu     $s1, $a0, $zero
/* B6611C 8024066C AFBF005C */  sw        $ra, 0x5c($sp)
/* B66120 80240670 AFB20058 */  sw        $s2, 0x58($sp)
/* B66124 80240674 AFB00050 */  sw        $s0, 0x50($sp)
/* B66128 80240678 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B6612C 8024067C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B66130 80240680 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B66134 80240684 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B66138 80240688 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B6613C 8024068C 8E30000C */  lw        $s0, 0xc($s1)
/* B66140 80240690 8E050000 */  lw        $a1, ($s0)
/* B66144 80240694 0C0B1EAF */  jal       get_variable
/* B66148 80240698 26100004 */   addiu    $s0, $s0, 4
/* B6614C 8024069C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B66150 802406A0 0040202D */   daddu    $a0, $v0, $zero
/* B66154 802406A4 8E050000 */  lw        $a1, ($s0)
/* B66158 802406A8 26100004 */  addiu     $s0, $s0, 4
/* B6615C 802406AC 0220202D */  daddu     $a0, $s1, $zero
/* B66160 802406B0 0C0B210B */  jal       get_float_variable
/* B66164 802406B4 0040902D */   daddu    $s2, $v0, $zero
/* B66168 802406B8 8E050000 */  lw        $a1, ($s0)
/* B6616C 802406BC 26100004 */  addiu     $s0, $s0, 4
/* B66170 802406C0 0220202D */  daddu     $a0, $s1, $zero
/* B66174 802406C4 0C0B210B */  jal       get_float_variable
/* B66178 802406C8 46000706 */   mov.s    $f28, $f0
/* B6617C 802406CC 8E050000 */  lw        $a1, ($s0)
/* B66180 802406D0 26100004 */  addiu     $s0, $s0, 4
/* B66184 802406D4 0220202D */  daddu     $a0, $s1, $zero
/* B66188 802406D8 0C0B210B */  jal       get_float_variable
/* B6618C 802406DC 46000686 */   mov.s    $f26, $f0
/* B66190 802406E0 0220202D */  daddu     $a0, $s1, $zero
/* B66194 802406E4 8E050000 */  lw        $a1, ($s0)
/* B66198 802406E8 0C0B210B */  jal       get_float_variable
/* B6619C 802406EC 46000586 */   mov.s    $f22, $f0
/* B661A0 802406F0 0240202D */  daddu     $a0, $s2, $zero
/* B661A4 802406F4 0C046B4C */  jal       get_model_from_list_index
/* B661A8 802406F8 46000606 */   mov.s    $f24, $f0
/* B661AC 802406FC 0040882D */  daddu     $s1, $v0, $zero
/* B661B0 80240700 96220000 */  lhu       $v0, ($s1)
/* B661B4 80240704 30420400 */  andi      $v0, $v0, 0x400
/* B661B8 80240708 1440001E */  bnez      $v0, .L80240784
/* B661BC 8024070C 26300058 */   addiu    $s0, $s1, 0x58
/* B661C0 80240710 4480A000 */  mtc1      $zero, $f20
/* B661C4 80240714 4406B000 */  mfc1      $a2, $f22
/* B661C8 80240718 4405A000 */  mfc1      $a1, $f20
/* B661CC 8024071C 4407A000 */  mfc1      $a3, $f20
/* B661D0 80240720 0C019E40 */  jal       guTranslateF
/* B661D4 80240724 0200202D */   daddu    $a0, $s0, $zero
/* B661D8 80240728 4405E000 */  mfc1      $a1, $f28
/* B661DC 8024072C 4406D000 */  mfc1      $a2, $f26
/* B661E0 80240730 4407C000 */  mfc1      $a3, $f24
/* B661E4 80240734 0C09017C */  jal       func_802405F0_B660A0
/* B661E8 80240738 27A40010 */   addiu    $a0, $sp, 0x10
/* B661EC 8024073C 27A40010 */  addiu     $a0, $sp, 0x10
/* B661F0 80240740 0200282D */  daddu     $a1, $s0, $zero
/* B661F4 80240744 0C019D80 */  jal       guMtxCatF
/* B661F8 80240748 0200302D */   daddu    $a2, $s0, $zero
/* B661FC 8024074C 27A40010 */  addiu     $a0, $sp, 0x10
/* B66200 80240750 4600B587 */  neg.s     $f22, $f22
/* B66204 80240754 4405A000 */  mfc1      $a1, $f20
/* B66208 80240758 4406B000 */  mfc1      $a2, $f22
/* B6620C 8024075C 0C019E40 */  jal       guTranslateF
/* B66210 80240760 00A0382D */   daddu    $a3, $a1, $zero
/* B66214 80240764 27A40010 */  addiu     $a0, $sp, 0x10
/* B66218 80240768 0200282D */  daddu     $a1, $s0, $zero
/* B6621C 8024076C 0C019D80 */  jal       guMtxCatF
/* B66220 80240770 00A0302D */   daddu    $a2, $a1, $zero
/* B66224 80240774 96220000 */  lhu       $v0, ($s1)
/* B66228 80240778 34421400 */  ori       $v0, $v0, 0x1400
/* B6622C 8024077C 080901FF */  j         .L802407FC
/* B66230 80240780 A6220000 */   sh       $v0, ($s1)
.L80240784:
/* B66234 80240784 4480A000 */  mtc1      $zero, $f20
/* B66238 80240788 4406B000 */  mfc1      $a2, $f22
/* B6623C 8024078C 4405A000 */  mfc1      $a1, $f20
/* B66240 80240790 4407A000 */  mfc1      $a3, $f20
/* B66244 80240794 0C019E40 */  jal       guTranslateF
/* B66248 80240798 27A40010 */   addiu    $a0, $sp, 0x10
/* B6624C 8024079C 27A40010 */  addiu     $a0, $sp, 0x10
/* B66250 802407A0 26300058 */  addiu     $s0, $s1, 0x58
/* B66254 802407A4 0200282D */  daddu     $a1, $s0, $zero
/* B66258 802407A8 0C019D80 */  jal       guMtxCatF
/* B6625C 802407AC 0200302D */   daddu    $a2, $s0, $zero
/* B66260 802407B0 4405E000 */  mfc1      $a1, $f28
/* B66264 802407B4 4406D000 */  mfc1      $a2, $f26
/* B66268 802407B8 4407C000 */  mfc1      $a3, $f24
/* B6626C 802407BC 0C09017C */  jal       func_802405F0_B660A0
/* B66270 802407C0 27A40010 */   addiu    $a0, $sp, 0x10
/* B66274 802407C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B66278 802407C8 0200282D */  daddu     $a1, $s0, $zero
/* B6627C 802407CC 0C019D80 */  jal       guMtxCatF
/* B66280 802407D0 0200302D */   daddu    $a2, $s0, $zero
/* B66284 802407D4 27A40010 */  addiu     $a0, $sp, 0x10
/* B66288 802407D8 4600B587 */  neg.s     $f22, $f22
/* B6628C 802407DC 4405A000 */  mfc1      $a1, $f20
/* B66290 802407E0 4406B000 */  mfc1      $a2, $f22
/* B66294 802407E4 0C019E40 */  jal       guTranslateF
/* B66298 802407E8 00A0382D */   daddu    $a3, $a1, $zero
/* B6629C 802407EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B662A0 802407F0 0200282D */  daddu     $a1, $s0, $zero
/* B662A4 802407F4 0C019D80 */  jal       guMtxCatF
/* B662A8 802407F8 00A0302D */   daddu    $a2, $a1, $zero
.L802407FC:
/* B662AC 802407FC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B662B0 80240800 8FB20058 */  lw        $s2, 0x58($sp)
/* B662B4 80240804 8FB10054 */  lw        $s1, 0x54($sp)
/* B662B8 80240808 8FB00050 */  lw        $s0, 0x50($sp)
/* B662BC 8024080C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B662C0 80240810 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B662C4 80240814 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B662C8 80240818 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B662CC 8024081C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B662D0 80240820 24020002 */  addiu     $v0, $zero, 2
/* B662D4 80240824 03E00008 */  jr        $ra
/* B662D8 80240828 27BD0088 */   addiu    $sp, $sp, 0x88
