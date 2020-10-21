.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241200_B29230
/* B29230 80241200 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B29234 80241204 AFB10054 */  sw        $s1, 0x54($sp)
/* B29238 80241208 0080882D */  daddu     $s1, $a0, $zero
/* B2923C 8024120C AFBF005C */  sw        $ra, 0x5c($sp)
/* B29240 80241210 AFB20058 */  sw        $s2, 0x58($sp)
/* B29244 80241214 AFB00050 */  sw        $s0, 0x50($sp)
/* B29248 80241218 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B2924C 8024121C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B29250 80241220 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B29254 80241224 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B29258 80241228 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B2925C 8024122C 8E30000C */  lw        $s0, 0xc($s1)
/* B29260 80241230 8E050000 */  lw        $a1, ($s0)
/* B29264 80241234 0C0B1EAF */  jal       get_variable
/* B29268 80241238 26100004 */   addiu    $s0, $s0, 4
/* B2926C 8024123C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B29270 80241240 0040202D */   daddu    $a0, $v0, $zero
/* B29274 80241244 8E050000 */  lw        $a1, ($s0)
/* B29278 80241248 26100004 */  addiu     $s0, $s0, 4
/* B2927C 8024124C 0220202D */  daddu     $a0, $s1, $zero
/* B29280 80241250 0C0B210B */  jal       get_float_variable
/* B29284 80241254 0040902D */   daddu    $s2, $v0, $zero
/* B29288 80241258 8E050000 */  lw        $a1, ($s0)
/* B2928C 8024125C 26100004 */  addiu     $s0, $s0, 4
/* B29290 80241260 0220202D */  daddu     $a0, $s1, $zero
/* B29294 80241264 0C0B210B */  jal       get_float_variable
/* B29298 80241268 46000706 */   mov.s    $f28, $f0
/* B2929C 8024126C 8E050000 */  lw        $a1, ($s0)
/* B292A0 80241270 26100004 */  addiu     $s0, $s0, 4
/* B292A4 80241274 0220202D */  daddu     $a0, $s1, $zero
/* B292A8 80241278 0C0B210B */  jal       get_float_variable
/* B292AC 8024127C 46000686 */   mov.s    $f26, $f0
/* B292B0 80241280 0220202D */  daddu     $a0, $s1, $zero
/* B292B4 80241284 8E050000 */  lw        $a1, ($s0)
/* B292B8 80241288 0C0B210B */  jal       get_float_variable
/* B292BC 8024128C 46000586 */   mov.s    $f22, $f0
/* B292C0 80241290 0240202D */  daddu     $a0, $s2, $zero
/* B292C4 80241294 0C046B4C */  jal       get_model_from_list_index
/* B292C8 80241298 46000606 */   mov.s    $f24, $f0
/* B292CC 8024129C 0040882D */  daddu     $s1, $v0, $zero
/* B292D0 802412A0 96220000 */  lhu       $v0, ($s1)
/* B292D4 802412A4 30420400 */  andi      $v0, $v0, 0x400
/* B292D8 802412A8 1440001E */  bnez      $v0, .L80241324
/* B292DC 802412AC 26300058 */   addiu    $s0, $s1, 0x58
/* B292E0 802412B0 4480A000 */  mtc1      $zero, $f20
/* B292E4 802412B4 4406B000 */  mfc1      $a2, $f22
/* B292E8 802412B8 4405A000 */  mfc1      $a1, $f20
/* B292EC 802412BC 4407A000 */  mfc1      $a3, $f20
/* B292F0 802412C0 0C019E40 */  jal       guTranslateF
/* B292F4 802412C4 0200202D */   daddu    $a0, $s0, $zero
/* B292F8 802412C8 4405E000 */  mfc1      $a1, $f28
/* B292FC 802412CC 4406D000 */  mfc1      $a2, $f26
/* B29300 802412D0 4407C000 */  mfc1      $a3, $f24
/* B29304 802412D4 0C090464 */  jal       func_80241190_B291C0
/* B29308 802412D8 27A40010 */   addiu    $a0, $sp, 0x10
/* B2930C 802412DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B29310 802412E0 0200282D */  daddu     $a1, $s0, $zero
/* B29314 802412E4 0C019D80 */  jal       guMtxCatF
/* B29318 802412E8 0200302D */   daddu    $a2, $s0, $zero
/* B2931C 802412EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B29320 802412F0 4600B587 */  neg.s     $f22, $f22
/* B29324 802412F4 4405A000 */  mfc1      $a1, $f20
/* B29328 802412F8 4406B000 */  mfc1      $a2, $f22
/* B2932C 802412FC 0C019E40 */  jal       guTranslateF
/* B29330 80241300 00A0382D */   daddu    $a3, $a1, $zero
/* B29334 80241304 27A40010 */  addiu     $a0, $sp, 0x10
/* B29338 80241308 0200282D */  daddu     $a1, $s0, $zero
/* B2933C 8024130C 0C019D80 */  jal       guMtxCatF
/* B29340 80241310 00A0302D */   daddu    $a2, $a1, $zero
/* B29344 80241314 96220000 */  lhu       $v0, ($s1)
/* B29348 80241318 34421400 */  ori       $v0, $v0, 0x1400
/* B2934C 8024131C 080904E7 */  j         .L8024139C
/* B29350 80241320 A6220000 */   sh       $v0, ($s1)
.L80241324:
/* B29354 80241324 4480A000 */  mtc1      $zero, $f20
/* B29358 80241328 4406B000 */  mfc1      $a2, $f22
/* B2935C 8024132C 4405A000 */  mfc1      $a1, $f20
/* B29360 80241330 4407A000 */  mfc1      $a3, $f20
/* B29364 80241334 0C019E40 */  jal       guTranslateF
/* B29368 80241338 27A40010 */   addiu    $a0, $sp, 0x10
/* B2936C 8024133C 27A40010 */  addiu     $a0, $sp, 0x10
/* B29370 80241340 26300058 */  addiu     $s0, $s1, 0x58
/* B29374 80241344 0200282D */  daddu     $a1, $s0, $zero
/* B29378 80241348 0C019D80 */  jal       guMtxCatF
/* B2937C 8024134C 0200302D */   daddu    $a2, $s0, $zero
/* B29380 80241350 4405E000 */  mfc1      $a1, $f28
/* B29384 80241354 4406D000 */  mfc1      $a2, $f26
/* B29388 80241358 4407C000 */  mfc1      $a3, $f24
/* B2938C 8024135C 0C090464 */  jal       func_80241190_B291C0
/* B29390 80241360 27A40010 */   addiu    $a0, $sp, 0x10
/* B29394 80241364 27A40010 */  addiu     $a0, $sp, 0x10
/* B29398 80241368 0200282D */  daddu     $a1, $s0, $zero
/* B2939C 8024136C 0C019D80 */  jal       guMtxCatF
/* B293A0 80241370 0200302D */   daddu    $a2, $s0, $zero
/* B293A4 80241374 27A40010 */  addiu     $a0, $sp, 0x10
/* B293A8 80241378 4600B587 */  neg.s     $f22, $f22
/* B293AC 8024137C 4405A000 */  mfc1      $a1, $f20
/* B293B0 80241380 4406B000 */  mfc1      $a2, $f22
/* B293B4 80241384 0C019E40 */  jal       guTranslateF
/* B293B8 80241388 00A0382D */   daddu    $a3, $a1, $zero
/* B293BC 8024138C 27A40010 */  addiu     $a0, $sp, 0x10
/* B293C0 80241390 0200282D */  daddu     $a1, $s0, $zero
/* B293C4 80241394 0C019D80 */  jal       guMtxCatF
/* B293C8 80241398 00A0302D */   daddu    $a2, $a1, $zero
.L8024139C:
/* B293CC 8024139C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B293D0 802413A0 8FB20058 */  lw        $s2, 0x58($sp)
/* B293D4 802413A4 8FB10054 */  lw        $s1, 0x54($sp)
/* B293D8 802413A8 8FB00050 */  lw        $s0, 0x50($sp)
/* B293DC 802413AC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B293E0 802413B0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B293E4 802413B4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B293E8 802413B8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B293EC 802413BC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B293F0 802413C0 24020002 */  addiu     $v0, $zero, 2
/* B293F4 802413C4 03E00008 */  jr        $ra
/* B293F8 802413C8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B293FC 802413CC 00000000 */  nop       
