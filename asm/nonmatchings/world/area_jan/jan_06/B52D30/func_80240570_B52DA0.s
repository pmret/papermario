.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240570_B52DA0
/* B52DA0 80240570 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B52DA4 80240574 AFB10054 */  sw        $s1, 0x54($sp)
/* B52DA8 80240578 0080882D */  daddu     $s1, $a0, $zero
/* B52DAC 8024057C AFBF005C */  sw        $ra, 0x5c($sp)
/* B52DB0 80240580 AFB20058 */  sw        $s2, 0x58($sp)
/* B52DB4 80240584 AFB00050 */  sw        $s0, 0x50($sp)
/* B52DB8 80240588 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B52DBC 8024058C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B52DC0 80240590 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B52DC4 80240594 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B52DC8 80240598 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B52DCC 8024059C 8E30000C */  lw        $s0, 0xc($s1)
/* B52DD0 802405A0 8E050000 */  lw        $a1, ($s0)
/* B52DD4 802405A4 0C0B1EAF */  jal       get_variable
/* B52DD8 802405A8 26100004 */   addiu    $s0, $s0, 4
/* B52DDC 802405AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B52DE0 802405B0 0040202D */   daddu    $a0, $v0, $zero
/* B52DE4 802405B4 8E050000 */  lw        $a1, ($s0)
/* B52DE8 802405B8 26100004 */  addiu     $s0, $s0, 4
/* B52DEC 802405BC 0220202D */  daddu     $a0, $s1, $zero
/* B52DF0 802405C0 0C0B210B */  jal       get_float_variable
/* B52DF4 802405C4 0040902D */   daddu    $s2, $v0, $zero
/* B52DF8 802405C8 8E050000 */  lw        $a1, ($s0)
/* B52DFC 802405CC 26100004 */  addiu     $s0, $s0, 4
/* B52E00 802405D0 0220202D */  daddu     $a0, $s1, $zero
/* B52E04 802405D4 0C0B210B */  jal       get_float_variable
/* B52E08 802405D8 46000706 */   mov.s    $f28, $f0
/* B52E0C 802405DC 8E050000 */  lw        $a1, ($s0)
/* B52E10 802405E0 26100004 */  addiu     $s0, $s0, 4
/* B52E14 802405E4 0220202D */  daddu     $a0, $s1, $zero
/* B52E18 802405E8 0C0B210B */  jal       get_float_variable
/* B52E1C 802405EC 46000686 */   mov.s    $f26, $f0
/* B52E20 802405F0 0220202D */  daddu     $a0, $s1, $zero
/* B52E24 802405F4 8E050000 */  lw        $a1, ($s0)
/* B52E28 802405F8 0C0B210B */  jal       get_float_variable
/* B52E2C 802405FC 46000586 */   mov.s    $f22, $f0
/* B52E30 80240600 0240202D */  daddu     $a0, $s2, $zero
/* B52E34 80240604 0C046B4C */  jal       get_model_from_list_index
/* B52E38 80240608 46000606 */   mov.s    $f24, $f0
/* B52E3C 8024060C 0040882D */  daddu     $s1, $v0, $zero
/* B52E40 80240610 96220000 */  lhu       $v0, ($s1)
/* B52E44 80240614 30420400 */  andi      $v0, $v0, 0x400
/* B52E48 80240618 1440001E */  bnez      $v0, .L80240694
/* B52E4C 8024061C 26300058 */   addiu    $s0, $s1, 0x58
/* B52E50 80240620 4480A000 */  mtc1      $zero, $f20
/* B52E54 80240624 4406B000 */  mfc1      $a2, $f22
/* B52E58 80240628 4405A000 */  mfc1      $a1, $f20
/* B52E5C 8024062C 4407A000 */  mfc1      $a3, $f20
/* B52E60 80240630 0C019E40 */  jal       guTranslateF
/* B52E64 80240634 0200202D */   daddu    $a0, $s0, $zero
/* B52E68 80240638 4405E000 */  mfc1      $a1, $f28
/* B52E6C 8024063C 4406D000 */  mfc1      $a2, $f26
/* B52E70 80240640 4407C000 */  mfc1      $a3, $f24
/* B52E74 80240644 0C090140 */  jal       func_80240500_B52D30
/* B52E78 80240648 27A40010 */   addiu    $a0, $sp, 0x10
/* B52E7C 8024064C 27A40010 */  addiu     $a0, $sp, 0x10
/* B52E80 80240650 0200282D */  daddu     $a1, $s0, $zero
/* B52E84 80240654 0C019D80 */  jal       guMtxCatF
/* B52E88 80240658 0200302D */   daddu    $a2, $s0, $zero
/* B52E8C 8024065C 27A40010 */  addiu     $a0, $sp, 0x10
/* B52E90 80240660 4600B587 */  neg.s     $f22, $f22
/* B52E94 80240664 4405A000 */  mfc1      $a1, $f20
/* B52E98 80240668 4406B000 */  mfc1      $a2, $f22
/* B52E9C 8024066C 0C019E40 */  jal       guTranslateF
/* B52EA0 80240670 00A0382D */   daddu    $a3, $a1, $zero
/* B52EA4 80240674 27A40010 */  addiu     $a0, $sp, 0x10
/* B52EA8 80240678 0200282D */  daddu     $a1, $s0, $zero
/* B52EAC 8024067C 0C019D80 */  jal       guMtxCatF
/* B52EB0 80240680 00A0302D */   daddu    $a2, $a1, $zero
/* B52EB4 80240684 96220000 */  lhu       $v0, ($s1)
/* B52EB8 80240688 34421400 */  ori       $v0, $v0, 0x1400
/* B52EBC 8024068C 080901C3 */  j         .L8024070C
/* B52EC0 80240690 A6220000 */   sh       $v0, ($s1)
.L80240694:
/* B52EC4 80240694 4480A000 */  mtc1      $zero, $f20
/* B52EC8 80240698 4406B000 */  mfc1      $a2, $f22
/* B52ECC 8024069C 4405A000 */  mfc1      $a1, $f20
/* B52ED0 802406A0 4407A000 */  mfc1      $a3, $f20
/* B52ED4 802406A4 0C019E40 */  jal       guTranslateF
/* B52ED8 802406A8 27A40010 */   addiu    $a0, $sp, 0x10
/* B52EDC 802406AC 27A40010 */  addiu     $a0, $sp, 0x10
/* B52EE0 802406B0 26300058 */  addiu     $s0, $s1, 0x58
/* B52EE4 802406B4 0200282D */  daddu     $a1, $s0, $zero
/* B52EE8 802406B8 0C019D80 */  jal       guMtxCatF
/* B52EEC 802406BC 0200302D */   daddu    $a2, $s0, $zero
/* B52EF0 802406C0 4405E000 */  mfc1      $a1, $f28
/* B52EF4 802406C4 4406D000 */  mfc1      $a2, $f26
/* B52EF8 802406C8 4407C000 */  mfc1      $a3, $f24
/* B52EFC 802406CC 0C090140 */  jal       func_80240500_B52D30
/* B52F00 802406D0 27A40010 */   addiu    $a0, $sp, 0x10
/* B52F04 802406D4 27A40010 */  addiu     $a0, $sp, 0x10
/* B52F08 802406D8 0200282D */  daddu     $a1, $s0, $zero
/* B52F0C 802406DC 0C019D80 */  jal       guMtxCatF
/* B52F10 802406E0 0200302D */   daddu    $a2, $s0, $zero
/* B52F14 802406E4 27A40010 */  addiu     $a0, $sp, 0x10
/* B52F18 802406E8 4600B587 */  neg.s     $f22, $f22
/* B52F1C 802406EC 4405A000 */  mfc1      $a1, $f20
/* B52F20 802406F0 4406B000 */  mfc1      $a2, $f22
/* B52F24 802406F4 0C019E40 */  jal       guTranslateF
/* B52F28 802406F8 00A0382D */   daddu    $a3, $a1, $zero
/* B52F2C 802406FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B52F30 80240700 0200282D */  daddu     $a1, $s0, $zero
/* B52F34 80240704 0C019D80 */  jal       guMtxCatF
/* B52F38 80240708 00A0302D */   daddu    $a2, $a1, $zero
.L8024070C:
/* B52F3C 8024070C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B52F40 80240710 8FB20058 */  lw        $s2, 0x58($sp)
/* B52F44 80240714 8FB10054 */  lw        $s1, 0x54($sp)
/* B52F48 80240718 8FB00050 */  lw        $s0, 0x50($sp)
/* B52F4C 8024071C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B52F50 80240720 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B52F54 80240724 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B52F58 80240728 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B52F5C 8024072C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B52F60 80240730 24020002 */  addiu     $v0, $zero, 2
/* B52F64 80240734 03E00008 */  jr        $ra
/* B52F68 80240738 27BD0088 */   addiu    $sp, $sp, 0x88
/* B52F6C 8024073C 00000000 */  nop       
