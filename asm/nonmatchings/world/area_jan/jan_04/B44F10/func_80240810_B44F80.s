.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240810_B44F80
/* B44F80 80240810 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B44F84 80240814 AFB10054 */  sw        $s1, 0x54($sp)
/* B44F88 80240818 0080882D */  daddu     $s1, $a0, $zero
/* B44F8C 8024081C AFBF005C */  sw        $ra, 0x5c($sp)
/* B44F90 80240820 AFB20058 */  sw        $s2, 0x58($sp)
/* B44F94 80240824 AFB00050 */  sw        $s0, 0x50($sp)
/* B44F98 80240828 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B44F9C 8024082C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B44FA0 80240830 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B44FA4 80240834 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B44FA8 80240838 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B44FAC 8024083C 8E30000C */  lw        $s0, 0xc($s1)
/* B44FB0 80240840 8E050000 */  lw        $a1, ($s0)
/* B44FB4 80240844 0C0B1EAF */  jal       get_variable
/* B44FB8 80240848 26100004 */   addiu    $s0, $s0, 4
/* B44FBC 8024084C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B44FC0 80240850 0040202D */   daddu    $a0, $v0, $zero
/* B44FC4 80240854 8E050000 */  lw        $a1, ($s0)
/* B44FC8 80240858 26100004 */  addiu     $s0, $s0, 4
/* B44FCC 8024085C 0220202D */  daddu     $a0, $s1, $zero
/* B44FD0 80240860 0C0B210B */  jal       get_float_variable
/* B44FD4 80240864 0040902D */   daddu    $s2, $v0, $zero
/* B44FD8 80240868 8E050000 */  lw        $a1, ($s0)
/* B44FDC 8024086C 26100004 */  addiu     $s0, $s0, 4
/* B44FE0 80240870 0220202D */  daddu     $a0, $s1, $zero
/* B44FE4 80240874 0C0B210B */  jal       get_float_variable
/* B44FE8 80240878 46000706 */   mov.s    $f28, $f0
/* B44FEC 8024087C 8E050000 */  lw        $a1, ($s0)
/* B44FF0 80240880 26100004 */  addiu     $s0, $s0, 4
/* B44FF4 80240884 0220202D */  daddu     $a0, $s1, $zero
/* B44FF8 80240888 0C0B210B */  jal       get_float_variable
/* B44FFC 8024088C 46000686 */   mov.s    $f26, $f0
/* B45000 80240890 0220202D */  daddu     $a0, $s1, $zero
/* B45004 80240894 8E050000 */  lw        $a1, ($s0)
/* B45008 80240898 0C0B210B */  jal       get_float_variable
/* B4500C 8024089C 46000586 */   mov.s    $f22, $f0
/* B45010 802408A0 0240202D */  daddu     $a0, $s2, $zero
/* B45014 802408A4 0C046B4C */  jal       get_model_from_list_index
/* B45018 802408A8 46000606 */   mov.s    $f24, $f0
/* B4501C 802408AC 0040882D */  daddu     $s1, $v0, $zero
/* B45020 802408B0 96220000 */  lhu       $v0, ($s1)
/* B45024 802408B4 30420400 */  andi      $v0, $v0, 0x400
/* B45028 802408B8 1440001E */  bnez      $v0, .L80240934
/* B4502C 802408BC 26300058 */   addiu    $s0, $s1, 0x58
/* B45030 802408C0 4480A000 */  mtc1      $zero, $f20
/* B45034 802408C4 4406B000 */  mfc1      $a2, $f22
/* B45038 802408C8 4405A000 */  mfc1      $a1, $f20
/* B4503C 802408CC 4407A000 */  mfc1      $a3, $f20
/* B45040 802408D0 0C019E40 */  jal       guTranslateF
/* B45044 802408D4 0200202D */   daddu    $a0, $s0, $zero
/* B45048 802408D8 4405E000 */  mfc1      $a1, $f28
/* B4504C 802408DC 4406D000 */  mfc1      $a2, $f26
/* B45050 802408E0 4407C000 */  mfc1      $a3, $f24
/* B45054 802408E4 0C0901E8 */  jal       func_802407A0_B44F10
/* B45058 802408E8 27A40010 */   addiu    $a0, $sp, 0x10
/* B4505C 802408EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B45060 802408F0 0200282D */  daddu     $a1, $s0, $zero
/* B45064 802408F4 0C019D80 */  jal       guMtxCatF
/* B45068 802408F8 0200302D */   daddu    $a2, $s0, $zero
/* B4506C 802408FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B45070 80240900 4600B587 */  neg.s     $f22, $f22
/* B45074 80240904 4405A000 */  mfc1      $a1, $f20
/* B45078 80240908 4406B000 */  mfc1      $a2, $f22
/* B4507C 8024090C 0C019E40 */  jal       guTranslateF
/* B45080 80240910 00A0382D */   daddu    $a3, $a1, $zero
/* B45084 80240914 27A40010 */  addiu     $a0, $sp, 0x10
/* B45088 80240918 0200282D */  daddu     $a1, $s0, $zero
/* B4508C 8024091C 0C019D80 */  jal       guMtxCatF
/* B45090 80240920 00A0302D */   daddu    $a2, $a1, $zero
/* B45094 80240924 96220000 */  lhu       $v0, ($s1)
/* B45098 80240928 34421400 */  ori       $v0, $v0, 0x1400
/* B4509C 8024092C 0809026B */  j         .L802409AC
/* B450A0 80240930 A6220000 */   sh       $v0, ($s1)
.L80240934:
/* B450A4 80240934 4480A000 */  mtc1      $zero, $f20
/* B450A8 80240938 4406B000 */  mfc1      $a2, $f22
/* B450AC 8024093C 4405A000 */  mfc1      $a1, $f20
/* B450B0 80240940 4407A000 */  mfc1      $a3, $f20
/* B450B4 80240944 0C019E40 */  jal       guTranslateF
/* B450B8 80240948 27A40010 */   addiu    $a0, $sp, 0x10
/* B450BC 8024094C 27A40010 */  addiu     $a0, $sp, 0x10
/* B450C0 80240950 26300058 */  addiu     $s0, $s1, 0x58
/* B450C4 80240954 0200282D */  daddu     $a1, $s0, $zero
/* B450C8 80240958 0C019D80 */  jal       guMtxCatF
/* B450CC 8024095C 0200302D */   daddu    $a2, $s0, $zero
/* B450D0 80240960 4405E000 */  mfc1      $a1, $f28
/* B450D4 80240964 4406D000 */  mfc1      $a2, $f26
/* B450D8 80240968 4407C000 */  mfc1      $a3, $f24
/* B450DC 8024096C 0C0901E8 */  jal       func_802407A0_B44F10
/* B450E0 80240970 27A40010 */   addiu    $a0, $sp, 0x10
/* B450E4 80240974 27A40010 */  addiu     $a0, $sp, 0x10
/* B450E8 80240978 0200282D */  daddu     $a1, $s0, $zero
/* B450EC 8024097C 0C019D80 */  jal       guMtxCatF
/* B450F0 80240980 0200302D */   daddu    $a2, $s0, $zero
/* B450F4 80240984 27A40010 */  addiu     $a0, $sp, 0x10
/* B450F8 80240988 4600B587 */  neg.s     $f22, $f22
/* B450FC 8024098C 4405A000 */  mfc1      $a1, $f20
/* B45100 80240990 4406B000 */  mfc1      $a2, $f22
/* B45104 80240994 0C019E40 */  jal       guTranslateF
/* B45108 80240998 00A0382D */   daddu    $a3, $a1, $zero
/* B4510C 8024099C 27A40010 */  addiu     $a0, $sp, 0x10
/* B45110 802409A0 0200282D */  daddu     $a1, $s0, $zero
/* B45114 802409A4 0C019D80 */  jal       guMtxCatF
/* B45118 802409A8 00A0302D */   daddu    $a2, $a1, $zero
.L802409AC:
/* B4511C 802409AC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B45120 802409B0 8FB20058 */  lw        $s2, 0x58($sp)
/* B45124 802409B4 8FB10054 */  lw        $s1, 0x54($sp)
/* B45128 802409B8 8FB00050 */  lw        $s0, 0x50($sp)
/* B4512C 802409BC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B45130 802409C0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B45134 802409C4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B45138 802409C8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B4513C 802409CC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B45140 802409D0 24020002 */  addiu     $v0, $zero, 2
/* B45144 802409D4 03E00008 */  jr        $ra
/* B45148 802409D8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B4514C 802409DC 00000000 */  nop       
