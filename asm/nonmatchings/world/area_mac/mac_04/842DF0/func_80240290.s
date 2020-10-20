.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240290
/* 842E60 80240290 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 842E64 80240294 AFB10054 */  sw        $s1, 0x54($sp)
/* 842E68 80240298 0080882D */  daddu     $s1, $a0, $zero
/* 842E6C 8024029C AFBF005C */  sw        $ra, 0x5c($sp)
/* 842E70 802402A0 AFB20058 */  sw        $s2, 0x58($sp)
/* 842E74 802402A4 AFB00050 */  sw        $s0, 0x50($sp)
/* 842E78 802402A8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 842E7C 802402AC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 842E80 802402B0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 842E84 802402B4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 842E88 802402B8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 842E8C 802402BC 8E30000C */  lw        $s0, 0xc($s1)
/* 842E90 802402C0 8E050000 */  lw        $a1, ($s0)
/* 842E94 802402C4 0C0B1EAF */  jal       get_variable
/* 842E98 802402C8 26100004 */   addiu    $s0, $s0, 4
/* 842E9C 802402CC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 842EA0 802402D0 0040202D */   daddu    $a0, $v0, $zero
/* 842EA4 802402D4 8E050000 */  lw        $a1, ($s0)
/* 842EA8 802402D8 26100004 */  addiu     $s0, $s0, 4
/* 842EAC 802402DC 0220202D */  daddu     $a0, $s1, $zero
/* 842EB0 802402E0 0C0B210B */  jal       get_float_variable
/* 842EB4 802402E4 0040902D */   daddu    $s2, $v0, $zero
/* 842EB8 802402E8 8E050000 */  lw        $a1, ($s0)
/* 842EBC 802402EC 26100004 */  addiu     $s0, $s0, 4
/* 842EC0 802402F0 0220202D */  daddu     $a0, $s1, $zero
/* 842EC4 802402F4 0C0B210B */  jal       get_float_variable
/* 842EC8 802402F8 46000706 */   mov.s    $f28, $f0
/* 842ECC 802402FC 8E050000 */  lw        $a1, ($s0)
/* 842ED0 80240300 26100004 */  addiu     $s0, $s0, 4
/* 842ED4 80240304 0220202D */  daddu     $a0, $s1, $zero
/* 842ED8 80240308 0C0B210B */  jal       get_float_variable
/* 842EDC 8024030C 46000686 */   mov.s    $f26, $f0
/* 842EE0 80240310 0220202D */  daddu     $a0, $s1, $zero
/* 842EE4 80240314 8E050000 */  lw        $a1, ($s0)
/* 842EE8 80240318 0C0B210B */  jal       get_float_variable
/* 842EEC 8024031C 46000586 */   mov.s    $f22, $f0
/* 842EF0 80240320 0240202D */  daddu     $a0, $s2, $zero
/* 842EF4 80240324 0C046B4C */  jal       get_model_from_list_index
/* 842EF8 80240328 46000606 */   mov.s    $f24, $f0
/* 842EFC 8024032C 0040882D */  daddu     $s1, $v0, $zero
/* 842F00 80240330 96220000 */  lhu       $v0, ($s1)
/* 842F04 80240334 30420400 */  andi      $v0, $v0, 0x400
/* 842F08 80240338 1440001E */  bnez      $v0, .L802403B4
/* 842F0C 8024033C 26300058 */   addiu    $s0, $s1, 0x58
/* 842F10 80240340 4480A000 */  mtc1      $zero, $f20
/* 842F14 80240344 4406B000 */  mfc1      $a2, $f22
/* 842F18 80240348 4405A000 */  mfc1      $a1, $f20
/* 842F1C 8024034C 4407A000 */  mfc1      $a3, $f20
/* 842F20 80240350 0C019E40 */  jal       guTranslateF
/* 842F24 80240354 0200202D */   daddu    $a0, $s0, $zero
/* 842F28 80240358 4405E000 */  mfc1      $a1, $f28
/* 842F2C 8024035C 4406D000 */  mfc1      $a2, $f26
/* 842F30 80240360 4407C000 */  mfc1      $a3, $f24
/* 842F34 80240364 0C090088 */  jal       func_80240220
/* 842F38 80240368 27A40010 */   addiu    $a0, $sp, 0x10
/* 842F3C 8024036C 27A40010 */  addiu     $a0, $sp, 0x10
/* 842F40 80240370 0200282D */  daddu     $a1, $s0, $zero
/* 842F44 80240374 0C019D80 */  jal       guMtxCatF
/* 842F48 80240378 0200302D */   daddu    $a2, $s0, $zero
/* 842F4C 8024037C 27A40010 */  addiu     $a0, $sp, 0x10
/* 842F50 80240380 4600B587 */  neg.s     $f22, $f22
/* 842F54 80240384 4405A000 */  mfc1      $a1, $f20
/* 842F58 80240388 4406B000 */  mfc1      $a2, $f22
/* 842F5C 8024038C 0C019E40 */  jal       guTranslateF
/* 842F60 80240390 00A0382D */   daddu    $a3, $a1, $zero
/* 842F64 80240394 27A40010 */  addiu     $a0, $sp, 0x10
/* 842F68 80240398 0200282D */  daddu     $a1, $s0, $zero
/* 842F6C 8024039C 0C019D80 */  jal       guMtxCatF
/* 842F70 802403A0 00A0302D */   daddu    $a2, $a1, $zero
/* 842F74 802403A4 96220000 */  lhu       $v0, ($s1)
/* 842F78 802403A8 34421400 */  ori       $v0, $v0, 0x1400
/* 842F7C 802403AC 0809010B */  j         .L8024042C
/* 842F80 802403B0 A6220000 */   sh       $v0, ($s1)
.L802403B4:
/* 842F84 802403B4 4480A000 */  mtc1      $zero, $f20
/* 842F88 802403B8 4406B000 */  mfc1      $a2, $f22
/* 842F8C 802403BC 4405A000 */  mfc1      $a1, $f20
/* 842F90 802403C0 4407A000 */  mfc1      $a3, $f20
/* 842F94 802403C4 0C019E40 */  jal       guTranslateF
/* 842F98 802403C8 27A40010 */   addiu    $a0, $sp, 0x10
/* 842F9C 802403CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 842FA0 802403D0 26300058 */  addiu     $s0, $s1, 0x58
/* 842FA4 802403D4 0200282D */  daddu     $a1, $s0, $zero
/* 842FA8 802403D8 0C019D80 */  jal       guMtxCatF
/* 842FAC 802403DC 0200302D */   daddu    $a2, $s0, $zero
/* 842FB0 802403E0 4405E000 */  mfc1      $a1, $f28
/* 842FB4 802403E4 4406D000 */  mfc1      $a2, $f26
/* 842FB8 802403E8 4407C000 */  mfc1      $a3, $f24
/* 842FBC 802403EC 0C090088 */  jal       func_80240220
/* 842FC0 802403F0 27A40010 */   addiu    $a0, $sp, 0x10
/* 842FC4 802403F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 842FC8 802403F8 0200282D */  daddu     $a1, $s0, $zero
/* 842FCC 802403FC 0C019D80 */  jal       guMtxCatF
/* 842FD0 80240400 0200302D */   daddu    $a2, $s0, $zero
/* 842FD4 80240404 27A40010 */  addiu     $a0, $sp, 0x10
/* 842FD8 80240408 4600B587 */  neg.s     $f22, $f22
/* 842FDC 8024040C 4405A000 */  mfc1      $a1, $f20
/* 842FE0 80240410 4406B000 */  mfc1      $a2, $f22
/* 842FE4 80240414 0C019E40 */  jal       guTranslateF
/* 842FE8 80240418 00A0382D */   daddu    $a3, $a1, $zero
/* 842FEC 8024041C 27A40010 */  addiu     $a0, $sp, 0x10
/* 842FF0 80240420 0200282D */  daddu     $a1, $s0, $zero
/* 842FF4 80240424 0C019D80 */  jal       guMtxCatF
/* 842FF8 80240428 00A0302D */   daddu    $a2, $a1, $zero
.L8024042C:
/* 842FFC 8024042C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 843000 80240430 8FB20058 */  lw        $s2, 0x58($sp)
/* 843004 80240434 8FB10054 */  lw        $s1, 0x54($sp)
/* 843008 80240438 8FB00050 */  lw        $s0, 0x50($sp)
/* 84300C 8024043C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 843010 80240440 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 843014 80240444 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 843018 80240448 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 84301C 8024044C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 843020 80240450 24020002 */  addiu     $v0, $zero, 2
/* 843024 80240454 03E00008 */  jr        $ra
/* 843028 80240458 27BD0088 */   addiu    $sp, $sp, 0x88
/* 84302C 8024045C 00000000 */  nop       
