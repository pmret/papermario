.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E10_B5A680
/* B5A680 80240E10 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B5A684 80240E14 AFB10054 */  sw        $s1, 0x54($sp)
/* B5A688 80240E18 0080882D */  daddu     $s1, $a0, $zero
/* B5A68C 80240E1C AFBF005C */  sw        $ra, 0x5c($sp)
/* B5A690 80240E20 AFB20058 */  sw        $s2, 0x58($sp)
/* B5A694 80240E24 AFB00050 */  sw        $s0, 0x50($sp)
/* B5A698 80240E28 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B5A69C 80240E2C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B5A6A0 80240E30 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B5A6A4 80240E34 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B5A6A8 80240E38 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B5A6AC 80240E3C 8E30000C */  lw        $s0, 0xc($s1)
/* B5A6B0 80240E40 8E050000 */  lw        $a1, ($s0)
/* B5A6B4 80240E44 0C0B1EAF */  jal       get_variable
/* B5A6B8 80240E48 26100004 */   addiu    $s0, $s0, 4
/* B5A6BC 80240E4C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B5A6C0 80240E50 0040202D */   daddu    $a0, $v0, $zero
/* B5A6C4 80240E54 8E050000 */  lw        $a1, ($s0)
/* B5A6C8 80240E58 26100004 */  addiu     $s0, $s0, 4
/* B5A6CC 80240E5C 0220202D */  daddu     $a0, $s1, $zero
/* B5A6D0 80240E60 0C0B210B */  jal       get_float_variable
/* B5A6D4 80240E64 0040902D */   daddu    $s2, $v0, $zero
/* B5A6D8 80240E68 8E050000 */  lw        $a1, ($s0)
/* B5A6DC 80240E6C 26100004 */  addiu     $s0, $s0, 4
/* B5A6E0 80240E70 0220202D */  daddu     $a0, $s1, $zero
/* B5A6E4 80240E74 0C0B210B */  jal       get_float_variable
/* B5A6E8 80240E78 46000706 */   mov.s    $f28, $f0
/* B5A6EC 80240E7C 8E050000 */  lw        $a1, ($s0)
/* B5A6F0 80240E80 26100004 */  addiu     $s0, $s0, 4
/* B5A6F4 80240E84 0220202D */  daddu     $a0, $s1, $zero
/* B5A6F8 80240E88 0C0B210B */  jal       get_float_variable
/* B5A6FC 80240E8C 46000686 */   mov.s    $f26, $f0
/* B5A700 80240E90 0220202D */  daddu     $a0, $s1, $zero
/* B5A704 80240E94 8E050000 */  lw        $a1, ($s0)
/* B5A708 80240E98 0C0B210B */  jal       get_float_variable
/* B5A70C 80240E9C 46000586 */   mov.s    $f22, $f0
/* B5A710 80240EA0 0240202D */  daddu     $a0, $s2, $zero
/* B5A714 80240EA4 0C046B4C */  jal       get_model_from_list_index
/* B5A718 80240EA8 46000606 */   mov.s    $f24, $f0
/* B5A71C 80240EAC 0040882D */  daddu     $s1, $v0, $zero
/* B5A720 80240EB0 96220000 */  lhu       $v0, ($s1)
/* B5A724 80240EB4 30420400 */  andi      $v0, $v0, 0x400
/* B5A728 80240EB8 1440001E */  bnez      $v0, .L80240F34
/* B5A72C 80240EBC 26300058 */   addiu    $s0, $s1, 0x58
/* B5A730 80240EC0 4480A000 */  mtc1      $zero, $f20
/* B5A734 80240EC4 4406B000 */  mfc1      $a2, $f22
/* B5A738 80240EC8 4405A000 */  mfc1      $a1, $f20
/* B5A73C 80240ECC 4407A000 */  mfc1      $a3, $f20
/* B5A740 80240ED0 0C019E40 */  jal       guTranslateF
/* B5A744 80240ED4 0200202D */   daddu    $a0, $s0, $zero
/* B5A748 80240ED8 4405E000 */  mfc1      $a1, $f28
/* B5A74C 80240EDC 4406D000 */  mfc1      $a2, $f26
/* B5A750 80240EE0 4407C000 */  mfc1      $a3, $f24
/* B5A754 80240EE4 0C090368 */  jal       func_80240DA0_B5A610
/* B5A758 80240EE8 27A40010 */   addiu    $a0, $sp, 0x10
/* B5A75C 80240EEC 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A760 80240EF0 0200282D */  daddu     $a1, $s0, $zero
/* B5A764 80240EF4 0C019D80 */  jal       guMtxCatF
/* B5A768 80240EF8 0200302D */   daddu    $a2, $s0, $zero
/* B5A76C 80240EFC 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A770 80240F00 4600B587 */  neg.s     $f22, $f22
/* B5A774 80240F04 4405A000 */  mfc1      $a1, $f20
/* B5A778 80240F08 4406B000 */  mfc1      $a2, $f22
/* B5A77C 80240F0C 0C019E40 */  jal       guTranslateF
/* B5A780 80240F10 00A0382D */   daddu    $a3, $a1, $zero
/* B5A784 80240F14 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A788 80240F18 0200282D */  daddu     $a1, $s0, $zero
/* B5A78C 80240F1C 0C019D80 */  jal       guMtxCatF
/* B5A790 80240F20 00A0302D */   daddu    $a2, $a1, $zero
/* B5A794 80240F24 96220000 */  lhu       $v0, ($s1)
/* B5A798 80240F28 34421400 */  ori       $v0, $v0, 0x1400
/* B5A79C 80240F2C 080903EB */  j         .L80240FAC
/* B5A7A0 80240F30 A6220000 */   sh       $v0, ($s1)
.L80240F34:
/* B5A7A4 80240F34 4480A000 */  mtc1      $zero, $f20
/* B5A7A8 80240F38 4406B000 */  mfc1      $a2, $f22
/* B5A7AC 80240F3C 4405A000 */  mfc1      $a1, $f20
/* B5A7B0 80240F40 4407A000 */  mfc1      $a3, $f20
/* B5A7B4 80240F44 0C019E40 */  jal       guTranslateF
/* B5A7B8 80240F48 27A40010 */   addiu    $a0, $sp, 0x10
/* B5A7BC 80240F4C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A7C0 80240F50 26300058 */  addiu     $s0, $s1, 0x58
/* B5A7C4 80240F54 0200282D */  daddu     $a1, $s0, $zero
/* B5A7C8 80240F58 0C019D80 */  jal       guMtxCatF
/* B5A7CC 80240F5C 0200302D */   daddu    $a2, $s0, $zero
/* B5A7D0 80240F60 4405E000 */  mfc1      $a1, $f28
/* B5A7D4 80240F64 4406D000 */  mfc1      $a2, $f26
/* B5A7D8 80240F68 4407C000 */  mfc1      $a3, $f24
/* B5A7DC 80240F6C 0C090368 */  jal       func_80240DA0_B5A610
/* B5A7E0 80240F70 27A40010 */   addiu    $a0, $sp, 0x10
/* B5A7E4 80240F74 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A7E8 80240F78 0200282D */  daddu     $a1, $s0, $zero
/* B5A7EC 80240F7C 0C019D80 */  jal       guMtxCatF
/* B5A7F0 80240F80 0200302D */   daddu    $a2, $s0, $zero
/* B5A7F4 80240F84 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A7F8 80240F88 4600B587 */  neg.s     $f22, $f22
/* B5A7FC 80240F8C 4405A000 */  mfc1      $a1, $f20
/* B5A800 80240F90 4406B000 */  mfc1      $a2, $f22
/* B5A804 80240F94 0C019E40 */  jal       guTranslateF
/* B5A808 80240F98 00A0382D */   daddu    $a3, $a1, $zero
/* B5A80C 80240F9C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A810 80240FA0 0200282D */  daddu     $a1, $s0, $zero
/* B5A814 80240FA4 0C019D80 */  jal       guMtxCatF
/* B5A818 80240FA8 00A0302D */   daddu    $a2, $a1, $zero
.L80240FAC:
/* B5A81C 80240FAC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B5A820 80240FB0 8FB20058 */  lw        $s2, 0x58($sp)
/* B5A824 80240FB4 8FB10054 */  lw        $s1, 0x54($sp)
/* B5A828 80240FB8 8FB00050 */  lw        $s0, 0x50($sp)
/* B5A82C 80240FBC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B5A830 80240FC0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B5A834 80240FC4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B5A838 80240FC8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B5A83C 80240FCC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B5A840 80240FD0 24020002 */  addiu     $v0, $zero, 2
/* B5A844 80240FD4 03E00008 */  jr        $ra
/* B5A848 80240FD8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B5A84C 80240FDC 00000000 */  nop       
