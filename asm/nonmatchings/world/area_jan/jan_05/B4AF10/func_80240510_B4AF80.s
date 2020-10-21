.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240510_B4AF80
/* B4AF80 80240510 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B4AF84 80240514 AFB10054 */  sw        $s1, 0x54($sp)
/* B4AF88 80240518 0080882D */  daddu     $s1, $a0, $zero
/* B4AF8C 8024051C AFBF005C */  sw        $ra, 0x5c($sp)
/* B4AF90 80240520 AFB20058 */  sw        $s2, 0x58($sp)
/* B4AF94 80240524 AFB00050 */  sw        $s0, 0x50($sp)
/* B4AF98 80240528 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B4AF9C 8024052C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B4AFA0 80240530 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B4AFA4 80240534 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B4AFA8 80240538 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B4AFAC 8024053C 8E30000C */  lw        $s0, 0xc($s1)
/* B4AFB0 80240540 8E050000 */  lw        $a1, ($s0)
/* B4AFB4 80240544 0C0B1EAF */  jal       get_variable
/* B4AFB8 80240548 26100004 */   addiu    $s0, $s0, 4
/* B4AFBC 8024054C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B4AFC0 80240550 0040202D */   daddu    $a0, $v0, $zero
/* B4AFC4 80240554 8E050000 */  lw        $a1, ($s0)
/* B4AFC8 80240558 26100004 */  addiu     $s0, $s0, 4
/* B4AFCC 8024055C 0220202D */  daddu     $a0, $s1, $zero
/* B4AFD0 80240560 0C0B210B */  jal       get_float_variable
/* B4AFD4 80240564 0040902D */   daddu    $s2, $v0, $zero
/* B4AFD8 80240568 8E050000 */  lw        $a1, ($s0)
/* B4AFDC 8024056C 26100004 */  addiu     $s0, $s0, 4
/* B4AFE0 80240570 0220202D */  daddu     $a0, $s1, $zero
/* B4AFE4 80240574 0C0B210B */  jal       get_float_variable
/* B4AFE8 80240578 46000706 */   mov.s    $f28, $f0
/* B4AFEC 8024057C 8E050000 */  lw        $a1, ($s0)
/* B4AFF0 80240580 26100004 */  addiu     $s0, $s0, 4
/* B4AFF4 80240584 0220202D */  daddu     $a0, $s1, $zero
/* B4AFF8 80240588 0C0B210B */  jal       get_float_variable
/* B4AFFC 8024058C 46000686 */   mov.s    $f26, $f0
/* B4B000 80240590 0220202D */  daddu     $a0, $s1, $zero
/* B4B004 80240594 8E050000 */  lw        $a1, ($s0)
/* B4B008 80240598 0C0B210B */  jal       get_float_variable
/* B4B00C 8024059C 46000586 */   mov.s    $f22, $f0
/* B4B010 802405A0 0240202D */  daddu     $a0, $s2, $zero
/* B4B014 802405A4 0C046B4C */  jal       get_model_from_list_index
/* B4B018 802405A8 46000606 */   mov.s    $f24, $f0
/* B4B01C 802405AC 0040882D */  daddu     $s1, $v0, $zero
/* B4B020 802405B0 96220000 */  lhu       $v0, ($s1)
/* B4B024 802405B4 30420400 */  andi      $v0, $v0, 0x400
/* B4B028 802405B8 1440001E */  bnez      $v0, .L80240634
/* B4B02C 802405BC 26300058 */   addiu    $s0, $s1, 0x58
/* B4B030 802405C0 4480A000 */  mtc1      $zero, $f20
/* B4B034 802405C4 4406B000 */  mfc1      $a2, $f22
/* B4B038 802405C8 4405A000 */  mfc1      $a1, $f20
/* B4B03C 802405CC 4407A000 */  mfc1      $a3, $f20
/* B4B040 802405D0 0C019E40 */  jal       guTranslateF
/* B4B044 802405D4 0200202D */   daddu    $a0, $s0, $zero
/* B4B048 802405D8 4405E000 */  mfc1      $a1, $f28
/* B4B04C 802405DC 4406D000 */  mfc1      $a2, $f26
/* B4B050 802405E0 4407C000 */  mfc1      $a3, $f24
/* B4B054 802405E4 0C090128 */  jal       func_802404A0_B4AF10
/* B4B058 802405E8 27A40010 */   addiu    $a0, $sp, 0x10
/* B4B05C 802405EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B060 802405F0 0200282D */  daddu     $a1, $s0, $zero
/* B4B064 802405F4 0C019D80 */  jal       guMtxCatF
/* B4B068 802405F8 0200302D */   daddu    $a2, $s0, $zero
/* B4B06C 802405FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B070 80240600 4600B587 */  neg.s     $f22, $f22
/* B4B074 80240604 4405A000 */  mfc1      $a1, $f20
/* B4B078 80240608 4406B000 */  mfc1      $a2, $f22
/* B4B07C 8024060C 0C019E40 */  jal       guTranslateF
/* B4B080 80240610 00A0382D */   daddu    $a3, $a1, $zero
/* B4B084 80240614 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B088 80240618 0200282D */  daddu     $a1, $s0, $zero
/* B4B08C 8024061C 0C019D80 */  jal       guMtxCatF
/* B4B090 80240620 00A0302D */   daddu    $a2, $a1, $zero
/* B4B094 80240624 96220000 */  lhu       $v0, ($s1)
/* B4B098 80240628 34421400 */  ori       $v0, $v0, 0x1400
/* B4B09C 8024062C 080901AB */  j         .L802406AC
/* B4B0A0 80240630 A6220000 */   sh       $v0, ($s1)
.L80240634:
/* B4B0A4 80240634 4480A000 */  mtc1      $zero, $f20
/* B4B0A8 80240638 4406B000 */  mfc1      $a2, $f22
/* B4B0AC 8024063C 4405A000 */  mfc1      $a1, $f20
/* B4B0B0 80240640 4407A000 */  mfc1      $a3, $f20
/* B4B0B4 80240644 0C019E40 */  jal       guTranslateF
/* B4B0B8 80240648 27A40010 */   addiu    $a0, $sp, 0x10
/* B4B0BC 8024064C 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B0C0 80240650 26300058 */  addiu     $s0, $s1, 0x58
/* B4B0C4 80240654 0200282D */  daddu     $a1, $s0, $zero
/* B4B0C8 80240658 0C019D80 */  jal       guMtxCatF
/* B4B0CC 8024065C 0200302D */   daddu    $a2, $s0, $zero
/* B4B0D0 80240660 4405E000 */  mfc1      $a1, $f28
/* B4B0D4 80240664 4406D000 */  mfc1      $a2, $f26
/* B4B0D8 80240668 4407C000 */  mfc1      $a3, $f24
/* B4B0DC 8024066C 0C090128 */  jal       func_802404A0_B4AF10
/* B4B0E0 80240670 27A40010 */   addiu    $a0, $sp, 0x10
/* B4B0E4 80240674 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B0E8 80240678 0200282D */  daddu     $a1, $s0, $zero
/* B4B0EC 8024067C 0C019D80 */  jal       guMtxCatF
/* B4B0F0 80240680 0200302D */   daddu    $a2, $s0, $zero
/* B4B0F4 80240684 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B0F8 80240688 4600B587 */  neg.s     $f22, $f22
/* B4B0FC 8024068C 4405A000 */  mfc1      $a1, $f20
/* B4B100 80240690 4406B000 */  mfc1      $a2, $f22
/* B4B104 80240694 0C019E40 */  jal       guTranslateF
/* B4B108 80240698 00A0382D */   daddu    $a3, $a1, $zero
/* B4B10C 8024069C 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B110 802406A0 0200282D */  daddu     $a1, $s0, $zero
/* B4B114 802406A4 0C019D80 */  jal       guMtxCatF
/* B4B118 802406A8 00A0302D */   daddu    $a2, $a1, $zero
.L802406AC:
/* B4B11C 802406AC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B4B120 802406B0 8FB20058 */  lw        $s2, 0x58($sp)
/* B4B124 802406B4 8FB10054 */  lw        $s1, 0x54($sp)
/* B4B128 802406B8 8FB00050 */  lw        $s0, 0x50($sp)
/* B4B12C 802406BC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B4B130 802406C0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B4B134 802406C4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B4B138 802406C8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B4B13C 802406CC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B4B140 802406D0 24020002 */  addiu     $v0, $zero, 2
/* B4B144 802406D4 03E00008 */  jr        $ra
/* B4B148 802406D8 27BD0088 */   addiu    $sp, $sp, 0x88
