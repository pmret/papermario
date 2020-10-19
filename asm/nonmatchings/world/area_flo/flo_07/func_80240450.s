.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240450
/* CAC640 80240450 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CAC644 80240454 AFB10054 */  sw        $s1, 0x54($sp)
/* CAC648 80240458 0080882D */  daddu     $s1, $a0, $zero
/* CAC64C 8024045C AFBF005C */  sw        $ra, 0x5c($sp)
/* CAC650 80240460 AFB20058 */  sw        $s2, 0x58($sp)
/* CAC654 80240464 AFB00050 */  sw        $s0, 0x50($sp)
/* CAC658 80240468 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CAC65C 8024046C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CAC660 80240470 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CAC664 80240474 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CAC668 80240478 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CAC66C 8024047C 8E30000C */  lw        $s0, 0xc($s1)
/* CAC670 80240480 8E050000 */  lw        $a1, ($s0)
/* CAC674 80240484 0C0B1EAF */  jal       get_variable
/* CAC678 80240488 26100004 */   addiu    $s0, $s0, 4
/* CAC67C 8024048C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CAC680 80240490 0040202D */   daddu    $a0, $v0, $zero
/* CAC684 80240494 8E050000 */  lw        $a1, ($s0)
/* CAC688 80240498 26100004 */  addiu     $s0, $s0, 4
/* CAC68C 8024049C 0220202D */  daddu     $a0, $s1, $zero
/* CAC690 802404A0 0C0B210B */  jal       get_float_variable
/* CAC694 802404A4 0040902D */   daddu    $s2, $v0, $zero
/* CAC698 802404A8 8E050000 */  lw        $a1, ($s0)
/* CAC69C 802404AC 26100004 */  addiu     $s0, $s0, 4
/* CAC6A0 802404B0 0220202D */  daddu     $a0, $s1, $zero
/* CAC6A4 802404B4 0C0B210B */  jal       get_float_variable
/* CAC6A8 802404B8 46000706 */   mov.s    $f28, $f0
/* CAC6AC 802404BC 8E050000 */  lw        $a1, ($s0)
/* CAC6B0 802404C0 26100004 */  addiu     $s0, $s0, 4
/* CAC6B4 802404C4 0220202D */  daddu     $a0, $s1, $zero
/* CAC6B8 802404C8 0C0B210B */  jal       get_float_variable
/* CAC6BC 802404CC 46000686 */   mov.s    $f26, $f0
/* CAC6C0 802404D0 0220202D */  daddu     $a0, $s1, $zero
/* CAC6C4 802404D4 8E050000 */  lw        $a1, ($s0)
/* CAC6C8 802404D8 0C0B210B */  jal       get_float_variable
/* CAC6CC 802404DC 46000586 */   mov.s    $f22, $f0
/* CAC6D0 802404E0 0240202D */  daddu     $a0, $s2, $zero
/* CAC6D4 802404E4 0C046B4C */  jal       get_model_from_list_index
/* CAC6D8 802404E8 46000606 */   mov.s    $f24, $f0
/* CAC6DC 802404EC 0040882D */  daddu     $s1, $v0, $zero
/* CAC6E0 802404F0 96220000 */  lhu       $v0, ($s1)
/* CAC6E4 802404F4 30420400 */  andi      $v0, $v0, 0x400
/* CAC6E8 802404F8 1440001E */  bnez      $v0, .L80240574
/* CAC6EC 802404FC 26300058 */   addiu    $s0, $s1, 0x58
/* CAC6F0 80240500 4480A000 */  mtc1      $zero, $f20
/* CAC6F4 80240504 4406B000 */  mfc1      $a2, $f22
/* CAC6F8 80240508 4405A000 */  mfc1      $a1, $f20
/* CAC6FC 8024050C 4407A000 */  mfc1      $a3, $f20
/* CAC700 80240510 0C019E40 */  jal       guTranslateF
/* CAC704 80240514 0200202D */   daddu    $a0, $s0, $zero
/* CAC708 80240518 4405E000 */  mfc1      $a1, $f28
/* CAC70C 8024051C 4406D000 */  mfc1      $a2, $f26
/* CAC710 80240520 4407C000 */  mfc1      $a3, $f24
/* CAC714 80240524 0C0900F8 */  jal       func_802403E0
/* CAC718 80240528 27A40010 */   addiu    $a0, $sp, 0x10
/* CAC71C 8024052C 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC720 80240530 0200282D */  daddu     $a1, $s0, $zero
/* CAC724 80240534 0C019D80 */  jal       guMtxCatF
/* CAC728 80240538 0200302D */   daddu    $a2, $s0, $zero
/* CAC72C 8024053C 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC730 80240540 4600B587 */  neg.s     $f22, $f22
/* CAC734 80240544 4405A000 */  mfc1      $a1, $f20
/* CAC738 80240548 4406B000 */  mfc1      $a2, $f22
/* CAC73C 8024054C 0C019E40 */  jal       guTranslateF
/* CAC740 80240550 00A0382D */   daddu    $a3, $a1, $zero
/* CAC744 80240554 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC748 80240558 0200282D */  daddu     $a1, $s0, $zero
/* CAC74C 8024055C 0C019D80 */  jal       guMtxCatF
/* CAC750 80240560 00A0302D */   daddu    $a2, $a1, $zero
/* CAC754 80240564 96220000 */  lhu       $v0, ($s1)
/* CAC758 80240568 34421400 */  ori       $v0, $v0, 0x1400
/* CAC75C 8024056C 0809017B */  j         .L802405EC
/* CAC760 80240570 A6220000 */   sh       $v0, ($s1)
.L80240574:
/* CAC764 80240574 4480A000 */  mtc1      $zero, $f20
/* CAC768 80240578 4406B000 */  mfc1      $a2, $f22
/* CAC76C 8024057C 4405A000 */  mfc1      $a1, $f20
/* CAC770 80240580 4407A000 */  mfc1      $a3, $f20
/* CAC774 80240584 0C019E40 */  jal       guTranslateF
/* CAC778 80240588 27A40010 */   addiu    $a0, $sp, 0x10
/* CAC77C 8024058C 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC780 80240590 26300058 */  addiu     $s0, $s1, 0x58
/* CAC784 80240594 0200282D */  daddu     $a1, $s0, $zero
/* CAC788 80240598 0C019D80 */  jal       guMtxCatF
/* CAC78C 8024059C 0200302D */   daddu    $a2, $s0, $zero
/* CAC790 802405A0 4405E000 */  mfc1      $a1, $f28
/* CAC794 802405A4 4406D000 */  mfc1      $a2, $f26
/* CAC798 802405A8 4407C000 */  mfc1      $a3, $f24
/* CAC79C 802405AC 0C0900F8 */  jal       func_802403E0
/* CAC7A0 802405B0 27A40010 */   addiu    $a0, $sp, 0x10
/* CAC7A4 802405B4 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC7A8 802405B8 0200282D */  daddu     $a1, $s0, $zero
/* CAC7AC 802405BC 0C019D80 */  jal       guMtxCatF
/* CAC7B0 802405C0 0200302D */   daddu    $a2, $s0, $zero
/* CAC7B4 802405C4 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC7B8 802405C8 4600B587 */  neg.s     $f22, $f22
/* CAC7BC 802405CC 4405A000 */  mfc1      $a1, $f20
/* CAC7C0 802405D0 4406B000 */  mfc1      $a2, $f22
/* CAC7C4 802405D4 0C019E40 */  jal       guTranslateF
/* CAC7C8 802405D8 00A0382D */   daddu    $a3, $a1, $zero
/* CAC7CC 802405DC 27A40010 */  addiu     $a0, $sp, 0x10
/* CAC7D0 802405E0 0200282D */  daddu     $a1, $s0, $zero
/* CAC7D4 802405E4 0C019D80 */  jal       guMtxCatF
/* CAC7D8 802405E8 00A0302D */   daddu    $a2, $a1, $zero
.L802405EC:
/* CAC7DC 802405EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* CAC7E0 802405F0 8FB20058 */  lw        $s2, 0x58($sp)
/* CAC7E4 802405F4 8FB10054 */  lw        $s1, 0x54($sp)
/* CAC7E8 802405F8 8FB00050 */  lw        $s0, 0x50($sp)
/* CAC7EC 802405FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CAC7F0 80240600 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CAC7F4 80240604 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CAC7F8 80240608 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CAC7FC 8024060C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CAC800 80240610 24020002 */  addiu     $v0, $zero, 2
/* CAC804 80240614 03E00008 */  jr        $ra
/* CAC808 80240618 27BD0088 */   addiu    $sp, $sp, 0x88
