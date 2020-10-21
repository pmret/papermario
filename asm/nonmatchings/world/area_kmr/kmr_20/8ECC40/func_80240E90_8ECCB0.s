.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_8ECCB0
/* 8ECCB0 80240E90 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8ECCB4 80240E94 AFB10054 */  sw        $s1, 0x54($sp)
/* 8ECCB8 80240E98 0080882D */  daddu     $s1, $a0, $zero
/* 8ECCBC 80240E9C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8ECCC0 80240EA0 AFB20058 */  sw        $s2, 0x58($sp)
/* 8ECCC4 80240EA4 AFB00050 */  sw        $s0, 0x50($sp)
/* 8ECCC8 80240EA8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8ECCCC 80240EAC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8ECCD0 80240EB0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8ECCD4 80240EB4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8ECCD8 80240EB8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8ECCDC 80240EBC 8E30000C */  lw        $s0, 0xc($s1)
/* 8ECCE0 80240EC0 8E050000 */  lw        $a1, ($s0)
/* 8ECCE4 80240EC4 0C0B1EAF */  jal       get_variable
/* 8ECCE8 80240EC8 26100004 */   addiu    $s0, $s0, 4
/* 8ECCEC 80240ECC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8ECCF0 80240ED0 0040202D */   daddu    $a0, $v0, $zero
/* 8ECCF4 80240ED4 8E050000 */  lw        $a1, ($s0)
/* 8ECCF8 80240ED8 26100004 */  addiu     $s0, $s0, 4
/* 8ECCFC 80240EDC 0220202D */  daddu     $a0, $s1, $zero
/* 8ECD00 80240EE0 0C0B210B */  jal       get_float_variable
/* 8ECD04 80240EE4 0040902D */   daddu    $s2, $v0, $zero
/* 8ECD08 80240EE8 8E050000 */  lw        $a1, ($s0)
/* 8ECD0C 80240EEC 26100004 */  addiu     $s0, $s0, 4
/* 8ECD10 80240EF0 0220202D */  daddu     $a0, $s1, $zero
/* 8ECD14 80240EF4 0C0B210B */  jal       get_float_variable
/* 8ECD18 80240EF8 46000706 */   mov.s    $f28, $f0
/* 8ECD1C 80240EFC 8E050000 */  lw        $a1, ($s0)
/* 8ECD20 80240F00 26100004 */  addiu     $s0, $s0, 4
/* 8ECD24 80240F04 0220202D */  daddu     $a0, $s1, $zero
/* 8ECD28 80240F08 0C0B210B */  jal       get_float_variable
/* 8ECD2C 80240F0C 46000686 */   mov.s    $f26, $f0
/* 8ECD30 80240F10 0220202D */  daddu     $a0, $s1, $zero
/* 8ECD34 80240F14 8E050000 */  lw        $a1, ($s0)
/* 8ECD38 80240F18 0C0B210B */  jal       get_float_variable
/* 8ECD3C 80240F1C 46000586 */   mov.s    $f22, $f0
/* 8ECD40 80240F20 0240202D */  daddu     $a0, $s2, $zero
/* 8ECD44 80240F24 0C046B4C */  jal       get_model_from_list_index
/* 8ECD48 80240F28 46000606 */   mov.s    $f24, $f0
/* 8ECD4C 80240F2C 0040882D */  daddu     $s1, $v0, $zero
/* 8ECD50 80240F30 96220000 */  lhu       $v0, ($s1)
/* 8ECD54 80240F34 30420400 */  andi      $v0, $v0, 0x400
/* 8ECD58 80240F38 1440001E */  bnez      $v0, .L80240FB4
/* 8ECD5C 80240F3C 26300058 */   addiu    $s0, $s1, 0x58
/* 8ECD60 80240F40 4480A000 */  mtc1      $zero, $f20
/* 8ECD64 80240F44 4406B000 */  mfc1      $a2, $f22
/* 8ECD68 80240F48 4405A000 */  mfc1      $a1, $f20
/* 8ECD6C 80240F4C 4407A000 */  mfc1      $a3, $f20
/* 8ECD70 80240F50 0C019E40 */  jal       guTranslateF
/* 8ECD74 80240F54 0200202D */   daddu    $a0, $s0, $zero
/* 8ECD78 80240F58 4405E000 */  mfc1      $a1, $f28
/* 8ECD7C 80240F5C 4406D000 */  mfc1      $a2, $f26
/* 8ECD80 80240F60 4407C000 */  mfc1      $a3, $f24
/* 8ECD84 80240F64 0C090388 */  jal       func_80240E20_8ECC40
/* 8ECD88 80240F68 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ECD8C 80240F6C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECD90 80240F70 0200282D */  daddu     $a1, $s0, $zero
/* 8ECD94 80240F74 0C019D80 */  jal       guMtxCatF
/* 8ECD98 80240F78 0200302D */   daddu    $a2, $s0, $zero
/* 8ECD9C 80240F7C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECDA0 80240F80 4600B587 */  neg.s     $f22, $f22
/* 8ECDA4 80240F84 4405A000 */  mfc1      $a1, $f20
/* 8ECDA8 80240F88 4406B000 */  mfc1      $a2, $f22
/* 8ECDAC 80240F8C 0C019E40 */  jal       guTranslateF
/* 8ECDB0 80240F90 00A0382D */   daddu    $a3, $a1, $zero
/* 8ECDB4 80240F94 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECDB8 80240F98 0200282D */  daddu     $a1, $s0, $zero
/* 8ECDBC 80240F9C 0C019D80 */  jal       guMtxCatF
/* 8ECDC0 80240FA0 00A0302D */   daddu    $a2, $a1, $zero
/* 8ECDC4 80240FA4 96220000 */  lhu       $v0, ($s1)
/* 8ECDC8 80240FA8 34421400 */  ori       $v0, $v0, 0x1400
/* 8ECDCC 80240FAC 0809040B */  j         .L8024102C
/* 8ECDD0 80240FB0 A6220000 */   sh       $v0, ($s1)
.L80240FB4:
/* 8ECDD4 80240FB4 4480A000 */  mtc1      $zero, $f20
/* 8ECDD8 80240FB8 4406B000 */  mfc1      $a2, $f22
/* 8ECDDC 80240FBC 4405A000 */  mfc1      $a1, $f20
/* 8ECDE0 80240FC0 4407A000 */  mfc1      $a3, $f20
/* 8ECDE4 80240FC4 0C019E40 */  jal       guTranslateF
/* 8ECDE8 80240FC8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ECDEC 80240FCC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECDF0 80240FD0 26300058 */  addiu     $s0, $s1, 0x58
/* 8ECDF4 80240FD4 0200282D */  daddu     $a1, $s0, $zero
/* 8ECDF8 80240FD8 0C019D80 */  jal       guMtxCatF
/* 8ECDFC 80240FDC 0200302D */   daddu    $a2, $s0, $zero
/* 8ECE00 80240FE0 4405E000 */  mfc1      $a1, $f28
/* 8ECE04 80240FE4 4406D000 */  mfc1      $a2, $f26
/* 8ECE08 80240FE8 4407C000 */  mfc1      $a3, $f24
/* 8ECE0C 80240FEC 0C090388 */  jal       func_80240E20_8ECC40
/* 8ECE10 80240FF0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ECE14 80240FF4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECE18 80240FF8 0200282D */  daddu     $a1, $s0, $zero
/* 8ECE1C 80240FFC 0C019D80 */  jal       guMtxCatF
/* 8ECE20 80241000 0200302D */   daddu    $a2, $s0, $zero
/* 8ECE24 80241004 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECE28 80241008 4600B587 */  neg.s     $f22, $f22
/* 8ECE2C 8024100C 4405A000 */  mfc1      $a1, $f20
/* 8ECE30 80241010 4406B000 */  mfc1      $a2, $f22
/* 8ECE34 80241014 0C019E40 */  jal       guTranslateF
/* 8ECE38 80241018 00A0382D */   daddu    $a3, $a1, $zero
/* 8ECE3C 8024101C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECE40 80241020 0200282D */  daddu     $a1, $s0, $zero
/* 8ECE44 80241024 0C019D80 */  jal       guMtxCatF
/* 8ECE48 80241028 00A0302D */   daddu    $a2, $a1, $zero
.L8024102C:
/* 8ECE4C 8024102C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8ECE50 80241030 8FB20058 */  lw        $s2, 0x58($sp)
/* 8ECE54 80241034 8FB10054 */  lw        $s1, 0x54($sp)
/* 8ECE58 80241038 8FB00050 */  lw        $s0, 0x50($sp)
/* 8ECE5C 8024103C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8ECE60 80241040 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8ECE64 80241044 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8ECE68 80241048 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8ECE6C 8024104C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8ECE70 80241050 24020002 */  addiu     $v0, $zero, 2
/* 8ECE74 80241054 03E00008 */  jr        $ra
/* 8ECE78 80241058 27BD0088 */   addiu    $sp, $sp, 0x88
/* 8ECE7C 8024105C 00000000 */  nop       
