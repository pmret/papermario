.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241750_B67200
/* B67200 80241750 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B67204 80241754 AFB10054 */  sw        $s1, 0x54($sp)
/* B67208 80241758 0080882D */  daddu     $s1, $a0, $zero
/* B6720C 8024175C AFBF005C */  sw        $ra, 0x5c($sp)
/* B67210 80241760 AFB20058 */  sw        $s2, 0x58($sp)
/* B67214 80241764 AFB00050 */  sw        $s0, 0x50($sp)
/* B67218 80241768 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B6721C 8024176C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B67220 80241770 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B67224 80241774 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B67228 80241778 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B6722C 8024177C 8E30000C */  lw        $s0, 0xc($s1)
/* B67230 80241780 8E050000 */  lw        $a1, ($s0)
/* B67234 80241784 0C0B1EAF */  jal       get_variable
/* B67238 80241788 26100004 */   addiu    $s0, $s0, 4
/* B6723C 8024178C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B67240 80241790 0040202D */   daddu    $a0, $v0, $zero
/* B67244 80241794 8E050000 */  lw        $a1, ($s0)
/* B67248 80241798 26100004 */  addiu     $s0, $s0, 4
/* B6724C 8024179C 0220202D */  daddu     $a0, $s1, $zero
/* B67250 802417A0 0C0B210B */  jal       get_float_variable
/* B67254 802417A4 0040902D */   daddu    $s2, $v0, $zero
/* B67258 802417A8 8E050000 */  lw        $a1, ($s0)
/* B6725C 802417AC 26100004 */  addiu     $s0, $s0, 4
/* B67260 802417B0 0220202D */  daddu     $a0, $s1, $zero
/* B67264 802417B4 0C0B210B */  jal       get_float_variable
/* B67268 802417B8 46000706 */   mov.s    $f28, $f0
/* B6726C 802417BC 8E050000 */  lw        $a1, ($s0)
/* B67270 802417C0 26100004 */  addiu     $s0, $s0, 4
/* B67274 802417C4 0220202D */  daddu     $a0, $s1, $zero
/* B67278 802417C8 0C0B210B */  jal       get_float_variable
/* B6727C 802417CC 46000686 */   mov.s    $f26, $f0
/* B67280 802417D0 0220202D */  daddu     $a0, $s1, $zero
/* B67284 802417D4 8E050000 */  lw        $a1, ($s0)
/* B67288 802417D8 0C0B210B */  jal       get_float_variable
/* B6728C 802417DC 46000586 */   mov.s    $f22, $f0
/* B67290 802417E0 0240202D */  daddu     $a0, $s2, $zero
/* B67294 802417E4 0C046B4C */  jal       get_model_from_list_index
/* B67298 802417E8 46000606 */   mov.s    $f24, $f0
/* B6729C 802417EC 0040882D */  daddu     $s1, $v0, $zero
/* B672A0 802417F0 96220000 */  lhu       $v0, ($s1)
/* B672A4 802417F4 30420400 */  andi      $v0, $v0, 0x400
/* B672A8 802417F8 1440001E */  bnez      $v0, .L80241874
/* B672AC 802417FC 26300058 */   addiu    $s0, $s1, 0x58
/* B672B0 80241800 4480A000 */  mtc1      $zero, $f20
/* B672B4 80241804 4406B000 */  mfc1      $a2, $f22
/* B672B8 80241808 4405A000 */  mfc1      $a1, $f20
/* B672BC 8024180C 4407A000 */  mfc1      $a3, $f20
/* B672C0 80241810 0C019E40 */  jal       guTranslateF
/* B672C4 80241814 0200202D */   daddu    $a0, $s0, $zero
/* B672C8 80241818 4405E000 */  mfc1      $a1, $f28
/* B672CC 8024181C 4406D000 */  mfc1      $a2, $f26
/* B672D0 80241820 4407C000 */  mfc1      $a3, $f24
/* B672D4 80241824 0C0905B8 */  jal       func_802416E0_B67190
/* B672D8 80241828 27A40010 */   addiu    $a0, $sp, 0x10
/* B672DC 8024182C 27A40010 */  addiu     $a0, $sp, 0x10
/* B672E0 80241830 0200282D */  daddu     $a1, $s0, $zero
/* B672E4 80241834 0C019D80 */  jal       guMtxCatF
/* B672E8 80241838 0200302D */   daddu    $a2, $s0, $zero
/* B672EC 8024183C 27A40010 */  addiu     $a0, $sp, 0x10
/* B672F0 80241840 4600B587 */  neg.s     $f22, $f22
/* B672F4 80241844 4405A000 */  mfc1      $a1, $f20
/* B672F8 80241848 4406B000 */  mfc1      $a2, $f22
/* B672FC 8024184C 0C019E40 */  jal       guTranslateF
/* B67300 80241850 00A0382D */   daddu    $a3, $a1, $zero
/* B67304 80241854 27A40010 */  addiu     $a0, $sp, 0x10
/* B67308 80241858 0200282D */  daddu     $a1, $s0, $zero
/* B6730C 8024185C 0C019D80 */  jal       guMtxCatF
/* B67310 80241860 00A0302D */   daddu    $a2, $a1, $zero
/* B67314 80241864 96220000 */  lhu       $v0, ($s1)
/* B67318 80241868 34421400 */  ori       $v0, $v0, 0x1400
/* B6731C 8024186C 0809063B */  j         .L802418EC
/* B67320 80241870 A6220000 */   sh       $v0, ($s1)
.L80241874:
/* B67324 80241874 4480A000 */  mtc1      $zero, $f20
/* B67328 80241878 4406B000 */  mfc1      $a2, $f22
/* B6732C 8024187C 4405A000 */  mfc1      $a1, $f20
/* B67330 80241880 4407A000 */  mfc1      $a3, $f20
/* B67334 80241884 0C019E40 */  jal       guTranslateF
/* B67338 80241888 27A40010 */   addiu    $a0, $sp, 0x10
/* B6733C 8024188C 27A40010 */  addiu     $a0, $sp, 0x10
/* B67340 80241890 26300058 */  addiu     $s0, $s1, 0x58
/* B67344 80241894 0200282D */  daddu     $a1, $s0, $zero
/* B67348 80241898 0C019D80 */  jal       guMtxCatF
/* B6734C 8024189C 0200302D */   daddu    $a2, $s0, $zero
/* B67350 802418A0 4405E000 */  mfc1      $a1, $f28
/* B67354 802418A4 4406D000 */  mfc1      $a2, $f26
/* B67358 802418A8 4407C000 */  mfc1      $a3, $f24
/* B6735C 802418AC 0C0905B8 */  jal       func_802416E0_B67190
/* B67360 802418B0 27A40010 */   addiu    $a0, $sp, 0x10
/* B67364 802418B4 27A40010 */  addiu     $a0, $sp, 0x10
/* B67368 802418B8 0200282D */  daddu     $a1, $s0, $zero
/* B6736C 802418BC 0C019D80 */  jal       guMtxCatF
/* B67370 802418C0 0200302D */   daddu    $a2, $s0, $zero
/* B67374 802418C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B67378 802418C8 4600B587 */  neg.s     $f22, $f22
/* B6737C 802418CC 4405A000 */  mfc1      $a1, $f20
/* B67380 802418D0 4406B000 */  mfc1      $a2, $f22
/* B67384 802418D4 0C019E40 */  jal       guTranslateF
/* B67388 802418D8 00A0382D */   daddu    $a3, $a1, $zero
/* B6738C 802418DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B67390 802418E0 0200282D */  daddu     $a1, $s0, $zero
/* B67394 802418E4 0C019D80 */  jal       guMtxCatF
/* B67398 802418E8 00A0302D */   daddu    $a2, $a1, $zero
.L802418EC:
/* B6739C 802418EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B673A0 802418F0 8FB20058 */  lw        $s2, 0x58($sp)
/* B673A4 802418F4 8FB10054 */  lw        $s1, 0x54($sp)
/* B673A8 802418F8 8FB00050 */  lw        $s0, 0x50($sp)
/* B673AC 802418FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B673B0 80241900 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B673B4 80241904 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B673B8 80241908 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B673BC 8024190C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B673C0 80241910 24020002 */  addiu     $v0, $zero, 2
/* B673C4 80241914 03E00008 */  jr        $ra
/* B673C8 80241918 27BD0088 */   addiu    $sp, $sp, 0x88
/* B673CC 8024191C 00000000 */  nop       
