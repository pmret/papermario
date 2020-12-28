.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B80_43A610
/* 43A610 80218B80 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 43A614 80218B84 AFB10054 */  sw        $s1, 0x54($sp)
/* 43A618 80218B88 0080882D */  daddu     $s1, $a0, $zero
/* 43A61C 80218B8C AFBF005C */  sw        $ra, 0x5c($sp)
/* 43A620 80218B90 AFB20058 */  sw        $s2, 0x58($sp)
/* 43A624 80218B94 AFB00050 */  sw        $s0, 0x50($sp)
/* 43A628 80218B98 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 43A62C 80218B9C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 43A630 80218BA0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 43A634 80218BA4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 43A638 80218BA8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 43A63C 80218BAC 8E30000C */  lw        $s0, 0xc($s1)
/* 43A640 80218BB0 8E050000 */  lw        $a1, ($s0)
/* 43A644 80218BB4 0C0B1EAF */  jal       get_variable
/* 43A648 80218BB8 26100004 */   addiu    $s0, $s0, 4
/* 43A64C 80218BBC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 43A650 80218BC0 0040202D */   daddu    $a0, $v0, $zero
/* 43A654 80218BC4 8E050000 */  lw        $a1, ($s0)
/* 43A658 80218BC8 26100004 */  addiu     $s0, $s0, 4
/* 43A65C 80218BCC 0220202D */  daddu     $a0, $s1, $zero
/* 43A660 80218BD0 0C0B210B */  jal       get_float_variable
/* 43A664 80218BD4 0040902D */   daddu    $s2, $v0, $zero
/* 43A668 80218BD8 8E050000 */  lw        $a1, ($s0)
/* 43A66C 80218BDC 26100004 */  addiu     $s0, $s0, 4
/* 43A670 80218BE0 0220202D */  daddu     $a0, $s1, $zero
/* 43A674 80218BE4 0C0B210B */  jal       get_float_variable
/* 43A678 80218BE8 46000706 */   mov.s    $f28, $f0
/* 43A67C 80218BEC 8E050000 */  lw        $a1, ($s0)
/* 43A680 80218BF0 26100004 */  addiu     $s0, $s0, 4
/* 43A684 80218BF4 0220202D */  daddu     $a0, $s1, $zero
/* 43A688 80218BF8 0C0B210B */  jal       get_float_variable
/* 43A68C 80218BFC 46000686 */   mov.s    $f26, $f0
/* 43A690 80218C00 0220202D */  daddu     $a0, $s1, $zero
/* 43A694 80218C04 8E050000 */  lw        $a1, ($s0)
/* 43A698 80218C08 0C0B210B */  jal       get_float_variable
/* 43A69C 80218C0C 46000586 */   mov.s    $f22, $f0
/* 43A6A0 80218C10 0240202D */  daddu     $a0, $s2, $zero
/* 43A6A4 80218C14 0C046B4C */  jal       get_model_from_list_index
/* 43A6A8 80218C18 46000606 */   mov.s    $f24, $f0
/* 43A6AC 80218C1C 0040882D */  daddu     $s1, $v0, $zero
/* 43A6B0 80218C20 96220000 */  lhu       $v0, ($s1)
/* 43A6B4 80218C24 30420400 */  andi      $v0, $v0, 0x400
/* 43A6B8 80218C28 1440001E */  bnez      $v0, .L80218CA4
/* 43A6BC 80218C2C 26300058 */   addiu    $s0, $s1, 0x58
/* 43A6C0 80218C30 4480A000 */  mtc1      $zero, $f20
/* 43A6C4 80218C34 4406B000 */  mfc1      $a2, $f22
/* 43A6C8 80218C38 4405A000 */  mfc1      $a1, $f20
/* 43A6CC 80218C3C 4407A000 */  mfc1      $a3, $f20
/* 43A6D0 80218C40 0C019E40 */  jal       guTranslateF
/* 43A6D4 80218C44 0200202D */   daddu    $a0, $s0, $zero
/* 43A6D8 80218C48 4405E000 */  mfc1      $a1, $f28
/* 43A6DC 80218C4C 4406D000 */  mfc1      $a2, $f26
/* 43A6E0 80218C50 4407C000 */  mfc1      $a3, $f24
/* 43A6E4 80218C54 0C0862C4 */  jal       func_80218B10_43A5A0
/* 43A6E8 80218C58 27A40010 */   addiu    $a0, $sp, 0x10
/* 43A6EC 80218C5C 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A6F0 80218C60 0200282D */  daddu     $a1, $s0, $zero
/* 43A6F4 80218C64 0C019D80 */  jal       guMtxCatF
/* 43A6F8 80218C68 0200302D */   daddu    $a2, $s0, $zero
/* 43A6FC 80218C6C 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A700 80218C70 4600B587 */  neg.s     $f22, $f22
/* 43A704 80218C74 4405A000 */  mfc1      $a1, $f20
/* 43A708 80218C78 4406B000 */  mfc1      $a2, $f22
/* 43A70C 80218C7C 0C019E40 */  jal       guTranslateF
/* 43A710 80218C80 00A0382D */   daddu    $a3, $a1, $zero
/* 43A714 80218C84 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A718 80218C88 0200282D */  daddu     $a1, $s0, $zero
/* 43A71C 80218C8C 0C019D80 */  jal       guMtxCatF
/* 43A720 80218C90 00A0302D */   daddu    $a2, $a1, $zero
/* 43A724 80218C94 96220000 */  lhu       $v0, ($s1)
/* 43A728 80218C98 34421400 */  ori       $v0, $v0, 0x1400
/* 43A72C 80218C9C 08086347 */  j         .L80218D1C
/* 43A730 80218CA0 A6220000 */   sh       $v0, ($s1)
.L80218CA4:
/* 43A734 80218CA4 4480A000 */  mtc1      $zero, $f20
/* 43A738 80218CA8 4406B000 */  mfc1      $a2, $f22
/* 43A73C 80218CAC 4405A000 */  mfc1      $a1, $f20
/* 43A740 80218CB0 4407A000 */  mfc1      $a3, $f20
/* 43A744 80218CB4 0C019E40 */  jal       guTranslateF
/* 43A748 80218CB8 27A40010 */   addiu    $a0, $sp, 0x10
/* 43A74C 80218CBC 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A750 80218CC0 26300058 */  addiu     $s0, $s1, 0x58
/* 43A754 80218CC4 0200282D */  daddu     $a1, $s0, $zero
/* 43A758 80218CC8 0C019D80 */  jal       guMtxCatF
/* 43A75C 80218CCC 0200302D */   daddu    $a2, $s0, $zero
/* 43A760 80218CD0 4405E000 */  mfc1      $a1, $f28
/* 43A764 80218CD4 4406D000 */  mfc1      $a2, $f26
/* 43A768 80218CD8 4407C000 */  mfc1      $a3, $f24
/* 43A76C 80218CDC 0C0862C4 */  jal       func_80218B10_43A5A0
/* 43A770 80218CE0 27A40010 */   addiu    $a0, $sp, 0x10
/* 43A774 80218CE4 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A778 80218CE8 0200282D */  daddu     $a1, $s0, $zero
/* 43A77C 80218CEC 0C019D80 */  jal       guMtxCatF
/* 43A780 80218CF0 0200302D */   daddu    $a2, $s0, $zero
/* 43A784 80218CF4 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A788 80218CF8 4600B587 */  neg.s     $f22, $f22
/* 43A78C 80218CFC 4405A000 */  mfc1      $a1, $f20
/* 43A790 80218D00 4406B000 */  mfc1      $a2, $f22
/* 43A794 80218D04 0C019E40 */  jal       guTranslateF
/* 43A798 80218D08 00A0382D */   daddu    $a3, $a1, $zero
/* 43A79C 80218D0C 27A40010 */  addiu     $a0, $sp, 0x10
/* 43A7A0 80218D10 0200282D */  daddu     $a1, $s0, $zero
/* 43A7A4 80218D14 0C019D80 */  jal       guMtxCatF
/* 43A7A8 80218D18 00A0302D */   daddu    $a2, $a1, $zero
.L80218D1C:
/* 43A7AC 80218D1C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 43A7B0 80218D20 8FB20058 */  lw        $s2, 0x58($sp)
/* 43A7B4 80218D24 8FB10054 */  lw        $s1, 0x54($sp)
/* 43A7B8 80218D28 8FB00050 */  lw        $s0, 0x50($sp)
/* 43A7BC 80218D2C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 43A7C0 80218D30 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 43A7C4 80218D34 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 43A7C8 80218D38 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 43A7CC 80218D3C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 43A7D0 80218D40 24020002 */  addiu     $v0, $zero, 2
/* 43A7D4 80218D44 03E00008 */  jr        $ra
/* 43A7D8 80218D48 27BD0088 */   addiu    $sp, $sp, 0x88
/* 43A7DC 80218D4C 00000000 */  nop       
