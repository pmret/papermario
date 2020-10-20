.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242260
/* B60510 80242260 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B60514 80242264 AFB10054 */  sw        $s1, 0x54($sp)
/* B60518 80242268 0080882D */  daddu     $s1, $a0, $zero
/* B6051C 8024226C AFBF005C */  sw        $ra, 0x5c($sp)
/* B60520 80242270 AFB20058 */  sw        $s2, 0x58($sp)
/* B60524 80242274 AFB00050 */  sw        $s0, 0x50($sp)
/* B60528 80242278 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B6052C 8024227C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B60530 80242280 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B60534 80242284 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B60538 80242288 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B6053C 8024228C 8E30000C */  lw        $s0, 0xc($s1)
/* B60540 80242290 8E050000 */  lw        $a1, ($s0)
/* B60544 80242294 0C0B1EAF */  jal       get_variable
/* B60548 80242298 26100004 */   addiu    $s0, $s0, 4
/* B6054C 8024229C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B60550 802422A0 0040202D */   daddu    $a0, $v0, $zero
/* B60554 802422A4 8E050000 */  lw        $a1, ($s0)
/* B60558 802422A8 26100004 */  addiu     $s0, $s0, 4
/* B6055C 802422AC 0220202D */  daddu     $a0, $s1, $zero
/* B60560 802422B0 0C0B210B */  jal       get_float_variable
/* B60564 802422B4 0040902D */   daddu    $s2, $v0, $zero
/* B60568 802422B8 8E050000 */  lw        $a1, ($s0)
/* B6056C 802422BC 26100004 */  addiu     $s0, $s0, 4
/* B60570 802422C0 0220202D */  daddu     $a0, $s1, $zero
/* B60574 802422C4 0C0B210B */  jal       get_float_variable
/* B60578 802422C8 46000706 */   mov.s    $f28, $f0
/* B6057C 802422CC 8E050000 */  lw        $a1, ($s0)
/* B60580 802422D0 26100004 */  addiu     $s0, $s0, 4
/* B60584 802422D4 0220202D */  daddu     $a0, $s1, $zero
/* B60588 802422D8 0C0B210B */  jal       get_float_variable
/* B6058C 802422DC 46000686 */   mov.s    $f26, $f0
/* B60590 802422E0 0220202D */  daddu     $a0, $s1, $zero
/* B60594 802422E4 8E050000 */  lw        $a1, ($s0)
/* B60598 802422E8 0C0B210B */  jal       get_float_variable
/* B6059C 802422EC 46000586 */   mov.s    $f22, $f0
/* B605A0 802422F0 0240202D */  daddu     $a0, $s2, $zero
/* B605A4 802422F4 0C046B4C */  jal       get_model_from_list_index
/* B605A8 802422F8 46000606 */   mov.s    $f24, $f0
/* B605AC 802422FC 0040882D */  daddu     $s1, $v0, $zero
/* B605B0 80242300 96220000 */  lhu       $v0, ($s1)
/* B605B4 80242304 30420400 */  andi      $v0, $v0, 0x400
/* B605B8 80242308 1440001E */  bnez      $v0, .L80242384
/* B605BC 8024230C 26300058 */   addiu    $s0, $s1, 0x58
/* B605C0 80242310 4480A000 */  mtc1      $zero, $f20
/* B605C4 80242314 4406B000 */  mfc1      $a2, $f22
/* B605C8 80242318 4405A000 */  mfc1      $a1, $f20
/* B605CC 8024231C 4407A000 */  mfc1      $a3, $f20
/* B605D0 80242320 0C019E40 */  jal       guTranslateF
/* B605D4 80242324 0200202D */   daddu    $a0, $s0, $zero
/* B605D8 80242328 4405E000 */  mfc1      $a1, $f28
/* B605DC 8024232C 4406D000 */  mfc1      $a2, $f26
/* B605E0 80242330 4407C000 */  mfc1      $a3, $f24
/* B605E4 80242334 0C09087C */  jal       func_802421F0
/* B605E8 80242338 27A40010 */   addiu    $a0, $sp, 0x10
/* B605EC 8024233C 27A40010 */  addiu     $a0, $sp, 0x10
/* B605F0 80242340 0200282D */  daddu     $a1, $s0, $zero
/* B605F4 80242344 0C019D80 */  jal       guMtxCatF
/* B605F8 80242348 0200302D */   daddu    $a2, $s0, $zero
/* B605FC 8024234C 27A40010 */  addiu     $a0, $sp, 0x10
/* B60600 80242350 4600B587 */  neg.s     $f22, $f22
/* B60604 80242354 4405A000 */  mfc1      $a1, $f20
/* B60608 80242358 4406B000 */  mfc1      $a2, $f22
/* B6060C 8024235C 0C019E40 */  jal       guTranslateF
/* B60610 80242360 00A0382D */   daddu    $a3, $a1, $zero
/* B60614 80242364 27A40010 */  addiu     $a0, $sp, 0x10
/* B60618 80242368 0200282D */  daddu     $a1, $s0, $zero
/* B6061C 8024236C 0C019D80 */  jal       guMtxCatF
/* B60620 80242370 00A0302D */   daddu    $a2, $a1, $zero
/* B60624 80242374 96220000 */  lhu       $v0, ($s1)
/* B60628 80242378 34421400 */  ori       $v0, $v0, 0x1400
/* B6062C 8024237C 080908FF */  j         .L802423FC
/* B60630 80242380 A6220000 */   sh       $v0, ($s1)
.L80242384:
/* B60634 80242384 4480A000 */  mtc1      $zero, $f20
/* B60638 80242388 4406B000 */  mfc1      $a2, $f22
/* B6063C 8024238C 4405A000 */  mfc1      $a1, $f20
/* B60640 80242390 4407A000 */  mfc1      $a3, $f20
/* B60644 80242394 0C019E40 */  jal       guTranslateF
/* B60648 80242398 27A40010 */   addiu    $a0, $sp, 0x10
/* B6064C 8024239C 27A40010 */  addiu     $a0, $sp, 0x10
/* B60650 802423A0 26300058 */  addiu     $s0, $s1, 0x58
/* B60654 802423A4 0200282D */  daddu     $a1, $s0, $zero
/* B60658 802423A8 0C019D80 */  jal       guMtxCatF
/* B6065C 802423AC 0200302D */   daddu    $a2, $s0, $zero
/* B60660 802423B0 4405E000 */  mfc1      $a1, $f28
/* B60664 802423B4 4406D000 */  mfc1      $a2, $f26
/* B60668 802423B8 4407C000 */  mfc1      $a3, $f24
/* B6066C 802423BC 0C09087C */  jal       func_802421F0
/* B60670 802423C0 27A40010 */   addiu    $a0, $sp, 0x10
/* B60674 802423C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B60678 802423C8 0200282D */  daddu     $a1, $s0, $zero
/* B6067C 802423CC 0C019D80 */  jal       guMtxCatF
/* B60680 802423D0 0200302D */   daddu    $a2, $s0, $zero
/* B60684 802423D4 27A40010 */  addiu     $a0, $sp, 0x10
/* B60688 802423D8 4600B587 */  neg.s     $f22, $f22
/* B6068C 802423DC 4405A000 */  mfc1      $a1, $f20
/* B60690 802423E0 4406B000 */  mfc1      $a2, $f22
/* B60694 802423E4 0C019E40 */  jal       guTranslateF
/* B60698 802423E8 00A0382D */   daddu    $a3, $a1, $zero
/* B6069C 802423EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B606A0 802423F0 0200282D */  daddu     $a1, $s0, $zero
/* B606A4 802423F4 0C019D80 */  jal       guMtxCatF
/* B606A8 802423F8 00A0302D */   daddu    $a2, $a1, $zero
.L802423FC:
/* B606AC 802423FC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B606B0 80242400 8FB20058 */  lw        $s2, 0x58($sp)
/* B606B4 80242404 8FB10054 */  lw        $s1, 0x54($sp)
/* B606B8 80242408 8FB00050 */  lw        $s0, 0x50($sp)
/* B606BC 8024240C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B606C0 80242410 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B606C4 80242414 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B606C8 80242418 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B606CC 8024241C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B606D0 80242420 24020002 */  addiu     $v0, $zero, 2
/* B606D4 80242424 03E00008 */  jr        $ra
/* B606D8 80242428 27BD0088 */   addiu    $sp, $sp, 0x88
/* B606DC 8024242C 00000000 */  nop       
