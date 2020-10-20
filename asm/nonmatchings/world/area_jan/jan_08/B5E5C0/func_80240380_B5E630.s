.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240380_B5E630
/* B5E630 80240380 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B5E634 80240384 AFB10054 */  sw        $s1, 0x54($sp)
/* B5E638 80240388 0080882D */  daddu     $s1, $a0, $zero
/* B5E63C 8024038C AFBF005C */  sw        $ra, 0x5c($sp)
/* B5E640 80240390 AFB20058 */  sw        $s2, 0x58($sp)
/* B5E644 80240394 AFB00050 */  sw        $s0, 0x50($sp)
/* B5E648 80240398 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B5E64C 8024039C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B5E650 802403A0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B5E654 802403A4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B5E658 802403A8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B5E65C 802403AC 8E30000C */  lw        $s0, 0xc($s1)
/* B5E660 802403B0 8E050000 */  lw        $a1, ($s0)
/* B5E664 802403B4 0C0B1EAF */  jal       get_variable
/* B5E668 802403B8 26100004 */   addiu    $s0, $s0, 4
/* B5E66C 802403BC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B5E670 802403C0 0040202D */   daddu    $a0, $v0, $zero
/* B5E674 802403C4 8E050000 */  lw        $a1, ($s0)
/* B5E678 802403C8 26100004 */  addiu     $s0, $s0, 4
/* B5E67C 802403CC 0220202D */  daddu     $a0, $s1, $zero
/* B5E680 802403D0 0C0B210B */  jal       get_float_variable
/* B5E684 802403D4 0040902D */   daddu    $s2, $v0, $zero
/* B5E688 802403D8 8E050000 */  lw        $a1, ($s0)
/* B5E68C 802403DC 26100004 */  addiu     $s0, $s0, 4
/* B5E690 802403E0 0220202D */  daddu     $a0, $s1, $zero
/* B5E694 802403E4 0C0B210B */  jal       get_float_variable
/* B5E698 802403E8 46000706 */   mov.s    $f28, $f0
/* B5E69C 802403EC 8E050000 */  lw        $a1, ($s0)
/* B5E6A0 802403F0 26100004 */  addiu     $s0, $s0, 4
/* B5E6A4 802403F4 0220202D */  daddu     $a0, $s1, $zero
/* B5E6A8 802403F8 0C0B210B */  jal       get_float_variable
/* B5E6AC 802403FC 46000686 */   mov.s    $f26, $f0
/* B5E6B0 80240400 0220202D */  daddu     $a0, $s1, $zero
/* B5E6B4 80240404 8E050000 */  lw        $a1, ($s0)
/* B5E6B8 80240408 0C0B210B */  jal       get_float_variable
/* B5E6BC 8024040C 46000586 */   mov.s    $f22, $f0
/* B5E6C0 80240410 0240202D */  daddu     $a0, $s2, $zero
/* B5E6C4 80240414 0C046B4C */  jal       get_model_from_list_index
/* B5E6C8 80240418 46000606 */   mov.s    $f24, $f0
/* B5E6CC 8024041C 0040882D */  daddu     $s1, $v0, $zero
/* B5E6D0 80240420 96220000 */  lhu       $v0, ($s1)
/* B5E6D4 80240424 30420400 */  andi      $v0, $v0, 0x400
/* B5E6D8 80240428 1440001E */  bnez      $v0, .L802404A4
/* B5E6DC 8024042C 26300058 */   addiu    $s0, $s1, 0x58
/* B5E6E0 80240430 4480A000 */  mtc1      $zero, $f20
/* B5E6E4 80240434 4406B000 */  mfc1      $a2, $f22
/* B5E6E8 80240438 4405A000 */  mfc1      $a1, $f20
/* B5E6EC 8024043C 4407A000 */  mfc1      $a3, $f20
/* B5E6F0 80240440 0C019E40 */  jal       guTranslateF
/* B5E6F4 80240444 0200202D */   daddu    $a0, $s0, $zero
/* B5E6F8 80240448 4405E000 */  mfc1      $a1, $f28
/* B5E6FC 8024044C 4406D000 */  mfc1      $a2, $f26
/* B5E700 80240450 4407C000 */  mfc1      $a3, $f24
/* B5E704 80240454 0C0900C4 */  jal       func_80240310
/* B5E708 80240458 27A40010 */   addiu    $a0, $sp, 0x10
/* B5E70C 8024045C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E710 80240460 0200282D */  daddu     $a1, $s0, $zero
/* B5E714 80240464 0C019D80 */  jal       guMtxCatF
/* B5E718 80240468 0200302D */   daddu    $a2, $s0, $zero
/* B5E71C 8024046C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E720 80240470 4600B587 */  neg.s     $f22, $f22
/* B5E724 80240474 4405A000 */  mfc1      $a1, $f20
/* B5E728 80240478 4406B000 */  mfc1      $a2, $f22
/* B5E72C 8024047C 0C019E40 */  jal       guTranslateF
/* B5E730 80240480 00A0382D */   daddu    $a3, $a1, $zero
/* B5E734 80240484 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E738 80240488 0200282D */  daddu     $a1, $s0, $zero
/* B5E73C 8024048C 0C019D80 */  jal       guMtxCatF
/* B5E740 80240490 00A0302D */   daddu    $a2, $a1, $zero
/* B5E744 80240494 96220000 */  lhu       $v0, ($s1)
/* B5E748 80240498 34421400 */  ori       $v0, $v0, 0x1400
/* B5E74C 8024049C 08090147 */  j         .L8024051C
/* B5E750 802404A0 A6220000 */   sh       $v0, ($s1)
.L802404A4:
/* B5E754 802404A4 4480A000 */  mtc1      $zero, $f20
/* B5E758 802404A8 4406B000 */  mfc1      $a2, $f22
/* B5E75C 802404AC 4405A000 */  mfc1      $a1, $f20
/* B5E760 802404B0 4407A000 */  mfc1      $a3, $f20
/* B5E764 802404B4 0C019E40 */  jal       guTranslateF
/* B5E768 802404B8 27A40010 */   addiu    $a0, $sp, 0x10
/* B5E76C 802404BC 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E770 802404C0 26300058 */  addiu     $s0, $s1, 0x58
/* B5E774 802404C4 0200282D */  daddu     $a1, $s0, $zero
/* B5E778 802404C8 0C019D80 */  jal       guMtxCatF
/* B5E77C 802404CC 0200302D */   daddu    $a2, $s0, $zero
/* B5E780 802404D0 4405E000 */  mfc1      $a1, $f28
/* B5E784 802404D4 4406D000 */  mfc1      $a2, $f26
/* B5E788 802404D8 4407C000 */  mfc1      $a3, $f24
/* B5E78C 802404DC 0C0900C4 */  jal       func_80240310
/* B5E790 802404E0 27A40010 */   addiu    $a0, $sp, 0x10
/* B5E794 802404E4 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E798 802404E8 0200282D */  daddu     $a1, $s0, $zero
/* B5E79C 802404EC 0C019D80 */  jal       guMtxCatF
/* B5E7A0 802404F0 0200302D */   daddu    $a2, $s0, $zero
/* B5E7A4 802404F4 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E7A8 802404F8 4600B587 */  neg.s     $f22, $f22
/* B5E7AC 802404FC 4405A000 */  mfc1      $a1, $f20
/* B5E7B0 80240500 4406B000 */  mfc1      $a2, $f22
/* B5E7B4 80240504 0C019E40 */  jal       guTranslateF
/* B5E7B8 80240508 00A0382D */   daddu    $a3, $a1, $zero
/* B5E7BC 8024050C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E7C0 80240510 0200282D */  daddu     $a1, $s0, $zero
/* B5E7C4 80240514 0C019D80 */  jal       guMtxCatF
/* B5E7C8 80240518 00A0302D */   daddu    $a2, $a1, $zero
.L8024051C:
/* B5E7CC 8024051C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B5E7D0 80240520 8FB20058 */  lw        $s2, 0x58($sp)
/* B5E7D4 80240524 8FB10054 */  lw        $s1, 0x54($sp)
/* B5E7D8 80240528 8FB00050 */  lw        $s0, 0x50($sp)
/* B5E7DC 8024052C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B5E7E0 80240530 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B5E7E4 80240534 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B5E7E8 80240538 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B5E7EC 8024053C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B5E7F0 80240540 24020002 */  addiu     $v0, $zero, 2
/* B5E7F4 80240544 03E00008 */  jr        $ra
/* B5E7F8 80240548 27BD0088 */   addiu    $sp, $sp, 0x88
