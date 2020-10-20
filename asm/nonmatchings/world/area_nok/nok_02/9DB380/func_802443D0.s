.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802443D0
/* 9DB3F0 802443D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 9DB3F4 802443D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 9DB3F8 802443D8 0080882D */  daddu     $s1, $a0, $zero
/* 9DB3FC 802443DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 9DB400 802443E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 9DB404 802443E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 9DB408 802443E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 9DB40C 802443EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 9DB410 802443F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 9DB414 802443F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 9DB418 802443F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 9DB41C 802443FC 8E30000C */  lw        $s0, 0xc($s1)
/* 9DB420 80244400 8E050000 */  lw        $a1, ($s0)
/* 9DB424 80244404 0C0B1EAF */  jal       get_variable
/* 9DB428 80244408 26100004 */   addiu    $s0, $s0, 4
/* 9DB42C 8024440C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 9DB430 80244410 0040202D */   daddu    $a0, $v0, $zero
/* 9DB434 80244414 8E050000 */  lw        $a1, ($s0)
/* 9DB438 80244418 26100004 */  addiu     $s0, $s0, 4
/* 9DB43C 8024441C 0220202D */  daddu     $a0, $s1, $zero
/* 9DB440 80244420 0C0B210B */  jal       get_float_variable
/* 9DB444 80244424 0040902D */   daddu    $s2, $v0, $zero
/* 9DB448 80244428 8E050000 */  lw        $a1, ($s0)
/* 9DB44C 8024442C 26100004 */  addiu     $s0, $s0, 4
/* 9DB450 80244430 0220202D */  daddu     $a0, $s1, $zero
/* 9DB454 80244434 0C0B210B */  jal       get_float_variable
/* 9DB458 80244438 46000706 */   mov.s    $f28, $f0
/* 9DB45C 8024443C 8E050000 */  lw        $a1, ($s0)
/* 9DB460 80244440 26100004 */  addiu     $s0, $s0, 4
/* 9DB464 80244444 0220202D */  daddu     $a0, $s1, $zero
/* 9DB468 80244448 0C0B210B */  jal       get_float_variable
/* 9DB46C 8024444C 46000686 */   mov.s    $f26, $f0
/* 9DB470 80244450 0220202D */  daddu     $a0, $s1, $zero
/* 9DB474 80244454 8E050000 */  lw        $a1, ($s0)
/* 9DB478 80244458 0C0B210B */  jal       get_float_variable
/* 9DB47C 8024445C 46000586 */   mov.s    $f22, $f0
/* 9DB480 80244460 0240202D */  daddu     $a0, $s2, $zero
/* 9DB484 80244464 0C046B4C */  jal       get_model_from_list_index
/* 9DB488 80244468 46000606 */   mov.s    $f24, $f0
/* 9DB48C 8024446C 0040882D */  daddu     $s1, $v0, $zero
/* 9DB490 80244470 96220000 */  lhu       $v0, ($s1)
/* 9DB494 80244474 30420400 */  andi      $v0, $v0, 0x400
/* 9DB498 80244478 1440001E */  bnez      $v0, .L802444F4
/* 9DB49C 8024447C 26300058 */   addiu    $s0, $s1, 0x58
/* 9DB4A0 80244480 4480A000 */  mtc1      $zero, $f20
/* 9DB4A4 80244484 4406B000 */  mfc1      $a2, $f22
/* 9DB4A8 80244488 4405A000 */  mfc1      $a1, $f20
/* 9DB4AC 8024448C 4407A000 */  mfc1      $a3, $f20
/* 9DB4B0 80244490 0C019E40 */  jal       guTranslateF
/* 9DB4B4 80244494 0200202D */   daddu    $a0, $s0, $zero
/* 9DB4B8 80244498 4405E000 */  mfc1      $a1, $f28
/* 9DB4BC 8024449C 4406D000 */  mfc1      $a2, $f26
/* 9DB4C0 802444A0 4407C000 */  mfc1      $a3, $f24
/* 9DB4C4 802444A4 0C0910D8 */  jal       func_80244360
/* 9DB4C8 802444A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 9DB4CC 802444AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB4D0 802444B0 0200282D */  daddu     $a1, $s0, $zero
/* 9DB4D4 802444B4 0C019D80 */  jal       guMtxCatF
/* 9DB4D8 802444B8 0200302D */   daddu    $a2, $s0, $zero
/* 9DB4DC 802444BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB4E0 802444C0 4600B587 */  neg.s     $f22, $f22
/* 9DB4E4 802444C4 4405A000 */  mfc1      $a1, $f20
/* 9DB4E8 802444C8 4406B000 */  mfc1      $a2, $f22
/* 9DB4EC 802444CC 0C019E40 */  jal       guTranslateF
/* 9DB4F0 802444D0 00A0382D */   daddu    $a3, $a1, $zero
/* 9DB4F4 802444D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB4F8 802444D8 0200282D */  daddu     $a1, $s0, $zero
/* 9DB4FC 802444DC 0C019D80 */  jal       guMtxCatF
/* 9DB500 802444E0 00A0302D */   daddu    $a2, $a1, $zero
/* 9DB504 802444E4 96220000 */  lhu       $v0, ($s1)
/* 9DB508 802444E8 34421400 */  ori       $v0, $v0, 0x1400
/* 9DB50C 802444EC 0809115B */  j         .L8024456C
/* 9DB510 802444F0 A6220000 */   sh       $v0, ($s1)
.L802444F4:
/* 9DB514 802444F4 4480A000 */  mtc1      $zero, $f20
/* 9DB518 802444F8 4406B000 */  mfc1      $a2, $f22
/* 9DB51C 802444FC 4405A000 */  mfc1      $a1, $f20
/* 9DB520 80244500 4407A000 */  mfc1      $a3, $f20
/* 9DB524 80244504 0C019E40 */  jal       guTranslateF
/* 9DB528 80244508 27A40010 */   addiu    $a0, $sp, 0x10
/* 9DB52C 8024450C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB530 80244510 26300058 */  addiu     $s0, $s1, 0x58
/* 9DB534 80244514 0200282D */  daddu     $a1, $s0, $zero
/* 9DB538 80244518 0C019D80 */  jal       guMtxCatF
/* 9DB53C 8024451C 0200302D */   daddu    $a2, $s0, $zero
/* 9DB540 80244520 4405E000 */  mfc1      $a1, $f28
/* 9DB544 80244524 4406D000 */  mfc1      $a2, $f26
/* 9DB548 80244528 4407C000 */  mfc1      $a3, $f24
/* 9DB54C 8024452C 0C0910D8 */  jal       func_80244360
/* 9DB550 80244530 27A40010 */   addiu    $a0, $sp, 0x10
/* 9DB554 80244534 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB558 80244538 0200282D */  daddu     $a1, $s0, $zero
/* 9DB55C 8024453C 0C019D80 */  jal       guMtxCatF
/* 9DB560 80244540 0200302D */   daddu    $a2, $s0, $zero
/* 9DB564 80244544 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB568 80244548 4600B587 */  neg.s     $f22, $f22
/* 9DB56C 8024454C 4405A000 */  mfc1      $a1, $f20
/* 9DB570 80244550 4406B000 */  mfc1      $a2, $f22
/* 9DB574 80244554 0C019E40 */  jal       guTranslateF
/* 9DB578 80244558 00A0382D */   daddu    $a3, $a1, $zero
/* 9DB57C 8024455C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9DB580 80244560 0200282D */  daddu     $a1, $s0, $zero
/* 9DB584 80244564 0C019D80 */  jal       guMtxCatF
/* 9DB588 80244568 00A0302D */   daddu    $a2, $a1, $zero
.L8024456C:
/* 9DB58C 8024456C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 9DB590 80244570 8FB20058 */  lw        $s2, 0x58($sp)
/* 9DB594 80244574 8FB10054 */  lw        $s1, 0x54($sp)
/* 9DB598 80244578 8FB00050 */  lw        $s0, 0x50($sp)
/* 9DB59C 8024457C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 9DB5A0 80244580 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 9DB5A4 80244584 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 9DB5A8 80244588 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 9DB5AC 8024458C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 9DB5B0 80244590 24020002 */  addiu     $v0, $zero, 2
/* 9DB5B4 80244594 03E00008 */  jr        $ra
/* 9DB5B8 80244598 27BD0088 */   addiu    $sp, $sp, 0x88
/* 9DB5BC 8024459C 00000000 */  nop       
