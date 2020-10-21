.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429A0_9C7D80
/* 9C7D80 802429A0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 9C7D84 802429A4 AFB10054 */  sw        $s1, 0x54($sp)
/* 9C7D88 802429A8 0080882D */  daddu     $s1, $a0, $zero
/* 9C7D8C 802429AC AFBF005C */  sw        $ra, 0x5c($sp)
/* 9C7D90 802429B0 AFB20058 */  sw        $s2, 0x58($sp)
/* 9C7D94 802429B4 AFB00050 */  sw        $s0, 0x50($sp)
/* 9C7D98 802429B8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 9C7D9C 802429BC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 9C7DA0 802429C0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 9C7DA4 802429C4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 9C7DA8 802429C8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 9C7DAC 802429CC 8E30000C */  lw        $s0, 0xc($s1)
/* 9C7DB0 802429D0 8E050000 */  lw        $a1, ($s0)
/* 9C7DB4 802429D4 0C0B1EAF */  jal       get_variable
/* 9C7DB8 802429D8 26100004 */   addiu    $s0, $s0, 4
/* 9C7DBC 802429DC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 9C7DC0 802429E0 0040202D */   daddu    $a0, $v0, $zero
/* 9C7DC4 802429E4 8E050000 */  lw        $a1, ($s0)
/* 9C7DC8 802429E8 26100004 */  addiu     $s0, $s0, 4
/* 9C7DCC 802429EC 0220202D */  daddu     $a0, $s1, $zero
/* 9C7DD0 802429F0 0C0B210B */  jal       get_float_variable
/* 9C7DD4 802429F4 0040902D */   daddu    $s2, $v0, $zero
/* 9C7DD8 802429F8 8E050000 */  lw        $a1, ($s0)
/* 9C7DDC 802429FC 26100004 */  addiu     $s0, $s0, 4
/* 9C7DE0 80242A00 0220202D */  daddu     $a0, $s1, $zero
/* 9C7DE4 80242A04 0C0B210B */  jal       get_float_variable
/* 9C7DE8 80242A08 46000706 */   mov.s    $f28, $f0
/* 9C7DEC 80242A0C 8E050000 */  lw        $a1, ($s0)
/* 9C7DF0 80242A10 26100004 */  addiu     $s0, $s0, 4
/* 9C7DF4 80242A14 0220202D */  daddu     $a0, $s1, $zero
/* 9C7DF8 80242A18 0C0B210B */  jal       get_float_variable
/* 9C7DFC 80242A1C 46000686 */   mov.s    $f26, $f0
/* 9C7E00 80242A20 0220202D */  daddu     $a0, $s1, $zero
/* 9C7E04 80242A24 8E050000 */  lw        $a1, ($s0)
/* 9C7E08 80242A28 0C0B210B */  jal       get_float_variable
/* 9C7E0C 80242A2C 46000586 */   mov.s    $f22, $f0
/* 9C7E10 80242A30 0240202D */  daddu     $a0, $s2, $zero
/* 9C7E14 80242A34 0C046B4C */  jal       get_model_from_list_index
/* 9C7E18 80242A38 46000606 */   mov.s    $f24, $f0
/* 9C7E1C 80242A3C 0040882D */  daddu     $s1, $v0, $zero
/* 9C7E20 80242A40 96220000 */  lhu       $v0, ($s1)
/* 9C7E24 80242A44 30420400 */  andi      $v0, $v0, 0x400
/* 9C7E28 80242A48 1440001E */  bnez      $v0, .L80242AC4
/* 9C7E2C 80242A4C 26300058 */   addiu    $s0, $s1, 0x58
/* 9C7E30 80242A50 4480A000 */  mtc1      $zero, $f20
/* 9C7E34 80242A54 4406B000 */  mfc1      $a2, $f22
/* 9C7E38 80242A58 4405A000 */  mfc1      $a1, $f20
/* 9C7E3C 80242A5C 4407A000 */  mfc1      $a3, $f20
/* 9C7E40 80242A60 0C019E40 */  jal       guTranslateF
/* 9C7E44 80242A64 0200202D */   daddu    $a0, $s0, $zero
/* 9C7E48 80242A68 4405E000 */  mfc1      $a1, $f28
/* 9C7E4C 80242A6C 4406D000 */  mfc1      $a2, $f26
/* 9C7E50 80242A70 4407C000 */  mfc1      $a3, $f24
/* 9C7E54 80242A74 0C090A4C */  jal       func_80242930_9C7D10
/* 9C7E58 80242A78 27A40010 */   addiu    $a0, $sp, 0x10
/* 9C7E5C 80242A7C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7E60 80242A80 0200282D */  daddu     $a1, $s0, $zero
/* 9C7E64 80242A84 0C019D80 */  jal       guMtxCatF
/* 9C7E68 80242A88 0200302D */   daddu    $a2, $s0, $zero
/* 9C7E6C 80242A8C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7E70 80242A90 4600B587 */  neg.s     $f22, $f22
/* 9C7E74 80242A94 4405A000 */  mfc1      $a1, $f20
/* 9C7E78 80242A98 4406B000 */  mfc1      $a2, $f22
/* 9C7E7C 80242A9C 0C019E40 */  jal       guTranslateF
/* 9C7E80 80242AA0 00A0382D */   daddu    $a3, $a1, $zero
/* 9C7E84 80242AA4 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7E88 80242AA8 0200282D */  daddu     $a1, $s0, $zero
/* 9C7E8C 80242AAC 0C019D80 */  jal       guMtxCatF
/* 9C7E90 80242AB0 00A0302D */   daddu    $a2, $a1, $zero
/* 9C7E94 80242AB4 96220000 */  lhu       $v0, ($s1)
/* 9C7E98 80242AB8 34421400 */  ori       $v0, $v0, 0x1400
/* 9C7E9C 80242ABC 08090ACF */  j         .L80242B3C
/* 9C7EA0 80242AC0 A6220000 */   sh       $v0, ($s1)
.L80242AC4:
/* 9C7EA4 80242AC4 4480A000 */  mtc1      $zero, $f20
/* 9C7EA8 80242AC8 4406B000 */  mfc1      $a2, $f22
/* 9C7EAC 80242ACC 4405A000 */  mfc1      $a1, $f20
/* 9C7EB0 80242AD0 4407A000 */  mfc1      $a3, $f20
/* 9C7EB4 80242AD4 0C019E40 */  jal       guTranslateF
/* 9C7EB8 80242AD8 27A40010 */   addiu    $a0, $sp, 0x10
/* 9C7EBC 80242ADC 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7EC0 80242AE0 26300058 */  addiu     $s0, $s1, 0x58
/* 9C7EC4 80242AE4 0200282D */  daddu     $a1, $s0, $zero
/* 9C7EC8 80242AE8 0C019D80 */  jal       guMtxCatF
/* 9C7ECC 80242AEC 0200302D */   daddu    $a2, $s0, $zero
/* 9C7ED0 80242AF0 4405E000 */  mfc1      $a1, $f28
/* 9C7ED4 80242AF4 4406D000 */  mfc1      $a2, $f26
/* 9C7ED8 80242AF8 4407C000 */  mfc1      $a3, $f24
/* 9C7EDC 80242AFC 0C090A4C */  jal       func_80242930_9C7D10
/* 9C7EE0 80242B00 27A40010 */   addiu    $a0, $sp, 0x10
/* 9C7EE4 80242B04 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7EE8 80242B08 0200282D */  daddu     $a1, $s0, $zero
/* 9C7EEC 80242B0C 0C019D80 */  jal       guMtxCatF
/* 9C7EF0 80242B10 0200302D */   daddu    $a2, $s0, $zero
/* 9C7EF4 80242B14 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7EF8 80242B18 4600B587 */  neg.s     $f22, $f22
/* 9C7EFC 80242B1C 4405A000 */  mfc1      $a1, $f20
/* 9C7F00 80242B20 4406B000 */  mfc1      $a2, $f22
/* 9C7F04 80242B24 0C019E40 */  jal       guTranslateF
/* 9C7F08 80242B28 00A0382D */   daddu    $a3, $a1, $zero
/* 9C7F0C 80242B2C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9C7F10 80242B30 0200282D */  daddu     $a1, $s0, $zero
/* 9C7F14 80242B34 0C019D80 */  jal       guMtxCatF
/* 9C7F18 80242B38 00A0302D */   daddu    $a2, $a1, $zero
.L80242B3C:
/* 9C7F1C 80242B3C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 9C7F20 80242B40 8FB20058 */  lw        $s2, 0x58($sp)
/* 9C7F24 80242B44 8FB10054 */  lw        $s1, 0x54($sp)
/* 9C7F28 80242B48 8FB00050 */  lw        $s0, 0x50($sp)
/* 9C7F2C 80242B4C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 9C7F30 80242B50 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 9C7F34 80242B54 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 9C7F38 80242B58 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 9C7F3C 80242B5C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 9C7F40 80242B60 24020002 */  addiu     $v0, $zero, 2
/* 9C7F44 80242B64 03E00008 */  jr        $ra
/* 9C7F48 80242B68 27BD0088 */   addiu    $sp, $sp, 0x88
/* 9C7F4C 80242B6C 00000000 */  nop       
