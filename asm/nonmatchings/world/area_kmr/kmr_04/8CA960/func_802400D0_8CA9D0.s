.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D0_8CA9D0
/* 8CA9D0 802400D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8CA9D4 802400D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 8CA9D8 802400D8 0080882D */  daddu     $s1, $a0, $zero
/* 8CA9DC 802400DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 8CA9E0 802400E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 8CA9E4 802400E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 8CA9E8 802400E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8CA9EC 802400EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8CA9F0 802400F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8CA9F4 802400F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8CA9F8 802400F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8CA9FC 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* 8CAA00 80240100 8E050000 */  lw        $a1, ($s0)
/* 8CAA04 80240104 0C0B1EAF */  jal       get_variable
/* 8CAA08 80240108 26100004 */   addiu    $s0, $s0, 4
/* 8CAA0C 8024010C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8CAA10 80240110 0040202D */   daddu    $a0, $v0, $zero
/* 8CAA14 80240114 8E050000 */  lw        $a1, ($s0)
/* 8CAA18 80240118 26100004 */  addiu     $s0, $s0, 4
/* 8CAA1C 8024011C 0220202D */  daddu     $a0, $s1, $zero
/* 8CAA20 80240120 0C0B210B */  jal       get_float_variable
/* 8CAA24 80240124 0040902D */   daddu    $s2, $v0, $zero
/* 8CAA28 80240128 8E050000 */  lw        $a1, ($s0)
/* 8CAA2C 8024012C 26100004 */  addiu     $s0, $s0, 4
/* 8CAA30 80240130 0220202D */  daddu     $a0, $s1, $zero
/* 8CAA34 80240134 0C0B210B */  jal       get_float_variable
/* 8CAA38 80240138 46000706 */   mov.s    $f28, $f0
/* 8CAA3C 8024013C 8E050000 */  lw        $a1, ($s0)
/* 8CAA40 80240140 26100004 */  addiu     $s0, $s0, 4
/* 8CAA44 80240144 0220202D */  daddu     $a0, $s1, $zero
/* 8CAA48 80240148 0C0B210B */  jal       get_float_variable
/* 8CAA4C 8024014C 46000686 */   mov.s    $f26, $f0
/* 8CAA50 80240150 0220202D */  daddu     $a0, $s1, $zero
/* 8CAA54 80240154 8E050000 */  lw        $a1, ($s0)
/* 8CAA58 80240158 0C0B210B */  jal       get_float_variable
/* 8CAA5C 8024015C 46000586 */   mov.s    $f22, $f0
/* 8CAA60 80240160 0240202D */  daddu     $a0, $s2, $zero
/* 8CAA64 80240164 0C046B4C */  jal       get_model_from_list_index
/* 8CAA68 80240168 46000606 */   mov.s    $f24, $f0
/* 8CAA6C 8024016C 0040882D */  daddu     $s1, $v0, $zero
/* 8CAA70 80240170 96220000 */  lhu       $v0, ($s1)
/* 8CAA74 80240174 30420400 */  andi      $v0, $v0, 0x400
/* 8CAA78 80240178 1440001E */  bnez      $v0, .L802401F4
/* 8CAA7C 8024017C 26300058 */   addiu    $s0, $s1, 0x58
/* 8CAA80 80240180 4480A000 */  mtc1      $zero, $f20
/* 8CAA84 80240184 4406B000 */  mfc1      $a2, $f22
/* 8CAA88 80240188 4405A000 */  mfc1      $a1, $f20
/* 8CAA8C 8024018C 4407A000 */  mfc1      $a3, $f20
/* 8CAA90 80240190 0C019E40 */  jal       guTranslateF
/* 8CAA94 80240194 0200202D */   daddu    $a0, $s0, $zero
/* 8CAA98 80240198 4405E000 */  mfc1      $a1, $f28
/* 8CAA9C 8024019C 4406D000 */  mfc1      $a2, $f26
/* 8CAAA0 802401A0 4407C000 */  mfc1      $a3, $f24
/* 8CAAA4 802401A4 0C090018 */  jal       func_80240060_8CA960
/* 8CAAA8 802401A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8CAAAC 802401AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAAB0 802401B0 0200282D */  daddu     $a1, $s0, $zero
/* 8CAAB4 802401B4 0C019D80 */  jal       guMtxCatF
/* 8CAAB8 802401B8 0200302D */   daddu    $a2, $s0, $zero
/* 8CAABC 802401BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAAC0 802401C0 4600B587 */  neg.s     $f22, $f22
/* 8CAAC4 802401C4 4405A000 */  mfc1      $a1, $f20
/* 8CAAC8 802401C8 4406B000 */  mfc1      $a2, $f22
/* 8CAACC 802401CC 0C019E40 */  jal       guTranslateF
/* 8CAAD0 802401D0 00A0382D */   daddu    $a3, $a1, $zero
/* 8CAAD4 802401D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAAD8 802401D8 0200282D */  daddu     $a1, $s0, $zero
/* 8CAADC 802401DC 0C019D80 */  jal       guMtxCatF
/* 8CAAE0 802401E0 00A0302D */   daddu    $a2, $a1, $zero
/* 8CAAE4 802401E4 96220000 */  lhu       $v0, ($s1)
/* 8CAAE8 802401E8 34421400 */  ori       $v0, $v0, 0x1400
/* 8CAAEC 802401EC 0809009B */  j         .L8024026C
/* 8CAAF0 802401F0 A6220000 */   sh       $v0, ($s1)
.L802401F4:
/* 8CAAF4 802401F4 4480A000 */  mtc1      $zero, $f20
/* 8CAAF8 802401F8 4406B000 */  mfc1      $a2, $f22
/* 8CAAFC 802401FC 4405A000 */  mfc1      $a1, $f20
/* 8CAB00 80240200 4407A000 */  mfc1      $a3, $f20
/* 8CAB04 80240204 0C019E40 */  jal       guTranslateF
/* 8CAB08 80240208 27A40010 */   addiu    $a0, $sp, 0x10
/* 8CAB0C 8024020C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAB10 80240210 26300058 */  addiu     $s0, $s1, 0x58
/* 8CAB14 80240214 0200282D */  daddu     $a1, $s0, $zero
/* 8CAB18 80240218 0C019D80 */  jal       guMtxCatF
/* 8CAB1C 8024021C 0200302D */   daddu    $a2, $s0, $zero
/* 8CAB20 80240220 4405E000 */  mfc1      $a1, $f28
/* 8CAB24 80240224 4406D000 */  mfc1      $a2, $f26
/* 8CAB28 80240228 4407C000 */  mfc1      $a3, $f24
/* 8CAB2C 8024022C 0C090018 */  jal       func_80240060_8CA960
/* 8CAB30 80240230 27A40010 */   addiu    $a0, $sp, 0x10
/* 8CAB34 80240234 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAB38 80240238 0200282D */  daddu     $a1, $s0, $zero
/* 8CAB3C 8024023C 0C019D80 */  jal       guMtxCatF
/* 8CAB40 80240240 0200302D */   daddu    $a2, $s0, $zero
/* 8CAB44 80240244 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAB48 80240248 4600B587 */  neg.s     $f22, $f22
/* 8CAB4C 8024024C 4405A000 */  mfc1      $a1, $f20
/* 8CAB50 80240250 4406B000 */  mfc1      $a2, $f22
/* 8CAB54 80240254 0C019E40 */  jal       guTranslateF
/* 8CAB58 80240258 00A0382D */   daddu    $a3, $a1, $zero
/* 8CAB5C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8CAB60 80240260 0200282D */  daddu     $a1, $s0, $zero
/* 8CAB64 80240264 0C019D80 */  jal       guMtxCatF
/* 8CAB68 80240268 00A0302D */   daddu    $a2, $a1, $zero
.L8024026C:
/* 8CAB6C 8024026C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8CAB70 80240270 8FB20058 */  lw        $s2, 0x58($sp)
/* 8CAB74 80240274 8FB10054 */  lw        $s1, 0x54($sp)
/* 8CAB78 80240278 8FB00050 */  lw        $s0, 0x50($sp)
/* 8CAB7C 8024027C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8CAB80 80240280 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8CAB84 80240284 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8CAB88 80240288 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8CAB8C 8024028C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8CAB90 80240290 24020002 */  addiu     $v0, $zero, 2
/* 8CAB94 80240294 03E00008 */  jr        $ra
/* 8CAB98 80240298 27BD0088 */   addiu    $sp, $sp, 0x88
