.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_8EC210
/* 8EC210 802403F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8EC214 802403F4 AFB10054 */  sw        $s1, 0x54($sp)
/* 8EC218 802403F8 0080882D */  daddu     $s1, $a0, $zero
/* 8EC21C 802403FC AFBF005C */  sw        $ra, 0x5c($sp)
/* 8EC220 80240400 AFB20058 */  sw        $s2, 0x58($sp)
/* 8EC224 80240404 AFB00050 */  sw        $s0, 0x50($sp)
/* 8EC228 80240408 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8EC22C 8024040C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8EC230 80240410 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8EC234 80240414 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8EC238 80240418 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8EC23C 8024041C 8E30000C */  lw        $s0, 0xc($s1)
/* 8EC240 80240420 8E050000 */  lw        $a1, ($s0)
/* 8EC244 80240424 0C0B1EAF */  jal       get_variable
/* 8EC248 80240428 26100004 */   addiu    $s0, $s0, 4
/* 8EC24C 8024042C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8EC250 80240430 0040202D */   daddu    $a0, $v0, $zero
/* 8EC254 80240434 8E050000 */  lw        $a1, ($s0)
/* 8EC258 80240438 26100004 */  addiu     $s0, $s0, 4
/* 8EC25C 8024043C 0220202D */  daddu     $a0, $s1, $zero
/* 8EC260 80240440 0C0B210B */  jal       get_float_variable
/* 8EC264 80240444 0040902D */   daddu    $s2, $v0, $zero
/* 8EC268 80240448 8E050000 */  lw        $a1, ($s0)
/* 8EC26C 8024044C 26100004 */  addiu     $s0, $s0, 4
/* 8EC270 80240450 0220202D */  daddu     $a0, $s1, $zero
/* 8EC274 80240454 0C0B210B */  jal       get_float_variable
/* 8EC278 80240458 46000706 */   mov.s    $f28, $f0
/* 8EC27C 8024045C 8E050000 */  lw        $a1, ($s0)
/* 8EC280 80240460 26100004 */  addiu     $s0, $s0, 4
/* 8EC284 80240464 0220202D */  daddu     $a0, $s1, $zero
/* 8EC288 80240468 0C0B210B */  jal       get_float_variable
/* 8EC28C 8024046C 46000686 */   mov.s    $f26, $f0
/* 8EC290 80240470 0220202D */  daddu     $a0, $s1, $zero
/* 8EC294 80240474 8E050000 */  lw        $a1, ($s0)
/* 8EC298 80240478 0C0B210B */  jal       get_float_variable
/* 8EC29C 8024047C 46000586 */   mov.s    $f22, $f0
/* 8EC2A0 80240480 0240202D */  daddu     $a0, $s2, $zero
/* 8EC2A4 80240484 0C046B4C */  jal       get_model_from_list_index
/* 8EC2A8 80240488 46000606 */   mov.s    $f24, $f0
/* 8EC2AC 8024048C 0040882D */  daddu     $s1, $v0, $zero
/* 8EC2B0 80240490 96220000 */  lhu       $v0, ($s1)
/* 8EC2B4 80240494 30420400 */  andi      $v0, $v0, 0x400
/* 8EC2B8 80240498 1440001E */  bnez      $v0, .L80240514
/* 8EC2BC 8024049C 26300058 */   addiu    $s0, $s1, 0x58
/* 8EC2C0 802404A0 4480A000 */  mtc1      $zero, $f20
/* 8EC2C4 802404A4 4406B000 */  mfc1      $a2, $f22
/* 8EC2C8 802404A8 4405A000 */  mfc1      $a1, $f20
/* 8EC2CC 802404AC 4407A000 */  mfc1      $a3, $f20
/* 8EC2D0 802404B0 0C019E40 */  jal       guTranslateF
/* 8EC2D4 802404B4 0200202D */   daddu    $a0, $s0, $zero
/* 8EC2D8 802404B8 4405E000 */  mfc1      $a1, $f28
/* 8EC2DC 802404BC 4406D000 */  mfc1      $a2, $f26
/* 8EC2E0 802404C0 4407C000 */  mfc1      $a3, $f24
/* 8EC2E4 802404C4 0C0900E0 */  jal       func_80240380_8EC1A0
/* 8EC2E8 802404C8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8EC2EC 802404CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC2F0 802404D0 0200282D */  daddu     $a1, $s0, $zero
/* 8EC2F4 802404D4 0C019D80 */  jal       guMtxCatF
/* 8EC2F8 802404D8 0200302D */   daddu    $a2, $s0, $zero
/* 8EC2FC 802404DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC300 802404E0 4600B587 */  neg.s     $f22, $f22
/* 8EC304 802404E4 4405A000 */  mfc1      $a1, $f20
/* 8EC308 802404E8 4406B000 */  mfc1      $a2, $f22
/* 8EC30C 802404EC 0C019E40 */  jal       guTranslateF
/* 8EC310 802404F0 00A0382D */   daddu    $a3, $a1, $zero
/* 8EC314 802404F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC318 802404F8 0200282D */  daddu     $a1, $s0, $zero
/* 8EC31C 802404FC 0C019D80 */  jal       guMtxCatF
/* 8EC320 80240500 00A0302D */   daddu    $a2, $a1, $zero
/* 8EC324 80240504 96220000 */  lhu       $v0, ($s1)
/* 8EC328 80240508 34421400 */  ori       $v0, $v0, 0x1400
/* 8EC32C 8024050C 08090163 */  j         .L8024058C
/* 8EC330 80240510 A6220000 */   sh       $v0, ($s1)
.L80240514:
/* 8EC334 80240514 4480A000 */  mtc1      $zero, $f20
/* 8EC338 80240518 4406B000 */  mfc1      $a2, $f22
/* 8EC33C 8024051C 4405A000 */  mfc1      $a1, $f20
/* 8EC340 80240520 4407A000 */  mfc1      $a3, $f20
/* 8EC344 80240524 0C019E40 */  jal       guTranslateF
/* 8EC348 80240528 27A40010 */   addiu    $a0, $sp, 0x10
/* 8EC34C 8024052C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC350 80240530 26300058 */  addiu     $s0, $s1, 0x58
/* 8EC354 80240534 0200282D */  daddu     $a1, $s0, $zero
/* 8EC358 80240538 0C019D80 */  jal       guMtxCatF
/* 8EC35C 8024053C 0200302D */   daddu    $a2, $s0, $zero
/* 8EC360 80240540 4405E000 */  mfc1      $a1, $f28
/* 8EC364 80240544 4406D000 */  mfc1      $a2, $f26
/* 8EC368 80240548 4407C000 */  mfc1      $a3, $f24
/* 8EC36C 8024054C 0C0900E0 */  jal       func_80240380_8EC1A0
/* 8EC370 80240550 27A40010 */   addiu    $a0, $sp, 0x10
/* 8EC374 80240554 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC378 80240558 0200282D */  daddu     $a1, $s0, $zero
/* 8EC37C 8024055C 0C019D80 */  jal       guMtxCatF
/* 8EC380 80240560 0200302D */   daddu    $a2, $s0, $zero
/* 8EC384 80240564 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC388 80240568 4600B587 */  neg.s     $f22, $f22
/* 8EC38C 8024056C 4405A000 */  mfc1      $a1, $f20
/* 8EC390 80240570 4406B000 */  mfc1      $a2, $f22
/* 8EC394 80240574 0C019E40 */  jal       guTranslateF
/* 8EC398 80240578 00A0382D */   daddu    $a3, $a1, $zero
/* 8EC39C 8024057C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC3A0 80240580 0200282D */  daddu     $a1, $s0, $zero
/* 8EC3A4 80240584 0C019D80 */  jal       guMtxCatF
/* 8EC3A8 80240588 00A0302D */   daddu    $a2, $a1, $zero
.L8024058C:
/* 8EC3AC 8024058C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8EC3B0 80240590 8FB20058 */  lw        $s2, 0x58($sp)
/* 8EC3B4 80240594 8FB10054 */  lw        $s1, 0x54($sp)
/* 8EC3B8 80240598 8FB00050 */  lw        $s0, 0x50($sp)
/* 8EC3BC 8024059C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8EC3C0 802405A0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8EC3C4 802405A4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8EC3C8 802405A8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8EC3CC 802405AC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8EC3D0 802405B0 24020002 */  addiu     $v0, $zero, 2
/* 8EC3D4 802405B4 03E00008 */  jr        $ra
/* 8EC3D8 802405B8 27BD0088 */   addiu    $sp, $sp, 0x88
