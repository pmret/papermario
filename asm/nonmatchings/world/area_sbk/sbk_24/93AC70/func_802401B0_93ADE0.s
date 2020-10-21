.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B0_93ADE0
/* 93ADE0 802401B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 93ADE4 802401B4 AFB10054 */  sw        $s1, 0x54($sp)
/* 93ADE8 802401B8 0080882D */  daddu     $s1, $a0, $zero
/* 93ADEC 802401BC AFBF005C */  sw        $ra, 0x5c($sp)
/* 93ADF0 802401C0 AFB20058 */  sw        $s2, 0x58($sp)
/* 93ADF4 802401C4 AFB00050 */  sw        $s0, 0x50($sp)
/* 93ADF8 802401C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 93ADFC 802401CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 93AE00 802401D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 93AE04 802401D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 93AE08 802401D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 93AE0C 802401DC 8E30000C */  lw        $s0, 0xc($s1)
/* 93AE10 802401E0 8E050000 */  lw        $a1, ($s0)
/* 93AE14 802401E4 0C0B1EAF */  jal       get_variable
/* 93AE18 802401E8 26100004 */   addiu    $s0, $s0, 4
/* 93AE1C 802401EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 93AE20 802401F0 0040202D */   daddu    $a0, $v0, $zero
/* 93AE24 802401F4 8E050000 */  lw        $a1, ($s0)
/* 93AE28 802401F8 26100004 */  addiu     $s0, $s0, 4
/* 93AE2C 802401FC 0220202D */  daddu     $a0, $s1, $zero
/* 93AE30 80240200 0C0B210B */  jal       get_float_variable
/* 93AE34 80240204 0040902D */   daddu    $s2, $v0, $zero
/* 93AE38 80240208 8E050000 */  lw        $a1, ($s0)
/* 93AE3C 8024020C 26100004 */  addiu     $s0, $s0, 4
/* 93AE40 80240210 0220202D */  daddu     $a0, $s1, $zero
/* 93AE44 80240214 0C0B210B */  jal       get_float_variable
/* 93AE48 80240218 46000706 */   mov.s    $f28, $f0
/* 93AE4C 8024021C 8E050000 */  lw        $a1, ($s0)
/* 93AE50 80240220 26100004 */  addiu     $s0, $s0, 4
/* 93AE54 80240224 0220202D */  daddu     $a0, $s1, $zero
/* 93AE58 80240228 0C0B210B */  jal       get_float_variable
/* 93AE5C 8024022C 46000686 */   mov.s    $f26, $f0
/* 93AE60 80240230 0220202D */  daddu     $a0, $s1, $zero
/* 93AE64 80240234 8E050000 */  lw        $a1, ($s0)
/* 93AE68 80240238 0C0B210B */  jal       get_float_variable
/* 93AE6C 8024023C 46000586 */   mov.s    $f22, $f0
/* 93AE70 80240240 0240202D */  daddu     $a0, $s2, $zero
/* 93AE74 80240244 0C046B4C */  jal       get_model_from_list_index
/* 93AE78 80240248 46000606 */   mov.s    $f24, $f0
/* 93AE7C 8024024C 0040882D */  daddu     $s1, $v0, $zero
/* 93AE80 80240250 96220000 */  lhu       $v0, ($s1)
/* 93AE84 80240254 30420400 */  andi      $v0, $v0, 0x400
/* 93AE88 80240258 1440001E */  bnez      $v0, .L802402D4
/* 93AE8C 8024025C 26300058 */   addiu    $s0, $s1, 0x58
/* 93AE90 80240260 4480A000 */  mtc1      $zero, $f20
/* 93AE94 80240264 4406B000 */  mfc1      $a2, $f22
/* 93AE98 80240268 4405A000 */  mfc1      $a1, $f20
/* 93AE9C 8024026C 4407A000 */  mfc1      $a3, $f20
/* 93AEA0 80240270 0C019E40 */  jal       guTranslateF
/* 93AEA4 80240274 0200202D */   daddu    $a0, $s0, $zero
/* 93AEA8 80240278 4405E000 */  mfc1      $a1, $f28
/* 93AEAC 8024027C 4406D000 */  mfc1      $a2, $f26
/* 93AEB0 80240280 4407C000 */  mfc1      $a3, $f24
/* 93AEB4 80240284 0C090050 */  jal       func_80240140_93AD70
/* 93AEB8 80240288 27A40010 */   addiu    $a0, $sp, 0x10
/* 93AEBC 8024028C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AEC0 80240290 0200282D */  daddu     $a1, $s0, $zero
/* 93AEC4 80240294 0C019D80 */  jal       guMtxCatF
/* 93AEC8 80240298 0200302D */   daddu    $a2, $s0, $zero
/* 93AECC 8024029C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AED0 802402A0 4600B587 */  neg.s     $f22, $f22
/* 93AED4 802402A4 4405A000 */  mfc1      $a1, $f20
/* 93AED8 802402A8 4406B000 */  mfc1      $a2, $f22
/* 93AEDC 802402AC 0C019E40 */  jal       guTranslateF
/* 93AEE0 802402B0 00A0382D */   daddu    $a3, $a1, $zero
/* 93AEE4 802402B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AEE8 802402B8 0200282D */  daddu     $a1, $s0, $zero
/* 93AEEC 802402BC 0C019D80 */  jal       guMtxCatF
/* 93AEF0 802402C0 00A0302D */   daddu    $a2, $a1, $zero
/* 93AEF4 802402C4 96220000 */  lhu       $v0, ($s1)
/* 93AEF8 802402C8 34421400 */  ori       $v0, $v0, 0x1400
/* 93AEFC 802402CC 080900D3 */  j         .L8024034C
/* 93AF00 802402D0 A6220000 */   sh       $v0, ($s1)
.L802402D4:
/* 93AF04 802402D4 4480A000 */  mtc1      $zero, $f20
/* 93AF08 802402D8 4406B000 */  mfc1      $a2, $f22
/* 93AF0C 802402DC 4405A000 */  mfc1      $a1, $f20
/* 93AF10 802402E0 4407A000 */  mfc1      $a3, $f20
/* 93AF14 802402E4 0C019E40 */  jal       guTranslateF
/* 93AF18 802402E8 27A40010 */   addiu    $a0, $sp, 0x10
/* 93AF1C 802402EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AF20 802402F0 26300058 */  addiu     $s0, $s1, 0x58
/* 93AF24 802402F4 0200282D */  daddu     $a1, $s0, $zero
/* 93AF28 802402F8 0C019D80 */  jal       guMtxCatF
/* 93AF2C 802402FC 0200302D */   daddu    $a2, $s0, $zero
/* 93AF30 80240300 4405E000 */  mfc1      $a1, $f28
/* 93AF34 80240304 4406D000 */  mfc1      $a2, $f26
/* 93AF38 80240308 4407C000 */  mfc1      $a3, $f24
/* 93AF3C 8024030C 0C090050 */  jal       func_80240140_93AD70
/* 93AF40 80240310 27A40010 */   addiu    $a0, $sp, 0x10
/* 93AF44 80240314 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AF48 80240318 0200282D */  daddu     $a1, $s0, $zero
/* 93AF4C 8024031C 0C019D80 */  jal       guMtxCatF
/* 93AF50 80240320 0200302D */   daddu    $a2, $s0, $zero
/* 93AF54 80240324 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AF58 80240328 4600B587 */  neg.s     $f22, $f22
/* 93AF5C 8024032C 4405A000 */  mfc1      $a1, $f20
/* 93AF60 80240330 4406B000 */  mfc1      $a2, $f22
/* 93AF64 80240334 0C019E40 */  jal       guTranslateF
/* 93AF68 80240338 00A0382D */   daddu    $a3, $a1, $zero
/* 93AF6C 8024033C 27A40010 */  addiu     $a0, $sp, 0x10
/* 93AF70 80240340 0200282D */  daddu     $a1, $s0, $zero
/* 93AF74 80240344 0C019D80 */  jal       guMtxCatF
/* 93AF78 80240348 00A0302D */   daddu    $a2, $a1, $zero
.L8024034C:
/* 93AF7C 8024034C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 93AF80 80240350 8FB20058 */  lw        $s2, 0x58($sp)
/* 93AF84 80240354 8FB10054 */  lw        $s1, 0x54($sp)
/* 93AF88 80240358 8FB00050 */  lw        $s0, 0x50($sp)
/* 93AF8C 8024035C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 93AF90 80240360 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 93AF94 80240364 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 93AF98 80240368 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 93AF9C 8024036C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 93AFA0 80240370 24020002 */  addiu     $v0, $zero, 2
/* 93AFA4 80240374 03E00008 */  jr        $ra
/* 93AFA8 80240378 27BD0088 */   addiu    $sp, $sp, 0x88
/* 93AFAC 8024037C 00000000 */  nop       
