.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241790_B85910
/* B85910 80241790 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B85914 80241794 AFB10054 */  sw        $s1, 0x54($sp)
/* B85918 80241798 0080882D */  daddu     $s1, $a0, $zero
/* B8591C 8024179C AFBF005C */  sw        $ra, 0x5c($sp)
/* B85920 802417A0 AFB20058 */  sw        $s2, 0x58($sp)
/* B85924 802417A4 AFB00050 */  sw        $s0, 0x50($sp)
/* B85928 802417A8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B8592C 802417AC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B85930 802417B0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B85934 802417B4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B85938 802417B8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B8593C 802417BC 8E30000C */  lw        $s0, 0xc($s1)
/* B85940 802417C0 8E050000 */  lw        $a1, ($s0)
/* B85944 802417C4 0C0B1EAF */  jal       get_variable
/* B85948 802417C8 26100004 */   addiu    $s0, $s0, 4
/* B8594C 802417CC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B85950 802417D0 0040202D */   daddu    $a0, $v0, $zero
/* B85954 802417D4 8E050000 */  lw        $a1, ($s0)
/* B85958 802417D8 26100004 */  addiu     $s0, $s0, 4
/* B8595C 802417DC 0220202D */  daddu     $a0, $s1, $zero
/* B85960 802417E0 0C0B210B */  jal       get_float_variable
/* B85964 802417E4 0040902D */   daddu    $s2, $v0, $zero
/* B85968 802417E8 8E050000 */  lw        $a1, ($s0)
/* B8596C 802417EC 26100004 */  addiu     $s0, $s0, 4
/* B85970 802417F0 0220202D */  daddu     $a0, $s1, $zero
/* B85974 802417F4 0C0B210B */  jal       get_float_variable
/* B85978 802417F8 46000706 */   mov.s    $f28, $f0
/* B8597C 802417FC 8E050000 */  lw        $a1, ($s0)
/* B85980 80241800 26100004 */  addiu     $s0, $s0, 4
/* B85984 80241804 0220202D */  daddu     $a0, $s1, $zero
/* B85988 80241808 0C0B210B */  jal       get_float_variable
/* B8598C 8024180C 46000686 */   mov.s    $f26, $f0
/* B85990 80241810 0220202D */  daddu     $a0, $s1, $zero
/* B85994 80241814 8E050000 */  lw        $a1, ($s0)
/* B85998 80241818 0C0B210B */  jal       get_float_variable
/* B8599C 8024181C 46000586 */   mov.s    $f22, $f0
/* B859A0 80241820 0240202D */  daddu     $a0, $s2, $zero
/* B859A4 80241824 0C046B4C */  jal       get_model_from_list_index
/* B859A8 80241828 46000606 */   mov.s    $f24, $f0
/* B859AC 8024182C 0040882D */  daddu     $s1, $v0, $zero
/* B859B0 80241830 96220000 */  lhu       $v0, ($s1)
/* B859B4 80241834 30420400 */  andi      $v0, $v0, 0x400
/* B859B8 80241838 1440001E */  bnez      $v0, .L802418B4
/* B859BC 8024183C 26300058 */   addiu    $s0, $s1, 0x58
/* B859C0 80241840 4480A000 */  mtc1      $zero, $f20
/* B859C4 80241844 4406B000 */  mfc1      $a2, $f22
/* B859C8 80241848 4405A000 */  mfc1      $a1, $f20
/* B859CC 8024184C 4407A000 */  mfc1      $a3, $f20
/* B859D0 80241850 0C019E40 */  jal       guTranslateF
/* B859D4 80241854 0200202D */   daddu    $a0, $s0, $zero
/* B859D8 80241858 4405E000 */  mfc1      $a1, $f28
/* B859DC 8024185C 4406D000 */  mfc1      $a2, $f26
/* B859E0 80241860 4407C000 */  mfc1      $a3, $f24
/* B859E4 80241864 0C0905C8 */  jal       func_80241720_B858A0
/* B859E8 80241868 27A40010 */   addiu    $a0, $sp, 0x10
/* B859EC 8024186C 27A40010 */  addiu     $a0, $sp, 0x10
/* B859F0 80241870 0200282D */  daddu     $a1, $s0, $zero
/* B859F4 80241874 0C019D80 */  jal       guMtxCatF
/* B859F8 80241878 0200302D */   daddu    $a2, $s0, $zero
/* B859FC 8024187C 27A40010 */  addiu     $a0, $sp, 0x10
/* B85A00 80241880 4600B587 */  neg.s     $f22, $f22
/* B85A04 80241884 4405A000 */  mfc1      $a1, $f20
/* B85A08 80241888 4406B000 */  mfc1      $a2, $f22
/* B85A0C 8024188C 0C019E40 */  jal       guTranslateF
/* B85A10 80241890 00A0382D */   daddu    $a3, $a1, $zero
/* B85A14 80241894 27A40010 */  addiu     $a0, $sp, 0x10
/* B85A18 80241898 0200282D */  daddu     $a1, $s0, $zero
/* B85A1C 8024189C 0C019D80 */  jal       guMtxCatF
/* B85A20 802418A0 00A0302D */   daddu    $a2, $a1, $zero
/* B85A24 802418A4 96220000 */  lhu       $v0, ($s1)
/* B85A28 802418A8 34421400 */  ori       $v0, $v0, 0x1400
/* B85A2C 802418AC 0809064B */  j         .L8024192C
/* B85A30 802418B0 A6220000 */   sh       $v0, ($s1)
.L802418B4:
/* B85A34 802418B4 4480A000 */  mtc1      $zero, $f20
/* B85A38 802418B8 4406B000 */  mfc1      $a2, $f22
/* B85A3C 802418BC 4405A000 */  mfc1      $a1, $f20
/* B85A40 802418C0 4407A000 */  mfc1      $a3, $f20
/* B85A44 802418C4 0C019E40 */  jal       guTranslateF
/* B85A48 802418C8 27A40010 */   addiu    $a0, $sp, 0x10
/* B85A4C 802418CC 27A40010 */  addiu     $a0, $sp, 0x10
/* B85A50 802418D0 26300058 */  addiu     $s0, $s1, 0x58
/* B85A54 802418D4 0200282D */  daddu     $a1, $s0, $zero
/* B85A58 802418D8 0C019D80 */  jal       guMtxCatF
/* B85A5C 802418DC 0200302D */   daddu    $a2, $s0, $zero
/* B85A60 802418E0 4405E000 */  mfc1      $a1, $f28
/* B85A64 802418E4 4406D000 */  mfc1      $a2, $f26
/* B85A68 802418E8 4407C000 */  mfc1      $a3, $f24
/* B85A6C 802418EC 0C0905C8 */  jal       func_80241720_B858A0
/* B85A70 802418F0 27A40010 */   addiu    $a0, $sp, 0x10
/* B85A74 802418F4 27A40010 */  addiu     $a0, $sp, 0x10
/* B85A78 802418F8 0200282D */  daddu     $a1, $s0, $zero
/* B85A7C 802418FC 0C019D80 */  jal       guMtxCatF
/* B85A80 80241900 0200302D */   daddu    $a2, $s0, $zero
/* B85A84 80241904 27A40010 */  addiu     $a0, $sp, 0x10
/* B85A88 80241908 4600B587 */  neg.s     $f22, $f22
/* B85A8C 8024190C 4405A000 */  mfc1      $a1, $f20
/* B85A90 80241910 4406B000 */  mfc1      $a2, $f22
/* B85A94 80241914 0C019E40 */  jal       guTranslateF
/* B85A98 80241918 00A0382D */   daddu    $a3, $a1, $zero
/* B85A9C 8024191C 27A40010 */  addiu     $a0, $sp, 0x10
/* B85AA0 80241920 0200282D */  daddu     $a1, $s0, $zero
/* B85AA4 80241924 0C019D80 */  jal       guMtxCatF
/* B85AA8 80241928 00A0302D */   daddu    $a2, $a1, $zero
.L8024192C:
/* B85AAC 8024192C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B85AB0 80241930 8FB20058 */  lw        $s2, 0x58($sp)
/* B85AB4 80241934 8FB10054 */  lw        $s1, 0x54($sp)
/* B85AB8 80241938 8FB00050 */  lw        $s0, 0x50($sp)
/* B85ABC 8024193C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B85AC0 80241940 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B85AC4 80241944 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B85AC8 80241948 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B85ACC 8024194C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B85AD0 80241950 24020002 */  addiu     $v0, $zero, 2
/* B85AD4 80241954 03E00008 */  jr        $ra
/* B85AD8 80241958 27BD0088 */   addiu    $sp, $sp, 0x88
/* B85ADC 8024195C 00000000 */  nop       
