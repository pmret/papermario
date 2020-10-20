.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241050_B5A8C0
/* B5A8C0 80241050 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B5A8C4 80241054 AFB10054 */  sw        $s1, 0x54($sp)
/* B5A8C8 80241058 0080882D */  daddu     $s1, $a0, $zero
/* B5A8CC 8024105C AFBF005C */  sw        $ra, 0x5c($sp)
/* B5A8D0 80241060 AFB20058 */  sw        $s2, 0x58($sp)
/* B5A8D4 80241064 AFB00050 */  sw        $s0, 0x50($sp)
/* B5A8D8 80241068 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B5A8DC 8024106C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B5A8E0 80241070 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B5A8E4 80241074 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B5A8E8 80241078 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B5A8EC 8024107C 8E30000C */  lw        $s0, 0xc($s1)
/* B5A8F0 80241080 8E050000 */  lw        $a1, ($s0)
/* B5A8F4 80241084 0C0B1EAF */  jal       get_variable
/* B5A8F8 80241088 26100004 */   addiu    $s0, $s0, 4
/* B5A8FC 8024108C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B5A900 80241090 0040202D */   daddu    $a0, $v0, $zero
/* B5A904 80241094 8E050000 */  lw        $a1, ($s0)
/* B5A908 80241098 26100004 */  addiu     $s0, $s0, 4
/* B5A90C 8024109C 0220202D */  daddu     $a0, $s1, $zero
/* B5A910 802410A0 0C0B210B */  jal       get_float_variable
/* B5A914 802410A4 0040902D */   daddu    $s2, $v0, $zero
/* B5A918 802410A8 8E050000 */  lw        $a1, ($s0)
/* B5A91C 802410AC 26100004 */  addiu     $s0, $s0, 4
/* B5A920 802410B0 0220202D */  daddu     $a0, $s1, $zero
/* B5A924 802410B4 0C0B210B */  jal       get_float_variable
/* B5A928 802410B8 46000706 */   mov.s    $f28, $f0
/* B5A92C 802410BC 8E050000 */  lw        $a1, ($s0)
/* B5A930 802410C0 26100004 */  addiu     $s0, $s0, 4
/* B5A934 802410C4 0220202D */  daddu     $a0, $s1, $zero
/* B5A938 802410C8 0C0B210B */  jal       get_float_variable
/* B5A93C 802410CC 46000686 */   mov.s    $f26, $f0
/* B5A940 802410D0 0220202D */  daddu     $a0, $s1, $zero
/* B5A944 802410D4 8E050000 */  lw        $a1, ($s0)
/* B5A948 802410D8 0C0B210B */  jal       get_float_variable
/* B5A94C 802410DC 46000586 */   mov.s    $f22, $f0
/* B5A950 802410E0 0240202D */  daddu     $a0, $s2, $zero
/* B5A954 802410E4 0C046B4C */  jal       get_model_from_list_index
/* B5A958 802410E8 46000606 */   mov.s    $f24, $f0
/* B5A95C 802410EC 0040882D */  daddu     $s1, $v0, $zero
/* B5A960 802410F0 96220000 */  lhu       $v0, ($s1)
/* B5A964 802410F4 30420400 */  andi      $v0, $v0, 0x400
/* B5A968 802410F8 1440001E */  bnez      $v0, .L80241174
/* B5A96C 802410FC 26300058 */   addiu    $s0, $s1, 0x58
/* B5A970 80241100 4480A000 */  mtc1      $zero, $f20
/* B5A974 80241104 4406B000 */  mfc1      $a2, $f22
/* B5A978 80241108 4405A000 */  mfc1      $a1, $f20
/* B5A97C 8024110C 4407A000 */  mfc1      $a3, $f20
/* B5A980 80241110 0C019E40 */  jal       guTranslateF
/* B5A984 80241114 0200202D */   daddu    $a0, $s0, $zero
/* B5A988 80241118 4405E000 */  mfc1      $a1, $f28
/* B5A98C 8024111C 4406D000 */  mfc1      $a2, $f26
/* B5A990 80241120 4407C000 */  mfc1      $a3, $f24
/* B5A994 80241124 0C0903F8 */  jal       func_80240FE0
/* B5A998 80241128 27A40010 */   addiu    $a0, $sp, 0x10
/* B5A99C 8024112C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A9A0 80241130 0200282D */  daddu     $a1, $s0, $zero
/* B5A9A4 80241134 0C019D80 */  jal       guMtxCatF
/* B5A9A8 80241138 0200302D */   daddu    $a2, $s0, $zero
/* B5A9AC 8024113C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A9B0 80241140 4600B587 */  neg.s     $f22, $f22
/* B5A9B4 80241144 4405A000 */  mfc1      $a1, $f20
/* B5A9B8 80241148 4406B000 */  mfc1      $a2, $f22
/* B5A9BC 8024114C 0C019E40 */  jal       guTranslateF
/* B5A9C0 80241150 00A0382D */   daddu    $a3, $a1, $zero
/* B5A9C4 80241154 27A40010 */  addiu     $a0, $sp, 0x10
/* B5A9C8 80241158 0200282D */  daddu     $a1, $s0, $zero
/* B5A9CC 8024115C 0C019D80 */  jal       guMtxCatF
/* B5A9D0 80241160 00A0302D */   daddu    $a2, $a1, $zero
/* B5A9D4 80241164 96220000 */  lhu       $v0, ($s1)
/* B5A9D8 80241168 34421400 */  ori       $v0, $v0, 0x1400
/* B5A9DC 8024116C 0809047B */  j         .L802411EC
/* B5A9E0 80241170 A6220000 */   sh       $v0, ($s1)
.L80241174:
/* B5A9E4 80241174 4480A000 */  mtc1      $zero, $f20
/* B5A9E8 80241178 4406B000 */  mfc1      $a2, $f22
/* B5A9EC 8024117C 4405A000 */  mfc1      $a1, $f20
/* B5A9F0 80241180 4407A000 */  mfc1      $a3, $f20
/* B5A9F4 80241184 0C019E40 */  jal       guTranslateF
/* B5A9F8 80241188 27A40010 */   addiu    $a0, $sp, 0x10
/* B5A9FC 8024118C 27A40010 */  addiu     $a0, $sp, 0x10
/* B5AA00 80241190 26300058 */  addiu     $s0, $s1, 0x58
/* B5AA04 80241194 0200282D */  daddu     $a1, $s0, $zero
/* B5AA08 80241198 0C019D80 */  jal       guMtxCatF
/* B5AA0C 8024119C 0200302D */   daddu    $a2, $s0, $zero
/* B5AA10 802411A0 4405E000 */  mfc1      $a1, $f28
/* B5AA14 802411A4 4406D000 */  mfc1      $a2, $f26
/* B5AA18 802411A8 4407C000 */  mfc1      $a3, $f24
/* B5AA1C 802411AC 0C0903F8 */  jal       func_80240FE0
/* B5AA20 802411B0 27A40010 */   addiu    $a0, $sp, 0x10
/* B5AA24 802411B4 27A40010 */  addiu     $a0, $sp, 0x10
/* B5AA28 802411B8 0200282D */  daddu     $a1, $s0, $zero
/* B5AA2C 802411BC 0C019D80 */  jal       guMtxCatF
/* B5AA30 802411C0 0200302D */   daddu    $a2, $s0, $zero
/* B5AA34 802411C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B5AA38 802411C8 4600B587 */  neg.s     $f22, $f22
/* B5AA3C 802411CC 4405A000 */  mfc1      $a1, $f20
/* B5AA40 802411D0 4406B000 */  mfc1      $a2, $f22
/* B5AA44 802411D4 0C019E40 */  jal       guTranslateF
/* B5AA48 802411D8 00A0382D */   daddu    $a3, $a1, $zero
/* B5AA4C 802411DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B5AA50 802411E0 0200282D */  daddu     $a1, $s0, $zero
/* B5AA54 802411E4 0C019D80 */  jal       guMtxCatF
/* B5AA58 802411E8 00A0302D */   daddu    $a2, $a1, $zero
.L802411EC:
/* B5AA5C 802411EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B5AA60 802411F0 8FB20058 */  lw        $s2, 0x58($sp)
/* B5AA64 802411F4 8FB10054 */  lw        $s1, 0x54($sp)
/* B5AA68 802411F8 8FB00050 */  lw        $s0, 0x50($sp)
/* B5AA6C 802411FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B5AA70 80241200 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B5AA74 80241204 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B5AA78 80241208 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B5AA7C 8024120C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B5AA80 80241210 24020002 */  addiu     $v0, $zero, 2
/* B5AA84 80241214 03E00008 */  jr        $ra
/* B5AA88 80241218 27BD0088 */   addiu    $sp, $sp, 0x88
/* B5AA8C 8024121C 00000000 */  nop       
