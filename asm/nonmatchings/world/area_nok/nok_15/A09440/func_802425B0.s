.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425B0
/* A094B0 802425B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* A094B4 802425B4 AFB10054 */  sw        $s1, 0x54($sp)
/* A094B8 802425B8 0080882D */  daddu     $s1, $a0, $zero
/* A094BC 802425BC AFBF005C */  sw        $ra, 0x5c($sp)
/* A094C0 802425C0 AFB20058 */  sw        $s2, 0x58($sp)
/* A094C4 802425C4 AFB00050 */  sw        $s0, 0x50($sp)
/* A094C8 802425C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* A094CC 802425CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* A094D0 802425D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* A094D4 802425D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* A094D8 802425D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* A094DC 802425DC 8E30000C */  lw        $s0, 0xc($s1)
/* A094E0 802425E0 8E050000 */  lw        $a1, ($s0)
/* A094E4 802425E4 0C0B1EAF */  jal       get_variable
/* A094E8 802425E8 26100004 */   addiu    $s0, $s0, 4
/* A094EC 802425EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A094F0 802425F0 0040202D */   daddu    $a0, $v0, $zero
/* A094F4 802425F4 8E050000 */  lw        $a1, ($s0)
/* A094F8 802425F8 26100004 */  addiu     $s0, $s0, 4
/* A094FC 802425FC 0220202D */  daddu     $a0, $s1, $zero
/* A09500 80242600 0C0B210B */  jal       get_float_variable
/* A09504 80242604 0040902D */   daddu    $s2, $v0, $zero
/* A09508 80242608 8E050000 */  lw        $a1, ($s0)
/* A0950C 8024260C 26100004 */  addiu     $s0, $s0, 4
/* A09510 80242610 0220202D */  daddu     $a0, $s1, $zero
/* A09514 80242614 0C0B210B */  jal       get_float_variable
/* A09518 80242618 46000706 */   mov.s    $f28, $f0
/* A0951C 8024261C 8E050000 */  lw        $a1, ($s0)
/* A09520 80242620 26100004 */  addiu     $s0, $s0, 4
/* A09524 80242624 0220202D */  daddu     $a0, $s1, $zero
/* A09528 80242628 0C0B210B */  jal       get_float_variable
/* A0952C 8024262C 46000686 */   mov.s    $f26, $f0
/* A09530 80242630 0220202D */  daddu     $a0, $s1, $zero
/* A09534 80242634 8E050000 */  lw        $a1, ($s0)
/* A09538 80242638 0C0B210B */  jal       get_float_variable
/* A0953C 8024263C 46000586 */   mov.s    $f22, $f0
/* A09540 80242640 0240202D */  daddu     $a0, $s2, $zero
/* A09544 80242644 0C046B4C */  jal       get_model_from_list_index
/* A09548 80242648 46000606 */   mov.s    $f24, $f0
/* A0954C 8024264C 0040882D */  daddu     $s1, $v0, $zero
/* A09550 80242650 96220000 */  lhu       $v0, ($s1)
/* A09554 80242654 30420400 */  andi      $v0, $v0, 0x400
/* A09558 80242658 1440001E */  bnez      $v0, .L802426D4
/* A0955C 8024265C 26300058 */   addiu    $s0, $s1, 0x58
/* A09560 80242660 4480A000 */  mtc1      $zero, $f20
/* A09564 80242664 4406B000 */  mfc1      $a2, $f22
/* A09568 80242668 4405A000 */  mfc1      $a1, $f20
/* A0956C 8024266C 4407A000 */  mfc1      $a3, $f20
/* A09570 80242670 0C019E40 */  jal       guTranslateF
/* A09574 80242674 0200202D */   daddu    $a0, $s0, $zero
/* A09578 80242678 4405E000 */  mfc1      $a1, $f28
/* A0957C 8024267C 4406D000 */  mfc1      $a2, $f26
/* A09580 80242680 4407C000 */  mfc1      $a3, $f24
/* A09584 80242684 0C090950 */  jal       func_80242540
/* A09588 80242688 27A40010 */   addiu    $a0, $sp, 0x10
/* A0958C 8024268C 27A40010 */  addiu     $a0, $sp, 0x10
/* A09590 80242690 0200282D */  daddu     $a1, $s0, $zero
/* A09594 80242694 0C019D80 */  jal       guMtxCatF
/* A09598 80242698 0200302D */   daddu    $a2, $s0, $zero
/* A0959C 8024269C 27A40010 */  addiu     $a0, $sp, 0x10
/* A095A0 802426A0 4600B587 */  neg.s     $f22, $f22
/* A095A4 802426A4 4405A000 */  mfc1      $a1, $f20
/* A095A8 802426A8 4406B000 */  mfc1      $a2, $f22
/* A095AC 802426AC 0C019E40 */  jal       guTranslateF
/* A095B0 802426B0 00A0382D */   daddu    $a3, $a1, $zero
/* A095B4 802426B4 27A40010 */  addiu     $a0, $sp, 0x10
/* A095B8 802426B8 0200282D */  daddu     $a1, $s0, $zero
/* A095BC 802426BC 0C019D80 */  jal       guMtxCatF
/* A095C0 802426C0 00A0302D */   daddu    $a2, $a1, $zero
/* A095C4 802426C4 96220000 */  lhu       $v0, ($s1)
/* A095C8 802426C8 34421400 */  ori       $v0, $v0, 0x1400
/* A095CC 802426CC 080909D3 */  j         .L8024274C
/* A095D0 802426D0 A6220000 */   sh       $v0, ($s1)
.L802426D4:
/* A095D4 802426D4 4480A000 */  mtc1      $zero, $f20
/* A095D8 802426D8 4406B000 */  mfc1      $a2, $f22
/* A095DC 802426DC 4405A000 */  mfc1      $a1, $f20
/* A095E0 802426E0 4407A000 */  mfc1      $a3, $f20
/* A095E4 802426E4 0C019E40 */  jal       guTranslateF
/* A095E8 802426E8 27A40010 */   addiu    $a0, $sp, 0x10
/* A095EC 802426EC 27A40010 */  addiu     $a0, $sp, 0x10
/* A095F0 802426F0 26300058 */  addiu     $s0, $s1, 0x58
/* A095F4 802426F4 0200282D */  daddu     $a1, $s0, $zero
/* A095F8 802426F8 0C019D80 */  jal       guMtxCatF
/* A095FC 802426FC 0200302D */   daddu    $a2, $s0, $zero
/* A09600 80242700 4405E000 */  mfc1      $a1, $f28
/* A09604 80242704 4406D000 */  mfc1      $a2, $f26
/* A09608 80242708 4407C000 */  mfc1      $a3, $f24
/* A0960C 8024270C 0C090950 */  jal       func_80242540
/* A09610 80242710 27A40010 */   addiu    $a0, $sp, 0x10
/* A09614 80242714 27A40010 */  addiu     $a0, $sp, 0x10
/* A09618 80242718 0200282D */  daddu     $a1, $s0, $zero
/* A0961C 8024271C 0C019D80 */  jal       guMtxCatF
/* A09620 80242720 0200302D */   daddu    $a2, $s0, $zero
/* A09624 80242724 27A40010 */  addiu     $a0, $sp, 0x10
/* A09628 80242728 4600B587 */  neg.s     $f22, $f22
/* A0962C 8024272C 4405A000 */  mfc1      $a1, $f20
/* A09630 80242730 4406B000 */  mfc1      $a2, $f22
/* A09634 80242734 0C019E40 */  jal       guTranslateF
/* A09638 80242738 00A0382D */   daddu    $a3, $a1, $zero
/* A0963C 8024273C 27A40010 */  addiu     $a0, $sp, 0x10
/* A09640 80242740 0200282D */  daddu     $a1, $s0, $zero
/* A09644 80242744 0C019D80 */  jal       guMtxCatF
/* A09648 80242748 00A0302D */   daddu    $a2, $a1, $zero
.L8024274C:
/* A0964C 8024274C 8FBF005C */  lw        $ra, 0x5c($sp)
/* A09650 80242750 8FB20058 */  lw        $s2, 0x58($sp)
/* A09654 80242754 8FB10054 */  lw        $s1, 0x54($sp)
/* A09658 80242758 8FB00050 */  lw        $s0, 0x50($sp)
/* A0965C 8024275C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* A09660 80242760 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* A09664 80242764 D7B80070 */  ldc1      $f24, 0x70($sp)
/* A09668 80242768 D7B60068 */  ldc1      $f22, 0x68($sp)
/* A0966C 8024276C D7B40060 */  ldc1      $f20, 0x60($sp)
/* A09670 80242770 24020002 */  addiu     $v0, $zero, 2
/* A09674 80242774 03E00008 */  jr        $ra
/* A09678 80242778 27BD0088 */   addiu    $sp, $sp, 0x88
/* A0967C 8024277C 00000000 */  nop       
