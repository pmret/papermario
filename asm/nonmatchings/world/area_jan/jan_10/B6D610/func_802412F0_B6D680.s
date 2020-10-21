.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412F0_B6D680
/* B6D680 802412F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B6D684 802412F4 AFB10054 */  sw        $s1, 0x54($sp)
/* B6D688 802412F8 0080882D */  daddu     $s1, $a0, $zero
/* B6D68C 802412FC AFBF005C */  sw        $ra, 0x5c($sp)
/* B6D690 80241300 AFB20058 */  sw        $s2, 0x58($sp)
/* B6D694 80241304 AFB00050 */  sw        $s0, 0x50($sp)
/* B6D698 80241308 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B6D69C 8024130C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B6D6A0 80241310 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B6D6A4 80241314 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B6D6A8 80241318 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B6D6AC 8024131C 8E30000C */  lw        $s0, 0xc($s1)
/* B6D6B0 80241320 8E050000 */  lw        $a1, ($s0)
/* B6D6B4 80241324 0C0B1EAF */  jal       get_variable
/* B6D6B8 80241328 26100004 */   addiu    $s0, $s0, 4
/* B6D6BC 8024132C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B6D6C0 80241330 0040202D */   daddu    $a0, $v0, $zero
/* B6D6C4 80241334 8E050000 */  lw        $a1, ($s0)
/* B6D6C8 80241338 26100004 */  addiu     $s0, $s0, 4
/* B6D6CC 8024133C 0220202D */  daddu     $a0, $s1, $zero
/* B6D6D0 80241340 0C0B210B */  jal       get_float_variable
/* B6D6D4 80241344 0040902D */   daddu    $s2, $v0, $zero
/* B6D6D8 80241348 8E050000 */  lw        $a1, ($s0)
/* B6D6DC 8024134C 26100004 */  addiu     $s0, $s0, 4
/* B6D6E0 80241350 0220202D */  daddu     $a0, $s1, $zero
/* B6D6E4 80241354 0C0B210B */  jal       get_float_variable
/* B6D6E8 80241358 46000706 */   mov.s    $f28, $f0
/* B6D6EC 8024135C 8E050000 */  lw        $a1, ($s0)
/* B6D6F0 80241360 26100004 */  addiu     $s0, $s0, 4
/* B6D6F4 80241364 0220202D */  daddu     $a0, $s1, $zero
/* B6D6F8 80241368 0C0B210B */  jal       get_float_variable
/* B6D6FC 8024136C 46000686 */   mov.s    $f26, $f0
/* B6D700 80241370 0220202D */  daddu     $a0, $s1, $zero
/* B6D704 80241374 8E050000 */  lw        $a1, ($s0)
/* B6D708 80241378 0C0B210B */  jal       get_float_variable
/* B6D70C 8024137C 46000586 */   mov.s    $f22, $f0
/* B6D710 80241380 0240202D */  daddu     $a0, $s2, $zero
/* B6D714 80241384 0C046B4C */  jal       get_model_from_list_index
/* B6D718 80241388 46000606 */   mov.s    $f24, $f0
/* B6D71C 8024138C 0040882D */  daddu     $s1, $v0, $zero
/* B6D720 80241390 96220000 */  lhu       $v0, ($s1)
/* B6D724 80241394 30420400 */  andi      $v0, $v0, 0x400
/* B6D728 80241398 1440001E */  bnez      $v0, .L80241414
/* B6D72C 8024139C 26300058 */   addiu    $s0, $s1, 0x58
/* B6D730 802413A0 4480A000 */  mtc1      $zero, $f20
/* B6D734 802413A4 4406B000 */  mfc1      $a2, $f22
/* B6D738 802413A8 4405A000 */  mfc1      $a1, $f20
/* B6D73C 802413AC 4407A000 */  mfc1      $a3, $f20
/* B6D740 802413B0 0C019E40 */  jal       guTranslateF
/* B6D744 802413B4 0200202D */   daddu    $a0, $s0, $zero
/* B6D748 802413B8 4405E000 */  mfc1      $a1, $f28
/* B6D74C 802413BC 4406D000 */  mfc1      $a2, $f26
/* B6D750 802413C0 4407C000 */  mfc1      $a3, $f24
/* B6D754 802413C4 0C0904A0 */  jal       func_80241280_B6D610
/* B6D758 802413C8 27A40010 */   addiu    $a0, $sp, 0x10
/* B6D75C 802413CC 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D760 802413D0 0200282D */  daddu     $a1, $s0, $zero
/* B6D764 802413D4 0C019D80 */  jal       guMtxCatF
/* B6D768 802413D8 0200302D */   daddu    $a2, $s0, $zero
/* B6D76C 802413DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D770 802413E0 4600B587 */  neg.s     $f22, $f22
/* B6D774 802413E4 4405A000 */  mfc1      $a1, $f20
/* B6D778 802413E8 4406B000 */  mfc1      $a2, $f22
/* B6D77C 802413EC 0C019E40 */  jal       guTranslateF
/* B6D780 802413F0 00A0382D */   daddu    $a3, $a1, $zero
/* B6D784 802413F4 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D788 802413F8 0200282D */  daddu     $a1, $s0, $zero
/* B6D78C 802413FC 0C019D80 */  jal       guMtxCatF
/* B6D790 80241400 00A0302D */   daddu    $a2, $a1, $zero
/* B6D794 80241404 96220000 */  lhu       $v0, ($s1)
/* B6D798 80241408 34421400 */  ori       $v0, $v0, 0x1400
/* B6D79C 8024140C 08090523 */  j         .L8024148C
/* B6D7A0 80241410 A6220000 */   sh       $v0, ($s1)
.L80241414:
/* B6D7A4 80241414 4480A000 */  mtc1      $zero, $f20
/* B6D7A8 80241418 4406B000 */  mfc1      $a2, $f22
/* B6D7AC 8024141C 4405A000 */  mfc1      $a1, $f20
/* B6D7B0 80241420 4407A000 */  mfc1      $a3, $f20
/* B6D7B4 80241424 0C019E40 */  jal       guTranslateF
/* B6D7B8 80241428 27A40010 */   addiu    $a0, $sp, 0x10
/* B6D7BC 8024142C 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D7C0 80241430 26300058 */  addiu     $s0, $s1, 0x58
/* B6D7C4 80241434 0200282D */  daddu     $a1, $s0, $zero
/* B6D7C8 80241438 0C019D80 */  jal       guMtxCatF
/* B6D7CC 8024143C 0200302D */   daddu    $a2, $s0, $zero
/* B6D7D0 80241440 4405E000 */  mfc1      $a1, $f28
/* B6D7D4 80241444 4406D000 */  mfc1      $a2, $f26
/* B6D7D8 80241448 4407C000 */  mfc1      $a3, $f24
/* B6D7DC 8024144C 0C0904A0 */  jal       func_80241280_B6D610
/* B6D7E0 80241450 27A40010 */   addiu    $a0, $sp, 0x10
/* B6D7E4 80241454 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D7E8 80241458 0200282D */  daddu     $a1, $s0, $zero
/* B6D7EC 8024145C 0C019D80 */  jal       guMtxCatF
/* B6D7F0 80241460 0200302D */   daddu    $a2, $s0, $zero
/* B6D7F4 80241464 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D7F8 80241468 4600B587 */  neg.s     $f22, $f22
/* B6D7FC 8024146C 4405A000 */  mfc1      $a1, $f20
/* B6D800 80241470 4406B000 */  mfc1      $a2, $f22
/* B6D804 80241474 0C019E40 */  jal       guTranslateF
/* B6D808 80241478 00A0382D */   daddu    $a3, $a1, $zero
/* B6D80C 8024147C 27A40010 */  addiu     $a0, $sp, 0x10
/* B6D810 80241480 0200282D */  daddu     $a1, $s0, $zero
/* B6D814 80241484 0C019D80 */  jal       guMtxCatF
/* B6D818 80241488 00A0302D */   daddu    $a2, $a1, $zero
.L8024148C:
/* B6D81C 8024148C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B6D820 80241490 8FB20058 */  lw        $s2, 0x58($sp)
/* B6D824 80241494 8FB10054 */  lw        $s1, 0x54($sp)
/* B6D828 80241498 8FB00050 */  lw        $s0, 0x50($sp)
/* B6D82C 8024149C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B6D830 802414A0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B6D834 802414A4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B6D838 802414A8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B6D83C 802414AC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B6D840 802414B0 24020002 */  addiu     $v0, $zero, 2
/* B6D844 802414B4 03E00008 */  jr        $ra
/* B6D848 802414B8 27BD0088 */   addiu    $sp, $sp, 0x88
