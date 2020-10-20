.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A8_DA55E8
/* DA55E8 802403A8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DA55EC 802403AC AFB20018 */  sw        $s2, 0x18($sp)
/* DA55F0 802403B0 0080902D */  daddu     $s2, $a0, $zero
/* DA55F4 802403B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* DA55F8 802403B8 AFB50024 */  sw        $s5, 0x24($sp)
/* DA55FC 802403BC AFB40020 */  sw        $s4, 0x20($sp)
/* DA5600 802403C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* DA5604 802403C4 AFB10014 */  sw        $s1, 0x14($sp)
/* DA5608 802403C8 AFB00010 */  sw        $s0, 0x10($sp)
/* DA560C 802403CC F7B80040 */  sdc1      $f24, 0x40($sp)
/* DA5610 802403D0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DA5614 802403D4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* DA5618 802403D8 8E50000C */  lw        $s0, 0xc($s2)
/* DA561C 802403DC 8E140000 */  lw        $s4, ($s0)
/* DA5620 802403E0 26100004 */  addiu     $s0, $s0, 4
/* DA5624 802403E4 0C0B1EAF */  jal       get_variable
/* DA5628 802403E8 0280282D */   daddu    $a1, $s4, $zero
/* DA562C 802403EC 0040982D */  daddu     $s3, $v0, $zero
/* DA5630 802403F0 8E150000 */  lw        $s5, ($s0)
/* DA5634 802403F4 26100004 */  addiu     $s0, $s0, 4
/* DA5638 802403F8 8E050000 */  lw        $a1, ($s0)
/* DA563C 802403FC 26100004 */  addiu     $s0, $s0, 4
/* DA5640 80240400 0C0B210B */  jal       get_float_variable
/* DA5644 80240404 0240202D */   daddu    $a0, $s2, $zero
/* DA5648 80240408 8E050000 */  lw        $a1, ($s0)
/* DA564C 8024040C 26100004 */  addiu     $s0, $s0, 4
/* DA5650 80240410 0240202D */  daddu     $a0, $s2, $zero
/* DA5654 80240414 0C0B210B */  jal       get_float_variable
/* DA5658 80240418 46000606 */   mov.s    $f24, $f0
/* DA565C 8024041C 8E050000 */  lw        $a1, ($s0)
/* DA5660 80240420 26100004 */  addiu     $s0, $s0, 4
/* DA5664 80240424 0240202D */  daddu     $a0, $s2, $zero
/* DA5668 80240428 0C0B1EAF */  jal       get_variable
/* DA566C 8024042C 46000506 */   mov.s    $f20, $f0
/* DA5670 80240430 8E050000 */  lw        $a1, ($s0)
/* DA5674 80240434 26100004 */  addiu     $s0, $s0, 4
/* DA5678 80240438 0240202D */  daddu     $a0, $s2, $zero
/* DA567C 8024043C 0C0B1EAF */  jal       get_variable
/* DA5680 80240440 0040882D */   daddu    $s1, $v0, $zero
/* DA5684 80240444 0240202D */  daddu     $a0, $s2, $zero
/* DA5688 80240448 8E050000 */  lw        $a1, ($s0)
/* DA568C 8024044C 0C0B210B */  jal       get_float_variable
/* DA5690 80240450 0040802D */   daddu    $s0, $v0, $zero
/* DA5694 80240454 3C014334 */  lui       $at, 0x4334
/* DA5698 80240458 44811000 */  mtc1      $at, $f2
/* DA569C 8024045C 3C014049 */  lui       $at, 0x4049
/* DA56A0 80240460 34210FD8 */  ori       $at, $at, 0xfd8
/* DA56A4 80240464 44812000 */  mtc1      $at, $f4
/* DA56A8 80240468 46020003 */  div.s     $f0, $f0, $f2
/* DA56AC 8024046C 46040582 */  mul.s     $f22, $f0, $f4
/* DA56B0 80240470 00000000 */  nop       
/* DA56B4 80240474 4618A501 */  sub.s     $f20, $f20, $f24
/* DA56B8 80240478 3C013F00 */  lui       $at, 0x3f00
/* DA56BC 8024047C 44810000 */  mtc1      $at, $f0
/* DA56C0 80240480 00000000 */  nop       
/* DA56C4 80240484 4600A502 */  mul.s     $f20, $f20, $f0
/* DA56C8 80240488 00000000 */  nop       
/* DA56CC 8024048C 12000007 */  beqz      $s0, .L802404AC
/* DA56D0 80240490 0233102A */   slt      $v0, $s1, $s3
/* DA56D4 80240494 10400005 */  beqz      $v0, .L802404AC
/* DA56D8 80240498 0240202D */   daddu    $a0, $s2, $zero
/* DA56DC 8024049C 0220982D */  daddu     $s3, $s1, $zero
/* DA56E0 802404A0 0280282D */  daddu     $a1, $s4, $zero
/* DA56E4 802404A4 0C0B2026 */  jal       set_variable
/* DA56E8 802404A8 0220302D */   daddu    $a2, $s1, $zero
.L802404AC:
/* DA56EC 802404AC 3C014049 */  lui       $at, 0x4049
/* DA56F0 802404B0 34210FD8 */  ori       $at, $at, 0xfd8
/* DA56F4 802404B4 44810000 */  mtc1      $at, $f0
/* DA56F8 802404B8 44936000 */  mtc1      $s3, $f12
/* DA56FC 802404BC 00000000 */  nop       
/* DA5700 802404C0 46806320 */  cvt.s.w   $f12, $f12
/* DA5704 802404C4 46006302 */  mul.s     $f12, $f12, $f0
/* DA5708 802404C8 00000000 */  nop       
/* DA570C 802404CC 44910000 */  mtc1      $s1, $f0
/* DA5710 802404D0 00000000 */  nop       
/* DA5714 802404D4 46800020 */  cvt.s.w   $f0, $f0
/* DA5718 802404D8 46006303 */  div.s     $f12, $f12, $f0
/* DA571C 802404DC 0C00A874 */  jal       cos_rad
/* DA5720 802404E0 46166300 */   add.s    $f12, $f12, $f22
/* DA5724 802404E4 4600A002 */  mul.s     $f0, $f20, $f0
/* DA5728 802404E8 00000000 */  nop       
/* DA572C 802404EC 4614C080 */  add.s     $f2, $f24, $f20
/* DA5730 802404F0 46001081 */  sub.s     $f2, $f2, $f0
/* DA5734 802404F4 0240202D */  daddu     $a0, $s2, $zero
/* DA5738 802404F8 44061000 */  mfc1      $a2, $f2
/* DA573C 802404FC 0C0B2190 */  jal       set_float_variable
/* DA5740 80240500 02A0282D */   daddu    $a1, $s5, $zero
/* DA5744 80240504 8FBF0028 */  lw        $ra, 0x28($sp)
/* DA5748 80240508 8FB50024 */  lw        $s5, 0x24($sp)
/* DA574C 8024050C 8FB40020 */  lw        $s4, 0x20($sp)
/* DA5750 80240510 8FB3001C */  lw        $s3, 0x1c($sp)
/* DA5754 80240514 8FB20018 */  lw        $s2, 0x18($sp)
/* DA5758 80240518 8FB10014 */  lw        $s1, 0x14($sp)
/* DA575C 8024051C 8FB00010 */  lw        $s0, 0x10($sp)
/* DA5760 80240520 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DA5764 80240524 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DA5768 80240528 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DA576C 8024052C 24020002 */  addiu     $v0, $zero, 2
/* DA5770 80240530 03E00008 */  jr        $ra
/* DA5774 80240534 27BD0048 */   addiu    $sp, $sp, 0x48
