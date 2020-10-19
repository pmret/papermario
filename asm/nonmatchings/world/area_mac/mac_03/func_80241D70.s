.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D70
/* 833570 80241D70 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 833574 80241D74 AFB10054 */  sw        $s1, 0x54($sp)
/* 833578 80241D78 0080882D */  daddu     $s1, $a0, $zero
/* 83357C 80241D7C AFBF005C */  sw        $ra, 0x5c($sp)
/* 833580 80241D80 AFB20058 */  sw        $s2, 0x58($sp)
/* 833584 80241D84 AFB00050 */  sw        $s0, 0x50($sp)
/* 833588 80241D88 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 83358C 80241D8C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 833590 80241D90 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 833594 80241D94 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 833598 80241D98 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 83359C 80241D9C 8E30000C */  lw        $s0, 0xc($s1)
/* 8335A0 80241DA0 8E050000 */  lw        $a1, ($s0)
/* 8335A4 80241DA4 0C0B1EAF */  jal       get_variable
/* 8335A8 80241DA8 26100004 */   addiu    $s0, $s0, 4
/* 8335AC 80241DAC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8335B0 80241DB0 0040202D */   daddu    $a0, $v0, $zero
/* 8335B4 80241DB4 8E050000 */  lw        $a1, ($s0)
/* 8335B8 80241DB8 26100004 */  addiu     $s0, $s0, 4
/* 8335BC 80241DBC 0220202D */  daddu     $a0, $s1, $zero
/* 8335C0 80241DC0 0C0B210B */  jal       get_float_variable
/* 8335C4 80241DC4 0040902D */   daddu    $s2, $v0, $zero
/* 8335C8 80241DC8 8E050000 */  lw        $a1, ($s0)
/* 8335CC 80241DCC 26100004 */  addiu     $s0, $s0, 4
/* 8335D0 80241DD0 0220202D */  daddu     $a0, $s1, $zero
/* 8335D4 80241DD4 0C0B210B */  jal       get_float_variable
/* 8335D8 80241DD8 46000706 */   mov.s    $f28, $f0
/* 8335DC 80241DDC 8E050000 */  lw        $a1, ($s0)
/* 8335E0 80241DE0 26100004 */  addiu     $s0, $s0, 4
/* 8335E4 80241DE4 0220202D */  daddu     $a0, $s1, $zero
/* 8335E8 80241DE8 0C0B210B */  jal       get_float_variable
/* 8335EC 80241DEC 46000686 */   mov.s    $f26, $f0
/* 8335F0 80241DF0 0220202D */  daddu     $a0, $s1, $zero
/* 8335F4 80241DF4 8E050000 */  lw        $a1, ($s0)
/* 8335F8 80241DF8 0C0B210B */  jal       get_float_variable
/* 8335FC 80241DFC 46000586 */   mov.s    $f22, $f0
/* 833600 80241E00 0240202D */  daddu     $a0, $s2, $zero
/* 833604 80241E04 0C046B4C */  jal       get_model_from_list_index
/* 833608 80241E08 46000606 */   mov.s    $f24, $f0
/* 83360C 80241E0C 0040882D */  daddu     $s1, $v0, $zero
/* 833610 80241E10 96220000 */  lhu       $v0, ($s1)
/* 833614 80241E14 30420400 */  andi      $v0, $v0, 0x400
/* 833618 80241E18 1440001E */  bnez      $v0, .L80241E94
/* 83361C 80241E1C 26300058 */   addiu    $s0, $s1, 0x58
/* 833620 80241E20 4480A000 */  mtc1      $zero, $f20
/* 833624 80241E24 4406B000 */  mfc1      $a2, $f22
/* 833628 80241E28 4405A000 */  mfc1      $a1, $f20
/* 83362C 80241E2C 4407A000 */  mfc1      $a3, $f20
/* 833630 80241E30 0C019E40 */  jal       guTranslateF
/* 833634 80241E34 0200202D */   daddu    $a0, $s0, $zero
/* 833638 80241E38 4405E000 */  mfc1      $a1, $f28
/* 83363C 80241E3C 4406D000 */  mfc1      $a2, $f26
/* 833640 80241E40 4407C000 */  mfc1      $a3, $f24
/* 833644 80241E44 0C090740 */  jal       func_80241D00
/* 833648 80241E48 27A40010 */   addiu    $a0, $sp, 0x10
/* 83364C 80241E4C 27A40010 */  addiu     $a0, $sp, 0x10
/* 833650 80241E50 0200282D */  daddu     $a1, $s0, $zero
/* 833654 80241E54 0C019D80 */  jal       guMtxCatF
/* 833658 80241E58 0200302D */   daddu    $a2, $s0, $zero
/* 83365C 80241E5C 27A40010 */  addiu     $a0, $sp, 0x10
/* 833660 80241E60 4600B587 */  neg.s     $f22, $f22
/* 833664 80241E64 4405A000 */  mfc1      $a1, $f20
/* 833668 80241E68 4406B000 */  mfc1      $a2, $f22
/* 83366C 80241E6C 0C019E40 */  jal       guTranslateF
/* 833670 80241E70 00A0382D */   daddu    $a3, $a1, $zero
/* 833674 80241E74 27A40010 */  addiu     $a0, $sp, 0x10
/* 833678 80241E78 0200282D */  daddu     $a1, $s0, $zero
/* 83367C 80241E7C 0C019D80 */  jal       guMtxCatF
/* 833680 80241E80 00A0302D */   daddu    $a2, $a1, $zero
/* 833684 80241E84 96220000 */  lhu       $v0, ($s1)
/* 833688 80241E88 34421400 */  ori       $v0, $v0, 0x1400
/* 83368C 80241E8C 080907C3 */  j         .L80241F0C
/* 833690 80241E90 A6220000 */   sh       $v0, ($s1)
.L80241E94:
/* 833694 80241E94 4480A000 */  mtc1      $zero, $f20
/* 833698 80241E98 4406B000 */  mfc1      $a2, $f22
/* 83369C 80241E9C 4405A000 */  mfc1      $a1, $f20
/* 8336A0 80241EA0 4407A000 */  mfc1      $a3, $f20
/* 8336A4 80241EA4 0C019E40 */  jal       guTranslateF
/* 8336A8 80241EA8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8336AC 80241EAC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8336B0 80241EB0 26300058 */  addiu     $s0, $s1, 0x58
/* 8336B4 80241EB4 0200282D */  daddu     $a1, $s0, $zero
/* 8336B8 80241EB8 0C019D80 */  jal       guMtxCatF
/* 8336BC 80241EBC 0200302D */   daddu    $a2, $s0, $zero
/* 8336C0 80241EC0 4405E000 */  mfc1      $a1, $f28
/* 8336C4 80241EC4 4406D000 */  mfc1      $a2, $f26
/* 8336C8 80241EC8 4407C000 */  mfc1      $a3, $f24
/* 8336CC 80241ECC 0C090740 */  jal       func_80241D00
/* 8336D0 80241ED0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8336D4 80241ED4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8336D8 80241ED8 0200282D */  daddu     $a1, $s0, $zero
/* 8336DC 80241EDC 0C019D80 */  jal       guMtxCatF
/* 8336E0 80241EE0 0200302D */   daddu    $a2, $s0, $zero
/* 8336E4 80241EE4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8336E8 80241EE8 4600B587 */  neg.s     $f22, $f22
/* 8336EC 80241EEC 4405A000 */  mfc1      $a1, $f20
/* 8336F0 80241EF0 4406B000 */  mfc1      $a2, $f22
/* 8336F4 80241EF4 0C019E40 */  jal       guTranslateF
/* 8336F8 80241EF8 00A0382D */   daddu    $a3, $a1, $zero
/* 8336FC 80241EFC 27A40010 */  addiu     $a0, $sp, 0x10
/* 833700 80241F00 0200282D */  daddu     $a1, $s0, $zero
/* 833704 80241F04 0C019D80 */  jal       guMtxCatF
/* 833708 80241F08 00A0302D */   daddu    $a2, $a1, $zero
.L80241F0C:
/* 83370C 80241F0C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 833710 80241F10 8FB20058 */  lw        $s2, 0x58($sp)
/* 833714 80241F14 8FB10054 */  lw        $s1, 0x54($sp)
/* 833718 80241F18 8FB00050 */  lw        $s0, 0x50($sp)
/* 83371C 80241F1C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 833720 80241F20 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 833724 80241F24 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 833728 80241F28 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 83372C 80241F2C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 833730 80241F30 24020002 */  addiu     $v0, $zero, 2
/* 833734 80241F34 03E00008 */  jr        $ra
/* 833738 80241F38 27BD0088 */   addiu    $sp, $sp, 0x88
/* 83373C 80241F3C 00000000 */  nop       
