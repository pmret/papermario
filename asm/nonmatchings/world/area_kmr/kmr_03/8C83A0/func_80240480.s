.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480
/* 8C8410 80240480 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8C8414 80240484 AFB10054 */  sw        $s1, 0x54($sp)
/* 8C8418 80240488 0080882D */  daddu     $s1, $a0, $zero
/* 8C841C 8024048C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8C8420 80240490 AFB20058 */  sw        $s2, 0x58($sp)
/* 8C8424 80240494 AFB00050 */  sw        $s0, 0x50($sp)
/* 8C8428 80240498 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8C842C 8024049C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8C8430 802404A0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8C8434 802404A4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8C8438 802404A8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8C843C 802404AC 8E30000C */  lw        $s0, 0xc($s1)
/* 8C8440 802404B0 8E050000 */  lw        $a1, ($s0)
/* 8C8444 802404B4 0C0B1EAF */  jal       get_variable
/* 8C8448 802404B8 26100004 */   addiu    $s0, $s0, 4
/* 8C844C 802404BC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8C8450 802404C0 0040202D */   daddu    $a0, $v0, $zero
/* 8C8454 802404C4 8E050000 */  lw        $a1, ($s0)
/* 8C8458 802404C8 26100004 */  addiu     $s0, $s0, 4
/* 8C845C 802404CC 0220202D */  daddu     $a0, $s1, $zero
/* 8C8460 802404D0 0C0B210B */  jal       get_float_variable
/* 8C8464 802404D4 0040902D */   daddu    $s2, $v0, $zero
/* 8C8468 802404D8 8E050000 */  lw        $a1, ($s0)
/* 8C846C 802404DC 26100004 */  addiu     $s0, $s0, 4
/* 8C8470 802404E0 0220202D */  daddu     $a0, $s1, $zero
/* 8C8474 802404E4 0C0B210B */  jal       get_float_variable
/* 8C8478 802404E8 46000706 */   mov.s    $f28, $f0
/* 8C847C 802404EC 8E050000 */  lw        $a1, ($s0)
/* 8C8480 802404F0 26100004 */  addiu     $s0, $s0, 4
/* 8C8484 802404F4 0220202D */  daddu     $a0, $s1, $zero
/* 8C8488 802404F8 0C0B210B */  jal       get_float_variable
/* 8C848C 802404FC 46000686 */   mov.s    $f26, $f0
/* 8C8490 80240500 0220202D */  daddu     $a0, $s1, $zero
/* 8C8494 80240504 8E050000 */  lw        $a1, ($s0)
/* 8C8498 80240508 0C0B210B */  jal       get_float_variable
/* 8C849C 8024050C 46000586 */   mov.s    $f22, $f0
/* 8C84A0 80240510 0240202D */  daddu     $a0, $s2, $zero
/* 8C84A4 80240514 0C046B4C */  jal       get_model_from_list_index
/* 8C84A8 80240518 46000606 */   mov.s    $f24, $f0
/* 8C84AC 8024051C 0040882D */  daddu     $s1, $v0, $zero
/* 8C84B0 80240520 96220000 */  lhu       $v0, ($s1)
/* 8C84B4 80240524 30420400 */  andi      $v0, $v0, 0x400
/* 8C84B8 80240528 1440001E */  bnez      $v0, .L802405A4
/* 8C84BC 8024052C 26300058 */   addiu    $s0, $s1, 0x58
/* 8C84C0 80240530 4480A000 */  mtc1      $zero, $f20
/* 8C84C4 80240534 4406B000 */  mfc1      $a2, $f22
/* 8C84C8 80240538 4405A000 */  mfc1      $a1, $f20
/* 8C84CC 8024053C 4407A000 */  mfc1      $a3, $f20
/* 8C84D0 80240540 0C019E40 */  jal       guTranslateF
/* 8C84D4 80240544 0200202D */   daddu    $a0, $s0, $zero
/* 8C84D8 80240548 4405E000 */  mfc1      $a1, $f28
/* 8C84DC 8024054C 4406D000 */  mfc1      $a2, $f26
/* 8C84E0 80240550 4407C000 */  mfc1      $a3, $f24
/* 8C84E4 80240554 0C090104 */  jal       func_80240410
/* 8C84E8 80240558 27A40010 */   addiu    $a0, $sp, 0x10
/* 8C84EC 8024055C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C84F0 80240560 0200282D */  daddu     $a1, $s0, $zero
/* 8C84F4 80240564 0C019D80 */  jal       guMtxCatF
/* 8C84F8 80240568 0200302D */   daddu    $a2, $s0, $zero
/* 8C84FC 8024056C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C8500 80240570 4600B587 */  neg.s     $f22, $f22
/* 8C8504 80240574 4405A000 */  mfc1      $a1, $f20
/* 8C8508 80240578 4406B000 */  mfc1      $a2, $f22
/* 8C850C 8024057C 0C019E40 */  jal       guTranslateF
/* 8C8510 80240580 00A0382D */   daddu    $a3, $a1, $zero
/* 8C8514 80240584 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C8518 80240588 0200282D */  daddu     $a1, $s0, $zero
/* 8C851C 8024058C 0C019D80 */  jal       guMtxCatF
/* 8C8520 80240590 00A0302D */   daddu    $a2, $a1, $zero
/* 8C8524 80240594 96220000 */  lhu       $v0, ($s1)
/* 8C8528 80240598 34421400 */  ori       $v0, $v0, 0x1400
/* 8C852C 8024059C 08090187 */  j         .L8024061C
/* 8C8530 802405A0 A6220000 */   sh       $v0, ($s1)
.L802405A4:
/* 8C8534 802405A4 4480A000 */  mtc1      $zero, $f20
/* 8C8538 802405A8 4406B000 */  mfc1      $a2, $f22
/* 8C853C 802405AC 4405A000 */  mfc1      $a1, $f20
/* 8C8540 802405B0 4407A000 */  mfc1      $a3, $f20
/* 8C8544 802405B4 0C019E40 */  jal       guTranslateF
/* 8C8548 802405B8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8C854C 802405BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C8550 802405C0 26300058 */  addiu     $s0, $s1, 0x58
/* 8C8554 802405C4 0200282D */  daddu     $a1, $s0, $zero
/* 8C8558 802405C8 0C019D80 */  jal       guMtxCatF
/* 8C855C 802405CC 0200302D */   daddu    $a2, $s0, $zero
/* 8C8560 802405D0 4405E000 */  mfc1      $a1, $f28
/* 8C8564 802405D4 4406D000 */  mfc1      $a2, $f26
/* 8C8568 802405D8 4407C000 */  mfc1      $a3, $f24
/* 8C856C 802405DC 0C090104 */  jal       func_80240410
/* 8C8570 802405E0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8C8574 802405E4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C8578 802405E8 0200282D */  daddu     $a1, $s0, $zero
/* 8C857C 802405EC 0C019D80 */  jal       guMtxCatF
/* 8C8580 802405F0 0200302D */   daddu    $a2, $s0, $zero
/* 8C8584 802405F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C8588 802405F8 4600B587 */  neg.s     $f22, $f22
/* 8C858C 802405FC 4405A000 */  mfc1      $a1, $f20
/* 8C8590 80240600 4406B000 */  mfc1      $a2, $f22
/* 8C8594 80240604 0C019E40 */  jal       guTranslateF
/* 8C8598 80240608 00A0382D */   daddu    $a3, $a1, $zero
/* 8C859C 8024060C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8C85A0 80240610 0200282D */  daddu     $a1, $s0, $zero
/* 8C85A4 80240614 0C019D80 */  jal       guMtxCatF
/* 8C85A8 80240618 00A0302D */   daddu    $a2, $a1, $zero
.L8024061C:
/* 8C85AC 8024061C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8C85B0 80240620 8FB20058 */  lw        $s2, 0x58($sp)
/* 8C85B4 80240624 8FB10054 */  lw        $s1, 0x54($sp)
/* 8C85B8 80240628 8FB00050 */  lw        $s0, 0x50($sp)
/* 8C85BC 8024062C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8C85C0 80240630 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8C85C4 80240634 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8C85C8 80240638 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8C85CC 8024063C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8C85D0 80240640 24020002 */  addiu     $v0, $zero, 2
/* 8C85D4 80240644 03E00008 */  jr        $ra
/* 8C85D8 80240648 27BD0088 */   addiu    $sp, $sp, 0x88
/* 8C85DC 8024064C 00000000 */  nop       
