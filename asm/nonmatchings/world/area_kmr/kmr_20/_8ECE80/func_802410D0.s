.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410D0
/* 8ECEF0 802410D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8ECEF4 802410D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 8ECEF8 802410D8 0080882D */  daddu     $s1, $a0, $zero
/* 8ECEFC 802410DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 8ECF00 802410E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 8ECF04 802410E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 8ECF08 802410E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8ECF0C 802410EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8ECF10 802410F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8ECF14 802410F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8ECF18 802410F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8ECF1C 802410FC 8E30000C */  lw        $s0, 0xc($s1)
/* 8ECF20 80241100 8E050000 */  lw        $a1, ($s0)
/* 8ECF24 80241104 0C0B1EAF */  jal       get_variable
/* 8ECF28 80241108 26100004 */   addiu    $s0, $s0, 4
/* 8ECF2C 8024110C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8ECF30 80241110 0040202D */   daddu    $a0, $v0, $zero
/* 8ECF34 80241114 8E050000 */  lw        $a1, ($s0)
/* 8ECF38 80241118 26100004 */  addiu     $s0, $s0, 4
/* 8ECF3C 8024111C 0220202D */  daddu     $a0, $s1, $zero
/* 8ECF40 80241120 0C0B210B */  jal       get_float_variable
/* 8ECF44 80241124 0040902D */   daddu    $s2, $v0, $zero
/* 8ECF48 80241128 8E050000 */  lw        $a1, ($s0)
/* 8ECF4C 8024112C 26100004 */  addiu     $s0, $s0, 4
/* 8ECF50 80241130 0220202D */  daddu     $a0, $s1, $zero
/* 8ECF54 80241134 0C0B210B */  jal       get_float_variable
/* 8ECF58 80241138 46000706 */   mov.s    $f28, $f0
/* 8ECF5C 8024113C 8E050000 */  lw        $a1, ($s0)
/* 8ECF60 80241140 26100004 */  addiu     $s0, $s0, 4
/* 8ECF64 80241144 0220202D */  daddu     $a0, $s1, $zero
/* 8ECF68 80241148 0C0B210B */  jal       get_float_variable
/* 8ECF6C 8024114C 46000686 */   mov.s    $f26, $f0
/* 8ECF70 80241150 0220202D */  daddu     $a0, $s1, $zero
/* 8ECF74 80241154 8E050000 */  lw        $a1, ($s0)
/* 8ECF78 80241158 0C0B210B */  jal       get_float_variable
/* 8ECF7C 8024115C 46000586 */   mov.s    $f22, $f0
/* 8ECF80 80241160 0240202D */  daddu     $a0, $s2, $zero
/* 8ECF84 80241164 0C046B4C */  jal       get_model_from_list_index
/* 8ECF88 80241168 46000606 */   mov.s    $f24, $f0
/* 8ECF8C 8024116C 0040882D */  daddu     $s1, $v0, $zero
/* 8ECF90 80241170 96220000 */  lhu       $v0, ($s1)
/* 8ECF94 80241174 30420400 */  andi      $v0, $v0, 0x400
/* 8ECF98 80241178 1440001E */  bnez      $v0, .L802411F4
/* 8ECF9C 8024117C 26300058 */   addiu    $s0, $s1, 0x58
/* 8ECFA0 80241180 4480A000 */  mtc1      $zero, $f20
/* 8ECFA4 80241184 4406B000 */  mfc1      $a2, $f22
/* 8ECFA8 80241188 4405A000 */  mfc1      $a1, $f20
/* 8ECFAC 8024118C 4407A000 */  mfc1      $a3, $f20
/* 8ECFB0 80241190 0C019E40 */  jal       guTranslateF
/* 8ECFB4 80241194 0200202D */   daddu    $a0, $s0, $zero
/* 8ECFB8 80241198 4405E000 */  mfc1      $a1, $f28
/* 8ECFBC 8024119C 4406D000 */  mfc1      $a2, $f26
/* 8ECFC0 802411A0 4407C000 */  mfc1      $a3, $f24
/* 8ECFC4 802411A4 0C090418 */  jal       func_80241060
/* 8ECFC8 802411A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ECFCC 802411AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECFD0 802411B0 0200282D */  daddu     $a1, $s0, $zero
/* 8ECFD4 802411B4 0C019D80 */  jal       guMtxCatF
/* 8ECFD8 802411B8 0200302D */   daddu    $a2, $s0, $zero
/* 8ECFDC 802411BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECFE0 802411C0 4600B587 */  neg.s     $f22, $f22
/* 8ECFE4 802411C4 4405A000 */  mfc1      $a1, $f20
/* 8ECFE8 802411C8 4406B000 */  mfc1      $a2, $f22
/* 8ECFEC 802411CC 0C019E40 */  jal       guTranslateF
/* 8ECFF0 802411D0 00A0382D */   daddu    $a3, $a1, $zero
/* 8ECFF4 802411D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ECFF8 802411D8 0200282D */  daddu     $a1, $s0, $zero
/* 8ECFFC 802411DC 0C019D80 */  jal       guMtxCatF
/* 8ED000 802411E0 00A0302D */   daddu    $a2, $a1, $zero
/* 8ED004 802411E4 96220000 */  lhu       $v0, ($s1)
/* 8ED008 802411E8 34421400 */  ori       $v0, $v0, 0x1400
/* 8ED00C 802411EC 0809049B */  j         .L8024126C
/* 8ED010 802411F0 A6220000 */   sh       $v0, ($s1)
.L802411F4:
/* 8ED014 802411F4 4480A000 */  mtc1      $zero, $f20
/* 8ED018 802411F8 4406B000 */  mfc1      $a2, $f22
/* 8ED01C 802411FC 4405A000 */  mfc1      $a1, $f20
/* 8ED020 80241200 4407A000 */  mfc1      $a3, $f20
/* 8ED024 80241204 0C019E40 */  jal       guTranslateF
/* 8ED028 80241208 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ED02C 8024120C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED030 80241210 26300058 */  addiu     $s0, $s1, 0x58
/* 8ED034 80241214 0200282D */  daddu     $a1, $s0, $zero
/* 8ED038 80241218 0C019D80 */  jal       guMtxCatF
/* 8ED03C 8024121C 0200302D */   daddu    $a2, $s0, $zero
/* 8ED040 80241220 4405E000 */  mfc1      $a1, $f28
/* 8ED044 80241224 4406D000 */  mfc1      $a2, $f26
/* 8ED048 80241228 4407C000 */  mfc1      $a3, $f24
/* 8ED04C 8024122C 0C090418 */  jal       func_80241060
/* 8ED050 80241230 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ED054 80241234 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED058 80241238 0200282D */  daddu     $a1, $s0, $zero
/* 8ED05C 8024123C 0C019D80 */  jal       guMtxCatF
/* 8ED060 80241240 0200302D */   daddu    $a2, $s0, $zero
/* 8ED064 80241244 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED068 80241248 4600B587 */  neg.s     $f22, $f22
/* 8ED06C 8024124C 4405A000 */  mfc1      $a1, $f20
/* 8ED070 80241250 4406B000 */  mfc1      $a2, $f22
/* 8ED074 80241254 0C019E40 */  jal       guTranslateF
/* 8ED078 80241258 00A0382D */   daddu    $a3, $a1, $zero
/* 8ED07C 8024125C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED080 80241260 0200282D */  daddu     $a1, $s0, $zero
/* 8ED084 80241264 0C019D80 */  jal       guMtxCatF
/* 8ED088 80241268 00A0302D */   daddu    $a2, $a1, $zero
.L8024126C:
/* 8ED08C 8024126C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8ED090 80241270 8FB20058 */  lw        $s2, 0x58($sp)
/* 8ED094 80241274 8FB10054 */  lw        $s1, 0x54($sp)
/* 8ED098 80241278 8FB00050 */  lw        $s0, 0x50($sp)
/* 8ED09C 8024127C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8ED0A0 80241280 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8ED0A4 80241284 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8ED0A8 80241288 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8ED0AC 8024128C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8ED0B0 80241290 24020002 */  addiu     $v0, $zero, 2
/* 8ED0B4 80241294 03E00008 */  jr        $ra
/* 8ED0B8 80241298 27BD0088 */   addiu    $sp, $sp, 0x88
/* 8ED0BC 8024129C 00000000 */  nop       
