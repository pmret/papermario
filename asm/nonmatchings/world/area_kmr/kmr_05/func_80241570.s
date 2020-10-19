.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241570
/* 8CF5E0 80241570 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8CF5E4 80241574 AFB10054 */  sw        $s1, 0x54($sp)
/* 8CF5E8 80241578 0080882D */  daddu     $s1, $a0, $zero
/* 8CF5EC 8024157C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8CF5F0 80241580 AFB20058 */  sw        $s2, 0x58($sp)
/* 8CF5F4 80241584 AFB00050 */  sw        $s0, 0x50($sp)
/* 8CF5F8 80241588 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8CF5FC 8024158C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8CF600 80241590 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8CF604 80241594 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8CF608 80241598 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8CF60C 8024159C 8E30000C */  lw        $s0, 0xc($s1)
/* 8CF610 802415A0 8E050000 */  lw        $a1, ($s0)
/* 8CF614 802415A4 0C0B1EAF */  jal       get_variable
/* 8CF618 802415A8 26100004 */   addiu    $s0, $s0, 4
/* 8CF61C 802415AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8CF620 802415B0 0040202D */   daddu    $a0, $v0, $zero
/* 8CF624 802415B4 8E050000 */  lw        $a1, ($s0)
/* 8CF628 802415B8 26100004 */  addiu     $s0, $s0, 4
/* 8CF62C 802415BC 0220202D */  daddu     $a0, $s1, $zero
/* 8CF630 802415C0 0C0B210B */  jal       get_float_variable
/* 8CF634 802415C4 0040902D */   daddu    $s2, $v0, $zero
/* 8CF638 802415C8 8E050000 */  lw        $a1, ($s0)
/* 8CF63C 802415CC 26100004 */  addiu     $s0, $s0, 4
/* 8CF640 802415D0 0220202D */  daddu     $a0, $s1, $zero
/* 8CF644 802415D4 0C0B210B */  jal       get_float_variable
/* 8CF648 802415D8 46000706 */   mov.s    $f28, $f0
/* 8CF64C 802415DC 8E050000 */  lw        $a1, ($s0)
/* 8CF650 802415E0 26100004 */  addiu     $s0, $s0, 4
/* 8CF654 802415E4 0220202D */  daddu     $a0, $s1, $zero
/* 8CF658 802415E8 0C0B210B */  jal       get_float_variable
/* 8CF65C 802415EC 46000686 */   mov.s    $f26, $f0
/* 8CF660 802415F0 0220202D */  daddu     $a0, $s1, $zero
/* 8CF664 802415F4 8E050000 */  lw        $a1, ($s0)
/* 8CF668 802415F8 0C0B210B */  jal       get_float_variable
/* 8CF66C 802415FC 46000586 */   mov.s    $f22, $f0
/* 8CF670 80241600 0240202D */  daddu     $a0, $s2, $zero
/* 8CF674 80241604 0C046B4C */  jal       get_model_from_list_index
/* 8CF678 80241608 46000606 */   mov.s    $f24, $f0
/* 8CF67C 8024160C 0040882D */  daddu     $s1, $v0, $zero
/* 8CF680 80241610 96220000 */  lhu       $v0, ($s1)
/* 8CF684 80241614 30420400 */  andi      $v0, $v0, 0x400
/* 8CF688 80241618 1440001E */  bnez      $v0, .L80241694
/* 8CF68C 8024161C 26300058 */   addiu    $s0, $s1, 0x58
/* 8CF690 80241620 4480A000 */  mtc1      $zero, $f20
/* 8CF694 80241624 4406B000 */  mfc1      $a2, $f22
/* 8CF698 80241628 4405A000 */  mfc1      $a1, $f20
/* 8CF69C 8024162C 4407A000 */  mfc1      $a3, $f20
/* 8CF6A0 80241630 0C019E40 */  jal       guTranslateF
/* 8CF6A4 80241634 0200202D */   daddu    $a0, $s0, $zero
/* 8CF6A8 80241638 4405E000 */  mfc1      $a1, $f28
/* 8CF6AC 8024163C 4406D000 */  mfc1      $a2, $f26
/* 8CF6B0 80241640 4407C000 */  mfc1      $a3, $f24
/* 8CF6B4 80241644 0C090540 */  jal       func_80241500
/* 8CF6B8 80241648 27A40010 */   addiu    $a0, $sp, 0x10
/* 8CF6BC 8024164C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF6C0 80241650 0200282D */  daddu     $a1, $s0, $zero
/* 8CF6C4 80241654 0C019D80 */  jal       guMtxCatF
/* 8CF6C8 80241658 0200302D */   daddu    $a2, $s0, $zero
/* 8CF6CC 8024165C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF6D0 80241660 4600B587 */  neg.s     $f22, $f22
/* 8CF6D4 80241664 4405A000 */  mfc1      $a1, $f20
/* 8CF6D8 80241668 4406B000 */  mfc1      $a2, $f22
/* 8CF6DC 8024166C 0C019E40 */  jal       guTranslateF
/* 8CF6E0 80241670 00A0382D */   daddu    $a3, $a1, $zero
/* 8CF6E4 80241674 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF6E8 80241678 0200282D */  daddu     $a1, $s0, $zero
/* 8CF6EC 8024167C 0C019D80 */  jal       guMtxCatF
/* 8CF6F0 80241680 00A0302D */   daddu    $a2, $a1, $zero
/* 8CF6F4 80241684 96220000 */  lhu       $v0, ($s1)
/* 8CF6F8 80241688 34421400 */  ori       $v0, $v0, 0x1400
/* 8CF6FC 8024168C 080905C3 */  j         .L8024170C
/* 8CF700 80241690 A6220000 */   sh       $v0, ($s1)
.L80241694:
/* 8CF704 80241694 4480A000 */  mtc1      $zero, $f20
/* 8CF708 80241698 4406B000 */  mfc1      $a2, $f22
/* 8CF70C 8024169C 4405A000 */  mfc1      $a1, $f20
/* 8CF710 802416A0 4407A000 */  mfc1      $a3, $f20
/* 8CF714 802416A4 0C019E40 */  jal       guTranslateF
/* 8CF718 802416A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8CF71C 802416AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF720 802416B0 26300058 */  addiu     $s0, $s1, 0x58
/* 8CF724 802416B4 0200282D */  daddu     $a1, $s0, $zero
/* 8CF728 802416B8 0C019D80 */  jal       guMtxCatF
/* 8CF72C 802416BC 0200302D */   daddu    $a2, $s0, $zero
/* 8CF730 802416C0 4405E000 */  mfc1      $a1, $f28
/* 8CF734 802416C4 4406D000 */  mfc1      $a2, $f26
/* 8CF738 802416C8 4407C000 */  mfc1      $a3, $f24
/* 8CF73C 802416CC 0C090540 */  jal       func_80241500
/* 8CF740 802416D0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8CF744 802416D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF748 802416D8 0200282D */  daddu     $a1, $s0, $zero
/* 8CF74C 802416DC 0C019D80 */  jal       guMtxCatF
/* 8CF750 802416E0 0200302D */   daddu    $a2, $s0, $zero
/* 8CF754 802416E4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF758 802416E8 4600B587 */  neg.s     $f22, $f22
/* 8CF75C 802416EC 4405A000 */  mfc1      $a1, $f20
/* 8CF760 802416F0 4406B000 */  mfc1      $a2, $f22
/* 8CF764 802416F4 0C019E40 */  jal       guTranslateF
/* 8CF768 802416F8 00A0382D */   daddu    $a3, $a1, $zero
/* 8CF76C 802416FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CF770 80241700 0200282D */  daddu     $a1, $s0, $zero
/* 8CF774 80241704 0C019D80 */  jal       guMtxCatF
/* 8CF778 80241708 00A0302D */   daddu    $a2, $a1, $zero
.L8024170C:
/* 8CF77C 8024170C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8CF780 80241710 8FB20058 */  lw        $s2, 0x58($sp)
/* 8CF784 80241714 8FB10054 */  lw        $s1, 0x54($sp)
/* 8CF788 80241718 8FB00050 */  lw        $s0, 0x50($sp)
/* 8CF78C 8024171C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8CF790 80241720 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8CF794 80241724 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8CF798 80241728 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8CF79C 8024172C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8CF7A0 80241730 24020002 */  addiu     $v0, $zero, 2
/* 8CF7A4 80241734 03E00008 */  jr        $ra
/* 8CF7A8 80241738 27BD0088 */   addiu    $sp, $sp, 0x88
