.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240450_EC7600
/* EC7600 80240450 27BDFF78 */  addiu     $sp, $sp, -0x88
/* EC7604 80240454 AFB10054 */  sw        $s1, 0x54($sp)
/* EC7608 80240458 0080882D */  daddu     $s1, $a0, $zero
/* EC760C 8024045C AFBF005C */  sw        $ra, 0x5c($sp)
/* EC7610 80240460 AFB20058 */  sw        $s2, 0x58($sp)
/* EC7614 80240464 AFB00050 */  sw        $s0, 0x50($sp)
/* EC7618 80240468 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* EC761C 8024046C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EC7620 80240470 F7B80070 */  sdc1      $f24, 0x70($sp)
/* EC7624 80240474 F7B60068 */  sdc1      $f22, 0x68($sp)
/* EC7628 80240478 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EC762C 8024047C 8E30000C */  lw        $s0, 0xc($s1)
/* EC7630 80240480 8E050000 */  lw        $a1, ($s0)
/* EC7634 80240484 0C0B53A3 */  jal       func_802D4E8C
/* EC7638 80240488 26100004 */   addiu    $s0, $s0, 4
/* EC763C 8024048C 0C04949C */  jal       func_80125270
/* EC7640 80240490 0040202D */   daddu    $a0, $v0, $zero
/* EC7644 80240494 8E050000 */  lw        $a1, ($s0)
/* EC7648 80240498 26100004 */  addiu     $s0, $s0, 4
/* EC764C 8024049C 0220202D */  daddu     $a0, $s1, $zero
/* EC7650 802404A0 0C0B55FF */  jal       func_802D57FC
/* EC7654 802404A4 0040902D */   daddu    $s2, $v0, $zero
/* EC7658 802404A8 8E050000 */  lw        $a1, ($s0)
/* EC765C 802404AC 26100004 */  addiu     $s0, $s0, 4
/* EC7660 802404B0 0220202D */  daddu     $a0, $s1, $zero
/* EC7664 802404B4 0C0B55FF */  jal       func_802D57FC
/* EC7668 802404B8 46000706 */   mov.s    $f28, $f0
/* EC766C 802404BC 8E050000 */  lw        $a1, ($s0)
/* EC7670 802404C0 26100004 */  addiu     $s0, $s0, 4
/* EC7674 802404C4 0220202D */  daddu     $a0, $s1, $zero
/* EC7678 802404C8 0C0B55FF */  jal       func_802D57FC
/* EC767C 802404CC 46000686 */   mov.s    $f26, $f0
/* EC7680 802404D0 0220202D */  daddu     $a0, $s1, $zero
/* EC7684 802404D4 8E050000 */  lw        $a1, ($s0)
/* EC7688 802404D8 0C0B55FF */  jal       func_802D57FC
/* EC768C 802404DC 46000586 */   mov.s    $f22, $f0
/* EC7690 802404E0 0240202D */  daddu     $a0, $s2, $zero
/* EC7694 802404E4 0C0493D1 */  jal       func_80124F44
/* EC7698 802404E8 46000606 */   mov.s    $f24, $f0
/* EC769C 802404EC 0040882D */  daddu     $s1, $v0, $zero
/* EC76A0 802404F0 96220000 */  lhu       $v0, ($s1)
/* EC76A4 802404F4 30420400 */  andi      $v0, $v0, 0x400
/* EC76A8 802404F8 1440001E */  bnez      $v0, .L80240574
/* EC76AC 802404FC 26300058 */   addiu    $s0, $s1, 0x58
/* EC76B0 80240500 4480A000 */  mtc1      $zero, $f20
/* EC76B4 80240504 4406B000 */  mfc1      $a2, $f22
/* EC76B8 80240508 4405A000 */  mfc1      $a1, $f20
/* EC76BC 8024050C 4407A000 */  mfc1      $a3, $f20
/* EC76C0 80240510 0C01B2B0 */  jal       func_8006CAC0
/* EC76C4 80240514 0200202D */   daddu    $a0, $s0, $zero
/* EC76C8 80240518 4405E000 */  mfc1      $a1, $f28
/* EC76CC 8024051C 4406D000 */  mfc1      $a2, $f26
/* EC76D0 80240520 4407C000 */  mfc1      $a3, $f24
/* EC76D4 80240524 0C0900F8 */  jal       func_802403E0_EC7590
/* EC76D8 80240528 27A40010 */   addiu    $a0, $sp, 0x10
/* EC76DC 8024052C 27A40010 */  addiu     $a0, $sp, 0x10
/* EC76E0 80240530 0200282D */  daddu     $a1, $s0, $zero
/* EC76E4 80240534 0C01B1F0 */  jal       osSiRawReadIo
/* EC76E8 80240538 0200302D */   daddu    $a2, $s0, $zero
/* EC76EC 8024053C 27A40010 */  addiu     $a0, $sp, 0x10
/* EC76F0 80240540 4600B587 */  neg.s     $f22, $f22
/* EC76F4 80240544 4405A000 */  mfc1      $a1, $f20
/* EC76F8 80240548 4406B000 */  mfc1      $a2, $f22
/* EC76FC 8024054C 0C01B2B0 */  jal       func_8006CAC0
/* EC7700 80240550 00A0382D */   daddu    $a3, $a1, $zero
/* EC7704 80240554 27A40010 */  addiu     $a0, $sp, 0x10
/* EC7708 80240558 0200282D */  daddu     $a1, $s0, $zero
/* EC770C 8024055C 0C01B1F0 */  jal       osSiRawReadIo
/* EC7710 80240560 00A0302D */   daddu    $a2, $a1, $zero
/* EC7714 80240564 96220000 */  lhu       $v0, ($s1)
/* EC7718 80240568 34421400 */  ori       $v0, $v0, 0x1400
/* EC771C 8024056C 0809017B */  j         .L802405EC
/* EC7720 80240570 A6220000 */   sh       $v0, ($s1)
.L80240574:
/* EC7724 80240574 4480A000 */  mtc1      $zero, $f20
/* EC7728 80240578 4406B000 */  mfc1      $a2, $f22
/* EC772C 8024057C 4405A000 */  mfc1      $a1, $f20
/* EC7730 80240580 4407A000 */  mfc1      $a3, $f20
/* EC7734 80240584 0C01B2B0 */  jal       func_8006CAC0
/* EC7738 80240588 27A40010 */   addiu    $a0, $sp, 0x10
/* EC773C 8024058C 27A40010 */  addiu     $a0, $sp, 0x10
/* EC7740 80240590 26300058 */  addiu     $s0, $s1, 0x58
/* EC7744 80240594 0200282D */  daddu     $a1, $s0, $zero
/* EC7748 80240598 0C01B1F0 */  jal       osSiRawReadIo
/* EC774C 8024059C 0200302D */   daddu    $a2, $s0, $zero
/* EC7750 802405A0 4405E000 */  mfc1      $a1, $f28
/* EC7754 802405A4 4406D000 */  mfc1      $a2, $f26
/* EC7758 802405A8 4407C000 */  mfc1      $a3, $f24
/* EC775C 802405AC 0C0900F8 */  jal       func_802403E0_EC7590
/* EC7760 802405B0 27A40010 */   addiu    $a0, $sp, 0x10
/* EC7764 802405B4 27A40010 */  addiu     $a0, $sp, 0x10
/* EC7768 802405B8 0200282D */  daddu     $a1, $s0, $zero
/* EC776C 802405BC 0C01B1F0 */  jal       osSiRawReadIo
/* EC7770 802405C0 0200302D */   daddu    $a2, $s0, $zero
/* EC7774 802405C4 27A40010 */  addiu     $a0, $sp, 0x10
/* EC7778 802405C8 4600B587 */  neg.s     $f22, $f22
/* EC777C 802405CC 4405A000 */  mfc1      $a1, $f20
/* EC7780 802405D0 4406B000 */  mfc1      $a2, $f22
/* EC7784 802405D4 0C01B2B0 */  jal       func_8006CAC0
/* EC7788 802405D8 00A0382D */   daddu    $a3, $a1, $zero
/* EC778C 802405DC 27A40010 */  addiu     $a0, $sp, 0x10
/* EC7790 802405E0 0200282D */  daddu     $a1, $s0, $zero
/* EC7794 802405E4 0C01B1F0 */  jal       osSiRawReadIo
/* EC7798 802405E8 00A0302D */   daddu    $a2, $a1, $zero
.L802405EC:
/* EC779C 802405EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* EC77A0 802405F0 8FB20058 */  lw        $s2, 0x58($sp)
/* EC77A4 802405F4 8FB10054 */  lw        $s1, 0x54($sp)
/* EC77A8 802405F8 8FB00050 */  lw        $s0, 0x50($sp)
/* EC77AC 802405FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* EC77B0 80240600 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EC77B4 80240604 D7B80070 */  ldc1      $f24, 0x70($sp)
/* EC77B8 80240608 D7B60068 */  ldc1      $f22, 0x68($sp)
/* EC77BC 8024060C D7B40060 */  ldc1      $f20, 0x60($sp)
/* EC77C0 80240610 24020002 */  addiu     $v0, $zero, 2
/* EC77C4 80240614 03E00008 */  jr        $ra
/* EC77C8 80240618 27BD0088 */   addiu    $sp, $sp, 0x88
