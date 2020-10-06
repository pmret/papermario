.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ScaleModel
/* ED738 802C8D88 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ED73C 802C8D8C AFB20058 */  sw        $s2, 0x58($sp)
/* ED740 802C8D90 0080902D */  daddu     $s2, $a0, $zero
/* ED744 802C8D94 AFBF005C */  sw        $ra, 0x5c($sp)
/* ED748 802C8D98 AFB10054 */  sw        $s1, 0x54($sp)
/* ED74C 802C8D9C AFB00050 */  sw        $s0, 0x50($sp)
/* ED750 802C8DA0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ED754 802C8DA4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* ED758 802C8DA8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ED75C 802C8DAC 8E50000C */  lw        $s0, 0xc($s2)
/* ED760 802C8DB0 8E050000 */  lw        $a1, ($s0)
/* ED764 802C8DB4 0C0B1EAF */  jal       get_variable
/* ED768 802C8DB8 26100004 */   addiu    $s0, $s0, 4
/* ED76C 802C8DBC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* ED770 802C8DC0 0040202D */   daddu    $a0, $v0, $zero
/* ED774 802C8DC4 8E050000 */  lw        $a1, ($s0)
/* ED778 802C8DC8 26100004 */  addiu     $s0, $s0, 4
/* ED77C 802C8DCC 0240202D */  daddu     $a0, $s2, $zero
/* ED780 802C8DD0 0C0B210B */  jal       get_float_variable
/* ED784 802C8DD4 0040882D */   daddu    $s1, $v0, $zero
/* ED788 802C8DD8 8E050000 */  lw        $a1, ($s0)
/* ED78C 802C8DDC 26100004 */  addiu     $s0, $s0, 4
/* ED790 802C8DE0 0240202D */  daddu     $a0, $s2, $zero
/* ED794 802C8DE4 0C0B210B */  jal       get_float_variable
/* ED798 802C8DE8 46000606 */   mov.s    $f24, $f0
/* ED79C 802C8DEC 0240202D */  daddu     $a0, $s2, $zero
/* ED7A0 802C8DF0 8E050000 */  lw        $a1, ($s0)
/* ED7A4 802C8DF4 0C0B210B */  jal       get_float_variable
/* ED7A8 802C8DF8 46000586 */   mov.s    $f22, $f0
/* ED7AC 802C8DFC 0220202D */  daddu     $a0, $s1, $zero
/* ED7B0 802C8E00 0C046B4C */  jal       get_model_from_list_index
/* ED7B4 802C8E04 46000506 */   mov.s    $f20, $f0
/* ED7B8 802C8E08 0040802D */  daddu     $s0, $v0, $zero
/* ED7BC 802C8E0C 96020000 */  lhu       $v0, ($s0)
/* ED7C0 802C8E10 30420400 */  andi      $v0, $v0, 0x400
/* ED7C4 802C8E14 1440000A */  bnez      $v0, .L802C8E40
/* ED7C8 802C8E18 00000000 */   nop      
/* ED7CC 802C8E1C 4405C000 */  mfc1      $a1, $f24
/* ED7D0 802C8E20 4406B000 */  mfc1      $a2, $f22
/* ED7D4 802C8E24 4407A000 */  mfc1      $a3, $f20
/* ED7D8 802C8E28 0C019DF0 */  jal       guScaleF
/* ED7DC 802C8E2C 26040058 */   addiu    $a0, $s0, 0x58
/* ED7E0 802C8E30 96020000 */  lhu       $v0, ($s0)
/* ED7E4 802C8E34 34421400 */  ori       $v0, $v0, 0x1400
/* ED7E8 802C8E38 080B2399 */  j         .L802C8E64
/* ED7EC 802C8E3C A6020000 */   sh       $v0, ($s0)
.L802C8E40:
/* ED7F0 802C8E40 4405C000 */  mfc1      $a1, $f24
/* ED7F4 802C8E44 4406B000 */  mfc1      $a2, $f22
/* ED7F8 802C8E48 4407A000 */  mfc1      $a3, $f20
/* ED7FC 802C8E4C 0C019DF0 */  jal       guScaleF
/* ED800 802C8E50 27A40010 */   addiu    $a0, $sp, 0x10
/* ED804 802C8E54 27A40010 */  addiu     $a0, $sp, 0x10
/* ED808 802C8E58 26050058 */  addiu     $a1, $s0, 0x58
/* ED80C 802C8E5C 0C019D80 */  jal       guMtxCatF
/* ED810 802C8E60 00A0302D */   daddu    $a2, $a1, $zero
.L802C8E64:
/* ED814 802C8E64 8FBF005C */  lw        $ra, 0x5c($sp)
/* ED818 802C8E68 8FB20058 */  lw        $s2, 0x58($sp)
/* ED81C 802C8E6C 8FB10054 */  lw        $s1, 0x54($sp)
/* ED820 802C8E70 8FB00050 */  lw        $s0, 0x50($sp)
/* ED824 802C8E74 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ED828 802C8E78 D7B60068 */  ldc1      $f22, 0x68($sp)
/* ED82C 802C8E7C D7B40060 */  ldc1      $f20, 0x60($sp)
/* ED830 802C8E80 24020002 */  addiu     $v0, $zero, 2
/* ED834 802C8E84 03E00008 */  jr        $ra
/* ED838 802C8E88 27BD0078 */   addiu    $sp, $sp, 0x78
