.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240440_8D8910
/* 8D8910 80240440 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8D8914 80240444 AFB10054 */  sw        $s1, 0x54($sp)
/* 8D8918 80240448 0080882D */  daddu     $s1, $a0, $zero
/* 8D891C 8024044C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8D8920 80240450 AFB20058 */  sw        $s2, 0x58($sp)
/* 8D8924 80240454 AFB00050 */  sw        $s0, 0x50($sp)
/* 8D8928 80240458 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8D892C 8024045C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8D8930 80240460 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8D8934 80240464 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8D8938 80240468 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8D893C 8024046C 8E30000C */  lw        $s0, 0xc($s1)
/* 8D8940 80240470 8E050000 */  lw        $a1, ($s0)
/* 8D8944 80240474 0C0B1EAF */  jal       get_variable
/* 8D8948 80240478 26100004 */   addiu    $s0, $s0, 4
/* 8D894C 8024047C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8D8950 80240480 0040202D */   daddu    $a0, $v0, $zero
/* 8D8954 80240484 8E050000 */  lw        $a1, ($s0)
/* 8D8958 80240488 26100004 */  addiu     $s0, $s0, 4
/* 8D895C 8024048C 0220202D */  daddu     $a0, $s1, $zero
/* 8D8960 80240490 0C0B210B */  jal       get_float_variable
/* 8D8964 80240494 0040902D */   daddu    $s2, $v0, $zero
/* 8D8968 80240498 8E050000 */  lw        $a1, ($s0)
/* 8D896C 8024049C 26100004 */  addiu     $s0, $s0, 4
/* 8D8970 802404A0 0220202D */  daddu     $a0, $s1, $zero
/* 8D8974 802404A4 0C0B210B */  jal       get_float_variable
/* 8D8978 802404A8 46000706 */   mov.s    $f28, $f0
/* 8D897C 802404AC 8E050000 */  lw        $a1, ($s0)
/* 8D8980 802404B0 26100004 */  addiu     $s0, $s0, 4
/* 8D8984 802404B4 0220202D */  daddu     $a0, $s1, $zero
/* 8D8988 802404B8 0C0B210B */  jal       get_float_variable
/* 8D898C 802404BC 46000686 */   mov.s    $f26, $f0
/* 8D8990 802404C0 0220202D */  daddu     $a0, $s1, $zero
/* 8D8994 802404C4 8E050000 */  lw        $a1, ($s0)
/* 8D8998 802404C8 0C0B210B */  jal       get_float_variable
/* 8D899C 802404CC 46000586 */   mov.s    $f22, $f0
/* 8D89A0 802404D0 0240202D */  daddu     $a0, $s2, $zero
/* 8D89A4 802404D4 0C046B4C */  jal       get_model_from_list_index
/* 8D89A8 802404D8 46000606 */   mov.s    $f24, $f0
/* 8D89AC 802404DC 0040882D */  daddu     $s1, $v0, $zero
/* 8D89B0 802404E0 96220000 */  lhu       $v0, ($s1)
/* 8D89B4 802404E4 30420400 */  andi      $v0, $v0, 0x400
/* 8D89B8 802404E8 1440001E */  bnez      $v0, .L80240564
/* 8D89BC 802404EC 26300058 */   addiu    $s0, $s1, 0x58
/* 8D89C0 802404F0 4480A000 */  mtc1      $zero, $f20
/* 8D89C4 802404F4 4406B000 */  mfc1      $a2, $f22
/* 8D89C8 802404F8 4405A000 */  mfc1      $a1, $f20
/* 8D89CC 802404FC 4407A000 */  mfc1      $a3, $f20
/* 8D89D0 80240500 0C019E40 */  jal       guTranslateF
/* 8D89D4 80240504 0200202D */   daddu    $a0, $s0, $zero
/* 8D89D8 80240508 4405E000 */  mfc1      $a1, $f28
/* 8D89DC 8024050C 4406D000 */  mfc1      $a2, $f26
/* 8D89E0 80240510 4407C000 */  mfc1      $a3, $f24
/* 8D89E4 80240514 0C0900F4 */  jal       func_802403D0_8D88A0
/* 8D89E8 80240518 27A40010 */   addiu    $a0, $sp, 0x10
/* 8D89EC 8024051C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D89F0 80240520 0200282D */  daddu     $a1, $s0, $zero
/* 8D89F4 80240524 0C019D80 */  jal       guMtxCatF
/* 8D89F8 80240528 0200302D */   daddu    $a2, $s0, $zero
/* 8D89FC 8024052C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D8A00 80240530 4600B587 */  neg.s     $f22, $f22
/* 8D8A04 80240534 4405A000 */  mfc1      $a1, $f20
/* 8D8A08 80240538 4406B000 */  mfc1      $a2, $f22
/* 8D8A0C 8024053C 0C019E40 */  jal       guTranslateF
/* 8D8A10 80240540 00A0382D */   daddu    $a3, $a1, $zero
/* 8D8A14 80240544 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D8A18 80240548 0200282D */  daddu     $a1, $s0, $zero
/* 8D8A1C 8024054C 0C019D80 */  jal       guMtxCatF
/* 8D8A20 80240550 00A0302D */   daddu    $a2, $a1, $zero
/* 8D8A24 80240554 96220000 */  lhu       $v0, ($s1)
/* 8D8A28 80240558 34421400 */  ori       $v0, $v0, 0x1400
/* 8D8A2C 8024055C 08090177 */  j         .L802405DC
/* 8D8A30 80240560 A6220000 */   sh       $v0, ($s1)
.L80240564:
/* 8D8A34 80240564 4480A000 */  mtc1      $zero, $f20
/* 8D8A38 80240568 4406B000 */  mfc1      $a2, $f22
/* 8D8A3C 8024056C 4405A000 */  mfc1      $a1, $f20
/* 8D8A40 80240570 4407A000 */  mfc1      $a3, $f20
/* 8D8A44 80240574 0C019E40 */  jal       guTranslateF
/* 8D8A48 80240578 27A40010 */   addiu    $a0, $sp, 0x10
/* 8D8A4C 8024057C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D8A50 80240580 26300058 */  addiu     $s0, $s1, 0x58
/* 8D8A54 80240584 0200282D */  daddu     $a1, $s0, $zero
/* 8D8A58 80240588 0C019D80 */  jal       guMtxCatF
/* 8D8A5C 8024058C 0200302D */   daddu    $a2, $s0, $zero
/* 8D8A60 80240590 4405E000 */  mfc1      $a1, $f28
/* 8D8A64 80240594 4406D000 */  mfc1      $a2, $f26
/* 8D8A68 80240598 4407C000 */  mfc1      $a3, $f24
/* 8D8A6C 8024059C 0C0900F4 */  jal       func_802403D0_8D88A0
/* 8D8A70 802405A0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8D8A74 802405A4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D8A78 802405A8 0200282D */  daddu     $a1, $s0, $zero
/* 8D8A7C 802405AC 0C019D80 */  jal       guMtxCatF
/* 8D8A80 802405B0 0200302D */   daddu    $a2, $s0, $zero
/* 8D8A84 802405B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D8A88 802405B8 4600B587 */  neg.s     $f22, $f22
/* 8D8A8C 802405BC 4405A000 */  mfc1      $a1, $f20
/* 8D8A90 802405C0 4406B000 */  mfc1      $a2, $f22
/* 8D8A94 802405C4 0C019E40 */  jal       guTranslateF
/* 8D8A98 802405C8 00A0382D */   daddu    $a3, $a1, $zero
/* 8D8A9C 802405CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D8AA0 802405D0 0200282D */  daddu     $a1, $s0, $zero
/* 8D8AA4 802405D4 0C019D80 */  jal       guMtxCatF
/* 8D8AA8 802405D8 00A0302D */   daddu    $a2, $a1, $zero
.L802405DC:
/* 8D8AAC 802405DC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8D8AB0 802405E0 8FB20058 */  lw        $s2, 0x58($sp)
/* 8D8AB4 802405E4 8FB10054 */  lw        $s1, 0x54($sp)
/* 8D8AB8 802405E8 8FB00050 */  lw        $s0, 0x50($sp)
/* 8D8ABC 802405EC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8D8AC0 802405F0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8D8AC4 802405F4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8D8AC8 802405F8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8D8ACC 802405FC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8D8AD0 80240600 24020002 */  addiu     $v0, $zero, 2
/* 8D8AD4 80240604 03E00008 */  jr        $ra
/* 8D8AD8 80240608 27BD0088 */   addiu    $sp, $sp, 0x88
/* 8D8ADC 8024060C 00000000 */  nop       
