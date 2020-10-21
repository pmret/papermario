.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C0_CEC300
/* CEC300 802400C0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CEC304 802400C4 AFB10054 */  sw        $s1, 0x54($sp)
/* CEC308 802400C8 0080882D */  daddu     $s1, $a0, $zero
/* CEC30C 802400CC AFBF005C */  sw        $ra, 0x5c($sp)
/* CEC310 802400D0 AFB20058 */  sw        $s2, 0x58($sp)
/* CEC314 802400D4 AFB00050 */  sw        $s0, 0x50($sp)
/* CEC318 802400D8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CEC31C 802400DC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CEC320 802400E0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CEC324 802400E4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CEC328 802400E8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CEC32C 802400EC 8E30000C */  lw        $s0, 0xc($s1)
/* CEC330 802400F0 8E050000 */  lw        $a1, ($s0)
/* CEC334 802400F4 0C0B1EAF */  jal       get_variable
/* CEC338 802400F8 26100004 */   addiu    $s0, $s0, 4
/* CEC33C 802400FC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CEC340 80240100 0040202D */   daddu    $a0, $v0, $zero
/* CEC344 80240104 8E050000 */  lw        $a1, ($s0)
/* CEC348 80240108 26100004 */  addiu     $s0, $s0, 4
/* CEC34C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* CEC350 80240110 0C0B210B */  jal       get_float_variable
/* CEC354 80240114 0040902D */   daddu    $s2, $v0, $zero
/* CEC358 80240118 8E050000 */  lw        $a1, ($s0)
/* CEC35C 8024011C 26100004 */  addiu     $s0, $s0, 4
/* CEC360 80240120 0220202D */  daddu     $a0, $s1, $zero
/* CEC364 80240124 0C0B210B */  jal       get_float_variable
/* CEC368 80240128 46000706 */   mov.s    $f28, $f0
/* CEC36C 8024012C 8E050000 */  lw        $a1, ($s0)
/* CEC370 80240130 26100004 */  addiu     $s0, $s0, 4
/* CEC374 80240134 0220202D */  daddu     $a0, $s1, $zero
/* CEC378 80240138 0C0B210B */  jal       get_float_variable
/* CEC37C 8024013C 46000686 */   mov.s    $f26, $f0
/* CEC380 80240140 0220202D */  daddu     $a0, $s1, $zero
/* CEC384 80240144 8E050000 */  lw        $a1, ($s0)
/* CEC388 80240148 0C0B210B */  jal       get_float_variable
/* CEC38C 8024014C 46000586 */   mov.s    $f22, $f0
/* CEC390 80240150 0240202D */  daddu     $a0, $s2, $zero
/* CEC394 80240154 0C046B4C */  jal       get_model_from_list_index
/* CEC398 80240158 46000606 */   mov.s    $f24, $f0
/* CEC39C 8024015C 0040882D */  daddu     $s1, $v0, $zero
/* CEC3A0 80240160 96220000 */  lhu       $v0, ($s1)
/* CEC3A4 80240164 30420400 */  andi      $v0, $v0, 0x400
/* CEC3A8 80240168 1440001E */  bnez      $v0, .L802401E4
/* CEC3AC 8024016C 26300058 */   addiu    $s0, $s1, 0x58
/* CEC3B0 80240170 4480A000 */  mtc1      $zero, $f20
/* CEC3B4 80240174 4406B000 */  mfc1      $a2, $f22
/* CEC3B8 80240178 4405A000 */  mfc1      $a1, $f20
/* CEC3BC 8024017C 4407A000 */  mfc1      $a3, $f20
/* CEC3C0 80240180 0C019E40 */  jal       guTranslateF
/* CEC3C4 80240184 0200202D */   daddu    $a0, $s0, $zero
/* CEC3C8 80240188 4405E000 */  mfc1      $a1, $f28
/* CEC3CC 8024018C 4406D000 */  mfc1      $a2, $f26
/* CEC3D0 80240190 4407C000 */  mfc1      $a3, $f24
/* CEC3D4 80240194 0C090014 */  jal       func_80240050_CEC290
/* CEC3D8 80240198 27A40010 */   addiu    $a0, $sp, 0x10
/* CEC3DC 8024019C 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC3E0 802401A0 0200282D */  daddu     $a1, $s0, $zero
/* CEC3E4 802401A4 0C019D80 */  jal       guMtxCatF
/* CEC3E8 802401A8 0200302D */   daddu    $a2, $s0, $zero
/* CEC3EC 802401AC 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC3F0 802401B0 4600B587 */  neg.s     $f22, $f22
/* CEC3F4 802401B4 4405A000 */  mfc1      $a1, $f20
/* CEC3F8 802401B8 4406B000 */  mfc1      $a2, $f22
/* CEC3FC 802401BC 0C019E40 */  jal       guTranslateF
/* CEC400 802401C0 00A0382D */   daddu    $a3, $a1, $zero
/* CEC404 802401C4 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC408 802401C8 0200282D */  daddu     $a1, $s0, $zero
/* CEC40C 802401CC 0C019D80 */  jal       guMtxCatF
/* CEC410 802401D0 00A0302D */   daddu    $a2, $a1, $zero
/* CEC414 802401D4 96220000 */  lhu       $v0, ($s1)
/* CEC418 802401D8 34421400 */  ori       $v0, $v0, 0x1400
/* CEC41C 802401DC 08090097 */  j         .L8024025C
/* CEC420 802401E0 A6220000 */   sh       $v0, ($s1)
.L802401E4:
/* CEC424 802401E4 4480A000 */  mtc1      $zero, $f20
/* CEC428 802401E8 4406B000 */  mfc1      $a2, $f22
/* CEC42C 802401EC 4405A000 */  mfc1      $a1, $f20
/* CEC430 802401F0 4407A000 */  mfc1      $a3, $f20
/* CEC434 802401F4 0C019E40 */  jal       guTranslateF
/* CEC438 802401F8 27A40010 */   addiu    $a0, $sp, 0x10
/* CEC43C 802401FC 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC440 80240200 26300058 */  addiu     $s0, $s1, 0x58
/* CEC444 80240204 0200282D */  daddu     $a1, $s0, $zero
/* CEC448 80240208 0C019D80 */  jal       guMtxCatF
/* CEC44C 8024020C 0200302D */   daddu    $a2, $s0, $zero
/* CEC450 80240210 4405E000 */  mfc1      $a1, $f28
/* CEC454 80240214 4406D000 */  mfc1      $a2, $f26
/* CEC458 80240218 4407C000 */  mfc1      $a3, $f24
/* CEC45C 8024021C 0C090014 */  jal       func_80240050_CEC290
/* CEC460 80240220 27A40010 */   addiu    $a0, $sp, 0x10
/* CEC464 80240224 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC468 80240228 0200282D */  daddu     $a1, $s0, $zero
/* CEC46C 8024022C 0C019D80 */  jal       guMtxCatF
/* CEC470 80240230 0200302D */   daddu    $a2, $s0, $zero
/* CEC474 80240234 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC478 80240238 4600B587 */  neg.s     $f22, $f22
/* CEC47C 8024023C 4405A000 */  mfc1      $a1, $f20
/* CEC480 80240240 4406B000 */  mfc1      $a2, $f22
/* CEC484 80240244 0C019E40 */  jal       guTranslateF
/* CEC488 80240248 00A0382D */   daddu    $a3, $a1, $zero
/* CEC48C 8024024C 27A40010 */  addiu     $a0, $sp, 0x10
/* CEC490 80240250 0200282D */  daddu     $a1, $s0, $zero
/* CEC494 80240254 0C019D80 */  jal       guMtxCatF
/* CEC498 80240258 00A0302D */   daddu    $a2, $a1, $zero
.L8024025C:
/* CEC49C 8024025C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CEC4A0 80240260 8FB20058 */  lw        $s2, 0x58($sp)
/* CEC4A4 80240264 8FB10054 */  lw        $s1, 0x54($sp)
/* CEC4A8 80240268 8FB00050 */  lw        $s0, 0x50($sp)
/* CEC4AC 8024026C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CEC4B0 80240270 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CEC4B4 80240274 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CEC4B8 80240278 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CEC4BC 8024027C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CEC4C0 80240280 24020002 */  addiu     $v0, $zero, 2
/* CEC4C4 80240284 03E00008 */  jr        $ra
/* CEC4C8 80240288 27BD0088 */   addiu    $sp, $sp, 0x88
/* CEC4CC 8024028C 00000000 */  nop       
