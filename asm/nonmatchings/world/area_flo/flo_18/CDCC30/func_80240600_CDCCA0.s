.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240600_CDCCA0
/* CDCCA0 80240600 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CDCCA4 80240604 AFB10054 */  sw        $s1, 0x54($sp)
/* CDCCA8 80240608 0080882D */  daddu     $s1, $a0, $zero
/* CDCCAC 8024060C AFBF005C */  sw        $ra, 0x5c($sp)
/* CDCCB0 80240610 AFB20058 */  sw        $s2, 0x58($sp)
/* CDCCB4 80240614 AFB00050 */  sw        $s0, 0x50($sp)
/* CDCCB8 80240618 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CDCCBC 8024061C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CDCCC0 80240620 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CDCCC4 80240624 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CDCCC8 80240628 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CDCCCC 8024062C 8E30000C */  lw        $s0, 0xc($s1)
/* CDCCD0 80240630 8E050000 */  lw        $a1, ($s0)
/* CDCCD4 80240634 0C0B1EAF */  jal       get_variable
/* CDCCD8 80240638 26100004 */   addiu    $s0, $s0, 4
/* CDCCDC 8024063C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CDCCE0 80240640 0040202D */   daddu    $a0, $v0, $zero
/* CDCCE4 80240644 8E050000 */  lw        $a1, ($s0)
/* CDCCE8 80240648 26100004 */  addiu     $s0, $s0, 4
/* CDCCEC 8024064C 0220202D */  daddu     $a0, $s1, $zero
/* CDCCF0 80240650 0C0B210B */  jal       get_float_variable
/* CDCCF4 80240654 0040902D */   daddu    $s2, $v0, $zero
/* CDCCF8 80240658 8E050000 */  lw        $a1, ($s0)
/* CDCCFC 8024065C 26100004 */  addiu     $s0, $s0, 4
/* CDCD00 80240660 0220202D */  daddu     $a0, $s1, $zero
/* CDCD04 80240664 0C0B210B */  jal       get_float_variable
/* CDCD08 80240668 46000706 */   mov.s    $f28, $f0
/* CDCD0C 8024066C 8E050000 */  lw        $a1, ($s0)
/* CDCD10 80240670 26100004 */  addiu     $s0, $s0, 4
/* CDCD14 80240674 0220202D */  daddu     $a0, $s1, $zero
/* CDCD18 80240678 0C0B210B */  jal       get_float_variable
/* CDCD1C 8024067C 46000686 */   mov.s    $f26, $f0
/* CDCD20 80240680 0220202D */  daddu     $a0, $s1, $zero
/* CDCD24 80240684 8E050000 */  lw        $a1, ($s0)
/* CDCD28 80240688 0C0B210B */  jal       get_float_variable
/* CDCD2C 8024068C 46000586 */   mov.s    $f22, $f0
/* CDCD30 80240690 0240202D */  daddu     $a0, $s2, $zero
/* CDCD34 80240694 0C046B4C */  jal       get_model_from_list_index
/* CDCD38 80240698 46000606 */   mov.s    $f24, $f0
/* CDCD3C 8024069C 0040882D */  daddu     $s1, $v0, $zero
/* CDCD40 802406A0 96220000 */  lhu       $v0, ($s1)
/* CDCD44 802406A4 30420400 */  andi      $v0, $v0, 0x400
/* CDCD48 802406A8 1440001E */  bnez      $v0, .L80240724
/* CDCD4C 802406AC 26300058 */   addiu    $s0, $s1, 0x58
/* CDCD50 802406B0 4480A000 */  mtc1      $zero, $f20
/* CDCD54 802406B4 4406B000 */  mfc1      $a2, $f22
/* CDCD58 802406B8 4405A000 */  mfc1      $a1, $f20
/* CDCD5C 802406BC 4407A000 */  mfc1      $a3, $f20
/* CDCD60 802406C0 0C019E40 */  jal       guTranslateF
/* CDCD64 802406C4 0200202D */   daddu    $a0, $s0, $zero
/* CDCD68 802406C8 4405E000 */  mfc1      $a1, $f28
/* CDCD6C 802406CC 4406D000 */  mfc1      $a2, $f26
/* CDCD70 802406D0 4407C000 */  mfc1      $a3, $f24
/* CDCD74 802406D4 0C090164 */  jal       func_80240590
/* CDCD78 802406D8 27A40010 */   addiu    $a0, $sp, 0x10
/* CDCD7C 802406DC 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCD80 802406E0 0200282D */  daddu     $a1, $s0, $zero
/* CDCD84 802406E4 0C019D80 */  jal       guMtxCatF
/* CDCD88 802406E8 0200302D */   daddu    $a2, $s0, $zero
/* CDCD8C 802406EC 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCD90 802406F0 4600B587 */  neg.s     $f22, $f22
/* CDCD94 802406F4 4405A000 */  mfc1      $a1, $f20
/* CDCD98 802406F8 4406B000 */  mfc1      $a2, $f22
/* CDCD9C 802406FC 0C019E40 */  jal       guTranslateF
/* CDCDA0 80240700 00A0382D */   daddu    $a3, $a1, $zero
/* CDCDA4 80240704 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCDA8 80240708 0200282D */  daddu     $a1, $s0, $zero
/* CDCDAC 8024070C 0C019D80 */  jal       guMtxCatF
/* CDCDB0 80240710 00A0302D */   daddu    $a2, $a1, $zero
/* CDCDB4 80240714 96220000 */  lhu       $v0, ($s1)
/* CDCDB8 80240718 34421400 */  ori       $v0, $v0, 0x1400
/* CDCDBC 8024071C 080901E7 */  j         .L8024079C
/* CDCDC0 80240720 A6220000 */   sh       $v0, ($s1)
.L80240724:
/* CDCDC4 80240724 4480A000 */  mtc1      $zero, $f20
/* CDCDC8 80240728 4406B000 */  mfc1      $a2, $f22
/* CDCDCC 8024072C 4405A000 */  mfc1      $a1, $f20
/* CDCDD0 80240730 4407A000 */  mfc1      $a3, $f20
/* CDCDD4 80240734 0C019E40 */  jal       guTranslateF
/* CDCDD8 80240738 27A40010 */   addiu    $a0, $sp, 0x10
/* CDCDDC 8024073C 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCDE0 80240740 26300058 */  addiu     $s0, $s1, 0x58
/* CDCDE4 80240744 0200282D */  daddu     $a1, $s0, $zero
/* CDCDE8 80240748 0C019D80 */  jal       guMtxCatF
/* CDCDEC 8024074C 0200302D */   daddu    $a2, $s0, $zero
/* CDCDF0 80240750 4405E000 */  mfc1      $a1, $f28
/* CDCDF4 80240754 4406D000 */  mfc1      $a2, $f26
/* CDCDF8 80240758 4407C000 */  mfc1      $a3, $f24
/* CDCDFC 8024075C 0C090164 */  jal       func_80240590
/* CDCE00 80240760 27A40010 */   addiu    $a0, $sp, 0x10
/* CDCE04 80240764 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCE08 80240768 0200282D */  daddu     $a1, $s0, $zero
/* CDCE0C 8024076C 0C019D80 */  jal       guMtxCatF
/* CDCE10 80240770 0200302D */   daddu    $a2, $s0, $zero
/* CDCE14 80240774 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCE18 80240778 4600B587 */  neg.s     $f22, $f22
/* CDCE1C 8024077C 4405A000 */  mfc1      $a1, $f20
/* CDCE20 80240780 4406B000 */  mfc1      $a2, $f22
/* CDCE24 80240784 0C019E40 */  jal       guTranslateF
/* CDCE28 80240788 00A0382D */   daddu    $a3, $a1, $zero
/* CDCE2C 8024078C 27A40010 */  addiu     $a0, $sp, 0x10
/* CDCE30 80240790 0200282D */  daddu     $a1, $s0, $zero
/* CDCE34 80240794 0C019D80 */  jal       guMtxCatF
/* CDCE38 80240798 00A0302D */   daddu    $a2, $a1, $zero
.L8024079C:
/* CDCE3C 8024079C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CDCE40 802407A0 8FB20058 */  lw        $s2, 0x58($sp)
/* CDCE44 802407A4 8FB10054 */  lw        $s1, 0x54($sp)
/* CDCE48 802407A8 8FB00050 */  lw        $s0, 0x50($sp)
/* CDCE4C 802407AC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CDCE50 802407B0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CDCE54 802407B4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CDCE58 802407B8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CDCE5C 802407BC D7B40060 */  ldc1      $f20, 0x60($sp)
/* CDCE60 802407C0 24020002 */  addiu     $v0, $zero, 2
/* CDCE64 802407C4 03E00008 */  jr        $ra
/* CDCE68 802407C8 27BD0088 */   addiu    $sp, $sp, 0x88
/* CDCE6C 802407CC 00000000 */  nop       
