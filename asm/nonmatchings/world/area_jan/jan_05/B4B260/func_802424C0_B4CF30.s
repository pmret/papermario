.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424C0_B4CF30
/* B4CF30 802424C0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B4CF34 802424C4 AFB10054 */  sw        $s1, 0x54($sp)
/* B4CF38 802424C8 0080882D */  daddu     $s1, $a0, $zero
/* B4CF3C 802424CC AFBF005C */  sw        $ra, 0x5c($sp)
/* B4CF40 802424D0 AFB20058 */  sw        $s2, 0x58($sp)
/* B4CF44 802424D4 AFB00050 */  sw        $s0, 0x50($sp)
/* B4CF48 802424D8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B4CF4C 802424DC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B4CF50 802424E0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B4CF54 802424E4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B4CF58 802424E8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B4CF5C 802424EC 8E30000C */  lw        $s0, 0xc($s1)
/* B4CF60 802424F0 8E050000 */  lw        $a1, ($s0)
/* B4CF64 802424F4 0C0B1EAF */  jal       get_variable
/* B4CF68 802424F8 26100004 */   addiu    $s0, $s0, 4
/* B4CF6C 802424FC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B4CF70 80242500 0040202D */   daddu    $a0, $v0, $zero
/* B4CF74 80242504 8E050000 */  lw        $a1, ($s0)
/* B4CF78 80242508 26100004 */  addiu     $s0, $s0, 4
/* B4CF7C 8024250C 0220202D */  daddu     $a0, $s1, $zero
/* B4CF80 80242510 0C0B210B */  jal       get_float_variable
/* B4CF84 80242514 0040902D */   daddu    $s2, $v0, $zero
/* B4CF88 80242518 8E050000 */  lw        $a1, ($s0)
/* B4CF8C 8024251C 26100004 */  addiu     $s0, $s0, 4
/* B4CF90 80242520 0220202D */  daddu     $a0, $s1, $zero
/* B4CF94 80242524 0C0B210B */  jal       get_float_variable
/* B4CF98 80242528 46000706 */   mov.s    $f28, $f0
/* B4CF9C 8024252C 8E050000 */  lw        $a1, ($s0)
/* B4CFA0 80242530 26100004 */  addiu     $s0, $s0, 4
/* B4CFA4 80242534 0220202D */  daddu     $a0, $s1, $zero
/* B4CFA8 80242538 0C0B210B */  jal       get_float_variable
/* B4CFAC 8024253C 46000686 */   mov.s    $f26, $f0
/* B4CFB0 80242540 0220202D */  daddu     $a0, $s1, $zero
/* B4CFB4 80242544 8E050000 */  lw        $a1, ($s0)
/* B4CFB8 80242548 0C0B210B */  jal       get_float_variable
/* B4CFBC 8024254C 46000586 */   mov.s    $f22, $f0
/* B4CFC0 80242550 0240202D */  daddu     $a0, $s2, $zero
/* B4CFC4 80242554 0C046B4C */  jal       get_model_from_list_index
/* B4CFC8 80242558 46000606 */   mov.s    $f24, $f0
/* B4CFCC 8024255C 0040882D */  daddu     $s1, $v0, $zero
/* B4CFD0 80242560 96220000 */  lhu       $v0, ($s1)
/* B4CFD4 80242564 30420400 */  andi      $v0, $v0, 0x400
/* B4CFD8 80242568 1440001E */  bnez      $v0, .L802425E4
/* B4CFDC 8024256C 26300058 */   addiu    $s0, $s1, 0x58
/* B4CFE0 80242570 4480A000 */  mtc1      $zero, $f20
/* B4CFE4 80242574 4406B000 */  mfc1      $a2, $f22
/* B4CFE8 80242578 4405A000 */  mfc1      $a1, $f20
/* B4CFEC 8024257C 4407A000 */  mfc1      $a3, $f20
/* B4CFF0 80242580 0C019E40 */  jal       guTranslateF
/* B4CFF4 80242584 0200202D */   daddu    $a0, $s0, $zero
/* B4CFF8 80242588 4405E000 */  mfc1      $a1, $f28
/* B4CFFC 8024258C 4406D000 */  mfc1      $a2, $f26
/* B4D000 80242590 4407C000 */  mfc1      $a3, $f24
/* B4D004 80242594 0C090914 */  jal       func_80242450_B4CEC0
/* B4D008 80242598 27A40010 */   addiu    $a0, $sp, 0x10
/* B4D00C 8024259C 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D010 802425A0 0200282D */  daddu     $a1, $s0, $zero
/* B4D014 802425A4 0C019D80 */  jal       guMtxCatF
/* B4D018 802425A8 0200302D */   daddu    $a2, $s0, $zero
/* B4D01C 802425AC 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D020 802425B0 4600B587 */  neg.s     $f22, $f22
/* B4D024 802425B4 4405A000 */  mfc1      $a1, $f20
/* B4D028 802425B8 4406B000 */  mfc1      $a2, $f22
/* B4D02C 802425BC 0C019E40 */  jal       guTranslateF
/* B4D030 802425C0 00A0382D */   daddu    $a3, $a1, $zero
/* B4D034 802425C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D038 802425C8 0200282D */  daddu     $a1, $s0, $zero
/* B4D03C 802425CC 0C019D80 */  jal       guMtxCatF
/* B4D040 802425D0 00A0302D */   daddu    $a2, $a1, $zero
/* B4D044 802425D4 96220000 */  lhu       $v0, ($s1)
/* B4D048 802425D8 34421400 */  ori       $v0, $v0, 0x1400
/* B4D04C 802425DC 08090997 */  j         .L8024265C
/* B4D050 802425E0 A6220000 */   sh       $v0, ($s1)
.L802425E4:
/* B4D054 802425E4 4480A000 */  mtc1      $zero, $f20
/* B4D058 802425E8 4406B000 */  mfc1      $a2, $f22
/* B4D05C 802425EC 4405A000 */  mfc1      $a1, $f20
/* B4D060 802425F0 4407A000 */  mfc1      $a3, $f20
/* B4D064 802425F4 0C019E40 */  jal       guTranslateF
/* B4D068 802425F8 27A40010 */   addiu    $a0, $sp, 0x10
/* B4D06C 802425FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D070 80242600 26300058 */  addiu     $s0, $s1, 0x58
/* B4D074 80242604 0200282D */  daddu     $a1, $s0, $zero
/* B4D078 80242608 0C019D80 */  jal       guMtxCatF
/* B4D07C 8024260C 0200302D */   daddu    $a2, $s0, $zero
/* B4D080 80242610 4405E000 */  mfc1      $a1, $f28
/* B4D084 80242614 4406D000 */  mfc1      $a2, $f26
/* B4D088 80242618 4407C000 */  mfc1      $a3, $f24
/* B4D08C 8024261C 0C090914 */  jal       func_80242450_B4CEC0
/* B4D090 80242620 27A40010 */   addiu    $a0, $sp, 0x10
/* B4D094 80242624 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D098 80242628 0200282D */  daddu     $a1, $s0, $zero
/* B4D09C 8024262C 0C019D80 */  jal       guMtxCatF
/* B4D0A0 80242630 0200302D */   daddu    $a2, $s0, $zero
/* B4D0A4 80242634 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D0A8 80242638 4600B587 */  neg.s     $f22, $f22
/* B4D0AC 8024263C 4405A000 */  mfc1      $a1, $f20
/* B4D0B0 80242640 4406B000 */  mfc1      $a2, $f22
/* B4D0B4 80242644 0C019E40 */  jal       guTranslateF
/* B4D0B8 80242648 00A0382D */   daddu    $a3, $a1, $zero
/* B4D0BC 8024264C 27A40010 */  addiu     $a0, $sp, 0x10
/* B4D0C0 80242650 0200282D */  daddu     $a1, $s0, $zero
/* B4D0C4 80242654 0C019D80 */  jal       guMtxCatF
/* B4D0C8 80242658 00A0302D */   daddu    $a2, $a1, $zero
.L8024265C:
/* B4D0CC 8024265C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B4D0D0 80242660 8FB20058 */  lw        $s2, 0x58($sp)
/* B4D0D4 80242664 8FB10054 */  lw        $s1, 0x54($sp)
/* B4D0D8 80242668 8FB00050 */  lw        $s0, 0x50($sp)
/* B4D0DC 8024266C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B4D0E0 80242670 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B4D0E4 80242674 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B4D0E8 80242678 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B4D0EC 8024267C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B4D0F0 80242680 24020002 */  addiu     $v0, $zero, 2
/* B4D0F4 80242684 03E00008 */  jr        $ra
/* B4D0F8 80242688 27BD0088 */   addiu    $sp, $sp, 0x88
