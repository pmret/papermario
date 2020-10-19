.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412A0_CBA4A0
/* CBA4A0 802412A0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CBA4A4 802412A4 AFB10054 */  sw        $s1, 0x54($sp)
/* CBA4A8 802412A8 0080882D */  daddu     $s1, $a0, $zero
/* CBA4AC 802412AC AFBF005C */  sw        $ra, 0x5c($sp)
/* CBA4B0 802412B0 AFB20058 */  sw        $s2, 0x58($sp)
/* CBA4B4 802412B4 AFB00050 */  sw        $s0, 0x50($sp)
/* CBA4B8 802412B8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CBA4BC 802412BC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CBA4C0 802412C0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CBA4C4 802412C4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CBA4C8 802412C8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CBA4CC 802412CC 8E30000C */  lw        $s0, 0xc($s1)
/* CBA4D0 802412D0 8E050000 */  lw        $a1, ($s0)
/* CBA4D4 802412D4 0C0B1EAF */  jal       get_variable
/* CBA4D8 802412D8 26100004 */   addiu    $s0, $s0, 4
/* CBA4DC 802412DC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CBA4E0 802412E0 0040202D */   daddu    $a0, $v0, $zero
/* CBA4E4 802412E4 8E050000 */  lw        $a1, ($s0)
/* CBA4E8 802412E8 26100004 */  addiu     $s0, $s0, 4
/* CBA4EC 802412EC 0220202D */  daddu     $a0, $s1, $zero
/* CBA4F0 802412F0 0C0B210B */  jal       get_float_variable
/* CBA4F4 802412F4 0040902D */   daddu    $s2, $v0, $zero
/* CBA4F8 802412F8 8E050000 */  lw        $a1, ($s0)
/* CBA4FC 802412FC 26100004 */  addiu     $s0, $s0, 4
/* CBA500 80241300 0220202D */  daddu     $a0, $s1, $zero
/* CBA504 80241304 0C0B210B */  jal       get_float_variable
/* CBA508 80241308 46000706 */   mov.s    $f28, $f0
/* CBA50C 8024130C 8E050000 */  lw        $a1, ($s0)
/* CBA510 80241310 26100004 */  addiu     $s0, $s0, 4
/* CBA514 80241314 0220202D */  daddu     $a0, $s1, $zero
/* CBA518 80241318 0C0B210B */  jal       get_float_variable
/* CBA51C 8024131C 46000686 */   mov.s    $f26, $f0
/* CBA520 80241320 0220202D */  daddu     $a0, $s1, $zero
/* CBA524 80241324 8E050000 */  lw        $a1, ($s0)
/* CBA528 80241328 0C0B210B */  jal       get_float_variable
/* CBA52C 8024132C 46000586 */   mov.s    $f22, $f0
/* CBA530 80241330 0240202D */  daddu     $a0, $s2, $zero
/* CBA534 80241334 0C046B4C */  jal       get_model_from_list_index
/* CBA538 80241338 46000606 */   mov.s    $f24, $f0
/* CBA53C 8024133C 0040882D */  daddu     $s1, $v0, $zero
/* CBA540 80241340 96220000 */  lhu       $v0, ($s1)
/* CBA544 80241344 30420400 */  andi      $v0, $v0, 0x400
/* CBA548 80241348 1440001E */  bnez      $v0, .L802413C4
/* CBA54C 8024134C 26300058 */   addiu    $s0, $s1, 0x58
/* CBA550 80241350 4480A000 */  mtc1      $zero, $f20
/* CBA554 80241354 4406B000 */  mfc1      $a2, $f22
/* CBA558 80241358 4405A000 */  mfc1      $a1, $f20
/* CBA55C 8024135C 4407A000 */  mfc1      $a3, $f20
/* CBA560 80241360 0C019E40 */  jal       guTranslateF
/* CBA564 80241364 0200202D */   daddu    $a0, $s0, $zero
/* CBA568 80241368 4405E000 */  mfc1      $a1, $f28
/* CBA56C 8024136C 4406D000 */  mfc1      $a2, $f26
/* CBA570 80241370 4407C000 */  mfc1      $a3, $f24
/* CBA574 80241374 0C09048C */  jal       func_80241230
/* CBA578 80241378 27A40010 */   addiu    $a0, $sp, 0x10
/* CBA57C 8024137C 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA580 80241380 0200282D */  daddu     $a1, $s0, $zero
/* CBA584 80241384 0C019D80 */  jal       guMtxCatF
/* CBA588 80241388 0200302D */   daddu    $a2, $s0, $zero
/* CBA58C 8024138C 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA590 80241390 4600B587 */  neg.s     $f22, $f22
/* CBA594 80241394 4405A000 */  mfc1      $a1, $f20
/* CBA598 80241398 4406B000 */  mfc1      $a2, $f22
/* CBA59C 8024139C 0C019E40 */  jal       guTranslateF
/* CBA5A0 802413A0 00A0382D */   daddu    $a3, $a1, $zero
/* CBA5A4 802413A4 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA5A8 802413A8 0200282D */  daddu     $a1, $s0, $zero
/* CBA5AC 802413AC 0C019D80 */  jal       guMtxCatF
/* CBA5B0 802413B0 00A0302D */   daddu    $a2, $a1, $zero
/* CBA5B4 802413B4 96220000 */  lhu       $v0, ($s1)
/* CBA5B8 802413B8 34421400 */  ori       $v0, $v0, 0x1400
/* CBA5BC 802413BC 0809050F */  j         .L8024143C
/* CBA5C0 802413C0 A6220000 */   sh       $v0, ($s1)
.L802413C4:
/* CBA5C4 802413C4 4480A000 */  mtc1      $zero, $f20
/* CBA5C8 802413C8 4406B000 */  mfc1      $a2, $f22
/* CBA5CC 802413CC 4405A000 */  mfc1      $a1, $f20
/* CBA5D0 802413D0 4407A000 */  mfc1      $a3, $f20
/* CBA5D4 802413D4 0C019E40 */  jal       guTranslateF
/* CBA5D8 802413D8 27A40010 */   addiu    $a0, $sp, 0x10
/* CBA5DC 802413DC 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA5E0 802413E0 26300058 */  addiu     $s0, $s1, 0x58
/* CBA5E4 802413E4 0200282D */  daddu     $a1, $s0, $zero
/* CBA5E8 802413E8 0C019D80 */  jal       guMtxCatF
/* CBA5EC 802413EC 0200302D */   daddu    $a2, $s0, $zero
/* CBA5F0 802413F0 4405E000 */  mfc1      $a1, $f28
/* CBA5F4 802413F4 4406D000 */  mfc1      $a2, $f26
/* CBA5F8 802413F8 4407C000 */  mfc1      $a3, $f24
/* CBA5FC 802413FC 0C09048C */  jal       func_80241230
/* CBA600 80241400 27A40010 */   addiu    $a0, $sp, 0x10
/* CBA604 80241404 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA608 80241408 0200282D */  daddu     $a1, $s0, $zero
/* CBA60C 8024140C 0C019D80 */  jal       guMtxCatF
/* CBA610 80241410 0200302D */   daddu    $a2, $s0, $zero
/* CBA614 80241414 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA618 80241418 4600B587 */  neg.s     $f22, $f22
/* CBA61C 8024141C 4405A000 */  mfc1      $a1, $f20
/* CBA620 80241420 4406B000 */  mfc1      $a2, $f22
/* CBA624 80241424 0C019E40 */  jal       guTranslateF
/* CBA628 80241428 00A0382D */   daddu    $a3, $a1, $zero
/* CBA62C 8024142C 27A40010 */  addiu     $a0, $sp, 0x10
/* CBA630 80241430 0200282D */  daddu     $a1, $s0, $zero
/* CBA634 80241434 0C019D80 */  jal       guMtxCatF
/* CBA638 80241438 00A0302D */   daddu    $a2, $a1, $zero
.L8024143C:
/* CBA63C 8024143C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CBA640 80241440 8FB20058 */  lw        $s2, 0x58($sp)
/* CBA644 80241444 8FB10054 */  lw        $s1, 0x54($sp)
/* CBA648 80241448 8FB00050 */  lw        $s0, 0x50($sp)
/* CBA64C 8024144C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CBA650 80241450 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CBA654 80241454 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CBA658 80241458 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CBA65C 8024145C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CBA660 80241460 24020002 */  addiu     $v0, $zero, 2
/* CBA664 80241464 03E00008 */  jr        $ra
/* CBA668 80241468 27BD0088 */   addiu    $sp, $sp, 0x88
/* CBA66C 8024146C 00000000 */  nop       
