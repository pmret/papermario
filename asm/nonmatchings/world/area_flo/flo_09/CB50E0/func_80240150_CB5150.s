.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240150_CB5150
/* CB5150 80240150 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CB5154 80240154 AFB10054 */  sw        $s1, 0x54($sp)
/* CB5158 80240158 0080882D */  daddu     $s1, $a0, $zero
/* CB515C 8024015C AFBF005C */  sw        $ra, 0x5c($sp)
/* CB5160 80240160 AFB20058 */  sw        $s2, 0x58($sp)
/* CB5164 80240164 AFB00050 */  sw        $s0, 0x50($sp)
/* CB5168 80240168 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CB516C 8024016C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CB5170 80240170 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CB5174 80240174 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CB5178 80240178 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CB517C 8024017C 8E30000C */  lw        $s0, 0xc($s1)
/* CB5180 80240180 8E050000 */  lw        $a1, ($s0)
/* CB5184 80240184 0C0B1EAF */  jal       get_variable
/* CB5188 80240188 26100004 */   addiu    $s0, $s0, 4
/* CB518C 8024018C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CB5190 80240190 0040202D */   daddu    $a0, $v0, $zero
/* CB5194 80240194 8E050000 */  lw        $a1, ($s0)
/* CB5198 80240198 26100004 */  addiu     $s0, $s0, 4
/* CB519C 8024019C 0220202D */  daddu     $a0, $s1, $zero
/* CB51A0 802401A0 0C0B210B */  jal       get_float_variable
/* CB51A4 802401A4 0040902D */   daddu    $s2, $v0, $zero
/* CB51A8 802401A8 8E050000 */  lw        $a1, ($s0)
/* CB51AC 802401AC 26100004 */  addiu     $s0, $s0, 4
/* CB51B0 802401B0 0220202D */  daddu     $a0, $s1, $zero
/* CB51B4 802401B4 0C0B210B */  jal       get_float_variable
/* CB51B8 802401B8 46000706 */   mov.s    $f28, $f0
/* CB51BC 802401BC 8E050000 */  lw        $a1, ($s0)
/* CB51C0 802401C0 26100004 */  addiu     $s0, $s0, 4
/* CB51C4 802401C4 0220202D */  daddu     $a0, $s1, $zero
/* CB51C8 802401C8 0C0B210B */  jal       get_float_variable
/* CB51CC 802401CC 46000686 */   mov.s    $f26, $f0
/* CB51D0 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* CB51D4 802401D4 8E050000 */  lw        $a1, ($s0)
/* CB51D8 802401D8 0C0B210B */  jal       get_float_variable
/* CB51DC 802401DC 46000586 */   mov.s    $f22, $f0
/* CB51E0 802401E0 0240202D */  daddu     $a0, $s2, $zero
/* CB51E4 802401E4 0C046B4C */  jal       get_model_from_list_index
/* CB51E8 802401E8 46000606 */   mov.s    $f24, $f0
/* CB51EC 802401EC 0040882D */  daddu     $s1, $v0, $zero
/* CB51F0 802401F0 96220000 */  lhu       $v0, ($s1)
/* CB51F4 802401F4 30420400 */  andi      $v0, $v0, 0x400
/* CB51F8 802401F8 1440001E */  bnez      $v0, .L80240274
/* CB51FC 802401FC 26300058 */   addiu    $s0, $s1, 0x58
/* CB5200 80240200 4480A000 */  mtc1      $zero, $f20
/* CB5204 80240204 4406B000 */  mfc1      $a2, $f22
/* CB5208 80240208 4405A000 */  mfc1      $a1, $f20
/* CB520C 8024020C 4407A000 */  mfc1      $a3, $f20
/* CB5210 80240210 0C019E40 */  jal       guTranslateF
/* CB5214 80240214 0200202D */   daddu    $a0, $s0, $zero
/* CB5218 80240218 4405E000 */  mfc1      $a1, $f28
/* CB521C 8024021C 4406D000 */  mfc1      $a2, $f26
/* CB5220 80240220 4407C000 */  mfc1      $a3, $f24
/* CB5224 80240224 0C090038 */  jal       func_802400E0
/* CB5228 80240228 27A40010 */   addiu    $a0, $sp, 0x10
/* CB522C 8024022C 27A40010 */  addiu     $a0, $sp, 0x10
/* CB5230 80240230 0200282D */  daddu     $a1, $s0, $zero
/* CB5234 80240234 0C019D80 */  jal       guMtxCatF
/* CB5238 80240238 0200302D */   daddu    $a2, $s0, $zero
/* CB523C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* CB5240 80240240 4600B587 */  neg.s     $f22, $f22
/* CB5244 80240244 4405A000 */  mfc1      $a1, $f20
/* CB5248 80240248 4406B000 */  mfc1      $a2, $f22
/* CB524C 8024024C 0C019E40 */  jal       guTranslateF
/* CB5250 80240250 00A0382D */   daddu    $a3, $a1, $zero
/* CB5254 80240254 27A40010 */  addiu     $a0, $sp, 0x10
/* CB5258 80240258 0200282D */  daddu     $a1, $s0, $zero
/* CB525C 8024025C 0C019D80 */  jal       guMtxCatF
/* CB5260 80240260 00A0302D */   daddu    $a2, $a1, $zero
/* CB5264 80240264 96220000 */  lhu       $v0, ($s1)
/* CB5268 80240268 34421400 */  ori       $v0, $v0, 0x1400
/* CB526C 8024026C 080900BB */  j         .L802402EC
/* CB5270 80240270 A6220000 */   sh       $v0, ($s1)
.L80240274:
/* CB5274 80240274 4480A000 */  mtc1      $zero, $f20
/* CB5278 80240278 4406B000 */  mfc1      $a2, $f22
/* CB527C 8024027C 4405A000 */  mfc1      $a1, $f20
/* CB5280 80240280 4407A000 */  mfc1      $a3, $f20
/* CB5284 80240284 0C019E40 */  jal       guTranslateF
/* CB5288 80240288 27A40010 */   addiu    $a0, $sp, 0x10
/* CB528C 8024028C 27A40010 */  addiu     $a0, $sp, 0x10
/* CB5290 80240290 26300058 */  addiu     $s0, $s1, 0x58
/* CB5294 80240294 0200282D */  daddu     $a1, $s0, $zero
/* CB5298 80240298 0C019D80 */  jal       guMtxCatF
/* CB529C 8024029C 0200302D */   daddu    $a2, $s0, $zero
/* CB52A0 802402A0 4405E000 */  mfc1      $a1, $f28
/* CB52A4 802402A4 4406D000 */  mfc1      $a2, $f26
/* CB52A8 802402A8 4407C000 */  mfc1      $a3, $f24
/* CB52AC 802402AC 0C090038 */  jal       func_802400E0
/* CB52B0 802402B0 27A40010 */   addiu    $a0, $sp, 0x10
/* CB52B4 802402B4 27A40010 */  addiu     $a0, $sp, 0x10
/* CB52B8 802402B8 0200282D */  daddu     $a1, $s0, $zero
/* CB52BC 802402BC 0C019D80 */  jal       guMtxCatF
/* CB52C0 802402C0 0200302D */   daddu    $a2, $s0, $zero
/* CB52C4 802402C4 27A40010 */  addiu     $a0, $sp, 0x10
/* CB52C8 802402C8 4600B587 */  neg.s     $f22, $f22
/* CB52CC 802402CC 4405A000 */  mfc1      $a1, $f20
/* CB52D0 802402D0 4406B000 */  mfc1      $a2, $f22
/* CB52D4 802402D4 0C019E40 */  jal       guTranslateF
/* CB52D8 802402D8 00A0382D */   daddu    $a3, $a1, $zero
/* CB52DC 802402DC 27A40010 */  addiu     $a0, $sp, 0x10
/* CB52E0 802402E0 0200282D */  daddu     $a1, $s0, $zero
/* CB52E4 802402E4 0C019D80 */  jal       guMtxCatF
/* CB52E8 802402E8 00A0302D */   daddu    $a2, $a1, $zero
.L802402EC:
/* CB52EC 802402EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* CB52F0 802402F0 8FB20058 */  lw        $s2, 0x58($sp)
/* CB52F4 802402F4 8FB10054 */  lw        $s1, 0x54($sp)
/* CB52F8 802402F8 8FB00050 */  lw        $s0, 0x50($sp)
/* CB52FC 802402FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CB5300 80240300 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CB5304 80240304 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CB5308 80240308 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CB530C 8024030C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CB5310 80240310 24020002 */  addiu     $v0, $zero, 2
/* CB5314 80240314 03E00008 */  jr        $ra
/* CB5318 80240318 27BD0088 */   addiu    $sp, $sp, 0x88
/* CB531C 8024031C 00000000 */  nop       
