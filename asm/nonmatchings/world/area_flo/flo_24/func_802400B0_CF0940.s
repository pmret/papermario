.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_CF09F0
/* CF09F0 802400B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CF09F4 802400B4 AFB10054 */  sw        $s1, 0x54($sp)
/* CF09F8 802400B8 0080882D */  daddu     $s1, $a0, $zero
/* CF09FC 802400BC AFBF005C */  sw        $ra, 0x5c($sp)
/* CF0A00 802400C0 AFB20058 */  sw        $s2, 0x58($sp)
/* CF0A04 802400C4 AFB00050 */  sw        $s0, 0x50($sp)
/* CF0A08 802400C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CF0A0C 802400CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CF0A10 802400D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CF0A14 802400D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CF0A18 802400D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CF0A1C 802400DC 8E30000C */  lw        $s0, 0xc($s1)
/* CF0A20 802400E0 8E050000 */  lw        $a1, ($s0)
/* CF0A24 802400E4 0C0B1EAF */  jal       get_variable
/* CF0A28 802400E8 26100004 */   addiu    $s0, $s0, 4
/* CF0A2C 802400EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CF0A30 802400F0 0040202D */   daddu    $a0, $v0, $zero
/* CF0A34 802400F4 8E050000 */  lw        $a1, ($s0)
/* CF0A38 802400F8 26100004 */  addiu     $s0, $s0, 4
/* CF0A3C 802400FC 0220202D */  daddu     $a0, $s1, $zero
/* CF0A40 80240100 0C0B210B */  jal       get_float_variable
/* CF0A44 80240104 0040902D */   daddu    $s2, $v0, $zero
/* CF0A48 80240108 8E050000 */  lw        $a1, ($s0)
/* CF0A4C 8024010C 26100004 */  addiu     $s0, $s0, 4
/* CF0A50 80240110 0220202D */  daddu     $a0, $s1, $zero
/* CF0A54 80240114 0C0B210B */  jal       get_float_variable
/* CF0A58 80240118 46000706 */   mov.s    $f28, $f0
/* CF0A5C 8024011C 8E050000 */  lw        $a1, ($s0)
/* CF0A60 80240120 26100004 */  addiu     $s0, $s0, 4
/* CF0A64 80240124 0220202D */  daddu     $a0, $s1, $zero
/* CF0A68 80240128 0C0B210B */  jal       get_float_variable
/* CF0A6C 8024012C 46000686 */   mov.s    $f26, $f0
/* CF0A70 80240130 0220202D */  daddu     $a0, $s1, $zero
/* CF0A74 80240134 8E050000 */  lw        $a1, ($s0)
/* CF0A78 80240138 0C0B210B */  jal       get_float_variable
/* CF0A7C 8024013C 46000586 */   mov.s    $f22, $f0
/* CF0A80 80240140 0240202D */  daddu     $a0, $s2, $zero
/* CF0A84 80240144 0C046B4C */  jal       get_model_from_list_index
/* CF0A88 80240148 46000606 */   mov.s    $f24, $f0
/* CF0A8C 8024014C 0040882D */  daddu     $s1, $v0, $zero
/* CF0A90 80240150 96220000 */  lhu       $v0, ($s1)
/* CF0A94 80240154 30420400 */  andi      $v0, $v0, 0x400
/* CF0A98 80240158 1440001E */  bnez      $v0, .L802401D4
/* CF0A9C 8024015C 26300058 */   addiu    $s0, $s1, 0x58
/* CF0AA0 80240160 4480A000 */  mtc1      $zero, $f20
/* CF0AA4 80240164 4406B000 */  mfc1      $a2, $f22
/* CF0AA8 80240168 4405A000 */  mfc1      $a1, $f20
/* CF0AAC 8024016C 4407A000 */  mfc1      $a3, $f20
/* CF0AB0 80240170 0C019E40 */  jal       guTranslateF
/* CF0AB4 80240174 0200202D */   daddu    $a0, $s0, $zero
/* CF0AB8 80240178 4405E000 */  mfc1      $a1, $f28
/* CF0ABC 8024017C 4406D000 */  mfc1      $a2, $f26
/* CF0AC0 80240180 4407C000 */  mfc1      $a3, $f24
/* CF0AC4 80240184 0C090010 */  jal       func_80240040
/* CF0AC8 80240188 27A40010 */   addiu    $a0, $sp, 0x10
/* CF0ACC 8024018C 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0AD0 80240190 0200282D */  daddu     $a1, $s0, $zero
/* CF0AD4 80240194 0C019D80 */  jal       guMtxCatF
/* CF0AD8 80240198 0200302D */   daddu    $a2, $s0, $zero
/* CF0ADC 8024019C 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0AE0 802401A0 4600B587 */  neg.s     $f22, $f22
/* CF0AE4 802401A4 4405A000 */  mfc1      $a1, $f20
/* CF0AE8 802401A8 4406B000 */  mfc1      $a2, $f22
/* CF0AEC 802401AC 0C019E40 */  jal       guTranslateF
/* CF0AF0 802401B0 00A0382D */   daddu    $a3, $a1, $zero
/* CF0AF4 802401B4 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0AF8 802401B8 0200282D */  daddu     $a1, $s0, $zero
/* CF0AFC 802401BC 0C019D80 */  jal       guMtxCatF
/* CF0B00 802401C0 00A0302D */   daddu    $a2, $a1, $zero
/* CF0B04 802401C4 96220000 */  lhu       $v0, ($s1)
/* CF0B08 802401C8 34421400 */  ori       $v0, $v0, 0x1400
/* CF0B0C 802401CC 08090093 */  j         .L8024024C
/* CF0B10 802401D0 A6220000 */   sh       $v0, ($s1)
.L802401D4:
/* CF0B14 802401D4 4480A000 */  mtc1      $zero, $f20
/* CF0B18 802401D8 4406B000 */  mfc1      $a2, $f22
/* CF0B1C 802401DC 4405A000 */  mfc1      $a1, $f20
/* CF0B20 802401E0 4407A000 */  mfc1      $a3, $f20
/* CF0B24 802401E4 0C019E40 */  jal       guTranslateF
/* CF0B28 802401E8 27A40010 */   addiu    $a0, $sp, 0x10
/* CF0B2C 802401EC 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0B30 802401F0 26300058 */  addiu     $s0, $s1, 0x58
/* CF0B34 802401F4 0200282D */  daddu     $a1, $s0, $zero
/* CF0B38 802401F8 0C019D80 */  jal       guMtxCatF
/* CF0B3C 802401FC 0200302D */   daddu    $a2, $s0, $zero
/* CF0B40 80240200 4405E000 */  mfc1      $a1, $f28
/* CF0B44 80240204 4406D000 */  mfc1      $a2, $f26
/* CF0B48 80240208 4407C000 */  mfc1      $a3, $f24
/* CF0B4C 8024020C 0C090010 */  jal       func_80240040
/* CF0B50 80240210 27A40010 */   addiu    $a0, $sp, 0x10
/* CF0B54 80240214 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0B58 80240218 0200282D */  daddu     $a1, $s0, $zero
/* CF0B5C 8024021C 0C019D80 */  jal       guMtxCatF
/* CF0B60 80240220 0200302D */   daddu    $a2, $s0, $zero
/* CF0B64 80240224 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0B68 80240228 4600B587 */  neg.s     $f22, $f22
/* CF0B6C 8024022C 4405A000 */  mfc1      $a1, $f20
/* CF0B70 80240230 4406B000 */  mfc1      $a2, $f22
/* CF0B74 80240234 0C019E40 */  jal       guTranslateF
/* CF0B78 80240238 00A0382D */   daddu    $a3, $a1, $zero
/* CF0B7C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* CF0B80 80240240 0200282D */  daddu     $a1, $s0, $zero
/* CF0B84 80240244 0C019D80 */  jal       guMtxCatF
/* CF0B88 80240248 00A0302D */   daddu    $a2, $a1, $zero
.L8024024C:
/* CF0B8C 8024024C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CF0B90 80240250 8FB20058 */  lw        $s2, 0x58($sp)
/* CF0B94 80240254 8FB10054 */  lw        $s1, 0x54($sp)
/* CF0B98 80240258 8FB00050 */  lw        $s0, 0x50($sp)
/* CF0B9C 8024025C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CF0BA0 80240260 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CF0BA4 80240264 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CF0BA8 80240268 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CF0BAC 8024026C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CF0BB0 80240270 24020002 */  addiu     $v0, $zero, 2
/* CF0BB4 80240274 03E00008 */  jr        $ra
/* CF0BB8 80240278 27BD0088 */   addiu    $sp, $sp, 0x88
/* CF0BBC 8024027C 00000000 */  nop       
