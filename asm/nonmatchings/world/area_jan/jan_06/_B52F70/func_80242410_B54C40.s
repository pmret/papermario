.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242410_B54C40
/* B54C40 80242410 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B54C44 80242414 AFB10054 */  sw        $s1, 0x54($sp)
/* B54C48 80242418 0080882D */  daddu     $s1, $a0, $zero
/* B54C4C 8024241C AFBF005C */  sw        $ra, 0x5c($sp)
/* B54C50 80242420 AFB20058 */  sw        $s2, 0x58($sp)
/* B54C54 80242424 AFB00050 */  sw        $s0, 0x50($sp)
/* B54C58 80242428 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B54C5C 8024242C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B54C60 80242430 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B54C64 80242434 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B54C68 80242438 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B54C6C 8024243C 8E30000C */  lw        $s0, 0xc($s1)
/* B54C70 80242440 8E050000 */  lw        $a1, ($s0)
/* B54C74 80242444 0C0B1EAF */  jal       get_variable
/* B54C78 80242448 26100004 */   addiu    $s0, $s0, 4
/* B54C7C 8024244C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B54C80 80242450 0040202D */   daddu    $a0, $v0, $zero
/* B54C84 80242454 8E050000 */  lw        $a1, ($s0)
/* B54C88 80242458 26100004 */  addiu     $s0, $s0, 4
/* B54C8C 8024245C 0220202D */  daddu     $a0, $s1, $zero
/* B54C90 80242460 0C0B210B */  jal       get_float_variable
/* B54C94 80242464 0040902D */   daddu    $s2, $v0, $zero
/* B54C98 80242468 8E050000 */  lw        $a1, ($s0)
/* B54C9C 8024246C 26100004 */  addiu     $s0, $s0, 4
/* B54CA0 80242470 0220202D */  daddu     $a0, $s1, $zero
/* B54CA4 80242474 0C0B210B */  jal       get_float_variable
/* B54CA8 80242478 46000706 */   mov.s    $f28, $f0
/* B54CAC 8024247C 8E050000 */  lw        $a1, ($s0)
/* B54CB0 80242480 26100004 */  addiu     $s0, $s0, 4
/* B54CB4 80242484 0220202D */  daddu     $a0, $s1, $zero
/* B54CB8 80242488 0C0B210B */  jal       get_float_variable
/* B54CBC 8024248C 46000686 */   mov.s    $f26, $f0
/* B54CC0 80242490 0220202D */  daddu     $a0, $s1, $zero
/* B54CC4 80242494 8E050000 */  lw        $a1, ($s0)
/* B54CC8 80242498 0C0B210B */  jal       get_float_variable
/* B54CCC 8024249C 46000586 */   mov.s    $f22, $f0
/* B54CD0 802424A0 0240202D */  daddu     $a0, $s2, $zero
/* B54CD4 802424A4 0C046B4C */  jal       get_model_from_list_index
/* B54CD8 802424A8 46000606 */   mov.s    $f24, $f0
/* B54CDC 802424AC 0040882D */  daddu     $s1, $v0, $zero
/* B54CE0 802424B0 96220000 */  lhu       $v0, ($s1)
/* B54CE4 802424B4 30420400 */  andi      $v0, $v0, 0x400
/* B54CE8 802424B8 1440001E */  bnez      $v0, .L80242534
/* B54CEC 802424BC 26300058 */   addiu    $s0, $s1, 0x58
/* B54CF0 802424C0 4480A000 */  mtc1      $zero, $f20
/* B54CF4 802424C4 4406B000 */  mfc1      $a2, $f22
/* B54CF8 802424C8 4405A000 */  mfc1      $a1, $f20
/* B54CFC 802424CC 4407A000 */  mfc1      $a3, $f20
/* B54D00 802424D0 0C019E40 */  jal       guTranslateF
/* B54D04 802424D4 0200202D */   daddu    $a0, $s0, $zero
/* B54D08 802424D8 4405E000 */  mfc1      $a1, $f28
/* B54D0C 802424DC 4406D000 */  mfc1      $a2, $f26
/* B54D10 802424E0 4407C000 */  mfc1      $a3, $f24
/* B54D14 802424E4 0C0908E8 */  jal       func_802423A0
/* B54D18 802424E8 27A40010 */   addiu    $a0, $sp, 0x10
/* B54D1C 802424EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B54D20 802424F0 0200282D */  daddu     $a1, $s0, $zero
/* B54D24 802424F4 0C019D80 */  jal       guMtxCatF
/* B54D28 802424F8 0200302D */   daddu    $a2, $s0, $zero
/* B54D2C 802424FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B54D30 80242500 4600B587 */  neg.s     $f22, $f22
/* B54D34 80242504 4405A000 */  mfc1      $a1, $f20
/* B54D38 80242508 4406B000 */  mfc1      $a2, $f22
/* B54D3C 8024250C 0C019E40 */  jal       guTranslateF
/* B54D40 80242510 00A0382D */   daddu    $a3, $a1, $zero
/* B54D44 80242514 27A40010 */  addiu     $a0, $sp, 0x10
/* B54D48 80242518 0200282D */  daddu     $a1, $s0, $zero
/* B54D4C 8024251C 0C019D80 */  jal       guMtxCatF
/* B54D50 80242520 00A0302D */   daddu    $a2, $a1, $zero
/* B54D54 80242524 96220000 */  lhu       $v0, ($s1)
/* B54D58 80242528 34421400 */  ori       $v0, $v0, 0x1400
/* B54D5C 8024252C 0809096B */  j         .L802425AC
/* B54D60 80242530 A6220000 */   sh       $v0, ($s1)
.L80242534:
/* B54D64 80242534 4480A000 */  mtc1      $zero, $f20
/* B54D68 80242538 4406B000 */  mfc1      $a2, $f22
/* B54D6C 8024253C 4405A000 */  mfc1      $a1, $f20
/* B54D70 80242540 4407A000 */  mfc1      $a3, $f20
/* B54D74 80242544 0C019E40 */  jal       guTranslateF
/* B54D78 80242548 27A40010 */   addiu    $a0, $sp, 0x10
/* B54D7C 8024254C 27A40010 */  addiu     $a0, $sp, 0x10
/* B54D80 80242550 26300058 */  addiu     $s0, $s1, 0x58
/* B54D84 80242554 0200282D */  daddu     $a1, $s0, $zero
/* B54D88 80242558 0C019D80 */  jal       guMtxCatF
/* B54D8C 8024255C 0200302D */   daddu    $a2, $s0, $zero
/* B54D90 80242560 4405E000 */  mfc1      $a1, $f28
/* B54D94 80242564 4406D000 */  mfc1      $a2, $f26
/* B54D98 80242568 4407C000 */  mfc1      $a3, $f24
/* B54D9C 8024256C 0C0908E8 */  jal       func_802423A0
/* B54DA0 80242570 27A40010 */   addiu    $a0, $sp, 0x10
/* B54DA4 80242574 27A40010 */  addiu     $a0, $sp, 0x10
/* B54DA8 80242578 0200282D */  daddu     $a1, $s0, $zero
/* B54DAC 8024257C 0C019D80 */  jal       guMtxCatF
/* B54DB0 80242580 0200302D */   daddu    $a2, $s0, $zero
/* B54DB4 80242584 27A40010 */  addiu     $a0, $sp, 0x10
/* B54DB8 80242588 4600B587 */  neg.s     $f22, $f22
/* B54DBC 8024258C 4405A000 */  mfc1      $a1, $f20
/* B54DC0 80242590 4406B000 */  mfc1      $a2, $f22
/* B54DC4 80242594 0C019E40 */  jal       guTranslateF
/* B54DC8 80242598 00A0382D */   daddu    $a3, $a1, $zero
/* B54DCC 8024259C 27A40010 */  addiu     $a0, $sp, 0x10
/* B54DD0 802425A0 0200282D */  daddu     $a1, $s0, $zero
/* B54DD4 802425A4 0C019D80 */  jal       guMtxCatF
/* B54DD8 802425A8 00A0302D */   daddu    $a2, $a1, $zero
.L802425AC:
/* B54DDC 802425AC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B54DE0 802425B0 8FB20058 */  lw        $s2, 0x58($sp)
/* B54DE4 802425B4 8FB10054 */  lw        $s1, 0x54($sp)
/* B54DE8 802425B8 8FB00050 */  lw        $s0, 0x50($sp)
/* B54DEC 802425BC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B54DF0 802425C0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B54DF4 802425C4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B54DF8 802425C8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B54DFC 802425CC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B54E00 802425D0 24020002 */  addiu     $v0, $zero, 2
/* B54E04 802425D4 03E00008 */  jr        $ra
/* B54E08 802425D8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B54E0C 802425DC 00000000 */  nop       
