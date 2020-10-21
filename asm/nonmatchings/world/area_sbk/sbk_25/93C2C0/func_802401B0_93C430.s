.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B0_93C430
/* 93C430 802401B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 93C434 802401B4 AFB10054 */  sw        $s1, 0x54($sp)
/* 93C438 802401B8 0080882D */  daddu     $s1, $a0, $zero
/* 93C43C 802401BC AFBF005C */  sw        $ra, 0x5c($sp)
/* 93C440 802401C0 AFB20058 */  sw        $s2, 0x58($sp)
/* 93C444 802401C4 AFB00050 */  sw        $s0, 0x50($sp)
/* 93C448 802401C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 93C44C 802401CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 93C450 802401D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 93C454 802401D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 93C458 802401D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 93C45C 802401DC 8E30000C */  lw        $s0, 0xc($s1)
/* 93C460 802401E0 8E050000 */  lw        $a1, ($s0)
/* 93C464 802401E4 0C0B1EAF */  jal       get_variable
/* 93C468 802401E8 26100004 */   addiu    $s0, $s0, 4
/* 93C46C 802401EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 93C470 802401F0 0040202D */   daddu    $a0, $v0, $zero
/* 93C474 802401F4 8E050000 */  lw        $a1, ($s0)
/* 93C478 802401F8 26100004 */  addiu     $s0, $s0, 4
/* 93C47C 802401FC 0220202D */  daddu     $a0, $s1, $zero
/* 93C480 80240200 0C0B210B */  jal       get_float_variable
/* 93C484 80240204 0040902D */   daddu    $s2, $v0, $zero
/* 93C488 80240208 8E050000 */  lw        $a1, ($s0)
/* 93C48C 8024020C 26100004 */  addiu     $s0, $s0, 4
/* 93C490 80240210 0220202D */  daddu     $a0, $s1, $zero
/* 93C494 80240214 0C0B210B */  jal       get_float_variable
/* 93C498 80240218 46000706 */   mov.s    $f28, $f0
/* 93C49C 8024021C 8E050000 */  lw        $a1, ($s0)
/* 93C4A0 80240220 26100004 */  addiu     $s0, $s0, 4
/* 93C4A4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* 93C4A8 80240228 0C0B210B */  jal       get_float_variable
/* 93C4AC 8024022C 46000686 */   mov.s    $f26, $f0
/* 93C4B0 80240230 0220202D */  daddu     $a0, $s1, $zero
/* 93C4B4 80240234 8E050000 */  lw        $a1, ($s0)
/* 93C4B8 80240238 0C0B210B */  jal       get_float_variable
/* 93C4BC 8024023C 46000586 */   mov.s    $f22, $f0
/* 93C4C0 80240240 0240202D */  daddu     $a0, $s2, $zero
/* 93C4C4 80240244 0C046B4C */  jal       get_model_from_list_index
/* 93C4C8 80240248 46000606 */   mov.s    $f24, $f0
/* 93C4CC 8024024C 0040882D */  daddu     $s1, $v0, $zero
/* 93C4D0 80240250 96220000 */  lhu       $v0, ($s1)
/* 93C4D4 80240254 30420400 */  andi      $v0, $v0, 0x400
/* 93C4D8 80240258 1440001E */  bnez      $v0, .L802402D4
/* 93C4DC 8024025C 26300058 */   addiu    $s0, $s1, 0x58
/* 93C4E0 80240260 4480A000 */  mtc1      $zero, $f20
/* 93C4E4 80240264 4406B000 */  mfc1      $a2, $f22
/* 93C4E8 80240268 4405A000 */  mfc1      $a1, $f20
/* 93C4EC 8024026C 4407A000 */  mfc1      $a3, $f20
/* 93C4F0 80240270 0C019E40 */  jal       guTranslateF
/* 93C4F4 80240274 0200202D */   daddu    $a0, $s0, $zero
/* 93C4F8 80240278 4405E000 */  mfc1      $a1, $f28
/* 93C4FC 8024027C 4406D000 */  mfc1      $a2, $f26
/* 93C500 80240280 4407C000 */  mfc1      $a3, $f24
/* 93C504 80240284 0C090050 */  jal       func_80240140_93C3C0
/* 93C508 80240288 27A40010 */   addiu    $a0, $sp, 0x10
/* 93C50C 8024028C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C510 80240290 0200282D */  daddu     $a1, $s0, $zero
/* 93C514 80240294 0C019D80 */  jal       guMtxCatF
/* 93C518 80240298 0200302D */   daddu    $a2, $s0, $zero
/* 93C51C 8024029C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C520 802402A0 4600B587 */  neg.s     $f22, $f22
/* 93C524 802402A4 4405A000 */  mfc1      $a1, $f20
/* 93C528 802402A8 4406B000 */  mfc1      $a2, $f22
/* 93C52C 802402AC 0C019E40 */  jal       guTranslateF
/* 93C530 802402B0 00A0382D */   daddu    $a3, $a1, $zero
/* 93C534 802402B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C538 802402B8 0200282D */  daddu     $a1, $s0, $zero
/* 93C53C 802402BC 0C019D80 */  jal       guMtxCatF
/* 93C540 802402C0 00A0302D */   daddu    $a2, $a1, $zero
/* 93C544 802402C4 96220000 */  lhu       $v0, ($s1)
/* 93C548 802402C8 34421400 */  ori       $v0, $v0, 0x1400
/* 93C54C 802402CC 080900D3 */  j         .L8024034C
/* 93C550 802402D0 A6220000 */   sh       $v0, ($s1)
.L802402D4:
/* 93C554 802402D4 4480A000 */  mtc1      $zero, $f20
/* 93C558 802402D8 4406B000 */  mfc1      $a2, $f22
/* 93C55C 802402DC 4405A000 */  mfc1      $a1, $f20
/* 93C560 802402E0 4407A000 */  mfc1      $a3, $f20
/* 93C564 802402E4 0C019E40 */  jal       guTranslateF
/* 93C568 802402E8 27A40010 */   addiu    $a0, $sp, 0x10
/* 93C56C 802402EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C570 802402F0 26300058 */  addiu     $s0, $s1, 0x58
/* 93C574 802402F4 0200282D */  daddu     $a1, $s0, $zero
/* 93C578 802402F8 0C019D80 */  jal       guMtxCatF
/* 93C57C 802402FC 0200302D */   daddu    $a2, $s0, $zero
/* 93C580 80240300 4405E000 */  mfc1      $a1, $f28
/* 93C584 80240304 4406D000 */  mfc1      $a2, $f26
/* 93C588 80240308 4407C000 */  mfc1      $a3, $f24
/* 93C58C 8024030C 0C090050 */  jal       func_80240140_93C3C0
/* 93C590 80240310 27A40010 */   addiu    $a0, $sp, 0x10
/* 93C594 80240314 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C598 80240318 0200282D */  daddu     $a1, $s0, $zero
/* 93C59C 8024031C 0C019D80 */  jal       guMtxCatF
/* 93C5A0 80240320 0200302D */   daddu    $a2, $s0, $zero
/* 93C5A4 80240324 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C5A8 80240328 4600B587 */  neg.s     $f22, $f22
/* 93C5AC 8024032C 4405A000 */  mfc1      $a1, $f20
/* 93C5B0 80240330 4406B000 */  mfc1      $a2, $f22
/* 93C5B4 80240334 0C019E40 */  jal       guTranslateF
/* 93C5B8 80240338 00A0382D */   daddu    $a3, $a1, $zero
/* 93C5BC 8024033C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93C5C0 80240340 0200282D */  daddu     $a1, $s0, $zero
/* 93C5C4 80240344 0C019D80 */  jal       guMtxCatF
/* 93C5C8 80240348 00A0302D */   daddu    $a2, $a1, $zero
.L8024034C:
/* 93C5CC 8024034C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 93C5D0 80240350 8FB20058 */  lw        $s2, 0x58($sp)
/* 93C5D4 80240354 8FB10054 */  lw        $s1, 0x54($sp)
/* 93C5D8 80240358 8FB00050 */  lw        $s0, 0x50($sp)
/* 93C5DC 8024035C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 93C5E0 80240360 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 93C5E4 80240364 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 93C5E8 80240368 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 93C5EC 8024036C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 93C5F0 80240370 24020002 */  addiu     $v0, $zero, 2
/* 93C5F4 80240374 03E00008 */  jr        $ra
/* 93C5F8 80240378 27BD0088 */   addiu    $sp, $sp, 0x88
/* 93C5FC 8024037C 00000000 */  nop       
