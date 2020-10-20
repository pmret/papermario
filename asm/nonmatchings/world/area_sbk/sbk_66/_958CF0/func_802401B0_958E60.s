.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B0_958E60
/* 958E60 802401B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 958E64 802401B4 AFB10054 */  sw        $s1, 0x54($sp)
/* 958E68 802401B8 0080882D */  daddu     $s1, $a0, $zero
/* 958E6C 802401BC AFBF005C */  sw        $ra, 0x5c($sp)
/* 958E70 802401C0 AFB20058 */  sw        $s2, 0x58($sp)
/* 958E74 802401C4 AFB00050 */  sw        $s0, 0x50($sp)
/* 958E78 802401C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 958E7C 802401CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 958E80 802401D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 958E84 802401D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 958E88 802401D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 958E8C 802401DC 8E30000C */  lw        $s0, 0xc($s1)
/* 958E90 802401E0 8E050000 */  lw        $a1, ($s0)
/* 958E94 802401E4 0C0B1EAF */  jal       get_variable
/* 958E98 802401E8 26100004 */   addiu    $s0, $s0, 4
/* 958E9C 802401EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 958EA0 802401F0 0040202D */   daddu    $a0, $v0, $zero
/* 958EA4 802401F4 8E050000 */  lw        $a1, ($s0)
/* 958EA8 802401F8 26100004 */  addiu     $s0, $s0, 4
/* 958EAC 802401FC 0220202D */  daddu     $a0, $s1, $zero
/* 958EB0 80240200 0C0B210B */  jal       get_float_variable
/* 958EB4 80240204 0040902D */   daddu    $s2, $v0, $zero
/* 958EB8 80240208 8E050000 */  lw        $a1, ($s0)
/* 958EBC 8024020C 26100004 */  addiu     $s0, $s0, 4
/* 958EC0 80240210 0220202D */  daddu     $a0, $s1, $zero
/* 958EC4 80240214 0C0B210B */  jal       get_float_variable
/* 958EC8 80240218 46000706 */   mov.s    $f28, $f0
/* 958ECC 8024021C 8E050000 */  lw        $a1, ($s0)
/* 958ED0 80240220 26100004 */  addiu     $s0, $s0, 4
/* 958ED4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* 958ED8 80240228 0C0B210B */  jal       get_float_variable
/* 958EDC 8024022C 46000686 */   mov.s    $f26, $f0
/* 958EE0 80240230 0220202D */  daddu     $a0, $s1, $zero
/* 958EE4 80240234 8E050000 */  lw        $a1, ($s0)
/* 958EE8 80240238 0C0B210B */  jal       get_float_variable
/* 958EEC 8024023C 46000586 */   mov.s    $f22, $f0
/* 958EF0 80240240 0240202D */  daddu     $a0, $s2, $zero
/* 958EF4 80240244 0C046B4C */  jal       get_model_from_list_index
/* 958EF8 80240248 46000606 */   mov.s    $f24, $f0
/* 958EFC 8024024C 0040882D */  daddu     $s1, $v0, $zero
/* 958F00 80240250 96220000 */  lhu       $v0, ($s1)
/* 958F04 80240254 30420400 */  andi      $v0, $v0, 0x400
/* 958F08 80240258 1440001E */  bnez      $v0, .L802402D4
/* 958F0C 8024025C 26300058 */   addiu    $s0, $s1, 0x58
/* 958F10 80240260 4480A000 */  mtc1      $zero, $f20
/* 958F14 80240264 4406B000 */  mfc1      $a2, $f22
/* 958F18 80240268 4405A000 */  mfc1      $a1, $f20
/* 958F1C 8024026C 4407A000 */  mfc1      $a3, $f20
/* 958F20 80240270 0C019E40 */  jal       guTranslateF
/* 958F24 80240274 0200202D */   daddu    $a0, $s0, $zero
/* 958F28 80240278 4405E000 */  mfc1      $a1, $f28
/* 958F2C 8024027C 4406D000 */  mfc1      $a2, $f26
/* 958F30 80240280 4407C000 */  mfc1      $a3, $f24
/* 958F34 80240284 0C090050 */  jal       func_80240140
/* 958F38 80240288 27A40010 */   addiu    $a0, $sp, 0x10
/* 958F3C 8024028C 27A40010 */  addiu     $a0, $sp, 0x10
/* 958F40 80240290 0200282D */  daddu     $a1, $s0, $zero
/* 958F44 80240294 0C019D80 */  jal       guMtxCatF
/* 958F48 80240298 0200302D */   daddu    $a2, $s0, $zero
/* 958F4C 8024029C 27A40010 */  addiu     $a0, $sp, 0x10
/* 958F50 802402A0 4600B587 */  neg.s     $f22, $f22
/* 958F54 802402A4 4405A000 */  mfc1      $a1, $f20
/* 958F58 802402A8 4406B000 */  mfc1      $a2, $f22
/* 958F5C 802402AC 0C019E40 */  jal       guTranslateF
/* 958F60 802402B0 00A0382D */   daddu    $a3, $a1, $zero
/* 958F64 802402B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 958F68 802402B8 0200282D */  daddu     $a1, $s0, $zero
/* 958F6C 802402BC 0C019D80 */  jal       guMtxCatF
/* 958F70 802402C0 00A0302D */   daddu    $a2, $a1, $zero
/* 958F74 802402C4 96220000 */  lhu       $v0, ($s1)
/* 958F78 802402C8 34421400 */  ori       $v0, $v0, 0x1400
/* 958F7C 802402CC 080900D3 */  j         .L8024034C
/* 958F80 802402D0 A6220000 */   sh       $v0, ($s1)
.L802402D4:
/* 958F84 802402D4 4480A000 */  mtc1      $zero, $f20
/* 958F88 802402D8 4406B000 */  mfc1      $a2, $f22
/* 958F8C 802402DC 4405A000 */  mfc1      $a1, $f20
/* 958F90 802402E0 4407A000 */  mfc1      $a3, $f20
/* 958F94 802402E4 0C019E40 */  jal       guTranslateF
/* 958F98 802402E8 27A40010 */   addiu    $a0, $sp, 0x10
/* 958F9C 802402EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 958FA0 802402F0 26300058 */  addiu     $s0, $s1, 0x58
/* 958FA4 802402F4 0200282D */  daddu     $a1, $s0, $zero
/* 958FA8 802402F8 0C019D80 */  jal       guMtxCatF
/* 958FAC 802402FC 0200302D */   daddu    $a2, $s0, $zero
/* 958FB0 80240300 4405E000 */  mfc1      $a1, $f28
/* 958FB4 80240304 4406D000 */  mfc1      $a2, $f26
/* 958FB8 80240308 4407C000 */  mfc1      $a3, $f24
/* 958FBC 8024030C 0C090050 */  jal       func_80240140
/* 958FC0 80240310 27A40010 */   addiu    $a0, $sp, 0x10
/* 958FC4 80240314 27A40010 */  addiu     $a0, $sp, 0x10
/* 958FC8 80240318 0200282D */  daddu     $a1, $s0, $zero
/* 958FCC 8024031C 0C019D80 */  jal       guMtxCatF
/* 958FD0 80240320 0200302D */   daddu    $a2, $s0, $zero
/* 958FD4 80240324 27A40010 */  addiu     $a0, $sp, 0x10
/* 958FD8 80240328 4600B587 */  neg.s     $f22, $f22
/* 958FDC 8024032C 4405A000 */  mfc1      $a1, $f20
/* 958FE0 80240330 4406B000 */  mfc1      $a2, $f22
/* 958FE4 80240334 0C019E40 */  jal       guTranslateF
/* 958FE8 80240338 00A0382D */   daddu    $a3, $a1, $zero
/* 958FEC 8024033C 27A40010 */  addiu     $a0, $sp, 0x10
/* 958FF0 80240340 0200282D */  daddu     $a1, $s0, $zero
/* 958FF4 80240344 0C019D80 */  jal       guMtxCatF
/* 958FF8 80240348 00A0302D */   daddu    $a2, $a1, $zero
.L8024034C:
/* 958FFC 8024034C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 959000 80240350 8FB20058 */  lw        $s2, 0x58($sp)
/* 959004 80240354 8FB10054 */  lw        $s1, 0x54($sp)
/* 959008 80240358 8FB00050 */  lw        $s0, 0x50($sp)
/* 95900C 8024035C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 959010 80240360 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 959014 80240364 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 959018 80240368 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 95901C 8024036C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 959020 80240370 24020002 */  addiu     $v0, $zero, 2
/* 959024 80240374 03E00008 */  jr        $ra
/* 959028 80240378 27BD0088 */   addiu    $sp, $sp, 0x88
/* 95902C 8024037C 00000000 */  nop       
