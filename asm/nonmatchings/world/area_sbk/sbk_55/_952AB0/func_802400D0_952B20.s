.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D0_952B20
/* 952B20 802400D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 952B24 802400D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 952B28 802400D8 0080882D */  daddu     $s1, $a0, $zero
/* 952B2C 802400DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 952B30 802400E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 952B34 802400E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 952B38 802400E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 952B3C 802400EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 952B40 802400F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 952B44 802400F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 952B48 802400F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 952B4C 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* 952B50 80240100 8E050000 */  lw        $a1, ($s0)
/* 952B54 80240104 0C0B1EAF */  jal       get_variable
/* 952B58 80240108 26100004 */   addiu    $s0, $s0, 4
/* 952B5C 8024010C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 952B60 80240110 0040202D */   daddu    $a0, $v0, $zero
/* 952B64 80240114 8E050000 */  lw        $a1, ($s0)
/* 952B68 80240118 26100004 */  addiu     $s0, $s0, 4
/* 952B6C 8024011C 0220202D */  daddu     $a0, $s1, $zero
/* 952B70 80240120 0C0B210B */  jal       get_float_variable
/* 952B74 80240124 0040902D */   daddu    $s2, $v0, $zero
/* 952B78 80240128 8E050000 */  lw        $a1, ($s0)
/* 952B7C 8024012C 26100004 */  addiu     $s0, $s0, 4
/* 952B80 80240130 0220202D */  daddu     $a0, $s1, $zero
/* 952B84 80240134 0C0B210B */  jal       get_float_variable
/* 952B88 80240138 46000706 */   mov.s    $f28, $f0
/* 952B8C 8024013C 8E050000 */  lw        $a1, ($s0)
/* 952B90 80240140 26100004 */  addiu     $s0, $s0, 4
/* 952B94 80240144 0220202D */  daddu     $a0, $s1, $zero
/* 952B98 80240148 0C0B210B */  jal       get_float_variable
/* 952B9C 8024014C 46000686 */   mov.s    $f26, $f0
/* 952BA0 80240150 0220202D */  daddu     $a0, $s1, $zero
/* 952BA4 80240154 8E050000 */  lw        $a1, ($s0)
/* 952BA8 80240158 0C0B210B */  jal       get_float_variable
/* 952BAC 8024015C 46000586 */   mov.s    $f22, $f0
/* 952BB0 80240160 0240202D */  daddu     $a0, $s2, $zero
/* 952BB4 80240164 0C046B4C */  jal       get_model_from_list_index
/* 952BB8 80240168 46000606 */   mov.s    $f24, $f0
/* 952BBC 8024016C 0040882D */  daddu     $s1, $v0, $zero
/* 952BC0 80240170 96220000 */  lhu       $v0, ($s1)
/* 952BC4 80240174 30420400 */  andi      $v0, $v0, 0x400
/* 952BC8 80240178 1440001E */  bnez      $v0, .L802401F4
/* 952BCC 8024017C 26300058 */   addiu    $s0, $s1, 0x58
/* 952BD0 80240180 4480A000 */  mtc1      $zero, $f20
/* 952BD4 80240184 4406B000 */  mfc1      $a2, $f22
/* 952BD8 80240188 4405A000 */  mfc1      $a1, $f20
/* 952BDC 8024018C 4407A000 */  mfc1      $a3, $f20
/* 952BE0 80240190 0C019E40 */  jal       guTranslateF
/* 952BE4 80240194 0200202D */   daddu    $a0, $s0, $zero
/* 952BE8 80240198 4405E000 */  mfc1      $a1, $f28
/* 952BEC 8024019C 4406D000 */  mfc1      $a2, $f26
/* 952BF0 802401A0 4407C000 */  mfc1      $a3, $f24
/* 952BF4 802401A4 0C090018 */  jal       func_80240060
/* 952BF8 802401A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 952BFC 802401AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 952C00 802401B0 0200282D */  daddu     $a1, $s0, $zero
/* 952C04 802401B4 0C019D80 */  jal       guMtxCatF
/* 952C08 802401B8 0200302D */   daddu    $a2, $s0, $zero
/* 952C0C 802401BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 952C10 802401C0 4600B587 */  neg.s     $f22, $f22
/* 952C14 802401C4 4405A000 */  mfc1      $a1, $f20
/* 952C18 802401C8 4406B000 */  mfc1      $a2, $f22
/* 952C1C 802401CC 0C019E40 */  jal       guTranslateF
/* 952C20 802401D0 00A0382D */   daddu    $a3, $a1, $zero
/* 952C24 802401D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 952C28 802401D8 0200282D */  daddu     $a1, $s0, $zero
/* 952C2C 802401DC 0C019D80 */  jal       guMtxCatF
/* 952C30 802401E0 00A0302D */   daddu    $a2, $a1, $zero
/* 952C34 802401E4 96220000 */  lhu       $v0, ($s1)
/* 952C38 802401E8 34421400 */  ori       $v0, $v0, 0x1400
/* 952C3C 802401EC 0809009B */  j         .L8024026C
/* 952C40 802401F0 A6220000 */   sh       $v0, ($s1)
.L802401F4:
/* 952C44 802401F4 4480A000 */  mtc1      $zero, $f20
/* 952C48 802401F8 4406B000 */  mfc1      $a2, $f22
/* 952C4C 802401FC 4405A000 */  mfc1      $a1, $f20
/* 952C50 80240200 4407A000 */  mfc1      $a3, $f20
/* 952C54 80240204 0C019E40 */  jal       guTranslateF
/* 952C58 80240208 27A40010 */   addiu    $a0, $sp, 0x10
/* 952C5C 8024020C 27A40010 */  addiu     $a0, $sp, 0x10
/* 952C60 80240210 26300058 */  addiu     $s0, $s1, 0x58
/* 952C64 80240214 0200282D */  daddu     $a1, $s0, $zero
/* 952C68 80240218 0C019D80 */  jal       guMtxCatF
/* 952C6C 8024021C 0200302D */   daddu    $a2, $s0, $zero
/* 952C70 80240220 4405E000 */  mfc1      $a1, $f28
/* 952C74 80240224 4406D000 */  mfc1      $a2, $f26
/* 952C78 80240228 4407C000 */  mfc1      $a3, $f24
/* 952C7C 8024022C 0C090018 */  jal       func_80240060
/* 952C80 80240230 27A40010 */   addiu    $a0, $sp, 0x10
/* 952C84 80240234 27A40010 */  addiu     $a0, $sp, 0x10
/* 952C88 80240238 0200282D */  daddu     $a1, $s0, $zero
/* 952C8C 8024023C 0C019D80 */  jal       guMtxCatF
/* 952C90 80240240 0200302D */   daddu    $a2, $s0, $zero
/* 952C94 80240244 27A40010 */  addiu     $a0, $sp, 0x10
/* 952C98 80240248 4600B587 */  neg.s     $f22, $f22
/* 952C9C 8024024C 4405A000 */  mfc1      $a1, $f20
/* 952CA0 80240250 4406B000 */  mfc1      $a2, $f22
/* 952CA4 80240254 0C019E40 */  jal       guTranslateF
/* 952CA8 80240258 00A0382D */   daddu    $a3, $a1, $zero
/* 952CAC 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 952CB0 80240260 0200282D */  daddu     $a1, $s0, $zero
/* 952CB4 80240264 0C019D80 */  jal       guMtxCatF
/* 952CB8 80240268 00A0302D */   daddu    $a2, $a1, $zero
.L8024026C:
/* 952CBC 8024026C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 952CC0 80240270 8FB20058 */  lw        $s2, 0x58($sp)
/* 952CC4 80240274 8FB10054 */  lw        $s1, 0x54($sp)
/* 952CC8 80240278 8FB00050 */  lw        $s0, 0x50($sp)
/* 952CCC 8024027C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 952CD0 80240280 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 952CD4 80240284 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 952CD8 80240288 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 952CDC 8024028C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 952CE0 80240290 24020002 */  addiu     $v0, $zero, 2
/* 952CE4 80240294 03E00008 */  jr        $ra
/* 952CE8 80240298 27BD0088 */   addiu    $sp, $sp, 0x88
/* 952CEC 8024029C 00000000 */  nop       
