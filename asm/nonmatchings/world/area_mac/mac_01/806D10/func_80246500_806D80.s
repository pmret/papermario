.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80246500_806D80
/* 806D80 80246500 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 806D84 80246504 AFB10054 */  sw        $s1, 0x54($sp)
/* 806D88 80246508 0080882D */  daddu     $s1, $a0, $zero
/* 806D8C 8024650C AFBF005C */  sw        $ra, 0x5c($sp)
/* 806D90 80246510 AFB20058 */  sw        $s2, 0x58($sp)
/* 806D94 80246514 AFB00050 */  sw        $s0, 0x50($sp)
/* 806D98 80246518 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 806D9C 8024651C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 806DA0 80246520 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 806DA4 80246524 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 806DA8 80246528 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 806DAC 8024652C 8E30000C */  lw        $s0, 0xc($s1)
/* 806DB0 80246530 8E050000 */  lw        $a1, ($s0)
/* 806DB4 80246534 0C0B1EAF */  jal       get_variable
/* 806DB8 80246538 26100004 */   addiu    $s0, $s0, 4
/* 806DBC 8024653C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 806DC0 80246540 0040202D */   daddu    $a0, $v0, $zero
/* 806DC4 80246544 8E050000 */  lw        $a1, ($s0)
/* 806DC8 80246548 26100004 */  addiu     $s0, $s0, 4
/* 806DCC 8024654C 0220202D */  daddu     $a0, $s1, $zero
/* 806DD0 80246550 0C0B210B */  jal       get_float_variable
/* 806DD4 80246554 0040902D */   daddu    $s2, $v0, $zero
/* 806DD8 80246558 8E050000 */  lw        $a1, ($s0)
/* 806DDC 8024655C 26100004 */  addiu     $s0, $s0, 4
/* 806DE0 80246560 0220202D */  daddu     $a0, $s1, $zero
/* 806DE4 80246564 0C0B210B */  jal       get_float_variable
/* 806DE8 80246568 46000706 */   mov.s    $f28, $f0
/* 806DEC 8024656C 8E050000 */  lw        $a1, ($s0)
/* 806DF0 80246570 26100004 */  addiu     $s0, $s0, 4
/* 806DF4 80246574 0220202D */  daddu     $a0, $s1, $zero
/* 806DF8 80246578 0C0B210B */  jal       get_float_variable
/* 806DFC 8024657C 46000686 */   mov.s    $f26, $f0
/* 806E00 80246580 0220202D */  daddu     $a0, $s1, $zero
/* 806E04 80246584 8E050000 */  lw        $a1, ($s0)
/* 806E08 80246588 0C0B210B */  jal       get_float_variable
/* 806E0C 8024658C 46000586 */   mov.s    $f22, $f0
/* 806E10 80246590 0240202D */  daddu     $a0, $s2, $zero
/* 806E14 80246594 0C046B4C */  jal       get_model_from_list_index
/* 806E18 80246598 46000606 */   mov.s    $f24, $f0
/* 806E1C 8024659C 0040882D */  daddu     $s1, $v0, $zero
/* 806E20 802465A0 96220000 */  lhu       $v0, ($s1)
/* 806E24 802465A4 30420400 */  andi      $v0, $v0, 0x400
/* 806E28 802465A8 1440001E */  bnez      $v0, .L80246624
/* 806E2C 802465AC 26300058 */   addiu    $s0, $s1, 0x58
/* 806E30 802465B0 4480A000 */  mtc1      $zero, $f20
/* 806E34 802465B4 4406B000 */  mfc1      $a2, $f22
/* 806E38 802465B8 4405A000 */  mfc1      $a1, $f20
/* 806E3C 802465BC 4407A000 */  mfc1      $a3, $f20
/* 806E40 802465C0 0C019E40 */  jal       guTranslateF
/* 806E44 802465C4 0200202D */   daddu    $a0, $s0, $zero
/* 806E48 802465C8 4405E000 */  mfc1      $a1, $f28
/* 806E4C 802465CC 4406D000 */  mfc1      $a2, $f26
/* 806E50 802465D0 4407C000 */  mfc1      $a3, $f24
/* 806E54 802465D4 0C091924 */  jal       func_80246490_806D10
/* 806E58 802465D8 27A40010 */   addiu    $a0, $sp, 0x10
/* 806E5C 802465DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 806E60 802465E0 0200282D */  daddu     $a1, $s0, $zero
/* 806E64 802465E4 0C019D80 */  jal       guMtxCatF
/* 806E68 802465E8 0200302D */   daddu    $a2, $s0, $zero
/* 806E6C 802465EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 806E70 802465F0 4600B587 */  neg.s     $f22, $f22
/* 806E74 802465F4 4405A000 */  mfc1      $a1, $f20
/* 806E78 802465F8 4406B000 */  mfc1      $a2, $f22
/* 806E7C 802465FC 0C019E40 */  jal       guTranslateF
/* 806E80 80246600 00A0382D */   daddu    $a3, $a1, $zero
/* 806E84 80246604 27A40010 */  addiu     $a0, $sp, 0x10
/* 806E88 80246608 0200282D */  daddu     $a1, $s0, $zero
/* 806E8C 8024660C 0C019D80 */  jal       guMtxCatF
/* 806E90 80246610 00A0302D */   daddu    $a2, $a1, $zero
/* 806E94 80246614 96220000 */  lhu       $v0, ($s1)
/* 806E98 80246618 34421400 */  ori       $v0, $v0, 0x1400
/* 806E9C 8024661C 080919A7 */  j         .L8024669C
/* 806EA0 80246620 A6220000 */   sh       $v0, ($s1)
.L80246624:
/* 806EA4 80246624 4480A000 */  mtc1      $zero, $f20
/* 806EA8 80246628 4406B000 */  mfc1      $a2, $f22
/* 806EAC 8024662C 4405A000 */  mfc1      $a1, $f20
/* 806EB0 80246630 4407A000 */  mfc1      $a3, $f20
/* 806EB4 80246634 0C019E40 */  jal       guTranslateF
/* 806EB8 80246638 27A40010 */   addiu    $a0, $sp, 0x10
/* 806EBC 8024663C 27A40010 */  addiu     $a0, $sp, 0x10
/* 806EC0 80246640 26300058 */  addiu     $s0, $s1, 0x58
/* 806EC4 80246644 0200282D */  daddu     $a1, $s0, $zero
/* 806EC8 80246648 0C019D80 */  jal       guMtxCatF
/* 806ECC 8024664C 0200302D */   daddu    $a2, $s0, $zero
/* 806ED0 80246650 4405E000 */  mfc1      $a1, $f28
/* 806ED4 80246654 4406D000 */  mfc1      $a2, $f26
/* 806ED8 80246658 4407C000 */  mfc1      $a3, $f24
/* 806EDC 8024665C 0C091924 */  jal       func_80246490_806D10
/* 806EE0 80246660 27A40010 */   addiu    $a0, $sp, 0x10
/* 806EE4 80246664 27A40010 */  addiu     $a0, $sp, 0x10
/* 806EE8 80246668 0200282D */  daddu     $a1, $s0, $zero
/* 806EEC 8024666C 0C019D80 */  jal       guMtxCatF
/* 806EF0 80246670 0200302D */   daddu    $a2, $s0, $zero
/* 806EF4 80246674 27A40010 */  addiu     $a0, $sp, 0x10
/* 806EF8 80246678 4600B587 */  neg.s     $f22, $f22
/* 806EFC 8024667C 4405A000 */  mfc1      $a1, $f20
/* 806F00 80246680 4406B000 */  mfc1      $a2, $f22
/* 806F04 80246684 0C019E40 */  jal       guTranslateF
/* 806F08 80246688 00A0382D */   daddu    $a3, $a1, $zero
/* 806F0C 8024668C 27A40010 */  addiu     $a0, $sp, 0x10
/* 806F10 80246690 0200282D */  daddu     $a1, $s0, $zero
/* 806F14 80246694 0C019D80 */  jal       guMtxCatF
/* 806F18 80246698 00A0302D */   daddu    $a2, $a1, $zero
.L8024669C:
/* 806F1C 8024669C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 806F20 802466A0 8FB20058 */  lw        $s2, 0x58($sp)
/* 806F24 802466A4 8FB10054 */  lw        $s1, 0x54($sp)
/* 806F28 802466A8 8FB00050 */  lw        $s0, 0x50($sp)
/* 806F2C 802466AC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 806F30 802466B0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 806F34 802466B4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 806F38 802466B8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 806F3C 802466BC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 806F40 802466C0 24020002 */  addiu     $v0, $zero, 2
/* 806F44 802466C4 03E00008 */  jr        $ra
/* 806F48 802466C8 27BD0088 */   addiu    $sp, $sp, 0x88
/* 806F4C 802466CC 00000000 */  nop       
