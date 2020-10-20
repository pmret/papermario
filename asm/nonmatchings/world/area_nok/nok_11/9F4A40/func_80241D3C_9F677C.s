.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D3C_9F677C
/* 9F677C 80241D3C 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 9F6780 80241D40 AFB10054 */  sw        $s1, 0x54($sp)
/* 9F6784 80241D44 0080882D */  daddu     $s1, $a0, $zero
/* 9F6788 80241D48 AFBF005C */  sw        $ra, 0x5c($sp)
/* 9F678C 80241D4C AFB20058 */  sw        $s2, 0x58($sp)
/* 9F6790 80241D50 AFB00050 */  sw        $s0, 0x50($sp)
/* 9F6794 80241D54 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 9F6798 80241D58 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 9F679C 80241D5C F7B80070 */  sdc1      $f24, 0x70($sp)
/* 9F67A0 80241D60 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 9F67A4 80241D64 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 9F67A8 80241D68 8E30000C */  lw        $s0, 0xc($s1)
/* 9F67AC 80241D6C 8E050000 */  lw        $a1, ($s0)
/* 9F67B0 80241D70 0C0B1EAF */  jal       get_variable
/* 9F67B4 80241D74 26100004 */   addiu    $s0, $s0, 4
/* 9F67B8 80241D78 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 9F67BC 80241D7C 0040202D */   daddu    $a0, $v0, $zero
/* 9F67C0 80241D80 8E050000 */  lw        $a1, ($s0)
/* 9F67C4 80241D84 26100004 */  addiu     $s0, $s0, 4
/* 9F67C8 80241D88 0220202D */  daddu     $a0, $s1, $zero
/* 9F67CC 80241D8C 0C0B210B */  jal       get_float_variable
/* 9F67D0 80241D90 0040902D */   daddu    $s2, $v0, $zero
/* 9F67D4 80241D94 8E050000 */  lw        $a1, ($s0)
/* 9F67D8 80241D98 26100004 */  addiu     $s0, $s0, 4
/* 9F67DC 80241D9C 0220202D */  daddu     $a0, $s1, $zero
/* 9F67E0 80241DA0 0C0B210B */  jal       get_float_variable
/* 9F67E4 80241DA4 46000706 */   mov.s    $f28, $f0
/* 9F67E8 80241DA8 8E050000 */  lw        $a1, ($s0)
/* 9F67EC 80241DAC 26100004 */  addiu     $s0, $s0, 4
/* 9F67F0 80241DB0 0220202D */  daddu     $a0, $s1, $zero
/* 9F67F4 80241DB4 0C0B210B */  jal       get_float_variable
/* 9F67F8 80241DB8 46000686 */   mov.s    $f26, $f0
/* 9F67FC 80241DBC 0220202D */  daddu     $a0, $s1, $zero
/* 9F6800 80241DC0 8E050000 */  lw        $a1, ($s0)
/* 9F6804 80241DC4 0C0B210B */  jal       get_float_variable
/* 9F6808 80241DC8 46000586 */   mov.s    $f22, $f0
/* 9F680C 80241DCC 0240202D */  daddu     $a0, $s2, $zero
/* 9F6810 80241DD0 0C046B4C */  jal       get_model_from_list_index
/* 9F6814 80241DD4 46000606 */   mov.s    $f24, $f0
/* 9F6818 80241DD8 0040882D */  daddu     $s1, $v0, $zero
/* 9F681C 80241DDC 96220000 */  lhu       $v0, ($s1)
/* 9F6820 80241DE0 30420400 */  andi      $v0, $v0, 0x400
/* 9F6824 80241DE4 1440001E */  bnez      $v0, .L80241E60
/* 9F6828 80241DE8 26300058 */   addiu    $s0, $s1, 0x58
/* 9F682C 80241DEC 4480A000 */  mtc1      $zero, $f20
/* 9F6830 80241DF0 4406B000 */  mfc1      $a2, $f22
/* 9F6834 80241DF4 4405A000 */  mfc1      $a1, $f20
/* 9F6838 80241DF8 4407A000 */  mfc1      $a3, $f20
/* 9F683C 80241DFC 0C019E40 */  jal       guTranslateF
/* 9F6840 80241E00 0200202D */   daddu    $a0, $s0, $zero
/* 9F6844 80241E04 4405E000 */  mfc1      $a1, $f28
/* 9F6848 80241E08 4406D000 */  mfc1      $a2, $f26
/* 9F684C 80241E0C 4407C000 */  mfc1      $a3, $f24
/* 9F6850 80241E10 0C090733 */  jal       func_80241CCC
/* 9F6854 80241E14 27A40010 */   addiu    $a0, $sp, 0x10
/* 9F6858 80241E18 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F685C 80241E1C 0200282D */  daddu     $a1, $s0, $zero
/* 9F6860 80241E20 0C019D80 */  jal       guMtxCatF
/* 9F6864 80241E24 0200302D */   daddu    $a2, $s0, $zero
/* 9F6868 80241E28 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F686C 80241E2C 4600B587 */  neg.s     $f22, $f22
/* 9F6870 80241E30 4405A000 */  mfc1      $a1, $f20
/* 9F6874 80241E34 4406B000 */  mfc1      $a2, $f22
/* 9F6878 80241E38 0C019E40 */  jal       guTranslateF
/* 9F687C 80241E3C 00A0382D */   daddu    $a3, $a1, $zero
/* 9F6880 80241E40 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F6884 80241E44 0200282D */  daddu     $a1, $s0, $zero
/* 9F6888 80241E48 0C019D80 */  jal       guMtxCatF
/* 9F688C 80241E4C 00A0302D */   daddu    $a2, $a1, $zero
/* 9F6890 80241E50 96220000 */  lhu       $v0, ($s1)
/* 9F6894 80241E54 34421400 */  ori       $v0, $v0, 0x1400
/* 9F6898 80241E58 080907B6 */  j         .L80241ED8
/* 9F689C 80241E5C A6220000 */   sh       $v0, ($s1)
.L80241E60:
/* 9F68A0 80241E60 4480A000 */  mtc1      $zero, $f20
/* 9F68A4 80241E64 4406B000 */  mfc1      $a2, $f22
/* 9F68A8 80241E68 4405A000 */  mfc1      $a1, $f20
/* 9F68AC 80241E6C 4407A000 */  mfc1      $a3, $f20
/* 9F68B0 80241E70 0C019E40 */  jal       guTranslateF
/* 9F68B4 80241E74 27A40010 */   addiu    $a0, $sp, 0x10
/* 9F68B8 80241E78 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F68BC 80241E7C 26300058 */  addiu     $s0, $s1, 0x58
/* 9F68C0 80241E80 0200282D */  daddu     $a1, $s0, $zero
/* 9F68C4 80241E84 0C019D80 */  jal       guMtxCatF
/* 9F68C8 80241E88 0200302D */   daddu    $a2, $s0, $zero
/* 9F68CC 80241E8C 4405E000 */  mfc1      $a1, $f28
/* 9F68D0 80241E90 4406D000 */  mfc1      $a2, $f26
/* 9F68D4 80241E94 4407C000 */  mfc1      $a3, $f24
/* 9F68D8 80241E98 0C090733 */  jal       func_80241CCC
/* 9F68DC 80241E9C 27A40010 */   addiu    $a0, $sp, 0x10
/* 9F68E0 80241EA0 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F68E4 80241EA4 0200282D */  daddu     $a1, $s0, $zero
/* 9F68E8 80241EA8 0C019D80 */  jal       guMtxCatF
/* 9F68EC 80241EAC 0200302D */   daddu    $a2, $s0, $zero
/* 9F68F0 80241EB0 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F68F4 80241EB4 4600B587 */  neg.s     $f22, $f22
/* 9F68F8 80241EB8 4405A000 */  mfc1      $a1, $f20
/* 9F68FC 80241EBC 4406B000 */  mfc1      $a2, $f22
/* 9F6900 80241EC0 0C019E40 */  jal       guTranslateF
/* 9F6904 80241EC4 00A0382D */   daddu    $a3, $a1, $zero
/* 9F6908 80241EC8 27A40010 */  addiu     $a0, $sp, 0x10
/* 9F690C 80241ECC 0200282D */  daddu     $a1, $s0, $zero
/* 9F6910 80241ED0 0C019D80 */  jal       guMtxCatF
/* 9F6914 80241ED4 00A0302D */   daddu    $a2, $a1, $zero
.L80241ED8:
/* 9F6918 80241ED8 8FBF005C */  lw        $ra, 0x5c($sp)
/* 9F691C 80241EDC 8FB20058 */  lw        $s2, 0x58($sp)
/* 9F6920 80241EE0 8FB10054 */  lw        $s1, 0x54($sp)
/* 9F6924 80241EE4 8FB00050 */  lw        $s0, 0x50($sp)
/* 9F6928 80241EE8 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 9F692C 80241EEC D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 9F6930 80241EF0 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 9F6934 80241EF4 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 9F6938 80241EF8 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 9F693C 80241EFC 24020002 */  addiu     $v0, $zero, 2
/* 9F6940 80241F00 03E00008 */  jr        $ra
/* 9F6944 80241F04 27BD0088 */   addiu    $sp, $sp, 0x88
