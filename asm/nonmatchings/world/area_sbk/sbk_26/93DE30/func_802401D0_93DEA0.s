.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D0_93DEA0
/* 93DEA0 802401D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 93DEA4 802401D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 93DEA8 802401D8 0080882D */  daddu     $s1, $a0, $zero
/* 93DEAC 802401DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 93DEB0 802401E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 93DEB4 802401E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 93DEB8 802401E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 93DEBC 802401EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 93DEC0 802401F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 93DEC4 802401F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 93DEC8 802401F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 93DECC 802401FC 8E30000C */  lw        $s0, 0xc($s1)
/* 93DED0 80240200 8E050000 */  lw        $a1, ($s0)
/* 93DED4 80240204 0C0B1EAF */  jal       get_variable
/* 93DED8 80240208 26100004 */   addiu    $s0, $s0, 4
/* 93DEDC 8024020C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 93DEE0 80240210 0040202D */   daddu    $a0, $v0, $zero
/* 93DEE4 80240214 8E050000 */  lw        $a1, ($s0)
/* 93DEE8 80240218 26100004 */  addiu     $s0, $s0, 4
/* 93DEEC 8024021C 0220202D */  daddu     $a0, $s1, $zero
/* 93DEF0 80240220 0C0B210B */  jal       get_float_variable
/* 93DEF4 80240224 0040902D */   daddu    $s2, $v0, $zero
/* 93DEF8 80240228 8E050000 */  lw        $a1, ($s0)
/* 93DEFC 8024022C 26100004 */  addiu     $s0, $s0, 4
/* 93DF00 80240230 0220202D */  daddu     $a0, $s1, $zero
/* 93DF04 80240234 0C0B210B */  jal       get_float_variable
/* 93DF08 80240238 46000706 */   mov.s    $f28, $f0
/* 93DF0C 8024023C 8E050000 */  lw        $a1, ($s0)
/* 93DF10 80240240 26100004 */  addiu     $s0, $s0, 4
/* 93DF14 80240244 0220202D */  daddu     $a0, $s1, $zero
/* 93DF18 80240248 0C0B210B */  jal       get_float_variable
/* 93DF1C 8024024C 46000686 */   mov.s    $f26, $f0
/* 93DF20 80240250 0220202D */  daddu     $a0, $s1, $zero
/* 93DF24 80240254 8E050000 */  lw        $a1, ($s0)
/* 93DF28 80240258 0C0B210B */  jal       get_float_variable
/* 93DF2C 8024025C 46000586 */   mov.s    $f22, $f0
/* 93DF30 80240260 0240202D */  daddu     $a0, $s2, $zero
/* 93DF34 80240264 0C046B4C */  jal       get_model_from_list_index
/* 93DF38 80240268 46000606 */   mov.s    $f24, $f0
/* 93DF3C 8024026C 0040882D */  daddu     $s1, $v0, $zero
/* 93DF40 80240270 96220000 */  lhu       $v0, ($s1)
/* 93DF44 80240274 30420400 */  andi      $v0, $v0, 0x400
/* 93DF48 80240278 1440001E */  bnez      $v0, .L802402F4
/* 93DF4C 8024027C 26300058 */   addiu    $s0, $s1, 0x58
/* 93DF50 80240280 4480A000 */  mtc1      $zero, $f20
/* 93DF54 80240284 4406B000 */  mfc1      $a2, $f22
/* 93DF58 80240288 4405A000 */  mfc1      $a1, $f20
/* 93DF5C 8024028C 4407A000 */  mfc1      $a3, $f20
/* 93DF60 80240290 0C019E40 */  jal       guTranslateF
/* 93DF64 80240294 0200202D */   daddu    $a0, $s0, $zero
/* 93DF68 80240298 4405E000 */  mfc1      $a1, $f28
/* 93DF6C 8024029C 4406D000 */  mfc1      $a2, $f26
/* 93DF70 802402A0 4407C000 */  mfc1      $a3, $f24
/* 93DF74 802402A4 0C090058 */  jal       func_80240160_93DE30
/* 93DF78 802402A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 93DF7C 802402AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 93DF80 802402B0 0200282D */  daddu     $a1, $s0, $zero
/* 93DF84 802402B4 0C019D80 */  jal       guMtxCatF
/* 93DF88 802402B8 0200302D */   daddu    $a2, $s0, $zero
/* 93DF8C 802402BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 93DF90 802402C0 4600B587 */  neg.s     $f22, $f22
/* 93DF94 802402C4 4405A000 */  mfc1      $a1, $f20
/* 93DF98 802402C8 4406B000 */  mfc1      $a2, $f22
/* 93DF9C 802402CC 0C019E40 */  jal       guTranslateF
/* 93DFA0 802402D0 00A0382D */   daddu    $a3, $a1, $zero
/* 93DFA4 802402D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 93DFA8 802402D8 0200282D */  daddu     $a1, $s0, $zero
/* 93DFAC 802402DC 0C019D80 */  jal       guMtxCatF
/* 93DFB0 802402E0 00A0302D */   daddu    $a2, $a1, $zero
/* 93DFB4 802402E4 96220000 */  lhu       $v0, ($s1)
/* 93DFB8 802402E8 34421400 */  ori       $v0, $v0, 0x1400
/* 93DFBC 802402EC 080900DB */  j         .L8024036C
/* 93DFC0 802402F0 A6220000 */   sh       $v0, ($s1)
.L802402F4:
/* 93DFC4 802402F4 4480A000 */  mtc1      $zero, $f20
/* 93DFC8 802402F8 4406B000 */  mfc1      $a2, $f22
/* 93DFCC 802402FC 4405A000 */  mfc1      $a1, $f20
/* 93DFD0 80240300 4407A000 */  mfc1      $a3, $f20
/* 93DFD4 80240304 0C019E40 */  jal       guTranslateF
/* 93DFD8 80240308 27A40010 */   addiu    $a0, $sp, 0x10
/* 93DFDC 8024030C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93DFE0 80240310 26300058 */  addiu     $s0, $s1, 0x58
/* 93DFE4 80240314 0200282D */  daddu     $a1, $s0, $zero
/* 93DFE8 80240318 0C019D80 */  jal       guMtxCatF
/* 93DFEC 8024031C 0200302D */   daddu    $a2, $s0, $zero
/* 93DFF0 80240320 4405E000 */  mfc1      $a1, $f28
/* 93DFF4 80240324 4406D000 */  mfc1      $a2, $f26
/* 93DFF8 80240328 4407C000 */  mfc1      $a3, $f24
/* 93DFFC 8024032C 0C090058 */  jal       func_80240160_93DE30
/* 93E000 80240330 27A40010 */   addiu    $a0, $sp, 0x10
/* 93E004 80240334 27A40010 */  addiu     $a0, $sp, 0x10
/* 93E008 80240338 0200282D */  daddu     $a1, $s0, $zero
/* 93E00C 8024033C 0C019D80 */  jal       guMtxCatF
/* 93E010 80240340 0200302D */   daddu    $a2, $s0, $zero
/* 93E014 80240344 27A40010 */  addiu     $a0, $sp, 0x10
/* 93E018 80240348 4600B587 */  neg.s     $f22, $f22
/* 93E01C 8024034C 4405A000 */  mfc1      $a1, $f20
/* 93E020 80240350 4406B000 */  mfc1      $a2, $f22
/* 93E024 80240354 0C019E40 */  jal       guTranslateF
/* 93E028 80240358 00A0382D */   daddu    $a3, $a1, $zero
/* 93E02C 8024035C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93E030 80240360 0200282D */  daddu     $a1, $s0, $zero
/* 93E034 80240364 0C019D80 */  jal       guMtxCatF
/* 93E038 80240368 00A0302D */   daddu    $a2, $a1, $zero
.L8024036C:
/* 93E03C 8024036C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 93E040 80240370 8FB20058 */  lw        $s2, 0x58($sp)
/* 93E044 80240374 8FB10054 */  lw        $s1, 0x54($sp)
/* 93E048 80240378 8FB00050 */  lw        $s0, 0x50($sp)
/* 93E04C 8024037C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 93E050 80240380 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 93E054 80240384 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 93E058 80240388 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 93E05C 8024038C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 93E060 80240390 24020002 */  addiu     $v0, $zero, 2
/* 93E064 80240394 03E00008 */  jr        $ra
/* 93E068 80240398 27BD0088 */   addiu    $sp, $sp, 0x88
/* 93E06C 8024039C 00000000 */  nop       
