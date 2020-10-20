.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E30
/* 954DF0 80240E30 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 954DF4 80240E34 AFB10054 */  sw        $s1, 0x54($sp)
/* 954DF8 80240E38 0080882D */  daddu     $s1, $a0, $zero
/* 954DFC 80240E3C AFBF005C */  sw        $ra, 0x5c($sp)
/* 954E00 80240E40 AFB20058 */  sw        $s2, 0x58($sp)
/* 954E04 80240E44 AFB00050 */  sw        $s0, 0x50($sp)
/* 954E08 80240E48 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 954E0C 80240E4C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 954E10 80240E50 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 954E14 80240E54 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 954E18 80240E58 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 954E1C 80240E5C 8E30000C */  lw        $s0, 0xc($s1)
/* 954E20 80240E60 8E050000 */  lw        $a1, ($s0)
/* 954E24 80240E64 0C0B1EAF */  jal       get_variable
/* 954E28 80240E68 26100004 */   addiu    $s0, $s0, 4
/* 954E2C 80240E6C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 954E30 80240E70 0040202D */   daddu    $a0, $v0, $zero
/* 954E34 80240E74 8E050000 */  lw        $a1, ($s0)
/* 954E38 80240E78 26100004 */  addiu     $s0, $s0, 4
/* 954E3C 80240E7C 0220202D */  daddu     $a0, $s1, $zero
/* 954E40 80240E80 0C0B210B */  jal       get_float_variable
/* 954E44 80240E84 0040902D */   daddu    $s2, $v0, $zero
/* 954E48 80240E88 8E050000 */  lw        $a1, ($s0)
/* 954E4C 80240E8C 26100004 */  addiu     $s0, $s0, 4
/* 954E50 80240E90 0220202D */  daddu     $a0, $s1, $zero
/* 954E54 80240E94 0C0B210B */  jal       get_float_variable
/* 954E58 80240E98 46000706 */   mov.s    $f28, $f0
/* 954E5C 80240E9C 8E050000 */  lw        $a1, ($s0)
/* 954E60 80240EA0 26100004 */  addiu     $s0, $s0, 4
/* 954E64 80240EA4 0220202D */  daddu     $a0, $s1, $zero
/* 954E68 80240EA8 0C0B210B */  jal       get_float_variable
/* 954E6C 80240EAC 46000686 */   mov.s    $f26, $f0
/* 954E70 80240EB0 0220202D */  daddu     $a0, $s1, $zero
/* 954E74 80240EB4 8E050000 */  lw        $a1, ($s0)
/* 954E78 80240EB8 0C0B210B */  jal       get_float_variable
/* 954E7C 80240EBC 46000586 */   mov.s    $f22, $f0
/* 954E80 80240EC0 0240202D */  daddu     $a0, $s2, $zero
/* 954E84 80240EC4 0C046B4C */  jal       get_model_from_list_index
/* 954E88 80240EC8 46000606 */   mov.s    $f24, $f0
/* 954E8C 80240ECC 0040882D */  daddu     $s1, $v0, $zero
/* 954E90 80240ED0 96220000 */  lhu       $v0, ($s1)
/* 954E94 80240ED4 30420400 */  andi      $v0, $v0, 0x400
/* 954E98 80240ED8 1440001E */  bnez      $v0, .L80240F54
/* 954E9C 80240EDC 26300058 */   addiu    $s0, $s1, 0x58
/* 954EA0 80240EE0 4480A000 */  mtc1      $zero, $f20
/* 954EA4 80240EE4 4406B000 */  mfc1      $a2, $f22
/* 954EA8 80240EE8 4405A000 */  mfc1      $a1, $f20
/* 954EAC 80240EEC 4407A000 */  mfc1      $a3, $f20
/* 954EB0 80240EF0 0C019E40 */  jal       guTranslateF
/* 954EB4 80240EF4 0200202D */   daddu    $a0, $s0, $zero
/* 954EB8 80240EF8 4405E000 */  mfc1      $a1, $f28
/* 954EBC 80240EFC 4406D000 */  mfc1      $a2, $f26
/* 954EC0 80240F00 4407C000 */  mfc1      $a3, $f24
/* 954EC4 80240F04 0C090370 */  jal       func_80240DC0
/* 954EC8 80240F08 27A40010 */   addiu    $a0, $sp, 0x10
/* 954ECC 80240F0C 27A40010 */  addiu     $a0, $sp, 0x10
/* 954ED0 80240F10 0200282D */  daddu     $a1, $s0, $zero
/* 954ED4 80240F14 0C019D80 */  jal       guMtxCatF
/* 954ED8 80240F18 0200302D */   daddu    $a2, $s0, $zero
/* 954EDC 80240F1C 27A40010 */  addiu     $a0, $sp, 0x10
/* 954EE0 80240F20 4600B587 */  neg.s     $f22, $f22
/* 954EE4 80240F24 4405A000 */  mfc1      $a1, $f20
/* 954EE8 80240F28 4406B000 */  mfc1      $a2, $f22
/* 954EEC 80240F2C 0C019E40 */  jal       guTranslateF
/* 954EF0 80240F30 00A0382D */   daddu    $a3, $a1, $zero
/* 954EF4 80240F34 27A40010 */  addiu     $a0, $sp, 0x10
/* 954EF8 80240F38 0200282D */  daddu     $a1, $s0, $zero
/* 954EFC 80240F3C 0C019D80 */  jal       guMtxCatF
/* 954F00 80240F40 00A0302D */   daddu    $a2, $a1, $zero
/* 954F04 80240F44 96220000 */  lhu       $v0, ($s1)
/* 954F08 80240F48 34421400 */  ori       $v0, $v0, 0x1400
/* 954F0C 80240F4C 080903F3 */  j         .L80240FCC
/* 954F10 80240F50 A6220000 */   sh       $v0, ($s1)
.L80240F54:
/* 954F14 80240F54 4480A000 */  mtc1      $zero, $f20
/* 954F18 80240F58 4406B000 */  mfc1      $a2, $f22
/* 954F1C 80240F5C 4405A000 */  mfc1      $a1, $f20
/* 954F20 80240F60 4407A000 */  mfc1      $a3, $f20
/* 954F24 80240F64 0C019E40 */  jal       guTranslateF
/* 954F28 80240F68 27A40010 */   addiu    $a0, $sp, 0x10
/* 954F2C 80240F6C 27A40010 */  addiu     $a0, $sp, 0x10
/* 954F30 80240F70 26300058 */  addiu     $s0, $s1, 0x58
/* 954F34 80240F74 0200282D */  daddu     $a1, $s0, $zero
/* 954F38 80240F78 0C019D80 */  jal       guMtxCatF
/* 954F3C 80240F7C 0200302D */   daddu    $a2, $s0, $zero
/* 954F40 80240F80 4405E000 */  mfc1      $a1, $f28
/* 954F44 80240F84 4406D000 */  mfc1      $a2, $f26
/* 954F48 80240F88 4407C000 */  mfc1      $a3, $f24
/* 954F4C 80240F8C 0C090370 */  jal       func_80240DC0
/* 954F50 80240F90 27A40010 */   addiu    $a0, $sp, 0x10
/* 954F54 80240F94 27A40010 */  addiu     $a0, $sp, 0x10
/* 954F58 80240F98 0200282D */  daddu     $a1, $s0, $zero
/* 954F5C 80240F9C 0C019D80 */  jal       guMtxCatF
/* 954F60 80240FA0 0200302D */   daddu    $a2, $s0, $zero
/* 954F64 80240FA4 27A40010 */  addiu     $a0, $sp, 0x10
/* 954F68 80240FA8 4600B587 */  neg.s     $f22, $f22
/* 954F6C 80240FAC 4405A000 */  mfc1      $a1, $f20
/* 954F70 80240FB0 4406B000 */  mfc1      $a2, $f22
/* 954F74 80240FB4 0C019E40 */  jal       guTranslateF
/* 954F78 80240FB8 00A0382D */   daddu    $a3, $a1, $zero
/* 954F7C 80240FBC 27A40010 */  addiu     $a0, $sp, 0x10
/* 954F80 80240FC0 0200282D */  daddu     $a1, $s0, $zero
/* 954F84 80240FC4 0C019D80 */  jal       guMtxCatF
/* 954F88 80240FC8 00A0302D */   daddu    $a2, $a1, $zero
.L80240FCC:
/* 954F8C 80240FCC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 954F90 80240FD0 8FB20058 */  lw        $s2, 0x58($sp)
/* 954F94 80240FD4 8FB10054 */  lw        $s1, 0x54($sp)
/* 954F98 80240FD8 8FB00050 */  lw        $s0, 0x50($sp)
/* 954F9C 80240FDC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 954FA0 80240FE0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 954FA4 80240FE4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 954FA8 80240FE8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 954FAC 80240FEC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 954FB0 80240FF0 24020002 */  addiu     $v0, $zero, 2
/* 954FB4 80240FF4 03E00008 */  jr        $ra
/* 954FB8 80240FF8 27BD0088 */   addiu    $sp, $sp, 0x88
/* 954FBC 80240FFC 00000000 */  nop       
