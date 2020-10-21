.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D0_94EB70
/* 94EB70 802401D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 94EB74 802401D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 94EB78 802401D8 0080882D */  daddu     $s1, $a0, $zero
/* 94EB7C 802401DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 94EB80 802401E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 94EB84 802401E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 94EB88 802401E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 94EB8C 802401EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 94EB90 802401F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 94EB94 802401F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 94EB98 802401F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 94EB9C 802401FC 8E30000C */  lw        $s0, 0xc($s1)
/* 94EBA0 80240200 8E050000 */  lw        $a1, ($s0)
/* 94EBA4 80240204 0C0B1EAF */  jal       get_variable
/* 94EBA8 80240208 26100004 */   addiu    $s0, $s0, 4
/* 94EBAC 8024020C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 94EBB0 80240210 0040202D */   daddu    $a0, $v0, $zero
/* 94EBB4 80240214 8E050000 */  lw        $a1, ($s0)
/* 94EBB8 80240218 26100004 */  addiu     $s0, $s0, 4
/* 94EBBC 8024021C 0220202D */  daddu     $a0, $s1, $zero
/* 94EBC0 80240220 0C0B210B */  jal       get_float_variable
/* 94EBC4 80240224 0040902D */   daddu    $s2, $v0, $zero
/* 94EBC8 80240228 8E050000 */  lw        $a1, ($s0)
/* 94EBCC 8024022C 26100004 */  addiu     $s0, $s0, 4
/* 94EBD0 80240230 0220202D */  daddu     $a0, $s1, $zero
/* 94EBD4 80240234 0C0B210B */  jal       get_float_variable
/* 94EBD8 80240238 46000706 */   mov.s    $f28, $f0
/* 94EBDC 8024023C 8E050000 */  lw        $a1, ($s0)
/* 94EBE0 80240240 26100004 */  addiu     $s0, $s0, 4
/* 94EBE4 80240244 0220202D */  daddu     $a0, $s1, $zero
/* 94EBE8 80240248 0C0B210B */  jal       get_float_variable
/* 94EBEC 8024024C 46000686 */   mov.s    $f26, $f0
/* 94EBF0 80240250 0220202D */  daddu     $a0, $s1, $zero
/* 94EBF4 80240254 8E050000 */  lw        $a1, ($s0)
/* 94EBF8 80240258 0C0B210B */  jal       get_float_variable
/* 94EBFC 8024025C 46000586 */   mov.s    $f22, $f0
/* 94EC00 80240260 0240202D */  daddu     $a0, $s2, $zero
/* 94EC04 80240264 0C046B4C */  jal       get_model_from_list_index
/* 94EC08 80240268 46000606 */   mov.s    $f24, $f0
/* 94EC0C 8024026C 0040882D */  daddu     $s1, $v0, $zero
/* 94EC10 80240270 96220000 */  lhu       $v0, ($s1)
/* 94EC14 80240274 30420400 */  andi      $v0, $v0, 0x400
/* 94EC18 80240278 1440001E */  bnez      $v0, .L802402F4
/* 94EC1C 8024027C 26300058 */   addiu    $s0, $s1, 0x58
/* 94EC20 80240280 4480A000 */  mtc1      $zero, $f20
/* 94EC24 80240284 4406B000 */  mfc1      $a2, $f22
/* 94EC28 80240288 4405A000 */  mfc1      $a1, $f20
/* 94EC2C 8024028C 4407A000 */  mfc1      $a3, $f20
/* 94EC30 80240290 0C019E40 */  jal       guTranslateF
/* 94EC34 80240294 0200202D */   daddu    $a0, $s0, $zero
/* 94EC38 80240298 4405E000 */  mfc1      $a1, $f28
/* 94EC3C 8024029C 4406D000 */  mfc1      $a2, $f26
/* 94EC40 802402A0 4407C000 */  mfc1      $a3, $f24
/* 94EC44 802402A4 0C090058 */  jal       func_80240160_94EB00
/* 94EC48 802402A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 94EC4C 802402AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 94EC50 802402B0 0200282D */  daddu     $a1, $s0, $zero
/* 94EC54 802402B4 0C019D80 */  jal       guMtxCatF
/* 94EC58 802402B8 0200302D */   daddu    $a2, $s0, $zero
/* 94EC5C 802402BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 94EC60 802402C0 4600B587 */  neg.s     $f22, $f22
/* 94EC64 802402C4 4405A000 */  mfc1      $a1, $f20
/* 94EC68 802402C8 4406B000 */  mfc1      $a2, $f22
/* 94EC6C 802402CC 0C019E40 */  jal       guTranslateF
/* 94EC70 802402D0 00A0382D */   daddu    $a3, $a1, $zero
/* 94EC74 802402D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 94EC78 802402D8 0200282D */  daddu     $a1, $s0, $zero
/* 94EC7C 802402DC 0C019D80 */  jal       guMtxCatF
/* 94EC80 802402E0 00A0302D */   daddu    $a2, $a1, $zero
/* 94EC84 802402E4 96220000 */  lhu       $v0, ($s1)
/* 94EC88 802402E8 34421400 */  ori       $v0, $v0, 0x1400
/* 94EC8C 802402EC 080900DB */  j         .L8024036C
/* 94EC90 802402F0 A6220000 */   sh       $v0, ($s1)
.L802402F4:
/* 94EC94 802402F4 4480A000 */  mtc1      $zero, $f20
/* 94EC98 802402F8 4406B000 */  mfc1      $a2, $f22
/* 94EC9C 802402FC 4405A000 */  mfc1      $a1, $f20
/* 94ECA0 80240300 4407A000 */  mfc1      $a3, $f20
/* 94ECA4 80240304 0C019E40 */  jal       guTranslateF
/* 94ECA8 80240308 27A40010 */   addiu    $a0, $sp, 0x10
/* 94ECAC 8024030C 27A40010 */  addiu     $a0, $sp, 0x10
/* 94ECB0 80240310 26300058 */  addiu     $s0, $s1, 0x58
/* 94ECB4 80240314 0200282D */  daddu     $a1, $s0, $zero
/* 94ECB8 80240318 0C019D80 */  jal       guMtxCatF
/* 94ECBC 8024031C 0200302D */   daddu    $a2, $s0, $zero
/* 94ECC0 80240320 4405E000 */  mfc1      $a1, $f28
/* 94ECC4 80240324 4406D000 */  mfc1      $a2, $f26
/* 94ECC8 80240328 4407C000 */  mfc1      $a3, $f24
/* 94ECCC 8024032C 0C090058 */  jal       func_80240160_94EB00
/* 94ECD0 80240330 27A40010 */   addiu    $a0, $sp, 0x10
/* 94ECD4 80240334 27A40010 */  addiu     $a0, $sp, 0x10
/* 94ECD8 80240338 0200282D */  daddu     $a1, $s0, $zero
/* 94ECDC 8024033C 0C019D80 */  jal       guMtxCatF
/* 94ECE0 80240340 0200302D */   daddu    $a2, $s0, $zero
/* 94ECE4 80240344 27A40010 */  addiu     $a0, $sp, 0x10
/* 94ECE8 80240348 4600B587 */  neg.s     $f22, $f22
/* 94ECEC 8024034C 4405A000 */  mfc1      $a1, $f20
/* 94ECF0 80240350 4406B000 */  mfc1      $a2, $f22
/* 94ECF4 80240354 0C019E40 */  jal       guTranslateF
/* 94ECF8 80240358 00A0382D */   daddu    $a3, $a1, $zero
/* 94ECFC 8024035C 27A40010 */  addiu     $a0, $sp, 0x10
/* 94ED00 80240360 0200282D */  daddu     $a1, $s0, $zero
/* 94ED04 80240364 0C019D80 */  jal       guMtxCatF
/* 94ED08 80240368 00A0302D */   daddu    $a2, $a1, $zero
.L8024036C:
/* 94ED0C 8024036C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 94ED10 80240370 8FB20058 */  lw        $s2, 0x58($sp)
/* 94ED14 80240374 8FB10054 */  lw        $s1, 0x54($sp)
/* 94ED18 80240378 8FB00050 */  lw        $s0, 0x50($sp)
/* 94ED1C 8024037C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 94ED20 80240380 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 94ED24 80240384 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 94ED28 80240388 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 94ED2C 8024038C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 94ED30 80240390 24020002 */  addiu     $v0, $zero, 2
/* 94ED34 80240394 03E00008 */  jr        $ra
/* 94ED38 80240398 27BD0088 */   addiu    $sp, $sp, 0x88
/* 94ED3C 8024039C 00000000 */  nop       
