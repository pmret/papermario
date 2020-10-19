.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802438F0_95EAF0
/* 95EAF0 802438F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 95EAF4 802438F4 AFB10054 */  sw        $s1, 0x54($sp)
/* 95EAF8 802438F8 0080882D */  daddu     $s1, $a0, $zero
/* 95EAFC 802438FC AFBF005C */  sw        $ra, 0x5c($sp)
/* 95EB00 80243900 AFB20058 */  sw        $s2, 0x58($sp)
/* 95EB04 80243904 AFB00050 */  sw        $s0, 0x50($sp)
/* 95EB08 80243908 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 95EB0C 8024390C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 95EB10 80243910 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 95EB14 80243914 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 95EB18 80243918 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 95EB1C 8024391C 8E30000C */  lw        $s0, 0xc($s1)
/* 95EB20 80243920 8E050000 */  lw        $a1, ($s0)
/* 95EB24 80243924 0C0B1EAF */  jal       get_variable
/* 95EB28 80243928 26100004 */   addiu    $s0, $s0, 4
/* 95EB2C 8024392C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 95EB30 80243930 0040202D */   daddu    $a0, $v0, $zero
/* 95EB34 80243934 8E050000 */  lw        $a1, ($s0)
/* 95EB38 80243938 26100004 */  addiu     $s0, $s0, 4
/* 95EB3C 8024393C 0220202D */  daddu     $a0, $s1, $zero
/* 95EB40 80243940 0C0B210B */  jal       get_float_variable
/* 95EB44 80243944 0040902D */   daddu    $s2, $v0, $zero
/* 95EB48 80243948 8E050000 */  lw        $a1, ($s0)
/* 95EB4C 8024394C 26100004 */  addiu     $s0, $s0, 4
/* 95EB50 80243950 0220202D */  daddu     $a0, $s1, $zero
/* 95EB54 80243954 0C0B210B */  jal       get_float_variable
/* 95EB58 80243958 46000706 */   mov.s    $f28, $f0
/* 95EB5C 8024395C 8E050000 */  lw        $a1, ($s0)
/* 95EB60 80243960 26100004 */  addiu     $s0, $s0, 4
/* 95EB64 80243964 0220202D */  daddu     $a0, $s1, $zero
/* 95EB68 80243968 0C0B210B */  jal       get_float_variable
/* 95EB6C 8024396C 46000686 */   mov.s    $f26, $f0
/* 95EB70 80243970 0220202D */  daddu     $a0, $s1, $zero
/* 95EB74 80243974 8E050000 */  lw        $a1, ($s0)
/* 95EB78 80243978 0C0B210B */  jal       get_float_variable
/* 95EB7C 8024397C 46000586 */   mov.s    $f22, $f0
/* 95EB80 80243980 0240202D */  daddu     $a0, $s2, $zero
/* 95EB84 80243984 0C046B4C */  jal       get_model_from_list_index
/* 95EB88 80243988 46000606 */   mov.s    $f24, $f0
/* 95EB8C 8024398C 0040882D */  daddu     $s1, $v0, $zero
/* 95EB90 80243990 96220000 */  lhu       $v0, ($s1)
/* 95EB94 80243994 30420400 */  andi      $v0, $v0, 0x400
/* 95EB98 80243998 1440001E */  bnez      $v0, .L80243A14
/* 95EB9C 8024399C 26300058 */   addiu    $s0, $s1, 0x58
/* 95EBA0 802439A0 4480A000 */  mtc1      $zero, $f20
/* 95EBA4 802439A4 4406B000 */  mfc1      $a2, $f22
/* 95EBA8 802439A8 4405A000 */  mfc1      $a1, $f20
/* 95EBAC 802439AC 4407A000 */  mfc1      $a3, $f20
/* 95EBB0 802439B0 0C019E40 */  jal       guTranslateF
/* 95EBB4 802439B4 0200202D */   daddu    $a0, $s0, $zero
/* 95EBB8 802439B8 4405E000 */  mfc1      $a1, $f28
/* 95EBBC 802439BC 4406D000 */  mfc1      $a2, $f26
/* 95EBC0 802439C0 4407C000 */  mfc1      $a3, $f24
/* 95EBC4 802439C4 0C090E20 */  jal       func_80243880
/* 95EBC8 802439C8 27A40010 */   addiu    $a0, $sp, 0x10
/* 95EBCC 802439CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EBD0 802439D0 0200282D */  daddu     $a1, $s0, $zero
/* 95EBD4 802439D4 0C019D80 */  jal       guMtxCatF
/* 95EBD8 802439D8 0200302D */   daddu    $a2, $s0, $zero
/* 95EBDC 802439DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EBE0 802439E0 4600B587 */  neg.s     $f22, $f22
/* 95EBE4 802439E4 4405A000 */  mfc1      $a1, $f20
/* 95EBE8 802439E8 4406B000 */  mfc1      $a2, $f22
/* 95EBEC 802439EC 0C019E40 */  jal       guTranslateF
/* 95EBF0 802439F0 00A0382D */   daddu    $a3, $a1, $zero
/* 95EBF4 802439F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EBF8 802439F8 0200282D */  daddu     $a1, $s0, $zero
/* 95EBFC 802439FC 0C019D80 */  jal       guMtxCatF
/* 95EC00 80243A00 00A0302D */   daddu    $a2, $a1, $zero
/* 95EC04 80243A04 96220000 */  lhu       $v0, ($s1)
/* 95EC08 80243A08 34421400 */  ori       $v0, $v0, 0x1400
/* 95EC0C 80243A0C 08090EA3 */  j         .L80243A8C
/* 95EC10 80243A10 A6220000 */   sh       $v0, ($s1)
.L80243A14:
/* 95EC14 80243A14 4480A000 */  mtc1      $zero, $f20
/* 95EC18 80243A18 4406B000 */  mfc1      $a2, $f22
/* 95EC1C 80243A1C 4405A000 */  mfc1      $a1, $f20
/* 95EC20 80243A20 4407A000 */  mfc1      $a3, $f20
/* 95EC24 80243A24 0C019E40 */  jal       guTranslateF
/* 95EC28 80243A28 27A40010 */   addiu    $a0, $sp, 0x10
/* 95EC2C 80243A2C 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EC30 80243A30 26300058 */  addiu     $s0, $s1, 0x58
/* 95EC34 80243A34 0200282D */  daddu     $a1, $s0, $zero
/* 95EC38 80243A38 0C019D80 */  jal       guMtxCatF
/* 95EC3C 80243A3C 0200302D */   daddu    $a2, $s0, $zero
/* 95EC40 80243A40 4405E000 */  mfc1      $a1, $f28
/* 95EC44 80243A44 4406D000 */  mfc1      $a2, $f26
/* 95EC48 80243A48 4407C000 */  mfc1      $a3, $f24
/* 95EC4C 80243A4C 0C090E20 */  jal       func_80243880
/* 95EC50 80243A50 27A40010 */   addiu    $a0, $sp, 0x10
/* 95EC54 80243A54 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EC58 80243A58 0200282D */  daddu     $a1, $s0, $zero
/* 95EC5C 80243A5C 0C019D80 */  jal       guMtxCatF
/* 95EC60 80243A60 0200302D */   daddu    $a2, $s0, $zero
/* 95EC64 80243A64 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EC68 80243A68 4600B587 */  neg.s     $f22, $f22
/* 95EC6C 80243A6C 4405A000 */  mfc1      $a1, $f20
/* 95EC70 80243A70 4406B000 */  mfc1      $a2, $f22
/* 95EC74 80243A74 0C019E40 */  jal       guTranslateF
/* 95EC78 80243A78 00A0382D */   daddu    $a3, $a1, $zero
/* 95EC7C 80243A7C 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EC80 80243A80 0200282D */  daddu     $a1, $s0, $zero
/* 95EC84 80243A84 0C019D80 */  jal       guMtxCatF
/* 95EC88 80243A88 00A0302D */   daddu    $a2, $a1, $zero
.L80243A8C:
/* 95EC8C 80243A8C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 95EC90 80243A90 8FB20058 */  lw        $s2, 0x58($sp)
/* 95EC94 80243A94 8FB10054 */  lw        $s1, 0x54($sp)
/* 95EC98 80243A98 8FB00050 */  lw        $s0, 0x50($sp)
/* 95EC9C 80243A9C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 95ECA0 80243AA0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 95ECA4 80243AA4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 95ECA8 80243AA8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 95ECAC 80243AAC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 95ECB0 80243AB0 24020002 */  addiu     $v0, $zero, 2
/* 95ECB4 80243AB4 03E00008 */  jr        $ra
/* 95ECB8 80243AB8 27BD0088 */   addiu    $sp, $sp, 0x88
/* 95ECBC 80243ABC 00000000 */  nop       
