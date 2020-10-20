.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070
/* 8DA170 80240070 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8DA174 80240074 AFB10054 */  sw        $s1, 0x54($sp)
/* 8DA178 80240078 0080882D */  daddu     $s1, $a0, $zero
/* 8DA17C 8024007C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8DA180 80240080 AFB20058 */  sw        $s2, 0x58($sp)
/* 8DA184 80240084 AFB00050 */  sw        $s0, 0x50($sp)
/* 8DA188 80240088 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8DA18C 8024008C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8DA190 80240090 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8DA194 80240094 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8DA198 80240098 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8DA19C 8024009C 8E30000C */  lw        $s0, 0xc($s1)
/* 8DA1A0 802400A0 8E050000 */  lw        $a1, ($s0)
/* 8DA1A4 802400A4 0C0B1EAF */  jal       get_variable
/* 8DA1A8 802400A8 26100004 */   addiu    $s0, $s0, 4
/* 8DA1AC 802400AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8DA1B0 802400B0 0040202D */   daddu    $a0, $v0, $zero
/* 8DA1B4 802400B4 8E050000 */  lw        $a1, ($s0)
/* 8DA1B8 802400B8 26100004 */  addiu     $s0, $s0, 4
/* 8DA1BC 802400BC 0220202D */  daddu     $a0, $s1, $zero
/* 8DA1C0 802400C0 0C0B210B */  jal       get_float_variable
/* 8DA1C4 802400C4 0040902D */   daddu    $s2, $v0, $zero
/* 8DA1C8 802400C8 8E050000 */  lw        $a1, ($s0)
/* 8DA1CC 802400CC 26100004 */  addiu     $s0, $s0, 4
/* 8DA1D0 802400D0 0220202D */  daddu     $a0, $s1, $zero
/* 8DA1D4 802400D4 0C0B210B */  jal       get_float_variable
/* 8DA1D8 802400D8 46000706 */   mov.s    $f28, $f0
/* 8DA1DC 802400DC 8E050000 */  lw        $a1, ($s0)
/* 8DA1E0 802400E0 26100004 */  addiu     $s0, $s0, 4
/* 8DA1E4 802400E4 0220202D */  daddu     $a0, $s1, $zero
/* 8DA1E8 802400E8 0C0B210B */  jal       get_float_variable
/* 8DA1EC 802400EC 46000686 */   mov.s    $f26, $f0
/* 8DA1F0 802400F0 0220202D */  daddu     $a0, $s1, $zero
/* 8DA1F4 802400F4 8E050000 */  lw        $a1, ($s0)
/* 8DA1F8 802400F8 0C0B210B */  jal       get_float_variable
/* 8DA1FC 802400FC 46000586 */   mov.s    $f22, $f0
/* 8DA200 80240100 0240202D */  daddu     $a0, $s2, $zero
/* 8DA204 80240104 0C046B4C */  jal       get_model_from_list_index
/* 8DA208 80240108 46000606 */   mov.s    $f24, $f0
/* 8DA20C 8024010C 0040882D */  daddu     $s1, $v0, $zero
/* 8DA210 80240110 96220000 */  lhu       $v0, ($s1)
/* 8DA214 80240114 30420400 */  andi      $v0, $v0, 0x400
/* 8DA218 80240118 1440001E */  bnez      $v0, .L80240194
/* 8DA21C 8024011C 26300058 */   addiu    $s0, $s1, 0x58
/* 8DA220 80240120 4480A000 */  mtc1      $zero, $f20
/* 8DA224 80240124 4406B000 */  mfc1      $a2, $f22
/* 8DA228 80240128 4405A000 */  mfc1      $a1, $f20
/* 8DA22C 8024012C 4407A000 */  mfc1      $a3, $f20
/* 8DA230 80240130 0C019E40 */  jal       guTranslateF
/* 8DA234 80240134 0200202D */   daddu    $a0, $s0, $zero
/* 8DA238 80240138 4405E000 */  mfc1      $a1, $f28
/* 8DA23C 8024013C 4406D000 */  mfc1      $a2, $f26
/* 8DA240 80240140 4407C000 */  mfc1      $a3, $f24
/* 8DA244 80240144 0C090000 */  jal       func_80240000
/* 8DA248 80240148 27A40010 */   addiu    $a0, $sp, 0x10
/* 8DA24C 8024014C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA250 80240150 0200282D */  daddu     $a1, $s0, $zero
/* 8DA254 80240154 0C019D80 */  jal       guMtxCatF
/* 8DA258 80240158 0200302D */   daddu    $a2, $s0, $zero
/* 8DA25C 8024015C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA260 80240160 4600B587 */  neg.s     $f22, $f22
/* 8DA264 80240164 4405A000 */  mfc1      $a1, $f20
/* 8DA268 80240168 4406B000 */  mfc1      $a2, $f22
/* 8DA26C 8024016C 0C019E40 */  jal       guTranslateF
/* 8DA270 80240170 00A0382D */   daddu    $a3, $a1, $zero
/* 8DA274 80240174 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA278 80240178 0200282D */  daddu     $a1, $s0, $zero
/* 8DA27C 8024017C 0C019D80 */  jal       guMtxCatF
/* 8DA280 80240180 00A0302D */   daddu    $a2, $a1, $zero
/* 8DA284 80240184 96220000 */  lhu       $v0, ($s1)
/* 8DA288 80240188 34421400 */  ori       $v0, $v0, 0x1400
/* 8DA28C 8024018C 08090083 */  j         .L8024020C
/* 8DA290 80240190 A6220000 */   sh       $v0, ($s1)
.L80240194:
/* 8DA294 80240194 4480A000 */  mtc1      $zero, $f20
/* 8DA298 80240198 4406B000 */  mfc1      $a2, $f22
/* 8DA29C 8024019C 4405A000 */  mfc1      $a1, $f20
/* 8DA2A0 802401A0 4407A000 */  mfc1      $a3, $f20
/* 8DA2A4 802401A4 0C019E40 */  jal       guTranslateF
/* 8DA2A8 802401A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8DA2AC 802401AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA2B0 802401B0 26300058 */  addiu     $s0, $s1, 0x58
/* 8DA2B4 802401B4 0200282D */  daddu     $a1, $s0, $zero
/* 8DA2B8 802401B8 0C019D80 */  jal       guMtxCatF
/* 8DA2BC 802401BC 0200302D */   daddu    $a2, $s0, $zero
/* 8DA2C0 802401C0 4405E000 */  mfc1      $a1, $f28
/* 8DA2C4 802401C4 4406D000 */  mfc1      $a2, $f26
/* 8DA2C8 802401C8 4407C000 */  mfc1      $a3, $f24
/* 8DA2CC 802401CC 0C090000 */  jal       func_80240000
/* 8DA2D0 802401D0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8DA2D4 802401D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA2D8 802401D8 0200282D */  daddu     $a1, $s0, $zero
/* 8DA2DC 802401DC 0C019D80 */  jal       guMtxCatF
/* 8DA2E0 802401E0 0200302D */   daddu    $a2, $s0, $zero
/* 8DA2E4 802401E4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA2E8 802401E8 4600B587 */  neg.s     $f22, $f22
/* 8DA2EC 802401EC 4405A000 */  mfc1      $a1, $f20
/* 8DA2F0 802401F0 4406B000 */  mfc1      $a2, $f22
/* 8DA2F4 802401F4 0C019E40 */  jal       guTranslateF
/* 8DA2F8 802401F8 00A0382D */   daddu    $a3, $a1, $zero
/* 8DA2FC 802401FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DA300 80240200 0200282D */  daddu     $a1, $s0, $zero
/* 8DA304 80240204 0C019D80 */  jal       guMtxCatF
/* 8DA308 80240208 00A0302D */   daddu    $a2, $a1, $zero
.L8024020C:
/* 8DA30C 8024020C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8DA310 80240210 8FB20058 */  lw        $s2, 0x58($sp)
/* 8DA314 80240214 8FB10054 */  lw        $s1, 0x54($sp)
/* 8DA318 80240218 8FB00050 */  lw        $s0, 0x50($sp)
/* 8DA31C 8024021C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8DA320 80240220 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8DA324 80240224 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8DA328 80240228 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8DA32C 8024022C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8DA330 80240230 24020002 */  addiu     $v0, $zero, 2
/* 8DA334 80240234 03E00008 */  jr        $ra
/* 8DA338 80240238 27BD0088 */   addiu    $sp, $sp, 0x88
