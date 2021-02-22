.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241390_ED55B0
/* ED55B0 80241390 27BDFF78 */  addiu     $sp, $sp, -0x88
/* ED55B4 80241394 AFB10054 */  sw        $s1, 0x54($sp)
/* ED55B8 80241398 0080882D */  daddu     $s1, $a0, $zero
/* ED55BC 8024139C AFBF005C */  sw        $ra, 0x5c($sp)
/* ED55C0 802413A0 AFB20058 */  sw        $s2, 0x58($sp)
/* ED55C4 802413A4 AFB00050 */  sw        $s0, 0x50($sp)
/* ED55C8 802413A8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* ED55CC 802413AC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* ED55D0 802413B0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ED55D4 802413B4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* ED55D8 802413B8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ED55DC 802413BC 8E30000C */  lw        $s0, 0xc($s1)
/* ED55E0 802413C0 8E050000 */  lw        $a1, ($s0)
/* ED55E4 802413C4 0C0B53A3 */  jal       func_802D4E8C
/* ED55E8 802413C8 26100004 */   addiu    $s0, $s0, 4
/* ED55EC 802413CC 0C04949C */  jal       func_80125270
/* ED55F0 802413D0 0040202D */   daddu    $a0, $v0, $zero
/* ED55F4 802413D4 8E050000 */  lw        $a1, ($s0)
/* ED55F8 802413D8 26100004 */  addiu     $s0, $s0, 4
/* ED55FC 802413DC 0220202D */  daddu     $a0, $s1, $zero
/* ED5600 802413E0 0C0B55FF */  jal       func_802D57FC
/* ED5604 802413E4 0040902D */   daddu    $s2, $v0, $zero
/* ED5608 802413E8 8E050000 */  lw        $a1, ($s0)
/* ED560C 802413EC 26100004 */  addiu     $s0, $s0, 4
/* ED5610 802413F0 0220202D */  daddu     $a0, $s1, $zero
/* ED5614 802413F4 0C0B55FF */  jal       func_802D57FC
/* ED5618 802413F8 46000706 */   mov.s    $f28, $f0
/* ED561C 802413FC 8E050000 */  lw        $a1, ($s0)
/* ED5620 80241400 26100004 */  addiu     $s0, $s0, 4
/* ED5624 80241404 0220202D */  daddu     $a0, $s1, $zero
/* ED5628 80241408 0C0B55FF */  jal       func_802D57FC
/* ED562C 8024140C 46000686 */   mov.s    $f26, $f0
/* ED5630 80241410 0220202D */  daddu     $a0, $s1, $zero
/* ED5634 80241414 8E050000 */  lw        $a1, ($s0)
/* ED5638 80241418 0C0B55FF */  jal       func_802D57FC
/* ED563C 8024141C 46000586 */   mov.s    $f22, $f0
/* ED5640 80241420 0240202D */  daddu     $a0, $s2, $zero
/* ED5644 80241424 0C0493D1 */  jal       func_80124F44
/* ED5648 80241428 46000606 */   mov.s    $f24, $f0
/* ED564C 8024142C 0040882D */  daddu     $s1, $v0, $zero
/* ED5650 80241430 96220000 */  lhu       $v0, ($s1)
/* ED5654 80241434 30420400 */  andi      $v0, $v0, 0x400
/* ED5658 80241438 1440001E */  bnez      $v0, .L802414B4
/* ED565C 8024143C 26300058 */   addiu    $s0, $s1, 0x58
/* ED5660 80241440 4480A000 */  mtc1      $zero, $f20
/* ED5664 80241444 4406B000 */  mfc1      $a2, $f22
/* ED5668 80241448 4405A000 */  mfc1      $a1, $f20
/* ED566C 8024144C 4407A000 */  mfc1      $a3, $f20
/* ED5670 80241450 0C01B2B0 */  jal       func_8006CAC0
/* ED5674 80241454 0200202D */   daddu    $a0, $s0, $zero
/* ED5678 80241458 4405E000 */  mfc1      $a1, $f28
/* ED567C 8024145C 4406D000 */  mfc1      $a2, $f26
/* ED5680 80241460 4407C000 */  mfc1      $a3, $f24
/* ED5684 80241464 0C0904C8 */  jal       func_80241320_ED5540
/* ED5688 80241468 27A40010 */   addiu    $a0, $sp, 0x10
/* ED568C 8024146C 27A40010 */  addiu     $a0, $sp, 0x10
/* ED5690 80241470 0200282D */  daddu     $a1, $s0, $zero
/* ED5694 80241474 0C01B1F0 */  jal       osSiRawReadIo
/* ED5698 80241478 0200302D */   daddu    $a2, $s0, $zero
/* ED569C 8024147C 27A40010 */  addiu     $a0, $sp, 0x10
/* ED56A0 80241480 4600B587 */  neg.s     $f22, $f22
/* ED56A4 80241484 4405A000 */  mfc1      $a1, $f20
/* ED56A8 80241488 4406B000 */  mfc1      $a2, $f22
/* ED56AC 8024148C 0C01B2B0 */  jal       func_8006CAC0
/* ED56B0 80241490 00A0382D */   daddu    $a3, $a1, $zero
/* ED56B4 80241494 27A40010 */  addiu     $a0, $sp, 0x10
/* ED56B8 80241498 0200282D */  daddu     $a1, $s0, $zero
/* ED56BC 8024149C 0C01B1F0 */  jal       osSiRawReadIo
/* ED56C0 802414A0 00A0302D */   daddu    $a2, $a1, $zero
/* ED56C4 802414A4 96220000 */  lhu       $v0, ($s1)
/* ED56C8 802414A8 34421400 */  ori       $v0, $v0, 0x1400
/* ED56CC 802414AC 0809054B */  j         .L8024152C
/* ED56D0 802414B0 A6220000 */   sh       $v0, ($s1)
.L802414B4:
/* ED56D4 802414B4 4480A000 */  mtc1      $zero, $f20
/* ED56D8 802414B8 4406B000 */  mfc1      $a2, $f22
/* ED56DC 802414BC 4405A000 */  mfc1      $a1, $f20
/* ED56E0 802414C0 4407A000 */  mfc1      $a3, $f20
/* ED56E4 802414C4 0C01B2B0 */  jal       func_8006CAC0
/* ED56E8 802414C8 27A40010 */   addiu    $a0, $sp, 0x10
/* ED56EC 802414CC 27A40010 */  addiu     $a0, $sp, 0x10
/* ED56F0 802414D0 26300058 */  addiu     $s0, $s1, 0x58
/* ED56F4 802414D4 0200282D */  daddu     $a1, $s0, $zero
/* ED56F8 802414D8 0C01B1F0 */  jal       osSiRawReadIo
/* ED56FC 802414DC 0200302D */   daddu    $a2, $s0, $zero
/* ED5700 802414E0 4405E000 */  mfc1      $a1, $f28
/* ED5704 802414E4 4406D000 */  mfc1      $a2, $f26
/* ED5708 802414E8 4407C000 */  mfc1      $a3, $f24
/* ED570C 802414EC 0C0904C8 */  jal       func_80241320_ED5540
/* ED5710 802414F0 27A40010 */   addiu    $a0, $sp, 0x10
/* ED5714 802414F4 27A40010 */  addiu     $a0, $sp, 0x10
/* ED5718 802414F8 0200282D */  daddu     $a1, $s0, $zero
/* ED571C 802414FC 0C01B1F0 */  jal       osSiRawReadIo
/* ED5720 80241500 0200302D */   daddu    $a2, $s0, $zero
/* ED5724 80241504 27A40010 */  addiu     $a0, $sp, 0x10
/* ED5728 80241508 4600B587 */  neg.s     $f22, $f22
/* ED572C 8024150C 4405A000 */  mfc1      $a1, $f20
/* ED5730 80241510 4406B000 */  mfc1      $a2, $f22
/* ED5734 80241514 0C01B2B0 */  jal       func_8006CAC0
/* ED5738 80241518 00A0382D */   daddu    $a3, $a1, $zero
/* ED573C 8024151C 27A40010 */  addiu     $a0, $sp, 0x10
/* ED5740 80241520 0200282D */  daddu     $a1, $s0, $zero
/* ED5744 80241524 0C01B1F0 */  jal       osSiRawReadIo
/* ED5748 80241528 00A0302D */   daddu    $a2, $a1, $zero
.L8024152C:
/* ED574C 8024152C 8FBF005C */  lw        $ra, 0x5c($sp)
/* ED5750 80241530 8FB20058 */  lw        $s2, 0x58($sp)
/* ED5754 80241534 8FB10054 */  lw        $s1, 0x54($sp)
/* ED5758 80241538 8FB00050 */  lw        $s0, 0x50($sp)
/* ED575C 8024153C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* ED5760 80241540 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* ED5764 80241544 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ED5768 80241548 D7B60068 */  ldc1      $f22, 0x68($sp)
/* ED576C 8024154C D7B40060 */  ldc1      $f20, 0x60($sp)
/* ED5770 80241550 24020002 */  addiu     $v0, $zero, 2
/* ED5774 80241554 03E00008 */  jr        $ra
/* ED5778 80241558 27BD0088 */   addiu    $sp, $sp, 0x88
/* ED577C 8024155C 00000000 */  nop
