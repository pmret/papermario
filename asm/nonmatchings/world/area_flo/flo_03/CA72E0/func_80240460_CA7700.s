.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240460_CA7700
/* CA7700 80240460 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CA7704 80240464 AFB10054 */  sw        $s1, 0x54($sp)
/* CA7708 80240468 0080882D */  daddu     $s1, $a0, $zero
/* CA770C 8024046C AFBF005C */  sw        $ra, 0x5c($sp)
/* CA7710 80240470 AFB20058 */  sw        $s2, 0x58($sp)
/* CA7714 80240474 AFB00050 */  sw        $s0, 0x50($sp)
/* CA7718 80240478 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CA771C 8024047C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CA7720 80240480 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CA7724 80240484 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CA7728 80240488 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CA772C 8024048C 8E30000C */  lw        $s0, 0xc($s1)
/* CA7730 80240490 8E050000 */  lw        $a1, ($s0)
/* CA7734 80240494 0C0B1EAF */  jal       get_variable
/* CA7738 80240498 26100004 */   addiu    $s0, $s0, 4
/* CA773C 8024049C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CA7740 802404A0 0040202D */   daddu    $a0, $v0, $zero
/* CA7744 802404A4 8E050000 */  lw        $a1, ($s0)
/* CA7748 802404A8 26100004 */  addiu     $s0, $s0, 4
/* CA774C 802404AC 0220202D */  daddu     $a0, $s1, $zero
/* CA7750 802404B0 0C0B210B */  jal       get_float_variable
/* CA7754 802404B4 0040902D */   daddu    $s2, $v0, $zero
/* CA7758 802404B8 8E050000 */  lw        $a1, ($s0)
/* CA775C 802404BC 26100004 */  addiu     $s0, $s0, 4
/* CA7760 802404C0 0220202D */  daddu     $a0, $s1, $zero
/* CA7764 802404C4 0C0B210B */  jal       get_float_variable
/* CA7768 802404C8 46000706 */   mov.s    $f28, $f0
/* CA776C 802404CC 8E050000 */  lw        $a1, ($s0)
/* CA7770 802404D0 26100004 */  addiu     $s0, $s0, 4
/* CA7774 802404D4 0220202D */  daddu     $a0, $s1, $zero
/* CA7778 802404D8 0C0B210B */  jal       get_float_variable
/* CA777C 802404DC 46000686 */   mov.s    $f26, $f0
/* CA7780 802404E0 0220202D */  daddu     $a0, $s1, $zero
/* CA7784 802404E4 8E050000 */  lw        $a1, ($s0)
/* CA7788 802404E8 0C0B210B */  jal       get_float_variable
/* CA778C 802404EC 46000586 */   mov.s    $f22, $f0
/* CA7790 802404F0 0240202D */  daddu     $a0, $s2, $zero
/* CA7794 802404F4 0C046B4C */  jal       get_model_from_list_index
/* CA7798 802404F8 46000606 */   mov.s    $f24, $f0
/* CA779C 802404FC 0040882D */  daddu     $s1, $v0, $zero
/* CA77A0 80240500 96220000 */  lhu       $v0, ($s1)
/* CA77A4 80240504 30420400 */  andi      $v0, $v0, 0x400
/* CA77A8 80240508 1440001E */  bnez      $v0, .L80240584
/* CA77AC 8024050C 26300058 */   addiu    $s0, $s1, 0x58
/* CA77B0 80240510 4480A000 */  mtc1      $zero, $f20
/* CA77B4 80240514 4406B000 */  mfc1      $a2, $f22
/* CA77B8 80240518 4405A000 */  mfc1      $a1, $f20
/* CA77BC 8024051C 4407A000 */  mfc1      $a3, $f20
/* CA77C0 80240520 0C019E40 */  jal       guTranslateF
/* CA77C4 80240524 0200202D */   daddu    $a0, $s0, $zero
/* CA77C8 80240528 4405E000 */  mfc1      $a1, $f28
/* CA77CC 8024052C 4406D000 */  mfc1      $a2, $f26
/* CA77D0 80240530 4407C000 */  mfc1      $a3, $f24
/* CA77D4 80240534 0C0900FC */  jal       func_802403F0_CA7690
/* CA77D8 80240538 27A40010 */   addiu    $a0, $sp, 0x10
/* CA77DC 8024053C 27A40010 */  addiu     $a0, $sp, 0x10
/* CA77E0 80240540 0200282D */  daddu     $a1, $s0, $zero
/* CA77E4 80240544 0C019D80 */  jal       guMtxCatF
/* CA77E8 80240548 0200302D */   daddu    $a2, $s0, $zero
/* CA77EC 8024054C 27A40010 */  addiu     $a0, $sp, 0x10
/* CA77F0 80240550 4600B587 */  neg.s     $f22, $f22
/* CA77F4 80240554 4405A000 */  mfc1      $a1, $f20
/* CA77F8 80240558 4406B000 */  mfc1      $a2, $f22
/* CA77FC 8024055C 0C019E40 */  jal       guTranslateF
/* CA7800 80240560 00A0382D */   daddu    $a3, $a1, $zero
/* CA7804 80240564 27A40010 */  addiu     $a0, $sp, 0x10
/* CA7808 80240568 0200282D */  daddu     $a1, $s0, $zero
/* CA780C 8024056C 0C019D80 */  jal       guMtxCatF
/* CA7810 80240570 00A0302D */   daddu    $a2, $a1, $zero
/* CA7814 80240574 96220000 */  lhu       $v0, ($s1)
/* CA7818 80240578 34421400 */  ori       $v0, $v0, 0x1400
/* CA781C 8024057C 0809017F */  j         .L802405FC
/* CA7820 80240580 A6220000 */   sh       $v0, ($s1)
.L80240584:
/* CA7824 80240584 4480A000 */  mtc1      $zero, $f20
/* CA7828 80240588 4406B000 */  mfc1      $a2, $f22
/* CA782C 8024058C 4405A000 */  mfc1      $a1, $f20
/* CA7830 80240590 4407A000 */  mfc1      $a3, $f20
/* CA7834 80240594 0C019E40 */  jal       guTranslateF
/* CA7838 80240598 27A40010 */   addiu    $a0, $sp, 0x10
/* CA783C 8024059C 27A40010 */  addiu     $a0, $sp, 0x10
/* CA7840 802405A0 26300058 */  addiu     $s0, $s1, 0x58
/* CA7844 802405A4 0200282D */  daddu     $a1, $s0, $zero
/* CA7848 802405A8 0C019D80 */  jal       guMtxCatF
/* CA784C 802405AC 0200302D */   daddu    $a2, $s0, $zero
/* CA7850 802405B0 4405E000 */  mfc1      $a1, $f28
/* CA7854 802405B4 4406D000 */  mfc1      $a2, $f26
/* CA7858 802405B8 4407C000 */  mfc1      $a3, $f24
/* CA785C 802405BC 0C0900FC */  jal       func_802403F0_CA7690
/* CA7860 802405C0 27A40010 */   addiu    $a0, $sp, 0x10
/* CA7864 802405C4 27A40010 */  addiu     $a0, $sp, 0x10
/* CA7868 802405C8 0200282D */  daddu     $a1, $s0, $zero
/* CA786C 802405CC 0C019D80 */  jal       guMtxCatF
/* CA7870 802405D0 0200302D */   daddu    $a2, $s0, $zero
/* CA7874 802405D4 27A40010 */  addiu     $a0, $sp, 0x10
/* CA7878 802405D8 4600B587 */  neg.s     $f22, $f22
/* CA787C 802405DC 4405A000 */  mfc1      $a1, $f20
/* CA7880 802405E0 4406B000 */  mfc1      $a2, $f22
/* CA7884 802405E4 0C019E40 */  jal       guTranslateF
/* CA7888 802405E8 00A0382D */   daddu    $a3, $a1, $zero
/* CA788C 802405EC 27A40010 */  addiu     $a0, $sp, 0x10
/* CA7890 802405F0 0200282D */  daddu     $a1, $s0, $zero
/* CA7894 802405F4 0C019D80 */  jal       guMtxCatF
/* CA7898 802405F8 00A0302D */   daddu    $a2, $a1, $zero
.L802405FC:
/* CA789C 802405FC 8FBF005C */  lw        $ra, 0x5c($sp)
/* CA78A0 80240600 8FB20058 */  lw        $s2, 0x58($sp)
/* CA78A4 80240604 8FB10054 */  lw        $s1, 0x54($sp)
/* CA78A8 80240608 8FB00050 */  lw        $s0, 0x50($sp)
/* CA78AC 8024060C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CA78B0 80240610 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CA78B4 80240614 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CA78B8 80240618 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CA78BC 8024061C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CA78C0 80240620 24020002 */  addiu     $v0, $zero, 2
/* CA78C4 80240624 03E00008 */  jr        $ra
/* CA78C8 80240628 27BD0088 */   addiu    $sp, $sp, 0x88
/* CA78CC 8024062C 00000000 */  nop       
