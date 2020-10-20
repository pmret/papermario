.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241440_B855C0
/* B855C0 80241440 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B855C4 80241444 AFB10054 */  sw        $s1, 0x54($sp)
/* B855C8 80241448 0080882D */  daddu     $s1, $a0, $zero
/* B855CC 8024144C AFBF005C */  sw        $ra, 0x5c($sp)
/* B855D0 80241450 AFB20058 */  sw        $s2, 0x58($sp)
/* B855D4 80241454 AFB00050 */  sw        $s0, 0x50($sp)
/* B855D8 80241458 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B855DC 8024145C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B855E0 80241460 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B855E4 80241464 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B855E8 80241468 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B855EC 8024146C 8E30000C */  lw        $s0, 0xc($s1)
/* B855F0 80241470 8E050000 */  lw        $a1, ($s0)
/* B855F4 80241474 0C0B1EAF */  jal       get_variable
/* B855F8 80241478 26100004 */   addiu    $s0, $s0, 4
/* B855FC 8024147C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B85600 80241480 0040202D */   daddu    $a0, $v0, $zero
/* B85604 80241484 8E050000 */  lw        $a1, ($s0)
/* B85608 80241488 26100004 */  addiu     $s0, $s0, 4
/* B8560C 8024148C 0220202D */  daddu     $a0, $s1, $zero
/* B85610 80241490 0C0B210B */  jal       get_float_variable
/* B85614 80241494 0040902D */   daddu    $s2, $v0, $zero
/* B85618 80241498 8E050000 */  lw        $a1, ($s0)
/* B8561C 8024149C 26100004 */  addiu     $s0, $s0, 4
/* B85620 802414A0 0220202D */  daddu     $a0, $s1, $zero
/* B85624 802414A4 0C0B210B */  jal       get_float_variable
/* B85628 802414A8 46000706 */   mov.s    $f28, $f0
/* B8562C 802414AC 8E050000 */  lw        $a1, ($s0)
/* B85630 802414B0 26100004 */  addiu     $s0, $s0, 4
/* B85634 802414B4 0220202D */  daddu     $a0, $s1, $zero
/* B85638 802414B8 0C0B210B */  jal       get_float_variable
/* B8563C 802414BC 46000686 */   mov.s    $f26, $f0
/* B85640 802414C0 0220202D */  daddu     $a0, $s1, $zero
/* B85644 802414C4 8E050000 */  lw        $a1, ($s0)
/* B85648 802414C8 0C0B210B */  jal       get_float_variable
/* B8564C 802414CC 46000586 */   mov.s    $f22, $f0
/* B85650 802414D0 0240202D */  daddu     $a0, $s2, $zero
/* B85654 802414D4 0C046B4C */  jal       get_model_from_list_index
/* B85658 802414D8 46000606 */   mov.s    $f24, $f0
/* B8565C 802414DC 0040882D */  daddu     $s1, $v0, $zero
/* B85660 802414E0 96220000 */  lhu       $v0, ($s1)
/* B85664 802414E4 30420400 */  andi      $v0, $v0, 0x400
/* B85668 802414E8 1440001E */  bnez      $v0, .L80241564
/* B8566C 802414EC 26300058 */   addiu    $s0, $s1, 0x58
/* B85670 802414F0 4480A000 */  mtc1      $zero, $f20
/* B85674 802414F4 4406B000 */  mfc1      $a2, $f22
/* B85678 802414F8 4405A000 */  mfc1      $a1, $f20
/* B8567C 802414FC 4407A000 */  mfc1      $a3, $f20
/* B85680 80241500 0C019E40 */  jal       guTranslateF
/* B85684 80241504 0200202D */   daddu    $a0, $s0, $zero
/* B85688 80241508 4405E000 */  mfc1      $a1, $f28
/* B8568C 8024150C 4406D000 */  mfc1      $a2, $f26
/* B85690 80241510 4407C000 */  mfc1      $a3, $f24
/* B85694 80241514 0C0904F4 */  jal       func_802413D0
/* B85698 80241518 27A40010 */   addiu    $a0, $sp, 0x10
/* B8569C 8024151C 27A40010 */  addiu     $a0, $sp, 0x10
/* B856A0 80241520 0200282D */  daddu     $a1, $s0, $zero
/* B856A4 80241524 0C019D80 */  jal       guMtxCatF
/* B856A8 80241528 0200302D */   daddu    $a2, $s0, $zero
/* B856AC 8024152C 27A40010 */  addiu     $a0, $sp, 0x10
/* B856B0 80241530 4600B587 */  neg.s     $f22, $f22
/* B856B4 80241534 4405A000 */  mfc1      $a1, $f20
/* B856B8 80241538 4406B000 */  mfc1      $a2, $f22
/* B856BC 8024153C 0C019E40 */  jal       guTranslateF
/* B856C0 80241540 00A0382D */   daddu    $a3, $a1, $zero
/* B856C4 80241544 27A40010 */  addiu     $a0, $sp, 0x10
/* B856C8 80241548 0200282D */  daddu     $a1, $s0, $zero
/* B856CC 8024154C 0C019D80 */  jal       guMtxCatF
/* B856D0 80241550 00A0302D */   daddu    $a2, $a1, $zero
/* B856D4 80241554 96220000 */  lhu       $v0, ($s1)
/* B856D8 80241558 34421400 */  ori       $v0, $v0, 0x1400
/* B856DC 8024155C 08090577 */  j         .L802415DC
/* B856E0 80241560 A6220000 */   sh       $v0, ($s1)
.L80241564:
/* B856E4 80241564 4480A000 */  mtc1      $zero, $f20
/* B856E8 80241568 4406B000 */  mfc1      $a2, $f22
/* B856EC 8024156C 4405A000 */  mfc1      $a1, $f20
/* B856F0 80241570 4407A000 */  mfc1      $a3, $f20
/* B856F4 80241574 0C019E40 */  jal       guTranslateF
/* B856F8 80241578 27A40010 */   addiu    $a0, $sp, 0x10
/* B856FC 8024157C 27A40010 */  addiu     $a0, $sp, 0x10
/* B85700 80241580 26300058 */  addiu     $s0, $s1, 0x58
/* B85704 80241584 0200282D */  daddu     $a1, $s0, $zero
/* B85708 80241588 0C019D80 */  jal       guMtxCatF
/* B8570C 8024158C 0200302D */   daddu    $a2, $s0, $zero
/* B85710 80241590 4405E000 */  mfc1      $a1, $f28
/* B85714 80241594 4406D000 */  mfc1      $a2, $f26
/* B85718 80241598 4407C000 */  mfc1      $a3, $f24
/* B8571C 8024159C 0C0904F4 */  jal       func_802413D0
/* B85720 802415A0 27A40010 */   addiu    $a0, $sp, 0x10
/* B85724 802415A4 27A40010 */  addiu     $a0, $sp, 0x10
/* B85728 802415A8 0200282D */  daddu     $a1, $s0, $zero
/* B8572C 802415AC 0C019D80 */  jal       guMtxCatF
/* B85730 802415B0 0200302D */   daddu    $a2, $s0, $zero
/* B85734 802415B4 27A40010 */  addiu     $a0, $sp, 0x10
/* B85738 802415B8 4600B587 */  neg.s     $f22, $f22
/* B8573C 802415BC 4405A000 */  mfc1      $a1, $f20
/* B85740 802415C0 4406B000 */  mfc1      $a2, $f22
/* B85744 802415C4 0C019E40 */  jal       guTranslateF
/* B85748 802415C8 00A0382D */   daddu    $a3, $a1, $zero
/* B8574C 802415CC 27A40010 */  addiu     $a0, $sp, 0x10
/* B85750 802415D0 0200282D */  daddu     $a1, $s0, $zero
/* B85754 802415D4 0C019D80 */  jal       guMtxCatF
/* B85758 802415D8 00A0302D */   daddu    $a2, $a1, $zero
.L802415DC:
/* B8575C 802415DC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B85760 802415E0 8FB20058 */  lw        $s2, 0x58($sp)
/* B85764 802415E4 8FB10054 */  lw        $s1, 0x54($sp)
/* B85768 802415E8 8FB00050 */  lw        $s0, 0x50($sp)
/* B8576C 802415EC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B85770 802415F0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B85774 802415F4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B85778 802415F8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B8577C 802415FC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B85780 80241600 24020002 */  addiu     $v0, $zero, 2
/* B85784 80241604 03E00008 */  jr        $ra
/* B85788 80241608 27BD0088 */   addiu    $sp, $sp, 0x88
