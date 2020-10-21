.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241620_91FB90
/* 91FB90 80241620 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 91FB94 80241624 AFB10054 */  sw        $s1, 0x54($sp)
/* 91FB98 80241628 0080882D */  daddu     $s1, $a0, $zero
/* 91FB9C 8024162C AFBF005C */  sw        $ra, 0x5c($sp)
/* 91FBA0 80241630 AFB20058 */  sw        $s2, 0x58($sp)
/* 91FBA4 80241634 AFB00050 */  sw        $s0, 0x50($sp)
/* 91FBA8 80241638 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 91FBAC 8024163C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 91FBB0 80241640 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 91FBB4 80241644 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 91FBB8 80241648 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 91FBBC 8024164C 8E30000C */  lw        $s0, 0xc($s1)
/* 91FBC0 80241650 8E050000 */  lw        $a1, ($s0)
/* 91FBC4 80241654 0C0B1EAF */  jal       get_variable
/* 91FBC8 80241658 26100004 */   addiu    $s0, $s0, 4
/* 91FBCC 8024165C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 91FBD0 80241660 0040202D */   daddu    $a0, $v0, $zero
/* 91FBD4 80241664 8E050000 */  lw        $a1, ($s0)
/* 91FBD8 80241668 26100004 */  addiu     $s0, $s0, 4
/* 91FBDC 8024166C 0220202D */  daddu     $a0, $s1, $zero
/* 91FBE0 80241670 0C0B210B */  jal       get_float_variable
/* 91FBE4 80241674 0040902D */   daddu    $s2, $v0, $zero
/* 91FBE8 80241678 8E050000 */  lw        $a1, ($s0)
/* 91FBEC 8024167C 26100004 */  addiu     $s0, $s0, 4
/* 91FBF0 80241680 0220202D */  daddu     $a0, $s1, $zero
/* 91FBF4 80241684 0C0B210B */  jal       get_float_variable
/* 91FBF8 80241688 46000706 */   mov.s    $f28, $f0
/* 91FBFC 8024168C 8E050000 */  lw        $a1, ($s0)
/* 91FC00 80241690 26100004 */  addiu     $s0, $s0, 4
/* 91FC04 80241694 0220202D */  daddu     $a0, $s1, $zero
/* 91FC08 80241698 0C0B210B */  jal       get_float_variable
/* 91FC0C 8024169C 46000686 */   mov.s    $f26, $f0
/* 91FC10 802416A0 0220202D */  daddu     $a0, $s1, $zero
/* 91FC14 802416A4 8E050000 */  lw        $a1, ($s0)
/* 91FC18 802416A8 0C0B210B */  jal       get_float_variable
/* 91FC1C 802416AC 46000586 */   mov.s    $f22, $f0
/* 91FC20 802416B0 0240202D */  daddu     $a0, $s2, $zero
/* 91FC24 802416B4 0C046B4C */  jal       get_model_from_list_index
/* 91FC28 802416B8 46000606 */   mov.s    $f24, $f0
/* 91FC2C 802416BC 0040882D */  daddu     $s1, $v0, $zero
/* 91FC30 802416C0 96220000 */  lhu       $v0, ($s1)
/* 91FC34 802416C4 30420400 */  andi      $v0, $v0, 0x400
/* 91FC38 802416C8 1440001E */  bnez      $v0, .L80241744
/* 91FC3C 802416CC 26300058 */   addiu    $s0, $s1, 0x58
/* 91FC40 802416D0 4480A000 */  mtc1      $zero, $f20
/* 91FC44 802416D4 4406B000 */  mfc1      $a2, $f22
/* 91FC48 802416D8 4405A000 */  mfc1      $a1, $f20
/* 91FC4C 802416DC 4407A000 */  mfc1      $a3, $f20
/* 91FC50 802416E0 0C019E40 */  jal       guTranslateF
/* 91FC54 802416E4 0200202D */   daddu    $a0, $s0, $zero
/* 91FC58 802416E8 4405E000 */  mfc1      $a1, $f28
/* 91FC5C 802416EC 4406D000 */  mfc1      $a2, $f26
/* 91FC60 802416F0 4407C000 */  mfc1      $a3, $f24
/* 91FC64 802416F4 0C09056C */  jal       func_802415B0_91FB20
/* 91FC68 802416F8 27A40010 */   addiu    $a0, $sp, 0x10
/* 91FC6C 802416FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FC70 80241700 0200282D */  daddu     $a1, $s0, $zero
/* 91FC74 80241704 0C019D80 */  jal       guMtxCatF
/* 91FC78 80241708 0200302D */   daddu    $a2, $s0, $zero
/* 91FC7C 8024170C 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FC80 80241710 4600B587 */  neg.s     $f22, $f22
/* 91FC84 80241714 4405A000 */  mfc1      $a1, $f20
/* 91FC88 80241718 4406B000 */  mfc1      $a2, $f22
/* 91FC8C 8024171C 0C019E40 */  jal       guTranslateF
/* 91FC90 80241720 00A0382D */   daddu    $a3, $a1, $zero
/* 91FC94 80241724 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FC98 80241728 0200282D */  daddu     $a1, $s0, $zero
/* 91FC9C 8024172C 0C019D80 */  jal       guMtxCatF
/* 91FCA0 80241730 00A0302D */   daddu    $a2, $a1, $zero
/* 91FCA4 80241734 96220000 */  lhu       $v0, ($s1)
/* 91FCA8 80241738 34421400 */  ori       $v0, $v0, 0x1400
/* 91FCAC 8024173C 080905EF */  j         .L802417BC
/* 91FCB0 80241740 A6220000 */   sh       $v0, ($s1)
.L80241744:
/* 91FCB4 80241744 4480A000 */  mtc1      $zero, $f20
/* 91FCB8 80241748 4406B000 */  mfc1      $a2, $f22
/* 91FCBC 8024174C 4405A000 */  mfc1      $a1, $f20
/* 91FCC0 80241750 4407A000 */  mfc1      $a3, $f20
/* 91FCC4 80241754 0C019E40 */  jal       guTranslateF
/* 91FCC8 80241758 27A40010 */   addiu    $a0, $sp, 0x10
/* 91FCCC 8024175C 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FCD0 80241760 26300058 */  addiu     $s0, $s1, 0x58
/* 91FCD4 80241764 0200282D */  daddu     $a1, $s0, $zero
/* 91FCD8 80241768 0C019D80 */  jal       guMtxCatF
/* 91FCDC 8024176C 0200302D */   daddu    $a2, $s0, $zero
/* 91FCE0 80241770 4405E000 */  mfc1      $a1, $f28
/* 91FCE4 80241774 4406D000 */  mfc1      $a2, $f26
/* 91FCE8 80241778 4407C000 */  mfc1      $a3, $f24
/* 91FCEC 8024177C 0C09056C */  jal       func_802415B0_91FB20
/* 91FCF0 80241780 27A40010 */   addiu    $a0, $sp, 0x10
/* 91FCF4 80241784 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FCF8 80241788 0200282D */  daddu     $a1, $s0, $zero
/* 91FCFC 8024178C 0C019D80 */  jal       guMtxCatF
/* 91FD00 80241790 0200302D */   daddu    $a2, $s0, $zero
/* 91FD04 80241794 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FD08 80241798 4600B587 */  neg.s     $f22, $f22
/* 91FD0C 8024179C 4405A000 */  mfc1      $a1, $f20
/* 91FD10 802417A0 4406B000 */  mfc1      $a2, $f22
/* 91FD14 802417A4 0C019E40 */  jal       guTranslateF
/* 91FD18 802417A8 00A0382D */   daddu    $a3, $a1, $zero
/* 91FD1C 802417AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 91FD20 802417B0 0200282D */  daddu     $a1, $s0, $zero
/* 91FD24 802417B4 0C019D80 */  jal       guMtxCatF
/* 91FD28 802417B8 00A0302D */   daddu    $a2, $a1, $zero
.L802417BC:
/* 91FD2C 802417BC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 91FD30 802417C0 8FB20058 */  lw        $s2, 0x58($sp)
/* 91FD34 802417C4 8FB10054 */  lw        $s1, 0x54($sp)
/* 91FD38 802417C8 8FB00050 */  lw        $s0, 0x50($sp)
/* 91FD3C 802417CC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 91FD40 802417D0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 91FD44 802417D4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 91FD48 802417D8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 91FD4C 802417DC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 91FD50 802417E0 24020002 */  addiu     $v0, $zero, 2
/* 91FD54 802417E4 03E00008 */  jr        $ra
/* 91FD58 802417E8 27BD0088 */   addiu    $sp, $sp, 0x88
/* 91FD5C 802417EC 00000000 */  nop       
